#ifndef __SIGNALANTOPORPOINTF_H
#define __SIGNALANTOPORPOINTF_H
//
#include <QObject>
//
class DemonstrataQPointF;
class QPointF;
class funkcio;
//
/*! Используется совместно c DemonstrataQPointF. Высылает сигналы при изменении 
 * точки.
 *
 * Совместное использование SignalantoPorPointF и DemonstrataQPointF позволяет
 * высылать сигналы со значениями точки, при каждом её изменении. Это позволяет
 * соединить объект DemonstrataQPointF с элементами отображения в окне и затем
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
 * SignalantoPorPointF требует при создании указатель на объект 
 * DemonstrataQPointF. Если передать 0, то ни один сигнал не будет вылан. 
 * 
 * Если установлен не обязательный параметр funkcio * F, то будут высылаться 
 * сигналы со значениями преданной целевой функци в точке.
 * 
 * Сигналы SignalojPorPointF::proviziValoroFukcioEnPointo(const QString &) и
 * SignalojPorPointF::ValoroFukcioEnPointo(double) высылаются, только если 
 * установлена целевая функция.
 * 
 * Функция SendiSignaloj заставляет объект SignalojPorPointF выслать сигналы.
 * Используется в DemonstrataQPointF. Можно вызвать её вручную, что бы обновить 
 * итображения точки. Обычно вызывать вручную не требуется.
 * 
 * Как и любой наследник QObject, SignalantoPorPointF может быть добавлен в
 * иерархию объектов. 
 * 
 * @see DemonstrataQPointF.
 * 
 * @author Василий Почкаенко.
 */
class SignalantoPorPointF: public QObject{
Q_OBJECT
private:
	DemonstrataQPointF * p;
	funkcio * f;
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
