#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QVariant>
#include <QMessageBox>

#include "funkcio.h"
#include "Konstantoj.h"

#include "cwdescentwinimpl.h"
//#include "CWdescent_mdImpl.h"
//#include "FasterDescentImpl.h"
//#include "HuGiImpl.h"
//#include "NeMiImpl.h"
//#include "NotWeNImpl.h"

#include "ui_mainwindow.h"

class AlgoritmoWin;
class funkcio;

//
//! Производный класс от класса главной формы приложения optimizationmethods.
/*! Предназначен для выбора метода оптимизации и целевой функции, а также выбора варианта.
 * @author Проскурин Александр Викторович
 * @file mainwindowimpl.h
 */
class MainWindowImpl : public QStackedWidget, public Ui::MainWindow
{
Q_OBJECT

	//! Флаг для проверки пройдености квадратичной функции.
	bool takeQuadFun;
	
	//! Объект-родитель для создания окон прохождения алгоритмов.
	AlgoritmoWin *AW;

	//! Индексы метода и типа функции.
	QVector<int> methFunc;

private:
	//! Чтение данных варианта из текстового файла.
	/*! В качестве аргументов принимает:
	 * typeFunction - индекс целевой функции (0 - quadFunction, 1 - ravinFunction);
	 * numberVariants - номер варианта.
	 * Возвращает вектор данных варианта при успешном чтении и вектор с нулевыми значениями в остальных случаях.
	 */
	QVector<double> ReadVariants(const int typeFunction, const int numberVariants);

	//! Анализ директории вариантов целевой функции.
	/*! В качестве аргумента принимает:
	 * typeFunction - индекс целевой функции (0 - quadFunction, 1 - ravinFunction).
	 * Возвращает вектор из существующих вариантов
	 */
	QVector<int> AnalysisDirVariants(const int typeFunction);

	//! Инициализация выпадающего списка варинтов.
	/*! В своей работе использует метод AnalysisDirVariants(const int typeFunction).
	 * Заполняет выпадающий список существующими вариантами.
	 */
	void initializationComboBox(const int typeFunction);
	
public:
	//! Конструктор класса.
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );

private slots:
	//! Слот класса, получающий сигнал при нажатии на кнопку "Далее" (1-ая страница).
	/*! В начале считывает в поле methFunc индекс метода оптимизации и индекс типа функции,
	 * а затем делает видимой вторую страницу формы.
	 */
	void on_next_button_clicked();

	//! Слот класса, получающий сигнал при нажатии кнопки "Далее" (2-ая страница).
	/*! Считывает данные варианта из файла,
	 * создает объект целевого класса и объект формы метода оптимизации
	 */
	void on_next_button_2_clicked();

	//! Слот класса, получающий сигнал при нажатии кнопки "Назад" (2-ая страница)
	void on_back_button_clicked();

	//! Слот класса, получающий сигнал при выборе варианта функции.
	/*! В своей работе использует метод ReadVariants(const int typeFunction, const int numberVariants).
	 * Заполняет lineEdit-ы данными варианта.
	 */
	void on_comboBox_activated(int index);
};
#endif




