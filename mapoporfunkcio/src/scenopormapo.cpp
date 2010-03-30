#include "scenopormapo.h"
#include <QRect>
#include "funkcio.h"
#include <QColor>
#include <QPainter>
#include <QImage>
//#include <QString>
//#include <QMessageBox>
//
ScenoPorMapo::ScenoPorMapo( funkcio * Funkcio, QObject * parent)
  : QGraphicsScene(parent), F(Funkcio),
    mapo(4000, 4000, QImage::Format_ARGB32_Premultiplied){
  designiMapo();
}
ScenoPorMapo::ScenoPorMapo( funkcio * Funkcio, const QRectF & sceneRect, QObject * parent)
	: QGraphicsScene(sceneRect, parent), F(Funkcio),
    mapo(4000, 4000, QImage::Format_ARGB32_Premultiplied){
  designiMapo();
}
ScenoPorMapo::ScenoPorMapo( funkcio * Funkcio, qreal x, qreal y, qreal width, qreal height, QObject * parent)
	: QGraphicsScene(x, y, width, height, parent), F(Funkcio),
    mapo(4000, 4000, QImage::Format_ARGB32_Premultiplied){
  designiMapo();
}
//


void ScenoPorMapo::drawBackground(QPainter * painter, const QRectF & rect){
  painter->drawImage( QPoint(0, 0), mapo, rect);
}


void ScenoPorMapo::designiMapo()
{
  QColor koloro(Qt::red);
  qreal h, s, v;
  koloro.getHsvF(&h, &s, 0);
  QPainter painter(&mapo);
  double min = F->rezulto(F->minPoint(0.1)) ;
  // Перебираю видимую область и каждую точку заполняю цветом в соответствии
  // со значением целевой функции.
//  QMessageBox msg(QMessageBox::Information, trUtf8("Границы области"), QString::number(r.x()) + " " + QString::number(r.y()) + " " + QString::number(r.right()) + " " + QString::number(r.bottom()));
//  msg.exec();
  for(int i = -2000; i <= 2000; ++i){
    for(int j = -2000; j <= 2000; ++j){
      v = F->rezulto(i, j)-min;
      if(v > 255){
        v = 255;
      }else if(v < 0){
        v = 0;
      }
      koloro.setHsvF(h, s, v);
      painter.setPen(koloro);
      painter.drawPoint(i, j);
    }
  }
}

