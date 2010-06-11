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
}

void spuroSinkoLauxKoordinatoj::aldoniSercxantaPointo(QPointF p){
}

void spuroSinkoLauxKoordinatoj::difiniMomentaKoloro(QColor c){
	MomentaKoloro = c;
}


void spuroSinkoLauxKoordinatoj::difiniMomentaPointo(QPointF p){
}


void spuroSinkoLauxKoordinatoj::senspurigi(){
}