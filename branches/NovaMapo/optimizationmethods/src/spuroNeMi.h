#ifndef SPUROSINKOLAUXKOORDINATOJ_H
#define SPUROSINKOLAUXKOORDINATOJ_H
//
#include "spuro.h"
#include <QPolygonF>
//
class QwtPlotCurve;
class funkcio;
//! Отображает "след" покоординатного спуска с дискретным шагом.
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
	//! Треугольник.
	QwtPlotCurve * triangulo;
	//! Полигон для отрисовки отражения/растяжения/зжатия.
	QPolygonF SP;
	QwtPlotCurve * sp;
	//! Указатель на целевую функцию.
	funkcio * f;
	
	bool menshe( const QPointF & p1, const QPointF & p2 );
	bool bolshe( const QPointF & p1, const QPointF & p2 );
	//! Наименьшая из 2 точек. Если точки равны вернёт первую.
	const QPointF & minValue( const QPointF & p1, const QPointF & p2);
	//! Наибольшая из 2 точек. Если точки равны вернёт первую.
	const QPointF & maxValue( const QPointF & p1, const QPointF & p2);
public:
	//! Устанавливает полотно, на котором будет нарисован след.
	void difiniPlt( QwtPlot * Plt );
	

	spuroNeMi(QColor momentaKoloro, //!< Текущий цвет "следа".
	          QColor bazaKoloro, //!< Основной цвет "следа".
	          funkcio *F //!< Указатель на целевую функцию.
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