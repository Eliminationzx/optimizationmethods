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

public:
	/*! Конструктор.
	 * @param f Указатель на целевую функцию. FasterDescentImpl не заботится о назначении Funkcio родителя.
	 * @param d Массив с данными задания.Структура: 0 - точность; 1 - шаг по оси х1; 2 - шаг по оси х2; 3 - коэффициент изменения шага; 4 - х1; 5 - х2; 6 - максимальное количество ошибок.
	 * @param parent Родитель.
	 * @param flags Флаги параметров окна.
	 */
	NotWenImpl( funkcio *f, QVector<double> *d, QWidget * parent = 0,
                    Qt::WFlags flags = 0 );

private slots:

signals:
	//! Пользователь прошёл тест.
	void usiloPlenumis(int);

	/*! Использую сигнал для прехода, который не требует действий пользователя,
	 * а только проверяет условие.
	 */
	void stateHasEntered();
};
#endif





