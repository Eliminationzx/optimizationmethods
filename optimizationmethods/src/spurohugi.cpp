#include "spurohugi.h"
#include "Konstantoj.h"
#include <QPolygonF>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
//
spuroHuGi::spuroHuGi( QColor momentaKoloro, QColor bazaKoloro, qreal Skalo,
                      QGraphicsItem * parent )
	: spuro( A::HuGi, bazaKoloro, Skalo, parent){
	
}
//
