#ifndef NEMIIMPL_H
#define NEMIIMPL_H
//
#include "algoritmowin.h"
#include "ui_NeMi.h"
#include "demonstrataqpointf.h"
#include <QSignalTransition>
#include <QState>
//
class funkcio;
//
//! Окно для прохождения метода Нелдора-Мида.
class NeMiImpl : public AlgoritmoWin, public Ui::NeMi
{
Q_OBJECT
protected:
	//! Первая точка основного триугольника.
	DemonstrataQPointF P1;
	//! Вторая точка основного триугольника.
	DemonstrataQPointF P2;
	//! Третья точка основного триугольника.
	DemonstrataQPointF P3;
public:
	NeMiImpl( funkcio * f, QVector<double> *d, QWidget * parent = 0,
	          Qt::WFlags flags = 0 );
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
	/*! Обработчик входа в состояние ss.
	 */
	void ss_entered();
	/*! Обработчик входа в состояние s1.
	 */
	void s1_entered();
	/*! Обработчик входа в состояние s2.
	 */
	void s2_entered();
	/*! Обработчик входа в состояние s3.
	 */
	void s3_entered();
	/*! Обработчик входа в состояние s5.
	 */
	void s5_entered();
	/*! Обработчик входа в состояние s6.
	 */
	void s6_entered();
	/*! Обработчик входа в состояние s7.
	 */
	void s7_entered();
	/*! Обработчик входа в состояние s8.
	 */
	void s8_entered();
	/*! Обработчик входа в состояние s9.
	 */
	void s9_entered();
	/*! Обработчик входа в состояние s10.
	 */
	void s10_entered();
	/*! Обработчик входа в состояние s11.
	 */
	void s11_entered();
	//! Обработчик входа в состояние sf - конец поиска.
	void sf_entered();
  //! Фиксирует совершение пользователем ошики.
  void registriEraro();
};
#endif





