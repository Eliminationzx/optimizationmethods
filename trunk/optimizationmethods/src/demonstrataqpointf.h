#ifndef DEMONSTRATAQPOINTF_H
#define DEMONSTRATAQPOINTF_H
//
#include <QPointF>
#include <QObject>
#include "funkcio.h"
//
/*! Используется внутри DemonstrataQPointF. Высылет сигналы при изменении точки.
 *
 * Функция SendiSignaloj принимает точку, чьё значение надо передать, и
 * заставляет объект SignalojPorPointF выслать сигналы.
 * 
 * @author Василий Почкаенко.
 */
class SignalojPorPointF: public QObject{
Q_OBJECT
private:
	funkcio * f;
	QPointF * p;
public:
	//! Высылает все сигналы.
	void SendiSignaloj(){
		emit proviziValoro(*p);
	  emit proviziValoro(trUtf8("%1; %2").arg(QString::number(p->x())).arg(QString::number(p->y())));
	  emit proviziXValoro(p->toPoint().x());
	  emit proviziXValoro(p->x());
	  emit proviziXValoro(QString::number(p->x()));
	  emit proviziYValoro(p->y());
	  emit proviziYValoro(p->y());
	  emit proviziYValoro(QString::number(p->y()));
	  if(f != 0){
		  emit proviziValoroFukcioEnPointo(f->rezulto(*p));
		  emit proviziValoroFukcioEnPointo(QString::number(f->rezulto(*p)));
	  }
	};
	SignalojPorPointF( QPointF * P, funkcio * F = 0, QObject * parent = 0 )
		:QObject(parent), p(P), f(F){};
signals:
  //! Предоставляет значение функции в точке.
  void proviziValoroFukcioEnPointo(double);
  //! Предоставляет значение функции в точке в виде строки.
  void proviziValoroFukcioEnPointo(const QString &);
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
 * В этом классе переопределены все методы, изменяющие точку. В них добавлена
 * высылка сигналов. Для самого изменения используется реализация из QPointF.
 * 
 * Для QObject запрещён оператор =, поэтому объект высылающий сигналы с новыми
 * значениями точки добавлен в DemonstrataQPointF в виде члена. В результате
 * сигналы скрыты внутри DemonstrataQPointF. Чтобы соединить слот с нужным
 * сигналом, воспользуйтесь соответствующей функцией:
 * - connectProviziXValoro_QString для SignalojPorPointF::proviziXValoro(QString&)
 * - connectProviziXValoro_double для SignalojPorPointF::proviziXValoro(double)
 * - connectProviziXValoro_int для SignalojPorPointF::proviziXValoro(int)
 * - connectProviziYValoro_QString для SignalojPorPointF::proviziXValoro(QString&)
 * - connectProviziYValoro_double для SignalojPorPointF::proviziXValoro(double)
 * - connectProviziYValoro_int для SignalojPorPointF::proviziXValoro(int)
 * - connectProviziValoro_QString для SignalojPorPointF::proviziValoro(const QString&)
 * - connectProviziValoro_QPointF для SignalojPorPointF::proviziValoro(const QPointF&)
 * - connectProviziValoroFukcioEnPointo_double для SignalojPorPointF::ValoroFukcioEnPointo(double)
 * - connectProviziValoroFukcioEnPointo_QString для SignalojPorPointF::proviziValoroFukcioEnPointo(const QString &)
 * 
 * Сигналы SignalojPorPointF::proviziValoroFukcioEnPointo(const QString &) и
 * SignalojPorPointF::ValoroFukcioEnPointo(double) высылаются, только если 
 * установлена целевая функция.
 * 
 * @author Василий Почкаенко.
 */
class DemonstrataQPointF : public QPointF{
private:
	//! Наследник QObject, высылающий сигналы при изменении точки.
	SignalojPorPointF *sp;
	//! Указатель на целевую функцию.
	funkcio *f;
public:
	//! Устанавливает целевую функцию.
	void difiniFunkcio(funkcio *F){ f = F; };
	/*! Соединяет полученный слот с сигналом
	 * SignalojPorPointF::ValoroFukcioEnPointo(double).
	 *
	 * @return true в случае успеха, иначе false.
	 */
	bool connectProviziValoroFukcioEnPointo_double(QObject * ricevanto, const char * slot);
	/*! Соединяет полученный слот с сигналом
	 * SignalojPorPointF::proviziValoroFukcioEnPointo(const QString &).
	 *
	 * @return true в случае успеха, иначе false.
	 */
	bool connectProviziValoroFukcioEnPointo_QString(QObject * ricevanto, const char * slot);
	/*! Соединяет полученный слот с сигналом
	 * SignalojPorPointF::proviziXValoro(QString&).
	 *
	 * @return true в случае успеха, иначе false.
	 */
	bool connectProviziXValoro_QString(QObject * ricevanto, const char * slot);
	/*! Соединяет полученный слот с сигналом
	 * SignalojPorPointF::proviziXValoro(double).
	 *
	 * @return true в случае успеха, иначе false.
	 */
	bool connectProviziXValoro_double(QObject * ricevanto, const char * slot);
	/*! Соединяет полученный слот с сигналом
	 * SignalojPorPointF::proviziXValoro(int).
	 *
	 * @return true в случае успеха, иначе false.
	 */
	bool connectProviziXValoro_int(QObject * ricevanto, const char * slot);
	/*! Соединяет полученный слот с сигналом
	 * SignalojPorPointF::proviziYValoro(QString).
	 *
	 * @return true в случае успеха, иначе false.
	 */
	bool connectProviziYValoro_QString(QObject * ricevanto, const char * slot);
	/*! Соединяет полученный слот с сигналом
	 * SignalojPorPointF::proviziYValoro(double).
	 *
	 * @return true в случае успеха, иначе false.
	 */
	bool connectProviziYValoro_double(QObject * ricevanto, const char * slot);
	/*! Соединяет полученный слот с сигналом
	 * SignalojPorPointF::proviziXValoro(int).
	 *
	 * @return true в случае успеха, иначе false.
	 */
	bool connectProviziYValoro_int(QObject * ricevanto, const char * slot);
	/*! Соединяет полученный слот с сигналом
	 * SignalojPorPointF::proviziValoro(const QString&).
	 *
	 * @return true в случае успеха, иначе false.
	 */
	bool connectProviziValoro_QString(QObject * ricevanto, const char * slot);
	/*! Соединяет полученный слот с сигналом
	 * SignalojPorPointF::proviziValoro(const QPointF&).
	 *
	 * @return true в случае успеха, иначе false.
	 */
	bool connectProviziValoro_QPointF(QObject * ricevanto, const char * slot);
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
  DemonstrataQPointF(funkcio * F = 0);
  DemonstrataQPointF( const QPoint & point, funkcio * F = 0);
  DemonstrataQPointF( const QPointF & point, funkcio * F = 0);
  DemonstrataQPointF( qreal x, qreal y, funkcio * F = 0);
  ~DemonstrataQPointF();
};

qreal Length( const QPointF & point);
#endif

