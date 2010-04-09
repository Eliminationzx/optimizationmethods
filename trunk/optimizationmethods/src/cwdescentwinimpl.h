#ifndef CWDESCENTWINIMPL_H
#define CWDESCENTWINIMPL_H
//
#include "algoritmowin.h"
#include "ui_CWdescent_fixwindow.h"
//
//! Окно для прохождения Покоординатного спуска с фиксированным шагом.
/*! Алгоритм:
 * 1) Изменяем x1 в положительную сторону на значение h1 
 * 2) Если значение F(x1 + h1, x2) < F(x1, x2), то необходимо принять новую точку, иначе не принимаем её. 
 * 3) Если не приняли, то изменяем x1 в отрицательную сторону на значение h1 
 * 4) Если значение F(x1 - h1, x2) < F(x1, x2), то необходимо принять новую точку, иначе не принимаем её. 
 * 5) Повторяем пункты 1, 2, 3 и 4 для x2 и h2 
 * 6) Если не приняли ни одно новое значения для x1 и x2, то уменьшаем длину шага 
 * 7) Если длина шага меньше требуемой точности, то завершаем поиск, иначе переходим к пункту 1
 * @author Александр Белоконь.
 * @file cwdescentwinimpl.h
 */
class CWdescentWinImpl : public AlgoritmoWin, public Ui::CWdescentWin
{
Q_OBJECT
protected:
  //! Текущая точка.
  QPointF MomentaPointo;
  //! Новая точка.
  QPointF NovaPointo;
public:
	CWdescentWinImpl( funkcio *f, QVector<double> *d, QWidget * parent = 0, Qt::WFlags flags = 0 );
private slots:
};
#endif





