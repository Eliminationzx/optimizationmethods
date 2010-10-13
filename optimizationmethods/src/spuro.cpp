#include "spuro.h"
#include "qwt_plot.h"
//
void spuro::difiniPlt( QwtPlot * Plt ){
	plt = Plt;
	plt->replot();
}