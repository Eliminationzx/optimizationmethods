#include "spuroNeMi.h"
#include "funkcio.h"
#include "Konstantoj.h"
#include "demonstrataqpointf.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>


#include <QMessageBox>
//
spuroNeMi::spuroNeMi(QColor momentaKoloro, QColor bazaKoloro, funkcio *F ) 
	: spuro(bazaKoloro), MomentaKoloro(momentaKoloro), f(F){
	triangulo = new QwtPlotCurve();
	triangulo->setPen(BazaKoloro);
	triangulo->attach(plt);
	
	sp = new QwtPlotCurve();
	sp->setPen(MomentaKoloro);
	sp->attach(plt);
}
//

void spuroNeMi::difiniPlt( QwtPlot * Plt ){
	plt = Plt;
	triangulo->attach(plt);
	sp->attach(plt);
	plt->replot();
}

void spuroNeMi::finisxiIteracio(){
	SP.clear();
	sp->setData(SP);
	plt->replot();
}

void spuroNeMi::difiniMomentaKoloro(QColor c){
	MomentaKoloro = c;
	sp->setPen(MomentaKoloro);
	plt->replot();
}

void spuroNeMi::senspurigi(){
	SP.clear();
	sp->setData(SP);
	triangulo->setData(QPolygonF());
	plt->replot();
}

void spuroNeMi::difiniP1(const QPointF & p){
	P1 = p;
	triangulo->setData(QPolygonF()<<P1<<P2<<P3<<P1);
	plt->replot();
}

void spuroNeMi::difiniP2(const QPointF & p){
	P2 = p;
	triangulo->setData(QPolygonF()<<P1<<P2<<P3<<P1);
	plt->replot();
}

void spuroNeMi::difiniP3(const QPointF & p){
	P3 = p;
	triangulo->setData(QPolygonF()<<P1<<P2<<P3<<P1);
	plt->replot();
}

void spuroNeMi::difiniPRespegulo(const QPointF & p){
	// Создаю полигон Хl, p, Хm.
	// Хl - наименьшая в триуголнике, Хm - средняя.
	SP<<minValue(P1, minValue(P2, P3));
	SP<<p;
	QPointF M = maxValue(P1, maxValue(P2, P3));
	if(bolshe(M, P1) && bolshe(P1, SP.first())){
		SP<<P1;
	}else if(bolshe(M, P2) && bolshe(P2, SP.first())){
		SP<<P2;
	}else if(bolshe(M, P3) && bolshe(P3, SP.first())){
		SP<<P3;
	}
	
	sp->setData(SP);
	plt->replot();
}

void spuroNeMi::difiniPDilato(const QPointF & p){
	SP<<p<<SP<<SP.first();
	sp->setData(SP);
	plt->replot();
}

void spuroNeMi::difiniPKompakto(const QPointF & p){
	SP<<p<<SP<<SP.first();
	sp->setData(SP);
	plt->replot();
}

const QPointF & spuroNeMi::minValue( const QPointF & p1, const QPointF & p2){
	if(f->rezulto(p1) <= f->rezulto(p2)){
		return p1;
	}else{
		return p2;
	}
}

const QPointF & spuroNeMi::maxValue( const QPointF & p1, const QPointF & p2){
	if(f->rezulto(p1) >= f->rezulto(p2)){
		return p1;
	}else{
		return p2;
	}
}

bool spuroNeMi::menshe( const QPointF & p1, const QPointF & p2 ){
	return (f->rezulto(p1) < f->rezulto(p2));
}

bool spuroNeMi::bolshe( const QPointF & p1, const QPointF & p2 ){
	return (f->rezulto(p1) > f->rezulto(p2));
}