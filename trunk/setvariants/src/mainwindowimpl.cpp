#include "mainwindowimpl.h"
//
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{
	setupUi(this);
	
	initializationQuadComboBox();
	on_comboBox_activated(0);
	initializationRavinComboBox();
	on_comboBox_ravin_activated(0);
	initializationError();
}

//! Запись данных варианта в текстовый файл.
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

//! Запись данных варианта в текстовый файл.
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

//! Запись максимального количества ошибок для перехода к овражной функции в текстовый файл.
bool MainWindowImpl::WriteError(const QVector<int> data)
{
	QFile file(QDir::toNativeSeparators("variants/maxError"));
	if(file.open(QIODevice::WriteOnly))
	{
		QTextStream stream(&file);
		for(int i = 0; i < 6; ++i)
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

//! Запись пароля для разблокирования овражной функции в текстовый файл.
bool MainWindowImpl::WritePass(const QByteArray data)
{
	QFile file(QDir::toNativeSeparators("variants/ps"));
	if(file.open(QIODevice::WriteOnly))
	{
		QTextStream stream(&file);
		stream.setCodec("UTF-8");
		stream<<data;
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

//! Чтение данных варианта из текстового файла.
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
	else
		data.fill(NULL, 13);
	return data;
}

//! Чтение данных варианта из текстового файла.
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
	else
		data.fill(NULL, 13);
	return data;
}

//! Чтение максимального количества ошибок для перехода к овражной функции из текстового файла.
QVector<int> MainWindowImpl::ReadError()
{
	QVector<int> data(0);
	QFile file(QDir::toNativeSeparators("variants/maxError"));
	if(file.open(QIODevice::ReadOnly))
	{
		QTextStream stream(&file);
		while(!stream.atEnd())
		{
			data.append(stream.readLine().toInt());
		}
	}
	else
		data.fill(NULL, 6);
	return data;
}

//! Чтение пароля для разблокирования овражной функции из текстового файла.
QByteArray MainWindowImpl::ReadPass()
{
	QByteArray data;
	QFile file(QDir::toNativeSeparators("variants/ps"));
	if(file.open(QIODevice::ReadOnly))
	{
		QTextStream stream(&file);
		stream.setCodec("UTF-8");
		data.append(stream.readAll());
	}
	else
		data.fill(NULL);
	return data;
}

//! Анализ директории вариантов целевой функции.
QVector<int> MainWindowImpl::AnalysisDirVariants(const QString typeFunction)
{
	QVector<int> variants(0);
	QDir dir(QDir::toNativeSeparators("variants/" + typeFunction));
	QStringList listFiles = dir.entryList(QDir::Files);
	foreach(QString str, listFiles)
	{
		variants.append(str.toInt());
	}
	return variants;
}

//! Анализ директории вариантов целевой функции.
QVector<int> MainWindowImpl::AnalysisDirVariants(const int typeFunction)
{
	QVector<int> variants(0);
	QString path;
	switch (typeFunction)
	{
		case 0:
			path = "variants/quadFunction/";
			break;
		case 1:
			path = "variants/ravinFunction/";
	}
	QDir dir(QDir::toNativeSeparators(path));
	QStringList listFiles = dir.entryList(QDir::Files);
	foreach(QString str, listFiles)
	{
		variants.append(str.toInt());
	}
	return variants;
}

//! Инициализация выпадающего списка варинтов для квадратичной функции.
void MainWindowImpl::initializationQuadComboBox()
{
	QVector<int> data;
	QVariant var;
	data = AnalysisDirVariants(0);
	foreach(int i, data)
	{
		var.setValue(i);
		comboBox->addItem(trUtf8("Вариант ").append(QString::number(i + 1)), var);
	}
	comboBox->addItem(trUtf8("Вариант ").append(QString::number(data.size() + 1)));
}

//! Инициализация выпадающего списка варинтов для овражной функции.
void MainWindowImpl::initializationRavinComboBox()
{
	QVector<int> data_ravin;
	QVariant var;
	data_ravin = AnalysisDirVariants(1);
	foreach(int i, data_ravin)
	{
		var.setValue(i);
		comboBox_ravin->addItem(trUtf8("Вариант ").append(QString::number(i + 1)), var);
	}
	comboBox_ravin->addItem(trUtf8("Вариант ").append(QString::number(data_ravin.size() + 1)));
}

//! Инициализация формы для количества ошибок.
void MainWindowImpl::initializationError()
{
	QVector<int> data;
	data = ReadError();
	CWdescent_fix->setText(QString::number(data[0]));
	CWdescent_md->setText(QString::number(data[1]));
	FasterDescent->setText(QString::number(data[2]));
	HuGi->setText(QString::number(data[3]));
	NeMi->setText(QString::number(data[4]));
	NotWen->setText(QString::number(data[5]));
}

//
// Нажата кнопка сохранить в квадратичной функции.
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
	if(WriteVariants(0, data))
	{
		comboBox->clear();
		initializationQuadComboBox();
		on_comboBox_activated(data[0]);
		statusbar->showMessage(trUtf8("Вариант успешно записан"), 1000);
	}
	else
		statusbar->showMessage(trUtf8("Ошибка при записи - возможно отсутствует директория"), 2000);
}

// Нажата кнопка сохранить в овражной функции.
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
	if(WriteVariants(1, data))
	{
		comboBox_ravin->clear();
		initializationRavinComboBox();
		on_comboBox_ravin_activated(data[0]);
		statusbar->showMessage(trUtf8("Вариант успешно записан"), 1000);
	}
	else
		statusbar->showMessage(trUtf8("Ошибка при записи - возможно отсутствует директория"), 2000);
}

//! Нажата кнопка сохранить при установке количества ошибок.
void MainWindowImpl::on_save_button_err_clicked()
{
	// TODO
	QVector<int> data(6);
	data[0] = CWdescent_fix->text().toInt();
	data[1] = CWdescent_md->text().toInt();
	data[2] = FasterDescent->text().toInt();
	data[3] = HuGi->text().toInt();
	data[4] = NeMi->text().toInt();
	data[5] = NotWen->text().toInt();
	if(WriteError(data))
	{
		initializationError();
		statusbar->showMessage(trUtf8("Информация успешно записана"), 1000);
	}
	else
		statusbar->showMessage(trUtf8("Ошибка при записи - возможно отсутствует директория"), 2000);
}

//! нажата кнопки "Сохранить" при установке пароля.
void MainWindowImpl::on_save_button_pass_clicked()
{
	// TODO
	QByteArray passInEdit = QCryptographicHash::hash(oldPass->text().toUtf8(), QCryptographicHash::Md5);
	
	if(ReadPass() == passInEdit || ReadPass() == "")
	{
		if(newPass->text() == newPassRep->text())
		{
			if(WritePass(QCryptographicHash::hash(newPass->text().toUtf8(), QCryptographicHash::Md5)))
			{
				statusbar->showMessage(trUtf8("Информация успешно записана"), 1000);
				oldPass->setText("");
				newPass->setText("");
				newPassRep->setText("");
			}
			else
				statusbar->showMessage(trUtf8("Ошибка при записи - возможно отсутствует директория"), 2000);
		}
		else
			statusbar->showMessage(trUtf8("Введеные новый пароль и его повтор не совпадают"), 2000);
	}
	else
		statusbar->showMessage(trUtf8("Введеный старый пароль не верен"), 2000);
}

// Выбран существующий вариант в квадратичной функции.
void MainWindowImpl::on_comboBox_activated(int index)
{
	// TODO
	QVector<double> data(13);
	data = ReadVariants(0, index);
	if(AnalysisDirVariants(0).size() > index)
	{
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
	else
	{
		a->setText("");
		b->setText("");
		c->setText("");
		d->setText("");
		e->setText("");
		f->setText("");
		g->setText("");
		accuracy->setText("");
		stepx1->setText("");
		stepx2->setText("");
		stepChange->setText("");
		x1->setText("");
		x2->setText("");
	}
}

// Выбран существующий вариант в овражной функции.
void MainWindowImpl::on_comboBox_ravin_activated(int index)
{
	// TODO
	QVector<double> data(8);
	data = ReadVariants(1, index);
	if(AnalysisDirVariants(1).size() > index)
	{
		a_ravin->setText(QString::number(data[0]));
		b_ravin->setText(QString::number(data[1]));
		accuracy_ravin->setText(QString::number(data[2]));
		stepx1_ravin->setText(QString::number(data[3]));
		stepx2_ravin->setText(QString::number(data[4]));
		stepChange_ravin->setText(QString::number(data[5]));
		x1_ravin->setText(QString::number(data[6]));
		x2_ravin->setText(QString::number(data[7]));
	}
	else
	{
		a_ravin->setText("");
		b_ravin->setText("");
		accuracy_ravin->setText("");
		stepx1_ravin->setText("");
		stepx2_ravin->setText("");
		stepChange_ravin->setText("");
		x1_ravin->setText("");
		x2_ravin->setText("");
	}
}


