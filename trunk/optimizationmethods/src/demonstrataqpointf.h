#ifndef DEMONSTRATAQPOINTF_H
#define DEMONSTRATAQPOINTF_H
//
#include <QPointF>
#include "signalantoporpointf.h"
//

/*! Расширение QPointF, для высылки сигналов с информацией об изменениях.
 *
 * В этом классе переопределены все методы, изменяющие точку. В них добавлена
 * высылка сигналов. Для самого изменения используется реализация из QPointF.
 * 
 * @author Василий Почкаенко.
 */
class DemonstrataQPointF : public QPointF{
private:
	//! Наследник QObject, высылающий сигналы при изменении точки.
	SignalantoPorPointF * sp;
public:
  //! Устанавливает указатель на "сигнализатор"
  inline void difiniSignalantoPorPointF(SignalantoPorPointF * SP){ sp = SP; };
  //! Устанавливает новое значение X.
  void setX(qreal x);
  //! Устанавливает новое значение Y.
  void setY(qreal y);
  QPointF & operator*=(qreal factor);
  QPointF & operator+=(const QPointF & point);
  QPointF & operator-=(const QPointF & point);
  QPointF & operator/=(qreal divisor);
  QPointF & operator=(const QPointF & point);
  QPointF & operator=(const QPoint & point);
  DemonstrataQPointF():QPointF(){};
  DemonstrataQPointF( const QPoint & point):QPointF(point), sp(0){};
  DemonstrataQPointF( const QPointF & point):QPointF(point), sp(0){};
  DemonstrataQPointF( qreal x, qreal y):QPointF(x, y), sp(0){};
};

qreal Length( const QPointF & point);
#endif

