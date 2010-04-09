#ifndef DEMONSTRATAQPOINTF_H
#define DEMONSTRATAQPOINTF_H
//
#include <QPointF>
#include <QObject>
//
//! Расширение QPointF, дла автоматического отображения его значений в окне.
/*! К QPointF добавлены сигалы передающие его значение. Эти сигналы вызываются во всех методах изменяющих значение точки.
 * 
 * @author Василий Почкаенко.
 * @file demonstrataqpointf.h
 */
class DemonstrataQPointF : public QObject, public QPointF{
Q_OBJECT
signals:
  //! Предоставляет значение в виде целого числа.
  void proviziXValoro(int valoro);
  //! Предоставляет значение в виде десятичной дроби.
  void proviziXValoro(double valoro);
  //! Предоставляет значение в виде строки.
  void proviziXValoro(QString valoro);
  //! Предоставляет значение в виде целого числа.
  void proviziYValoro(int valoro);
  //! Предоставляет значение в виде десятичной дроби.
  void proviziYValoro(double valoro);
  //! Предоставляет значение в виде виде строки.
  void proviziYValoro(QString valoro);
public: 
  QPointF & operator*=(qreal factor);
  QPointF & operator+=(const QPointF & point);
  QPointF & operator-=(const QPointF & point);
  QPointF & operator/=(qreal divisor);
  //! Устанавливает новое значение X.
  void setX(qreal x);
  //! Устанавливает новое значение Y.
  void setY(qreal y);
  DemonstrataQPointF(qreal x, qreal y, const QObject * parent = 0);
  DemonstrataQPointF(const QPoint & point, const QObject * parent = 0);
  
};
#endif
