#include "spuroNeMi.h"
#include "Konstantoj.h"
#include <QPolygonF>
#include <QPainter>
//
spuroNeMi::spuroNeMi(QColor momentaKoloro, QColor bazaKoloro, qreal Skalo, QGraphicsItem * parent) 
	: spuro( A::CWdescent_fix, bazaKoloro, Skalo, parent), MomentaKoloro(momentaKoloro){
	// TODO
}
//

QRectF spuroNeMi::boundingRect() const{
  // Размер элемента - обьединённый размер "хвоста" и текущей итерации * на
  // масштаб + поправка, чтоб не остался старый "указатель"
  QRectF rez = MomentaPointoj.boundingRect() | Vosto.boundingRect();
  rez.setTopLeft(rez.topLeft() * skalo - QPointF(2, 2));
  rez.setBottomRight(rez.bottomRight() * skalo + QPointF(2, 2));
  return rez;
}

void spuroNeMi::finisxiIteracio(){
  MomentaPointo = MomentaPointoj.back();
  Vosto += MomentaPointoj;
  MomentaPointoj.clear();
  MomentaPointoj.append(MomentaPointo);
  update();// Планирую перерисовку.
}

void spuroNeMi::reveniAlMomentoPointo(){
  MomentaPointoj.append(MomentaPointo);
  update();// Планирую перерисовку.
}

void spuroNeMi::aldoniSercxantaPointo(QPointF p){
  MomentaPointoj.append(p);
  update();// Планирую перерисовку.
}
void spuroNeMi::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widge*/){
  painter->save();
  
  painter->setPen(BazaKoloro);
  painter->drawPolyline(aplikiScalo(Vosto));
  painter->setPen(MomentaKoloro);
  painter->drawPolyline(aplikiScalo(MomentaPointoj));
  painter->setPen(BazaKoloro);
  painter->drawEllipse(MomentaPointoj.last() * skalo, 2, 2);
  
  painter->restore();
}

void spuroNeMi::difiniUnuaPointo(QPointF p){
  MomentaPointo = p;
  MomentaPointoj.append(p);
  update();// Планирую перерисовку.
}

void spuroNeMi::difiniUnuaPointo( qreal x, qreal y ){
  difiniUnuaPointo(QPointF(x, y));
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


void spuroNeMi::difiniMomentaPointo(QPointF p){
	MomentaPointo = p;
}


void spuroNeMi::senspurigi(){
	prepareGeometryChange ();
//	QRectF r = boundingRect();
	MomentaPointoj.clear();
//	QPointF p = Vosto.first();
	Vosto.clear();
//	difiniUnuaPointo(p);
//	update(r);// Планирую перерисовку.
}