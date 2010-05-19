#ifndef SPUROSINKOLAUXKOORDINATOJ_MD_H
#define SPUROSINKOLAUXKOORDINATOJ_MD_H
//
#include "spuro.h"
//
//! Отображает "след" покоординатного спуска с переменным шагом.
class spuroSinkoLauxKoordinatoj_md : public spuro
{
Q_OBJECT
private:
	//! Цвет текущей итерации.
	QColor MomentaKoloro;
	//! Точки прошедших итераций.
	QPolygonF Vosto;
	//! Точки текущей итерации.
	QPolygonF MomentaPointoj;
	//! Текущая точка.
	QPointF MomentaPointo;
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
	
	spuroSinkoLauxKoordinatoj_md(QColor momentaKoloro, //!< Цвет текущей итерации.
	                             QColor bazaKoloro, //!< Основной цвет "следа".
	                             qreal Skalo = 1, //!< Коэффициент масштаба.
	                             QGraphicsItem * parent = 0 //!< Элемент родитель.
	                            );
public slots:
	/*! Установить первую точку.
	 * 
	 * Устанавливает точку с которой начинается поиск.
	 */
	void difiniUnuaPointo( QPointF p );
	//! Перегружает difiniUnuaPointo(QPointF &p).
	void difiniUnuaPointo( qreal x, qreal y );
	/*! Завершить итерацию.
	 * 
	 * Делает последнюю точку из MomentaPointoj основной точкой текущей итерации.
	 * Переносит точки завершаемой итерации в "хвост".
	 * Заменяет список точек текущей итерации на вновь полученную основную точку текущей итерации.
	 */
	void finisxiIteracio();
	//! Добавить точку.
	void aldoniPointo(QPointF);
	//! Установить базовый цвет.
	void difiniBazaKoloro(QColor bazaKoloro);
	//! Установить текущий цвет.
	void difiniMomentaKoloro(QColor momentaKoloro);
	//! Очищает "след".
	void senspurigi();
};
#endif
