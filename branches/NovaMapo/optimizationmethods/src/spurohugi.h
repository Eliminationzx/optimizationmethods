#ifndef SPUROHUGI_H
#define SPUROHUGI_H
//
#include "spuro.h"
#include <QPolygonF>
//
class QwtPlotCurve;
class QwtPlotMarker;
//! Отображает "след" метода Хука-Дживса.
class spuroHuGi : public spuro{
Q_OBJECT
private:
	//! Точка B1.
	QPointF b1;
	QwtPlotMarker * p1;
//	QwtPlotMarker * B1;
	//! Точки от B1 до B2.
	QPolygonF B1gxisB2;
	QwtPlotCurve * b1gxisb2;
	QwtPlotMarker * p2;
	//! Точки от B2 до P.
	QPolygonF B2gxisP;
	QwtPlotCurve * b2gxisp;
	QwtPlotMarker * p;
public:
	//! Устанавливает полотно, на котором будет нарисован след.
	void difiniPlt( QwtPlot * Plt );
	
	spuroHuGi(
	          QColor bazaKoloro //!< Основной цвет "следа".
	         );
public slots:
	/*! Установить точку B1.
	 *
	 * Этот слот стирает старый след и переносит точку B1. difiniB2 и difiniP будут рисовать
	 * новый след.
	 */
	void difiniB1(const QPointF & B1);
	//! Установить точку B2.
	void difiniB2(const QPointF & B2);
	/*! Установить точку P.
	 *
	 * Вызывать её до difiniB2 бесполезно.
	 */
	void difiniP(const QPointF & P);
	//! Очищает "след".
	void senspurigi();
};
#endif
