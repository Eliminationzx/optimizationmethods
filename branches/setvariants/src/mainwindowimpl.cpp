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
	file.open(QIODevice::WriteOnly);
	QTextStream stream(&file);
	for(int i = 1; i < data.size(); ++i)
	{
		stream<<data[i]<<" ";
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
			break;
	}
	QFile file(QDir::toNativeSeparators(path + QString::number(data[0])));
	file.open(QIODevice::WriteOnly);
	QTextStream stream(&file);
	for(int i = 1; i < data.size(); ++i)
	{
		stream<<data[i]<<" ";
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

//
