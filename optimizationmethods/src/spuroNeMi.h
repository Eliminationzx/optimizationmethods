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
	//! Цвет отражения/растяжения/зжатия.
	QColor MomentaKoloro;
	//! Первая точка основного триугольника.
	QPointF P1;
	//! Вторая точка основного триугольника.
	QPointF P2;
	//! Третья точка основного триугольника.
	QPointF P3;
	//! Полигон для отрисовки отражения/растяжения/зжатия.
	QPolygonF SP;
protected:
	//! Применяет масштаб к полигонам.
	virtual QPolygonF aplikiScalo(QPolygonF p);
public:
	//! Реализует отрисовку элемента.
	void paint(QPainter *painter, //!< Контекст рисования элемента.
	           const QStyleOptionGraphicsItem *option, //!< Опции стилей для элементов, такие как его состояние, область отображения и подсказки степени его детализации.
	           QWidget *widget = 0 //!< Указывает на виджет, который отрисовывается; в противном случае он равен 0. Для кэшированного рисования widget всегда равен 0.
	          );
	//! Возвращает приблизительную площадь отрисовываемую элементом.
	QRectF boundingRect() const;
	
	spuroNeMi(QColor momentaKoloro, //!< Цвет текущей итерации.
	                          QColor bazaKoloro, //!< Основной цвет "следа".
	                          qreal Skalo = 1, //!< Коэффициент масштаба.
	                          QGraphicsItem * parent = 0 //!< Элемент родитель.
	                         );
public slots:
	/*! Завершить итерацию.
	 */
	void finisxiIteracio();
	//! Установить первую точку.
	void difiniP1(QPointF &);
	//! Установить вторую точку.
	void difiniP2(QPointF &);
	//! Установить третью точку.
	void difiniP3(QPointF &);
	//! Установить точку отражения.
	void difiniPRespegulo(QPointF &);
	//! Установить точку растяжения.
	void difiniPDilato(QPointF &);
	//! Установить точку сжатия.
	void difiniPKompakto(QPointF &);
	//! Установить базовый цвет.
	void difiniBazaKoloro(QColor bazaKoloro);
	//! Установить текущий цвет.
	void difiniMomentaKoloro(QColor momentaKoloro);
	//! Очищает "след".
	void senspurigi();
};
#endif

/*! @class spuroNeMi
 * Этот "след" представляет собой ломаную линию, соединяющую установленные для него точки.
 * Рисует прошедшие итерации основным цветом - BazaKoloro, а текущую MomentaKoloro.
 *
 * Этот класс не проверяет логику прохождения алгоритма. Он лишь позволяет нарисовать "след" на сцене.
 *
 * Сразу же после создания "следа" необходимо задать начальную точку. Для этого используется слот void difiniUnuaPointo( QPointF p ).
 *
 * В классе создана основная точка итерации - MomentaPointo. Это точка вокруг которой ведётся поиск. Для каждой итерации эта точка должна быть обновлена.
 *
 * Чтобы добавить точку поиска воспользуйтесь слотом void aldoniSercxantaPointo(QPointF). Если точка поиска не оказалась меньше основной точки итерации, то вызовите слот void reveniAlMomentoPointo(). Не забывайте возвращаться назад.
 *
 * Если итерация закончена вызовите слот void finisxiIteracio(). Обратите внимание, что finisxiIteracio задаёт в качестве основной точки новой итерации последнюю точку из списка завершённой итерации. Не забывайте возвращаться назад с помощью reveniAlMomentoPointo().
 *
 * @author Василий Почкаенко.
 */