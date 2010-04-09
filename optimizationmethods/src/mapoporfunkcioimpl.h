#ifndef MAPOPORFUNKCIOIMPL_H
#define MAPOPORFUNKCIOIMPL_H
//
#include <QWidget>
#include "ui_mapoporfunkcio.h"
//
class ScenoPorMapo;
class QGraphicsItem;
class funkcio;
class spuro;
//
using namespace std;
//! Виджет для отображения карты высот целевой функции и "следа алогритма на ней"
/*!
 * 
 * @author Василий Почкаенко.
 * @file mapoporfunkcioimpl.h
 */
class MapoPorFunkcioImpl : public QWidget, public Ui::MapoPorFunkcio
{
Q_OBJECT
private:
  //! Целевая функция.
  funkcio * F;
  //! Сцена
  ScenoPorMapo *s;
  //! "След"
  spuro * Spuro;
public:
  MapoPorFunkcioImpl( funkcio * Funkcio, QWidget * parent = 0, Qt::WFlags f = 0 );
  MapoPorFunkcioImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
public slots:
  //! Возвращает указатель на "след" прохождения алгоритма.
  /*! "Следы" разных алгоритмов имеют разные слоты. 
   * @see spuro, spuroSinkoLauxKoordinatoj.
 */
  const spuro * proviziSpuro();
  //! Устанавливает целивую функцию.
  void difiniFunkcio(funkcio * f);
  //! Создает на сцене "след" алгоритма.
  void kreiSpuro(
                 int IdAlgoritmo, //!< Порядковый номер алгоритма.
                 QColor bazaKoloro //!< Основной цвет "следа".
                );
private slots:
  //! Увеличить.
	void on_PligrandigiBtn_clicked();
  //! Уменьшить.
	void on_MalpliigiBtn_clicked();
};
#endif







