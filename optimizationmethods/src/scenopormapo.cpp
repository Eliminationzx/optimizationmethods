#include "scenopormapo.h"
#include <QRect>
#include "funkcio.h"
#include <QColor>
#include <QPainter>
#include "spuro.h"
#include <limits>
#include <QGraphicsItem>
//
ScenoPorMapo::ScenoPorMapo( funkcio * Funkcio, QObject * parent)
	: QGraphicsScene(parent), F(Funkcio), skalo(1){}
ScenoPorMapo::ScenoPorMapo( funkcio * Funkcio, const QRectF & sceneRect, QObject * parent)
	: QGraphicsScene(sceneRect, parent), F(Funkcio), skalo(1){}
ScenoPorMapo::ScenoPorMapo( funkcio * Funkcio, qreal x, qreal y, qreal width, qreal height, QObject * parent)
	: QGraphicsScene(x, y, width, height, parent), F(Funkcio), skalo(1){}
//


void ScenoPorMapo::drawBackground(QPainter * painter, const QRectF & rect){
//  painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
  QColor koloro(Qt::red);
  qreal h, s, v;
  koloro.getHsvF(&h, &s, &v);
  QRect r(rect.toRect());
  double min = F->rezulto(F->minPoint(0.1));
  // Перебираю видимую область и каждую точку заполняю цветом в соответствии
  // со значением целевой функции.
  for(int i = r.x(); i <= r.right(); ++i){
    for(int j = r.y(); j <= r.bottom(); ++j){
      v = (F->rezulto(i / skalo, j / skalo)-min)/100000;
      if(v > 1){
        v = 1;
      }else if(v < 0){
        v = 0;
      }
      koloro.setHsvF(h, s, v);
      painter->setPen(koloro);
      painter->drawPoint(i, j);
    }
  }
}


void ScenoPorMapo::setScale(qreal factor ){
  skalo = factor;
  //Устанавливаю масштаб для "следа".
  if(items().count() > 0){
    ((spuro*)(items()[0]))->setScale(factor);
  }  
  using namespace std;
  update(-numeric_limits<int>::max()/2, -numeric_limits<int>::max()/2,
         numeric_limits<int>::max(), numeric_limits<int>::max());
}


qreal ScenoPorMapo::scale() const{
  return skalo;
}



void ScenoPorMapo::mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
  QGraphicsScene::mouseMoveEvent ( mouseEvent );// Вызываю реализацию по умолчанию.
}

