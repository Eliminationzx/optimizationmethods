#ifndef NEMIIMPL_H
#define NEMIIMPL_H
//
#include "algoritmowin.h"
#include "ui_NeMi.h"
#include "demonstrataqpointf.h"
#include <QSignalTransition>
#include <QState>
//
class funkcio;
const int a = 1;
const int b = 2;
const double c = 0.5;
//
//! Окно для прохождения метода Нелдора-Мида.
class NeMiImpl : public AlgoritmoWin, public Ui::NeMi
{
Q_OBJECT

protected:
	//! Первая точка основного триугольника.
	DemonstrataQPointF P1;
	//! Вторая точка основного триугольника.
	DemonstrataQPointF P2;
	//! Третья точка основного триугольника.
	DemonstrataQPointF P3;
	//! Указатель на наибольшую точку.
	DemonstrataQPointF * Ph;
	//! Указатель на средную точку.
	DemonstrataQPointF * Pm;
	//! Указатель на наименьшую точку.
	DemonstrataQPointF * Pl;
	//! Центр тяжести триугольника.
	QPointF Pc;
	//! Отражённая точка.
	DemonstrataQPointF PR;
	//! Сжатая точка.
	DemonstrataQPointF PK;
	//! Растянутая точка.
	DemonstrataQPointF PD;

public:
	NeMiImpl( funkcio * f, QVector<double> d, QWidget * parent = 0,
	          Qt::WFlags flags = 0 );

private slots:
	void on_about_action_activated();
	//! изменить шрифт
	void on_difiniFonto_act_activated();

	//! help браузер
	void on_helpo_action_activated();

	qreal averagxoDistanco();
	/*! "Обнуление" переменных.
	 *
	 * Этим методом задаются началные знаения всем переменным алгоритма.
	 * Используется перед запуском конецного автомата и в переходе вызванным
	 * действием "Начать заново".
	 */
	void init();
	/*! Обработчик входа в состояние so.
	 *
	 * Исполизую для дебага.
	 */
	void so_entered();
	/*! Обработчик входа в состояние ss.
	 */
	void ss_entered();
	/*! Обработчик входа в состояние s1.
	 */
	void s1_entered();
	/*! Обработчик входа в состояние s2.
	 */
	void s2_entered();
	/*! Обработчик входа в состояние s3.
	 */
	void s3_entered();
	/*! Обработчик входа в состояние s5.
	 */
	void s5_entered();
	/*! Обработчик выхода из состояния s5.
	 */
	void s5_exited();
	/*! Обработчик входа в состояние s6.
	 */
	void s6_entered();
	/*! Обработчик входа в состояние s7.
	 */
	void s7_entered();
	/*! Обработчик входа в состояние s8.
	 */
	void s8_entered();
	/*! Обработчик входа в состояние s9.
	 */
	void s9_entered();
	/*! Обработчик входа в состояние s10.
	 */
	void s10_entered();
	/*! Обработчик входа в состояние s11.
	 */
	void s11_entered();
	//! Обработчик входа в состояние sf - конец поиска.
	void sf_entered();
  //! Фиксирует совершение пользователем ошики.
  void registriEraro();
  //! Обработчик перехода s3s1.
  void s3s2_triggered();
signals:
	/*! Использую сигнал для прехода, который не требует действий пользователя,
	 * а только проверяет условие.
	 */
	void stateHasEntered();
};
/*! В этом пространстве имён содержаться классы относящиеся к конечному автомату
 * для метода Нелдора-Мида.
 *
 * Объявления наследников QSignalTransition можно не смотреть. Важна только
 * реализация метода eventTest, ради которой и переопрделяю классы.
 */
namespace NeMi{
	/*! Переход от s2 к s3.
	 *
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s2s3Transiro: public QSignalTransition{
		private:
			QRadioButton * t1_ref;
			QRadioButton * t2_ref;
			QRadioButton * t3_ref;
			DemonstrataQPointF ** ph;
			DemonstrataQPointF * p1;
			DemonstrataQPointF * p2;
			DemonstrataQPointF * p3;
			funkcio * f;
		public:
			s2s3Transiro( QRadioButton * t1_ref_rb, QRadioButton * t2_ref_rb,
			              QRadioButton * t3_ref_rb, DemonstrataQPointF ** Ph,
										DemonstrataQPointF * P1, DemonstrataQPointF * P2,
										DemonstrataQPointF * P3, funkcio * F,
										QState * sourceState = 0)
				: QSignalTransition(sourceState), t1_ref(t1_ref_rb), t2_ref(t2_ref_rb),
					t3_ref(t3_ref_rb), ph(Ph), p1(P1), p2(P2), p3(P3), f(F){};
			s2s3Transiro( QRadioButton * t1_ref_rb,
			              QRadioButton * t2_ref_rb,
			              QRadioButton * t3_ref_rb,
			              DemonstrataQPointF ** Ph,
			              DemonstrataQPointF * P1,
			              DemonstrataQPointF * P2,
										DemonstrataQPointF * P3,
									  funkcio * F,
									  QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			              )
				: QSignalTransition(sender, signal, sourceState), t1_ref(t1_ref_rb),
					t2_ref(t2_ref_rb), t3_ref(t3_ref_rb), ph(Ph), p1(P1), p2(P2), p3(P3),
					f(F){};
		protected:
			//! Переход срабатывает, только если выбрана наибольшая точка.
			bool eventTest(QEvent *e);
	};
	/*! Переход от s3 к s1.
	 *
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s3s2Transiro: public QSignalTransition{
		private:
			DemonstrataQPointF ** pl;
			DemonstrataQPointF * pr;
			DemonstrataQPointF ** pm;
			funkcio * f;
		public:
			s3s2Transiro( DemonstrataQPointF ** Pl, DemonstrataQPointF * PR,
			              DemonstrataQPointF ** Pm, funkcio * F,
			              QState * sourceState = 0)
				: QSignalTransition(sourceState), pl(Pl), pr(PR), pm(Pm), f(F){};
			s3s2Transiro( DemonstrataQPointF ** Pl,
			              DemonstrataQPointF * PR,
			              DemonstrataQPointF ** Pm,
			              funkcio * F,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            )
				: QSignalTransition(sender, signal, sourceState), pl(Pl), pr(PR),
					pm(Pm), f(F){};
		protected:
			//! Переход срабатывает, только если F(Xl) < F(Хотр) < F(Xm).
			bool eventTest(QEvent *e);
	};
	/*! Переход от s3 к s5.
	 *
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s3s5Transiro: public QSignalTransition{
		private:
			DemonstrataQPointF ** ph;
			DemonstrataQPointF * pr;
			DemonstrataQPointF ** pm;
			funkcio * f;
		public:
			s3s5Transiro( DemonstrataQPointF ** Ph, DemonstrataQPointF * PR,
			              DemonstrataQPointF ** Pm, funkcio * F,
			              QState * sourceState = 0)
				: QSignalTransition(sourceState), ph(Ph), pr(PR), pm(Pm), f(F){};
			s3s5Transiro( DemonstrataQPointF ** Ph,
			              DemonstrataQPointF * PR,
			              DemonstrataQPointF ** Pm,
			              funkcio * F,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            )
				: QSignalTransition(sender, signal, sourceState), ph(Ph), pr(PR),
					pm(Pm), f(F){};
		protected:
			//! Переход срабатывает, только если F(Xm) < F(Хотр) < F(Xh).
			bool eventTest(QEvent *e);
	};
	/*! Переход от s3 к s6.
	 *
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s3s6Transiro: public QSignalTransition{
		private:
			DemonstrataQPointF ** pl;
			DemonstrataQPointF * pr;
			funkcio * f;
		public:
			s3s6Transiro( DemonstrataQPointF ** Pl, DemonstrataQPointF * PR,
			              funkcio * F,QState * sourceState = 0)
				: QSignalTransition(sourceState), pl(Pl), pr(PR), f(F){};
			s3s6Transiro( DemonstrataQPointF ** Pl,
			              DemonstrataQPointF * PR,
			              funkcio * F,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            )
				: QSignalTransition(sender, signal, sourceState), pl(Pl), pr(PR),
					f(F){};
		protected:
			//! Переход срабатывает, только если F(Хотр) < F(Хl).
			bool eventTest(QEvent *e);
	};
	/*! Переход от s3 к s11.
	 *
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s3s11Transiro: public QSignalTransition{
		private:
			DemonstrataQPointF ** ph;
			DemonstrataQPointF * ps;
			funkcio * f;
		public:
			s3s11Transiro( DemonstrataQPointF ** Ph, DemonstrataQPointF * PS,
										 funkcio * F, QState * sourceState = 0)
				: QSignalTransition(sourceState), ph(Ph), ps(PS), f(F){};
				s3s11Transiro( DemonstrataQPointF ** Ph,
											 DemonstrataQPointF * PS,
											 funkcio * F,
											 QObject * sender,
			                 const char * signal,
			                 QState * sourceState = 0
			               )
				: QSignalTransition(sender, signal, sourceState), ph(Ph), ps(PS), f(F){};
		protected:
			//! Переход срабатывает, только если
			bool eventTest(QEvent *e);
	};
	/*! Переход от s5 к s10.
	 *
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s5s10Transiro: public QSignalTransition{
		private:
			QRadioButton * t1_com;
			QRadioButton * t2_com;
			QRadioButton * t3_com;
			DemonstrataQPointF ** ph;
			DemonstrataQPointF * p1;
			DemonstrataQPointF * p2;
			DemonstrataQPointF * p3;
			funkcio * f;
		public:
			s5s10Transiro( QRadioButton * t1_com_rb, QRadioButton * t2_com_rb,
			               QRadioButton * t3_com_rb, DemonstrataQPointF ** Ph,
			               DemonstrataQPointF * P1, DemonstrataQPointF * P2,
			               DemonstrataQPointF * P3, funkcio * F,
										 QState * sourceState = 0)
				: QSignalTransition(sourceState), t1_com(t1_com_rb), t2_com(t2_com_rb),
					t3_com(t3_com_rb), ph(Ph), p1(P1), p2(P2), p3(P3), f(F){};
			s5s10Transiro( QRadioButton * t1_com_rb,
			               QRadioButton * t2_com_rb,
			               QRadioButton * t3_com_rb,
			               DemonstrataQPointF ** Ph,
			               DemonstrataQPointF * P1,
			               DemonstrataQPointF * P2,
										 DemonstrataQPointF * P3,
										 funkcio * F,
									   QObject * sender,
			               const char * signal,
			               QState * sourceState = 0
			             )
				: QSignalTransition(sender, signal, sourceState), t1_com(t1_com_rb),
					t2_com(t2_com_rb), t3_com(t3_com_rb), ph(Ph), p1(P1), p2(P2), p3(P3),
					f(F){};
		protected:
			//! Переход срабатывает, только если выбрана max{T1, T2, T3}
			bool eventTest(QEvent *e);
	};
	/*! Переход от s6 к s8.
	 *
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s6s8Transiro: public QSignalTransition{
		private:
			QRadioButton * tras_str;
			DemonstrataQPointF ** pl;
			DemonstrataQPointF * pd;
			funkcio * f;
		public:
			s6s8Transiro( QRadioButton * tras_str_rb,
			            DemonstrataQPointF ** Pl, DemonstrataQPointF * PD, funkcio * F,
									QState * sourceState = 0)
				: QSignalTransition(sourceState), tras_str(tras_str_rb),
					pl(Pl), pd(PD), f(F){};
			s6s8Transiro( QRadioButton * tras_str_rb,
			              DemonstrataQPointF ** Pl,
			              DemonstrataQPointF * PD,
			              funkcio * F,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            )
				: QSignalTransition(sender, signal, sourceState), tras_str(tras_str_rb),
					pl(Pl), pd(PD), f(F){};
		protected:
			//! Переход срабатывает, только если F(Xрас) < F(Xl) && выбрана Храс.
			bool eventTest(QEvent *e);
	};
	/*! Переход от s6 к s9.
	 *
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s6s9Transiro: public QSignalTransition{
		private:
			QRadioButton * totr_str;
			DemonstrataQPointF ** pl;
			DemonstrataQPointF * pd;
			funkcio * f;
		public:
			s6s9Transiro( QRadioButton * totr_str_rb, 
			              DemonstrataQPointF ** Pl, DemonstrataQPointF * PD, funkcio * F,
									  QState * sourceState = 0)
				: QSignalTransition(sourceState), totr_str(totr_str_rb), pl(Pl), pd(PD),
					f(F){};
			s6s9Transiro( QRadioButton * totr_str_rb,
			              DemonstrataQPointF ** Pl,
			              DemonstrataQPointF * PD,
			              funkcio * F,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            )
				: QSignalTransition(sender, signal, sourceState), totr_str(totr_str_rb),
					pl(Pl), pd(PD), f(F){};
		protected:
			//! Переход срабатывает, только если F(Xрас) >= F(Xl) && выбрана Хотр.
			bool eventTest(QEvent *e);
	};
	/*! Переход от s11 к s7.
	 *
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s11s7Transiro: public QSignalTransition{
		private:
			QRadioButton * t1_red;
			QRadioButton * t2_red;
			QRadioButton * t3_red;
			DemonstrataQPointF ** pl;
			DemonstrataQPointF * p1;
			DemonstrataQPointF * p2;
			DemonstrataQPointF * p3;
			funkcio * f;
		public:
			s11s7Transiro( QRadioButton * t1_red_rb,
			               QRadioButton * t2_red_rb,
			               QRadioButton * t3_red_rb, DemonstrataQPointF ** Pl,
			               DemonstrataQPointF * P1, DemonstrataQPointF * P2,
			               DemonstrataQPointF * P3, funkcio * F,
			               QState * sourceState = 0)
				: QSignalTransition(sourceState), t1_red(t1_red_rb),
					t2_red(t2_red_rb), t3_red(t3_red_rb), pl(Pl), p1(P1), p2(P2), p3(P3),
					f(F){};
			s11s7Transiro( QRadioButton * t1_red_rb,
			               QRadioButton * t2_red_rb,
			               QRadioButton * t3_red_rb,
			               DemonstrataQPointF ** Pl,
			               DemonstrataQPointF * P1,
			               DemonstrataQPointF * P2,
			               DemonstrataQPointF * P3,
			               funkcio * F,
			               QObject * sender,
			               const char * signal,
			               QState * sourceState = 0
			             )
				: QSignalTransition(sender, signal, sourceState), t1_red(t1_red_rb),
					t2_red(t2_red_rb), t3_red(t3_red_rb), pl(Pl), p1(P1), p2(P2), p3(P3),
					f(F){};
		protected:
			//! Переход срабатывает, только если
			bool eventTest(QEvent *e);
	};
	/*! Переход от ss к s1.
	 *
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class sss1Transiro: public QSignalTransition{
		private:
			qreal s;
			DemonstrataQPointF ** ph;
			DemonstrataQPointF ** pl;
			DemonstrataQPointF ** pm;
			QPointF * pc;
			funkcio * f;
		public:
			sss1Transiro( qreal strikteco, DemonstrataQPointF ** Ph, DemonstrataQPointF ** Pl,
			              DemonstrataQPointF ** Pm, QPointF * Pc, funkcio * F,
										QState * sourceState = 0)
				: QSignalTransition(sourceState), s(strikteco), ph(Ph), pl(Pl), pm(Pm),
					pc(Pc), f(F){};
			sss1Transiro( qreal strikteco, 
			              DemonstrataQPointF ** Ph,
			              DemonstrataQPointF ** Pl,
			              DemonstrataQPointF ** Pm,
			              QPointF * Pc,
			              funkcio * F,
			              QObject * sender,
			              const char * signal,
		                QState * sourceState = 0
		              )
				: QSignalTransition(sender, signal, sourceState), s(strikteco), ph(Ph),
					pl(Pl), pm(Pm), pc(Pc), f(F){};
		protected:
			//! Переход срабатывает, только если (1/4)*((F(Xl)-(F(Xc))^2 + ((F(Xh)-(F(Xc)))^2 + ((F(Xm)-(F(Xc)))^2) >= e.
			bool eventTest(QEvent *e);
	};
	/*! Переход от ss к sf.
	 *
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class sssfTransiro: public QSignalTransition{
		private:
			qreal s;
			DemonstrataQPointF ** ph;
			DemonstrataQPointF ** pl;
			DemonstrataQPointF ** pm;
			QPointF * pc;
			funkcio * f;
		public:
			sssfTransiro( qreal strikteco, 
			              DemonstrataQPointF ** Ph, DemonstrataQPointF ** Pl,
			              DemonstrataQPointF ** Pm, QPointF * pc, funkcio * F,
										QState * sourceState = 0)
				: QSignalTransition(sourceState), s(strikteco), ph(Ph), pl(Pl), pm(Pm),
					pc(pc), f(F){};
			sssfTransiro( qreal strikteco, 
			              DemonstrataQPointF ** Ph,
			              DemonstrataQPointF ** Pl,
			              DemonstrataQPointF ** Pm,
			              QPointF * pc,
			              funkcio * F,
			              QObject * sender,
			              const char * signal,
		                QState * sourceState = 0
		              )
				: QSignalTransition(sender, signal, sourceState), s(strikteco), ph(Ph),
					pl(Pl), pm(Pm), pc(pc), f(F){};
		protected:
			//! Переход срабатывает, только если (1/4)*((F(Xl)-(F(Xc))^2 + ((F(Xh)-(F(Xc)))^2 + ((F(Xm)-(F(Xc)))^2) < e.
			bool eventTest(QEvent *e);
	};
}
#endif







