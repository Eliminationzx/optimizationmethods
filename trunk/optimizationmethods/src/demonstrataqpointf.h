#ifndef DEMONSTRATAQPOINTF_H
#define DEMONSTRATAQPOINTF_H
//
#include <QPointF>
#include <QObject>
//
//! Обёртка QPointF, дла автоматического отображения его значений в окне.
class DemonstrataQPointF : public QPointF{
//Q_OBJECT
Q_PROPERTY(qreal x READ x WRITE setX)
Q_PROPERTY(qreal y READ y WRITE setY)
private:
//	QPointF p;
public: 
  //! Устанавливает новое значение X.
  void setX(qreal x);
  //! Устанавливает новое значение Y.
  void setY(qreal y);
  QPointF & operator*=(qreal factor);
  QPointF & operator+=(const QPointF & point);
  QPointF & operator-=(const QPointF & point);
  QPointF & operator/=(qreal divisor);
  QPointF & operator=(QPointF & point);
  DemonstrataQPointF();
  DemonstrataQPointF( const QPoint & point);
  DemonstrataQPointF( const QPointF & point);
  DemonstrataQPointF( qreal x, qreal y );
//signals:
  //! Предоставляет значение в виде точки.
//  void proviziValoro(const QPointF&);
  //! Предоставляет значение в виде строки содержащей точку.
//  void proviziValoro(const QString &);
  //! Предоставляет значение в виде целого числа.
//  void proviziXValoro(int);
  //! Предоставляет значение в виде десятичной дроби.
//  void proviziXValoro(double valoro);
  //! Предоставляет значение в виде строки.
//  void proviziXValoro(const QString &);
  //! Предоставляет значение в виде целого числа.
//  void proviziYValoro(int);
  //! Предоставляет значение в виде десятичной дроби.
//  void proviziYValoro(double valoro);
  //! Предоставляет значение в виде виде строки.
//  void proviziYValoro(const QString &);  
};
#endif

/*! @class DemonstrataQPointF
 * К QPointF добавлены сигалы передающие его значение. Эти сигналы вызываются во всех методах изменяющих значение точки.
 * 
 * @author Василий Почкаенко.
 */
