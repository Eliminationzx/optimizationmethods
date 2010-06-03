#include "spuroNeMi.h"
#include "Konstantoj.h"
#include "demonstrataqpointf.h"
#include <QPolygonF>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
//
spuroNeMi::spuroNeMi(QColor momentaKoloro, QColor bazaKoloro, qreal Skalo, QGraphicsItem * parent) 
	: spuro( A::CWdescent_fix, bazaKoloro, Skalo, parent), MomentaKoloro(momentaKoloro){}
//

QRectF spuroNeMi::boundingRect() const{
	QPolygonF p;
	p<<P1<<P2<<P3;
	return (SP.boundingRect() | p.boundingRect());
}

void spuroNeMi::finisxiIteracio(){
	prepareGeometryChange ();
	SP.clear();
}


void spuroNeMi::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widge*/){
	painter->save();
	
	painter->setPen(MomentaKoloro);
	painter->drawPolyline(aplikiScalo(SP));
	painter->setPen(BazaKoloro);
	QPolygonF p;
	p<<P1<<P2<<P3;
	painter->drawPolygon(aplikiScalo(p));
	
	painter->restore();
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
	// Прокручиваю карту, чтобы не скрывать последнюю точку.
	this->scene()->views()[0]->ensureVisible(p.x() * skalo, p.y() * skalo, 1, 1);
}


void spuroNeMi::difiniP2(const QPointF & p){
	prepareGeometryChange ();
	P2 = p;
	// Прокручиваю карту, чтобы не скрывать последнюю точку.
	this->scene()->views()[0]->ensureVisible(p.x() * skalo, p.y() * skalo, 1, 1);
}


void spuroNeMi::difiniP3(const QPointF & p){
	prepareGeometryChange ();
	P3 = p;
	// Прокручиваю карту, чтобы не скрывать последнюю точку.
	this->scene()->views()[0]->ensureVisible(p.x() * skalo, p.y() * skalo, 1, 1);
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
	// Прокручиваю карту, чтобы не скрывать последнюю точку.
	this->scene()->views()[0]->ensureVisible(p.x() * skalo, p.y() * skalo, 1, 1);
}


void spuroNeMi::difiniPDilato(const QPointF & p){
	prepareGeometryChange ();
	SP<<p<<SP.first();
	// Прокручиваю карту, чтобы не скрывать последнюю точку.
	this->scene()->views()[0]->ensureVisible(p.x() * skalo, p.y() * skalo, 1, 1);
}

void spuroNeMi::difiniPKompakto(const QPointF & p){
	prepareGeometryChange ();
	SP.clear();
	difiniPRespegulo(p);
	// Прокручиваю карту, чтобы не скрывать последнюю точку.
	this->scene()->views()[0]->ensureVisible(p.x() * skalo, p.y() * skalo, 1, 1);
}