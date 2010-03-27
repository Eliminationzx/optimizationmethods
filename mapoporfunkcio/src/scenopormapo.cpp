#include "scenopormapo.h"
#include <QRect>
#include "funkcio.h"
#include <QColor>
#include <QImage>
#include <QPainter>
//
ScenoPorMapo::ScenoPorMapo( funkcio * Funkcio, QObject * parent)
	: QGraphicsScene(parent), F(Funkcio){}
ScenoPorMapo::ScenoPorMapo( funkcio * Funkcio, const QRectF & sceneRect, QObject * parent)
	: QGraphicsScene(sceneRect, parent), F(Funkcio){}
ScenoPorMapo::ScenoPorMapo( funkcio * Funkcio, qreal x, qreal y, qreal width, qreal height, QObject * parent)
	: QGraphicsScene(x, y, width, height, parent), F(Funkcio){}
//

void ScenoPorMapo::update(const QRectF & rect ){
  QImage i(rect.toRect().size(), QImage::Format_ARGB32_Premultiplied);
  QColor koloro(Qt::red);
  qreal h, s;
  koloro.getHsvF(&h, &s, 0);
  QRect r(rect.toRect());
  QPainter p(&i);
  for(int i = r.x(); i <= r.right(); ++i){
    for(int j = r.y(); j <= r.bottom(); ++j){
      koloro.setHsvF(h, s, F->rezulto(i, j));
      p.setPen(koloro);
      p.drawPoint(i, j);
    }
  }
  setBackgroundBrush(i);
  QGraphicsScene::update(rect);
}

