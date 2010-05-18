#include "spurosinkolauxkoordinatoj.h"
#include <QPolygonF>
#include <QPainter>
//
spuroSinkoLauxKoordinatoj::spuroSinkoLauxKoordinatoj(QColor momentaKoloro, QColor bazaKoloro, qreal Skalo, QGraphicsItem * parent) 
	: spuro( 0, bazaKoloro, Skalo, parent), MomentaKoloro(momentaKoloro){
	// TODO
}
//

QRectF spuroSinkoLauxKoordinatoj::boundingRect() const{
  // Размер элемента - обьединённый размер "хвоста" и текущей итерации * на
  // масштаб + поправка, чтоб не остался старый "указатель"
  QRectF rez = MomentaPointoj.boundingRect() | Vosto.boundingRect();
  rez.setTopLeft(rez.topLeft() * skalo - QPointF(2, 2));
  rez.setBottomRight(rez.bottomRight() * skalo + QPointF(2, 2));
  return rez;
}

void spuroSinkoLauxKoordinatoj::finisxiIteracio(){
  MomentaPointo = MomentaPointoj.back();
  Vosto += MomentaPointoj;
  MomentaPointoj.clear();
  MomentaPointoj.append(MomentaPointo);
  update();// Планирую перерисовку.
}

void spuroSinkoLauxKoordinatoj::reveniAlMomentoPointo(){
  MomentaPointoj.append(MomentaPointo);
  update();// Планирую перерисовку.
}

void spuroSinkoLauxKoordinatoj::aldoniSercxantaPointo(QPointF p){
  MomentaPointoj.append(p);
  update();// Планирую перерисовку.
}
void spuroSinkoLauxKoordinatoj::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widge*/){
  painter->save();
  
  painter->setPen(BazaKoloro);
  painter->drawPolyline(aplikiScalo(Vosto));
  painter->setPen(MomentaKoloro);
  painter->drawPolyline(aplikiScalo(MomentaPointoj));
  painter->setPen(BazaKoloro);
  painter->drawEllipse(MomentaPointoj.last() * skalo, 2, 2);
  
  painter->restore();
}

void spuroSinkoLauxKoordinatoj::difiniUnuaPointo(QPointF p){
  MomentaPointo = p;
  MomentaPointoj.append(p);
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


void spuroSinkoLauxKoordinatoj::difiniBazaKoloro(QColor c){
	BazaKoloro = c;
}


void spuroSinkoLauxKoordinatoj::difiniMomentaKoloro(QColor c){
	MomentaKoloro = c;
}


void spuroSinkoLauxKoordinatoj::difiniMomentaPointo(QPointF p){
	MomentaPointo = p;
}


void spuroSinkoLauxKoordinatoj::senspurigi(){
	MomentaPointoj.clear();
//	QPointF p = Vosto.first();
	Vosto.clear();
//	difiniUnuaPointo(p);
}