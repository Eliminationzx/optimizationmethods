#include "mapoporfunkcioimpl.h"
#include "funkcio.h"
//#include <QGraphicsItem>
#include "scenopormapo.h"
//#include <QGraphicsScene>
//#include <QMessageBox>
//
MapoPorFunkcioImpl::MapoPorFunkcioImpl( funkcio * Funkcio, QWidget * parent, Qt::WFlags f) 
	: QWidget(parent, f), F(Funkcio){
  setupUi(this);
  s = new ScenoPorMapo(F, parent);
  s->setSceneRect(-2000, -2000, 4000, 4000);
  grphVw->setScene(s);
//  s->addEllipse(-10, -10, 10, 10);
}
//

