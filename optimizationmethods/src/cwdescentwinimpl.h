#ifndef CWDESCENTWINIMPL_H
#define CWDESCENTWINIMPL_H
//
#include "algoritmowin.h"
#include "ui_CWdescent_fixwindow.h"
#include "demonstrataqpointf.h"
#include <QSignalTransition>
#include <QRadioButton>
//
/*! В этом пространстве имён содержаться классы относящиеся к конечному автомату
 * для покоординатного спуска с фиксированным шагом.
 */ 
namespace SinkoLauxKoordinatoj{
	/*! Базовый класс переходов внутри конечного автомата для покоординатного спуска.
	 *
	 * Для принятия решения об исполнении всем переходам надо иметь информацию о
	 * базовой точке итерации, текущей точке и новой. 
	 * 
	 * Переходы различаются, только реализацией метода bool eventTest(QEvent *e).
	 * При разборе кода можно пропустить обявления классв, см. только реализаци
	 * eventTest.
	 */
	class BasaTransiro: public QSignalTransition{
		protected:
		  //! Базовая точка итерации.
		  DemonstrataQPointF *BP;
		  //! Текущая базовая точка.
		  DemonstrataQPointF *MP;
		  //! Новая точка.
		  DemonstrataQPointF *NP;
		public:
			BasaTransiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QState * sourceState = 0
			            ) : QSignalTransition(sourceState), BP(bp), MP(mp), NP(np){};
			BasaTransiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : QSignalTransition(sender, signal, sourceState),
			                BP(bp), MP(mp), NP(np){};
	};
	//! Переход от s1 к s2.
	class s1s2Transiro: public QSignalTransition{
		protected:
			QRadioButton * up_x1;
		public:
			s1s2Transiro( QRadioButton *up_x1_rb, QState * sourceState = 0)
				: QSignalTransition(sourceState), up_x1(up_x1_rb){};
			s1s2Transiro( QRadioButton *up_x1_rb, QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : QSignalTransition(sender, signal, sourceState), up_x1(up_x1_rb){};
		protected:
			//! Перход срабатывает, только если выбран шаг в + по Х1 
    	bool eventTest(QEvent *e){
    		return up_x1->isChecked() && QSignalTransition::eventTest(e);
			};
	};	
	//! Переход от s2 к s3.
	class s2s3Transiro: public BasaTransiro{
		public:
			s2s3Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sourceState){};
			s2s3Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s2 к s4.
	class s2s4Transiro: public BasaTransiro{
		public:
			s2s4Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sourceState){};
			s2s4Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s3 к s4.
	class s3s4Transiro: public BasaTransiro{
		public:
			s3s4Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sourceState){};
			s3s4Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s3 к s5.
	class s3s5Transiro: public BasaTransiro{
		public:
			s3s5Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sourceState){};
			s3s5Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s4 к s5.
	class s4s5Transiro: public BasaTransiro{
		public:
			s4s5Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sourceState){};
			s4s5Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s5 к s6.
	class s5s6Transiro: public BasaTransiro{
		public:
			s5s6Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sourceState){};
			s5s6Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s5 к s7.
	class s5s7Transiro: public BasaTransiro{
		public:
			s5s7Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sourceState){};
			s5s7Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s6 к s7.
	class s6s7Transiro: public BasaTransiro{
		public:
			s6s7Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sourceState){};
			s6s7Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s6 к s8.
	class s6s8Transiro: public BasaTransiro{
		public:
			s6s8Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sourceState){};
			s6s8Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s7 к sf.
	class s7sfTransiro: public BasaTransiro{
		public:
			s7sfTransiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sourceState){};
			s7sfTransiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s8 к sf.
	class s8sfTransiro: public BasaTransiro{
		public:
			s8sfTransiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sourceState){};
			s8sfTransiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s7 к s1.
	class s7s1Transiro: public BasaTransiro{
		public:
			s7s1Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sourceState){};
			s7s1Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
	//! Переход от s8 к s1.
	class s8s1Transiro: public BasaTransiro{
		public:
			s8s1Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sourceState){};
			s8s1Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sender, signal, sourceState){};
		protected:
    	bool eventTest(QEvent *e);
	};	
};
//
//! Окно для прохождения Покоординатного спуска с фиксированным шагом.
class CWdescentWinImpl : public AlgoritmoWin, public Ui::CWdescentWin
{
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
  QPointF PX1;
  //! Шаг по х1.
  /*! Для удобства задаю в виде точки (0, длина).
   */
  QPointF PX2;
public:
	CWdescentWinImpl( funkcio *f, //!< Указатель на целевую функцию. CWdescentWinImpl не заботится о назначении Funkcio родителя.
                    QVector<double> *d, //!< Массив с данными задания.
                    QWidget * parent = 0, //!< Родитель.
                    Qt::WFlags flags = 0 //!< Флаги парамметров окна.
                  );
private slots:
  //! Фиксирует совершение пользователем ошики.
  void registriEraro();
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