#ifndef DEMONSTRATAQPOINTF_H
#define DEMONSTRATAQPOINTF_H
//
#include <QPointF>
#include <QObject>
//
//! Используется внутри DemonstrataQPointF. Высылет сигналы при изменении точки.
class SignalojPorPointF: public QObject{
Q_OBJECT
private:
public:
	//! Высылает все сигналы.
	void SendiSignaloj( const QPointF * p){
		emit proviziValoro(*p);
	  emit proviziValoro(trUtf8("%1; %2").arg(QString::number(p->x())).arg(QString::number(p->y())));
	  emit proviziXValoro(p->x());
	  emit proviziXValoro(p->x());
	  emit proviziXValoro(QString::number(p->x()));
	};
	SignalojPorPointF( QObject * p = 0 )
		:QObject(p){};
signals:
  //! Предоставляет значение в виде точки.
  void proviziValoro(const QPointF&);
  //! Предоставляет значение в виде строки содержащей точку.
  void proviziValoro(const QString &);
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
//
/*! Расширение QPointF, для высылки сигналов с информацией об изменениях.
 *
 * Для QObject запрещён оператор =, поэтому обьект высылающий согналы с новыми
 * значениями точки добавлен в DemonstrataQPointF в виде статического члена.
 * В результате сигналы скрыты внутри DemonstrataQPointF. Чтобы соединить слот 
 * с нужным сигналом, воспользуйтесь соответствующей функцией:
 */
class DemonstrataQPointF : public QPointF{
private:
	//! Ноаследник QObject, высылающий сигналы при изменении точки.
	static SignalojPorPointF sp;
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
};
#endif

/*! @class DemonstrataQPointF
 * К QPointF добавлены сигалы передающие его значение. Эти сигналы вызываются во всех методах изменяющих значение точки.
 * 
 * @author Василий Почкаенко.
 */
