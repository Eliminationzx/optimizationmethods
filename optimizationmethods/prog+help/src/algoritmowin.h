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
  QVector<double> D;
  //! Указатель на виджет - карту высот целевой функции.
  MapoPorFunkcioImpl * MapoWdg;
  //! Указатель на след.
  spuro * Sp;
public:
	AlgoritmoWin(funkcio *f, //!< Указатель на целевую функцию. ScenoPorMapo не заботится о назначении Funkcio родителя.
               QVector<double> *d, //!< Массив с данными задания.
               QWidget * parent = 0, //!< Родитель.
               Qt::WindowFlags flags = 0 //!< Флаги парамметров окна.
               );
	
};
#endif

/*! @class AlgoritmoWin
 * @author Василий Почкаенко.
 */
