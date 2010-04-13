#ifndef ALGORITMOWIN_H
#define ALGORITMOWIN_H
//
#include <QMainWindow>
class funkcio;
//
//! Базовый класс для окна прохождения алгоритма.
class AlgoritmoWin : public QMainWindow
{
Q_OBJECT
protected:
  //! Целевая функция.
  funkcio * F;
  //! Данные задания.
  QVector<double> * D;
public:
	AlgoritmoWin(funkcio *f, QVector<double> *d, QWidget * parent = 0, Qt::WindowFlags flags = 0);
	
};
#endif

/*! @class AlgoritmoWin
 * @author Василий Почкаенко.
 * @file algoritmowin.h
 */
