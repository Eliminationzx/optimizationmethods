#include "demonstrataqpointf.h"
#include <QString>
#include <QMessageBox>
//
DemonstrataQPointF::DemonstrataQPointF()
	:QPointF(){}
DemonstrataQPointF::DemonstrataQPointF( const QPoint & point)
	:QPointF(point){}
DemonstrataQPointF::DemonstrataQPointF( const QPointF & point )
	:QPointF(point){}
DemonstrataQPointF::DemonstrataQPointF( qreal x, qreal y)
	:QPointF(x, y){}
//

void DemonstrataQPointF::setX(qreal x){
	QPointF::setX(x);
}

void DemonstrataQPointF::setY(qreal y){
	QPointF::setY(y);
}

QPointF & DemonstrataQPointF::operator*=(qreal factor){
	QPointF::operator*=(factor);
}

QPointF & DemonstrataQPointF::operator/=(qreal divisor){
	QPointF::operator/=(divisor);
/*  emit proviziValoro(p);
  emit proviziValoro(trUtf8("%1; %2").arg(QString::number(p.x())).arg(QString::number(p.y())));
  emit proviziYValoro(p.toPoint().x());
  emit proviziYValoro(p.x());
  emit proviziYValoro(QString::number(p.x()));*/
}

QPointF & DemonstrataQPointF::operator+=(const QPointF & point){
}

QPointF & DemonstrataQPointF::operator-=(const QPointF & point){
}
