#include "spurohugi.h"
#include "Konstantoj.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <QPolygonF>
//
spuroHuGi::spuroHuGi( QColor bazaKoloro )
	: spuro(bazaKoloro)/*, b1(0, 0)*/{}
//

void spuroHuGi::difiniPlt( QwtPlot * Plt ){
	plt = Plt;
	plt->replot();
}

void spuroHuGi::difiniB1(QPointF & B1){
}

void spuroHuGi::difiniB2(QPointF & B2){
}

void spuroHuGi::difiniP(QPointF & P){
}
