#ifndef FASTERDESCENTIMPL_H
#define FASTERDESCENTIMPL_H
//
#include "ui_FasterDescent.h"
#include "algoritmowin.h"
#include "demonstrataqpointf.h"
#include <QSignalTransition>
#include <QState>
#include <QRadioButton>
#include <QLineEdit>
//
class funkcio;
//
//! Окно для прохождения метода наискорейшего спуска.
class FasterDescentImpl : public AlgoritmoWin, public Ui::FasterDescent
{
Q_OBJECT

protected:
	//! Количество ошибок допустимых.
	int quanError;
	
	//! Базовая точка итерации.
	DemonstrataQPointF BP;
	
	//! Градиент.
	DemonstrataQPointF grad;

	//! Длина шага.
	double lengthStep;

public:
	/*! Конструктор.
	 * @param f Указатель на целевую функцию. FasterDescentImpl не заботится о назначении Funkcio родителя.
	 * @param d Массив с данными задания.Структура: 0 - точность; 1 - шаг по оси х1; 2 - шаг по оси х2; 3 - коэффициент изменения шага; 4 - х1; 5 - х2; 6 - максимальное количество ошибок.
	 * @param parent Родитель.
	 * @param flags Флаги параметров окна.
	 */
	FasterDescentImpl( funkcio *f, QVector<double> *d, QWidget * parent = 0,
                    Qt::WFlags flags = 0 );

private slots:
	//! help браузер
	void on_helpo_action_activated();		

	//! изменить шрифт
	void on_difiniFonto_act_activated();	

	/*! "Обнуление" переменных.
	 * 
	 * Этим методом задаются началные знаения всем переменным алгоритма.
	 * Используется перед запуском конечного автомата и в переходе вызванным 
	 * действием "Начать заново".
	 */
	void init();

	/*! Обработчик входа в состояние so.
	 * Исполизую для дебага.
	 */
	void so_entered();

	/*! Обработчик входа в состояние s1.
	 * В этом состоянии ставится начальная страница из стека (индекс 4).
	 */
	void s1_entered();

	/*! Обработчик входа в состояние s2.
	 * В этом состоянии ставится страница из стека (индекс 0).
	 */
	void s2_entered();

	/*! Обработчик входа в состояние s3.
	 * В этом состоянии ставится страница из стека (индекс 1).
	 */
	void s3_entered();

	/*! Обработчик входа в состояние s4.
	 * В этом состоянии ставится начальная страница из стека (индекс 4),
	 * а также вычисляется градиент.
	 */
	void s4_entered();

	/*! Обработчик входа в состояние s5.
	 * В этом состоянии ставится страница из стека (индекс 2).
	 */
	void s5_entered();

	/*! Обработчик входа в состояние s6.
	 * В этом состоянии ставится начальная страница из стека (индекс 4),
	 * а также вычисляется длина градиента.
	 */
	void s6_entered();

	/*! Обработчик входа в состояние s7.
	 * В этом состоянии ставится страница из стека (индекс 3).
	 */
	void s7_entered();

	/*! Обработчик входа в состояние s8.
	 * В этом состоянии ставится начальная страница из стека (индекс 4),
	 * а также вычисляется шаг в направлении антиградиента.
	 */
	void s8_entered();

	/*! Обработчик входа в состояние s9.
	 * В этом состоянии вычисляется новая базовая точка.
	 */
	void s9_entered();

	//! Обработчик входа в состояние sf - конец поиска.
	void sf_entered();
	
	//! Фиксирует совершение пользователем ошибки.
	void registriEraro();

signals:
	//! Пользователь прошёл тест.
	void usiloPlenumis(int);

	/*! Использую сигнал для прехода, который не требует действий пользователя,
	 * а только проверяет условие.
	 */
	void stateHasEntered();
};

/*! В этом пространстве имён содержаться классы относящиеся к конечному автомату
 * для покоординатного спуска с минимизацией по направлению.
 * 
 * Объявления наследников QSignalTransition можно не смотреть. Важна только
 * реализация метода eventTest, ради которой и переопрделяю классы.
 */ 
namespace SinkoFD
{
	//! Переход от s1 к s2.
	class s1s2Transiro: public QSignalTransition
	{
		public:
			s1s2Transiro(QState * sourceState = 0) : QSignalTransition(sourceState){};
			s1s2Transiro(QObject * sender,
			             const char * signal,
			             QState * sourceState = 0)
				: QSignalTransition(sender, signal, sourceState){};
		protected:
			//! Перход срабатывает, только если нажата кнопка ввести S 
		bool eventTest(QEvent *e);
	};

	/*! Переход от s2 к s3.
	 * При создании требует указатели на переменные необходимые для принятия решения о переходе.
	 */
	class s2s3Transiro: public QSignalTransition
	{
		private:
			int * numberIterac;
			QRadioButton * aGrad_fx;
		public:
			s2s3Transiro(int * NumeroIteracio, QRadioButton * agrad_fx, QState * sourceState = 0
			                 ) : QSignalTransition(sourceState), numberIterac(NumeroIteracio), aGrad_fx(agrad_fx){};
			s2s3Transiro( int * NumeroIteracio,
							QRadioButton * agrad_fx,
			                   QObject * sender,
			                   const char * signal,
			                   QState * sourceState = 0
			                 ) : QSignalTransition(sender, signal, sourceState),
			                  numberIterac(NumeroIteracio), aGrad_fx(agrad_fx){};
		protected:
	    	bool eventTest(QEvent *e);
	};

	/*! Переход от s2 к s4.
	 * При создании требует указатели на переменные необходимые для принятия решения о переходе.
	 */
	class s2s4Transiro: public QSignalTransition
	{
		private:
			int * numberIterac;
			QRadioButton * aGrad_fx;
		public:
			s2s4Transiro(int * NumeroIteracio, QRadioButton * agrad_fx, QState * sourceState = 0
			                 ) : QSignalTransition(sourceState), numberIterac(NumeroIteracio), aGrad_fx(agrad_fx){};
			s2s4Transiro(int * NumeroIteracio,
							QRadioButton * agrad_fx,
			                   QObject * sender,
			                   const char * signal,
			                   QState * sourceState = 0
			                 ) : QSignalTransition(sender, signal, sourceState),
			                  numberIterac(NumeroIteracio), aGrad_fx(agrad_fx){};
		protected:
	    	bool eventTest(QEvent *e);
	};

	//! Переход от s3 к s4.
	class s3s4Transiro: public QSignalTransition
	{
		private:
			funkcio * f;
			QLineEdit * df_dx1;
			QLineEdit * df_dx2;
		public:
			s3s4Transiro(funkcio * F, QLineEdit * dfdx1, QLineEdit * dfdx2,
						QState * sourceState = 0) : QSignalTransition(sourceState), f(F), df_dx1(dfdx1), df_dx2(dfdx2){};
			s3s4Transiro(funkcio * F,
						QLineEdit * dfdx1,
						QLineEdit * dfdx2,
						QObject * sender,
			             const char * signal,
			             QState * sourceState = 0
				) : QSignalTransition(sender, signal, sourceState), f(F), df_dx1(dfdx1), df_dx2(dfdx2){};
		protected:
			//! Перход срабатывает, только если нажата кнопка ввести S 
		bool eventTest(QEvent *e);
	};
	
	//! Переход от s4 к s5.
	class s4s5Transiro: public QSignalTransition
	{
		public:
			s4s5Transiro(QState * sourceState = 0) : QSignalTransition(sourceState){};
			s4s5Transiro(QObject * sender,
			                   const char * signal,
			                   QState * sourceState = 0
			                 ) : QSignalTransition(sender, signal, sourceState){};
		protected:
	    	bool eventTest(QEvent *e);
	};
	
	/*! Переход от s5 к s6.
	 * При создании требует указатели на переменные необходимые для принятия решения о переходе.
	 */
	class s5s6Transiro: public QSignalTransition
	{
		private:
			QRadioButton * Gradfx;
		public:
			s5s6Transiro(QRadioButton * gradfx, QState * sourceState = 0
			                 ) : QSignalTransition(sourceState), Gradfx(gradfx){};
			s5s6Transiro(QRadioButton * gradfx,
			                   QObject * sender,
			                   const char * signal,
			                   QState * sourceState = 0
			                 ) : QSignalTransition(sender, signal, sourceState), Gradfx(gradfx){};
		protected:
	    	bool eventTest(QEvent *e);
	};

	/*! Переход от s6 к s7.
	 * При создании требует указатели на переменные необходимые для принятия решения о переходе.
	 */
	class s6s7Transiro: public QSignalTransition
	{
		private:
			DemonstrataQPointF * Grad;
			qreal s; //!< Точность.
		public:
			s6s7Transiro(DemonstrataQPointF * grad, qreal strikteco, QState * sourceState = 0
			                 ) : QSignalTransition(sourceState), Grad(grad), s(strikteco){};
			s6s7Transiro(DemonstrataQPointF * grad,
							qreal strikteco,
			                   QObject * sender,
			                   const char * signal,
			                   QState * sourceState = 0
			                 ) : QSignalTransition(sender, signal, sourceState), Grad(grad), s(strikteco){};
		protected:
	    	bool eventTest(QEvent *e);
	};
	
	/*! Переход от s6 к sf.
	 * При создании требует указатели на переменные необходимые для принятия решения о переходе.
	 */
	class s6sfTransiro: public QSignalTransition
	{
		private:
			DemonstrataQPointF * Grad;
			qreal s; //!< Точность.
		public:
			s6sfTransiro(DemonstrataQPointF * grad,
						qreal strikteco,
						QState * sourceState = 0
						) : QSignalTransition(sourceState), Grad(grad), s(strikteco){};
			s6sfTransiro(DemonstrataQPointF * grad,
						qreal strikteco,
						QObject * sender,
						const char * signal,
						QState * sourceState = 0
						) : QSignalTransition(sender, signal, sourceState),
						Grad(grad), s(strikteco){};
		protected:
		bool eventTest(QEvent *e);
	};
	
	/*! Переход от s7 к s8.
	 * При создании требует указатели на переменные необходимые для принятия решения о переходе.
	 */
	class s7s8Transiro: public QSignalTransition
	{
		private:
			QRadioButton * minF;
		public:
			s7s8Transiro(QRadioButton * minf, QState * sourceState = 0
			                 ) : QSignalTransition(sourceState), minF(minf){};
			s7s8Transiro(QRadioButton * minf,
			                   QObject * sender,
			                   const char * signal,
			                   QState * sourceState = 0
			                 ) : QSignalTransition(sender, signal, sourceState), minF(minf){};
		protected:
	    	bool eventTest(QEvent *e);
	};
	
	/*! Переход от s8 к s9.
	 * При создании требует указатели на переменные необходимые для принятия решения о переходе.
	 */
	class s8s9Transiro: public QSignalTransition
	{
		private:
			DemonstrataQPointF * bp;
			DemonstrataQPointF * Grad;
			qreal s; //!< Точность.
		public:
			s8s9Transiro(DemonstrataQPointF * BP,
						DemonstrataQPointF * grad,
						QState * sourceState = 0
						) : QSignalTransition(sourceState), bp(BP), Grad(grad){};
			s8s9Transiro(DemonstrataQPointF * BP,
						DemonstrataQPointF * grad,
						QObject * sender,
						const char * signal,
						QState * sourceState = 0
						) : QSignalTransition(sender, signal, sourceState),
						bp(BP), Grad(grad){};
		protected:
		bool eventTest(QEvent *e);
	};
};
#endif

/*! @class FasterDescentImpl
 * Алгоритм:
 *
 * @image html "CWdescent_md.png" "Блок-схема"
 * 
 * Операции алгоритма повторяются циклически, пока значение не приблизится к
 * минимуму на заданную точность.
 * 
 * Каждая итерация содержит следующие шаги:
 * Шаг1
 * Выбираем направление для минимизации как антиградиент в исходной точке с координатами (X1; X2) для функции F(X1; X2).
 * Шаг2
 * Вводим координаты градиента равные частным производным функции F(X). Если уже введены, то переходим к шагу 3.
 * Шаг3
 * Если длина антиградиента меньше E, то минимум найден. Иначе - переходим к шагу 4.
 * Шаг4
 * Вычисляем длину шага a = min F(Х + a*S) (Ищется любым методом одномерной оптимизации).
 * Шаг5
 * Делаем шаг и принимаем новую точку. Переходим к шагу 1.
 *
 * Реализация:
 * 
 * Реализовано в виде конечного автомата. См. обзор "Каркас конечного автомата"
 * в документации Qt.
 * 
 * Код написан согласно диаграмме состояний.
 *
 * @image html "FasterDescentStateMchine.png" "Покоординатный спуск"
 *
 * бт - базовая точка; в ней сохраняется значение тт в начале итерации.
 * Это позволяет вычислить расстояние на которое сместилась тт за итерацию.
 * 
 * Состояния алгоритма заключены в сложное состояние. Дочернии состояния
 * наследуют переходы родителя, но переходы назначенные непосредственно
 * состоянию имеют приоритет перед унаследованными. so имеет переходы без цели.
 * Они не изменяют состояние, а только высылают сигнал. По этому сигналу
 * регистрирую ошибку пользователя.
 * 
 * Перед запуском автомата задаю переменным начальные значения. См. init().
 * Использую этот слот и при переходе вызванным действием "Начать заново".
 * 
 * Применяю DemonstrataQPointF для BP, grad. В конструкторе окна соединяю их с надписями и картой,
 * а затем использую как обычные QPointF, не заботясь об отображении.
 * 
 * @author Проскурин Александр Викторович.
 */