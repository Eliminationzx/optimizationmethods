#include "spurohugi.h"
#include "Konstantoj.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_marker.h>
#include <qwt_symbol.h>
#include <QPolygonF>

#include <QMessageBox>
//
spuroHuGi::spuroHuGi( QColor bazaKoloro )
	: spuro(bazaKoloro){
	b1gxisb2 = new QwtPlotCurve();
	b1gxisb2->setPen(BazaKoloro);
	b1gxisb2->attach(plt);
	
	b2gxisp = new QwtPlotCurve();
	b2gxisp->setPen(BazaKoloro);
	b2gxisp->attach(plt);
	
	
	p2 = new QwtPlotCurve(trUtf8("B2"));
	p2->setPen(BazaKoloro);
	QwtSymbol smbl2(QwtSymbol::Ellipse, QBrush(Qt::lightGray), QPen(BazaKoloro),QSize(4,4));
	p2->setSymbol(smbl2);
	p2->setStyle(QwtPlotCurve::Dots);
	p2->attach(plt);
	
	p = new QwtPlotCurve(trUtf8("p"));
	p->setPen(BazaKoloro);
	QwtSymbol smbl3(QwtSymbol::Ellipse, QBrush(Qt::lightGray), QPen(BazaKoloro),QSize(4,4));
	p->setSymbol(smbl3);
	p->setStyle(QwtPlotCurve::Dots);
	p->attach(plt);
	
	p1 = new QwtPlotMarker();
	p1->setLineStyle(QwtPlotMarker::NoLine);
	p1->setLabelAlignment(Qt::AlignCenter | Qt::AlignTop);
	QwtSymbol smbl(QwtSymbol::Ellipse, QBrush(Qt::lightGray), QPen(BazaKoloro),QSize(4,4));
	p1->setSymbol(smbl);
	QwtText text("B1");
	text.setColor(BazaKoloro);
	p1->setLabel(text);
	p1->attach(plt);
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

void spuroHuGi::difiniB1(const QPointF & B1){
	b1 = B1;
	B1gxisB2.clear();
	B1gxisB2<<B1;
	B2gxisP.clear();
	p1->setValue(B1);
	b1gxisb2->setData(QPolygonF());
	b2gxisp->setData(QPolygonF());
	plt->replot();
}

void spuroHuGi::difiniB2(const QPointF & B2){
	if(B1gxisB2.empty());else{
		B1gxisB2<<B2;
		b1gxisb2->setData(B1gxisB2);
		plt->replot();
		B2gxisP.clear();
		B2gxisP<<B2;
		p2->setData(QPolygonF()<<B2);
		plt->replot();
	}
}

void spuroHuGi::difiniP(const QPointF & P){
	if(B2gxisP.empty());else{
		B2gxisP<<P;
		b2gxisp->setData(B2gxisP);
		p->setData(QPolygonF()<<P);
		plt->replot();
	}
}

void spuroHuGi::senspurigi(){
	B1gxisB2.clear();
	B2gxisP.clear();
	b1gxisb2->setData(QPolygonF());
	b2gxisp->setData(QPolygonF());
	p1->setValue(QPointF());
	p2->setData(QPolygonF());
	p->setData(QPolygonF());
	plt->replot();
}