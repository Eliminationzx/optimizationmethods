#ifndef __SPECTROGRAMDATA_H__
#define __SPECTROGRAMDATA_H__
#include <qwt_raster_data.h>

class funkcio;

class SpectrogramData: public QwtRasterData
{
private:
	//! Целевая функция.
	const funkcio * f;
	
	qreal max;
	
	qreal min;
public:
	SpectrogramData(const funkcio * F);
	
	virtual QwtRasterData * copy() const;
	
	//! Возвращает растояние от нименьшей точки, до наибольшой в переделах сцены.
	virtual QwtDoubleInterval range() const;
	
	//! Возвращает значение в точке.
	virtual double value(double x, double y) const;
};

#endif // __SPECTROGRAMDATA_H__
