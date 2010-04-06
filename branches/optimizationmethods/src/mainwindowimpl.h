#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include <QVariant>
#include "getvariantsImpl.h"
#include "ui_mainwindow.h"
//
//! Производный класс от класса главной формы приложения optimizationmethods.
/*! Предназначен для выбора метода оптимизации и целевой функции.
 * @author Проскурин Александр Викторович
 * @file mainwindowimpl.h
 */
class MainWindowImpl : public QMainWindow, public Ui::MainWindow
{
Q_OBJECT

//! Была ли пройдена квадратичная функция
bool takeQuadFun;

private:

public:
	//! Конструктор класса.
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );

private slots:
	//! Слот класса, получающий сигнал при нажатии на кнопку "Далее".
	/*! В начале считывает индекс выбраного варианта и типа функции,
	 * затем создает объект формы выбора варианта.
	 */
	void on_next_button_clicked();
};
#endif




