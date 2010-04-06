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

void spuroSinkoLauxKoordinatoj::finisxiIteracio(){
  
}

void spuroSinkoLauxKoordinatoj::reveniAlMomentoPointo(){
  
}

void spuroSinkoLauxKoordinatoj::aldoniSercxantaPointo(QPointF){
  
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

