#include "bazomapo.h"
#include "funkcio.h"
#include <limits>
#include <QPainter>
#include <QColor>
#include <QStyleOptionGraphicsItem>
//
  using namespace std;

BazoMapo::BazoMapo(funkcio * Funkcio, QGraphicsItem * parent) 
	: QGraphicsItem(parent), F(Funkcio){}
//

QRectF BazoMapo::boundingRect() const{
  return QRectF( numeric_limits<int>::min(), numeric_limits<int>::min(),
                 numeric_limits<int>::max(), numeric_limits<int>::max());
}


void BazoMapo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
  QColor koloro(Qt::red);
  qreal h, s;
  koloro.getHsvF(&h, &s, 0);
  QRect r(option->exposedRect.toRect());
  for(int i = r.x(); i <= r.right(); ++i){
    for(int j = r.y(); j <= r.bottom(); ++j){
      koloro.setHsvF(h, s, F->rezulto(i, j));
      painter->setPen(koloro);
      painter->drawPoint(i, j);
    }
  }
}

