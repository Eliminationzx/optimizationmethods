#ifndef FUNKCIO_H
#define FUNKCIO_H
//
#include <QObject>
#include <math.h>
#include <QVector>
#include <QPointF>
//
//! Класс для целевой функции.
class funkcio : public QObject
{
Q_OBJECT

public:
	//! Возвращает значение частной производной первого порядка по x1.
	virtual double df_dx1(const QVector<double> X) const = 0;
	//! Возвращает значение частной производной первого порядка по x1.
	virtual double df_dx1(const QPointF X) const = 0;
	
	//! Возвращает значение частной производной первого порядка по x2.
	virtual double df_dx2(const QVector<double> X) const = 0;
	//! Возвращает значение частной производной первого порядка по x2.
	virtual double df_dx2(const QPointF X) const = 0;
	
	//! Возвращает длину шага для оптимизации функции одной переменной.
	double lengthOfStep(const QVector<double> X, const double e) const;
	//! Возвращает длину шага для оптимизации функции одной переменной.
	double lengthOfStep(const QPointF X) const;

	//! Возвращает определитель гессиана.
	virtual double detGessian(const QPointF * X) const = 0;

	//! Возвращает результат вычисления функции в точке.
	virtual double rezulto(const double x1, //!< Первая координата точки.
	                       const double x2 //!< Вторая координата точки.
	                      ) const = 0;
	//! Возвращает результат вычисления функции в точке.
	/*! @param X Точка.
	 */
	virtual double rezulto(const QVector<double> X) const = 0;
	//! Возвращает результат вычисления функции в точке.
	/*! @param X Точка.
	 */
	virtual double rezulto(const QPointF & X) const { return rezulto(X.x(), X.y()); };
	//! Возвращает точку минимума функции.
	virtual QVector<double> minPoint(
	                                 const double e //!< Точность.
	                                ) const;

	virtual double getA() const = 0;
	virtual double getB() const = 0;
	virtual double getC() const = 0;
	virtual double getD() const = 0;
	virtual double getE() const = 0;
	virtual double getF() const = 0;
	virtual double getG() const = 0;

	/*! @param parent Родитель.
	 */
	funkcio(QObject * parent = 0) : QObject(parent){};
/*! @class funkcio
 * Базавый класс для всех целевых функций. Если хотите добавить свою, 
 * унаследуите этот класс и реализуйте все виртуальные методы. Совместимость 
 * проекта с наследниками этого класса гарантирована.
 * 
 * При разработки собственных прохождений какого либо алгоритма используите 
 * только этот класс для целевой функции.
 * 
 * Пример:
 * @code 
 * CWdescentWinImpl( funkcio *f, //!< Указатель на целевую функцию.
 *                    QVector<double> *d, //!< Массив с данными задания.
 *                    QWidget * parent = 0, //!< Родитель.
 *                    Qt::WFlags flags = 0 //!< Флаги парамметров окна.
 *                  );
 * @endcode
 * @author Александр Проскурин, Василий Почкаенко.
 */
};

//! Реализация целевой квадратичной функции.
/*! A*pow((x1 - B), 2) + C*pow((x2 - D), 2) + E*(x1 - F)*(x2 - G)
 * @author Александр Проскурин, Василий Почкаенко.
 */
class KvadratigantoFunkcio : public funkcio{
Q_OBJECT

private:
	//! Коэффициенты.
	double A, B, C, D, E, F, G;

public:

	//! Возвращает значение частной производной первого порядка по x1.
	double df_dx1(const QVector<double> X) const
	{ return 2*A*(X[0] - B) + E*(X[1] - G); };
	//! Возвращает значение частной производной первого порядка по x1.
	double df_dx1(const QPointF X) const
	{ return 2*A*(X.x() - B) + E*(X.y() - G); };

	//! Возвращает значение частной производной первого порядка по x2.
	double df_dx2(const QVector<double> X) const
	{ return 2*C*(X[1] - D) + E*(X[0] - F); }
	//! Возвращает значение частной производной первого порядка по x2.
	double df_dx2(const QPointF X) const
	{ return 2*C*(X.y() - D) + E*(X.x() - F); }

	//! Возвращает определитель гессиана.
	double detGessian(const QPointF * X) const
	{ return (2*A * 2*C) - (E*E); }

  //! Возвращает результат вычисления функции в точке.
  double rezulto(const double x1, //!< Первая координата точки.
                 const double x2 //!< Вторая координата точки.
                ) const
  { return A*pow((x1 - B), 2) + C*pow((x2 - D), 2) + E*(x1 - F)*(x2 - G); };
  //! Возвращает результат вычисления функции в точке.
  /*! @param X Точка.
   */
  double rezulto(const QVector<double> X) const
  { return A*pow((X[0] - B), 2) + C*pow((X[1] - D), 2) + E*(X[0] - F)*(X[1] - G); };
  //! Возвращает результат вычисления функции в точке.
  /*! @param X Точка.
   */
  double rezulto(const QPointF & X) const { return rezulto(X.x(), X.y()); };

	double getA() const { return A; };
	double getB() const { return B; };
	double getC() const { return C; };
	double getD() const { return D; };
	double getE() const { return E; };
	double getF() const { return F; };
	double getG() const { return G; };

	//! Конструктор класса KvadratigantoFunkcio по умолчанию.
  /*! @param parent Родитель.
   */
  KvadratigantoFunkcio(QObject * parent = 0) : funkcio(parent){
    A = 1; B = 1; C = 1; D = 1; E = 1; F = 1; G = 1;
  };
  //! Конструктор класса KvadratigantoFunkcio.
  /*! @param parent Родитель.
   */
  KvadratigantoFunkcio(double A, double B, double C, double D, double E, double F, double G, QObject * parent = 0)
    : funkcio(parent){
    this->A = A; this->B = B; this->C = C; this->D = D; this->E = E; this->F = F; this->G = G;
  };
	//! Конструктор класса KvadratigantoFunkcio.
  /*! @param parent Родитель.
   * @param data Массив с параметрами функции.
   */
	KvadratigantoFunkcio(QVector<double> data, QObject * parent = 0) : funkcio(parent)
 	{
		this->A = data[0]; this->B = data[1]; this->C = data[2]; this->D = data[3]; this->E = data[4]; this->F = data[5]; this->G = data[6];
 	};
  
};

//! Реализация целевой "овражной" функции.
/*!  A*pow((x2 - pow(x1, 2)), 2) + B*pow((1-x1), 2)
 * @author Александр Проскурин, Василий Почкаенко.
 */
class RavinaFunkcio : public funkcio
{
Q_OBJECT

private:
	//! Коэффициенты.
	double A, B;

	double getC() const { return 0; };
	double getD() const { return 0; };
	double getE() const { return 0; };
	double getF() const { return 0; };
	double getG() const { return 0; };

public:

	//! Возвращает значение частной производной первого порядка по x1.
	double df_dx1(const QVector<double> X) const
	{ return -4*A*(X[1]*X[0] - pow(X[0], 3)) + 2*B*(1 - X[0]); };
	//! Возвращает значение частной производной первого порядка по x1.
	double df_dx1(const QPointF X) const
	{ return -4*A*(X.y()*X.x() - pow(X.x(), 3)) + 2*B*(1 - X.x()); };

	//! Возвращает значение частной производной первого порядка по x2.
	double df_dx2(const QVector<double> X) const
	{ return 2*A*(X[1] - pow(X[0], 2)); };
	//! Возвращает значение частной производной первого порядка по x2.
	double df_dx2(const QPointF X) const
	{ return 2*A*(X.y() - pow(X.x(), 2)); };

	//! Возвращает определитель гессиана.
	double detGessian(const QPointF * X) const
	{ return df_dx1dx1(X) * df_dx2dx2() - pow(df_dx1dx2(X), 2); }
	
	//! Возвращает значение частной производной второго порядка.
	double df_dx1dx1(const QPointF * X) const
	{ return 12*A*X->x()*X->x() - 4*A*X->y() + 2*B; }
	//! Возвращает значение частной производной второго порядка.
	double df_dx1dx2(const QPointF * X) const
	{ return - 4*A*X->x(); }
	//! Возвращает значение частной производной второго порядка.
	double df_dx2dx2() const
	{ return 2*A; }
	
  //! Возвращает результат вычисления функции в точке.
  double rezulto(const double x1, //!< Первая координата точки.
                 const double x2 //!< Вторая координата точки.
                ) const
  { return A * pow((x2 - pow(x1, 2)), 2) + B * pow((1-x1), 2); };
  //! Возвращает результат вычисления функции в точке.
  /*! @param X Точка.
   */
  double rezulto(const QVector<double> X) const
  { return A * pow((X[1] - pow(X[0], 2)), 2) + B * pow((1-X[0]), 2); };
  //! Возвращает результат вычисления функции в точке.
  /*! @param X Точка.
   */
  double rezulto(const QPointF & X) const { return rezulto(X.x(), X.y()); };
  	
	double getA() const { return A; };
	double getB() const { return B; };

	//! Конструктор класса RavinaFunkcio по умолчанию.
	/*! @param parent Родитель.
	 */
  RavinaFunkcio(QObject * parent = 0) : funkcio(parent){ A = 1; B = 1; };
  //! Конструктор класса RavinaFunkcio.
  /*! @param parent Родитель.
   */
  RavinaFunkcio(double A, double B, QObject * parent = 0) : funkcio(parent){ this->A = A; this->B = B; };
	//! Конструктор класса RavinaFunkcio.
  /*! @param parent Родитель.
   * @param data Массив с параметрами функции.
   */
	RavinaFunkcio(QVector<double> data, QObject * parent = 0) : funkcio(parent)
	{
		this->A = data[0]; this->B = data[1];
	};
};
#endif
