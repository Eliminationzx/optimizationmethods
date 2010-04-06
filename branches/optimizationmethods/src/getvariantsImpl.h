#ifndef GETVARIANTSIMPL_H
#define GETVARIANTSIMPL_H
//
#include <QMainWindow>
#include "ui_getvariants.h"
//
//! Производный класс от класса формы выбора варианта приложения optimizationmethods.
/*! Предназначен для выбора варианта целевой функции и предоставления модулям объекта функции.
 * @author Проскурин Александр Викторович
 * @file mainwindowimpl.h
 */
class getvariantsImpl : public QMainWindow, public Ui::MainWindow
{
Q_OBJECT

public:
	//! Конструктор класса.
	getvariantsImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:
};
#endif





