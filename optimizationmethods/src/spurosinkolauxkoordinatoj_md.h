#ifndef SPUROSINKOLAUXKOORDINATOJ_MD_H
#define SPUROSINKOLAUXKOORDINATOJ_MD_H
//
#include "spuro.h"
#include <QPolygonF>
//
class QwtPlotCurve;
//! Отображает "след" покоординатного спуска с минимизацией по направлению.
class spuroSinkoLauxKoordinatoj_md : public spuro
{
Q_OBJECT
private:
	QwtPlotCurve * vosto;
	//! Точки прошедших итераций.
	QPolygonF Vosto;
	//! Текущая точка.
	QwtPlotCurve * MomentaPointo;
	double x;
	double y;
public:
	//! Устанавливает полотно, на котором будет нарисован след.
	void difiniPlt( QwtPlot * Plt );
	
	spuroSinkoLauxKoordinatoj_md(QColor bazaKoloro, //!< Основной цвет "следа".
	                             QwtPlot * Plt = 0 //!< Полотно, на котором будет нарисован след.
	                            );
public slots:
	//! Добавить точку.
	void aldoniPointo( const QPointF & p );
	//! Очищает "след".
	void senspurigi();
};
#endif
