#ifndef GETVARIANTSIMPL_H
#define GETVARIANTSIMPL_H
//
#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QVariant>
#include "ui_getvariants.h"
//
//! Производный класс от класса формы выбора варианта приложения optimizationmethods.
/*! Предназначен для выбора варианта целевой функции и предоставления модулям объекта функции.
 * @author Проскурин Александр Викторович
 * @file mainwindowimpl.h
 */
class getvariantsImpl : public QMainWindow, public Ui::getvariants
{
Q_OBJECT

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
	/*! В класс передается вектор, состоящий из двух элементов:
	 * data[0] - индекс метода оптимизации;
	 * data[1] - индекс целевой функции. 
	 */
	getvariantsImpl(QVector<int> data, QWidget * parent = 0, Qt::WFlags f = 0 );
	
private slots:
	//! Слот класса, получающий сигнал при выборе варианта функции.
	/*! В своей работе использует метод ReadVariants(const int typeFunction, const int numberVariants).
	 * Заполняет lineEdit-ы данными варианта.
	 */
	void on_comboBox_activated(int index);
};
#endif





