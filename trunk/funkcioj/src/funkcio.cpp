#include "funkcio.h"
//
//! Реализация целевой квадратичной функции.
/*! A*pow((x1 - B), 2) + C*pow((x2 - D), 2) + E*(x1 - F)*(x2 - G)
 */
  //! Возвращает длину шага для оптимизации функции одной переменной.
  double KvadratigantoFunkcio::lengthOfStep(const QVector<double> X, const double e)
  {
  	double a, b, tau = 0.618033988749894;
  	double lam = a + (1 - tau)*(b - a);
  	double mu = a + tau*(b - a);
  	while (abs(b - a) > e)
  	{
  		if (rezulto(X[0] - lam*df_dx1(X), X[1] - lam*df_dx2(X)) > rezulto(X[0] - mu*df_dx1(X), X[1] - mu*df_dx2(X)))
  		{
  			a = lam;
  			lam = mu;
  			mu = a + tau*(b - a);
 		}
 		else
 		{
 			b = mu;
 			mu = lam;
 			lam = a + (1 - tau)*(b - a);
		}
 	}
 	return (a + b)/2;
  }
  //! Возвращает точку минимума функции.
  QVector<double> KvadratigantoFunkcio::minPoint(const double e)
  {
    QVector<double> X(2);
    X[0] = 2; X[1] = 2;
  	while ((df_dx1(X) > e) || (df_dx2(X)) > e)
  	{
  		X[0] = X[0] - lengthOfStep(X, e)*df_dx1(X);
  		X[1] = X[1] - lengthOfStep(X, e)*df_dx2(X);
 	}
 	return X;
  }

//! Реализация целевой "овражной" функции.
/*!  A*pow((x2 - pow(x1, 2)), 2) + B*pow((1-x1), 2)
 */
  //! Возвращает длину шага для оптимизации функции одной переменной.
  double RavinaFunkcio::lengthOfStep(const QVector<double> X, const double e)
  {
  	double a, b, tau = 0.618033988749894;
  	double lam = a + (1 - tau)*(b - a);
  	double mu = a + tau*(b - a);
  	while (abs(b - a) > e)
  	{
  		if (rezulto(X[0] - lam*df_dx1(X), X[1] - lam*df_dx2(X)) > rezulto(X[0] - mu*df_dx1(X), X[1] - mu*df_dx2(X)))
  		{
  			a = lam;
  			lam = mu;
  			mu = a + tau*(b - a);
 		}
 		else
 		{
 			b = mu;
 			mu = lam;
 			lam = a + (1 - tau)*(b - a);
		}
 	}
 	return (a + b)/2;
  }
  //! Возвращает точку минимума функции.
  QVector<double> RavinaFunkcio::minPoint(const double e)
  {
  	QVector<double> X(2);
  	X[0] = 2; X[1] = 2;
  	while ((df_dx1(X) > e) || (df_dx2(X)) > e)
  	{
  		X[0] = X[0] - lengthOfStep(X, e)*df_dx1(X);
  		X[1] = X[1] - lengthOfStep(X, e)*df_dx2(X);
 	}
 	return X;
  }
//