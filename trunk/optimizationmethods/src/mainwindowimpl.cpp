#include "mainwindowimpl.h"
//
//! Конструктор класса.
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{
	setupUi(this);
	
	methFunc.append(0);
	methFunc.append(0);
	
	stackedWidget->setCurrentIndex(0);
	
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
	
	for(int i = 0; i < 6; ++i)
	{
		takeQuadFun[i] = false;
	}
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

//! Чтение максимального количества ошибок для перехода к овражной функции из текстового файла.
int MainWindowImpl::ReadError(int method)
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
	return data[method];
}

//! Открытие овражной функции.
void MainWindowImpl::openTakeQuadFun(int flag)
{
	takeQuadFun[flag] = ravinFunction->isChecked() - 1;
	choiceMethods->setCurrentIndex(flag);
	on_choiceMethods_activated(flag);
	quadFunction->setChecked(ravinFunction->isChecked());
	ravinFunction->setChecked(ravinFunction->isChecked() - 1);
}

//! Нажата кнопка "Далее" (1-ая страница).
void MainWindowImpl::on_next_button_clicked()
{
	// TODO
	methFunc[0] = choiceMethods->currentIndex();
	if(quadFunction->isChecked())
	{
		methFunc[1] = 0;
		
		c->setVisible(true);
		d->setVisible(true);
		e->setVisible(true);
		f->setVisible(true);
		g->setVisible(true);
		label_4->setVisible(true);
		label_5->setVisible(true);
		label_6->setVisible(true);
		label_7->setVisible(true);
		label_8->setVisible(true);
		
		stackedWidget->setCurrentIndex(1);
		QPixmap icon(":icon/quadFunc.bmp");
		func->setPixmap(icon);
	}
	else if(ravinFunction->isChecked())
	{
		methFunc[1] = 1;
		
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
		
		stackedWidget->setCurrentIndex(1);
		QPixmap icon(":icon/ravinFunc.bmp");
		func->setPixmap(icon);
	}
	
	on_choiceVar_clicked(true);
	initializationComboBox(methFunc[1]);
}

//! Нажата кнопка "Далее" (2-ая страница).
void MainWindowImpl::on_next_button_2_clicked()
{
	// TODO
	QVector<double> data(7);
	data[0] = accuracy->text().toDouble();
	data[1] = stepx1->text().toDouble();
	data[2] = stepx2->text().toDouble();
	data[3] = stepChange->text().toDouble();
	data[4] = x1->text().toDouble();
	data[5] = x2->text().toDouble();
	data[6] = ReadError(methFunc[0]);
	
	funkcio * funck;
	if(methFunc[1] == 0)
	{
		QVector<double> koef(7);
		koef[0] = a->text().toDouble();
		koef[1] = b->text().toDouble();
		koef[2] = c->text().toDouble();
		koef[3] = d->text().toDouble();
		koef[4] = e->text().toDouble();
		koef[5] = f->text().toDouble();
		koef[6] = g->text().toDouble();
		
		funck = new KvadratigantoFunkcio(koef);
	}
	else if(methFunc[1] == 1)
	{
		QVector<double> koef(2);
		koef[0] = a->text().toDouble();
		koef[1] = b->text().toDouble();
		
		funck = new RavinaFunkcio(koef);
	}

	switch(methFunc[0])
	{
		case A::CWdescent_fix:
			AW = new CWdescentWinImpl(funck, &data, this, Qt::Window);
			break;
		case A::CWdescent_md:
			AW = new CWdescent_mdImpl(funck, &data, this, Qt::Window);
			break;
		case A::FasterDescent:
			AW = new FasterDescentImpl(funck, &data, this, Qt::Window);
			break;
		case A::HuGi:
//			AW = new HuGiImpl(funck, &data, this, Qt::Window);
//			break;
		case A::NeMi:
			AW = new NeMiImpl(funck, &data, this, Qt::Window);
			break;
		case A::NotWen:
			AW = new NotWenImpl(funck, &data, this, Qt::Window);
			break;
/*		QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Алгоритм ещё не реализован"));
		msg.exec();
*/	}

	if(connect(AW, SIGNAL(usiloPlenumis(int)), SLOT(openTakeQuadFun(int))))
		AW->showMaximized();
	else
		QMessageBox::warning(this, trUtf8("Ошибка"), trUtf8("Ошибка соединения MainWindowImpl и AlgoritmoWin."));
}

//! Нажата кнопка "Назад" (2-ая страница).
void MainWindowImpl::on_back_button_clicked()
{
	// TODO
	comboBox->clear();
	stackedWidget->setCurrentIndex(0);
}

//! Выбран вариант функции.
void MainWindowImpl::on_comboBox_activated(int index)
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

//! Выбран пункт меню "Справка".
void MainWindowImpl::on_help_activated()
{
	HelpBrowser * hb = new HelpBrowser( "doc/", "help.htm", this);
	hb->resize(900, 600);
	hb->show();
}

//! Выбран пункт меню "О программе".
void MainWindowImpl::on_about_activated()
{
	aboutProgramImpl * about = new aboutProgramImpl(this);
	about->show();
}

//! Выбран пункт меню "Разрешить функцию".
void MainWindowImpl::on_allow_activated()
{
	Pass = new mainPassImpl(choiceMethods->currentIndex(), this);
	if(connect(Pass, SIGNAL(setFlag(int)), SLOT(openTakeQuadFun(int))))
		Pass->show();
	else
		QMessageBox::warning(this, trUtf8("Ошибка"), trUtf8("Ошибка соединения MainWindowImpl и mainPassImpl."));
}

//! Проверка takeQuadFun.
void MainWindowImpl::on_choiceMethods_activated(int index)
{
	// TODO
	if(takeQuadFun[index] == false)
	{
		quadFunction->setChecked(true);
		ravinFunction->setCheckable(false);
	}
	else if(takeQuadFun[index] == true)
		ravinFunction->setCheckable(true);
}

//! Выбор ввода информации через выбор варианта.
void MainWindowImpl::on_choiceVar_clicked(bool checked)
{
	// TODO
	choiceVar->setChecked(true);
	comboBox->setVisible(checked);
	label->setVisible(checked);
	
	quadKoef->setEnabled(checked - 1);
	quadSimpleCon->setEnabled(checked - 1);
	
	on_comboBox_activated(0);
}

//! Выбор ввода информации вручную.
void MainWindowImpl::on_inArm_clicked(bool checked)
{
	// TODO
	inArm->setChecked(true);
	comboBox->setVisible(checked - 1);
	label->setVisible(checked - 1);
	
	quadKoef->setEnabled(checked);
	quadSimpleCon->setEnabled(checked);
	
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
