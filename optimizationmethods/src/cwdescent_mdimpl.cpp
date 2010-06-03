#include "cwdescent_mdimpl.h"
#include "mapoporfunkcioimpl.h"
#include "Konstantoj.h"
#include "funkcio.h"
#include "spuro.h"
#include "spurosinkolauxkoordinatoj_md.h"
#include "demonstrataqpointf.h"
#include "signalantoporpointf.h"
#include "math.h"
#include "helpbrowserimpl.h"
#include "aboutprogramimpl.h"
#include <limits>
#include <QTextBrowser>
#include <QFontDialog>
#include <QString>
#include <QMessageBox>
#include <QStateMachine>
#include <QFinalState>
#include <QLabel>
#include <QDebug>
//
using namespace std;
using namespace A;
using namespace SinkoLauxKoordinatojMD;

CWdescent_mdImpl::CWdescent_mdImpl(funkcio *f, QVector<double> *d, QWidget * parent, Qt::WFlags flags) 
	: AlgoritmoWin(f, d, parent, flags)
{
	setupUi(this);
	connect(exit, SIGNAL(activated()), qApp, SLOT(closeAllWindows()));
	
// Для овражной функции убираю действие "Начать заново"
	if(F->metaObject()->className() == QString("RavinaFunkcio")){
		recomenc_acn->setEnabled(false);
	}

	qDebug()<<trUtf8("Покоординатный спуск с минимизацией по направлению"); // Вывожу дебажныю инфу на консоль.
	
	//Вывожу формулу функции.
	func->setText(textoFunkcio());
	
	// Создаю карту.
	// centralwidget->layout() - указатель на компановщик центрального виджета
	// static_cast<QGridLayout*>(centralwidget->layout()) - обьясняю компилятору, что это именно QGridLayout
	// добавляю вижет карты в позицию 1,1. Компановщик сам позаботится о назначении новому виджету родителя.
	static_cast<QGridLayout*>(centralwidget->layout())->addWidget(MapoWdg, 2, 1, 2, 1);

	MapoWdg->setScale(20);// Ставлю масштаб побольше. Надо будет определться с оптимальным значением.

	Sp = new spuroSinkoLauxKoordinatoj_md(Qt::white, Qt::blue);
	MapoWdg->difiniSpuro(Sp);
	MapoWdg->difiniFonaKoloro(Qt::green);
	
	connect(MapoWdg, SIGNAL(MusaPos(const QString &)), statusBar(), SLOT(showMessage( const QString &)));

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
	QState * sf = new QState();
	so->setInitialState(s1);

	//---Соединяю состояния и обрабодчики входа в них.-----------------------------
	connect(so, SIGNAL(entered()), SLOT(so_entered()));
	connect(s1, SIGNAL(entered()), SLOT(s1_entered()));
	connect(s2, SIGNAL(entered()), SLOT(s2_entered()));
	connect(s3, SIGNAL(entered()), SLOT(s3_entered()));
	connect(sf, SIGNAL(entered()), SLOT(sf_entered()));

	//---Создаю переходы, согласно диаграмме.--------------------------------------
	s1s2Transiro * s1s2 = new s1s2Transiro(min_x1_rb, calculate_bt, SIGNAL(clicked()), s1);
	s1s2->setTargetState(s2);
	s2s3Transiro * s2s3 = new s2s3Transiro(min_x2_rb, calculate_bt, SIGNAL(clicked()), s2);
	s2s3->setTargetState(s3);
	s3s1Transiro * s3s1 = new s3s1Transiro(&BP, &MP, F, strikteco, s3, SIGNAL(entered()), s3);
	s3s1->setTargetState(s1);
	s3sfTransiro * s3sf = new s3sfTransiro(&BP, &MP, F, strikteco, end_bt, SIGNAL(clicked()), s3);
	s3sf->setTargetState(sf);

	//---Создаю переход по действию "Начать заново"
	connect(so->addTransition(recomenc_acn, SIGNAL(activated()), s1), SIGNAL(triggered()), SLOT(init()));
	connect(sf->addTransition(recomenc_acn, SIGNAL(activated()), s1), SIGNAL(triggered()), SLOT(init()));


	//---Создаю переходы не имеющие цели. С помощью них фиксирую ошибки ползователя
	QSignalTransition * te1 = new QSignalTransition(calculate_bt, SIGNAL(clicked()));
	so->addTransition(te1);
	connect(te1, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te2 = new QSignalTransition(end_bt, SIGNAL(clicked()));
	so->addTransition(te2);
	connect(te2, SIGNAL(triggered()), SLOT(registriEraro()));

	//---Прикручиваю карту-------------------------------------------------------
	connect(sMP, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(aldoniPointo(const QPointF &)));

	connect(s1, SIGNAL(entered()), Sp, SLOT(finisxiIteracio()));
	
	//---Добавляю состояния в автомат и запускаю его.----------------------------
	SM->addState(so);
	SM->addState(sf);
	SM->setInitialState(so);
	init();
	SM->start();
}
//

//! Возвращает длину шага для оптимизации функции одной переменной по оси Х1.
DemonstrataQPointF CWdescent_mdImpl::LengthOfStepX1(DemonstrataQPointF X) const
{
	double y = X.y();

	double a = - ampleksoMapo;
	double b = ampleksoMapo;

	double tau = 0.618033988749894;
	double lam = a + (1 - tau)*(b - a);
	double mu = a + tau*(b - a);
	while (b - a > 0.000001)
	{
		if (F->rezulto(lam, y) > F->rezulto(mu, y))
		{
			a = lam;
			lam = a + (1 - tau)*(b - a);
			mu = a + tau*(b - a);
		}
		else
		{
			b = mu;
			lam = a + (1 - tau)*(b - a);
			mu = a + tau*(b - a);
		}
	}
	
	X = QPointF((a + b)/2, y);
	
	return X;
}

//! Возвращает длину шага для оптимизации функции одной переменной по оси Х2.
DemonstrataQPointF CWdescent_mdImpl::LengthOfStepX2(DemonstrataQPointF X) const
{
	double x = X.x();

	double a = - ampleksoMapo;
	double b = ampleksoMapo;

	double tau = 0.618033988749894;
	double lam = a + (1 - tau)*(b - a);
	double mu = a + tau*(b - a);
	while (b - a > 0.000001)
	{
		if (F->rezulto(x, lam) > F->rezulto(x, mu))
		{
			a = lam;
			lam = a + (1 - tau)*(b - a);
			mu = a + tau*(b - a);
		}
		else
		{
			b = mu;
			lam = a + (1 - tau)*(b - a);
			mu = a + tau*(b - a);
		}
	}
	
	X = QPointF(x, (a + b)/2);
	
	return X;
}

void CWdescent_mdImpl::on_difiniFonto_act_activated()
{
	bool b;
	QFont fnt = QFontDialog::getFont(&b, font());
	if(b){
		// Была нажата кнопка ОК.
		setFont(fnt);
	}
}

void CWdescent_mdImpl::on_helpo_action_activated()
{
	helpBrowserImpl * hb = new helpBrowserImpl( "doc/", "method2.htm", this);
	hb->resize(900, 600);
	hb->show();
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
	LogTxtBrsr->append(trUtf8("Конец алгоритма. Найден минимум функции: %1. Количество ошибок: %2.").arg(F->rezulto(MP)).arg(KvantoEraroj));
	QString str = trUtf8("Найден минимум. ");
	
	if(KvantoEraroj > quanError){
		// Слишком много ошибок.
		str += trUtf8("Ваше количество ошибок (%1) превысило допустимый предел (%2). Начните заново.").arg(KvantoEraroj).arg(quanError);
		QMessageBox::information(this, trUtf8("Внимание"), str);
		if(F->metaObject()->className() == QString("RavinaFunkcio"))
			close();
		else recomenc_acn->trigger();
	}else{
		str += trUtf8("Вы прошли тест. ");
		if(F->metaObject()->className() == QString("KvadratigantoFunkcio"))
		{
			str += trUtf8("Сообщите преподавателю и перейдите к овражной функции. Количество ошибок: <b>%1</b>.").arg(KvantoEraroj);
			emit usiloPlenumis(A::CWdescent_md);
			QMessageBox::information(this, trUtf8("Поздравляем"), str);
			close();
		}
		else if(F->metaObject()->className() == QString("RavinaFunkcio"))
		{
			str += trUtf8("Позовите преподавателя. Количество ошибок: <b>%1</b>.").arg(KvantoEraroj);
			QMessageBox::information(this, trUtf8("Поздравляем"), str);
		}
	}

	qDebug()<<trUtf8("Вошёл в Финальное состояние, сложного состояния"); // Вывожу дебажную инфу на консоль.
}

void CWdescent_mdImpl::s3_entered()
{
	MP = LengthOfStepX2(MP);
	
	// Вывожу на форму значение расстояния между предыдущей базовой точкой и
	// текущей, а также разность между предыдущим значением функции и текущим. 
	dx_lb->setText(QString::number(Length(BP - MP), 'f'));
	df_lb->setText(QString::number(F->rezulto(BP) - F->rezulto(MP), 'f'));

	LogTxtBrsr->append(trUtf8("  Сделан шаг по оси Х2. Новая точка: %1; %2").arg(MP.x()).arg(MP.y()));

	qDebug()<<trUtf8("Вошёл в s3"); // Вывожу дебажную инфу на консоль.
}

void CWdescent_mdImpl::s2_entered()
{
	MP = LengthOfStepX1(MP);

	// Вывожу на форму значение расстояния между предыдущей базовой точкой и
	// текущей, а также разность между предыдущим значением функции и текущим. 
	dx_lb->setText(QString::number(Length(BP - MP), 'f'));
	df_lb->setText(QString::number(F->rezulto(BP) - F->rezulto(MP), 'f'));
	
	BP = MP;
	
	LogTxtBrsr->append(trUtf8("  Сделан шаг в по оси Х1. Новая точка: %1; %2").arg(MP.x()).arg(MP.y()));

	qDebug()<<trUtf8("Вошёл в s2"); // Вывожу дебажную инфу на консоль.
}

void CWdescent_mdImpl::s1_entered()
{
	BP = MP;
	
	LogTxtBrsr->append(trUtf8("Итерация № %1.").arg(++NumeroIteracio));

	qDebug()<<trUtf8("Вошёл в s1"); // Вывожу дебажную инфу на консоль.
}

void CWdescent_mdImpl::so_entered()
{
	qDebug()<<trUtf8("Вошёл в so"); // Вывожу дебажныю инфу на консоль.
}

void CWdescent_mdImpl::init()
{
	precision_lb->setText(QString::number(strikteco));
	KvantoEraroj = 0;
	NumeroIteracio = 0;
	MP = QPointF(D[4],D[5]);
	quanError = (int)D[6];
	LogTxtBrsr->setText("");

	static_cast<spuroSinkoLauxKoordinatoj_md*>(Sp)->senspurigi();
	static_cast<spuroSinkoLauxKoordinatoj_md*>(Sp)->difiniUnuaPointo(MP);

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

	bool s3s1Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю |bp - mp| >= e || |f(bp) - f(mp)| >= e");
			// Проверяю своё условие.
			return Length(*bp - *mp) >= s || f->rezulto(*bp) - f->rezulto(*mp) >= s;
		}
		else
			return false;
	}

	bool s3sfTransiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю |bp - mp| < e && |f(bp) - f(mp)| < e");
			// Проверяю своё условие.
			return Length(*bp - *mp) < s && f->rezulto(*bp) - f->rezulto(*mp) < s;
		}
		else
			return false;
	}
};
//


void CWdescent_mdImpl::on_about_action_activated(){
	aboutProgramImpl * about = new aboutProgramImpl(this);
	about->show();
}

