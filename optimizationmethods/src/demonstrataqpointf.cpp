#include "demonstrataqpointf.h"
#include <QString>
//
DemonstrataQPointF::DemonstrataQPointF( qreal x, qreal y ) 
  : QPointF(x, y), QObject(parent){
  emit proviziXValoro((int)(this->x()));
  emit proviziXValoro((double)(this->x()));  
  emit proviziXValoro(QString::number(this->x()));  
  emit proviziYValoro((int)(this->y()));
  emit proviziYValoro((double)(this->y()));  
  emit proviziYValoro(QString::number(this->y()));  
}
DemonstrataQPointF::DemonstrataQPointF( const QPoint & point, const QObject * parent ) 
  : QPointF(point), QObject(parent){
  emit proviziXValoro((int)(this->x()));
  emit proviziXValoro((double)(this->x()));  
  emit proviziXValoro(QString::number(this->x()));  
  emit proviziYValoro((int)(this->y()));
  emit proviziYValoro((double)(this->y()));  
  emit proviziYValoro(QString::number(this->y()));  
}
//


void DemonstrataQPointF::setX(qreal x){
  QPointF::setX(x);
  emit proviziXValoro((int)x);
  emit proviziXValoro((double)x);  
  emit proviziXValoro(QString::number(x));  
}

void DemonstrataQPointF::setY(qreal y){
  QPointF::setY(y);
  emit proviziYValoro((int)y);
  emit proviziYValoro((double)y);  
  emit proviziYValoro(QString::number(y));  
}


QPointF & DemonstrataQPointF::operator*=(qreal factor)
{
  QPointF::operator*=(factor);
  emit proviziXValoro((int)(this->x()));
  emit proviziXValoro((double)(this->x()));  
  emit proviziXValoro(QString::number(this->x()));  
  emit proviziYValoro((int)(this->y()));
  emit proviziYValoro((double)(this->y()));  
  emit proviziYValoro(QString::number(this->y()));  
  return QPointF::operator*=(1);
}


QPointF & DemonstrataQPointF::operator/=(qreal divisor)
{
  QPointF::operator/=(divisor);
  emit proviziXValoro((int)(this->x()));
  emit proviziXValoro((double)(this->x()));  
  emit proviziXValoro(QString::number(this->x()));  
  emit proviziYValoro((int)(this->y()));
  emit proviziYValoro((double)(this->y()));  
  emit proviziYValoro(QString::number(this->y()));  
  return QPointF::operator*=(1);
}


QPointF & DemonstrataQPointF::operator+=(const QPointF & point)
{
  QPointF::operator+=(point);
  emit proviziXValoro((int)(this->x()));
  emit proviziXValoro((double)(this->x()));  
  emit proviziXValoro(QString::number(this->x()));  
  emit proviziYValoro((int)(this->y()));
  emit proviziYValoro((double)(this->y()));  
  emit proviziYValoro(QString::number(this->y()));  
  return QPointF::operator*=(1);
}


QPointF & DemonstrataQPointF::operator-=(const QPointF & point)
{
  QPointF::operator-=(point);
  emit proviziXValoro((int)(this->x()));
  emit proviziXValoro((double)(this->x()));  
  emit proviziXValoro(QString::number(this->x()));  
  emit proviziYValoro((int)(this->y()));
  emit proviziYValoro((double)(this->y()));  
  emit proviziYValoro(QString::number(this->y())); 
  return QPointF::operator*=(1);
}