#ifndef HUGIIMPL_H
#define HUGIIMPL_H
//
#include "algoritmowin.h"
#include "ui_HuGi.h"
#include "demonstrataqpointf.h"
#include <QSignalTransition>
//
//! Окно для прохождения метода Хука-Дживса.
class HuGiImpl : public AlgoritmoWin, public Ui::HuGi{
Q_OBJECT
private:
	//! Точка В1.
	DemonstrataQPointF B1;

	//! Точка В2.
	DemonstrataQPointF B2;

	//! Точка P.
	DemonstrataQPointF P;

	//! Новая точка.
	DemonstrataQPointF NP;

	//! Флаг наличия образца. Использую, чтобы избежать "взрыва состояний".
	bool FLG;

	//! Указатель на искомую точку. Использую, чтобы избежать "взрыва состояний".
	DemonstrataQPointF *IP;

	//! Шаг по х1.
	/*! Для удобства задаю в виде точки (длина, 0).
	 */
	DemonstrataQPointF PX1;

	//! Шаг по х2.
	/*! Для удобства задаю в виде точки (0, длина).
	 */
	DemonstrataQPointF PX2;

	//! Модификатор шага.
	static const qreal ModPX = 0.1;
public:
	/*! Конструктор.
	 * @param f Указатель на целевую функцию. HuGiImpl не заботится о назначении Funkcio родителя.
	 * @param d Массив с данными задания.Структура: 0 - точность; 1 - шаг по оси х1; 2 - шаг по оси х2; 3 - коэффициент изменения шага; 4 - х1; 5 - х2; 6 - максимальное количество ошибок.
	 * @param parent Родитель.
	 * @param flags Флаги параметров окна.
	 */
	HuGiImpl( funkcio *f, QVector<double> d, QWidget * parent = 0,
	          Qt::WFlags flags = 0 );
private slots:
	void on_about_action_activated();
	void on_helpo_action_activated();
	void on_difiniFonto_act_activated();
	
	void registriEraro();
	
	void sf_entered();
	/*! "Обнуление" переменных.
	 *
	 * Этим методом задаются начальные значения всем переменным алгоритма.
	 * Используется перед запуском конечного автомата и в переходе вызванном
	 * действием "Начать заново".
	 */
	void init();
	/*! Обработчик входа в состояние so.
	 *
	 * Использую для дебага.
	 */
	void so_entered();
	/*! Обработчик входа в состояние s1.
	 *
	 */
	void s1_entered();
	/*! Обработчик входа в состояние s3.
	 *
	 */
	void s3_entered();
	/*! Обработчик входа в состояние s4.
	 *
	 */
	void s4_entered();
	/*! Обработчик входа в состояние s5.
	 *
	 */
	void s5_entered();
	/*! Обработчик входа в состояние s7.
	 *
	 */
	void s7_entered();
	/*! Обработчик входа в состояние s8.
	 *
	 */
	void s8_entered();
	/*! Обработчик входа в состояние s10.
	 *
	 */
	void s10_entered();
	/*! Обработчик входа в состояние s12.
	 *
	 */
	void s12_entered();
	/*! Обработчик входа в состояние s13.
	 *
	 */
	void s13_entered();
	/*! Обработчик входа в состояние s15.
	 *
	 */
	void s15_entered();
	/*! Обработчик входа в состояние s16.
	 *
	 */
	void s16_entered();
	/*! Обработчик входа в состояние s17.
	 *
	 */
	void s17_entered();
	/*! Обработчик входа в состояние s18.
	 *
	 */
	void s18_entered();
};
#endif

/*! В этом пространстве имён содержаться классы относящиеся к конечному автомату
 * для метода Хука-Дживса.
 *
 * Объявления наследников QSignalTransition можно не смотреть. Важна только
 * реализация метода eventTest, ради которой и переопределяю классы.
 */
namespace HuGi{
	/*! Переход принятия новой точки на место искомой.
	 *
	 * Переход срабатывает, только если новая точка < текущего значения искомой.
	 * Используется при переходе от s5 к s8, s7 к s8, s10 к s13, s12 к s13.
	 */
	class KonsideriPointoTransiro: public QSignalTransition{
		private:
			DemonstrataQPointF ** ip;
			DemonstrataQPointF * np;
			funkcio * f;
		public:
			KonsideriPointoTransiro( DemonstrataQPointF ** IP,
			                         DemonstrataQPointF * NP,
			                         funkcio * F,
			                         QState * sourceState = 0
			                       ) : QSignalTransition(sourceState), ip(IP), np(NP),
			                           f(F){};
			KonsideriPointoTransiro( DemonstrataQPointF ** IP,
			                         DemonstrataQPointF * NP,
			                         funkcio * F,
			                         QObject * sender,
			                         const char * signal,
			                         QState * sourceState = 0
			                       )
			                        : QSignalTransition(sender, signal, sourceState),
			                          ip(IP), np(NP), f(F){};
		protected:
			//! Переход срабатывает, только если новая точка < текущего значения искомой.
			bool eventTest(QEvent *e);
	};

	/*! Переход непринятия новой точки на место искомой.
	 *
	 * Переход срабатывает, только если новая точка >= текущего значения искомой.
	 * Используется при переходе от s5 к s6, s7 к s9, s10 к s11.
	 */
	class NoKonsideriPointoTransiro: public QSignalTransition{
		private:
			DemonstrataQPointF ** ip;
			DemonstrataQPointF * np;
			funkcio * f;
		public:
			NoKonsideriPointoTransiro( DemonstrataQPointF ** IP,
			                           DemonstrataQPointF * NP,
			                           funkcio * F,
			                           QState * sourceState = 0
			                         ) : QSignalTransition(sourceState), ip(IP),
			                             np(NP), f(F){};
			NoKonsideriPointoTransiro( DemonstrataQPointF ** IP,
			                           DemonstrataQPointF * NP,
			                           funkcio * F,
			                           QObject * sender,
			                           const char * signal,
			                           QState * sourceState = 0
			                         ) : QSignalTransition(sender, signal, sourceState),
			                              ip(IP), np(NP), f(F){};
		protected:
		//! Переход срабатывает, только если новая точка >= текущего значения искомой
		bool eventTest(QEvent *e);
	};

	/*! Переход от s2 к s3.
	 *
	 * Переход срабатывает, только если не имеется образец и выбран исследующий
	 * поиск.
	 */
	class s2s3Transiro: public QSignalTransition{
		private:
			bool * flag;
			QRadioButton * rb;
		public:
			s2s3Transiro( bool * FLG,
			              QRadioButton * investigate_rb,
			              QState * sourceState = 0)
				: QSignalTransition(sourceState), flag(FLG), rb(investigate_rb){};
			s2s3Transiro( bool * FLG,
			              QRadioButton * investigate_rb,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            )
				: QSignalTransition(sender, signal, sourceState), flag(FLG),
					rb(investigate_rb){};
		protected:
			/*! Переход срабатывает, только если не имеется образец и выбран исследующий
			 * поиск.
			 */
			bool eventTest(QEvent *e);
	};

	/*! Переход от s2 к s4.
	 *
	 * Переход срабатывает, только если имеется образец и выбран поиск по образцу.
	 */
	class s2s4Transiro: public QSignalTransition{
		private:
			bool * flag;
			QRadioButton * rb;
		public:
			s2s4Transiro( bool * FLG,
			              QRadioButton * model_rb,
			              QState * sourceState = 0)
				: QSignalTransition(sourceState), flag(FLG), rb(model_rb){};
			s2s4Transiro( bool * FLG,
			              QRadioButton * model_rb,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			              )
				: QSignalTransition(sender, signal, sourceState), flag(FLG),
					rb(model_rb){};
		protected:
			//! Переход срабатывает, только если имеется образец и выбран поиск по образцу..
			bool eventTest(QEvent *e);
	};

	/*! Переход от s3 к s5 и от s4 к s5.
	 *
	 * Переход срабатывает, только если выбран шаг в + по Х1.
	 */
	class s3s5s4s5Transiro: public QSignalTransition{
		private:
			QRadioButton * rb;
		public:
			s3s5s4s5Transiro( QRadioButton * up_x1_rb,
			                  QState * sourceState = 0)
				: QSignalTransition(sourceState), rb(up_x1_rb){};
			s3s5s4s5Transiro( QRadioButton * up_x1_rb,
			                  QObject * sender,
			                  const char * signal,
			                  QState * sourceState = 0
			                )
				: QSignalTransition(sender, signal, sourceState), rb(up_x1_rb){};
		protected:
			//! Переход срабатывает, только если выбран шаг в + по Х1.
			bool eventTest(QEvent *e);
	};

	/*! Переход от s6 к s7.
	 *
	 * Переход срабатывает, только если выбран шаг в - по Х1.
	 */
	class s6s7Transiro: public QSignalTransition{
		private:
			QRadioButton * rb;
		public:
			s6s7Transiro( QRadioButton * doun_x1_rb,
										QState * sourceState = 0)
				: QSignalTransition(sourceState), rb(doun_x1_rb){};
			s6s7Transiro( QRadioButton * doun_x1_rb,
									  QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			              )
				: QSignalTransition(sender, signal, sourceState), rb(doun_x1_rb){};
		protected:
			//! Переход срабатывает, только если выбран шаг в - по Х1.
			bool eventTest(QEvent *e);
	};

	/*! Переход от s8 к s10 и от s9 к s10.
	 *
	 * Переход срабатывает, только если выбран шаг в + по Х2.
	 */
	class s8s10s9s10Transiro: public QSignalTransition{
		private:
			QRadioButton * rb;
		public:
			s8s10s9s10Transiro( QRadioButton * up_x2_rb,
			                  QState * sourceState = 0)
				: QSignalTransition(sourceState), rb(up_x2_rb){};
			s8s10s9s10Transiro( QRadioButton * up_x2_rb,
			                  QObject * sender,
			                  const char * signal,
			                  QState * sourceState = 0
			                )
				: QSignalTransition(sender, signal, sourceState), rb(up_x2_rb){};
		protected:
			//! Переход срабатывает, только если выбран шаг в + по Х2.
			bool eventTest(QEvent *e);
	};

	/*! Переход от s11 к s12.
	 *
	 * Переход срабатывает, только если выбран шаг в - по Х2.
	 */
	class s11s12Transiro: public QSignalTransition{
		private:
			QRadioButton * rb;
		public:
			s11s12Transiro( QRadioButton * doun_x2_rb,
										QState * sourceState = 0)
				: QSignalTransition(sourceState), rb(doun_x2_rb){};
			s11s12Transiro( QRadioButton * doun_x2_rb,
									  QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			              )
				: QSignalTransition(sender, signal, sourceState), rb(doun_x2_rb){};
		protected:
			//! Переход срабатывает, только если выбран шаг в - по Х1.
			bool eventTest(QEvent *e);
	};

	/*! Переход от s12 к s14.
	 *
	 * Переход срабатывает, только если не имеется образца и новая точка >=
	 * текущего значения искомой.
	 */
	class s12s14Transiro: public QSignalTransition{
		private:
			bool * flag;
			DemonstrataQPointF ** ip;
			DemonstrataQPointF * np;
			funkcio * f;
		public:
			s12s14Transiro( bool * FLG,
			                DemonstrataQPointF ** IP,
			                DemonstrataQPointF * NP,
			                funkcio * F,
			                QState * sourceState = 0)
				: QSignalTransition(sourceState), flag(FLG), ip(IP), np(NP), f(F){};
			s12s14Transiro( bool * FLG,
			                DemonstrataQPointF ** IP,
			                DemonstrataQPointF * NP,
			                funkcio * F,
			                QObject * sender,
			                const char * signal,
			                QState * sourceState = 0
			              )
				: QSignalTransition(sender, signal, sourceState), flag(FLG), ip(IP),
					np(NP), f(F){};
		protected:
			/*! Переход срабатывает, только если если не имеется образца , на новую точку и
			 * на искомую.
			 */
			bool eventTest(QEvent *e);
	};

	/*! Переход от s12 к s17.
	 *
	 * Переход срабатывает, только если имеется образец и новая точка >=
	 * текущего значения искомой.
	 */
	class s12s17Transiro: public QSignalTransition{
		private:
			bool * flag;
			DemonstrataQPointF ** ip;
			DemonstrataQPointF * np;
			funkcio * f;
		public:
			s12s17Transiro( bool * FLG,
			                DemonstrataQPointF ** IP,
			                DemonstrataQPointF * NP,
			                funkcio * F,
			                QState * sourceState = 0)
				: QSignalTransition(sourceState), flag(FLG), ip(IP), np(NP), f(F){};
			s12s17Transiro( bool * FLG,
			                DemonstrataQPointF ** IP,
			                DemonstrataQPointF * NP,
			                funkcio * F,
			                QObject * sender,
			                const char * signal,
			                QState * sourceState = 0
			              )
				: QSignalTransition(sender, signal, sourceState), flag(FLG), ip(IP),
					np(NP), f(F){};
		protected:
			/*! Переход срабатывает, только если имеется образец и новая точка >=
			 * текущего значения искомой.
			 */
			bool eventTest(QEvent *e);
	};

	/*! Переход от s13 к s14.
	 *
	 * Переход срабатывает, только если не имеется образца.
	 */
	class s13s14Transiro: public QSignalTransition{
		private:
			bool * flag;
		public:
			s13s14Transiro( bool * FLG,
			                QState * sourceState = 0)
				: QSignalTransition(sourceState), flag(FLG){};
			s13s14Transiro( bool * FLG,
			                QObject * sender,
			                const char * signal,
			                QState * sourceState = 0
			              )
				: QSignalTransition(sender, signal, sourceState), flag(FLG){};
		protected:
			//! Переход срабатывает, только если не имеется образца.
			bool eventTest(QEvent *e);
	};

	/*! Переход от s13 к s17.
	 *
	 * Переход срабатывает, только если имеется образец.
	 */
	class s13s17Transiro: public QSignalTransition{
		private:
			bool * flag;
		public:
			s13s17Transiro( bool * FLG,
			                QState * sourceState = 0)
				: QSignalTransition(sourceState), flag(FLG){};
			s13s17Transiro( bool * FLG,
			                QObject * sender,
			                const char * signal,
			                QState * sourceState = 0
			              )
				: QSignalTransition(sender, signal, sourceState), flag(FLG){};
		protected:
			//! Переход срабатывает, только если имеется образец.
			bool eventTest(QEvent *e);
	};
	/*! Переход от s14 к s15.
	 *
	 * Переход срабатывает, только если не была принята новая точка и шаги больше
	 * или равны погрешности.
	 */
	class s14s15Transiro: public QSignalTransition{
		private:
			DemonstrataQPointF ** ip;
			DemonstrataQPointF * np;
			DemonstrataQPointF * px1;
			DemonstrataQPointF * px2;
			qreal s;
		public:
			s14s15Transiro( DemonstrataQPointF ** IP,
			                DemonstrataQPointF * NP,
			                DemonstrataQPointF * pX1,
			                DemonstrataQPointF * pX2,
			                qreal strikteco,
			                QState * sourceState = 0)
				: QSignalTransition(sourceState), ip(IP), np(NP), px1(pX1), px2(pX2),
					s(strikteco){};
			s14s15Transiro( DemonstrataQPointF ** IP,
			                DemonstrataQPointF * NP,
			                DemonstrataQPointF * pX1,
			                DemonstrataQPointF * pX2,
			                qreal strikteco,
			                QObject * sender,
			                const char * signal,
			                QState * sourceState = 0
			              )
				: QSignalTransition(sender, signal, sourceState), ip(IP), np(NP),
					px1(pX1), px2(pX2), s(strikteco){};
		protected:
			/*! Переход срабатывает, только если не была принята новая точка и шаги больше
			 * или равны погрешности.
			 */
			bool eventTest(QEvent *e);
	};
	/*! Переход от s14 к s16.
	 *
	 * Переход срабатывает, только если была принята новая точка и шаги больше
	 * или равны погрешности.
	 */
	class s14s16Transiro: public QSignalTransition{
		private:
			DemonstrataQPointF ** ip;
			DemonstrataQPointF * np;
			DemonstrataQPointF * px1;
			DemonstrataQPointF * px2;
			qreal s;
		public:
			s14s16Transiro( DemonstrataQPointF ** IP,
			                DemonstrataQPointF * NP,
			                DemonstrataQPointF * pX1,
			                DemonstrataQPointF * pX2,
			                qreal strikteco,
			                QState * sourceState = 0)
				: QSignalTransition(sourceState), ip(IP), np(NP), px1(pX1), px2(pX2),
					s(strikteco){};
			s14s16Transiro( DemonstrataQPointF ** IP,
			                DemonstrataQPointF * NP,
			                DemonstrataQPointF * pX1,
			                DemonstrataQPointF * pX2,
			                qreal strikteco,
			                QObject * sender,
			                const char * signal,
			                QState * sourceState = 0
			              )
				: QSignalTransition(sender, signal, sourceState), ip(IP), np(NP),
					px1(pX1), px2(pX2), s(strikteco){};
		protected:
			/*! Переход срабатывает, только если была принята новая точка и шаги больше
			 * или равны погрешности.
			 */
			bool eventTest(QEvent *e);
	};
	/*! Переход от s14 к sf.
	 *
	 * Переход срабатывает, только если шаги меньше погрешности.
	 */
	class s14sfTransiro: public QSignalTransition{
		private:
			DemonstrataQPointF * px1;
			DemonstrataQPointF * px2;
			qreal s;
		public:
			s14sfTransiro( DemonstrataQPointF * pX1,
			               DemonstrataQPointF * pX2,
			               qreal strikteco,
			               QState * sourceState = 0)
				: QSignalTransition(sourceState), px1(pX1), px2(pX2), s(strikteco){};
			s14sfTransiro( DemonstrataQPointF * pX1,
			               DemonstrataQPointF * pX2,
			               qreal strikteco,
			               QObject * sender,
			               const char * signal,
			               QState * sourceState = 0
			             )
				: QSignalTransition(sender, signal, sourceState), px1(pX1), px2(pX2),
					s(strikteco){};
		protected:
			//! Переход срабатывает, только если шаги меньше погрешности.
			bool eventTest(QEvent *e);
	};
	/*! Переход от s17 к s18.
	 *
	 * Переход срабатывает, только если искомая точка меньше В2.
	 */
	class s17s18Transiro: public QSignalTransition{
		private:
			DemonstrataQPointF ** ip;
			DemonstrataQPointF * b2;
		public:
			s17s18Transiro( DemonstrataQPointF ** IP,
			                DemonstrataQPointF * B2,
			                QState * sourceState = 0)
				: QSignalTransition(sourceState), ip(IP), b2(B2){};
			s17s18Transiro( DemonstrataQPointF ** IP,
			                DemonstrataQPointF * B2,
			                QObject * sender,
			                const char * signal,
			                QState * sourceState = 0
			              )
				: QSignalTransition(sender, signal, sourceState), ip(IP), b2(B2){};
		protected:
			//! Переход срабатывает, только если искомая точка меньше В2.
			bool eventTest(QEvent *e);
	};
	/*! Переход от s17 к s1.
	 *
	 * Переход срабатывает, только если искомая точка больше или равна В2.
	 */
	class s17s1Transiro: public QSignalTransition{
		private:
			DemonstrataQPointF ** ip;
			DemonstrataQPointF * b2;
		public:
			s17s1Transiro( DemonstrataQPointF ** IP,
			               DemonstrataQPointF * B2,
			               QState * sourceState = 0)
				: QSignalTransition(sourceState), ip(IP), b2(B2){};
			s17s1Transiro( DemonstrataQPointF ** IP,
			               DemonstrataQPointF * B2,
			               QObject * sender,
			               const char * signal,
			               QState * sourceState = 0
			              )
				: QSignalTransition(sender, signal, sourceState), ip(IP), b2(B2){};
		protected:
			//! Переход срабатывает, только если точка больше или равна В2.
			bool eventTest(QEvent *e);
	};
};

/*! @class HuGiImpl
 *
 * @author Александр Белоконь, Василий Почкаенко.
 */