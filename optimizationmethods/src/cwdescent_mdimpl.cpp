#include "cwdescent_mdimpl.h"
#include "mapoporfunkcioimpl.h"
#include "Konstantoj.h"
#include "funkcio.h"
#include "spuro.h"
#include "spurosinkolauxkoordinatoj.h"
#include "demonstrataqpointf.h"
#include "signalantoporpointf.h"
#include "math.h"
#include <QTextBrowser>
#include <QString>
#include <QMessageBox>
#include <QStateMachine>
#include <QFinalState>
#include <QLabel>
#include <QDebug>
//
using namespace SinkoLauxKoordinatojMD;

CWdescent_mdImpl::CWdescent_mdImpl(funkcio *f, QVector<double> *d, QWidget * parent, Qt::WFlags flags) 
	: AlgoritmoWin(f, d, parent, flags)
{
	setupUi(this);
	
	qDebug()<<trUtf8("Покоординатный спуск с минимизацией по направлению"); // Вывожу дебажныю инфу на консоль.

	// Создаю карту.
	// centralwidget->layout() - указатель на компановщик центрального виджета
	// static_cast<QGridLayout*>(centralwidget->layout()) - обьясняю компилятору, что это именно QGridLayout
	// добавляю вижет карты в позицию 1,1. Компановщик сам позаботится о назначении новому виджету родителя.
	static_cast<QGridLayout*>(centralwidget->layout())->addWidget(MapoWdg, 1, 1, 2, 1);

	MapoWdg->setScale(6);// Ставлю масштаб побольше. Надо будет определться с оптимальным значением.

	//===Соединяю точки и надписи на форме=========================================
	SignalantoPorPointF * sMP = new SignalantoPorPointF(&MP, F, this);
	connect(sMP, SIGNAL(proviziXValoro(const QString &)), x1_lb, SLOT(setText(const QString &)));
	connect(sMP, SIGNAL(proviziYValoro(const QString &)), x2_lb, SLOT(setText(const QString &)));
	connect(sMP, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), fsign_lb, SLOT(setText(const QString &)));

	//===Создаю конечный автомат.==================================================
	QStateMachine * SM = new QStateMachine();

	//---Создаю состояния, согласно диаграмме.-------------------------------------
	QState * so = new QState();
	QState * s1 = new QState(so);
	QState * s2 = new QState(so);
	QState * s3 = new QState(so);
	QState * s4 = new QState(so);
	QFinalState * sf = new QFinalState(so);
	QFinalState * sfm = new QFinalState();
	so->setInitialState(s1);

	//---Соединяю состояния и обрабодчики входа в них.-----------------------------
	connect(so, SIGNAL(entered()), SLOT(so_entered()));
	connect(s1, SIGNAL(entered()), SLOT(s1_entered()));
	connect(s2, SIGNAL(entered()), SLOT(s2_entered()));
	connect(s3, SIGNAL(entered()), SLOT(s3_entered()));
	connect(s4, SIGNAL(entered()), SLOT(s4_entered()));

	//---Создаю переходы, согласно диаграмме.--------------------------------------
	s1s2Transiro * s1s2 = new s1s2Transiro(min_x1_rb, calculate_bt, SIGNAL(clicked()), s1);
	s1s2->setTargetState(s2);
	s2s3Transiro * s2s3 = new s2s3Transiro(min_x2_rb, calculate_bt, SIGNAL(clicked()), s2);
	s2s3->setTargetState(s3);
	s3->addTransition(this, SIGNAL(stateHasEntered()), s4);// Переход s3s4 совершается сразу при входе в s3.
	s4s1Transiro * s4s1 = new s4s1Transiro(&BP, &MP, strikteco, s4, SIGNAL(entered()), s4);
	s4s1->setTargetState(s1);
	s4sfTransiro * s4sf = new s4sfTransiro(&BP, &MP, strikteco, end_bt, SIGNAL(clicked()), s4);
	s4sf->setTargetState(sf);

	//---Создаю переход от сложного состояния к финалу автомата.
	so->addTransition(so, SIGNAL(finished()), sfm); // Вызывается, когда сложное состояние достигло финиша - был найден минимум.

	//---Создаю переходы не имеющие цели. С помощью них фиксирую ошибки ползователя
	QSignalTransition * te1 = new QSignalTransition(calculate_bt, SIGNAL(clicked()));
	so->addTransition(te1);
	connect(te1, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te2 = new QSignalTransition(end_bt, SIGNAL(clicked()));
	so->addTransition(te2);
	connect(te2, SIGNAL(triggered()), SLOT(registriEraro()));

	//---Настраиваю некоторые состояния, чтоб затирали надпись со значениями новой точки, дабы не смущать пользователя.
	s1->assignProperty(dx_lb, "text", trUtf8("Неопределено"));
	s1->assignProperty(df_lb, "text", trUtf8("Неопределено"));

	//---Настраиваю выделение цветом растояния между точками.
	s4->assignProperty(dx_lb, "palette", QPalette(Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red));
	s4->assignProperty(df_lb, "palette", QPalette(Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red));
	s1->assignProperty(dx_lb, "palette", this->palette());
	s1->assignProperty(df_lb, "palette", this->palette());

	//---Добавляю состояния в автомат и запускаю его.------------------------------
	SM->addState(so);
	SM->addState(sfm);
	SM->setInitialState(so);
	init();
	SM->start();
}
//

//! Возвращает длину шага для оптимизации функции одной переменной по оси Х1.
DemonstrataQPointF CWdescent_mdImpl::LengthOfStepX1(const DemonstrataQPointF X)
{
	double y = X.y();

	// Начальная точка соотвествует координате текущей точки.
	double a = X.x();

	// b надо взять такое, что бы в разрезе по выбраной оси функция имела форму чашки. 
	double b = a + 100;
	// Изменяю b, пока не будет чашка. (Знаю, что очень по индуски, но пока ничего лушего не придумал).
	while(F->rezulto(a + b, y) < F->rezulto(a + b - 50, y))
	{
		if (b - a <= 10000)
			b += 100;
		else
			break;
	}
	if (b - a > 10000)
	{
		b = a - 100;
		while(F->rezulto(a - b, y) < F->rezulto(a - b + 50, y))
		{
				b -= 100;
		}
	}
	
	double tau = 0.618033988749894;
	double lam = a + (1 - tau)*(b - a);
	double mu = a + tau*(b - a);
	while (abs(b - a) > 0.0001)
	{
		if (F->rezulto(lam, y) > F->rezulto(mu, y))
		{
			a = lam;
			lam = mu;
			mu = a + tau*(b - a);
		}
		else
		{
			b = mu;
			mu = lam;
			lam = a + (1 - tau)*(b - a);
		}
	}
	
	X = QPointF((a + b)/2, y);
	
	return X;
}

//! Возвращает длину шага для оптимизации функции одной переменной по оси Х2.
DemonstrataQPointF CWdescent_mdImpl::LengthOfStepX2(const DemonstrataQPointF X)
{
	double x = X.x();

	// Начальная точка соотвествует координате текущей точки.
	double a = X.y();
	
	// b надо взять такое, что бы в разрезе по выбраной оси функция имела форму чашки. 
	double b = a + 100;
	// Изменяю b, пока не будет чашка. (Знаю, что очень по индуски, но пока ничего лушего не придумал).
	while(F->rezulto(x, a + b) < F->rezulto(x, a + b - 50))
	{
		if (b - a <= 10000)
			b += 100;
		else
			break;
	}
	if (b - a > 10000)
	{
		b = a - 100;
		while(F->rezulto(x, a + b) < F->rezulto(x, a + b - 50))
		{
				b -= 100;
		}
	}
	
	double tau = 0.618033988749894;
	double lam = a + (1 - tau)*(b - a);
	double mu = a + tau*(b - a);
	while (abs(b - a) > 0.0001)
	{
		if (F->rezulto(x, lam) > F->rezulto(x, mu))
		{
			a = lam;
			lam = mu;
			mu = a + tau*(b - a);
		}
		else
		{
			b = mu;
			mu = lam;
			lam = a + (1 - tau)*(b - a);
		}
	}
	
	X = QPointF(x, (a + b)/2);
	
	return X;
}

void CWdescent_mdImpl::registriEraro()
{
	++KvantoEraroj;
	LogTxtBrsr->append(trUtf8("    Совершена ошибка. Общее количество ошибок: %1").arg(KvantoEraroj));
	QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Неправильное действие"));
	msg.exec();
	
	qDebug()<<trUtf8("Пользователь ошибся"); // Вывожу дебажную инфу на консоль.
}

void CWdescent_mdImpl::sf_entered()
{
	LogTxtBrsr->append(trUtf8("Конец алгоритма. Найден: %1").arg(F->rezulto(MP)));
	QMessageBox::information(this, trUtf8("Конец"), trUtf8("Найден минимум"));

	qDebug()<<trUtf8("Вошёл в Финальное состояние, сложного сосояния"); // Вывожу дебажную инфу на консоль.
}

void CWdescent_mdImpl::s4_entered()
{
	// Вывожу на форму значение расстояния между предыдущей базовой точкой и
	// текущей, а также разность между предыдущим значением функции и текущим. 
	dx_lb->setText(QString::number(Length(BP - MP), 'f'));
	df_lb->setText(QString::number(F->rezulto(BP) - F->rezulto(MP), 'f'));
	
	qDebug()<<trUtf8("Вошёл в s4"); // Вывожу дебажную инфу на консоль.
}

void CWdescent_mdImpl::s3_entered()
{
	MP = LengthOfStepX2(MP);
	LogTxtBrsr->append(trUtf8("  Сделан шаг по оси Х2. Новая точка: %1; %2").arg(MP.x()).arg(MP.y()));

	qDebug()<<trUtf8("Вошёл в s3"); // Вывожу дебажную инфу на консоль.
}

void CWdescent_mdImpl::s2_entered()
{
	MP = LengthOfStepX1(MP);
	LogTxtBrsr->append(trUtf8("  Сделан шаг в по оси Х1. Новая точка: %1; %2").arg(MP.x()).arg(MP.y()));

	qDebug()<<trUtf8("Вошёл в s2"); // Вывожу дебажную инфу на консоль.
}

void CWdescent_mdImpl::s1_entered()
{
	BP = MP;
	LogTxtBrsr->append(trUtf8("Начало итерации № %1. Базовая точка: %2; %3. Текущая точка: %4; %5.").arg(++NumeroIteracio).arg(BP.x()).arg(BP.y()).arg(MP.x()).arg(MP.y()));

	qDebug()<<trUtf8("Вошёл в s1"); // Вывожу дебажную инфу на консоль.
}

void CWdescent_mdImpl::so_entered()
{
	qDebug()<<trUtf8("Вошёл в so"); // Вывожу дебажныю инфу на консоль.
}

void CWdescent_mdImpl::init()
{
	strikteco = (*D)[0];
	precision_lb->setText(QString::number(strikteco));
	KvantoEraroj = 0;
	NumeroIteracio = 0;
	MP = QPointF((*D)[4],(*D)[5]);
	LogTxtBrsr->setText("");

	qDebug()<<trUtf8("Задаю переменным начальные значения"); // Вывожу дебажную инфу на консоль.
}

namespace SinkoLauxKoordinatojMD
{
	bool s1s2Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбран шаг по X1");
			// Проверяю своё условие.
			return min_x1->isChecked();
		}
		else
			return false;
	}

	bool s2s3Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбран шаг по X2");
			// Проверяю своё условие.
			return min_x2->isChecked();
		}
		else
			return false;
	}

	bool s4sfTransiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю |bp - mp| < e && |f(bp) - f(mp)| < e");
			// Проверяю своё условие.
			return Length(*bp - *mp) < s && (f->rezulto(*bp) - f->rezulto(*mp)) < s;
		}
		else
			return false;
	}

	bool s4s1Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю |bp - mp| >= e && |f(bp) - f(mp)| >= e");
			// Проверяю своё условие.
			return Length(*bp - *mp) >= s || (f->rezulto(*bp) - f->rezulto(*mp)) >= s;
		}
		else
			return false;
	}
};
//

