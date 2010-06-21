#include "mapoporfunkcioimpl.h"
#include "funkcio.h"
#include "spuro.h"
#include <QColor>
#include <QGridLayout>
#include <QVector>
#include <QPushButton>
#include <qwt_color_map.h>
#include <qwt_plot_spectrogram.h>
#include <qwt_scale_widget.h>
#include <qwt_scale_draw.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_layout.h>
#include "spectrogramdata.h"


#include <QMessageBox>
//
MapoPorFunkcioImpl::MapoPorFunkcioImpl( const funkcio * Funkcio, QWidget * parent, Qt::WFlags f) 
	: QWidget(parent, f), F(Funkcio){
//	setupUi(this);
	
	QGridLayout * gridLayout = new QGridLayout(this);
	qwtPlt = new QwtPlot(this);
	gridLayout->addWidget(qwtPlt, 0, 0, 1, 2);
	QPushButton * PligrandigiBtn = new QPushButton("+", this);
	gridLayout->addWidget(PligrandigiBtn, 1, 0, 1, 1);
	QPushButton * MalpliigiBtn = new QPushButton("-", this);
	gridLayout->addWidget(MalpliigiBtn, 1, 1, 1, 1);
	
	connect(PligrandigiBtn, SIGNAL(clicked()), SLOT(on_PligrandigiBtn_clicked()));
	connect(MalpliigiBtn, SIGNAL(clicked()), SLOT(on_MalpliigiBtn_clicked()));
	
	s = new QwtPlotSpectrogram();
	
	QwtLinearColorMap colorMap(Qt::black, Qt::green);
	QVector<double> minPointo;
	if(F->metaObject()->className() == QString("KvadratigantoFunkcio")){
		minPointo = F->minPoint(0.1);
	}else{
		minPointo = F->minPoint(0.00000000001);
	}	
	qreal min = F->rezulto(minPointo[0], minPointo[1]);
	//--Ищу точку приближенную к максимальной в области карты.---------------------
	qreal max = F->rezulto(ampleksoMapo, ampleksoMapo);
	QPointF maxP = QPointF(ampleksoMapo, ampleksoMapo);
	if (F->rezulto(ampleksoMapo, -ampleksoMapo) > max) max = F->rezulto(ampleksoMapo, -ampleksoMapo);
	if (F->rezulto(-ampleksoMapo, ampleksoMapo) > max) max = F->rezulto(-ampleksoMapo, ampleksoMapo);
	if (F->rezulto(-ampleksoMapo, -ampleksoMapo) > max) max = F->rezulto(-ampleksoMapo, -ampleksoMapo);
	if (F->rezulto(0, ampleksoMapo) > max) max = F->rezulto(0, ampleksoMapo);
	if (F->rezulto(0, -ampleksoMapo) > max) max = F->rezulto(0, -ampleksoMapo);
	if (F->rezulto(ampleksoMapo, 0) > max) max = F->rezulto(ampleksoMapo, 0);
	if (F->rezulto(-ampleksoMapo, 0) > max) max = F->rezulto(-ampleksoMapo, 0);
	if(F->metaObject()->className() == QString("KvadratigantoFunkcio")){
		colorMap.addColorStop(0, Qt::black);
		colorMap.addColorStop(F->rezulto(maxP*0.05)/max, Qt::green);
		colorMap.addColorStop(F->rezulto(maxP*0.1)/max, Qt::darkGreen);
		colorMap.addColorStop(F->rezulto(maxP*0.3)/max, Qt::green);
		colorMap.addColorStop(F->rezulto(maxP*0.6)/max, Qt::darkGreen);
		colorMap.addColorStop(0.99, Qt::green);
	}else{
		colorMap.addColorStop(0, Qt::black);
		colorMap.addColorStop(F->rezulto(maxP*0.02)/max, Qt::darkGreen);
		colorMap.addColorStop(F->rezulto(maxP*0.04)/max, Qt::green);
		colorMap.addColorStop(F->rezulto(maxP*0.1)/max, Qt::darkGreen);
		colorMap.addColorStop(F->rezulto(maxP*0.3)/max, Qt::green);
		colorMap.addColorStop(F->rezulto(maxP*0.6)/max, Qt::darkGreen);
		colorMap.addColorStop(0.99, Qt::green);
	}
	s->setColorMap(colorMap);
	
	s->setData(SpectrogramData(F, min));
	s->attach(qwtPlt);

	skalo = new QwtPlotZoomer(qwtPlt->canvas());
	skalo->setTrackerPen(QColor(Qt::lightGray));
	skalo->setTrackerMode(QwtPicker::AlwaysOn);
	skalo->zoom(QRectF(-5, -5, 10, 10));// Предварительно увеличиваю масштаб.
	skalo->setMousePattern(QwtEventPattern::MouseSelect1,
	                       Qt::LeftButton, Qt::ControlModifier);
	
	QwtPlotPanner *panner = new QwtPlotPanner(qwtPlt->canvas());
//	panner->setAxisEnabled(QwtPlot::yRight, false);
	panner->setMouseButton(Qt::LeftButton);
	
}
MapoPorFunkcioImpl::MapoPorFunkcioImpl( QWidget * parent, Qt::WFlags f){
	MapoPorFunkcioImpl(new KvadratigantoFunkcio(0,0,0,0,0,0,0,parent), parent, f);
}
//


void MapoPorFunkcioImpl::on_PligrandigiBtn_clicked(){
	skalo->zoom(QRectF(skalo->zoomRect().topLeft() + QPointF(1,1),
	                   skalo->zoomRect().bottomRight() - QPointF(1,1)));
}

void MapoPorFunkcioImpl::on_MalpliigiBtn_clicked(){
//	skalo->zoom(QRectF(skalo->zoomRect().topLeft() - QPointF(1,1),
//	                   skalo->zoomRect().bottomRight() + QPointF(1,1)));

	QMessageBox::information(this, "", trUtf8("%1 %2 %3 %4").arg(skalo->zoomRect().topLeft().x()).arg(skalo->zoomRect().topLeft().y()).arg(skalo->zoomRect().bottomRight().x()).arg(skalo->zoomRect().bottomRight().y()));
}


void MapoPorFunkcioImpl::difiniFunkcio(funkcio * f){
	F = f;
}

const spuro * MapoPorFunkcioImpl::proviziSpuro() const{
//	return Spuro;
}


void MapoPorFunkcioImpl::setScale(qreal factor){
	// Перед изменением масштаба сцены, установлю его для следа.
	// В ScenoPorMapo::setScale изменить масштаб "следа" не возможно из-за
	// проблем с приведением типа.
//	Spuro->setScale(factor);
//	s->setScale(factor);
}


qreal MapoPorFunkcioImpl::Scale() const {
//	return s->scale();
}


void MapoPorFunkcioImpl::difiniSpuro(spuro * S){
	Spuro = S;
	Spuro->difiniPlt(qwtPlt);
}

//QColor MapoPorFunkcioImpl::fonaKoloro() const {
//	return s->Koloro();
//}