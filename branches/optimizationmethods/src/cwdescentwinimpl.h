#ifndef CWDESCENTWINIMPL_H
#define CWDESCENTWINIMPL_H
//
#include "algoritmowin.h"
#include "ui_CWdescent_fixwindow.h"
#include "demonstrataqpointf.h"
#include <QSignalTransition>
#include <QState>
#include <QRadioButton>
//
class funkcio;
//
//! Окно для прохождения Покоординатного спуска с фиксированным шагом.
class CWdescentWinImpl : public AlgoritmoWin, public Ui::CWdescentWin{
Q_OBJECT
protected:
  //! Точность.
  qreal strikteco;
  //! Количество ошибок.
  int KvantoEraroj;
  //! Номер итерации.
  int NumeroIteracio;
  //! Базовая точка итерации.
  DemonstrataQPointF BP;
  //! Текущая базовая точка.
  DemonstrataQPointF MP;
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
  //! Модификатор шага.
  qreal ModPX;
  /*! Флаг для проверки, была ли принята новая точка.
	 * 
	 * Отступаю от классического конечного автомата, что бы избежать взрыва 
	 * состояний.
	 */
	 bool acpNP;
public:
  //! Возвращает шаг по х1.
//  DemonstrataQPointF & pX1(){ return PX1; };
  //! Возвращает шаг по х1.
//  DemonstrataQPointF & pX2(){ return PX2; }; 
  //! Возвращает точность.
//  qreal & Strikteco(){ return strikteco; };
	//! Возвращает указатель на целевую функцию.
//  funkcio * f(){ return F; }; 
  //! Возвращает базовую точка итерации.
//  DemonstrataQPointF & bp(){ return BP; };
  //! Возвращает текущую базовая точка.
//  DemonstrataQPointF & mp(){ return MP; };
  //! Возвращает новую точка.
//  DemonstrataQPointF & np(){ return NP; };
	CWdescentWinImpl( funkcio *f, //!< Указатель на целевую функцию. CWdescentWinImpl не заботится о назначении Funkcio родителя.
                    QVector<double> *d, //!< Массив с данными задания.
                    QWidget * parent = 0, //!< Родитель.
                    Qt::WFlags flags = 0 //!< Флаги параметров окна.
                  );
private slots:
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
	 * В этом состоянии задаются начальные для итерации значения переменых.
	 */
	void s1_entered();
	/*! Обработчик входа в состояние s2.
	 * 
	 * В этом состоянии проверяется точка смещённая от текщей в + по Х1.
	 */
	void s2_entered();
	/*! Обработчик входа в состояние s3.
	 * 
	 * Исполизую для дебага.
	 */
	void s3_entered();
	/*! Обработчик входа в состояние s4.
	 * 
	 * В этом состоянии проверяется точка смещённая от текщей в - по Х1.
	 */
	void s4_entered();
	/*! Обработчик входа в состояние s5.
	 * 
	 * В этом состоянии текущей точке присваевается значение новой.После поиска
	 * по Х1.
	 */
	void s5_entered();
	/*! Обработчик входа в состояние s6.
	 * 
	 * Исполизую для дебага.
	 */
	void s6_entered();
	/*! Обработчик входа в состояние s7.
	 * 
	 * В этом состоянии проверяется точка смещённая от текщей в + по Х2.
	 */
	void s7_entered();
	/*! Обработчик входа в состояние s8.
	 * 
	 * Исполизую для дебага.
	 */
	void s8_entered();
	/*! Обработчик входа в состояние s9.
	 * 
	 * В этом состоянии проверяется точка смещённая от текщей в - по Х2.
	 */
	void s9_entered();
	/*! Обработчик входа в состояние s10.
	 * 
	 * В этом состоянии текущей точке присваевается значение новой. После поиска
	 * по всем осям.
	 */
	void s10_entered();
	/*! Обработчик входа в состояние s11.
	 * 
	 * Исполизую для дебага.
	 */
	void s11_entered();
	/*! Обработчик входа в состояние s12.
	 * 
	 * В этом состоянии изменяются длины шагов.
	 */
	void s12_entered();
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
 */ 
namespace SinkoLauxKoordinatoj{
	/*! Переход принятия новой точки в качестве текщей.
	 * 
	 * Используется при переходе от s2 к s5, s4 к s5, s7 к s10, s9 к s10.
	 */
	class KonsideriPointoTransiro: public QSignalTransition{
		private:
			DemonstrataQPointF * mp;
			DemonstrataQPointF * np;
			funkcio * f;
		public:
			KonsideriPointoTransiro( DemonstrataQPointF * MP,
			                         DemonstrataQPointF * NP,
			                         funkcio * F,
			                         QState * sourceState = 0
			            ) : QSignalTransition(sourceState), mp(MP), np(NP), f(F){};
			KonsideriPointoTransiro( DemonstrataQPointF * MP,
			                         DemonstrataQPointF * NP,
			                         funkcio * F,
			                         QObject * sender,
			                         const char * signal,
			                         QState * sourceState = 0
			                       )
			                        : QSignalTransition(sender, signal, sourceState),
			                          mp(MP), np(NP), f(F){};
		protected:
    	bool eventTest(QEvent *e);
	};
	/*! Переход непринятия новой точки в качестве текуей.
	 * 
	 * Используется при переходе от s2 к s3, s4 к s6, s7 к s8, s7 к s11.
	 */
	class NoKonsideriPointoTransiro: public QSignalTransition{
		private:
			DemonstrataQPointF * mp;
			DemonstrataQPointF * np;
			funkcio * f;
		public:
			NoKonsideriPointoTransiro( DemonstrataQPointF * MP,
			                           DemonstrataQPointF * NP,
			                           funkcio * F,
			                           QState * sourceState = 0
			            ) : QSignalTransition(sourceState), mp(MP), np(NP), f(F){};
			NoKonsideriPointoTransiro( DemonstrataQPointF * MP,
			                           DemonstrataQPointF * NP,
			                           funkcio * F,
			                           QObject * sender,
			                           const char * signal,
			                           QState * sourceState = 0
			                          ) : QSignalTransition(sender, signal, sourceState),
			                              mp(MP), np(NP), f(F){};
		protected:
    	bool eventTest(QEvent *e);
	};
	//! Переход от s11 к s12.
	class s11s12Transiro: public QSignalTransition{
		private:
			bool * acpnp;
		public:
			s11s12Transiro( bool * acpNP, QState * sourceState = 0)
				: QSignalTransition(sourceState), acpnp(acpNP){};
			s11s12Transiro( bool * acpNP,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            )
				: QSignalTransition(sender, signal, sourceState), acpnp(acpNP){};
		protected:
			//! Перход срабатывает, только если выбран шаг в + по Х1 
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s1 к s2.
	class s1s2Transiro: public QSignalTransition{
		private:
			QRadioButton * up_x1;
		public:
			s1s2Transiro( QRadioButton * up_x1_rb, QState * sourceState = 0)
				: QSignalTransition(sourceState), up_x1(up_x1_rb){};
			s1s2Transiro( QRadioButton * up_x1_rb,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            )
				: QSignalTransition(sender, signal, sourceState), up_x1(up_x1_rb){};
		protected:
			//! Перход срабатывает, только если выбран шаг в + по Х1 
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s3 к s4.
	class s3s4Transiro: public QSignalTransition{
		private:
			QRadioButton * down_x1;
		public:
			s3s4Transiro( QRadioButton * down_x1_rb, QState * sourceState = 0
			            ) : QSignalTransition(sourceState), down_x1(down_x1_rb){};
			s3s4Transiro( QRadioButton * down_x1_rb,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : QSignalTransition(sender, signal, sourceState),
			                down_x1(down_x1_rb){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s5 к s7.
	class s5s7_s6s7Transiro: public QSignalTransition{
		private:
			QRadioButton * up_x2;
		public:
			s5s7_s6s7Transiro( QRadioButton * up_x2_rb, QState * sourceState = 0
			                 ) : QSignalTransition(sourceState), up_x2(up_x2_rb){};
			s5s7_s6s7Transiro( QRadioButton * up_x2_rb,
			                   QObject * sender,
			                   const char * signal,
			                   QState * sourceState = 0
			                 ) : QSignalTransition(sender, signal, sourceState),
			                     up_x2(up_x2_rb){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s8 к s9.
	class s8s9Transiro: public QSignalTransition{
		private:
			QRadioButton * down_x2;
		public:
			s8s9Transiro( QRadioButton * down_x2_rb, QState * sourceState = 0
			            ) : QSignalTransition(sourceState), down_x2(down_x2_rb){};
			s8s9Transiro( QRadioButton * down_x2_rb,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : QSignalTransition(sender, signal, sourceState),
			                down_x2(down_x2_rb){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s10 к sf.
	class s11sfTransiro: public QSignalTransition{
		private:
			DemonstrataQPointF * bp;
			DemonstrataQPointF * mp;
			qreal s;//!< Точность.
			bool * acpnp;
		public:
			s11sfTransiro( bool * acpNP,
			               DemonstrataQPointF * BP,
			               DemonstrataQPointF * MP,
			               qreal strikteco,
			               QState * sourceState = 0
			             ) : QSignalTransition(sourceState), bp(BP), mp(MP),
			                 s(strikteco), acpnp(acpNP){};
			s11sfTransiro( bool * acpNP,
			               DemonstrataQPointF * BP,
			               DemonstrataQPointF * MP,
			               qreal strikteco,
			               QObject * sender,
			               const char * signal,
			               QState * sourceState = 0
			             ) : QSignalTransition(sender, signal, sourceState),
			                 bp(BP), mp(MP), s(strikteco), acpnp(acpNP){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s10 к s1.
	class s11s1Transiro: public QSignalTransition{
		private:
			DemonstrataQPointF * bp;
			DemonstrataQPointF * mp;
			qreal s;//!< Точность.
		public:
			s11s1Transiro( DemonstrataQPointF * BP,
			               DemonstrataQPointF * MP,
			               qreal strikteco,
			               QState * sourceState = 0
			             ) : QSignalTransition(sourceState), bp(BP), mp(MP),
			                 s(strikteco){};
			s11s1Transiro( DemonstrataQPointF * BP,
			               DemonstrataQPointF * MP,
			               qreal strikteco,
			               QObject * sender,
			               const char * signal,
			               QState * sourceState = 0
			             ) : QSignalTransition(sender, signal, sourceState),
			                 bp(BP), mp(MP), s(strikteco){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s12 к sf.
	class s12sfTransiro: public QSignalTransition{
		private:
		  DemonstrataQPointF * pX1; //!< Шаг по х1.
		  DemonstrataQPointF * pX2; //!< Шаг по х2.
		  qreal s;//!< Точность.
		public:
			s12sfTransiro( DemonstrataQPointF * PX1,
			               DemonstrataQPointF * PX2,
			               qreal strikteco,
			               QState * sourceState = 0
			             ) : QSignalTransition(sourceState), pX1(PX1), pX2(PX2),
			                 s(strikteco){};
			s12sfTransiro( DemonstrataQPointF * PX1,
			               DemonstrataQPointF * PX2,
			               qreal strikteco,
			               QObject * sender,
			               const char * signal,
			               QState * sourceState = 0
			             ) : QSignalTransition(sender, signal, sourceState), pX1(PX1),
			                 pX2(PX2), s(strikteco){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s12 к s1.
	class s12s1Transiro: public QSignalTransition{
		private:
		  DemonstrataQPointF * pX1; //!< Шаг по х1.
		  DemonstrataQPointF * pX2; //!< Шаг по х2.
		  qreal s;//!< Точность.
		public:
			s12s1Transiro( DemonstrataQPointF * PX1,
			               DemonstrataQPointF * PX2,
			               qreal strikteco,
			               QState * sourceState = 0
			             ) : QSignalTransition(sourceState), pX1(PX1), pX2(PX2),
			                 s(strikteco){};
			s12s1Transiro( DemonstrataQPointF * PX1,
			               DemonstrataQPointF * PX2,
			               qreal strikteco,
			               QObject * sender,
			               const char * signal,
			               QState * sourceState = 0
			             ) : QSignalTransition(sender, signal, sourceState), pX1(PX1),
			                 pX2(PX2), s(strikteco){};
		protected:
    	bool eventTest(QEvent *e);
	};	
};
#endif

/*! @class CWdescentWinImpl
 * Алгоритм:
 *
 * @image html "CWdescentFix.png" "Блок-схема"
 * 
 * Операции алгоритма повторяются циклически, пока не значение не приблизится к минимуму на заданную точность.
 * Каждая итерация содержит следующие шаги:
 *
 * 1) Изменяем x1 в положительную сторону на значение h1.
 *
 * 2) Если значение F(x1 + h1, x2) < F(x1, x2), то необходимо принять новую точку и проверить условие выхода, иначе не принимаем её.
 *
 * 3) Если не приняли, то изменяем x1 в отрицательную сторону на значение h1.
 *
 * 4) Если значение F(x1 - h1, x2) < F(x1, x2), то необходимо принять новую точку и проверить условие выхода, иначе не принимаем её.
 *
 * 5) Изменяем x2 в положительную сторону на значение h2.
 *
 * 6) Если значение F(x1, x2 + h2) < F(x1, x2), то необходимо принять новую точку и проверить условие выхода, иначе не принимаем её.
 *
 * 7) Если не приняли, то изменяем x2 в отрицательную сторону на значение h2.
 *
 * 8) Если значение F(x1, x2 - h2) < F(x1, x2), то необходимо принять новую точку и проверить условие выхода, иначе не принимаем её.
 *
 * 9) Если не приняли ни одно новое значения для x1 и x2, то уменьшаем длину шага.
 *
 * 10) Проверяем условие завершения:
 * 
 *   Если расстояние от предыдущей базовой точки до текущей меньше требуемой точности, то завершаем поиск, иначе переходим к следующей итерации.
 * 
 * 11) Конец поиска
 *
 * Реализация:
 * 
 * Работа программы идёт не линейно - разные этапы итерации разнесены в разные подпрограммы.
 *
 * Имеется флаг состояния - FlagEtapo, хранящий номер этапа итерации. При каждом действии пользователя провепяется соответствие его действия проходимому этапу.
 *
 * 1 - нажата calculate_bt и выбрана up_x1_rb
 * 
 * 2 - нажата accept_bt или not_accept_bt
 * 
 * 3 - нажата calculate_bt и выбрана down_x1_rb
 * 
 * 4 - нажата accept_bt или not_accept_bt
 * 
 * 5 - нажата calculate_bt и выбрана up_x2_rb
 * 
 * 6 - нажата accept_bt или not_accept_bt
 * 
 * 7 - нажата calculate_bt и выбрана down_x2_rb
 * 
 * 8 - нажата accept_bt или not_accept_bt
 * 
 * 9 - нажата change_step_bt
 * 
 * 10 - Этот этап выполняется в accept_bt сразу после обработки этапов 2,4,6,8.
 * 
 * 11 - нажата end_bt
 *
 * При не соответствии выдаётся ошибка. При соответствии выполияется действие и переход на следующий этап согласно алгоритму.
 * 
 * @author Александр Белоконь, Василий Почкаенко.
 */