#include "spurohugi.h"
#include "Konstantoj.h"
#include <QPolygonF>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
//
spuroHuGi::spuroHuGi( QColor bazaKoloro, qreal Skalo, QGraphicsItem * parent )
	: spuro( A::HuGi, bazaKoloro, Skalo, parent){
	
}
//

void spuroHuGi::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widge*/){
	painter->save();
	
	
	painter->restore();
}

QRectF spuroHuGi::boundingRect() const{
}

void spuroHuGi::difiniB1(QPointF & B1){
	
}

void spuroHuGi::difiniB2(QPointF & B2){
	
}

void spuroHuGi::difiniP(QPointF & P){
	
}
