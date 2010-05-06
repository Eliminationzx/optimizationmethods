#ifndef DEMONSTRATAQPOINTF_H
#define DEMONSTRATAQPOINTF_H
//
#include <QPointF>
#include "signalantoporpointf.h"
//

/*! Расширение QPointF, для использования совместно с SignalantoPorPointF.
 *
 * Совместное использование SignalantoPorPointF и DemonstrataQPointF позволяет
 * высылать сигналы со значениями точки, при каждом её изменении. Это позволяет
 * соединнить объект DemonstrataQPointF с элементами отображения в окне и затем
 * работать с ним, как с обычной точкой(QPointF), не заботясь об отображении. 
 * MOC сам всё сделает.
 * 
 * Пример:
 * @code 
 * KvadratigantoFunkcio f;
 * DemonstrataQPointF p;
 * SignalantoPorPointF sp(&p, &f);
 * connect(&sp, SIGNAL(proviziValoro(const QString &)), lb, SLOT(setTEXT(const QString &)));
 * ...
 * p *= 6;
 * @endcode
 *  
 * В этом классе переопределены все методы, изменяющие точку. В них добавлен
 * вызов SignalantoPorPointF::SendiSignaloj(). Для самого изменения
 * используется реализация из QPointF. Указатель на SignalantoPorPointF
 * передаётся в метод difiniSignalantoPorPointF. Обычно он вызывается в 
 * конструкторе SignalantoPorPointF. Если объекту DemonstrataQPointF не
 * назначен объект SignalantoPorPointF, то он ни чем не отличается от QPointF.
 *  
 * @see SignalantoPorPointF.
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
  DemonstrataQPointF():QPointF(), sp(0){};
  DemonstrataQPointF( const QPoint & point):QPointF(point), sp(0){};
  DemonstrataQPointF( const QPointF & point):QPointF(point), sp(0){};
  DemonstrataQPointF( qreal x, qreal y):QPointF(x, y), sp(0){};
};

qreal Length( const QPointF & point);
#endif

