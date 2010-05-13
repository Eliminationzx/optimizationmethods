#include "demonstrataqpointf.h"
#include <math.h>
#include <QString>
#include <QMessageBox>

#include <QDebug>
//

void DemonstrataQPointF::setX(qreal x){
	QPointF::setX(x);
	// Высылаю сигналы, если есть объект SignalojPorPointF.
	if(sp != 0) sp->SendiSignaloj();
}

void DemonstrataQPointF::setY(qreal y){
	QPointF::setY(y);
	// Высылаю сигналы, если есть объект SignalojPorPointF.
	if(sp != 0) sp->SendiSignaloj();
}

QPointF & DemonstrataQPointF::operator*=(qreal factor){
	QPointF::operator*=(factor);
	// Высылаю сигналы, если есть объект SignalojPorPointF.
	if(sp != 0) sp->SendiSignaloj();
	return *this;
}

QPointF & DemonstrataQPointF::operator/=(qreal divisor){
	QPointF::operator/=(divisor);
	// Высылаю сигналы, если есть объект SignalojPorPointF.
	if(sp != 0) sp->SendiSignaloj();
	return *this;
}

QPointF & DemonstrataQPointF::operator+=(const QPointF & point){
	QPointF::operator+=(point);
	// Высылаю сигналы, если есть объект SignalojPorPointF.
	if(sp != 0) sp->SendiSignaloj();
	return *this;
}

QPointF & DemonstrataQPointF::operator-=(const QPointF & point){
	QPointF::operator-=(point);
	// Высылаю сигналы, если есть объект SignalojPorPointF.
	if(sp != 0) sp->SendiSignaloj();
	return *this;
}

QPointF & DemonstrataQPointF::operator=(const DemonstrataQPointF & point){
	QPointF::operator=(point);
	// Высылаю сигналы, если есть объект SignalojPorPointF.
	if(sp != 0) sp->SendiSignaloj();
	return *this;
}

QPointF & DemonstrataQPointF::operator=(const QPointF & point){
	QPointF::operator=(point);
	// Высылаю сигналы, если есть объект SignalojPorPointF.
	if(sp != 0) sp->SendiSignaloj();
	return *this;
}

QPointF & DemonstrataQPointF::operator=(const QPoint & point){
	QPointF::operator=(point);
	// Высылаю сигналы, если есть объект SignalojPorPointF.
	if(sp != 0) sp->SendiSignaloj();
	return *this;
}

qreal Length( const QPointF & p){
	return sqrt(p.x()*p.x() + p.y()*p.y());
}