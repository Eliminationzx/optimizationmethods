#include "spuro.h"
//
spuro::spuro(int IdAlgoritmo, QColor bazaKoloro, QGraphicsItem * parent)
  : QGraphicsItem(parent), BazaKoloro(bazaKoloro), IDAlgoritmo(IdAlgoritmo), skalo(1) {};
//


void spuro::setScale(qreal factor){
  skalo = factor;
}


qreal spuro::scale() const{
  return skalo;
}