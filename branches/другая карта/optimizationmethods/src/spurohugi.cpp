#include "spurohugi.h"
#include "Konstantoj.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <QPolygonF>
//
spuroHuGi::spuroHuGi( QColor bazaKoloro )
	: spuro(bazaKoloro){
	b1gxisb2 = new QwtPlotCurve();
	b1gxisb2->setPen(BazaKoloro);
	b1gxisb2->attach(plt);
	
	b2gxisp = new QwtPlotCurve();
	b2gxisp->setPen(BazaKoloro);
	b2gxisp->attach(plt);
	
	p1 = new QwtPlotCurve();
	p1->setPen(BazaKoloro);
	QwtSymbol smbl(QwtSymbol::Ellipse, QBrush(Qt::lightGray), QPen(BazaKoloro),QSize(4,4));
	p1->setSymbol(smbl);
	p1->setStyle(QwtPlotCurve::Dots);
	p1->attach(plt);
	
	p2 = new QwtPlotCurve();
	p2->setPen(BazaKoloro);
//	QwtSymbol smbl(QwtSymbol::Ellipse, QBrush(Qt::lightGray), QPen(BazaKoloro),QSize(4,4));
	p2->setSymbol(smbl);
	p2->setStyle(QwtPlotCurve::Dots);
	p2->attach(plt);
	
	p = new QwtPlotCurve();
	p->setPen(BazaKoloro);
//	QwtSymbol smbl(QwtSymbol::Ellipse, QBrush(Qt::lightGray), QPen(BazaKoloro),QSize(4,4));
	p->setSymbol(smbl);
	p->setStyle(QwtPlotCurve::Dots);
	p->attach(plt);
}
//

void spuroHuGi::difiniPlt( QwtPlot * Plt ){
	plt = Plt;
	b1gxisb2->attach(plt);
	b2gxisp->attach(plt);
	p1->attach(plt);
	p2->attach(plt);
	p->attach(plt);
	plt->replot();
}

void spuroHuGi::difiniB1(QPointF & B1){
	b1 = B1;
	B1gxisB2.clear();
	B1gxisB2<<B1;
	B2gxisP.clear();
	p1->setData(QPolygonF()<<B1);
	b1gxisb2->setData(QPolygonF());
	b2gxisp->setData(QPolygonF());
	plt->replot();
}

void spuroHuGi::difiniB2(QPointF & B2){
	if(B1gxisB2.empty());else{
		B1gxisB2<<B2;
		b1gxisb2->setData(QPolygonF());
		plt->replot();
		B2gxisP.clear();
		B2gxisP<<B2;
		plt->replot();
	}
}

void spuroHuGi::difiniP(QPointF & P){
	if(B2gxisP.empty());else{
		B2gxisP<<P;
		b2gxisp->setData(B2gxisP);
		plt->replot();
	}
}
