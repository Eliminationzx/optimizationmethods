#include "demonstrataqpointf.h"
#include <QString>
#include <QMessageBox>
//
DemonstrataQPointF::DemonstrataQPointF(funkcio * F)
	:QPointF(){
	sp = new SignalojPorPointF(this, F);
	sp->SendiSignaloj();
}
DemonstrataQPointF::DemonstrataQPointF( const QPoint & point, funkcio * F)
	:QPointF(point){
	sp = new SignalojPorPointF(this, F);
	sp->SendiSignaloj();
}
DemonstrataQPointF::DemonstrataQPointF( const QPointF & point, funkcio * F )
	:QPointF(point){
	sp = new SignalojPorPointF(this, F);
	sp->SendiSignaloj();
}
DemonstrataQPointF::DemonstrataQPointF( qreal x, qreal y, funkcio * F)
	:QPointF(x, y){
	sp = new SignalojPorPointF(this, F);
	sp->SendiSignaloj();
}

DemonstrataQPointF::~DemonstrataQPointF(){
	delete sp;
}
//

void DemonstrataQPointF::setX(qreal x){
	QPointF::setX(x);
	sp->SendiSignaloj();
}

void DemonstrataQPointF::setY(qreal y){
	QPointF::setY(y);
	sp->SendiSignaloj();
}

QPointF & DemonstrataQPointF::operator*=(qreal factor){
	QPointF::operator*=(factor);
	sp->SendiSignaloj();
	return *this;
}

QPointF & DemonstrataQPointF::operator/=(qreal divisor){
	QPointF::operator/=(divisor);
	sp->SendiSignaloj();
	return *this;
}

QPointF & DemonstrataQPointF::operator+=(const QPointF & point){
	QPointF::operator+=(point);
	sp->SendiSignaloj();
	return *this;
}

QPointF & DemonstrataQPointF::operator-=(const QPointF & point){
	QPointF::operator-=(point);
	sp->SendiSignaloj();
	return *this;
}

QPointF & DemonstrataQPointF::operator=(const QPointF & point){
	QPointF::operator=(point);
	sp->SendiSignaloj();
	return *this;
}

QPointF & DemonstrataQPointF::operator=(const QPoint & point){
	QPointF::operator=(point);
	sp->SendiSignaloj();
	return *this;
}

bool DemonstrataQPointF::connectProviziValoro_QPointF(QObject * ricevanto, const char * slot){
	return QObject::connect(sp, SIGNAL(proviziValoro(const QPointF&)), ricevanto, slot);
}

bool DemonstrataQPointF::connectProviziValoro_QString(QObject * ricevanto, const char * slot){
	return QObject::connect(sp, SIGNAL(proviziValoro(const QString&)), ricevanto, slot);
}

bool DemonstrataQPointF::connectProviziXValoro_QString(QObject * ricevanto, const char * slot){
	return QObject::connect(sp, SIGNAL(proviziXValoro(const QString&)), ricevanto, slot);
}

bool DemonstrataQPointF::connectProviziXValoro_double(QObject * ricevanto, const char * slot){
	return QObject::connect(sp, SIGNAL(proviziXValoro(double)), ricevanto, slot);
}

bool DemonstrataQPointF::connectProviziXValoro_int(QObject * ricevanto, const char * slot){
	return QObject::connect(sp, SIGNAL(proviziXValoro(int)), ricevanto, slot);
}

bool DemonstrataQPointF::connectProviziYValoro_QString(QObject * ricevanto, const char * slot){
	return QObject::connect(sp, SIGNAL(proviziYValoro(const QString&)), ricevanto, slot);
}

bool DemonstrataQPointF::connectProviziYValoro_double(QObject * ricevanto, const char * slot){
	return QObject::connect(sp, SIGNAL(proviziYValoro(double)), ricevanto, slot);
}

bool DemonstrataQPointF::connectProviziYValoro_int(QObject * ricevanto, const char * slot){
	return QObject::connect(sp, SIGNAL(proviziYValoro(int)), ricevanto, slot);
}

bool DemonstrataQPointF::connectProviziValoroFukcioEnPointo_QString(QObject * ricevanto, const char * slot){
	return QObject::connect(sp, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), ricevanto, slot);
}

bool DemonstrataQPointF::connectProviziValoroFukcioEnPointo_double(QObject * ricevanto, const char * slot){
	return QObject::connect(sp, SIGNAL(proviziValoroFukcioEnPointo(double)), ricevanto, slot);
}

qreal Length( const QPointF & p){
	return sqrt(p.x()*p.x() + p.y()*p.y());
}