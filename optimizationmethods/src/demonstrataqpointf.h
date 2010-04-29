#ifndef DEMONSTRATAQPOINTF_H
#define DEMONSTRATAQPOINTF_H
//
#include <QPointF>
#include <QObject>
//
//! Обёртка QPointF, дла автоматического отображения его значений в окне.
class DemonstrataQPointF : public QObject{
Q_OBJECT
private:
	QPointF p;
public: 
  QPointF & operator=(const DemonstrataQPointF&);
  QPointF & operator*=(qreal factor);
  QPointF & operator+=(const DemonstrataQPointF & point);
  QPointF & operator-=(const DemonstrataQPointF & point);
  QPointF & operator/=(qreal divisor);
  //! Устанавливает новое значение X.
  void setX(qreal x);
  //! Устанавливает новое значение Y.
  void setY(qreal y);
  DemonstrataQPointF( QObject * parent = 0);
  DemonstrataQPointF( const QPoint & point, QObject * parent = 0);
  DemonstrataQPointF( qreal x, qreal y, QObject * parent = 0);
  DemonstrataQPointF( DemonstrataQPointF & DP);
signals:
  //! Предоставляет значение в виде точки.
  void proviziValoro(QPointF);
  //! Предоставляет значение в виде целого числа.
  void proviziXValoro(int);
  //! Предоставляет значение в виде десятичной дроби.
  void proviziXValoro(double valoro);
  //! Предоставляет значение в виде строки.
  void proviziXValoro(const QString &);
  //! Предоставляет значение в виде целого числа.
  void proviziYValoro(int);
  //! Предоставляет значение в виде десятичной дроби.
  void proviziYValoro(double valoro);
  //! Предоставляет значение в виде виде строки.
  void proviziYValoro(const QString &);  
};
#endif

/*! @class DemonstrataQPointF
 * К QPointF добавлены сигалы передающие его значение. Эти сигналы вызываются во всех методах изменяющих значение точки.
 * 
 * @author Василий Почкаенко.
 */
