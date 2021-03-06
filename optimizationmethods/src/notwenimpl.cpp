#include "notwenimpl.h"
#include "mapoporfunkcioimpl.h"
#include "Konstantoj.h"
#include "funkcio.h"
#include "spuro.h"
#include "spurosinkolauxkoordinatoj_md.h"
#include "demonstrataqpointf.h"
#include "signalantoporpointf.h"
#include "helpbrowserimpl.h"
#include "math.h"
#include "aboutprogramimpl.h"
#include <QTextBrowser>
#include <QString>
#include <QMessageBox>
#include <QStateMachine>
#include <QFinalState>
#include <QLabel>
#include <QFontDialog>
#include <QDebug>

#include <math.h>
#include <QtScript>
#include <QScriptEngine>
//
using namespace SinkoNotWen;

NotWenImpl::NotWenImpl( funkcio *f, QVector<double> d, QWidget * parent, Qt::WFlags flags)
	: AlgoritmoWin(f, d, parent, flags)
{
	setupUi(this);
	connect(exit, SIGNAL(activated()), qApp, SLOT(closeAllWindows()));

	qDebug()<<trUtf8("Метод Ньютона"); // Вывожу дебажную инфу на консоль.

	//Вывожу формулу функции.
	func->setText(textoFunkcio());

	// Для овражной функции убираю действие "Начать заново"
	if(F->metaObject()->className() == QString("RavinaFunkcio")){
		recomenc_acn->setEnabled(false);
	}

	// Создаю карту.
	verticalLayout_2->addWidget(MapoWdg, 1);
	
//	MapoWdg->setScale(20);// Ставлю масштаб побольше. Надо будет определться с оптимальным значением.

	Sp = new spuroSinkoLauxKoordinatoj_md(Qt::blue);
	MapoWdg->difiniSpuro(Sp);
//	MapoWdg->difiniFonaKoloro(Qt::green);

	//===Соединяю точки и надписи на форме=========================================
	SignalantoPorPointF * sBP = new SignalantoPorPointF(&BP, F, this);
	connect(sBP, SIGNAL(proviziXValoro(const QString &)), x1_lb, SLOT(setText(const QString &)));
	connect(sBP, SIGNAL(proviziYValoro(const QString &)), x2_lb, SLOT(setText(const QString &)));
	connect(sBP, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), fsign_lb, SLOT(setText(const QString &)));

	//===Создаю конечный автомат.==================================================
	QStateMachine * SM = new QStateMachine();

	//---Создаю состояния, согласно диаграмме.-------------------------------------
	QState * so = new QState();
	QState * s1 = new QState(so);
	QState * s2 = new QState(so);
	QState * s3 = new QState(so);
	QState * s4 = new QState(so);
	QState * s5 = new QState(so);
	QState * s6 = new QState(so);
	QState * s7 = new QState(so);
	QState * sf = new QState();
	so->setInitialState(s1);

	//---Соединяю состояния и обрабодчики входа в них.-----------------------------
	connect(so, SIGNAL(entered()), SLOT(so_entered()));
	connect(s1, SIGNAL(entered()), SLOT(s1_entered()));
	connect(s2, SIGNAL(entered()), SLOT(s2_entered()));
	connect(s3, SIGNAL(entered()), SLOT(s3_entered()));
	connect(s4, SIGNAL(entered()), SLOT(s4_entered()));
	connect(s5, SIGNAL(entered()), SLOT(s5_entered()));
	connect(s6, SIGNAL(entered()), SLOT(s6_entered()));
	connect(s7, SIGNAL(entered()), SLOT(s7_entered()));
	connect(sf, SIGNAL(entered()), SLOT(sf_entered()));

	//---Создаю переходы, согласно диаграмме.--------------------------------------
	s1s2Transiro * s1s2 = new s1s2Transiro(_g_xkgradfxk, next1_bt, SIGNAL(clicked()), s1);
	s1s2->setTargetState(s2);
	s2s3Transiro * s2s3 = new s2s3Transiro(&NumeroIteracio, part_proizvod_first, next2_bt, SIGNAL(clicked()), s2);
	s2s3->setTargetState(s3);
	s2s4Transiro * s2s4 = new s2s4Transiro(&NumeroIteracio, part_proizvod_first, next2_bt, SIGNAL(clicked()), s2);
	s2s4->setTargetState(s4);
	s3s4Transiro * s3s4 = new s3s4Transiro(F, &BP, dfdx1, dfdx2, next3_bt, SIGNAL(clicked()), s3);
	s3s4->setTargetState(s4);
	s4s5Transiro * s4s5 = new s4s5Transiro(gradfxk_less, next4_bt, SIGNAL(clicked()), s4);
	s4s5->setTargetState(s5);
	s5s6Transiro * s5s6 = new s5s6Transiro(&NumeroIteracio, &grad, strikteco, to_continue, next5_bt, SIGNAL(clicked()), s5);
	s5s6->setTargetState(s6);
	s5s7Transiro * s5s7 = new s5s7Transiro(&NumeroIteracio, &grad, strikteco, to_continue, next5_bt, SIGNAL(clicked()), s5);
	s5s7->setTargetState(s7);
	s5sfTransiro * s5sf = new s5sfTransiro(&grad, strikteco, stop, next5_bt, SIGNAL(clicked()), s5);
	s5sf->setTargetState(sf);
	s6s7Transiro * s6s7 = new s6s7Transiro(F, &BP, dfdx1dx1, dfdx1dx2, dfdx2dx1, dfdx2dx2, gess11, gess12, gess21, gess22, next6_bt, SIGNAL(clicked()), s6);
	s6s7->setTargetState(s7);
	s7->addTransition(this, SIGNAL(stateHasEntered()), s1);

	//---Создаю переход по действию "Начать заново"
	connect(so->addTransition(recomenc_acn, SIGNAL(activated()), s1), SIGNAL(triggered()), SLOT(init()));
	connect(sf->addTransition(recomenc_acn, SIGNAL(activated()), s1), SIGNAL(triggered()), SLOT(init()));

	//---Создаю переходы не имеющие цели. С помощью них фиксирую ошибки ползователя
	QSignalTransition * te1 = new QSignalTransition(next1_bt, SIGNAL(clicked()));
	so->addTransition(te1);
	connect(te1, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te2 = new QSignalTransition(next2_bt, SIGNAL(clicked()));
	so->addTransition(te2);
	connect(te2, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te3 = new QSignalTransition(next3_bt, SIGNAL(clicked()));
	so->addTransition(te3);
	connect(te3, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te4 = new QSignalTransition(next4_bt, SIGNAL(clicked()));
	so->addTransition(te4);
	connect(te4, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te5 = new QSignalTransition(next5_bt, SIGNAL(clicked()));
	so->addTransition(te5);
	connect(te5, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te6 = new QSignalTransition(next6_bt, SIGNAL(clicked()));
	so->addTransition(te6);
	connect(te6, SIGNAL(triggered()), SLOT(registriEraro()));

	//---Прикручиваю карту---------------------------------------------------------
	connect(sBP, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(aldoniPointo(QPointF)));
	
	//---Добавляю состояния в автомат и запускаю его.------------------------------
	SM->addState(so);
	SM->addState(sf);
	SM->setInitialState(so);
	init();
	SM->start();
}
//

void NotWenImpl::on_difiniFonto_act_activated()
{
	bool b;
	QFont fnt = QFontDialog::getFont(&b, font());
	if(b){
		// Была нажата кнопка ОК.
		setFont(fnt);
	}
}

void NotWenImpl::on_helpo_action_activated()
{
	helpBrowserImpl *hb = new helpBrowserImpl( "doc/", "method6.htm", this);
	hb->resize(900, 600);
	hb->show();
}

void NotWenImpl::registriEraro()
{
	++KvantoEraroj;
	LogTxtBrsr->append(trUtf8("    Совершена ошибка. Общее количество ошибок: %1").arg(KvantoEraroj));
	QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Неправильное действие"));
	msg.exec();
	
	qDebug()<<trUtf8("Пользователь ошибся"); // Вывожу дебажную инфу на консоль.
}

void NotWenImpl::sf_entered()
{
	stackedWidget->setCurrentIndex(6);
	
	LogTxtBrsr->append(trUtf8("Конец алгоритма. Найден минимум функции: %1. Количество ошибок: <b>%2</b>.").arg(F->rezulto(BP)).arg(KvantoEraroj));
	if(F->metaObject()->className() == QString("RavinaFunkcio"))
	{
		if(D[7] == -1)
			LogTxtBrsr->append(trUtf8("Квадратичная функция не пройдена."));
		else
			LogTxtBrsr->append(trUtf8("Количество ошибок в квадратичной функции: <b>%1</b>.").arg(D[7]));
	}
	
	
	QString str = trUtf8("Найден минимум. ");
	
	if(KvantoEraroj > quanError){
		// Слишком много ошибок.
		str += trUtf8("Ваше количество ошибок (<b>%1</b>) превысило допустимый предел (%2). Начните заново.").arg(KvantoEraroj).arg(quanError);
		QMessageBox::information(this, trUtf8("Внимание"), str);
		if(F->metaObject()->className() == QString("RavinaFunkcio"))
			close();
		else recomenc_acn->trigger();
	}else{
		str += trUtf8("Вы прошли тест. ");
		if(F->metaObject()->className() == QString("KvadratigantoFunkcio"))
		{
			str += trUtf8("Сообщите преподавателю и перейдите к овражной функции. Количество ошибок: <b>%1</b>.").arg(KvantoEraroj);
			emit usiloPlenumis(A::NotWen, KvantoEraroj);
			QMessageBox::information(this, trUtf8("Поздравляем"), str);
			close();
		}
		else if(F->metaObject()->className() == QString("RavinaFunkcio"))
		{
			str += trUtf8("Позовите преподавателя. Количество ошибок: <b>%1</b>. ").arg(KvantoEraroj);
		
			if(D[7] == -1)
				str += trUtf8("Квадратичная функция не пройдена.");
			else
				str += trUtf8("Количество ошибок в квадратичной функции: <b>%1</b>.").arg(D[7]);

			QMessageBox::information(this, trUtf8("Поздравляем"), str);
		}
	}

	qDebug()<<trUtf8("Вошёл в Финальное состояние, сложного состояния"); // Вывожу дебажную инфу на консоль.
}

void NotWenImpl::s7_entered()
{
	if(F->metaObject()->className() == QString("KvadratigantoFunkcio"))
	{
		gessian1 = QPointF(2*F->getC(), - F->getE());
		gessian2 = QPointF(- F->getE(), 2*F->getA());
	}
	else if(F->metaObject()->className() == QString("RavinaFunkcio"))
	{
		gessian1 = QPointF(static_cast<RavinaFunkcio*>(F)->df_dx2dx2(), - static_cast<RavinaFunkcio*>(F)->df_dx1dx2(&BP));
		gessian2 = QPointF(- static_cast<RavinaFunkcio*>(F)->df_dx1dx2(&BP), static_cast<RavinaFunkcio*>(F)->df_dx1dx1(&BP));
	}
	
	BP = QPointF(BP.x() - (gessian1.x()*grad.x() + gessian1.y()*grad.y()) / F->detGessian(&BP), BP.y() - (gessian2.x()*grad.x() + gessian2.y()*grad.y()) / F->detGessian(&BP)); 

	qDebug()<<trUtf8("Вошёл в s7"); // Вывожу дебажную инфу на консоль.
	
	emit stateHasEntered(); // Переход по этому сигналу произойдёт, только если выполнится его условие.
}

void NotWenImpl::s6_entered()
{
	stackedWidget->setCurrentIndex(5);

	QString tmpX10, tmpX20;
	
	if(F->metaObject()->className() == QString("KvadratigantoFunkcio"))
	{
		groupBox_8->setVisible(true);
		tmpX10 = QString("%1*(x1%2%3)%4%5*(x2%6%7)").arg(2*F->getA()).arg(NotWenImpl::otrNumberSign(F->getB())).arg(fabs(F->getB())).arg(NotWenImpl::numberSign(F->getE())).arg(fabs(F->getE())).arg(NotWenImpl::otrNumberSign(F->getG())).arg(fabs(F->getG()));
		tmpX20 = QString("%1*(x2%2%3)%4%5*(x1%6%7)").arg(2*F->getC()).arg(NotWenImpl::otrNumberSign(F->getD())).arg(fabs(F->getD())).arg(NotWenImpl::numberSign(F->getE())).arg(fabs(F->getE())).arg(NotWenImpl::otrNumberSign(F->getF())).arg(fabs(F->getF()));
	}
	else if(F->metaObject()->className() == QString("RavinaFunkcio"))
	{
		groupBox_8->setVisible(false);
		tmpX10 = QString("%1*(x2-x1^2)*(-2*x1)%2%3*(1-x1)").arg(2*F->getA()).arg(NotWenImpl::numberSign(-2*F->getB())).arg(fabs(-2*F->getB()));
		tmpX20 = QString("%1*(x2-x1^2)").arg(2*F->getA());
	}

	label_23->setText(tmpX10);
	label_24->setText(tmpX20);
		
	LogTxtBrsr->append(trUtf8("  Длина градиента больше заданой точности - продолжаем минимизацию"));

	qDebug()<<trUtf8("Вошёл в s6"); // Вывожу дебажную инфу на консоль.
}

void NotWenImpl::s5_entered()
{
	stackedWidget->setCurrentIndex(4);
	
	length_grad_lb->setText(QString::number(Length(grad), 'f', 3));
	
	LogTxtBrsr->append(trUtf8("  Критерий остановки определен успешно"));

	if(NumeroIteracio > 5 && KvantoEraroj <= quanError)
	{
		if(Length(grad) >= strikteco)
		{
			to_continue->setChecked(true);
			next5_bt->click();
		}
		else
		{
			stop->setChecked(true);
			next5_bt->click();
		}
	}

	qDebug()<<trUtf8("Вошёл в s5"); // Вывожу дебажную инфу на консоль.
}

void NotWenImpl::s4_entered()
{
	stackedWidget->setCurrentIndex(3);
	
	grad = QPointF(F->df_dx1(BP), F->df_dx2(BP));
	
	if (NumeroIteracio == 1)
		LogTxtBrsr->append(trUtf8("  Введён градиент"));
	else if (NumeroIteracio > 1)
		LogTxtBrsr->append(trUtf8("  Определение координат вектора градиента дано успешно"));

	if(NumeroIteracio > 5 && KvantoEraroj <= quanError)
	{
		gradfxk_less->setChecked(true);
		next4_bt->click();
	}

	qDebug()<<trUtf8("Вошёл в s4"); // Вывожу дебажную инфу на консоль.
}

void NotWenImpl::s3_entered()
{
	stackedWidget->setCurrentIndex(2);
	
	LogTxtBrsr->append(trUtf8("  Определение координат вектора градиента дано успешно"));

	qDebug()<<trUtf8("Вошёл в s3"); // Вывожу дебажную инфу на консоль.
}

void NotWenImpl::s2_entered()
{
	stackedWidget->setCurrentIndex(1);
	
	LogTxtBrsr->append(trUtf8("  Направление поиска определено успешно"));

	if(NumeroIteracio > 5 && KvantoEraroj <= quanError)
	{
		part_proizvod_first->setChecked(true);
		next2_bt->click();
	}

	qDebug()<<trUtf8("Вошёл в s2"); // Вывожу дебажную инфу на консоль.
}

void NotWenImpl::s1_entered()
{
	if(NumeroIteracio >= 1)
	{
		gxk->setChecked(true);
		proizvod_first->setChecked(true);
		fxk1_fxk->setChecked(true);
		stop->setChecked(true);
	}
	
	length_grad_lb->setText("");
	
	stackedWidget->setCurrentIndex(0);
	
	LogTxtBrsr->append(trUtf8("Итерация № %1.").arg(++NumeroIteracio));

	if(NumeroIteracio > 5 && KvantoEraroj <= quanError)
	{
		qApp->processEvents();
		_g_xkgradfxk->setChecked(true);
		next1_bt->click();
	}
	else if(NumeroIteracio > 5 && KvantoEraroj > quanError)
	{
			QString str = trUtf8("Ваше количество ошибок (<b>%1</b>) превысило допустимый предел (%2). Вернитесь к квадратиной функции.").arg(KvantoEraroj).arg(quanError);
			QMessageBox::information(this, trUtf8("Внимание"), str);
			close();
	}
	
	qDebug()<<trUtf8("Вошёл в s1"); // Вывожу дебажную инфу на консоль.
}

void NotWenImpl::so_entered()
{
	MapoWdg->setScale(10);// Ставлю масштаб побольше. Надо будет определться с оптимальным значением.

	qDebug()<<trUtf8("Вошёл в so"); // Вывожу дебажныю инфу на консоль.
}

void NotWenImpl::init()
{
	static_cast<spuroSinkoLauxKoordinatoj_md*>(Sp)->senspurigi();

	precision_lb->setText(QString::number(strikteco));
	KvantoEraroj = 0;
	NumeroIteracio = 0;
	BP = QPointF(D[4],D[5]);
	quanError = (int)D[6];
	LogTxtBrsr->setText("");

	qDebug()<<trUtf8("Задаю переменным начальные значения"); // Вывожу дебажную инфу на консоль.
}

bool NotWenImpl::DerivativeQuad(funkcio * F, DemonstrataQPointF * BP,
					QLineEdit * dfdx1, QLineEdit * dfdx2)
{
	//создаем исполняемую среду скрипта
	QScriptEngine engine;
	
	QString Dfdx1 = trUtf8("x1=%1; x2=%2;").arg(BP->x()).arg(BP->y());
	Dfdx1 += dfdx1->text() + ";";
	QString Dfdx2 = trUtf8("x1=%1; x2=%2;").arg(BP->x()).arg(BP->y());
	Dfdx2 += dfdx2->text() + ";";
	
	QScriptValue Derivativex1 = engine.evaluate(Dfdx1);
	QScriptValue Derivativex2 = engine.evaluate(Dfdx2);
	
	return fabs(Derivativex1.toNumber() - F->df_dx1(*BP)) <= 0.000001 &&
			fabs(Derivativex2.toNumber() - F->df_dx2(*BP)) <= 0.000001 ;
}

bool NotWenImpl::DerivativeRavin(funkcio * F, DemonstrataQPointF * BP,
					QLineEdit * dfdx1, QLineEdit * dfdx2)
{
	//создаем исполняемую среду скрипта
	QScriptEngine engine;
	
	QString Dfdx1 = trUtf8("x1=%1; x2=%2;").arg(BP->x()).arg(BP->y());
	
	QString tmp = dfdx1->text();
	int j = 0;
	while(!(tmp[j] == '^'))
		++j;
	for(int i = j; i >= 0; --i)
		if(tmp[i] == '1')
		{
			if(tmp[j+1] == '2')
				tmp.replace(j, 2, "*x1");
			else if(tmp[j+1] == '3')
				tmp.replace(j, 2, "*x1*x1");
			break;
		}
	
	Dfdx1 += tmp + ";";
	QString Dfdx2 = trUtf8("x1=%1; x2=%2;").arg(BP->x()).arg(BP->y());
	
	tmp = dfdx2->text();
	j = 0;
	while(!(tmp[j] == '^' && tmp[j+1] == '2'))
		++j;
	for(int i = j; i >= 0; --i)
		if(tmp[i] == '1')
		{
			tmp.replace(j, 2, "*x1");
			break;
		}
	
	Dfdx2 += tmp + ";";
	
	QScriptValue Derivativex1 = engine.evaluate(Dfdx1);
	QScriptValue Derivativex2 = engine.evaluate(Dfdx2);
	
	return fabs(Derivativex1.toNumber() - F->df_dx1(*BP)) <= 0.000001 &&
			fabs(Derivativex2.toNumber() - F->df_dx2(*BP)) <= 0.000001 ;
}

bool NotWenImpl::aGessQuad(funkcio * F, DemonstrataQPointF * BP,
					QLineEdit * gess11, QLineEdit * gess12,
					QLineEdit * gess21, QLineEdit * gess22)
{
	//создаем исполняемую среду скрипта
	QScriptEngine engine;
	
	QScriptValue Gess11 = engine.evaluate(gess11->text());
	QScriptValue Gess12 = engine.evaluate(gess12->text());
	QScriptValue Gess21 = engine.evaluate(gess21->text());
	QScriptValue Gess22 = engine.evaluate(gess22->text());
	
	return fabs(Gess11.toNumber() - (2*F->getC() / F->detGessian(BP))) <= 0.000001 &&
			fabs(Gess12.toNumber() - (-F->getE() / F->detGessian(BP))) <= 0.000001 &&
			fabs(Gess21.toNumber() - (-F->getE() / F->detGessian(BP))) <= 0.000001 &&
			fabs(Gess22.toNumber() - (2*F->getA() / F->detGessian(BP))) <= 0.000001 ;
}

bool NotWenImpl::GessRavin(funkcio * F, DemonstrataQPointF * BP,
					QLineEdit * Dfdx1dx1, QLineEdit * Dfdx1dx2,
					QLineEdit * Dfdx2dx1, QLineEdit * Dfdx2dx2)
{
	//создаем исполняемую среду скрипта
	QScriptEngine engine;
	
	QString dfdx1dx1 = trUtf8("x1=%1; x2=%2;").arg(BP->x()).arg(BP->y());
	
	QString tmp = Dfdx1dx1->text();
	int j = 0;
	while(!(tmp[j] == '^' && tmp[j+1] == '2'))
		++j;
	for(int i = j; i >= 0; --i)
		if(tmp[i] == '1')
		{
			tmp.replace(j, 2, "*x1");
			break;
		}
	
	dfdx1dx1 += tmp + ";";
	QString dfdx1dx2 = trUtf8("x1=%1; x2=%2;").arg(BP->x()).arg(BP->y());
	dfdx1dx2 += Dfdx1dx2->text() + ";";
	QString dfdx2dx1 = trUtf8("x1=%1; x2=%2;").arg(BP->x()).arg(BP->y());
	dfdx2dx1 += Dfdx2dx1->text() + ";";
	QString dfdx2dx2 = Dfdx2dx2->text();
	
	QScriptValue Gess11 = engine.evaluate(dfdx1dx1);
	QScriptValue Gess12 = engine.evaluate(dfdx1dx2);
	QScriptValue Gess21 = engine.evaluate(dfdx2dx1);
	QScriptValue Gess22 = engine.evaluate(dfdx2dx2);
	
	return fabs(Gess11.toNumber() - static_cast<RavinaFunkcio*>(F)->df_dx1dx1(BP)) <= 0.000001 &&
			fabs(Gess12.toNumber() - static_cast<RavinaFunkcio*>(F)->df_dx1dx2(BP)) <= 0.000001 &&
			fabs(Gess21.toNumber() - static_cast<RavinaFunkcio*>(F)->df_dx1dx2(BP)) <= 0.000001 &&
			fabs(Gess22.toNumber() - static_cast<RavinaFunkcio*>(F)->df_dx2dx2()) <= 0.000001 ;
}

namespace SinkoNotWen
{
	bool s1s2Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбрано -G^-1(Xk)*grad F(Xk)");
			// Проверяю своё условие.
			return _G_xkgradfxk->isChecked();
		}
		else
			return false;
	}

	bool s2s3Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбрано частные первые производные и первая итерация");
			// Проверяю своё условие.
			return Part_proizvod_first->isChecked() && *numberIterac == 1;
		}
		else
			return false;
	}

	bool s2s4Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбрано частные первые производные и не первая итерация");
			// Проверяю своё условие.
			return Part_proizvod_first->isChecked() && *numberIterac > 1;
		}
		else
			return false;
	}

	bool s3s4Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что введен градиент");
			// Проверяю своё условие.

			if(f->metaObject()->className() == QString("KvadratigantoFunkcio"))
				if(NotWenImpl::DerivativeQuad(f, bp, df_dx1, df_dx2))
					return true;
				else
					return false;
			else if(f->metaObject()->className() == QString("RavinaFunkcio"))
				if(NotWenImpl::DerivativeRavin(f, bp, df_dx1, df_dx2))
					return true;
				else
					return false;
		}
		else
			return false;
	}

	bool s4s5Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбран критерий |grad F(Xk)| < e");
			// Проверяю своё условие.
			return Gradfxk_less->isChecked();
		}
		else
			return false;
	}

	bool s5s6Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю |grad f(X)| >= e && первая итерация && выбран пункт продолжить");
			// Проверяю своё условие.
			return Length(*Grad) >= s && *numberIterac == 1 && To_continue->isChecked(); 
		}
		else
			return false;
	}

	bool s5s7Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю |grad f(X)| >= e && не первая итерация && выбран пункт продолжить");
			// Проверяю своё условие.
			return Length(*Grad) >= s && *numberIterac > 1 && To_continue->isChecked(); 
		}
		else
			return false;
	}

	bool s5sfTransiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю |grad f(X)| < e && выбран пункт останвить");
			// Проверяю своё условие.
			return Length(*Grad) < s && Stop->isChecked();
		}
		else
			return false;
	}

	bool s6s7Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что правильно введен гессиан и обратный гессиан");

			if(f->metaObject()->className() == QString("KvadratigantoFunkcio"))
			{
				if(Dfdx1dx1->text() == QString::number(2*f->getA()) && Dfdx1dx2->text() == QString::number(f->getE()) && 
					Dfdx2dx1->text() == QString::number(f->getE()) && Dfdx2dx2->text() == QString::number(2*f->getC()) &&
					NotWenImpl::aGessQuad(f, bp, Gess11, Gess12, Gess21, Gess22))
				{
					return true;
				}
				else
					return false;
				
			}
			else if(f->metaObject()->className() == QString("RavinaFunkcio"))
			{
				if(NotWenImpl::GessRavin(f, bp, Dfdx1dx1, Dfdx1dx2, Dfdx2dx1, Dfdx2dx2))
				{
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
};
//

void NotWenImpl::on_about_action_activated(){
	aboutProgramImpl * about = new aboutProgramImpl(this);
	about->show();
}
