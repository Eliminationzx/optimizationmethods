#ifndef CWDESCENTWINIMPL_H
#define CWDESCENTWINIMPL_H
//
#include "algoritmowin.h"
#include "ui_CWdescent_fixwindow.h"
#include "demonstrataqpointf.h"
//
//! Этапы итерации
enum EtapojIteracio{
  PasxiDekstren, //!< Шаг направо.
  PasxiMaldekstren, //!< Шаг налево.
  PasxiSupren, //!< Шаг вверх.
  PasxiMalsupren, //!< Шаг вниз.
  KonsideradoPointo, //!< Рассмотрение точки. Принимать а качестве новой текущей или нет.
  MmalpliigiPasxo, //!< Уменьшение шага.
  Finisxo //!< Конец алгоритма.
};
//! Окно для прохождения Покоординатного спуска с фиксированным шагом.
class CWdescentWinImpl : public AlgoritmoWin, public Ui::CWdescentWin
{
Q_OBJECT
protected:
  //! Номер итерации.
  int NumeroIteracio;
  //! Флаг этапа итерации.
  EtapojIteracio FlagEtapo;
  //! Текущая точка.
  DemonstrataQPointF MomentaPointo;
  //! Новая точка.
  DemonstrataQPointF NovaPointo;
  //! Шаг по х1.
  /*! Для удобства задаю в виде точки (длина, 0).
   */
  DemonstrataQPointF PasxoX1;
  //! Шаг по х1.
  /*! Для удобства задаю в виде точки (0, длина).
   */
  DemonstrataQPointF PasxoX2;
public:
	CWdescentWinImpl( funkcio *f, QVector<double> *d, QWidget * parent = 0, Qt::WFlags flags = 0 );
private slots:
};
#endif

/*! @class CWdescentWinImpl
 * Алгоритм:
 * 
 * Операции алгоритма повторяются циклически, пока не значениене приблизится к минимуму на заданную точность.
 * Каждая итерация содержит следующие шаги:
 * 
 * 1) Изменяем x1 в положительную сторону на значение h1.
 * 
 * 2) Если значение F(x1 + h1, x2) < F(x1, x2), то необходимо принять новую точку и перейти к следующей итерации, иначе не принимаем её. 
 * 
 * 3) Если не приняли, то изменяем x1 в отрицательную сторону на значение h1.
 * 
 * 4) Если значение F(x1 - h1, x2) < F(x1, x2), то необходимо принять новую точку и перейти к следующей итерации, иначе не принимаем её. 
 * 
 * 5) Повторяем пункты 1, 2, 3 и 4 для x2 и h2.
 * 
 * 6) Если не приняли ни одно новое значения для x1 и x2, то уменьшаем длину шага.
 * 
 * 7) Если длина шага меньше требуемой точности, то завершаем поиск, иначе переходим к следующей итерации.
 * 
 * @author Александр Белоконь.
 * @file cwdescentwinimpl.h
 */