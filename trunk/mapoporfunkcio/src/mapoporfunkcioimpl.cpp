#include "mapoporfunkcioimpl.h"
#include "bazomapo.h"
#include "funkcio.h"
#include <QGraphicsItem>
#include "scenopormapo.h"
#include <limits>
//
MapoPorFunkcioImpl::MapoPorFunkcioImpl( QWidget * parent, Qt::WFlags f) 
	: QWidget(parent, f)
{
  setupUi(this);
  s = new ScenoPorMapo(new KvadratigantoFunkcio(1, 0, 1, 0, 0, 0, 0, parent), parent);
  s->setSceneRect(numeric_limits<int>::min(), numeric_limits<int>::min(),
                   numeric_limits<int>::max(), numeric_limits<int>::max());
  grphVw->setScene(s);
}
//

