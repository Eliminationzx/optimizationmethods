#ifndef DEMONSTRATAQPOINTF_H
#define DEMONSTRATAQPOINTF_H
//
#include <QPointF>
#include <QObject>
//
//! Расширение QPointF, дла автоматического отображения его значений в окне.
class DemonstrataQPointF : public QObject, public QPointF{
Q_OBJECT
signals:
  //! Предоставляет значение в виде целого числа.
  void proviziXValoro(int);
  //! Предоставляет значение в виде десятичной дроби.
  void proviziXValoro(double valoro);
  //! Предоставляет значение в виде строки.
  void proviziXValoro(QString &);
  //! Предоставляет значение в виде целого числа.
  void proviziYValoro(int);
  //! Предоставляет значение в виде десятичной дроби.
  void proviziYValoro(double valoro);
  //! Предоставляет значение в виде виде строки.
  void proviziYValoro(const QString &);
public: 
  QPointF & operator*=(qreal factor);
  QPointF & operator+=(const DemonstrataQPointF & point);
  QPointF & operator-=(const DemonstrataQPointF & point);
  QPointF & operator/=(qreal divisor);
  //! Устанавливает новое значение X.
  void setX(qreal x);
  //! Устанавливает новое значение Y.
  void setY(qreal y);
  DemonstrataQPointF(qreal x, qreal y, QObject * parent = 0);
  DemonstrataQPointF(const DemonstrataQPointF & point, QObject * parent = 0);
  DemonstrataQPointF(const QPointF & point, QObject * parent = 0);
  
};
#endif

/*! @class DemonstrataQPointF
 * К QPointF добавлены сигалы передающие его значение. Эти сигналы вызываются во всех методах изменяющих значение точки.
 * 
 * @author Василий Почкаенко.
 * @file demonstrataqpointf.h
 */
