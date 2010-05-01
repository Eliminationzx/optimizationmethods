#include "demonstrataqpointf.h"
#include <QString>
#include <QMessageBox>
//
DemonstrataQPointF::DemonstrataQPointF()
	:QPointF(), sp(new SignalojPorPointF()){
	sp->SendiSignaloj(this);
}
DemonstrataQPointF::DemonstrataQPointF( const QPoint & point)
	:QPointF(point), sp(new SignalojPorPointF()){
	sp->SendiSignaloj(this);
}
DemonstrataQPointF::DemonstrataQPointF( const QPointF & point )
	:QPointF(point), sp(new SignalojPorPointF()){
	sp->SendiSignaloj(this);
}
DemonstrataQPointF::DemonstrataQPointF( qreal x, qreal y)
	:QPointF(x, y), sp(new SignalojPorPointF()){
	sp->SendiSignaloj(this);
}

DemonstrataQPointF::~DemonstrataQPointF(){
	delete sp;
}
//

void DemonstrataQPointF::setX(qreal x){
	QPointF::setX(x);
	sp->SendiSignaloj(this);
}

void DemonstrataQPointF::setY(qreal y){
	QPointF::setY(y);
	sp->SendiSignaloj(this);
}

QPointF & DemonstrataQPointF::operator*=(qreal factor){
	QPointF::operator*=(factor);
	sp->SendiSignaloj(this);
	return *this;
}

QPointF & DemonstrataQPointF::operator/=(qreal divisor){
	QPointF::operator/=(divisor);
	sp->SendiSignaloj(this);
	return *this;
}

QPointF & DemonstrataQPointF::operator+=(const QPointF & point){
	QPointF::operator+=(point);
	sp->SendiSignaloj(this);
	return *this;
}

QPointF & DemonstrataQPointF::operator-=(const QPointF & point){
	QPointF::operator-=(point);
	sp->SendiSignaloj(this);
	return *this;
}

QPointF & DemonstrataQPointF::operator=(const QPointF & point){
	QPointF::operator=(point);
	sp->SendiSignaloj(this);
	return *this;
}

QPointF & DemonstrataQPointF::operator=(const QPoint & point){
	QPointF::operator=(point);
	sp->SendiSignaloj(this);
	return *this;
}

bool DemonstrataQPointF::connectProviziValoro_QPointF(QObject * ricevanto, const char * slot)
{
	return QObject::connect(sp, SIGNAL(proviziValoro(const QPointF&)), ricevanto, slot);
}

bool DemonstrataQPointF::connectProviziValoro_QString(QObject * ricevanto, const char * slot)
{
	return QObject::connect(sp, SIGNAL(proviziValoro(const QString&)), ricevanto, slot);
}
