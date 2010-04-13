#ifndef ALGORITMOWIN_H
#define ALGORITMOWIN_H
//
#include <QMainWindow>
//
class funkcio;
class MapoPorFunkcioImpl;
class spuro;
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
  //! Указатель на виджет - карту высот целевой функции.
  MapoPorFunkcioImpl * MapoWdg;
  //! Указатель на след.
  spuro * Sp;
public:
	AlgoritmoWin(funkcio *f, QVector<double> *d, QWidget * parent = 0, Qt::WindowFlags flags = 0);
	
};
#endif

/*! @class AlgoritmoWin
 * @author Василий Почкаенко.
 * @file algoritmowin.h
 */
