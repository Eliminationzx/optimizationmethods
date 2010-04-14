#ifndef CWDESCENTWINIMPL_H
#define CWDESCENTWINIMPL_H
//
#include "algoritmowin.h"
#include "ui_CWdescent_fixwindow.h"
#include "demonstrataqpointf.h"
//
//! Этапы итерации
enum EtapojIteracio{
  PasxiDekstren, //!< Шаг направо.
  PasxiMaldekstren, //!< Шаг налево.
  PasxiSupren, //!< Шаг вверх.
  PasxiMalsupren, //!< Шаг вниз.
  MalpliigiPasxo, //!< Уменьшение шага.
  Finisxo //!< Конец алгоритма.
};
//! Окно для прохождения Покоординатного спуска с фиксированным шагом.
class CWdescentWinImpl : public AlgoritmoWin, public Ui::CWdescentWin
{
Q_OBJECT
protected:
  //! Количество ошибок.
  int KvantoEraroj;
  //! Номер итерации.
  int NumeroIteracio;
  //! Флаг этапа итерации.
  EtapojIteracio FlagEtapo;
  //! Флаг рассмотрения точки. Принимать в качестве новой текущей или нет.
  bool KonsideradoPointo; 
  //! Текущая точка.
  DemonstrataQPointF MomentaPointo;
  //! Новая точка.
  DemonstrataQPointF NovaPointo;
  //! Шаг по х1.
  /*! Для удобства задаю в виде точки (длина, 0).
   */
  DemonstrataQPointF PasxoX1;
  //! Шаг по х1.
  /*! Для удобства задаю в виде точки (0, длина).
   */
  DemonstrataQPointF PasxoX2;
public:
	CWdescentWinImpl( funkcio *f, QVector<double> *d, QWidget * parent = 0, Qt::WFlags flags = 0 );
private slots:
  //! Обработчик кнопки шага.
  void on_calculate_bt_clicked();
  //! Обработчик кнопки принятия точки.
  void on_accept_bt_clicked();
  //! Обработчик кнопки не принятия точки.
  void on_not_accept_bt_clicked();
  //! Обработчик кнопки завершения лгоритма.
  void on_end_bt_clicked();
  //! Обработчик кнопки уменьшения шага.
  void on_change_step_bt_clicked();
};
#endif

/*! @class CWdescentWinImpl
 * Алгоритм:
 * 
 * Операции алгоритма повторяются циклически, пока не значениене приблизится к минимуму на заданную точность.
 * Каждая итерация содержит следующие шаги:
 * 
 * 1) Изменяем x1 в положительную сторону на значение h1.
 * 
 * Если значение F(x1 + h1, x2) < F(x1, x2), то необходимо принять новую точку и перейти к следующей итерации, иначе не принимаем её. 
 * 
 * 2) Если не приняли, то изменяем x1 в отрицательную сторону на значение h1.
 * 
 * Если значение F(x1 - h1, x2) < F(x1, x2), то необходимо принять новую точку и перейти к следующей итерации, иначе не принимаем её. 
 * 
 * 3) Повторяем пункты 1, 2 для x2 и h2.
 * 
 * 4) Если не приняли ни одно новое значения для x1 и x2, то уменьшаем длину шага.
 * 
 * 5) Если длина шага меньше требуемой точности, то завершаем поиск, иначе переходим к следующей итерации.
 * 
 * Реализация:
 * Работа программы идёт не линейно - разные этапы итерации разнесены в разные подпрограммы.
 * 
 * Имеются флаги состояния - FlagEtapo, KonsideradoPointo. Каждая итерация начинаится со значениями FlagEtapo = PasxiDekstren, KonsideradoPointo = false, что соответствует ожиданию шага в + по Х1.
 * Если пользователь сделал ожидаемое действие - шаг в + по Х1, то KonsideradoPointo присвоить true, что соответствует ожиданию выбора точки. Иначе зафиксировать ошибку, а состояние тапа алгоритма на изменять.
 * Аналогично работаю с остальными этапами.
 * 
 * FlagEtapo = PasxiMaldekstren, KonsideradoPointo = false соответствует ожиданию шага в - по Х1.(см. шаг 2) алгоритма)
 * 
 * FlagEtapo = PasxiMaldekstren, KonsideradoPointo = true соответствует ожиданию выбора точки при шаге в - по Х1.(см. шаг 2) алгоритма)
 * 
 * FlagEtapo = PasxiSupren, KonsideradoPointo = false соответствует ожиданию шага в + по Х2.(см. шаг 1) алгоритма)
 * 
 * FlagEtapo = PasxiSupren, KonsideradoPointo = true соответствует ожиданию выбора точки при шаге в + по Х2.(см. шаг 1) алгоритма)
 * 
 * FlagEtapo = PasxiMalsupren, KonsideradoPointo = false соответствует ожиданию шага в - по Х2.(см. шаг 2) алгоритма)
 * 
 * FlagEtapo = PasxiMalsupren, KonsideradoPointo = true соответствует ожиданию выбора точки при шаге в 1 по Х2.(см. шаг 2) алгоритма)
 * 
 * FlagEtapo = MalpliigiPasxo соответствует ожиданию уменьшения шага.(см. шаг 4) алгоритма)
 * 
 * FlagEtapo = Finisxo соответствует ожиданию завершения алгоритма.(см. шаг 5) алгоритма)
 * 
 * @author Александр Белоконь.
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