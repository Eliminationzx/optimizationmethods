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

private:
  //! Возвращает значение частной производной первого порядка по x1.
  virtual double df_dx1(const QVector<double> X) = 0;
  //! Возвращает значение частной производной первого порядка по x2.
  virtual double df_dx2(const QVector<double> X) = 0;
  //! Возвращает длину шага для оптимизации функции одной переменной.
  double lengthOfStep(const QVector<double> X, const double e);
  
public:
  //! Возвращает результат вычисления функции в точке.
  virtual double rezulto(const double x1, const double x2) = 0;
  //! Возвращает результат вычисления функции в точке.
  virtual double rezulto(const QVector<double> X) = 0;
  //! Возвращает результат вычисления функции в точке.
  virtual double rezulto(const QPointF X){ return rezulto(X.x(), X.y()); };
  //! Возвращает точку минимума функции.
  virtual QVector<double> minPoint(
                                   const double e //!< Точность.
                                  );
  //! Возвращает точку минимума функции.
//  virtual QPointF minPoint(
//                           const double e //!< Точность.
//                          ){ return QPointF(minPoint(e)[0], return QPointF(minPoint(e)[1]); };
  funkcio(QObject * parent = 0) : QObject(parent){};
};

//! Реализация целевой квадратичной функции.
/*! A*pow((x1 - B), 2) + C*pow((x2 - D), 2) + E*(x1 - F)*(x2 - G)
 */
class KvadratigantoFunkcio : public funkcio
{
Q_OBJECT

private:
  //! Коэффициенты.
  double A, B, C, D, E, F, G;
  //! Возвращает значение частной производной первого порядка по x1.
  double df_dx1(const QVector<double> X)
  { return 2*A*(X[0] - B) + E*(X[1] - G); };
  //! Возвращает значение частной производной первого порядка по x2.
  double df_dx2(const QVector<double> X)
  { return 2*C*(X[1] - D) + E*(X[0] - F); }
  	
public:
  //! Возвращает результат вычисления функции в точке.
  double rezulto(const double x1, const double x2)
  { return A*pow((x1 - B), 2) + C*pow((x2 - D), 2) + E*(x1 - F)*(x2 - G); };
  //! Возвращает результат вычисления функции в точке.
  double rezulto(const QVector<double> X)
  { return A*pow((X[0] - B), 2) + C*pow((X[1] - D), 2) + E*(X[0] - F)*(X[1] - G); };
  	
  	//! Конструктор класса KvadratigantoFunkcio по умолчанию.
  KvadratigantoFunkcio(QObject * parent = 0) : funkcio(parent){
    A = 1; B = 1; C = 1; D = 1; E = 1; F = 1; G = 1;
  };
  //! Конструктор класса KvadratigantoFunkcio.
  KvadratigantoFunkcio(double A, double B, double C, double D, double E, double F, double G, QObject * parent = 0)
    : funkcio(parent){
    this->A = A; this->B = B; this->C = C; this->D = D; this->E = E; this->F = F; this->G = G;
  };
	//! Конструктор класса KvadratigantoFunkcio.
	KvadratigantoFunkcio(QVector<double> data, QObject * parent = 0) : funkcio(parent)
 	{
		this->A = data[0]; this->B = data[1]; this->C = data[2]; this->D = data[3]; this->E = data[4]; this->F = data[5]; this->G = data[6];
 	};
  
};

//! Реализация целевой "овражной" функции.
/*!  A*pow((x2 - pow(x1, 2)), 2) + B*pow((1-x1), 2)
 */
class RavinaFunkcio : public funkcio
{
Q_OBJECT

private:
  //! Коэффициенты.
  double A, B;
  //! Возвращает значение частной производной первого порядка по x1.
  double df_dx1(const QVector<double> X)
  { return -4*A*(X[1] - pow(X[0], 2)) + 2*B*(1 - X[0]); };
  //! Возвращает значение частной производной первого порядка по x2.
  double df_dx2(const QVector<double> X)
  { return 2*A*(X[1] - pow(X[0], 2)); };
  
public:
  //! Возвращает результат вычисления функции в точке.
  double rezulto(const double x1, const double x2)
  { return A * pow((x2 - pow(x1, 2)), 2) + B * pow((1-x1), 2); };
  //! Возвращает результат вычисления функции в точке.
  double rezulto(const QVector<double> X)
  { return A * pow((X[1] - pow(X[0], 2)), 2) + B * pow((1-X[0]), 2); };
  	
  	//! Конструктор класса RavinaFunkcio по умолчанию.
  RavinaFunkcio(QObject * parent = 0) : funkcio(parent){ A = 1; B = 1; };
  //! Конструктор класса RavinaFunkcio.
  RavinaFunkcio(double A, double B, QObject * parent = 0) : funkcio(parent){ this->A = A; this->B = B; };
	//! Конструктор класса RavinaFunkcio.
	RavinaFunkcio(QVector<double> data, QObject * parent = 0) : funkcio(parent)
	{
		this->A = data[0]; this->B = data[1];
	};
};
#endif
