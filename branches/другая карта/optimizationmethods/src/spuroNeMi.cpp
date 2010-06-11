#include "spuroNeMi.h"
#include "Konstantoj.h"
#include "demonstrataqpointf.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
//
spuroNeMi::spuroNeMi(QColor momentaKoloro, QColor bazaKoloro ) 
	: spuro(bazaKoloro), MomentaKoloro(momentaKoloro){
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
	sp->setData(QPolygonF()<<P1<<P2<<P3<<P1);
	plt->replot();
}

void spuroNeMi::difiniP2(const QPointF & p){
	P2 = p;
	sp->setData(QPolygonF()<<P1<<P2<<P3<<P1);
	plt->replot();
}

void spuroNeMi::difiniP3(const QPointF & p){
	P3 = p;
	sp->setData(QPolygonF()<<P1<<P2<<P3<<P1);
	plt->replot();
}

void spuroNeMi::difiniPRespegulo(const QPointF & p){
	// Создаю полигон Хl, p, Хm.
	// Хl - наименьшая в триуголнике, Хm - средняя.
	if(Length(p - P1) < Length(p - P2)){
		if(Length(p - P1) < Length(p - P3)){
			SP<<(P1);
			SP<<(p);
			if(Length(p - P2) < Length(p - P3)){
				SP<<(P2);
			}else{
				SP<<(P3);
			}
		}else{
			SP<<(P3);
			SP<<(p);
			SP<<(P1);
		}
	}else{
		if(Length(p - P2) < Length(p - P3)){
			SP<<(P2);
			SP<<(p);
			if(Length(p - P1) < Length(p - P3)){
				SP<<(P1);
			}else{
				SP<<(P3);
			}
		}else{
			SP<<(P3);
			SP<<(p);
			SP<<(P2);
		}
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