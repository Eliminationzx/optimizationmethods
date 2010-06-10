#include "spurosinkolauxkoordinatoj_md.h"
#include "Konstantoj.h"
#include <qwt_plot_curve.h>
#include <qwt_plot.h>
//
spuroSinkoLauxKoordinatoj_md::spuroSinkoLauxKoordinatoj_md(QColor bazaKoloro, QwtPlot * Plt ) 
	: spuro(bazaKoloro, Plt){
	vosto = new QwtPlotCurve();
	vosto->setPen(BazaKoloro);
//	vosto->setVisible(true);
	vosto->attach(plt);
}
//

void spuroSinkoLauxKoordinatoj_md::difiniPlt( QwtPlot * Plt ){
	plt = Plt;
	plt->replot();
}

void spuroSinkoLauxKoordinatoj_md::senspurigi(){
	vosto->setData(QPolygonF());
	plt->replot();
}

void spuroSinkoLauxKoordinatoj_md::aldoniPointo(const QPointF & p){
	Vosto<<p;
	vosto->setData(Vosto);
	plt->replot();
}