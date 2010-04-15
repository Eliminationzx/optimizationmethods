#include "mainwindowimpl.h"
//
//! Конструктор класса.
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) 
	: QStackedWidget(parent)
{
	setupUi(this);
	
	takeQuadFun = false;
	
	QVariant var;
	var.setValue(0);
	choiceMethods->addItem(trUtf8("Метод покоординатного спуска с дискретным шагом"), var);
	var.setValue(1);
	choiceMethods->addItem(trUtf8("Метод покоординатного спуска с минимизацией по направлению"), var);
	var.setValue(2);
	choiceMethods->addItem(trUtf8("Метод наискорейшего спуска"), var);
	var.setValue(3);
	choiceMethods->addItem(trUtf8("Метод Хука-Дживса"), var);
	var.setValue(4);
	choiceMethods->addItem(trUtf8("Метод Нелдера-Мида"), var);
	var.setValue(5);
	choiceMethods->addItem(trUtf8("Метод Ньютона"), var);
	choiceMethods->setCurrentIndex(0);
	
	ravinFunction->setCheckable(false);
}
//

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

//! Инициализация выпадающего списка варинтов.
void MainWindowImpl::initializationComboBox(const int typeFunction)
{
	QVector<int> data;
	QVariant var;
	data = AnalysisDirVariants(typeFunction);
	foreach(int i, data)
	{
		var.setValue(i);
		comboBox->addItem(trUtf8("Вариант ").append(QString::number(i + 1)), var);
	}
}

//! Нажата кнопка "Далее" (1-ая страница).
void MainWindowImpl::on_next_button_clicked()
{
	// TODO
	methFunc.append(choiceMethods->currentIndex());
	if(quadFunction->isChecked())
	{
		methFunc.append(0);
		
		this->setCurrentIndex(1);
	}
	else if(ravinFunction->isChecked())
	{
		methFunc.append(1);
		
		c->setVisible(false);
		d->setVisible(false);
		e->setVisible(false);
		f->setVisible(false);
		g->setVisible(false);
		label_4->setVisible(false);
		label_5->setVisible(false);
		label_6->setVisible(false);
		label_7->setVisible(false);
		label_8->setVisible(false);
		
		this->setCurrentIndex(1);
	}
	
	initializationComboBox(methFunc[1]);

	on_comboBox_activated(0);
}

//! Нажата кнопка "Далее" (2-ая страница).
void MainWindowImpl::on_next_button_2_clicked()
{
	// TODO
	QVector<double> data;
	funkcio * funck;
	if(methFunc[1] == 0)
	{
		data = ReadVariants(methFunc[1], comboBox->currentIndex());
		funck = new KvadratigantoFunkcio(data);
	}
	else if(methFunc[1] == 1)
	{
		data = ReadVariants(methFunc[1], comboBox->currentIndex());
		funck = new RavinaFunkcio(data);
	}
	QVector<double> simpleCon = data.mid(data.size()-6);
	
	switch(methFunc[0])
	{
		case A::CWdescent_fix:
			AW = new CWdescentWinImpl(funck, &simpleCon, this, Qt::Window);
			break;
		case A::CWdescent_md:
//			
//			break;
		case A::FasterDescent:
//			AW = new 
//			break;
		case A::HuGi:
//			AW = new 
//			break;
		case A::NeMiImpl:
//			AW = new 
//			break;
		case A::NotWen:
//			AW = new 
      QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Алгоритм ещё не реализован"));
      msg.exec();
	}
	AW->showMaximized();
}

//! Нажата кнопка "Назад" (2-ая страница).
void MainWindowImpl::on_back_button_clicked()
{
	// TODO
	this->setCurrentIndex(0);
}

//! Выбран вариант функции.
void MainWindowImpl::on_comboBox_activated(int index)
{
	// TODO
	if(methFunc[1] == 0)
	{
		QVector<double> data(13);
		data = ReadVariants(methFunc[0], index);
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
	else if(methFunc[1] == 1)
	{
		QVector<double> data(8);
		data = ReadVariants(methFunc[0], index);
		a->setText(QString::number(data[0]));
		b->setText(QString::number(data[1]));
		accuracy->setText(QString::number(data[2]));
		stepx1->setText(QString::number(data[3]));
		stepx2->setText(QString::number(data[4]));
		stepChange->setText(QString::number(data[5]));
		x1->setText(QString::number(data[6]));
		x2->setText(QString::number(data[7]));
	}
}
