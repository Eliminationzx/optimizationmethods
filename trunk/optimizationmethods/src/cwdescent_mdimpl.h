#ifndef CWDESCENT_MDIMPL_H
#define CWDESCENT_MDIMPL_H
//
#include "ui_CWdescent_md.h"
#include "algoritmowin.h"
#include "demonstrataqpointf.h"
#include <QSignalTransition>
#include <QState>
#include <QRadioButton>
//
class funkcio;
//
//! Окно для прохождения Покоординатного спуска с минимизацией по направлению.
class CWdescent_mdImpl : public AlgoritmoWin, public Ui::CWdescent_md
{
Q_OBJECT

protected:
	//! Количество ошибок допустимых.
	int quanError;
	
	//! Базовая точка итерации.
	DemonstrataQPointF BP;
	
	//! Текущая базовая точка.
	DemonstrataQPointF MP;

	//! Возвращает точку, полученную при оптимизации функции одной переменной по оси Х1.
	DemonstrataQPointF LengthOfStepX1(DemonstrataQPointF X) const;

	//! Возвращает точку, полученную при оптимизации функции одной переменной по оси Х2.
	DemonstrataQPointF LengthOfStepX2(DemonstrataQPointF X) const;
public:
	/*! Конструктор.
	 * @param f Указатель на целевую функцию. CWdescent_mdImpl не заботится о назначении Funkcio родителя.
	 * @param d Массив с данными задания.Структура: 0 - точность; 1 - шаг по оси х1; 2 - шаг по оси х2; 3 - коэффициент изменения шага; 4 - х1; 5 - х2; 6 - максимальное количество ошибок.
	 * @param parent Родитель.
	 * @param flags Флаги параметров окна.
	 */
	CWdescent_mdImpl( funkcio *f, QVector<double> *d, QWidget * parent = 0,
		Qt::WFlags flags = 0 );
		
private slots:
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
	 * В этом состоянии задаются начальные для итерации значения переменых.
	 */
	void s1_entered();

	/*! Обработчик входа в состояние s2.
	 * В этом состоянии проверяется точка смещённая от базовой по Х1.
	 */
	void s2_entered();

	/*! Обработчик входа в состояние s3.
	 * В этом состоянии проверяется точка смещённая от базовой по Х2.
	 */
	void s3_entered();

	//! Обработчик входа в состояние sf - конец поиска.
	void sf_entered();
	
	//! Фиксирует совершение пользователем ошибки.
	void registriEraro();

};

/*! В этом пространстве имён содержаться классы относящиеся к конечному автомату
 * для покоординатного спуска с минимизацией по направлению.
 * 
 * Объявления наследников QSignalTransition можно не смотреть. Важна только
 * реализация метода eventTest, ради которой и переопрделяю классы.
 */ 
namespace SinkoLauxKoordinatojMD
{
	/*! Переход от s1 к s2.
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s1s2Transiro: public QSignalTransition
	{
		private:
			QRadioButton * min_x1;
		public:
			s1s2Transiro( QRadioButton * min_x1_rb, QState * sourceState = 0)
				: QSignalTransition(sourceState), min_x1(min_x1_rb){};
			s1s2Transiro( QRadioButton * min_x1_rb,
			              QObject * sender,
			              const char * signal,
			              QState * sourceState = 0
			            )
				: QSignalTransition(sender, signal, sourceState), min_x1(min_x1_rb){};
		protected:
			//! Перход срабатывает, только если выбран шаг в + по Х1 
    	bool eventTest(QEvent *e);
	};

	/*! Переход от s2 к s3.
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s2s3Transiro: public QSignalTransition
	{
		private:
			QRadioButton * min_x2;
		public:
			s2s3Transiro( QRadioButton * min_x2_rb, QState * sourceState = 0
			                 ) : QSignalTransition(sourceState), min_x2(min_x2_rb){};
			s2s3Transiro( QRadioButton * min_x2_rb,
			                   QObject * sender,
			                   const char * signal,
			                   QState * sourceState = 0
			                 ) : QSignalTransition(sender, signal, sourceState),
			                     min_x2(min_x2_rb){};
		protected:
    	bool eventTest(QEvent *e);
	};
	
	/*! Переход от s3 к s1.
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s3s1Transiro: public QSignalTransition{
		private:
			DemonstrataQPointF * bp;
			DemonstrataQPointF * mp;
			funkcio * f;
			qreal s; //!< Точность.
		public:
			s3s1Transiro(DemonstrataQPointF * BP,
						DemonstrataQPointF * MP,
						funkcio * F,
						qreal strikteco,
						QState * sourceState = 0
						) : QSignalTransition(sourceState), bp(BP), mp(MP), f(F), s(strikteco){};
			s3s1Transiro(DemonstrataQPointF * BP,
						DemonstrataQPointF * MP,
						funkcio * F,
						qreal strikteco,
						QObject * sender,
						const char * signal,
						QState * sourceState = 0
						) : QSignalTransition(sender, signal, sourceState),
						bp(BP), mp(MP), f(F), s(strikteco){};
		protected:
    	bool eventTest(QEvent *e);
	};
	
	/*! Переход от s3 к sf.
	 * При создании требует указатели на переменные необходимые для принятия
	 * решения о переходе.
	 */
	class s3sfTransiro: public QSignalTransition
	{
		private:
			DemonstrataQPointF * bp;
			DemonstrataQPointF * mp;
			funkcio * f;
			qreal s; //!< Точность.
		public:
			s3sfTransiro(DemonstrataQPointF * BP,
						DemonstrataQPointF * MP,
						funkcio * F,
						qreal strikteco,
						QState * sourceState = 0
						) : QSignalTransition(sourceState), bp(BP), mp(MP), f(F), s(strikteco){};
			s3sfTransiro(DemonstrataQPointF * BP,
						DemonstrataQPointF * MP,
						funkcio * F,
						qreal strikteco,
						QObject * sender,
						const char * signal,
						QState * sourceState = 0
						) : QSignalTransition(sender, signal, sourceState),
						bp(BP), mp(MP), f(F), s(strikteco){};
		protected:
		bool eventTest(QEvent *e);
	};
};
#endif

/*! @class CWdescent_mdImpl
 * Алгоритм:
 *
 * @image html "CWdescent_md.png" "Блок-схема"
 * 
 * Операции алгоритма повторяются циклически, пока значение не приблизится к
 * минимуму на заданную точность.
 * 
 * Каждая итерация содержит следующие шаги:
 * Шаг1
 * Вычисляем минимум целевой функции F(X1; X2) вдоль оси X1 (идет оптимизация одной переменной). 
 * Шаг2
 * Вычисляем минимум целевой функции F(X1; X2) вдоль оси X2 (идет оптимизация одной переменной). 
 * Шаг3
 * Если max(dF, dX) < E, то завершаем процесс минимизации. Иначе - переходим к шагу 1.
 *
 * Реализация:
 * 
 * Реализовано в виде конечного автомата. См. обзор "Каркас конечного автомата"
 * в документации Qt.
 * 
 * Код написан согласно диаграмме состояний.
 *
 * @image html "CWdescentMDStateMchine.png" "Покоординатный спуск"
 *
 * тт - текущая точка.
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
 * Применяю DemonstrataQPointF для BP, MP. В конструкторе окна соединяю их с надписями и картой,
 * а затем использую как обычные QPointF, не заботясь об отображении.
 * 
 * @author Проскурин Александр Викторович.
 */
