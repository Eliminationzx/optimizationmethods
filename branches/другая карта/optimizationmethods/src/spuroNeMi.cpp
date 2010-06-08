#include "spuroNeMi.h"
#include "Konstantoj.h"
#include "demonstrataqpointf.h"
#include <qwt_plot_curve.h>
#include <QPolygonF>
//
spuroNeMi::spuroNeMi(QColor momentaKoloro, QColor bazaKoloro ) 
	: spuro(bazaKoloro), MomentaKoloro(momentaKoloro){}
//

void spuroNeMi::finisxiIteracio(){
}

void spuroNeMi::difiniMomentaKoloro(QColor c){
	MomentaKoloro = c;
}

void spuroNeMi::senspurigi(){
}

void spuroNeMi::difiniP1(const QPointF & p){
}

void spuroNeMi::difiniP2(const QPointF & p){
}

void spuroNeMi::difiniP3(const QPointF & p){
}

void spuroNeMi::difiniPRespegulo(const QPointF & p){
	// Создаю полигон Хl, p, Хm.
	// Хl - наименьшая в триуголнике, Хm - средняя.
//	if(Length(p - P1) < Length(p - P2)){
//		if(Length(p - P1) < Length(p - P3)){
//			SP<<(P1);
//			SP<<(p);
//			if(Length(p - P2) < Length(p - P3)){
//				SP<<(P2);
//			}else{
//				SP<<(P3);
//			}
//		}else{
//			SP<<(P3);
//			SP<<(p);
//			SP<<(P1);
//		}
//	}else{
//		if(Length(p - P2) < Length(p - P3)){
//			SP<<(P2);
//			SP<<(p);
//			if(Length(p - P1) < Length(p - P3)){
//				SP<<(P1);
//			}else{
//				SP<<(P3);
//			}
//		}else{
//			SP<<(P3);
//			SP<<(p);
//			SP<<(P2);
//		}
//	}
}

void spuroNeMi::difiniPDilato(const QPointF & p){
}

void spuroNeMi::difiniPKompakto(const QPointF & p){
}