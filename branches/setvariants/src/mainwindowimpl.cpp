#include "mainwindowimpl.h"
//
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{
	setupUi(this);
}

//! Запись данных варианта в текстовый файл
bool MainWindowImpl::WriteVariants(const QString typeFunction, const QVector<QString> data)
{
	QFile file(QDir::toNativeSeparators("variants/" + typeFunction + "/" + data[0]));
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
bool MainWindowImpl::WriteVariants(const int typeFunction, const QVector<QString> data)
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
	QFile file(QDir::toNativeSeparators(path + data[0]));
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
QVector<QString> ReadVariants(const QString typeFunction, const int numberVariants)
{
	QVector<QString> data(0);
	QFile file(QDir::toNativeSeparators("variants/" + typeFunction + "/" + QString::number(numberVariants)));
	if(file.open(QIODevice::ReadOnly))
	{
		QTextStream stream(&file);
		while(!stream.atEnd())
		{
			data.append(stream.readLine());
		}
	}
	return data;
}

//! Чтение данных варианта из текстового файла
QVector<QString> ReadVariants(const int typeFunction, const int numberVariants)
{
	QVector<QString> data(0);
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
			data.append(stream.readLine());
		}
	}
	return data;
}

//
// Нажата кнопка сохранить в квадратичной функции
void MainWindowImpl::on_save_button_clicked()
{
	// TODO
	QVector<QString> data(14);
	data[0] = QString::number(comboBox->currentIndex());
	data[1] = a->text();
	data[2] = b->text();
	data[3] = c->text();
	data[4] = d->text();
	data[5] = e->text();
	data[6] = f->text();
	data[7] = g->text();
	data[8] = accuracy->text();
	data[9] = stepx1->text();
	data[10] = stepx2->text();
	data[11] = stepChange->text();
	data[12] = x1->text();
	data[13] = x2->text();
	WriteVariants(0, data);
//	if(WriteVariants(0, data))
//		QStatusBar::showMessage("Вариант записан", 250);
}

// Нажата кнопка сохранить в овражной функции
void MainWindowImpl::on_save_button_ravin_clicked()
{
	// TODO
	QVector<QString> data(9);
	data[0] = QString::number(comboBox_ravin->currentIndex());
	data[1] = a_ravin->text();
	data[2] = b_ravin->text();
	data[3] = accuracy_ravin->text();
	data[4] = stepx1_ravin->text();
	data[5] = stepx2_ravin->text();
	data[6] = stepChange_ravin->text();
	data[7] = x1_ravin->text();
	data[8] = x2_ravin->text();
	WriteVariants(1, data);
}
