#include "demonstrataqpointf.h"
#include <QString>
#include <QMessageBox>
//
DemonstrataQPointF::DemonstrataQPointF( qreal x, qreal y, QObject * parent ) 
  : QObject(parent), QPointF(x, y){
  emit proviziXValoro((int)(this->x()));
  emit proviziXValoro((double)(this->x()));  
  QString s = QString::number(this->x());
  emit proviziXValoro(s);  
  emit proviziYValoro((int)(this->y()));
  emit proviziYValoro((double)(this->y())); 
  s = QString::number(this->y());
  emit proviziYValoro(s);  
}
DemonstrataQPointF::DemonstrataQPointF( const DemonstrataQPointF & point, QObject * parent ) 
  : QObject(parent), QPointF(point){
  emit proviziXValoro((int)(this->x()));
  emit proviziXValoro((double)(this->x()));  
  QString s = QString::number(this->x());
  emit proviziXValoro(s);  
  emit proviziYValoro((int)(this->y()));
  emit proviziYValoro((double)(this->y()));  
  s = QString::number(this->y());
  emit proviziYValoro(s);  

}
DemonstrataQPointF::DemonstrataQPointF( const QPointF & point, QObject * parent ) 
  : QObject(parent), QPointF(point){
  emit proviziXValoro((int)(this->x()));
  emit proviziXValoro((double)(this->x()));  
  QString s = QString::number(this->x());
  emit proviziXValoro(s);  
  emit proviziYValoro((int)(this->y()));
  emit proviziYValoro((double)(this->y()));  
  s = QString::number(this->y());
  emit proviziYValoro(s);  

}
//


void DemonstrataQPointF::setX(qreal x){
  QPointF::setX(x);
  emit proviziXValoro((int)x);
  emit proviziXValoro((double)x);  
  QString s = QString::number(this->x());
  emit proviziXValoro(x);  
}

void DemonstrataQPointF::setY(qreal y){
  QPointF::setY(y);
  emit proviziYValoro((int)y);
  emit proviziYValoro((double)y);  
  QString s = QString::number(this->y());
  emit proviziYValoro(s);  
}


QPointF & DemonstrataQPointF::operator=(const DemonstrataQPointF & p){
  return QPointF::operator=(p);
}


QPointF & DemonstrataQPointF::operator*=(qreal factor)
{
  QPointF::operator*=(factor);
  /*emit proviziXValoro((int)(this->x()));
  emit proviziXValoro((double)(this->x()));  
  QString s = QString::number(this->x());
  emit proviziXValoro(s);  
  emit proviziYValoro((int)(this->y()));
  emit proviziYValoro((double)(this->y()));  
  s = QString::number(this->y());
  emit proviziYValoro(s); */ 

  return QPointF::operator*=(1);
}


QPointF & DemonstrataQPointF::operator/=(qreal divisor)
{
  QPointF::operator/=(divisor);
  /*emit proviziXValoro((int)(this->x()));
  emit proviziXValoro((double)(this->x()));  
  QString s = QString::number(this->x());
  emit proviziXValoro(s);  
  emit proviziYValoro((int)(this->y()));
  emit proviziYValoro((double)(this->y()));  
  s = QString::number(this->y());
  emit proviziYValoro(s);  */

  return QPointF::operator*=(1);
}


QPointF & DemonstrataQPointF::operator+=(const DemonstrataQPointF & point)
{
  QPointF::operator+=(point);
  /*emit proviziXValoro((int)(this->x()));
  emit proviziXValoro((double)(this->x()));  
  QString s = QString::number(this->x());
  emit proviziXValoro(s);  
  emit proviziYValoro((int)(this->y()));
  emit proviziYValoro((double)(this->y()));  
  s = QString::number(this->y());
  emit proviziYValoro(s);  */

  return QPointF::operator*=(1);
}


QPointF & DemonstrataQPointF::operator-=(const DemonstrataQPointF & point)
{
  QPointF::operator-=(point);
/*  emit proviziXValoro((int)(this->x()));
  emit proviziXValoro((double)(this->x()));  
  QString s = QString::number(this->x());
  emit proviziXValoro(s);  
  emit proviziYValoro((int)(this->y()));
  emit proviziYValoro((double)(this->y()));  
  s = QString::number(this->y());
  emit proviziYValoro(s); */
  return QPointF::operator*=(1);
}

QPointF & DemonstrataQPointF::AlQPointF(){
  return QPointF::operator*=(1);
}