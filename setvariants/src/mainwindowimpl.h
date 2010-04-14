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
//! Производный класс от класса формы приложения setvariants.
/*! Предназначен для сохранения и редактирования данных вариантов целевых функций.
 * @author Проскурин Александр Викторович
 * @file mainwindowimpl.h
 */
class MainWindowImpl : public QMainWindow, public Ui::MainWindow
{
Q_OBJECT

private:
	//! Запись данных варинта в текстовый файл.
	/*! В качестве аргументов принимает:
	 * typeFunction - название целевой функции (quadFunction или ravinFunction);
	 * data - вектор данных варианта, первым элементом которого является номер варианта.
	 * Возвращает true при успешной записи и false в остальных случаях.
	 */
	bool WriteVariants(const QString typeFunction, const QVector<double> data);

	//! Запись данных варинта в текстовый файл
	/*! В качестве аргументов принимает:
	 * typeFunction - индекс целевой функции (0 - quadFunction, 1 - ravinFunction);
	 * data - вектор данных варианта, первым элементом которого является номер варианта.
	 * Возвращает true при успешной записи и false в остальных случаях.
	 */
	bool WriteVariants(const int typeFunction, const QVector<double> data);

	//! Чтение данных варианта из текстового файла.
	/*! В качестве аргументов принимает:
	 * typeFunction - название целевой функции (quadFunction или ravinFunction);
	 * numberVariants - номер варианта.
	 * Возвращает вектор данных варианта при успешном чтении и вектор с нулевыми значениями в остальных случаях.
	 */
	QVector<double> ReadVariants(const QString typeFunction, const int numberVariants);

	//! Чтение данных варианта из текстового файла.
	/*! В качестве аргументов принимает:
	 * typeFunction - индекс целевой функции (0 - quadFunction, 1 - ravinFunction);
	 * numberVariants - номер варианта.
	 * Возвращает вектор данных варианта при успешном чтении и вектор с нулевыми значениями в остальных случаях.
	 */
	QVector<double> ReadVariants(const int typeFunction, const int numberVariants);

	//! Анализ директории вариантов целевой функции.
	/*! В качестве аргумента принимает:
	 * typeFunction - название целевой функции (quadFunction или ravinFunction).
	 * Возвращает вектор из существующих вариантов
	 */
	QVector<int> AnalysisDirVariants(const QString typeFunction);

	//! Анализ директории вариантов целевой функции.
	/*! В качестве аргумента принимает:
	 * typeFunction - индекс целевой функции (0 - quadFunction, 1 - ravinFunction).
	 * Возвращает вектор из существующих вариантов
	 */
	QVector<int> AnalysisDirVariants(const int typeFunction);

	//! Инициализация выпадающего списка варинтов для квадратичной функции.
	/*! В своей работе использует метод AnalysisDirVariants(const int typeFunction).
	 * Заполняет выпадающий список существующими вариантами и добавляет последний пустой.
	 */
	void initializationQuadComboBox();

	//! Инициализация выпадающего списка варинтов для овражной функции.
	/*! В своей работе использует метод AnalysisDirVariants(const int typeFunction).
	 * Заполняет выпадающий список существующими вариантами и добавляет последний пустой.
	 */
	void initializationRavinComboBox();

public:
	//! Конструктор класса.
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );

private slots:
	//! Слот класса, получающий сигнал при выборе варианта овражной функции.
	/*! В своей работе использует метод ReadVariants(const int typeFunction, const int numberVariants).
	 * Заполняет lineEdit-ы данными варианта.
	 */
	void on_comboBox_ravin_activated(int index);

	//! Слот класса, получающий сигнал при выборе варианта квадратичной функции.
	/*! В своей работе использует метод ReadVariants(const int typeFunction, const int numberVariants).
	 * Заполняет lineEdit-ы данными варианта.
	 */
	void on_comboBox_activated(int index);

	//! Слот класса, получающий сигнал при нажатии кнопки "Сохранить" в овражной функции.
	/*! В своей работе использует методы WriteVariants(const int typeFunction, const QVector<double> data) и initializationRavinComboBox().
	 * Считывает данные из формы и записывает в файл.
	 * При окончании работы выводит надпись об успешной записи или неудачи в statusBar.
	 */
	void on_save_button_ravin_clicked();

	//! Слот класса, получающий сигнал при нажатии кнопки "Сохранить" в квадратичной функции.
	/*! В своей работе использует методы WriteVariants(const int typeFunction, const QVector<double> data) и initializationQuadComboBox().
	 * Считывает данные из формы и записывает в файл.
	 * При окончании работы выводит надпись об успешной записи или неудачи в statusBar.
	 */
	void on_save_button_clicked();
};
#endif