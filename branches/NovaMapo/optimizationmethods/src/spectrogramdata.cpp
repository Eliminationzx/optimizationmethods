#include "spectrogramdata.h"
#include "funkcio.h"
#include "Konstantoj.h"
#include <QDebug>

SpectrogramData::SpectrogramData(const funkcio * F)
	: QwtRasterData(QwtDoubleRect(-ampleksoMapo, -ampleksoMapo, 2*ampleksoMapo, 2*ampleksoMapo)), f(F){
	min = f->rezulto(f->minPoint(0.1)[0], f->minPoint(0.1)[1]);
	//--Ищу точку приближенную к максимальной в области карты.---------------------
	max = F->rezulto(ampleksoMapo, ampleksoMapo);
	QPointF maxP = QPointF(ampleksoMapo, ampleksoMapo);
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
	return new SpectrogramData(f);
}

QwtDoubleInterval SpectrogramData::range() const{
	return QwtDoubleInterval(min, max);
}

double SpectrogramData::value(double x, double y) const{
	return f->rezulto(x, y);
}