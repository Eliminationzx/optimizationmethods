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
  //! Указатель на целевую функцию.
  funkcio *F; 
public:
  //! Возвращает шаг по х1.
  DemonstrataQPointF & pX1(){ return PX1; };
  //! Возвращает шаг по х1.
  DemonstrataQPointF & pX2(){ return PX2; }; 
  //! Возвращает точность.
  qreal & Strikteco(){ return strikteco; };
	//! Возвращает указатель на целевую функцию.
  funkcio * f(){ return F; }; 
  //! Возвращает базовую точка итерации.
  DemonstrataQPointF & bp(){ return BP; };
  //! Возвращает текущую базовая точка.
  DemonstrataQPointF & mp(){ return MP; };
  //! Возвращает новую точка.
  DemonstrataQPointF & np(){ return NP; };
	CWdescentWinImpl( funkcio *f, //!< Указатель на целевую функцию. CWdescentWinImpl не заботится о назначении Funkcio родителя.
                    QVector<double> *d, //!< Массив с данными задания.
                    QWidget * parent = 0, //!< Родитель.
                    Qt::WFlags flags = 0 //!< Флаги парамметров окна.
                  );
private slots:
	/*! Обработчик входа в состояние s1.
	 * 
	 * В этом состоянии 
	 */
	void s1_entered();
	/*! Обработчик входа в состояние s2.
	 * 
	 * В этом состоянии проверяется точка смещённая от текщей в + по Х1.
	 */
	void s2_entered();
	/*! Обработчик входа в состояние s3.
	 * 
	 * В этом состоянии проверяется точка смещённая от текщей в - по Х1.
	 */
	void s4_entered();
	/*! Обработчик входа в состояния s5 и s10.
	 * 
	 * В этих состояниях текущей точке присваевается значение новой.
	 */
	void s5_s10_entered();
	/*! Обработчик входа в состояние s7.
	 * 
	 * В этом состоянии проверяется точка смещённая от текщей в + по Х2.
	 */
	void s7_entered();
	/*! Обработчик входа в состояние s9.
	 * 
	 * В этом состоянии проверяется точка смещённая от текщей в - по Х2.
	 */
	void s9_entered();
	/*! Обработчик входа в состояние s12.
	 * 
	 * В этом состоянии изменяются длины шагов.
	 */
	void s12_entered();
	//! Обработчик входа в состояние sf - конец поиска.
	void sf_entered();
  //! Фиксирует совершение пользователем ошики.
  void registriEraro();
};

/*! В этом пространстве имён содержаться классы относящиеся к конечному автомату
 * для покоординатного спуска с фиксированным шагом.
 */ 
namespace SinkoLauxKoordinatoj{
	/*! Базовый класс переходов внутри конечного автомата для покоординатного спуска.
	 * 
	 * Переходы различаются, только реализацией метода bool eventTest(QEvent *e).
	 * При разборе кода можно пропустить обявления классв, см. только реализаци
	 * eventTest в cwdescentwinimpl.cpp.
	 */
	class BasaTransiro: public QSignalTransition{
		protected:
			CWdescentWinImpl * o;
		public:
			BasaTransiro( QState * sourceState = 0 )
				: QSignalTransition(sourceState),
					o(static_cast<CWdescentWinImpl*>(this->sourceState()->parentState()->parent())){};
			BasaTransiro( QObject * sender, const char * signal,
			              QState * sourceState = 0
			            )
				: QSignalTransition(sender, signal, sourceState),
					o(static_cast<CWdescentWinImpl*>(this->sourceState()->parentState()->parent())){};
	};
	/*! Переход принятия новой точки в качестве текщей.
	 * 
	 * Используется при переходе от s2 к s5, s4 к s5, s7 к s10, s9 к s10.
	 */
	class KonsideriPointoTransiro: public BasaTransiro{
		public:
			KonsideriPointoTransiro( QState * sourceState = 0
			            ) : BasaTransiro(sourceState){};
			KonsideriPointoTransiro( QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};
	/*! Переход непринятия новой точки в качестве текщей.
	 * 
	 * Используется при переходе от s2 к s3, s4 к s6, s7 к s8, s7 к s11.
	 */
	class NoKonsideriPointoTransiro: public BasaTransiro{
		public:
			NoKonsideriPointoTransiro( QState * sourceState = 0
			            ) : BasaTransiro(sourceState){};
			NoKonsideriPointoTransiro( QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};
	//! Переход от s1 к s2.
	class s1s2Transiro: public BasaTransiro{
		public:
			s1s2Transiro( QState * sourceState = 0)
				: BasaTransiro(sourceState){};
			s1s2Transiro( QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            )
				: BasaTransiro(sender, signal, sourceState){};
		protected:
			//! Перход срабатывает, только если выбран шаг в + по Х1 
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s3 к s4.
	class s3s4Transiro: public BasaTransiro{
		public:
			s3s4Transiro( QState * sourceState = 0
			            ) : BasaTransiro(sourceState){};
			s3s4Transiro( QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s5 к s7.
	class s5s7_s6s7Transiro: public BasaTransiro{
		public:
			s5s7_s6s7Transiro( QState * sourceState = 0
			            ) : BasaTransiro(sourceState){};
			s5s7_s6s7Transiro( QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s8 к s9.
	class s8s9Transiro: public BasaTransiro{
		public:
			s8s9Transiro( QState * sourceState = 0
			            ) : BasaTransiro(sourceState){};
			s8s9Transiro( QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s10 к sf.
	class s10sfTransiro: public BasaTransiro{
		public:
			s10sfTransiro( QState * sourceState = 0
			            ) : BasaTransiro(sourceState){};
			s10sfTransiro( QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s10 к s1.
	class s10s1Transiro: public BasaTransiro{
		public:
			s10s1Transiro( QState * sourceState = 0
			            ) : BasaTransiro(sourceState){};
			s10s1Transiro( QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s12 к sf.
	class s12sfTransiro: public BasaTransiro{
		public:
			s12sfTransiro( QState * sourceState = 0
			            ) : BasaTransiro(sourceState){};
			s12sfTransiro( QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s12 к s1.
	class s12s1Transiro: public BasaTransiro{
		public:
			s12s1Transiro( QState * sourceState = 0
			            ) : BasaTransiro(sourceState){};
			s12s1Transiro( QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(sender, signal, sourceState){};
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