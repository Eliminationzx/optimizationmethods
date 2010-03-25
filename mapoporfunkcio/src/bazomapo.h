#ifndef BAZOMAPO_H
#define BAZOMAPO_H
//
#include <QGraphicsItem>
//
class BazoMapo : public QGraphicsItem{
//Q_OBJECT
public:
  QRectF boundingRect() const;
	BazoMapo(QGraphicsItem * parent = 0);
	
};
#endif
