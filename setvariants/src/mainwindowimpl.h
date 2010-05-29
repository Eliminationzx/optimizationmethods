#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QVariant>
#include <QCryptographicHash>
#include "HelpBrowser.h"
#include "aboutprogramimpl.h"
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
	/*! Возвращает true при успешной записи и false в остальных случаях.
	 * @param typeFunction - название целевой функции (quadFunction или ravinFunction);
	 * @param data - вектор данных варианта, первым элементом которого является номер варианта.
	 */
	bool WriteVariants(const QString typeFunction, const QVector<double> data);

	//! Запись данных варинта в текстовый файл.
	/*! Возвращает true при успешной записи и false в остальных случаях.
	 * @param typeFunction - индекс целевой функции (0 - quadFunction, 1 - ravinFunction);
	 * @param data - вектор данных варианта, первым элементом которого является номер варианта.
	 */
	bool WriteVariants(const int typeFunction, const QVector<double> data);

	//! Запись максимального количества ошибок для перехода к овражной функции в текстовый файл.
	/*! Возвращает true при успешной записи и false в остальных случаях.
	 * @param data - вектор количества ошибок.
	 */
	bool WriteError(const QVector<int> data);

	//! Запись пароля для разблокирования овражной функции в текстовый файл.
	/*! Возвращает true при успешной записи и false в остальных случаях.
	 * @param data - хэш из строки с паролем.
	 */
	bool WritePass(const QByteArray data);

	//! Чтение данных варианта из текстового файла.
	/*! Возвращает вектор данных варианта при успешном чтении и вектор с нулевыми значениями в остальных случаях.
	 * @param typeFunction - название целевой функции (quadFunction или ravinFunction);
	 * @param numberVariants - номер варианта.
	 */
	 QVector<double> ReadVariants(const QString typeFunction, const int numberVariants);

	//! Чтение данных варианта из текстового файла.
	/*! Возвращает вектор данных варианта при успешном чтении и вектор с нулевыми значениями в остальных случаях.
	 * @param typeFunction - индекс целевой функции (0 - quadFunction, 1 - ravinFunction);
	 * @param numberVariants - номер варианта.
	 */
	QVector<double> ReadVariants(const int typeFunction, const int numberVariants);
	
	//! Чтение максимального количества ошибок для перехода к овражной функции из текстового файла.
	/*! Возвращает вектор количества ошибок при успешном чтении и вектор с нулевыми значениями в остальных случаях.
	 */
	QVector<int> ReadError();

	//! Чтение пароля для разблокирования овражной функции из текстового файла.
	/*! Возвращает строку с хэшем пароля при успешном чтении или ноль в остальных случаях.
	 */
	QByteArray ReadPass();

	//! Анализ директории вариантов целевой функции.
	/*! Возвращает вектор из существующих вариантов.
	 * @param typeFunction - название целевой функции (quadFunction или ravinFunction).
	 */
	QVector<int> AnalysisDirVariants(const QString typeFunction);

	//! Анализ директории вариантов целевой функции.
	/*! Возвращает вектор из существующих вариантов.
	 * @param typeFunction - индекс целевой функции (0 - quadFunction, 1 - ravinFunction).
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
	
	//! Инициализация формы для количества ошибок.
	/*! В своей работе использует метод ReadError().
	 * Заполняет форму.
	 */
	void initializationError();

public:
	//! Конструктор класса.
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );

private slots:
	//! Слот класса, получающий сигнал при выборе пункта меню "О программе".
	/*! Выводит форму с данными о программе и об авторах.
	 * Страница с текстом лицензии лежит во вложенной папке doc.
	 */
	void on_about_activated();

	//! Слот класса, получающий сигнал при выборе пункта меню "Справка".
	/*! Выводит справку в браузерном окне.
	 * Страница со справкой лежит во вложенной папке doc.
	 */
	void on_help_activated();

	//! Слот класса, получающий сигнал при нажатии кнопки "Сохранить" при установке пароля.
	/*! В своей работе использует метод WritePass(const QByteArray data).
	 * Считывает данные из формы и записывает в файл.
	 * При окончании работы выводит надпись об успешной записи или неудачи в statusBar.
	 */
	void on_save_button_pass_clicked();

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

	//! Слот класса, получающий сигнал при нажатии кнопки "Сохранить" при установке количества ошибок.
	/*! В своей работе использует метод WriteError(const QVector<double> data).
	 * Считывает данные из формы и записывает в файл.
	 * При окончании работы выводит надпись об успешной записи или неудачи в statusBar.
	 */
	void on_save_button_err_clicked();

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
