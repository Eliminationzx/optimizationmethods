#include "spuro.h"
//
spuro::spuro(int IdAlgoritmo, QColor bazaKoloro, qreal Skalo, QGraphicsItem * parent)
	: QGraphicsItem(parent), IDAlgoritmo(IdAlgoritmo), BazaKoloro(bazaKoloro),
		skalo(Skalo), empty(false) {};
spuro::spuro(QGraphicsItem * parent)
	: QGraphicsItem(parent), IDAlgoritmo(0), BazaKoloro(QColor()),
		skalo(1), empty(true) {};
//


void spuro::setScale(qreal factor){
	skalo = factor;
}


qreal spuro::scale() const{
	return skalo;
}