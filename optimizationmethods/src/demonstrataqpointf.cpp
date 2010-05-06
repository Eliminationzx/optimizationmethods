#include "demonstrataqpointf.h"
#include <math.h>
#include <QString>
#include <QMessageBox>
//

void DemonstrataQPointF::setX(qreal x){
	QPointF::setX(x);
	if(sp != 0) sp->SendiSignaloj();
}

void DemonstrataQPointF::setY(qreal y){
	QPointF::setY(y);
	if(sp != 0) sp->SendiSignaloj();
}

QPointF & DemonstrataQPointF::operator*=(qreal factor){
	QPointF::operator*=(factor);
	if(sp != 0) sp->SendiSignaloj();
	return *this;
}

QPointF & DemonstrataQPointF::operator/=(qreal divisor){
	QPointF::operator/=(divisor);
	if(sp != 0) sp->SendiSignaloj();
	return *this;
}

QPointF & DemonstrataQPointF::operator+=(const QPointF & point){
	QPointF::operator+=(point);
	if(sp != 0) sp->SendiSignaloj();
	return *this;
}

QPointF & DemonstrataQPointF::operator-=(const QPointF & point){
	QPointF::operator-=(point);
	if(sp != 0) sp->SendiSignaloj();
	return *this;
}

QPointF & DemonstrataQPointF::operator=(const QPointF & point){
	QPointF::operator=(point);
	if(sp != 0) sp->SendiSignaloj();
	return *this;
}

QPointF & DemonstrataQPointF::operator=(const QPoint & point){
	QPointF::operator=(point);
	if(sp != 0) sp->SendiSignaloj();
	return *this;
}

qreal Length( const QPointF & p){
	return sqrt(p.x()*p.x() + p.y()*p.y());
}