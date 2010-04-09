#include "getvariantsImpl.h"
#include "Konstantoj.h"
#include <QMessageBox>
#include "cwdescentwinimpl.h"
//
getvariantsImpl::getvariantsImpl(QVector<int> data, QWidget * parent, Qt::WFlags z) 
	: QMainWindow(parent, z)
{
	setupUi(this);
	
	methFunc = data;
	
	if(methFunc[1] == 1)
	{
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
	}
	
	initializationComboBox(methFunc[1]);
	on_comboBox_activated(0);
}

//! Чтение данных варианта из текстового файла.
QVector<double> getvariantsImpl::ReadVariants(const int typeFunction, const int numberVariants)
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
QVector<int> getvariantsImpl::AnalysisDirVariants(const int typeFunction)
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
void getvariantsImpl::initializationComboBox(const int typeFunction)
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

//! Выбран вариант функции.
void getvariantsImpl::on_comboBox_activated(int index)
{
	// TODO
	if(methFunc[1] == 0)
	{
		QVector<double> data(13);
		data = ReadVariants(methFunc[1], index);
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
		data = ReadVariants(methFunc[1], index);
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

//! Нажата кнопка "Далее".
void getvariantsImpl::on_next_button_clicked()
{
	// TODO
	QVector<double> data;
	if(methFunc[1] == 0)
	{
		data = ReadVariants(methFunc[1], comboBox->currentIndex());
		funkcio * funck = new KvadratigantoFunkcio(data);
	}
	else if(methFunc[1] == 1)
	{
		data = ReadVariants(methFunc[1], comboBox->currentIndex());
		funkcio * funck = new RavinaFunkcio(data);
	}
	QVector<double> simpleCon = data.mid(data.size()-6);
	
	switch(methFunc[0])
	{
		case A::CWdescent_fix:
//			AW = new CWdescentWinImpl(указатель на фукцию, вектор с данными, this, Qt::Window);
//			break;
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
  AW->show();

}
