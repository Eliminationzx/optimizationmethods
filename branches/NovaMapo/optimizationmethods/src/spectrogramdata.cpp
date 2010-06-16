#include "spectrogramdata.h"
#include "funkcio.h"
#include "Konstantoj.h"
#include <QDebug>
#include <QVector>

SpectrogramData::SpectrogramData(const funkcio * F, qreal MIN)
	: QwtRasterData(QwtDoubleRect(-ampleksoMapo, -ampleksoMapo, 2*ampleksoMapo, 2*ampleksoMapo)), f(F){
//	QVector<double> minPointo(f->minPoint(0.00000000001));
	min = MIN;
	//--Ищу точку приближенную к максимальной в области карты.---------------------
	max = F->rezulto(ampleksoMapo, ampleksoMapo);
	if (F->rezulto(ampleksoMapo, -ampleksoMapo) > max) max = F->rezulto(ampleksoMapo, -ampleksoMapo);
	if (F->rezulto(-ampleksoMapo, ampleksoMapo) > max) max = F->rezulto(-ampleksoMapo, ampleksoMapo);
	if (F->rezulto(-ampleksoMapo, -ampleksoMapo) > max) max = F->rezulto(-ampleksoMapo, -ampleksoMapo);
	if (F->rezulto(0, ampleksoMapo) > max) max = F->rezulto(0, ampleksoMapo);
	if (F->rezulto(0, -ampleksoMapo) > max) max = F->rezulto(0, -ampleksoMapo);
	if (F->rezulto(ampleksoMapo, 0) > max) max = F->rezulto(ampleksoMapo, 0);
	if (F->rezulto(-ampleksoMapo, 0) > max) max = F->rezulto(-ampleksoMapo, 0);
	qDebug()<<QObject::trUtf8("Создал данные для карты");
}

QwtRasterData * SpectrogramData::copy() const{
	return new SpectrogramData(f, min);
}

QwtDoubleInterval SpectrogramData::range() const{
	return QwtDoubleInterval(min, max);
}

double SpectrogramData::value(double x, double y) const{
	return f->rezulto(x, y);
}