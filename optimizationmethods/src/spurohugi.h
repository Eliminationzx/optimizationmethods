#ifndef SPUROHUGI_H
#define SPUROHUGI_H
//
#include "spuro.h"
//
class spuroHuGi : public spuro
{
private:
	//! Точка B1.
//	QPointF b1;
	//! Точки от B1 до B2.
//	QPolygonF B1gxisB2;
	//! Точки от B2 до P.
//	QPolygonF B2gxisP;
public:
	spuroHuGi(
	          QColor bazaKoloro //!< Основной цвет "следа".
	         );
public slots:
	/*! Установить точку B1.
	 *
	 * Этот слот стирает старый след и переносит точку B1. difiniB2 и difiniP будут рисовать
	 * новый след.
	 */
	void difiniB1(QPointF & B1);
	//! Установить точку B2.
	void difiniB2(QPointF & B2);
	/*! Установить точку P.
	 *
	 * Вызывать её до difiniB2 бесполезно.
	 */
	void difiniP(QPointF & P);
};
#endif
