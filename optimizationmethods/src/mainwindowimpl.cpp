#include "mainwindowimpl.h"
#include "helpbrowserimpl.h"
#include "aboutprogramimpl.h"
#include <QDoubleValidator>
//
//! Конструктор класса.
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags flag)
	: QMainWindow(parent, flag)
{
	setupUi(this);

// Прикручиваю валидаторы к полям ввода.
	a->setValidator(new QDoubleValidator(a));
	b->setValidator(new QDoubleValidator(b));
	c->setValidator(new QDoubleValidator(c));
	d->setValidator(new QDoubleValidator(d));
	e->setValidator(new QDoubleValidator(e));
	f->setValidator(new QDoubleValidator(f));
	g->setValidator(new QDoubleValidator(g));
	accuracy->setValidator(new QDoubleValidator(accuracy));
	stepx1->setValidator(new QDoubleValidator(stepx1));
	stepx2->setValidator(new QDoubleValidator(stepx2));
	stepChange->setValidator(new QDoubleValidator(stepChange));
	x1->setValidator(new QDoubleValidator(x1));
	x2->setValidator(new QDoubleValidator(x2));

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

	takeQuadFun.resize(6);
	for(int i = 0; i < 6; ++i)
	{
		takeQuadFun[i].resize(2);
		takeQuadFun[i][0] = false;
		takeQuadFun[i][1] = -1;
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
	QFile file(QDir::toNativeSeparators("variants/me.dll"));
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
void MainWindowImpl::openTakeQuadFun(int flag, int numberError)
{
	takeQuadFun[flag][0] = ravinFunction->isChecked() - 1;
	takeQuadFun[flag][1] = numberError;
	choiceMethods->setCurrentIndex(flag);
	on_choiceMethods_activated(flag);
	quadFunction->setChecked(ravinFunction->isChecked());
	ravinFunction->setChecked(ravinFunction->isChecked() - 1);
}

//! Нажата кнопка "Далее" (1-ая страница).
void MainWindowImpl::on_next_button_clicked()
{
	stackedWidget->setCurrentIndex(1);
}

//! Нажата кнопка "Далее" (2-ая страница).
void MainWindowImpl::on_next_button_2_clicked()
{
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

		func->setText("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">"
			"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">"
			"p, li { white-space: pre-wrap; }"
			"</style></head><body style=\" font-family:'Times New Roman'; font-size:14pt; font-weight:400; font-style:normal;\">"
			"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
			"A*(x<span style=\" vertical-align:sub;\">1</span> - B)<span style=\" vertical-align:super;\">2</span> + C*(x"
			"<span style=\" vertical-align:sub;\">2</span> - D)<span style=\" vertical-align:super;\">2</span> + E*(x"
			"<span style=\" vertical-align:sub;\">1</span> - F)*(x<span style=\" vertical-align:sub;\">2</span> - G)</p></body></html>");
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

		func->setText("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">"
			"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">"
			"p, li { white-space: pre-wrap; }"
			"</style></head><body style=\" font-family:'Times New Roman'; font-size:14pt; font-weight:400; font-style:normal;\">"
			"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
			"A*(x<span style=\" vertical-align:sub;\">2</span> - x<span style=\" vertical-align:sub;\">1</span>"
			"<span style=\" vertical-align:super;\">2</span>)<span style=\" vertical-align:super;\">2</span> + B*(1-x"
			"<span style=\" vertical-align:sub;\">1</span>)<span style=\" vertical-align:super;\">2</span></p></body></html>");
	}

	on_choiceVar_clicked(true);
	initializationComboBox(methFunc[1]);
	stackedWidget->setCurrentIndex(2);
}

//! Нажата кнопка "Назад" (2-ая страница).
void MainWindowImpl::on_back_button_clicked()
{
	comboBox->clear();
	quadFunction->setChecked(true);
	ravinFunction->setChecked(false);
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
	helpBrowserImpl * hb = new helpBrowserImpl( "doc/", "help.htm", this);
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
	if(connect(Pass, SIGNAL(setFlag(int, int)), SLOT(openTakeQuadFun(int, int))))
		Pass->show();
	else
		QMessageBox::warning(this, trUtf8("Ошибка"), trUtf8("Ошибка соединения MainWindowImpl и mainPassImpl."));
}

//! Проверка takeQuadFun.
void MainWindowImpl::on_choiceMethods_activated(int index)
{
	// TODO
	if((bool)takeQuadFun[index][0] == false)
	{
		quadFunction->setChecked(true);
		ravinFunction->setCheckable(false);
	}
	else if((bool)takeQuadFun[index][0] == true)
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

void MainWindowImpl::on_next_button_3_clicked()
{
	QVector<double> data(8);
	data[0] = accuracy->text().toDouble();
	data[1] = stepx1->text().toDouble();
	data[2] = stepx2->text().toDouble();
	data[3] = stepChange->text().toDouble();
	data[4] = x1->text().toDouble();
	data[5] = x2->text().toDouble();
	data[6] = ReadError(methFunc[0]);
	data[7] = takeQuadFun[methFunc[0]][1];

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
			AW = new CWdescentWinImpl(funck, data, this, Qt::Window);
			break;
		case A::CWdescent_md:
			AW = new CWdescent_mdImpl(funck, data, this, Qt::Window);
			break;
		case A::FasterDescent:
			AW = new FasterDescentImpl(funck, data, this, Qt::Window);
			break;
		case A::HuGi:
			AW = new HuGiImpl(funck, data, this, Qt::Window);
			break;
		case A::NeMi:
			AW = new NeMiImpl(funck, data, this, Qt::Window);
			break;
		case A::NotWen:
			AW = new NotWenImpl(funck, data, this, Qt::Window);
			break;
	}

	if(connect(AW, SIGNAL(usiloPlenumis(int, int)), SLOT(openTakeQuadFun(int, int))))
	{
		if(AW->metaObject()->className() == QString("CWdescentWinImpl"))
		{
			takeQuadFun[0][0] = false;
			on_choiceMethods_activated(0);
		}
		else if(AW->metaObject()->className() == QString("CWdescent_mdImpl"))
		{
			takeQuadFun[1][0] = false;
			on_choiceMethods_activated(1);
		}
		else if(AW->metaObject()->className() == QString("FasterDescentImpl"))
		{
			takeQuadFun[2][0] = false;
			on_choiceMethods_activated(2);
		}
		else if(AW->metaObject()->className() == QString("HuGiImpl"))
		{
			takeQuadFun[3][0] = false;
			on_choiceMethods_activated(3);
		}
		else if(AW->metaObject()->className() == QString("NeMiImpl"))
		{
			takeQuadFun[4][0] = false;
			on_choiceMethods_activated(4);
		}
		else if(AW->metaObject()->className() == QString("NotWenImpl"))
		{
			takeQuadFun[5][0] = false;
			on_choiceMethods_activated(5);
		}

		AW->showMaximized();

		on_back_button_clicked();
	}
	else
		QMessageBox::warning(this, trUtf8("Ошибка"), trUtf8("Ошибка соединения MainWindowImpl и AlgoritmoWin."));
}

void MainWindowImpl::on_back_button_2_clicked()
{
	stackedWidget->setCurrentIndex(1);
}
