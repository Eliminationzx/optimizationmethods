#ifndef SPURO_H
#define SPURO_H
//
#include <QGraphicsItem>
#include <QObject>
#include "Konstantoj.h"
//
//! Базовый класс для отображения "следа" алгоритма.
class spuro : public QObject , public QGraphicsItem
{
Q_OBJECT
protected:
	//! Порядковый номер алгоритма.
	/*! @see A.
	 * 
	 */
	int IDAlgoritmo;
	//! Основной цвет "следа".
	QColor BazaKoloro;
	//! Коэффициент масштаба.
	qreal skalo;
	/*! Флаг заглушки.
	 *
	 * true если объект - заглушка.
	 * false если объект след для конкретного алгоритма.
	 */
	bool empty;
public:
	bool isEmpty() const { return empty; };
	//! Реализует отрисовку элемента.
	virtual void paint(QPainter *, //!< Контекст рисования элемента. Пустая реализция для заглушки.
	           const QStyleOptionGraphicsItem *, //!< Опции стилей для элементов, такие как его состояние, область отображения и подсказки степени его детализации.
	           QWidget *widget = 0 //!< Указывает на виджет, который отрисовывается; в противном случае он равен 0. Для кэшированного рисования widget всегда равен 0.
	          ){};
	//! Возвращает приблизительную площадь отрисовываемую элементом. Пустая реализция для заглушки.
	virtual QRectF boundingRect() const{ return QRectF(); };
	//! Возвращает масштаб.
	qreal scale() const;
	//! Устанавливает масштаб.
	/*! @param factor Множитель масштабирования. factor = 1 - масштаб 1:1.
	 */
	void setScale(qreal factor);
	//! Возвращает порядковый номер алгоритма.
	inline int proviziIdAlgoritmo() const { return IDAlgoritmo; };
	/*! Возвращает значение основного цвета.
	 * 
	 * @see A.
	 */
	inline QColor proviziBazaKoloro() const { return BazaKoloro; };
	
	spuro(int IdAlgoritmo, //!< Порядковый номер алгоритма(см. A).
	      QColor bazaKoloro, //!< Основной цвет "следа".
	      qreal Skalo = 1, //!< Коэффициент масштаба.
	      QGraphicsItem * parent = 0 //!< Элемент родитель.
	     );
	//! Конструктор для заглушки.
	spuro(
	      QGraphicsItem * parent = 0 //!< Элемент родитель.
	     );
};
#endif

/*! @class spuro
 * Этот класс не проверяет логику прохождения алгоритма. Он лишь позволяет нарисовать "след" на сцене.
 * 
 * @author Василий Почкаенко.
 */
