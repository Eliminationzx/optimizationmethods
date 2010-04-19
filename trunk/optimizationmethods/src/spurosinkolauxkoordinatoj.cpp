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
  // Размер элемента - обьединённый размер "хвоста" и текущей итерации * на
  // масштаб + поправка, чтоб не остался старый "указатель"
  QRectF rez = MomentaPointioj.boundingRect() | Vosto.boundingRect();
  rez.setTopLeft(rez.topLeft() * skalo - QPointF(2, 2));
  rez.setBottomRight(rez.bottomRight() * skalo + QPointF(2, 2));
  return rez;
}

void spuroSinkoLauxKoordinatoj::finisxiIteracio(){
  MomentaPointio = MomentaPointioj.back();
  Vosto += MomentaPointioj;
  MomentaPointioj.clear();
  MomentaPointioj.append(MomentaPointio);
  update();// Планирую перерисовку.
}

void spuroSinkoLauxKoordinatoj::reveniAlMomentoPointo(){
  MomentaPointioj.append(MomentaPointio);
  update();// Планирую перерисовку.
}

void spuroSinkoLauxKoordinatoj::aldoniSercxantaPointo(QPointF p){
  MomentaPointioj.append(p);
  update();// Планирую перерисовку.
}
void spuroSinkoLauxKoordinatoj::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widge*/){
  painter->save();
  
  painter->setPen(BazaKoloro);
  painter->drawPolyline(aplikiScalo(Vosto));
  painter->setPen(MomentaKoloro);
  painter->drawPolyline(aplikiScalo(MomentaPointioj));
  painter->setPen(BazaKoloro);
  painter->drawEllipse(MomentaPointioj.last() * skalo, 2, 2);
  
  painter->restore();
}

void spuroSinkoLauxKoordinatoj::difiniUnuaPointo(QPointF p){
  MomentaPointio = p;
  MomentaPointioj.append(p);
  update();// Планирую перерисовку.
}

void spuroSinkoLauxKoordinatoj::difiniUnuaPointo( qreal x, qreal y ){
  difiniUnuaPointo(QPointF(x, y));
}


QPolygonF spuroSinkoLauxKoordinatoj::aplikiScalo(QPolygonF p)
{
  QPolygonF rez;
  for(int i=0; i < p.count(); ++i){
    rez.append(p[i] * skalo);
  }
  return rez;
}

