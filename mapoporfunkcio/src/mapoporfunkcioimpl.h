#ifndef MAPOPORFUNKCIOIMPL_H
#define MAPOPORFUNKCIOIMPL_H
//
#include <QWidget>
#include "ui_mapoporfunkcio.h"
//
class ScenoPorMapo;
class QGraphicsItem;
class funkcio;
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
  funkcio *F;
  //! Сцена
  ScenoPorMapo *s;
public:
	MapoPorFunkcioImpl( funkcio * Funkcio, QWidget * parent = 0, Qt::WFlags f = 0 );
protected:
private slots:
  //! Увеличить.
	void on_PligrandigiBtn_clicked();
  //! Уменьшить.
	void on_MalpliigiBtn_clicked();
};
#endif







