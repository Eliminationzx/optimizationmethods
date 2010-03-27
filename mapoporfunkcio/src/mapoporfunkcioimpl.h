#ifndef MAPOPORFUNKCIOIMPL_H
#define MAPOPORFUNKCIOIMPL_H
//
#include <QWidget>
#include "ui_mapoporfunkcio.h"
//
class ScenoPorMapo;
class QGraphicsItem;
//
using namespace std;

class MapoPorFunkcioImpl : public QWidget, public Ui::MapoPorFunkcio
{
Q_OBJECT
private:
  ScenoPorMapo *s;
  QGraphicsItem *mapo;
public:
	MapoPorFunkcioImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:
};
#endif






