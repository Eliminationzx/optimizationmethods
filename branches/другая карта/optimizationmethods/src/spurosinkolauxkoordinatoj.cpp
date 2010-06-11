#include "spurosinkolauxkoordinatoj.h"
#include "Konstantoj.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <QPolygonF>
//
spuroSinkoLauxKoordinatoj::spuroSinkoLauxKoordinatoj(QColor momentaKoloro, QColor bazaKoloro) 
	: spuro( bazaKoloro), MomentaKoloro(momentaKoloro){
	vosto = new QwtPlotCurve();
	vosto->setPen(BazaKoloro);
	vosto->attach(plt);

	momentaPointoj = new QwtPlotCurve();
	momentaPointoj->setPen(MomentaKoloro);
	momentaPointoj->attach(plt);
	
	MomentaPointo = new QwtPlotCurve();
	MomentaPointo->setPen(BazaKoloro);
	QwtSymbol smbl(QwtSymbol::Ellipse, QBrush(Qt::lightGray), QPen(BazaKoloro),QSize(4,4));
	MomentaPointo->setSymbol(smbl);
	MomentaPointo->setStyle(QwtPlotCurve::Dots);
	MomentaPointo->attach(plt);	
}
//

void spuroSinkoLauxKoordinatoj::difiniPlt( QwtPlot * Plt ){
	plt = Plt;
	vosto->attach(plt);
	momentaPointoj->attach(plt);
	MomentaPointo->attach(plt);	
	plt->replot();
}

void spuroSinkoLauxKoordinatoj::finisxiIteracio(){
	Vosto<<MomentaPointoj;
	MomentaPointoj.clear();
	MomentaPointoj<<Vosto.last();
	vosto->setData(Vosto);
	momentaPointoj->setData(MomentaPointoj);
	MomentaPointo->setData(MomentaPointoj);
	plt->replot();
}

void spuroSinkoLauxKoordinatoj::aldoniSercxantaPointo(QPointF p){
	MomentaPointoj<<p;
	momentaPointoj->setData(MomentaPointoj);
	MomentaPointo->setData(QPolygonF()<<p);
	plt->replot();
}

void spuroSinkoLauxKoordinatoj::difiniMomentaKoloro(QColor c){
	MomentaKoloro = c;
	momentaPointoj->setPen(MomentaKoloro);
}


void spuroSinkoLauxKoordinatoj::difiniMomentaPointo(QPointF p){
	MomentaPointoj<<p;
	MomentaPointo->setData(QPolygonF()<<p);
	plt->replot();
}

void spuroSinkoLauxKoordinatoj::reveniAlMomentoPointo(){
	MomentaPointoj<<Vosto.last();
	vosto->setData(Vosto);
	momentaPointoj->setData(MomentaPointoj);
	MomentaPointo->setData(QPolygonF()<<MomentaPointoj.last());
	plt->replot();
}

void spuroSinkoLauxKoordinatoj::senspurigi(){
	vosto->setData(QPolygonF());
	MomentaPointo->setData(QPolygonF()<<Vosto.first());
	Vosto.clear();
	momentaPointoj->setData(QPolygonF());
	MomentaPointoj.clear();
	plt->replot();
}