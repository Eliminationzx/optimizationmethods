#include "fasterdescentimpl.h"
#include "mapoporfunkcioimpl.h"
#include "Konstantoj.h"
#include "funkcio.h"
#include "spuro.h"
#include "spurosinkolauxkoordinatoj.h"
#include "demonstrataqpointf.h"
#include "signalantoporpointf.h"
#include "helpbrowserimpl.h"
#include "math.h"
#include <QTextBrowser>
#include <QString>
#include <QMessageBox>
#include <QStateMachine>
#include <QFinalState>
#include <QLabel>
#include <QFontDialog>
#include <QDebug>
//
using namespace SinkoFD;

FasterDescentImpl::FasterDescentImpl( funkcio *f, QVector<double> *d, QWidget * parent, Qt::WFlags flags)
	: AlgoritmoWin(f, d, parent, flags)
{
	setupUi(this);
	connect(exit, SIGNAL(activated()), qApp, SLOT(closeAllWindows()));

	qDebug()<<trUtf8("Наискорейший спуск"); // Вывожу дебажную инфу на консоль.

// Для овражной функции убираю действие "Начать заново"
	if(F->metaObject()->className() == QString("RavinaFunkcio")){
		menubar->removeAction(recomenc_acn);
	}

	//Вывожу формулу функции.
	func->setText(textoFunkcio());

	// Создаю карту.
	// centralwidget->layout() - указатель на компановщик центрального виджета
	// static_cast<QGridLayout*>(centralwidget->layout()) - обьясняю компилятору, что это именно QGridLayout
	// добавляю вижет карты в позицию 1,1. Компановщик сам позаботится о назначении новому виджету родителя.
	static_cast<QGridLayout*>(centralwidget->layout())->addWidget(MapoWdg, 2, 1);

	MapoWdg->setScale(20);// Ставлю масштаб побольше. Надо будет определться с оптимальным значением.

	Sp = new spuroSinkoLauxKoordinatoj(Qt::white, Qt::blue);
	MapoWdg->difiniSpuro(Sp);
	MapoWdg->difiniFonaKoloro(Qt::green);

	connect(MapoWdg, SIGNAL(MusaPos(const QString &)), statusBar(), SLOT(showMessage( const QString &)));

	//===Соединяю точки и надписи на форме=========================================
	SignalantoPorPointF * sBP = new SignalantoPorPointF(&BP, F, this);
	connect(sBP, SIGNAL(proviziXValoro(const QString &)), x1_lb, SLOT(setText(const QString &)));
	connect(sBP, SIGNAL(proviziYValoro(const QString &)), x2_lb, SLOT(setText(const QString &)));
	connect(sBP, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), fsign_lb, SLOT(setText(const QString &)));
	SignalantoPorPointF * sGRAD = new SignalantoPorPointF(&grad, F, this);
	connect(sGRAD, SIGNAL(proviziXValoro(const QString &)), s_x1_lb, SLOT(setText(const QString &)));
	connect(sGRAD, SIGNAL(proviziYValoro(const QString &)), s_x2_lb, SLOT(setText(const QString &)));
	SignalantoPorPointF * sLengthStep = new SignalantoPorPointF(&lengthStep, F, this);
	connect(sLengthStep, SIGNAL(proviziXValoro(const QString &)), length_step_a_lb, SLOT(setText(const QString &)));

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
	QState * s8 = new QState(so);
	QState * s9 = new QState(so);
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
	connect(s8, SIGNAL(entered()), SLOT(s8_entered()));
	connect(s9, SIGNAL(entered()), SLOT(s9_entered()));
	connect(sf, SIGNAL(entered()), SLOT(sf_entered()));

	//---Создаю переходы, согласно диаграмме.--------------------------------------
	s1s2Transiro * s1s2 = new s1s2Transiro(inserts_bt, SIGNAL(clicked()), s1);
	s1s2->setTargetState(s2);
	s2s3Transiro * s2s3 = new s2s3Transiro(&NumeroIteracio, agrad_fx, next1_bt, SIGNAL(clicked()), s2);
	s2s3->setTargetState(s3);
	s2s4Transiro * s2s4 = new s2s4Transiro(&NumeroIteracio, agrad_fx, next1_bt, SIGNAL(clicked()), s2);
	s2s4->setTargetState(s4);
	s3s4Transiro * s3s4 = new s3s4Transiro(F, dfdx1, dfdx2, next2_bt, SIGNAL(clicked()), s3);
	s3s4->setTargetState(s4);
	s4s5Transiro * s4s5 = new s4s5Transiro(check_bt, SIGNAL(clicked()), s4);
	s4s5->setTargetState(s5);
	s5s6Transiro * s5s6 = new s5s6Transiro(gradfx, next3_bt, SIGNAL(clicked()), s5);
	s5s6->setTargetState(s6);
	s6s7Transiro * s6s7 = new s6s7Transiro(&grad, strikteco, calcula_bt, SIGNAL(clicked()), s6);
	s6s7->setTargetState(s7);
	s6sfTransiro * s6sf = new s6sfTransiro(&grad, strikteco, end_bt, SIGNAL(clicked()), s6);
	s6sf->setTargetState(sf);
	s7s8Transiro * s7s8 = new s7s8Transiro(minf, next4_bt, SIGNAL(clicked()), s7);
	s7s8->setTargetState(s8);
	s8s9Transiro * s8s9 = new s8s9Transiro(&BP, &grad, step_bt, SIGNAL(clicked()), s8);
	s8s9->setTargetState(s9);
	s9->addTransition(this, SIGNAL(stateHasEntered()), s1);

	//---Создаю переход по действию "Начать заново"
	connect(so->addTransition(recomenc_acn, SIGNAL(activated()), s1), SIGNAL(triggered()), SLOT(init()));
	connect(sf->addTransition(recomenc_acn, SIGNAL(activated()), s1), SIGNAL(triggered()), SLOT(init()));

	//---Создаю переходы не имеющие цели. С помощью них фиксирую ошибки ползователя
	QSignalTransition * te1 = new QSignalTransition(inserts_bt, SIGNAL(clicked()));
	so->addTransition(te1);
	connect(te1, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te2 = new QSignalTransition(calcula_bt, SIGNAL(clicked()));
	so->addTransition(te2);
	connect(te2, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te3 = new QSignalTransition(check_bt, SIGNAL(clicked()));
	so->addTransition(te3);
	connect(te3, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te4 = new QSignalTransition(step_bt, SIGNAL(clicked()));
	so->addTransition(te4);
	connect(te4, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te5 = new QSignalTransition(end_bt, SIGNAL(clicked()));
	so->addTransition(te5);
	connect(te5, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te6 = new QSignalTransition(next1_bt, SIGNAL(clicked()));
	so->addTransition(te6);
	connect(te6, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te7 = new QSignalTransition(next2_bt, SIGNAL(clicked()));
	so->addTransition(te7);
	connect(te7, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te8 = new QSignalTransition(next3_bt, SIGNAL(clicked()));
	so->addTransition(te8);
	connect(te8, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te9 = new QSignalTransition(next4_bt, SIGNAL(clicked()));
	so->addTransition(te9);
	connect(te9, SIGNAL(triggered()), SLOT(registriEraro()));

	//---Настраиваю выделение цветом растояния между точками.
/*	s6->assignProperty(length_grad_lb, "palette", QPalette(Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red));
	s1->assignProperty(length_grad_lb, "palette", this->palette());
*/
	//---Прикручиваю карту---------------------------------------------------------
	connect(sBP, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(difiniMomentaPointo(QPointF)));

	connect(s9, SIGNAL(entered()), Sp, SLOT(reveniAlMomentoPointo()));

	connect(s1, SIGNAL(entered()), Sp, SLOT(finisxiIteracio()));
	
	//---Добавляю состояния в автомат и запускаю его.------------------------------
	SM->addState(so);
	SM->addState(sf);
	SM->setInitialState(so);
	init();
	SM->start();
}
//

void FasterDescentImpl::on_difiniFonto_act_activated()
{
	bool b;
	QFont fnt = QFontDialog::getFont(&b, font());
	if(b){
		// Была нажата кнопка ОК.
		setFont(fnt);
	}
}

void FasterDescentImpl::on_helpo_action_activated()
{
	helpBrowserImpl *hb = new helpBrowserImpl( "doc/", "method3.htm", this);
	hb->resize(900, 600);
	hb->show();
}

void FasterDescentImpl::registriEraro()
{
	++KvantoEraroj;
	LogTxtBrsr->append(trUtf8("    Совершена ошибка. Общее количество ошибок: %1").arg(KvantoEraroj));
	QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Неправильное действие"));
	msg.exec();
	
	qDebug()<<trUtf8("Пользователь ошибся"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::sf_entered()
{
	LogTxtBrsr->append(trUtf8("Конец алгоритма. Найден минимум функции: %1").arg(F->rezulto(BP)));
	
	QString str = trUtf8("Найден минимум. ");
	
	if(KvantoEraroj > quanError){
		// Слишком много ошибок.
		str += trUtf8("Ваше количество ошибок (%1) превысило допустимый предел (%2). Начните заново.").arg(KvantoEraroj).arg(quanError);
		QMessageBox::information(this, trUtf8("Внимание"), str);
		if(F->metaObject()->className() == QString("RavinaFunkcio"))
			emit usiloPlenumis(A::FasterDescent);
		else recomenc_acn->trigger();
	}else{
		str += trUtf8("Вы прошли тест. ");
		if(F->metaObject()->className() == QString("KvadratigantoFunkcio"))
		{
			str += trUtf8("Сообщите преподавателю и перейдите к овражной функции. Количество ошибок: %1.").arg(KvantoEraroj);
			emit usiloPlenumis(A::FasterDescent);
		}
		else if(F->metaObject()->className() == QString("RavinaFunkcio"))
		{
			str += trUtf8("Позовите преподавателя. Количество ошибок: %1.").arg(KvantoEraroj);
		}
		QMessageBox::information(this, trUtf8("Поздравляем"), str);
	}

	qDebug()<<trUtf8("Вошёл в Финальное состояние, сложного состояния"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::s9_entered()
{
	BP = QPointF(BP.x() - lengthStep.x()*grad.x(), BP.y() - lengthStep.x()*grad.y()); 

	qDebug()<<trUtf8("Вошёл в s9"); // Вывожу дебажную инфу на консоль.
	
	emit stateHasEntered(); // Переход по этому сигналу произойдёт, только если выполнится его условие.
}

void FasterDescentImpl::s8_entered()
{
	stackedWidget->setCurrentIndex(4);
	
	lengthStep = QPointF(F->lengthOfStep(grad), 0);

	LogTxtBrsr->append(trUtf8("  а вычислено успешно"));

	if(F->metaObject()->className() == QString("RavinaFunkcio") && NumeroIteracio > 5 && KvantoEraroj <= quanError)
		step_bt->click();

	qDebug()<<trUtf8("Вошёл в s8"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::s7_entered()
{
	stackedWidget->setCurrentIndex(3);

	LogTxtBrsr->append(trUtf8("  Вычисляем а"));

	if(F->metaObject()->className() == QString("RavinaFunkcio") && NumeroIteracio > 5 && KvantoEraroj <= quanError)
	{
		minf->setChecked(true);
		next4_bt->click();
	}

	qDebug()<<trUtf8("Вошёл в s7"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::s6_entered()
{
	stackedWidget->setCurrentIndex(4);
	
	length_grad_lb->setText(QString::number(Length(grad), 'f'));
	
	LogTxtBrsr->append(trUtf8("  Проверка точности выполнена"));

	if(F->metaObject()->className() == QString("RavinaFunkcio") && NumeroIteracio > 5 && KvantoEraroj <= quanError)
	{
		if(Length(grad) >= strikteco)
			calcula_bt->click();
		else
			end_bt->click();
	}

	qDebug()<<trUtf8("Вошёл в s6"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::s5_entered()
{
	stackedWidget->setCurrentIndex(2);

	LogTxtBrsr->append(trUtf8("  Проверка точности"));

	if(F->metaObject()->className() == QString("RavinaFunkcio") && NumeroIteracio > 5 && KvantoEraroj <= quanError)
	{
		gradfx->setChecked(true);
		next3_bt->click();
	}

	qDebug()<<trUtf8("Вошёл в s5"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::s4_entered()
{
	stackedWidget->setCurrentIndex(4);
	
	grad = QPointF(F->df_dx1(BP), F->df_dx2(BP));
	
	if (NumeroIteracio == 1)
		LogTxtBrsr->append(trUtf8("  Введён градиент"));
	else if (NumeroIteracio > 1)
		LogTxtBrsr->append(trUtf8("  S определено успешно"));

	if(F->metaObject()->className() == QString("RavinaFunkcio") && NumeroIteracio > 5 && KvantoEraroj <= quanError)
		check_bt->click();

	qDebug()<<trUtf8("Вошёл в s4"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::s3_entered()
{
	stackedWidget->setCurrentIndex(1);
	
	LogTxtBrsr->append(trUtf8("  S определено успешно"));

	qDebug()<<trUtf8("Вошёл в s3"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::s2_entered()
{
	stackedWidget->setCurrentIndex(0);

	LogTxtBrsr->append(trUtf8("  Определяем S"));

	if(F->metaObject()->className() == QString("RavinaFunkcio") && NumeroIteracio > 5 && KvantoEraroj <= quanError)
	{
		agrad_fx->setChecked(true);
		next1_bt->click();
	}

	qDebug()<<trUtf8("Вошёл в s2"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::s1_entered()
{
	grad_fx->setChecked(true);
	fxk_fx->setChecked(true);
	two->setChecked(true);
	
	stackedWidget->setCurrentIndex(4);
	
	LogTxtBrsr->append(trUtf8("Итерация № %1.").arg(++NumeroIteracio));

	if(F->metaObject()->className() == QString("RavinaFunkcio") && NumeroIteracio > 5 && KvantoEraroj <= quanError)
	{
		qApp->processEvents();
		inserts_bt->click();
	}
	
	qDebug()<<trUtf8("Вошёл в s1"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::so_entered()
{
	qDebug()<<trUtf8("Вошёл в so"); // Вывожу дебажныю инфу на консоль.
}

void FasterDescentImpl::init()
{
	precision_lb->setText(QString::number(strikteco));
	KvantoEraroj = 0;
	NumeroIteracio = 0;
	BP = QPointF(D[4],D[5]);
	quanError = (int)D[6];
	LogTxtBrsr->setText("");

	static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->senspurigi();
	static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->difiniUnuaPointo(BP);

	qDebug()<<trUtf8("Задаю переменным начальные значения"); // Вывожу дебажную инфу на консоль.
}

namespace SinkoFD
{
	bool s1s2Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбран ввод S");
			// Проверяю своё условие.
			return true;
		}
		else
			return false;
	}

	bool s2s3Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбран антиградиент и первая итерация");
			// Проверяю своё условие.
			return aGrad_fx->isChecked() && *numberIterac == 1;
		}
		else
			return false;
	}

	bool s2s4Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбран антиградиент и не первая итерация");
			// Проверяю своё условие.
			return aGrad_fx->isChecked() && *numberIterac > 1;
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
			
			QString tmpX10, tmpX11;
			QString tmpX20, tmpX21;
			
			// Обрабатываю случаи, когда коэффициенты перед скобками равны 1, 0, -1 и другим значениям
			if(f->metaObject()->className() == QString("KvadratigantoFunkcio"))
			{
				if((2*f->getA() != 1 && 2*f->getA() != 0 && 2*f->getA() != -1) && (f->getE() == 1))
					tmpX11 = QString("%1*(x1%2%3)+(x2%4%5)").arg(2*f->getA()).arg(FasterDescentImpl::otrNumberSign(f->getB())).arg(fabs(f->getB())).arg(FasterDescentImpl::otrNumberSign(f->getG())).arg(fabs(f->getG()));
				else if((2*f->getA() != 1 && 2*f->getA() != 0 && 2*f->getA() != -1) && (f->getE() == 0))
					tmpX11 = QString("%1*(x1%2%3)").arg(2*f->getA()).arg(FasterDescentImpl::otrNumberSign(f->getB())).arg(fabs(f->getB()));
				else if((2*f->getA() != 1 && 2*f->getA() != 0 && 2*f->getA() != -1) && (f->getE() == -1))
					tmpX11 = QString("%1*(x1%2%3)-(x2%4%5)").arg(2*f->getA()).arg(FasterDescentImpl::otrNumberSign(f->getB())).arg(fabs(f->getB())).arg(FasterDescentImpl::otrNumberSign(f->getG())).arg(fabs(f->getG()));

				else if((2*f->getA() == 1) && (f->getE() != 1 && f->getE() != 0 && f->getE() != -1))
					tmpX11 = QString("(x1%1%2)%3%4*(x2%5%6)").arg(FasterDescentImpl::otrNumberSign(f->getB())).arg(fabs(f->getB())).arg(FasterDescentImpl::numberSign(f->getE())).arg(fabs(f->getE())).arg(FasterDescentImpl::otrNumberSign(f->getG())).arg(fabs(f->getG()));
				else if((2*f->getA() == 1) && (f->getE() == 1))
					tmpX11 = QString("(x1%1%2)+(x2%3%4)").arg(FasterDescentImpl::otrNumberSign(f->getB())).arg(fabs(f->getB())).arg(FasterDescentImpl::otrNumberSign(f->getG())).arg(fabs(f->getG()));
				else if((2*f->getA() == 1) && (f->getE() == 0))
					tmpX11 = QString("(x1%1%2)").arg(FasterDescentImpl::otrNumberSign(f->getB())).arg(fabs(f->getB()));
				else if((2*f->getA() == 1) && (f->getE() == -1))
					tmpX11 = QString("(x1%1%2)-(x2%3%4)").arg(FasterDescentImpl::otrNumberSign(f->getB())).arg(fabs(f->getB())).arg(FasterDescentImpl::otrNumberSign(f->getG())).arg(fabs(f->getG()));

				else if((2*f->getA() == 0) && (f->getE() != 1 && f->getE() != 0 && f->getE() != -1))
					tmpX11 = QString("%1*(x2%2%3)").arg(f->getE()).arg(FasterDescentImpl::otrNumberSign(f->getG())).arg(fabs(f->getG()));
				else if((2*f->getA() == 0) && (f->getE() == 1))
					tmpX11 = QString("(x2%1%%2)").arg(FasterDescentImpl::otrNumberSign(f->getG())).arg(fabs(f->getG()));
				else if((2*f->getA() == 0) && (f->getE() == 0))
					tmpX11 = QString("0");
				else if((2*f->getA() == 0) && (f->getE() == -1))
					tmpX11 = QString("-(x2%1%%2)").arg(FasterDescentImpl::otrNumberSign(f->getG())).arg(fabs(f->getG()));

				else if((2*f->getA() == -1) && (f->getE() != 1 && f->getE() != 0 && f->getE() != -1))
					tmpX11 = QString("-(x1%1%2)%3%4*(x2%5%6)").arg(FasterDescentImpl::otrNumberSign(f->getB())).arg(fabs(f->getB())).arg(FasterDescentImpl::numberSign(f->getE())).arg(fabs(f->getE())).arg(FasterDescentImpl::otrNumberSign(f->getG())).arg(fabs(f->getG()));
				else if((2*f->getA() == -1) && (f->getE() == 1))
					tmpX11 = QString("-(x1%1%2)+(x2%3%4)").arg(FasterDescentImpl::otrNumberSign(f->getB())).arg(fabs(f->getB())).arg(FasterDescentImpl::otrNumberSign(f->getG())).arg(fabs(f->getG()));
				else if((2*f->getA() == -1) && (f->getE() == 0))
					tmpX11 = QString("-(x1%1%2)").arg(FasterDescentImpl::otrNumberSign(f->getB())).arg(fabs(f->getB()));
				else if((2*f->getA() == -1) && (f->getE() == -1))
					tmpX11 = QString("-(x1%1%2)-(x2%3%4)").arg(FasterDescentImpl::otrNumberSign(f->getB())).arg(fabs(f->getB())).arg(FasterDescentImpl::otrNumberSign(f->getG())).arg(fabs(f->getG()));

					
				if((2*f->getC() != 1 && 2*f->getC() != 0) && 2*f->getC() != -1 && (f->getE() == 1))
					tmpX21 = QString("%1*(x2%2%3)+(x1%4%5)").arg(2*f->getC()).arg(FasterDescentImpl::otrNumberSign(f->getD())).arg(f->getD()).arg(FasterDescentImpl::otrNumberSign(f->getF())).arg(f->getF());
				else if((2*f->getC() != 1 && 2*f->getC() != 0 && 2*f->getC() != -1) && (f->getE() == 0))
					tmpX21 = QString("%1*(x2%2%3)").arg(2*f->getC()).arg(FasterDescentImpl::otrNumberSign(f->getD())).arg(f->getD());
				if((2*f->getC() != 1 && 2*f->getC() != 0) && 2*f->getC() != -1 && (f->getE() == -1))
					tmpX21 = QString("%1*(x2%2%3)-(x1%4%5)").arg(2*f->getC()).arg(FasterDescentImpl::otrNumberSign(f->getD())).arg(f->getD()).arg(FasterDescentImpl::otrNumberSign(f->getF())).arg(f->getF());

				else if((2*f->getC() == 1) && (f->getE() != 1 && f->getE() != 0 && f->getE() != -1))
					tmpX21 = QString("(x2%1%2)%3%4*(x1%5%6)").arg(FasterDescentImpl::otrNumberSign(f->getD())).arg(f->getD()).arg(FasterDescentImpl::numberSign(f->getE())).arg(f->getE()).arg(FasterDescentImpl::otrNumberSign(f->getF())).arg(f->getF());
				else if((2*f->getC() == 1) && (f->getE() == 1))
					tmpX21 = QString("(x2%1%2)+(x1%3%4)").arg(FasterDescentImpl::otrNumberSign(f->getD())).arg(f->getD()).arg(FasterDescentImpl::otrNumberSign(f->getF())).arg(f->getF());
				else if((2*f->getC() == 1) && (f->getE() == 0))
					tmpX21 = QString("(x2%1%2)").arg(FasterDescentImpl::otrNumberSign(f->getD())).arg(f->getD());
				else if((2*f->getC() == 1) && (f->getE() == -1))
					tmpX21 = QString("(x2%1%2)-(x1%3%4)").arg(FasterDescentImpl::otrNumberSign(f->getD())).arg(f->getD()).arg(FasterDescentImpl::otrNumberSign(f->getF())).arg(f->getF());

				else if((2*f->getC() == 0) && (f->getE() != 1 && f->getE() != 0 && f->getE() != -1))
					tmpX21 = QString("%1*(x1%2%3)").arg(f->getE()).arg(FasterDescentImpl::otrNumberSign(f->getF())).arg(f->getF());
				else if((2*f->getC() == 0) && (f->getE() == 1))
					tmpX21 = QString("(x1%1%2)").arg(FasterDescentImpl::otrNumberSign(f->getF())).arg(f->getF());
				else if((2*f->getC() == 0) && (f->getE() == 0))
					tmpX21 = QString("0");
				else if((2*f->getC() == 0) && (f->getE() == -1))
					tmpX21 = QString("-(x1%1%2)").arg(FasterDescentImpl::otrNumberSign(f->getF())).arg(f->getF());

				else if((2*f->getC() == -1) && (f->getE() != 1 && f->getE() != 0 && f->getE() != -1))
					tmpX21 = QString("-(x2%1%2)%3%4*(x1%5%6)").arg(FasterDescentImpl::otrNumberSign(f->getD())).arg(f->getD()).arg(FasterDescentImpl::numberSign(f->getE())).arg(f->getE()).arg(FasterDescentImpl::otrNumberSign(f->getF())).arg(f->getF());
				else if((2*f->getC() == -1) && (f->getE() == 1))
					tmpX21 = QString("-(x2%1%2)+(x1%3%4)").arg(FasterDescentImpl::otrNumberSign(f->getD())).arg(f->getD()).arg(FasterDescentImpl::otrNumberSign(f->getF())).arg(f->getF());
				else if((2*f->getC() == -1) && (f->getE() == 0))
					tmpX21 = QString("-(x2%1%2)").arg(FasterDescentImpl::otrNumberSign(f->getD())).arg(f->getD());
				else if((2*f->getC() == -1) && (f->getE() == -1))
					tmpX21 = QString("-(x2%1%2)-(x1%3%4)").arg(FasterDescentImpl::otrNumberSign(f->getD())).arg(f->getD()).arg(FasterDescentImpl::otrNumberSign(f->getF())).arg(f->getF());

				tmpX10 = QString("%1*(x1%2%3)%4%5*(x2%6%7)").arg(2*f->getA()).arg(FasterDescentImpl::otrNumberSign(f->getB())).arg(fabs(f->getB())).arg(FasterDescentImpl::numberSign(f->getE())).arg(fabs(f->getE())).arg(FasterDescentImpl::otrNumberSign(f->getG())).arg(fabs(f->getG()));
				tmpX20 = QString("%1*(x2%2%3)%4%5*(x1%6^7)").arg(2*f->getC()).arg(FasterDescentImpl::otrNumberSign(f->getD())).arg(fabs(f->getD())).arg(FasterDescentImpl::numberSign(f->getE())).arg(fabs(f->getE())).arg(FasterDescentImpl::otrNumberSign(f->getF())).arg(fabs(f->getF()));
			}
			else if(f->metaObject()->className() == QString("RavinaFunkcio"))
			{
				if((-4*f->getA() != 1 && -4*f->getA() != 0 && -4*f->getA() != -1) && (2*f->getB() == 1))
					tmpX11 = QString("%1*(x2*x1-x1^3)+(1-x1)").arg(-4*f->getA());
				else if((-4*f->getA() != 1 && -4*f->getA() != 0  && -4*f->getA() != -1) && (2*f->getB() == 0))
					tmpX11 = QString("%1*(x2*x1-x1^3)").arg(-4*f->getA());
				else if((-4*f->getA() != 1 && -4*f->getA() != 0  && -4*f->getA() != -1) && (2*f->getB() == -1))
					tmpX11 = QString("%1*(x2*x1-x1^3)-(1-x1)").arg(-4*f->getA());

				else if((-4*f->getA() == 1) && (2*f->getB() != 1 && 2*f->getB() != 0 && 2*f->getB() != -1))
					tmpX11 = QString("(x2*x1-x1^3)%1%2*(1-x1)").arg(FasterDescentImpl::otrNumberSign(f->getB())).arg(fabs(2*f->getB()));
				else if((-4*f->getA() == 1) && (2*f->getB() == 1))
					tmpX11 = QString("(x2*x1-x1^3)+(1-x1)");
				else if((-4*f->getA() == 1) && (2*f->getB() == 0))
					tmpX11 = QString("(x2*x1-x1^3)");
				else if((-4*f->getA() == 1) && (2*f->getB() == -1))
					tmpX11 = QString("(x2*x1-x1^3)-(1-x1)");

				else if((-4*f->getA() == 0) && (2*f->getB() != 1 && f->getE() != 0))
					tmpX10 = QString("%1*(1-x1)").arg(2*f->getB());
				else if((-4*f->getA() == 0) && (2*f->getB() == 1))
					tmpX11 = QString("(1-x1)");
				else if((-4*f->getA() == 0) && (2*f->getB() == 0))
					tmpX11 = QString("0");
				else if((-4*f->getA() == 0) && (2*f->getB() == -1))
					tmpX11 = QString("-(1-x1)");
				
				else if((-4*f->getA() == -1) && (2*f->getB() != 1 && 2*f->getB() != 0 && 2*f->getB() != -1))
					tmpX11 = QString("-(x2*x1-x1^3)%1%2*(1-x1)").arg(FasterDescentImpl::otrNumberSign(f->getB())).arg(fabs(2*f->getB()));
				else if((-4*f->getA() == -1) && (2*f->getB() == 1))
					tmpX11 = QString("-(x2*x1-x1^3)+(1-x1)");
				else if((-4*f->getA() == -1) && (2*f->getB() == 0))
					tmpX11 = QString("-(x2*x1-x1^3)");
				else if((-4*f->getA() == -1) && (2*f->getB() == -1))
					tmpX11 = QString("-(x2*x1-x1^3)-(1-x1)");


				if(f->getA() == 1)
					tmpX21 = QString("(x2-x1^2)");
				else if(f->getA() == 0)
					tmpX21 = QString("0");
				else if(f->getA() == -1)
					tmpX21 = QString("-(x2-x1^2)");
				
				tmpX10 = QString("%1*(x2*x1-x1^3)%2%3*(1-x1)").arg(-4*f->getA()).arg(FasterDescentImpl::otrNumberSign(f->getB())).arg(fabs(2*f->getB()));
				tmpX20 = QString("%1*(x2-x1^2)").arg(f->getA());
			}

			if(df_dx1->text() == tmpX10 || df_dx1->text() == tmpX11)
				return true;
			else if(df_dx2->text() == tmpX20 || df_dx2->text() == tmpX21)
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
			qDebug()<<trUtf8("  Проверяю, что выбрана проверка градиента");
			// Проверяю своё условие.
			return true;
		}
		else
			return false;
	}

	bool s5s6Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбрана длина градиент для проверки точности");
			// Проверяю своё условие.
			return Gradfx->isChecked();
		}
		else
			return false;
	}

	bool s6s7Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю |grad f(X)| >= e");
			// Проверяю своё условие.
			return Length(*Grad) >= s;
		}
		else
			return false;
	}

	bool s6sfTransiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю |grad f(X)| < e");
			// Проверяю своё условие.
			return Length(*Grad) < s;
		}
		else
			return false;
	}

	bool s7s8Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбрана a = min f(X + a*S)");
			// Проверяю своё условие.
			return minF->isChecked();
		}
		else
			return false;
	}

	bool s8s9Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбран сделать шаг");
			// Проверяю своё условие.
			return true;
		}
		else
			return false;
	}

};
//
