#include "mapoporfunkcioimpl.h"
#include "funkcio.h"
#include <QColor>
#include <qwt_color_map.h>
#include <qwt_plot_spectrogram.h>
#include <qwt_scale_widget.h>
#include <qwt_scale_draw.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_layout.h>
#include "spectrogramdata.h"
//
MapoPorFunkcioImpl::MapoPorFunkcioImpl( const funkcio * Funkcio, QWidget * parent, Qt::WFlags f) 
	: QWidget(parent, f), F(Funkcio){
	setupUi(this);
	
	s = new QwtPlotSpectrogram();
	
	QwtLinearColorMap colorMap(Qt::darkCyan, Qt::red);
	colorMap.addColorStop(0, Qt::darkBlue);
	colorMap.addColorStop(0.0005, Qt::blue);
	colorMap.addColorStop(0.001, Qt::darkGreen);
	colorMap.addColorStop(0.01, Qt::green);
	colorMap.addColorStop(0.1, Qt::yellow);
	colorMap.addColorStop(0.4, Qt::cyan);
	colorMap.addColorStop(0.99, Qt::white);
	
	s->setColorMap(colorMap);
	
	s->setData(SpectrogramData(F));
	s->attach(qwtPlt);
	
	QwtValueList contourLevels;
	for ( double level = s->data().range().minValue(); level < s->data().range().maxValue(); level += 1.0 )
		contourLevels += level;
	s->setContourLevels(contourLevels);
//	s->setDisplayMode(QwtPlotSpectrogram::ContourMode, true);

	skalo = new QwtPlotZoomer(qwtPlt->canvas());
	
	skalo->setMousePattern(QwtEventPattern::MouseSelect2,
	                       Qt::RightButton, Qt::ControlModifier);
	skalo->setMousePattern(QwtEventPattern::MouseSelect3, Qt::RightButton);
	
	skalo->setTrackerMode(QwtPicker::AlwaysOn);

	QwtPlotPanner *panner = new QwtPlotPanner(qwtPlt->canvas());
	panner->setAxisEnabled(QwtPlot::yRight, false);
	panner->setMouseButton(Qt::MidButton);
	
	
	
}
MapoPorFunkcioImpl::MapoPorFunkcioImpl( QWidget * parent, Qt::WFlags f){
	MapoPorFunkcioImpl(new KvadratigantoFunkcio(0,0,0,0,0,0,0,parent), parent, f);
}
//


void MapoPorFunkcioImpl::on_PligrandigiBtn_clicked(){
//	s->setScale((s->scale() * 1.1));
//	Spuro->setScale(s->scale());
}

void MapoPorFunkcioImpl::on_MalpliigiBtn_clicked(){
//	s->setScale((s->scale() * 0.9));
//	Spuro->setScale(s->scale());
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
//	s->removeItem(Spuro);
//	delete Spuro;
//	Spuro = S;
//	Spuro->setScale(s->scale());
//	s->addItem(Spuro);
}

//QColor MapoPorFunkcioImpl::fonaKoloro() const {
//	return s->Koloro();
//}