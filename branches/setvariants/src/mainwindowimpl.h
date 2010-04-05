#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include "ui_mainwindow.h"
//
class MainWindowImpl : public QMainWindow, public Ui::MainWindow
{
Q_OBJECT

public:
	//! Запись данных варинта в текстовый файл
	bool WriteVariants(const QString typeFunction, const QVector<double> data);
	//! Запись данных варинта в текстовый файл
	bool WriteVariants(const int typeFunction, const QVector<double> data);

public:
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );

private slots:
};
#endif




