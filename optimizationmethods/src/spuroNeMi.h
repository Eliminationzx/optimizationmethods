#ifndef SPUROSINKOLAUXKOORDINATOJ_H
#define SPUROSINKOLAUXKOORDINATOJ_H
//
#include "spuro.h"
//
//! Отображает "след" по координатного спуска с дискретным шагом.
class spuroNeMi : public spuro
{
Q_OBJECT
private:
	//! Цвет отражения/растяжения/сжатия.
	QColor MomentaKoloro;
	//! Первая точка основного треугольника.
	QPointF P1;
	//! Вторая точка основного треугольника.
	QPointF P2;
	//! Третья точка основного треугольника.
	QPointF P3;
	//! Полигон для отрисовки отражения/растяжения/зжатия.
	QPolygonF SP;
public:
	//! Реализует отрисовку элемента.
	void paint(QPainter *painter, //!< Контекст рисования элемента.
	           const QStyleOptionGraphicsItem *option, //!< Опции стилей для элементов, такие как его состояние, область отображения и подсказки степени его детализации.
	           QWidget *widget = 0 //!< Указывает на виджет, который отрисовывается; в противном случае он равен 0. Для кэшированного рисования widget всегда равен 0.
	          );
	//! Возвращает приблизительную площадь отрисовываемую элементом.
	QRectF boundingRect() const;
	
	spuroNeMi(QColor momentaKoloro, //!< Текущий цвет "следа".
	          QColor bazaKoloro, //!< Основной цвет "следа".
	          qreal Skalo = 1, //!< Коэффициент масштаба.
	          QGraphicsItem * parent = 0 //!< Элемент родитель.
	         );
public slots:
	/*! Завершить итерацию.
	 */ 
	void finisxiIteracio();
	//! Установить первую точку.
	void difiniP1(const QPointF &);
	//! Установить вторую точку.
	void difiniP2(const QPointF &);
	//! Установить третью точку.
	void difiniP3(const QPointF &);
	//! Установить точку отражения.
	void difiniPRespegulo(const QPointF &);
	//! Установить точку растяжения.
	void difiniPDilato(const QPointF &);
	//! Установить точку сжатия.
	void difiniPKompakto(const QPointF &);
	//! Установить базовый цвет.
	void difiniBazaKoloro(QColor bazaKoloro);
	//! Установить текущий цвет.
	void difiniMomentaKoloro(QColor momentaKoloro);
	//! Очищает "след".
	void senspurigi();
};
#endif

/*! @class spuroNeMi
 * Этот "след" представляет собой треугольник - "перекати поле". Сам
 * треугольник рисуется основным цветом(BazaKoloro), а точки поиска текущим
 * цветом (MomentaKoloro).
 * Для установки вершин треугольника используются методы difiniP1, difiniP2 и
 * difiniP3. Для установки точки отражения, тоски растяжения и точки сжатия
 * используются соответственно difiniPRespegulo, difiniPDilato и
 * difiniPKompakto.
 * В конце каждой итерации следует вызывать метод finisxiIteracio, который
 * очистит точки поиска.
 *
 * @author Василий Почкаенко.
 */