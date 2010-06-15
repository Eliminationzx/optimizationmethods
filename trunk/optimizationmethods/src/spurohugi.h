#ifndef SPUROHUGI_H
#define SPUROHUGI_H
//
#include "spuro.h"
//
class spuroHuGi : public spuro
{
private:
	//! Точка B1.
	QPointF b1;
	//! Точки от B1 до B2.
	QPolygonF B1gxisB2;
	//! Точки от B2 до P.
	QPolygonF B2gxisP;
public:
	//! Реализует отрисовку элемента.
	void paint(QPainter *painter, //!< Контекст рисования элемента.
	           const QStyleOptionGraphicsItem *option, //!< Опции стилей для элементов, такие как его состояние, область отображения и подсказки степени его детализации.
	           QWidget *widget = 0 //!< Указывает на виджет, который отрисовывается; в противном случае он равен 0. Для кэшированного рисования widget всегда равен 0.
	          );
	//! Возвращает приблизительную площадь отрисовываемую элементом.
	QRectF boundingRect() const;
	
	spuroHuGi( QColor bazaKoloro, //!< Основной цвет "следа".
	           qreal Skalo = 1, //!< Коэффициент масштаба.
	           QGraphicsItem * parent = 0 //!< Элемент родитель.
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
	//! Очищает "след".
	void senspurigi(){};
};
#endif
