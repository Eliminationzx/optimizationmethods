#include "mainwindowimpl.h"
//
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{
	setupUi(this);
}

//! Запись данных варианта в текстовый файл
bool MainWindowImpl::WriteVariants(const QString typeFunction, const QVector<double> data)
{
	QFile file(QDir::toNativeSeparators("variants/" + typeFunction + "/" + QString::number(data[0])));
	if(file.open(QIODevice::WriteOnly))
	{
		QTextStream stream(&file);
		for(int i = 1; i < data.size(); ++i)
		{
			stream<<data[i]<<"\n";
		}
		if(stream.status() != QTextStream::Ok)
		{
			file.close();
			return false;
		}
		else
		{
			file.close();
			return true;
		}
	}
	else
		return false;
}

//! Запись данных варианта в текстовый файл
bool MainWindowImpl::WriteVariants(const int typeFunction, const QVector<double> data)
{
	QString path;
	switch (typeFunction)
	{
		case 0:
			path = "variants/quadFunction/";
			break;
		case 1:
			path = "variants/ravinFunction/";
	}
	QFile file(QDir::toNativeSeparators(path + QString::number(data[0])));
	if(file.open(QIODevice::WriteOnly))
	{
		QTextStream stream(&file);
		for(int i = 1; i < data.size(); ++i)
		{
			stream<<data[i]<<"\n";
		}
		if(stream.status() != QTextStream::Ok)
		{
			file.close();
			return false;
		}
		else
		{
			file.close();
			return true;
		}
	}
	else
		return false;
}

//! Чтение данных варианта из текстового файла
QVector<double> MainWindowImpl::ReadVariants(const QString typeFunction, const int numberVariants)
{
	QVector<double> data(0);
	QFile file(QDir::toNativeSeparators("variants/" + typeFunction + "/" + QString::number(numberVariants)));
	if(file.open(QIODevice::ReadOnly))
	{
		QTextStream stream(&file);
		while(!stream.atEnd())
		{
			data.append(stream.readLine().toDouble());
		}
	}
	return data;
}

//! Чтение данных варианта из текстового файла
QVector<double> MainWindowImpl::ReadVariants(const int typeFunction, const int numberVariants)
{
	QVector<double> data(0);
	QString path;
	switch (typeFunction)
	{
		case 0:
			path = "variants/quadFunction/";
			break;
		case 1:
			path = "variants/ravinFunction/";
	}
	QFile file(QDir::toNativeSeparators(path + QString::number(numberVariants)));
	if(file.open(QIODevice::ReadOnly))
	{
		QTextStream stream(&file);
		while(!stream.atEnd())
		{
			data.append(stream.readLine().toDouble());
		}
	}
	return data;
}

//
// Нажата кнопка сохранить в квадратичной функции
void MainWindowImpl::on_save_button_clicked()
{
	// TODO
	QVector<double> data(14);
	data[0] = comboBox->currentIndex();
	data[1] = a->text().toDouble();
	data[2] = b->text().toDouble();
	data[3] = c->text().toDouble();
	data[4] = d->text().toDouble();
	data[5] = e->text().toDouble();
	data[6] = f->text().toDouble();
	data[7] = g->text().toDouble();
	data[8] = accuracy->text().toDouble();
	data[9] = stepx1->text().toDouble();
	data[10] = stepx2->text().toDouble();
	data[11] = stepChange->text().toDouble();
	data[12] = x1->text().toDouble();
	data[13] = x2->text().toDouble();
	WriteVariants(0, data);
//	if(WriteVariants(0, data))
//		QStatusBar::showMessage("Вариант записан", 250);
}

// Нажата кнопка сохранить в овражной функции
void MainWindowImpl::on_save_button_ravin_clicked()
{
	// TODO
	QVector<double> data(9);
	data[0] = comboBox_ravin->currentIndex();
	data[1] = a_ravin->text().toDouble();
	data[2] = b_ravin->text().toDouble();
	data[3] = accuracy_ravin->text().toDouble();
	data[4] = stepx1_ravin->text().toDouble();
	data[5] = stepx2_ravin->text().toDouble();
	data[6] = stepChange_ravin->text().toDouble();
	data[7] = x1_ravin->text().toDouble();
	data[8] = x2_ravin->text().toDouble();
	WriteVariants(1, data);
}

// Выбран существующий вариант в квадратичной функции
void MainWindowImpl::on_comboBox_activated(int index)
{
	// TODO
	QVector<double> data(13);
	data = ReadVariants(0, index);
	a->setText(QString::number(data[0]));
	b->setText(QString::number(data[1]));
	c->setText(QString::number(data[2]));
	d->setText(QString::number(data[3]));
	e->setText(QString::number(data[4]));
	f->setText(QString::number(data[5]));
	g->setText(QString::number(data[6]));
	accuracy->setText(QString::number(data[7]));
	stepx1->setText(QString::number(data[8]));
	stepx2->setText(QString::number(data[9]));
	stepChange->setText(QString::number(data[10]));
	x1->setText(QString::number(data[11]));
	x2->setText(QString::number(data[12]));
}

// Выбран существующий вариант в овражной функции
void MainWindowImpl::on_comboBox_ravin_activated(int index)
{
	// TODO
	QVector<double> data(8);
	data = ReadVariants(1, index);
	a_ravin->setText(QString::number(data[0]));
	b_ravin->setText(QString::number(data[1]));
	accuracy_ravin->setText(QString::number(data[2]));
	stepx1_ravin->setText(QString::number(data[3]));
	stepx2_ravin->setText(QString::number(data[4]));
	stepChange_ravin->setText(QString::number(data[5]));
	x1_ravin->setText(QString::number(data[6]));
	x2_ravin->setText(QString::number(data[7]));
}
