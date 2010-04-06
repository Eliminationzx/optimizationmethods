#include "spurosinkolauxkoordinatoj.h"
#include <QPolygonF>
//
spuroSinkoLauxKoordinatoj::spuroSinkoLauxKoordinatoj(QColor momentaKoloro, QColor bazaKoloro, QGraphicsItem * parent) 
	: spuro( 0, bazaKoloro, parent), MomentaKoloro(momentaKoloro){
	// TODO
}
//

QRectF spuroSinkoLauxKoordinatoj::boundingRect() const{
  
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
  // TODO
}

void spuroSinkoLauxKoordinatoj::difiniUnuaPointo(QPointF p){
  MomentaPointio = p;
  MomentaPointioj.append(p);
}

void spuroSinkoLauxKoordinatoj::difiniUnuaPointo( qreal x, qreal y ){
  difiniUnuaPointo(QPointF(x, y));
}

