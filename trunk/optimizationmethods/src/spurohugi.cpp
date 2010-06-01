#include "spurohugi.h"
#include "Konstantoj.h"
#include <QPolygonF>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
//
spuroHuGi::spuroHuGi( QColor bazaKoloro, qreal Skalo, QGraphicsItem * parent )
	: spuro( A::HuGi, bazaKoloro, Skalo, parent), b1(0, 0){}
//

void spuroHuGi::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widge*/){
	painter->save();
	
	painter->setPen(BazaKoloro);
	if (B2gxisP.empty());else{
		painter->drawPolyline(aplikiScalo(B2gxisP));
		painter->drawLine(B1gxisB2.last(), B2gxisP.first());
	}
	if (B1gxisB2.empty());else{
		painter->drawPolyline(aplikiScalo(B1gxisB2));
		painter->drawLine(b1, B1gxisB2.first());
	}
	if (B2gxisP.empty());else{
		painter->drawEllipse(B2gxisP.last() * skalo, 2, 2);
		QGraphicsSimpleTextItem *P = new QGraphicsSimpleTextItem(trUtf8("P"), this);
		P->setPos(B2gxisP.last() * skalo + QPointF(2, 2));
		P->setPen(QPen(Qt::blue));
		P->setBrush(Qt::yellow);
	}
	if (B1gxisB2.empty());else{
		painter->drawEllipse(B1gxisB2.last() * skalo, 2, 2);
		QGraphicsSimpleTextItem *B2 = new QGraphicsSimpleTextItem(trUtf8("B2"), this);
		B2->setPos(B1gxisB2.last() * skalo + QPointF(2, 2));
		B2->setPen(QPen(Qt::blue));
		B2->setBrush(Qt::yellow);
	}
	painter->drawEllipse(b1 * skalo, 2, 2);
	QGraphicsSimpleTextItem *B1 = new QGraphicsSimpleTextItem(trUtf8("B1"), this);
	B1->setPos(b1 * skalo + QPointF(2, 2));
	B1->setPen(QPen(Qt::blue));
	B1->setBrush(Qt::yellow);
	
	painter->restore();
}

QRectF spuroHuGi::boundingRect() const{
	return B1gxisB2.boundingRect() | B2gxisP.boundingRect() | QRectF(b1, b1);
}

void spuroHuGi::difiniB1(QPointF & B1){
	prepareGeometryChange ();
	b1 = B1;
	B1gxisB2.clear();
	B2gxisP.clear();
}

void spuroHuGi::difiniB2(QPointF & B2){
	prepareGeometryChange ();
	B1gxisB2<<B2;
}

void spuroHuGi::difiniP(QPointF & P){
	if (B1gxisB2.empty());else{
		prepareGeometryChange ();
		B2gxisP<<P;
	}
}
