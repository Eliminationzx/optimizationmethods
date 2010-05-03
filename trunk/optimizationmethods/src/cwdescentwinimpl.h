#ifndef CWDESCENTWINIMPL_H
#define CWDESCENTWINIMPL_H
//
#include "algoritmowin.h"
#include "ui_CWdescent_fixwindow.h"
#include "demonstrataqpointf.h"
#include <QSignalTransition>
//
/*! В этом пространстве имён содержаться классы относящиеся к конечному автомату
 * для покоординатного спуска с фиксированным шагом.
 */ 
namespace SinkoLauxKoordinatoj{
	/*! Базовый класс переходов внутри конечного автомата для покоординатного спуска.
	 *
	 * Для принятия решения об исполнении всем переходам надо иметь информацию о
	 * базовой точке итерации, текущей точке и новой.
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
	class s1s2Transiro: public BasaTransiro{
		public:
			s1s2Transiro( DemonstrataQPointF *bp,
			              DemonstrataQPointF *mp,
			              DemonstrataQPointF *np,
			              QState * sourceState = 0
			            ) : BasaTransiro(bp, mp, np, sourceState){};
			s1s2Transiro( DemonstrataQPointF *bp,
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