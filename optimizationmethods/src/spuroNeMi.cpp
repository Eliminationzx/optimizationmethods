#include "spuroNeMi.h"
#include "Konstantoj.h"
#include "demonstrataqpointf.h"
#include <QPolygonF>
#include <QPainter>
//
spuroNeMi::spuroNeMi(QColor momentaKoloro, QColor bazaKoloro, qreal Skalo, QGraphicsItem * parent) 
	: spuro( A::CWdescent_fix, bazaKoloro, Skalo, parent), MomentaKoloro(momentaKoloro){
	// TODO
}
//

QRectF spuroNeMi::boundingRect() const{
	QPolygonF p;
	p<<P1<<P2<<P3;	
	return SP.boundingRect() | p.boundingRect();
}

void spuroNeMi::finisxiIteracio(){
	prepareGeometryChange ();
	SP.clear();
}


void spuroNeMi::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widge*/){
	painter->save();
	
	painter->setPen(BazaKoloro);
	QPolygonF p;
	p<<P1<<P2<<P3<<P1;
	painter->drawPolygon(aplikiScalo(p));
	painter->setPen(MomentaKoloro);
	painter->drawPolygon(aplikiScalo(SP));
	
	painter->restore();
}


QPolygonF spuroNeMi::aplikiScalo(QPolygonF p)
{
  QPolygonF rez;
  for(int i=0; i < p.count(); ++i){
    rez.append(p[i] * skalo);
  }
  return rez;
}


void spuroNeMi::difiniBazaKoloro(QColor c){
	BazaKoloro = c;
}


void spuroNeMi::difiniMomentaKoloro(QColor c){
	MomentaKoloro = c;
}


void spuroNeMi::senspurigi(){
	prepareGeometryChange ();
	SP.clear();
}


void spuroNeMi::difiniP1(QPointF p){
	P1 = p;
}


void spuroNeMi::difiniP2(QPointF p){
	P2 = p;
}


void spuroNeMi::difiniP3(QPointF p){
	P3 = p;
}


void spuroNeMi::difiniPRespegulo(QPointF p){
	// Создаю полигон Хl, p, Хm.
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
}


void spuroNeMi::difiniPDilato(QPointF p){
	SP<<p<<SP.first();
}

void spuroNeMi::difiniPKompakto(QPointF p){
	SP.clear();
	difiniPRespegulo(p);
}