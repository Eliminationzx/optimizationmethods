#include "spurohugi.h"
#include "Konstantoj.h"
#include "qwt_plot.h"
#include "qwt_plot_curve.h"
#include "qwt_plot_marker.h"
#include "qwt_symbol.h"
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
	
	p1 = new QwtPlotMarker();
	p1->setLineStyle(QwtPlotMarker::NoLine);
	p1->setLabelAlignment(Qt::AlignCenter | Qt::AlignTop);
	QwtSymbol smbl(QwtSymbol::Ellipse, QBrush(Qt::lightGray), QPen(BazaKoloro),QSize(4,4));
	p1->setSymbol(smbl);
	QwtText text("B1");
	text.setColor(BazaKoloro);
	text.setBackgroundBrush(Qt::lightGray);
	p1->setLabel(text);
	p1->attach(plt);
	
	p2 = new QwtPlotMarker();
	p2->setLineStyle(QwtPlotMarker::NoLine);
	p2->setLabelAlignment(Qt::AlignCenter | Qt::AlignTop);
//	QwtSymbol smbl2(QwtSymbol::Ellipse, QBrush(Qt::lightGray), QPen(BazaKoloro),QSize(4,4));
	p2->setSymbol(smbl);
	QwtText text2("B2");
	text2.setColor(BazaKoloro);
	text2.setBackgroundBrush(Qt::lightGray);
	p2->setLabel(text2);
	p2->attach(plt);
	
	p = new QwtPlotMarker();
	p->setLineStyle(QwtPlotMarker::NoLine);
	p->setLabelAlignment(Qt::AlignCenter | Qt::AlignTop);
//	QwtSymbol smbl3(QwtSymbol::Ellipse, QBrush(Qt::lightGray), QPen(BazaKoloro),QSize(4,4));
	p->setSymbol(smbl);
	QwtText text3("P");
	text3.setColor(BazaKoloro);
	text3.setBackgroundBrush(Qt::lightGray);
	p->setLabel(text3);
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

void spuroHuGi::difiniB1(const QPointF & B1){
	b1 = B1;
	B1gxisB2.clear();
	p2->setVisible(false);
	B1gxisB2<<B1;
	B2gxisP.clear();
	p->setVisible(false);
	p1->setValue(B1);	
	p1->setVisible(true);
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
		p->setVisible(false);
		B2gxisP<<B2;
		p2->setValue(B2);
		p2->setVisible(true);
		plt->replot();
	}
}

void spuroHuGi::difiniP(const QPointF & P){
	if(B2gxisP.empty());else{
		B2gxisP<<P;
		b2gxisp->setData(B2gxisP);
		p->setValue(P);	
		p->setVisible(true);
		plt->replot();
	}
}

void spuroHuGi::senspurigi(){
	B1gxisB2.clear();
	B2gxisP.clear();
	b1gxisb2->setData(QPolygonF());
	b2gxisp->setData(QPolygonF());
	p1->setValue(QPointF());	
	p1->setVisible(false);
	p2->setVisible(false);	
	p->setVisible(false);
	plt->replot();
}