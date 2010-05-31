#ifndef SPUROHUGI_H
#define SPUROHUGI_H
//
#include "spuro.h"
//
class spuroHuGi : public spuro
{
private:
	//! Точка B1.
	QPointF B1;
	//! Точка B2.
	QPointF B2;
	//! Точка образца.
	QPointF P;
	//! Точки от B1 до B2.
	QPolygonF B1gxisB2;
	//! Точки от B2 до P.
	QPolygonF B2gxisP;
public:
	spuroHuGi( QColor bazaKoloro, //!< Основной цвет "следа".
	           qreal Skalo = 1, //!< Коэффициент масштаба.
	           QGraphicsItem * parent = 0 //!< Элемент родитель.
	         );
	
};
#endif
