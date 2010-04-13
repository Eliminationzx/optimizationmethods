#ifndef GETVARIANTSIMPL_H
#define GETVARIANTSIMPL_H
//
#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QVariant>
#include "funkcio.h"
#include "cwdescentwinimpl.h"
/*#include "CWdescent_mdImpl.h"
#include "FasterDescentImpl.h"
#include "HuGiImpl.h"
#include "NeMiImpl.h"
#include "NotWeNImpl.h"
*/
#include "ui_getvariants.h"
class AlgoritmoWin;
class funkcio;
//
//! Производный класс от класса формы выбора варианта приложения optimizationmethods.
/*! Предназначен для выбора варианта целевой функции и предоставления модулям объекта функции.
 * @author Александр Викторович Проскурин
 * @file mainwindowimpl.h
 */
class getvariantsImpl : public QMainWindow, public Ui::getvariants
{
Q_OBJECT

private:
  //! Окно прохождения алгоритма.
  AlgoritmoWin *AW;
	QVector<int> methFunc;
	
	//! Указатель на объект формы метода покоординатного спуска с дискрентым шагом
	//CWdescent_fixImpl * CWDF;
	//! Указатель на объект формы метода покоординатного спуска с минимизацией п направлению
	//CWdescent_mdImpl * CWDM;
	//! Указатель на объект формы метода наискорейшего спуска
	//FasterDescentImpl * FS;
	//! Указатель на объект формы метода Хука-Дживса
	//HuGiImpl * HG;
	//! Указатель на объект формы метода Нелдера-Мида
	//NeMiImpl * NM;
	//! Указатель на объект формы метода Ньютона
//NotWeNImpl * N;

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
	//! Слот класса, получающий сигнал при нажатии кнопки "Далее".
	/*! Считывает данные варианта из файла,
	 * создает объект целевого класса и объект формы метода оптимизации
	 */
	void on_next_button_clicked();

	//! Слот класса, получающий сигнал при выборе варианта функции.
	/*! В своей работе использует метод ReadVariants(const int typeFunction, const int numberVariants).
	 * Заполняет lineEdit-ы данными варианта.
	 */
	void on_comboBox_activated(int index);
};
#endif
