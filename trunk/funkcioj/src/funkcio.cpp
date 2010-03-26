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
  		if (KvadratigantoFunkcio::rezulto(X[0] - lam*KvadratigantoFunkcio::df_dx1(X), X[1] - lam*KvadratigantoFunkcio::df_dx2(X)) > KvadratigantoFunkcio::rezulto(X[0] - mu*KvadratigantoFunkcio::df_dx1(X), X[1] - mu*KvadratigantoFunkcio::df_dx2(X)))
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
  	while ((KvadratigantoFunkcio::df_dx1(X) > e) || (KvadratigantoFunkcio::df_dx2(X)) > e)
  	{
  		X[0] = X[0] - KvadratigantoFunkcio::lengthOfStep(X, e)*KvadratigantoFunkcio::df_dx1(X);
  		X[1] = X[1] - KvadratigantoFunkcio::lengthOfStep(X, e)*KvadratigantoFunkcio::df_dx2(X);
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
  		if (RavinaFunkcio::rezulto(X[0] - lam*RavinaFunkcio::df_dx1(X), X[1] - lam*RavinaFunkcio::df_dx2(X)) > RavinaFunkcio::rezulto(X[0] - mu*RavinaFunkcio::df_dx1(X), X[1] - mu*RavinaFunkcio::df_dx2(X)))
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
  	while ((RavinaFunkcio::df_dx1(X) > e) || (RavinaFunkcio::df_dx2(X)) > e)
  	{
  		X[0] = X[0] - RavinaFunkcio::lengthOfStep(X, e)*RavinaFunkcio::df_dx1(X);
  		X[1] = X[1] - RavinaFunkcio::lengthOfStep(X, e)*RavinaFunkcio::df_dx2(X);
 	}
 	return X;
  }
//