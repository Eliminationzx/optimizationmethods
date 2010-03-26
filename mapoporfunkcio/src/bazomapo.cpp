#include "bazomapo.h"
#include "funkcio.h"
#include <limits>
//
BazoMapo::BazoMapo( QGraphicsItem * parent) 
	: QGraphicsItem(parent){}
//

QRectF BazoMapo::boundingRect() const{
  using namespace std;
  return QRectF( numeric_limits<int>::min(), numeric_limits<int>::min(),
                 numeric_limits<int>::max(), numeric_limits<int>::max());
}


void BazoMapo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  // TODO
}

