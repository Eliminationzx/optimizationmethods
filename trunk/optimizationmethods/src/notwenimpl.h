#ifndef NOTWENIMPL_H
#define NOTWENIMPL_H
//
#include "ui_NotWen.h"
#include "algoritmowin.h"
#include "demonstrataqpointf.h"
#include <QSignalTransition>
#include <QState>
#include <QRadioButton>
#include <QLineEdit>
//
class funkcio;
//
//! Окно для прохождения метода  Ньютона.
class NotWenImpl : public AlgoritmoWin, public Ui::NotWen
{
Q_OBJECT

protected:
	//! Количество ошибок допустимых.
	int quanError;
	
	//! Базовая точка итерации.
	DemonstrataQPointF BP;
	
	//! Градиент.
	DemonstrataQPointF grad;
	
	//! Первая строка обратного гессиана.
	DemonstrataQPointF gessian1;
	
	//! Вторая строка обратного гессиана.
	DemonstrataQPointF gessian2;

public:
	/*! Конструктор.
	 * @param f Указатель на целевую функцию. FasterDescentImpl не заботится о назначении Funkcio родителя.
	 * @param d Массив с данными задания.Структура: 0 - точность; 1 - шаг по оси х1; 2 - шаг по оси х2; 3 - коэффициент изменения шага; 4 - х1; 5 - х2; 6 - максимальное количество ошибок.
	 * @param parent Родитель.
	 * @param flags Флаги параметров окна.
	 */
	NotWenImpl( funkcio *f, QVector<double> *d, QWidget * parent = 0,
                    Qt::WFlags flags = 0 );

	//! Возвращает противоположный знак числа.
	static QString otrNumberSign(double a)
	{
		if(a > 0)
			return "-";
		else
			return "+";
	};
	//! Возвращает знак числа.
	static QString numberSign(double a)
	{
		if(a > 0)
			return "+";
		else
			return "-";
	};
	
private slots:
	void on_about_action_activated();
	//! help браузер
	void on_helpo_action_activated();

	//! изменить шрифт
	void on_difiniFonto_act_activated();

	/*! "Обнуление" переменных.
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
	 * В этом состоянии ставится начальная страница из стека (индекс 0).
	 */
	void s1_entered();

	/*! Обработчик входа в состояние s2.
	 * В этом состоянии ставится страница из стека (индекс 1).
	 */
	void s2_entered();

	/*! Обработчик входа в состояние s3.
	 * В этом состоянии ставится страница из стека (индекс 2).
	 */
	void s3_entered();

	/*! Обработчик входа в состояние s4.
	 * В этом состоянии ставится начальная страница из стека (индекс 3),
	 * а также вычисляется градиент.
	 */
	void s4_entered();

	/*! Обработчик входа в состояние s5.
	 * В этом состоянии ставится страница из стека (индекс 4).
	 */
	void s5_entered();

	/*! Обработчик входа в состояние s6.
	 * В этом состоянии ставится начальная страница из стека (индекс 5)
	 */
	void s6_entered();

	/*! Обработчик входа в состояние s7.
	 * В этом состоянии ставится страница из стека (индекс 6),
	 * а также высчитывается новая базовая точка.
	 */
	void s7_entered();

	//! Обработчик входа в состояние sf - конец поиска.
	void sf_entered();
	
	//! Фиксирует совершение пользователем ошибки.
	void registriEraro();
	
signals:
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
namespace SinkoNotWen
{
	/*! Переход от s1 к s2.
	 * При создании требует указатели на переменные необходимые для принятия решения о переходе.
	 */
	class s1s2Transiro: public QSignalTransition
	{
		private:
			QRadioButton * _G_xkgradfxk;
		public:
			s1s2Transiro(QRadioButton * _g_xkgradfxk, QState * sourceState = 0)
						 : QSignalTransition(sourceState), _G_xkgradfxk(_g_xkgradfxk){};
			s1s2Transiro(QRadioButton * _g_xkgradfxk,
						QObject * sender,
						const char * signal,
						QState * sourceState = 0)
						: QSignalTransition(sender, signal, sourceState), _G_xkgradfxk(_g_xkgradfxk){};
		protected:
			//! Перход срабатывает, только если нажата кнопка next1
		bool eventTest(QEvent *e);
	};

	/*! Переход от s2 к s3.
	 * При создании требует указатели на переменные необходимые для принятия решения о переходе.
	 */
	class s2s3Transiro: public QSignalTransition
	{
		private:
			int * numberIterac;
			QRadioButton * Part_proizvod_first;
		public:
			s2s3Transiro(int * NumeroIteracio, QRadioButton * part_proizvod_first, QState * sourceState = 0)
					 : QSignalTransition(sourceState), numberIterac(NumeroIteracio), Part_proizvod_first(part_proizvod_first){};
			s2s3Transiro( int * NumeroIteracio,
							QRadioButton * part_proizvod_first,
							QObject * sender,
							const char * signal,
							QState * sourceState = 0)
							 : QSignalTransition(sender, signal, sourceState),
							  numberIterac(NumeroIteracio), Part_proizvod_first(part_proizvod_first){};
		protected:
			//! Перход срабатывает, только если нажата кнопка next2
			bool eventTest(QEvent *e);
	};

	/*! Переход от s2 к s4.
	 * При создании требует указатели на переменные необходимые для принятия решения о переходе.
	 */
	class s2s4Transiro: public QSignalTransition
	{
		private:
			int * numberIterac;
			QRadioButton * Part_proizvod_first;
		public:
			s2s4Transiro(int * NumeroIteracio, QRadioButton * part_proizvod_first, QState * sourceState = 0)
							 : QSignalTransition(sourceState), numberIterac(NumeroIteracio), Part_proizvod_first(part_proizvod_first){};
			s2s4Transiro(int * NumeroIteracio,
							QRadioButton * part_proizvod_first,
							QObject * sender,
							const char * signal,
							QState * sourceState = 0)
							 : QSignalTransition(sender, signal, sourceState),
							  numberIterac(NumeroIteracio), Part_proizvod_first(part_proizvod_first){};
		protected:
			//! Перход срабатывает, только если нажата кнопка next2
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
						QState * sourceState = 0)
						 : QSignalTransition(sender, signal, sourceState),
						  f(F), df_dx1(dfdx1), df_dx2(dfdx2){};
		protected:
			//! Перход срабатывает, только если нажата кнопка next3
		bool eventTest(QEvent *e);
	};
	
	/*! Переход от s4 к s5.
	 * При создании требует указатели на переменные необходимые для принятия решения о переходе.
	 */
	class s4s5Transiro: public QSignalTransition
	{
		private:
			QRadioButton * Gradfxk_less;
		public:
			s4s5Transiro(QRadioButton * gradfxk_less, QState * sourceState = 0)
							 : QSignalTransition(sourceState), Gradfxk_less(gradfxk_less){};
			s4s5Transiro(QRadioButton * gradfxk_less,
							QObject * sender,
							const char * signal,
							QState * sourceState = 0)
							 : QSignalTransition(sender, signal, sourceState),
							  Gradfxk_less(gradfxk_less){};
		protected:
			//! Перход срабатывает, только если нажата кнопка next4
			bool eventTest(QEvent *e);
	};

	/*! Переход от s5 к s6.
	 * При создании требует указатели на переменные необходимые для принятия решения о переходе.
	 */
	class s5s6Transiro: public QSignalTransition
	{
		private:
			int * numberIterac;
			DemonstrataQPointF * Grad;
			qreal s; //!< Точность.
			QRadioButton * To_continue;
		public:
			s5s6Transiro(int * NumeroIteracio, 
							DemonstrataQPointF * grad, 
							qreal strikteco, 
							QRadioButton * to_continue, 
							QState * sourceState = 0)
							 : QSignalTransition(sourceState),
							  numberIterac(NumeroIteracio), Grad(grad), s(strikteco), To_continue(to_continue){};
			s5s6Transiro(int * NumeroIteracio,
							DemonstrataQPointF * grad,
							qreal strikteco,
							QRadioButton * to_continue, 
							QObject * sender,
							const char * signal,
							QState * sourceState = 0)
							 : QSignalTransition(sender, signal, sourceState),
							  numberIterac(NumeroIteracio), Grad(grad), s(strikteco), To_continue(to_continue){};
		protected:
			//! Перход срабатывает, только если нажата кнопка next5
			bool eventTest(QEvent *e);
	};

	/*! Переход от s5 к s7.
	 * При создании требует указатели на переменные необходимые для принятия решения о переходе.
	 */
	class s5s7Transiro: public QSignalTransition
	{
		private:
			int * numberIterac;
			DemonstrataQPointF * Grad;
			qreal s; //!< Точность.
			QRadioButton * To_continue;
		public:
			s5s7Transiro(int * NumeroIteracio, 
							DemonstrataQPointF * grad, 
							qreal strikteco, 
							QRadioButton * to_continue,
							QState * sourceState = 0)
							 : QSignalTransition(sourceState),
							  numberIterac(NumeroIteracio), Grad(grad), s(strikteco), To_continue(to_continue){};
			s5s7Transiro(int * NumeroIteracio,
							DemonstrataQPointF * grad,
							qreal strikteco,
							QRadioButton * to_continue,
							QObject * sender,
							const char * signal,
							QState * sourceState = 0)
							 : QSignalTransition(sender, signal, sourceState),
							  numberIterac(NumeroIteracio), Grad(grad), s(strikteco), To_continue(to_continue){};
		protected:
			//! Перход срабатывает, только если нажата кнопка next5
			bool eventTest(QEvent *e);
	};

	/*! Переход от s5 к sf.
	 * При создании требует указатели на переменные необходимые для принятия решения о переходе.
	 */
	class s5sfTransiro: public QSignalTransition
	{
		private:
			DemonstrataQPointF * Grad;
			qreal s; //!< Точность.
			QRadioButton * Stop;
		public:
			s5sfTransiro(DemonstrataQPointF * grad,
						qreal strikteco,
						QRadioButton * stop,
						QState * sourceState = 0)
						 : QSignalTransition(sourceState),
						  Grad(grad), s(strikteco), Stop(stop){};
			s5sfTransiro(DemonstrataQPointF * grad,
						qreal strikteco,
						QRadioButton * stop,
						QObject * sender,
						const char * signal,
						QState * sourceState = 0)
						 : QSignalTransition(sender, signal, sourceState),
						  Grad(grad), s(strikteco), Stop(stop){};
		protected:
			//! Перход срабатывает, только если нажата кнопка next5
			bool eventTest(QEvent *e);
	};
	
	/*! Переход от s6 к s7.
	 * При создании требует указатели на переменные необходимые для принятия решения о переходе.
	 */
	class s6s7Transiro: public QSignalTransition
	{
		private:
			funkcio * f;
			DemonstrataQPointF * bp;
			QLineEdit * Dfdx1dx1;
			QLineEdit * Dfdx1dx2;
			QLineEdit * Dfdx2dx1;
			QLineEdit * Dfdx2dx2;
			QLineEdit * Gess11;
			QLineEdit * Gess12;
			QLineEdit * Gess21;
			QLineEdit * Gess22;
		public:
			s6s7Transiro(funkcio * F,
						DemonstrataQPointF * BP,
						QLineEdit * dfdx1dx1,
						QLineEdit * dfdx1dx2,
						QLineEdit * dfdx2dx1,
						QLineEdit * dfdx2dx2,
						QLineEdit * gess11,
						QLineEdit * gess12,
						QLineEdit * gess21,
						QLineEdit * gess22,
						QState * sourceState = 0)
						 : QSignalTransition(sourceState),
						  f(F), bp(BP), Dfdx1dx1(dfdx1dx1), Dfdx1dx2(dfdx1dx2), Dfdx2dx1(dfdx2dx1), Dfdx2dx2(dfdx2dx2),
						  Gess11(gess11), Gess12(gess12), Gess21(gess21), Gess22(gess22){};
			s6s7Transiro(funkcio * F,
						DemonstrataQPointF * BP,
						QLineEdit * dfdx1dx1,
						QLineEdit * dfdx1dx2,
						QLineEdit * dfdx2dx1,
						QLineEdit * dfdx2dx2,
						QLineEdit * gess11,
						QLineEdit * gess12,
						QLineEdit * gess21,
						QLineEdit * gess22,
						QObject * sender,
						const char * signal,
						QState * sourceState = 0)
						 : QSignalTransition(sender, signal, sourceState),
						  f(F), bp(BP), Dfdx1dx1(dfdx1dx1), Dfdx1dx2(dfdx1dx2), Dfdx2dx1(dfdx2dx1), Dfdx2dx2(dfdx2dx2),
						  Gess11(gess11), Gess12(gess12), Gess21(gess21), Gess22(gess22){};
		protected:
			//! Перход срабатывает, только если нажата кнопка next6
			bool eventTest(QEvent *e);
	};
};
#endif

/*! @class NotWenImpl
 * Алгоритм:
 *
 * @image html "NotWen.png" "Блок-схема"
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
 * @image html "NotWenStateMchine.png" "Покоординатный спуск"
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

