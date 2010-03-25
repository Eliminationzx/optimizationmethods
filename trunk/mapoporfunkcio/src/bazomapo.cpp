#include "bazomapo.h"
//
BazoMapo::BazoMapo( QGraphicsItem * parent) 
	: QGraphicsItem(parent), skalo(1){
	// TODO
}
//

QRectF BazoMapo::boundingRect() const{
  return QRectF( -amplekso * skalo, -amplekso * skalo, amplekso * skalo, amplekso * skalo);
}

