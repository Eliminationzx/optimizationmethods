#ifndef SPUROSINKOLAUXKOORDINATOJ_MD_H
#define SPUROSINKOLAUXKOORDINATOJ_MD_H
//
#include "spuro.h"
//
//! Отображает "след" покоординатного спуска с минимизацией по направлению.
class spuroSinkoLauxKoordinatoj_md : public spuro
{
Q_OBJECT
private:
	//! Цвет текущей итерации.
	QColor MomentaKoloro;
	//! Точки прошедших итераций.
//	QPolygonF Vosto;
	//! Точки текущей итерации.
//	QPolygonF MomentaPointoj;
	//! Текущая точка.
//	QPointF MomentaPointo;
public:
	spuroSinkoLauxKoordinatoj_md(QColor momentaKoloro, //!< Цвет текущей итерации.
	                             QColor bazaKoloro //!< Основной цвет "следа".
	                            );
public slots:
	/*! Установить первую точку.
	 * 
	 * Устанавливает точку с которой начинается поиск.
	 */
	void difiniUnuaPointo(const QPointF & p );
	//! Перегружает difiniUnuaPointo(QPointF &p).
	void difiniUnuaPointo( qreal x, qreal y );
	//! Добавить точку.
	void aldoniPointo( const QPointF & p );
	//! Установить текущий цвет.
	void difiniMomentaKoloro(QColor momentaKoloro);
	//! Очищает "след".
	void senspurigi();
};
#endif
