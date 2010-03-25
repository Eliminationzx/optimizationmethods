#include "bazomapo.h"
#include "funkcio.h"
//
BazoMapo::BazoMapo( QGraphicsItem * parent) 
	: QGraphicsItem(parent), skalo(1){
  F = new funkcio(this->scene());
}
//

QRectF BazoMapo::boundingRect() const{
  return QRectF( -amplekso * skalo, -amplekso * skalo, amplekso * skalo, amplekso * skalo);
}

