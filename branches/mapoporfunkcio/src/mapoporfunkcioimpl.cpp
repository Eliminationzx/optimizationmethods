#include "mapoporfunkcioimpl.h"
#include "funkcio.h"
//#include <QGraphicsItem>
#include "scenopormapo.h"
#include <limits>
#include <QGraphicsScene>
#include <QString>
#include <QMessageBox>
//
MapoPorFunkcioImpl::MapoPorFunkcioImpl( funkcio * Funkcio, QWidget * parent, Qt::WFlags f) 
	: QWidget(parent, f), F(Funkcio){
  setupUi(this);
  s = new ScenoPorMapo(F, parent);
//  QMessageBox msg(QMessageBox::Information, trUtf8("Границы области"), QString::number(numeric_limits<int>::min()) + " " + QString::number(numeric_limits<int>::max()));
//  msg.exec();
  s->setSceneRect(-numeric_limits<int>::max()/2, -numeric_limits<int>::max()/2,
                  numeric_limits<int>::max(), numeric_limits<int>::max());
  grphVw->setScene(s);
//  s->addEllipse(-10, -10, 10, 10);
}
//

