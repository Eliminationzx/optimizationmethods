#include "demonstrataqpointf.h"
#include <QString>
#include <QMessageBox>
//
DemonstrataQPointF::DemonstrataQPointF( QObject * parent )
	:QObject(parent){}
DemonstrataQPointF::DemonstrataQPointF( const QPoint & point, QObject * parent )
	:QObject(parent), p(point){}
DemonstrataQPointF::DemonstrataQPointF( qreal x, qreal y, QObject * parent )
	:QObject(parent), p(x, y){}
DemonstrataQPointF::DemonstrataQPointF( DemonstrataQPointF & DP){
	
}
//


void DemonstrataQPointF::setX(qreal x){
	p.setX(x);
}

void DemonstrataQPointF::setY(qreal y){
	p.setY(y);
}

QPointF & DemonstrataQPointF::operator*=(qreal factor){
}

QPointF & DemonstrataQPointF::operator/=(qreal divisor){
}

QPointF & DemonstrataQPointF::operator+=(const DemonstrataQPointF & point){
}

QPointF & DemonstrataQPointF::operator-=(const DemonstrataQPointF & point){
}
