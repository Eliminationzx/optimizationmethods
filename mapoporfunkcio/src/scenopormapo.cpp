#include "scenopormapo.h"
#include <QRect>
#include "funkcio.h"
#include <QColor>
//#include <QImage>
#include <QPainter>
#include <limits>
#include <QString>
#include <QMessageBox>
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
//  QMessageBox msg(QMessageBox::Information, trUtf8("Цвет"), QString::number(v));
  QRect r(rect.toRect());
  double min = F->rezulto(F->minPoint(0.1));
  // Перебираю видимую область и каждую точку заполняю цветом в соответствии
  // со значением целевой функции.
//  QMessageBox msg(QMessageBox::Information, trUtf8("Границы области"), QString::number(r.x()) + " " + QString::number(r.y()) + " " + QString::number(r.right()) + " " + QString::number(r.bottom()));
//  msg.exec();
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
  using namespace std;
  update(-numeric_limits<int>::max()/2, -numeric_limits<int>::max()/2,
         numeric_limits<int>::max(), numeric_limits<int>::max());
}


qreal ScenoPorMapo::scale() const{
  return skalo;
}

