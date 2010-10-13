#include "spurosinkolauxkoordinatoj_md.h"
#include "Konstantoj.h"
#include "qwt_plot_curve.h"
#include "qwt_plot.h"
#include "qwt_symbol.h"
//
spuroSinkoLauxKoordinatoj_md::spuroSinkoLauxKoordinatoj_md(QColor bazaKoloro, QwtPlot * Plt ) 
	: spuro(bazaKoloro, Plt){
	vosto = new QwtPlotCurve();
	vosto->setPen(BazaKoloro);
	vosto->attach(plt);
	
	MomentaPointo = new QwtPlotCurve();
	MomentaPointo->setPen(BazaKoloro);
	QwtSymbol smbl(QwtSymbol::Ellipse, QBrush(Qt::lightGray), QPen(BazaKoloro),QSize(4,4));
	MomentaPointo->setSymbol(smbl);
	MomentaPointo->setStyle(QwtPlotCurve::Dots);
	MomentaPointo->attach(plt);
}
//

void spuroSinkoLauxKoordinatoj_md::difiniPlt( QwtPlot * Plt ){
	plt = Plt;
	vosto->attach(plt);
	MomentaPointo->attach(plt);
	plt->replot();
}

void spuroSinkoLauxKoordinatoj_md::senspurigi(){
	vosto->setData(QPolygonF());
	MomentaPointo->setData(QPolygonF()<<Vosto.first());
	Vosto.clear();
	plt->replot();
}

void spuroSinkoLauxKoordinatoj_md::aldoniPointo(const QPointF & p){
	Vosto<<p;
	vosto->setData(Vosto);
	MomentaPointo->setData(QPolygonF()<<p);
	plt->replot();
}