#ifndef HUGIIMPL_H
#define HUGIIMPL_H
//
#include "algoritmowin.h"
#include "ui_HuGi.h"
//
class HuGiImpl : public AlgoritmoWin, public Ui::HuGi{
Q_OBJECT
public:
	/*! Конструктор.
	 * @param f Указатель на целевую функцию. CWdescentWinImpl не заботится о назначении Funkcio родителя.
	 * @param d Массив с данными задания.Структура: 0 - точность; 1 - шаг по оси х1; 2 - шаг по оси х2; 3 - коэффициент изменения шага; 4 - х1; 5 - х2; 6 - максимальное количество ошибок.
	 * @param parent Родитель.
	 * @param flags Флаги параметров окна.
	 */
	HuGiImpl( funkcio *f, QVector<double> d, QWidget * parent = 0,
	          Qt::WFlags flags = 0 );
private slots:
};
#endif





