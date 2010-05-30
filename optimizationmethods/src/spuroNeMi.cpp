#include "spuroNeMi.h"
#include "Konstantoj.h"
#include "demonstrataqpointf.h"
#include <QPolygonF>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <QMessageBox>
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
	prepareGeometryChange ();
	BazaKoloro = c;
}


void spuroNeMi::difiniMomentaKoloro(QColor c){
	prepareGeometryChange ();
	MomentaKoloro = c;
}


void spuroNeMi::senspurigi(){
	prepareGeometryChange ();
	SP.clear();
}


void spuroNeMi::difiniP1(const QPointF & p){
	prepareGeometryChange ();
	P1 = p;
	// Центрирую карту на первой точке.
	this->scene()->views()[0]->centerOn(P1 * skalo);
	
	QMessageBox::information(this->scene()->views()[0], trUtf8(""), trUtf8("Вошёл в spuroNeMi::difiniP1"));
}


void spuroNeMi::difiniP2(const QPointF & p){
	prepareGeometryChange ();
	P2 = p;
}


void spuroNeMi::difiniP3(const QPointF & p){
	prepareGeometryChange ();
	P3 = p;
}


void spuroNeMi::difiniPRespegulo(const QPointF & p){
	prepareGeometryChange ();
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


void spuroNeMi::difiniPDilato(const QPointF & p){
	prepareGeometryChange ();
	SP<<p<<SP.first();
}

void spuroNeMi::difiniPKompakto(const QPointF & p){
	prepareGeometryChange ();
	SP.clear();
	difiniPRespegulo(p);
}