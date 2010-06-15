#ifndef HUGIIMPL_H
#define HUGIIMPL_H
//
#include "ui_HuGi.h"
#include "algoritmowin.h"
#include "demonstrataqpointf.h"
#include <QSignalTransition>
#include <QState>
#include <QRadioButton>
//
class funkcio;
//
//! Окно для прохождения метода Хука-Дживса.
class HuGiImpl : public AlgoritmoWin, public Ui::HuGi
{
Q_OBJECT
protected:
 	//! Базовая точка итерации.
	DemonstrataQPointF BP;
	//! Текущая базовая точка.
	DemonstrataQPointF MP;
	//! Текущая базовая точка2.
	DemonstrataQPointF MP2;
	//! Промежуточная точка.
	DemonstrataQPointF PP;
	//! Новая точка.
	DemonstrataQPointF NP;
	//! Шаг по х1.
	/*! Для удобства задаю в виде точки (длина, 0).
	 */
	DemonstrataQPointF PX1;
	//! Шаг по х2.
	/*! Для удобства задаю в виде точки (0, длина).
	 */
	DemonstrataQPointF PX2; 
	//! Переменная - буфер для базовой точки
	DemonstrataQPointF TEMP_B; 
	
	//! Модификатор шага.	
	qreal ModPX;
	//! Флаг поиска по образцу
	bool FLAG_SO;
public:
	HuGiImpl( funkcio *f, QVector<double> d,QWidget * parent = 0, Qt::WFlags flags = 0 );
private slots:
	void on_about_action_activated();
	void on_helpo_action_activated();
	void on_difiniFonto_act_activated();
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
	/*! Обработчик входа в состояние s1.
	 * 
	 * В этом состоянии задается флаг о прохождении поиска по образцу (ставится false).
	 */
	void s1_entered();
	/*! Обработчик входа в состояние s2.
	 * 
	 * Использую для дебага.
	 */
	void s2_entered();
	/*! Обработчик входа в состояние s3.
	 * 
	 * В этом состоянии задаются начальные значения переменых для итерации.
	 */
	void s3_entered();
	/*! Обработчик входа в состояние s4.
	 * 
	 * В этом состоянии проверяется точка смещённая от текщей в + по Х1.
	 */
	void s4_entered();
	/*! Обработчик входа в состояние s5.
	 * 
	 *Исполизую для дебага.
	 *
	 */
	void s5_entered();
	/*! Обработчик входа в состояние s6.
	 * 
	 *  В этом состоянии проверяется точка смещённая от текщей в - по Х1.
	 * 
	 */
	void s6_entered();
	/*! Обработчик входа в состояние s7.
	 * 
	 * В этом состоянии текущей точке присваевается значение новой.После поиска
	 * по Х1.
	 */
	void s7_entered();
	/*! Обработчик входа в состояние s8.
	 * 
	 * Исполизую для дебага.
	 */
	void s8_entered();
	/*! Обработчик входа в состояние s9.
	 * 
	 * В этом состоянии проверяется точка смещённая от текщей в + по Х2.
	 */
	void s9_entered();
	/*! Обработчик входа в состояние s10.
	 * 
	 * Исполизую для дебага.
	 * 
	 */
	void s10_entered();
	/*! Обработчик входа в состояние s11.
	 * 
	 *  В этом состоянии проверяется точка смещённая от текщей в - по Х2.
	 */
	void s11_entered();
	/*! Обработчик входа в состояние s12.
	 * 
	 * В этом состоянии текущей точке присваевается значение новой. После поиска
	 * по всем осям.
	 */
	void s12_entered();
	/*! Обработчик входа в состояние s13.
	 * 
	 *Исполизую для дебага.
	 * 
	 */
	void s13_entered();
	/*! Обработчик входа в состояние s14.
	 * 
	 *В этом состоянии уменьшаем длины шагов в 10 раз.
	 * 
	 */
	void s14_entered();
	/*! Обработчик входа в состояние s15.
	 * 
	 *В этом состоянии выводим варианты поиска. Использую для дебага.
	 * 
	 */
	void s15_entered();
	/*! Обработчик входа в состояние s16.
	 * 
	 *В этом состоянии присваиваем базовой точке итерации значение b2_temp (b2 становится базисной точкой).
	 * 
	 */
	void s16_entered();
	/*! Обработчик входа в состояние s18.
	 * 
	 *В этом состоянии  вычисляется промежуточная точка. Принимаем ее как базовую. Точку b2 сохраняем в буфер.
	 * 
	 */
	 void s17_entered();
	/*! Обработчик входа в состояние s18.
	 * 
	 *В этом состоянии  вычисляется промежуточная точка. Принимаем ее как базовую. Точку b2 сохраняем в буфер.
	 * 
	 */
	void s18_entered();
	/*! Обработчик входа в состояние s19.
	 * 
	 *В этом состоянии  за b1 и за b2 принимается промежуточная точка. Флаг прохождения поиска по образцу принимает значение false.
	 * 
	 */
	void s19_entered();
	//! Обработчик входа в состояние sf - конец поиска.
	void sf_entered();
  //! Фиксирует совершение пользователем ошики.
  void registriEraro();
signals:
	/*! Использую сигнал для прехода, который не требует действий пользователя,
	 * а только проверяет условие.
	 */
	void stateHasEntered();
};


/*! В этом пространстве имён содержаться классы относящиеся к конечному автомату
 * для покоординатного спуска с фиксированным шагом.
 * 
 * Объявления наследников QSignalTransition можно не смотреть. Важна только
 * реализация метода eventTest, ради которой и переопрделяю классы.
 */ 
namespace SinkoLauxKoordinatoj_hugi
{
	/*! Переход от s2 к s3 .
	 * 
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s2s3Transiro: public QSignalTransition{
		private:
			QRadioButton * investigate;
		public:
			s2s3Transiro( QRadioButton * investigate_rb, QState * sourceState = 0
			            ) : QSignalTransition(sourceState), investigate(investigate_rb){};
			s2s3Transiro( QRadioButton * investigate_rb,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : QSignalTransition(sender, signal, sourceState),
			                investigate(investigate_rb){};
		protected:
    	bool eventTest(QEvent *e);
	};

	/*! Переход от s3 к s4.
	 * 
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s3s4Transiro: public QSignalTransition{
		private:
			QRadioButton * up_x1;
		public:
			s3s4Transiro( QRadioButton * up_x1_rb, QState * sourceState = 0)
				: QSignalTransition(sourceState), up_x1(up_x1_rb){};
			s3s4Transiro( QRadioButton * up_x1_rb,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            )
				: QSignalTransition(sender, signal, sourceState), up_x1(up_x1_rb){};
		protected:
			//! Перход срабатывает, только если выбран шаг в + по Х1 
    	bool eventTest(QEvent *e);
	};

	/*! Переход принятия новой точки в качестве текщей.
	 * 
	 * Используется при переходе от s4 к s7, s6 к s7, s9 к s12, s11 к s12.
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class KonsideriPointoTransiro: public QSignalTransition{
		private:
			DemonstrataQPointF * np;
			DemonstrataQPointF * pp;
			DemonstrataQPointF * mp2;
			bool * flag_so;
			funkcio * f;
		public:
			KonsideriPointoTransiro( DemonstrataQPointF * NP,
									DemonstrataQPointF * PP,
			                         DemonstrataQPointF * MP2,
			                         bool * FLAG_SO,
			                         funkcio * F,
			                         QState * sourceState = 0
			            ) : QSignalTransition(sourceState), np(NP), pp(PP), mp2(MP2), flag_so(FLAG_SO), f(F){};
			KonsideriPointoTransiro( DemonstrataQPointF * NP,
									DemonstrataQPointF * PP,
			                         DemonstrataQPointF * MP2,
			                         bool * FLAG_SO,
			                         funkcio * F,
			                         QObject * sender,
			                         const char * signal,
			                         QState * sourceState = 0
			                       )
			                        : QSignalTransition(sender, signal, sourceState),
			                          np(NP), pp(PP), mp2(MP2), flag_so(FLAG_SO), f(F){};
		protected:
    	bool eventTest(QEvent *e);
	};

	/*! Переход от s7 к s9.
	 * 
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s7s9_s8s9Transiro: public QSignalTransition{
		private:
			QRadioButton * up_x2;
		public:
			s7s9_s8s9Transiro( QRadioButton * up_x2_rb, QState * sourceState = 0
			                 ) : QSignalTransition(sourceState), up_x2(up_x2_rb){};
			s7s9_s8s9Transiro( QRadioButton * up_x2_rb,
			                   QObject * sender,
			                   const char * signal,
			                   QState * sourceState = 0
			                 ) : QSignalTransition(sender, signal, sourceState),
			                     up_x2(up_x2_rb){};
		protected:
    	bool eventTest(QEvent *e);
	};

	/*! Переход непринятия новой точки в качестве текуей.
	 * 
	 * Используется при переходе от s4 к s5, s6 к s8, s9 к s10, s11 к s13.
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class NoKonsideriPointoTransiro: public QSignalTransition{
		private:
			DemonstrataQPointF * np;
			DemonstrataQPointF * pp;
			DemonstrataQPointF * mp2;
			bool * flag_so;
			funkcio * f;
		public:
			NoKonsideriPointoTransiro( DemonstrataQPointF * NP,
									DemonstrataQPointF * PP,
			                           DemonstrataQPointF * MP2,
			                           bool * FLAG_SO,
			                           funkcio * F,
			                           QState * sourceState = 0
			            ) : QSignalTransition(sourceState), np(NP), pp(PP), mp2(MP2), flag_so(FLAG_SO), f(F){};
			NoKonsideriPointoTransiro( DemonstrataQPointF * NP,
									DemonstrataQPointF * PP,
			                           DemonstrataQPointF * MP2,
			                           bool * FLAG_SO,
			                           funkcio * F,
			                           QObject * sender,
			                           const char * signal,
			                           QState * sourceState = 0
			                          ) : QSignalTransition(sender, signal, sourceState),
			                              np(NP), pp(PP), mp2(MP2), flag_so(FLAG_SO), f(F){};
		protected:
    	bool eventTest(QEvent *e);
	};

	/*! Переход от s5 к s6.
	 * 
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s5s6Transiro: public QSignalTransition{
		private:
			QRadioButton * down_x1;
		public:
			s5s6Transiro( QRadioButton * down_x1_rb, QState * sourceState = 0
			            ) : QSignalTransition(sourceState), down_x1(down_x1_rb){};
			s5s6Transiro( QRadioButton * down_x1_rb,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : QSignalTransition(sender, signal, sourceState),
			                down_x1(down_x1_rb){};
		protected:
					//! Перход срабатывает, только если выбран шаг в - по Х1  
    	bool eventTest(QEvent *e);
	};

	/*! Переход от s10 к s11.
	 * 
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s10s11Transiro: public QSignalTransition{
		private:
			QRadioButton * down_x2;
		public:
			s10s11Transiro( QRadioButton * down_x2_rb, QState * sourceState = 0
			            ) : QSignalTransition(sourceState), down_x2(down_x2_rb){};
			s10s11Transiro( QRadioButton * down_x2_rb,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : QSignalTransition(sender, signal, sourceState),
			                down_x2(down_x2_rb){};
		protected:
    	bool eventTest(QEvent *e);
	};

	/*! Переход от s13 к s14.
	 * 
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s13s14Transiro: public QSignalTransition{
		private:
			DemonstrataQPointF * mp;
			DemonstrataQPointF * mp2;
			DemonstrataQPointF * px1;
			DemonstrataQPointF * px2;
			qreal s;//!< Точность.
		public:
			s13s14Transiro( DemonstrataQPointF * MP,
			                DemonstrataQPointF * MP2,
			                DemonstrataQPointF * pX1,
			                DemonstrataQPointF * pX2,
			                qreal strikteco,
			                QState * sourceState = 0)
				: QSignalTransition(sourceState), mp(MP),mp2(MP2), px1(pX1), px2(pX2),
					s(strikteco){};
			s13s14Transiro( DemonstrataQPointF * MP,
			                DemonstrataQPointF * MP2,
			                DemonstrataQPointF * pX1,
			                DemonstrataQPointF * pX2,
			                qreal strikteco,
			                QObject * sender,
			                const char * signal,
			                QState * sourceState = 0
			              )
				: QSignalTransition(sender, signal, sourceState), mp(MP),mp2(MP2),
					px1(pX1), px2(pX2), s(strikteco){};
		protected:
			//! Перход срабатывает, только если выбран шаг в + по Х1 
    	bool eventTest(QEvent *e);
	};

	/*! Переход от s13 к s16 .
	 * 
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s13s16Transiro: public QSignalTransition{
		private:
			QRadioButton * ok_rb_;
			DemonstrataQPointF * pp;
			DemonstrataQPointF * mp2;
			bool * flag_so;
			funkcio * f;
		public:
			s13s16Transiro(QRadioButton * ok_rb, 
			               DemonstrataQPointF * PP,
			               DemonstrataQPointF * MP2,
			              bool*FLAG_SO,
			              funkcio * F,
			               QState * sourceState = 0)
				: QSignalTransition(sourceState),ok_rb_(ok_rb), pp(PP),mp2(MP2),flag_so(FLAG_SO),f(F){};
			s13s16Transiro( QRadioButton * ok_rb,
			               DemonstrataQPointF * PP,
			               DemonstrataQPointF * MP2,
			              bool*FLAG_SO,
			              funkcio * F,
			               QObject * sender,
			               const char * signal,
			               QState * sourceState = 0
			             )
				: QSignalTransition(sender, signal, sourceState),ok_rb_(ok_rb), pp(PP),
					mp2(MP2),flag_so(FLAG_SO),f(F){};
		protected:
    	bool eventTest(QEvent *e);
	};	

	/*! Переход от s13 к sf.
	 * 
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s13sfTransiro: public QSignalTransition{
		private:
			QPointF * px1;
			QPointF * px2;
			qreal s;//!< Точность.
		public:
			s13sfTransiro( QPointF * pX1,
			               QPointF * pX2,
			               qreal strikteco,
			               QState * sourceState = 0
			             ) : QSignalTransition(sourceState), px1(pX1),
				px2(pX2), s(strikteco){};
			s13sfTransiro( QPointF * pX1,
			               QPointF * pX2,
			               qreal strikteco,
			               QObject * sender,
			               const char * signal,
			               QState * sourceState = 0
			             )
				: QSignalTransition(sender, signal, sourceState), px1(pX1), px2(pX2),
					s(strikteco){};
		protected:
    	bool eventTest(QEvent *e);
	};

	/*! Переход от s13 к s19 .
	 * 
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s13s19Transiro: public QSignalTransition{
		private:
			QRadioButton * no_rb_;
			DemonstrataQPointF * pp;
			DemonstrataQPointF * mp2;
			bool * flag_so;
			funkcio * f;
		public:
			s13s19Transiro(QRadioButton * no_rb,
			               DemonstrataQPointF * PP,
			               DemonstrataQPointF * MP2,
			              bool * FLAG_SO,
			              funkcio * F,
			               QState * sourceState = 0)
				: QSignalTransition(sourceState),no_rb_(no_rb), pp(PP),mp2(MP2),flag_so(FLAG_SO),f(F){};
			s13s19Transiro(QRadioButton * no_rb,
			               DemonstrataQPointF * PP,
			               DemonstrataQPointF * MP2,
			              bool * FLAG_SO,
			              funkcio * F,
			               QObject * sender,
			               const char * signal,
			               QState * sourceState = 0
			             )
				: QSignalTransition(sender, signal, sourceState),no_rb_(no_rb), pp(PP),
					mp2(MP2),flag_so(FLAG_SO),f(F){};
		protected:
    	bool eventTest(QEvent *e);
	};	

	/*! Переход от s15 к s18 .
	 * 
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s15s18_s17s18Transiro: public QSignalTransition{
		private:
			QRadioButton * model;
		public:
			s15s18_s17s18Transiro( QRadioButton * model_rb, QState * sourceState = 0
			            ) : QSignalTransition(sourceState), model(model_rb){};
			s15s18_s17s18Transiro( QRadioButton * model_rb,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : QSignalTransition(sender, signal, sourceState),
			                model(model_rb){};
		protected:
    	bool eventTest(QEvent *e);
	};
};
#endif





