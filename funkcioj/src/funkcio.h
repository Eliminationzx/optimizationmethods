#ifndef FUNKCIO_H
#define FUNKCIO_H
//
#include <QObject>
#include <math.h>
//
//! Класс для целевой функции. 
class funkcio : public QObject
{
Q_OBJECT
public:
  //! Возвращает результат вычисления функции в точке.
  virtual double rezulto(const double x1, const double x2) { return 1;};
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
public:
  //! Возвращает результат вычисления функции в точке.
  double rezulto(const double x1, const double x2) { return A*pow((x1 - B), 2) + C*pow((x2 - D), 2) + E*(x1 - F)*(x2 - G);};
  KvadratigantoFunkcio(QObject * parent = 0) : funkcio(parent){
    A = 1; B = 1; C = 1; D = 1; E = 1; F = 1; G = 1;
  };
  KvadratigantoFunkcio(double A, double B, double C, double D, double E, double F, double G, QObject * parent = 0)
    : funkcio(parent){
    this->A = A; this->B = B; this->C = C; this->D = D; this->E = E; this->F = F; this->G = G;
  };
  
};

//! Реализация целевой "овражной" функции.
/*!  A * pow((x2 - pow(x1, 2)), 2) + B * pow((1-x1), 2)
 */
class RavinaFunkcio : public funkcio
{
Q_OBJECT
private:
  //! Коэффициенты.
  double A, B;
public:
  //! Возвращает результат вычисления функции в точке.
  double rezulto(const double x1, const double x2) { return A * pow((x2 - pow(x1, 2)), 2) + B * pow((1-x1), 2); };
  RavinaFunkcio(QObject * parent = 0) : funkcio(parent){ A = 1; B = 1; };
  RavinaFunkcio(double A, double B, QObject * parent = 0) : funkcio(parent){ this->A = A; this->B = B; };
};
#endif
