#ifndef MAINPASSIMPL_H
#define MAINPASSIMPL_H
//
#include <QDialog>
#include <QVector>
#include <QVariant>
#include "ui_mainwindowPass.h"
//
class mainPassImpl : public QDialog, public Ui::mainPass
{
Q_OBJECT

public:
	mainPassImpl(int method, QWidget * parent = 0, Qt::WFlags f = 0 );
	
signals:
	//! Сигнал класса, высылаемый при нажатии на кнопку "Ок".
	void setFlag(int flag);

private slots:
	//! Слот класса, получающий сигнал при нажатии на кнопку "Ок".
	/* При совпадении пароля с заданым высылает сигнал классу MainWindowImpl, который переводит флаг прохождения квадратичной функции выбраным методом в true.
	 * После закрывает диалог.
	 */ 
	void on_Ok_clicked();
};
#endif





