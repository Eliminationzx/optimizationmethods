#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QVariant>
#include "ui_mainwindow.h"
//
class MainWindowImpl : public QMainWindow, public Ui::MainWindow
{
Q_OBJECT

private:
	//! Запись данных варинта в текстовый файл
	bool WriteVariants(const QString typeFunction, const QVector<double> data);
	//! Запись данных варинта в текстовый файл
	bool WriteVariants(const int typeFunction, const QVector<double> data);
	//! Чтение данных варианта из текстового файла
	QVector<double> ReadVariants(const QString typeFunction, const int numberVariants);
	//! Чтение данных варианта из текстового файла
	QVector<double> ReadVariants(const int typeFunction, const int numberVariants);
	//! Возвращает список уже существующих вариантов
	QVector<int> AnalysisDirVariants(const QString typeFunction);
	//! Возвращает список уже существующих вариантов
	QVector<int> AnalysisDirVariants(const int typeFunction);
	//! Инициализация выпадающего списка варинтов для квадратичной функции
	void initializationQuadComboBox();
	//! Инициализация выпадающего списка варинтов для овражной функции
	void initializationRavinComboBox();

public:
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );

private slots:
	void on_comboBox_ravin_activated(int index);
	void on_comboBox_activated(int index);
	void on_save_button_ravin_clicked();
	void on_save_button_clicked();
};
#endif




