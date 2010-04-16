#ifndef CWDESCENTWINIMPL_H
#define CWDESCENTWINIMPL_H
//
#include "algoritmowin.h"
#include "ui_CWdescent_fixwindow.h"
#include "demonstrataqpointf.h"
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
  //! Флаг этапа итерации.
  int FlagEtapo;
  //! Текущая точка.
  QPointF MomentaPointo;
  //! Новая точка.
  QPointF NovaPointo;
  //! Шаг по х1.
  /*! Для удобства задаю в виде точки (длина, 0).
   */
  QPointF PasxoX1;
  //! Шаг по х1.
  /*! Для удобства задаю в виде точки (0, длина).
   */
  QPointF PasxoX2;
public:
	CWdescentWinImpl( funkcio *f, QVector<double> *d, QWidget * parent = 0, Qt::WFlags flags = 0 );
private slots:
  //! Фиксирует совершение пользователем ошики.
  void registriEraro();
  //! Обработчик кнопки шага.
  void on_calculate_bt_clicked();
  //! Обработчик кнопки принятия точки.
  void on_accept_bt_clicked();
  //! Обработчик кнопки не принятия точки.
  void on_not_accept_bt_clicked();
  //! Обработчик кнопки завершения алгоритма.
  void on_end_bt_clicked();
  //! Обработчик кнопки уменьшения шага.
  void on_change_step_bt_clicked();
};
#endif

/*! @class CWdescentWinImpl
 * Алгоритм:
 *
 * Операции алгоритма повторяются циклически, пока не значение не приблизится к минимуму на заданную точность.
 * Каждая итерация содержит следующие шаги:
 *
 * 1) Изменяем x1 в положительную сторону на значение h1.
 *
 * 2) Если значение F(x1 + h1, x2) < F(x1, x2), то необходимо принять новую точку и перейти к следующей итерации, иначе не принимаем её.
 *
 * 3) Если не приняли, то изменяем x1 в отрицательную сторону на значение h1.
 *
 * 4) Если значение F(x1 - h1, x2) < F(x1, x2), то необходимо принять новую точку и перейти к следующей итерации, иначе не принимаем её.
 *
 * 5) Изменяем x2 в положительную сторону на значение h2.
 *
 * 6)Если значение F(x1, x2 + h2) < F(x1, x2), то необходимо принять новую точку и перейти к следующей итерации, иначе не принимаем её.
 *
 * 7) Если не приняли, то изменяем x2 в отрицательную сторону на значение h2.
 *
 * 8) Если значение F(x1, x2 - h2) < F(x1, x2), то необходимо принять новую точку и перейти к следующей итерации, иначе не принимаем её.
 *
 * 9) Если не приняли ни одно новое значения для x1 и x2, то уменьшаем длину шага.
 *
 *   Если длина шага меньше требуемой точности, то завершаем поиск, иначе переходим к следующей итерации.
 * 
 * 10) Конец поиска
 *
 * @image html Блок схема "Покоординатного спуска с фиксированным шагом.png" "Блок-схема"
 * 
 * Реализация:
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
 * 10 - нажата end_bt
 *
 * При не соответствии выдаётся ошибка. При соответствии выполияется действие и переход на следующий этап согласно алгоритму.
 * 
 * @author Александр Белоконь, Василий Почкаенко.
 * @file cwdescentwinimpl.h
 */

 /*! @enum EtapojIteracio
  *
  * Из PasxiDekstren можно пеейти только в PasxiMaldekstren или PasxiDekstren.
  * Из PasxiMaldekstren можно пеейти только в PasxiSupren или PasxiDekstren.
  * Из PasxiSupren можно пеейти только в PasxiMalupren или PasxiDekstren.
  * Из PasxiMalupren можно пеейти только в .
  * Из MalpliigiPasxo можно перейти только в PasxiMaldekstren или Finisxo.
  *
 */