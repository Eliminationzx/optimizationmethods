#ifndef FUNKCIO_H
#define FUNKCIO_H
//
#include <QObject>
#include <math.h>
#include <QVector>
//
//! Класс для целевой функции.
class funkcio : public QObject
{
Q_OBJECT

private:
  //! Возвращает значение частной производной первого порядка по x1.
  virtual double df_dx1(const QVector<double> X);
  //! Возвращает значение частной производной первого порядка по x2.
  virtual double df_dx2(const QVector<double> X);
  //! Возвращает длину шага для оптимизации функции одной переменной.
  virtual double lengthOfStep(const QVector<double> X, const double e);
  
public:
  //! Возвращает результат вычисления функции в точке.
  virtual double rezulto(const double x1, const double x2);
  //! Возвращает результат вычисления функции в точке.
  virtual double rezulto(const QVector<double> X);
  //! Возвращает точку минимума функции.
  virtual QVector<double> minPoint(const double e);
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
  //! Возвращает длину шага для оптимизации функции одной переменной.
  double lengthOfStep(const QVector<double> X, const double e);
  	
public:
  //! Возвращает результат вычисления функции в точке.
  double rezulto(const double x1, const double x2)
  { return A*pow((x1 - B), 2) + C*pow((x2 - D), 2) + E*(x1 - F)*(x2 - G); };
  //! Возвращает результат вычисления функции в точке.
  double rezulto(const QVector<double> X)
  { return A*pow((X[0] - B), 2) + C*pow((X[1] - D), 2) + E*(X[0] - F)*(X[1] - G); };
  //! Возвращает точку минимума функции.
  QVector<double> minPoint(const double e);
  KvadratigantoFunkcio(QObject * parent = 0) : funkcio(parent){
    A = 1; B = 1; C = 1; D = 1; E = 1; F = 1; G = 1;
  };
  KvadratigantoFunkcio(double A, double B, double C, double D, double E, double F, double G, QObject * parent = 0)
    : funkcio(parent){
    this->A = A; this->B = B; this->C = C; this->D = D; this->E = E; this->F = F; this->G = G;
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
  //! Возвращает длину шага для оптимизации функции одной переменной.
  double lengthOfStep(const QVector<double> X, const double e);
  
public:
  //! Возвращает результат вычисления функции в точке.
  double rezulto(const double x1, const double x2)
  { return A * pow((x2 - pow(x1, 2)), 2) + B * pow((1-x1), 2); };
  //! Возвращает результат вычисления функции в точке.
  double rezulto(const QVector<double> X)
  { return A * pow((X[1] - pow(X[0], 2)), 2) + B * pow((1-X[0]), 2); };
  //! Возвращает точку минимума функции.
  QVector<double> minPoint(const double e);
  RavinaFunkcio(QObject * parent = 0) : funkcio(parent){ A = 1; B = 1; };
  RavinaFunkcio(double A, double B, QObject * parent = 0) : funkcio(parent){ this->A = A; this->B = B; };
};
#endif
