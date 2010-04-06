#ifndef SPUROSINKOLAUXKOORDINATOJ_H
#define SPUROSINKOLAUXKOORDINATOJ_H
//
#include "spuro.h"
//
//! Отображет "след" покоординатного спуска с дискретным шагом.
/*! 
 * 
 * @author Василий Почкаенко.
 * @file spurosinkolauxkoordinatoj.h
 */
class spuroSinkoLauxKoordinatoj : public spuro
{

public:
	spuroSinkoLauxKoordinatoj(QColor bazaKoloro, //!< Основной цвет "следа".
                            QGraphicsItem * parent = 0 //!< Элемент родитель.
                           );
	
};
#endif
