#ifndef SPUROHUGI_H
#define SPUROHUGI_H
//
#include "spuro.h"
//
class spuroHuGi : public spuro
{

public:
	spuroHuGi( QColor momentaKoloro, //!< Цвет текущей итерации.
	           QColor bazaKoloro, //!< Основной цвет "следа".
	           qreal Skalo = 1, //!< Коэффициент масштаба.
	           QGraphicsItem * parent = 0 //!< Элемент родитель.
	         );
	
};
#endif
