#include "funkcio.h"
//
//! Реализация методов класса-родитекля для целевых функций.

  //! Возвращает длину шага для оптимизации функции одной переменной.
  double funkcio::lengthOfStep(const QVector<double> X, const double e) const
  {
    // Найдя антиградиент, мы ввели новую ось, вдоль которой теперь надо найти
    // минимум. Текущая точка (х1;х2) соответствует 0 на новой оси.
  	double a = 0;
	double b = 0.01;

	// Изменяю b, пока не будет чашка.
	while(rezulto(X[0] - b*df_dx1(X), X[1] - b*df_dx2(X)) < rezulto(X[0] - (b-50)*df_dx1(X), X[1] - (b-50)*df_dx2(X)))
		b += 0.5*b;

    double tau = 0.618033988749894;
  	double lam = a + (1 - tau)*(b - a);
  	double mu = a + tau*(b - a);
  	while (fabs(b - a) > e)
  	{
  		if (rezulto(X[0] - lam*df_dx1(X), X[1] - lam*df_dx2(X)) > rezulto(X[0] - mu*df_dx1(X), X[1] - mu*df_dx2(X)))
  		{
  			a = lam;
  			lam = a + (1 - tau)*(b - a);
  			mu = a + tau*(b - a);
 		}
 		else
 		{
 			b = mu;
 			lam = a + (1 - tau)*(b - a);
 			mu = a + tau*(b - a);
		}
 	}
 	return (a + b)/2;
  }

//! Возвращает длину шага для оптимизации функции одной переменной.
double funkcio::lengthOfStep(const QPointF X) const
{
	// Найдя антиградиент, мы ввели новую ось, вдоль которой теперь надо найти
	// минимум. Текущая точка (х1;х2) соответствует 0 на новой оси.
	double a = 0;
	// b надо взять такое, что бы в разрезе по новой оси функция имела форму чашки. 
	double b = 0.01;
	// Изменяю b, пока не будет чашка.
	while(rezulto(X.x() - b*df_dx1(X), X.y() - b*df_dx2(X)) < rezulto(X.x() - (b-0.01)*df_dx1(X), X.y() - (b-0.01)*df_dx2(X)))
		b += 0.5*b;
	
	double tau = 0.618033988749894;
	double lam = a + (1 - tau)*(b - a);
	double mu = a + tau*(b - a);
	
	while (fabs(b - a) > 0.0000001)
	{
		if(rezulto(X.x() - lam*df_dx1(X), X.y() - lam*df_dx2(X)) > rezulto(X.x() - mu*df_dx1(X), X.y() - mu*df_dx2(X)))
		{
			a = lam;
			lam = a + (1 - tau)*(b - a);
			mu = a + tau*(b - a);
		}
		else if(rezulto(X.x() - lam*df_dx1(X), X.y() - lam*df_dx2(X)) < rezulto(X.x() - mu*df_dx1(X), X.y() - mu*df_dx2(X)))
		{
			b = mu;
			lam = a + (1 - tau)*(b - a);
			mu = a + tau*(b - a);
		}
		else
		{
			a = lam;
			b = mu;
			lam = a + (1 - tau)*(b - a);
			mu = a + tau*(b - a);
		}
	}
	return (a + b)/2;
}

  //! Возвращает точку минимума функции.
  QVector<double> funkcio::minPoint(const double e) const
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