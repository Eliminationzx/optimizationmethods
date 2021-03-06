#include "spurosinkolauxkoordinatoj.h"
#include <QPolygonF>
#include <QPainter>
//
spuroSinkoLauxKoordinatoj::spuroSinkoLauxKoordinatoj(QColor momentaKoloro, QColor bazaKoloro, QGraphicsItem * parent) 
	: spuro( 0, bazaKoloro, parent), MomentaKoloro(momentaKoloro){
	// TODO
}
//

QRectF spuroSinkoLauxKoordinatoj::boundingRect() const{
  QRectF rez = MomentaPointioj.boundingRect() | Vosto.boundingRect();
  rez.setTopLeft(rez.topLeft() * skalo);
  rez.setBottomRight(rez.bottomRight() * skalo);
  return rez;
}

void spuroSinkoLauxKoordinatoj::finisxiIteracio(QPointF p){
  MomentaPointio = p;
  Vosto += MomentaPointioj;
  MomentaPointioj.clear();
  MomentaPointioj.append(p);
}

void spuroSinkoLauxKoordinatoj::reveniAlMomentoPointo(){
  MomentaPointioj.append(MomentaPointio);
}

void spuroSinkoLauxKoordinatoj::aldoniSercxantaPointo(QPointF p){
  MomentaPointioj.append(p);
}
void spuroSinkoLauxKoordinatoj::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widge){
  painter->save();
  
  painter->setPen(BazaKoloro);
  painter->drawPolygon(aplikiScalo(Vosto));
  painter->setPen(MomentaKoloro);
  painter->drawPolygon(aplikiScalo(MomentaPointioj));
  painter->setPen(BazaKoloro);
  painter->drawEllipse(MomentaPointioj.last(), 2, 2);
  
  painter->restore();
}

void spuroSinkoLauxKoordinatoj::difiniUnuaPointo(QPointF p){
  MomentaPointio = p;
  MomentaPointioj.append(p);
}

void spuroSinkoLauxKoordinatoj::difiniUnuaPointo( qreal x, qreal y ){
  difiniUnuaPointo(QPointF(x, y));
}


QPolygonF spuroSinkoLauxKoordinatoj::aplikiScalo(QPolygonF p)
{
  QPolygonF rez;
  for(int i; i < p.count(); ++i){
    rez.append(p[i] * skalo);
  }
  return rez;
}

