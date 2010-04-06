#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include <QVariant>
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

private:

public:
	//! Конструктор класса.
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );

private slots:
};
#endif




