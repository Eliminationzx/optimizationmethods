#ifndef __SIGNALANTOPORPOINTF_H
#define __SIGNALANTOPORPOINTF_H
//
#include <QObject>
//
class DemonstrataQPointF;
class QPointF;
class funkcio;
//
/*! Используется внутри DemonstrataQPointF. Высылет сигналы при изменении точки.
 *
 * Функция SendiSignaloj заставляет объект SignalojPorPointF выслать сигналы.
 * 
 * Сигналы SignalojPorPointF::proviziValoroFukcioEnPointo(const QString &) и
 * SignalojPorPointF::ValoroFukcioEnPointo(double) высылаются, только если 
 * установлена целевая функция.
 * 
 * @author Василий Почкаенко.
 */
class SignalantoPorPointF: public QObject{
Q_OBJECT
private:
	funkcio * f;
	DemonstrataQPointF * p;
public:
	//! Высылает все сигналы.
	void SendiSignaloj();
	SignalantoPorPointF( DemonstrataQPointF * P, funkcio * F = 0, QObject * parent = 0 );
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

#endif // __SIGNALANTOPORPOINTF_H__
