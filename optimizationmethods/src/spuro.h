#ifndef SPURO_H
#define SPURO_H
//
#include <QObject>
#include <QColor>
#include <QPointF>
#include "Konstantoj.h"
//
class QwtPlot;
//! Базовый класс для отображения "следа" алгоритма.
class spuro : public QObject
{
Q_OBJECT
protected:
	//! Основной цвет "следа".
	QColor BazaKoloro;
	
	//! Полотно, на котором будет нарисован след.
	QwtPlot * plt;
public:
	//! Возвращает значение основного цвета.
	inline QColor proviziBazaKoloro() const { return BazaKoloro; };
	
	//! Устанавливает значение основного цвета.
	inline void difiniBazaKoloro( QColor bazaKoloro ) { BazaKoloro = bazaKoloro; };
	
	//! Возвращает полотно, на котором будет нарисован след.
	inline QwtPlot * proviziPlt() const { return plt; };
	
	//! Устанавливает полотно, на котором будет нарисован след.
	void difiniPlt( QwtPlot * Plt );
	
	spuro(
	      const QColor bazaKoloro, //!< Основной цвет "следа".
	      QwtPlot * Plt = 0 //!< Полотно, на котором будет нарисован след.
	     ): BazaKoloro(bazaKoloro), plt(Plt) {};
};
#endif

/*! @class spuro
 * Этот класс не проверяет логику прохождения алгоритма. Он лишь позволяет 
 * нарисовать "след" на сцене.
 * 
 * @author Василий Почкаенко.
 */
