#include "mapoporfunkcioimpl.h"
#include "bazomapo.h"
#include "funkcio.h"
#include <QGraphicsItem>
#include "scenopormapo.h"
#include <limits>
#include <QGraphicsScene>
#include <QColor>
#include <QPainter>
#include <QMessageBox>
//
MapoPorFunkcioImpl::MapoPorFunkcioImpl( funkcio * Funkcio, QWidget * parent, Qt::WFlags f) 
	: QWidget(parent, f), F(Funkcio){
  setupUi(this);
  s = new ScenoPorMapo(F, parent);
  s->setSceneRect(numeric_limits<int>::min(), numeric_limits<int>::min(),
                   numeric_limits<int>::max(), numeric_limits<int>::max());
  grphVw->setScene(s);
//  s->addEllipse(-10, -10, 10, 10);
}
//

