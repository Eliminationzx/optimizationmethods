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
DemonstrataQPointF::DemonstrataQPointF( DemonstrataQPointF & DP)
	:p(DP.toPointF()){}
//


void DemonstrataQPointF::setX(qreal x){
	p.setX(x);
  emit proviziValoro(p);
  emit proviziValoro(trUtf8("%1; %2").arg(QString::number(p.x())).arg(QString::number(p.y())));
  emit proviziXValoro(p.toPoint().x());
  emit proviziXValoro(p.x());
  emit proviziXValoro(QString::number(p.x()));
}

void DemonstrataQPointF::setY(qreal y){
	p.setY(y);
  emit proviziValoro(p);
  emit proviziValoro(trUtf8("%1; %2").arg(QString::number(p.x())).arg(QString::number(p.y())));
  emit proviziYValoro(p.toPoint().x());
  emit proviziYValoro(p.x());
  emit proviziYValoro(QString::number(p.x()));
}

qreal DemonstrataQPointF::x() const{ return p.x(); }
qreal DemonstrataQPointF::y() const{ return p.y(); }

QPoint DemonstrataQPointF::toPoint() const{ return p.toPoint(); }

QPointF DemonstrataQPointF::toPointF() const{ return p; }

QPointF & DemonstrataQPointF::operator*=(qreal factor){
}

QPointF & DemonstrataQPointF::operator/=(qreal divisor){
}

QPointF & DemonstrataQPointF::operator+=(const DemonstrataQPointF & point){
}

QPointF & DemonstrataQPointF::operator-=(const DemonstrataQPointF & point){
}
