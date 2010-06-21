#include "hugiimpl.h"
#include "mapoporfunkcioimpl.h"
#include "Konstantoj.h"
#include "funkcio.h"
#include "demonstrataqpointf.h"
#include "signalantoporpointf.h"
#include "spurohugi.h"
#include "helpbrowserimpl.h"
#include "aboutprogramimpl.h"
#include <QTextBrowser>
#include <QString>
#include <QMessageBox>
#include <QStateMachine>
#include <QFinalState>
#include <QLabel>
#include <QFontDialog>
#include <QDebug>
#include <QRadioButton>
//
using namespace HuGi;

HuGiImpl::HuGiImpl( funkcio *f, QVector<double> d, QWidget * parent, Qt::WFlags flags ) 
	: AlgoritmoWin(f, d, parent, flags){
	setupUi(this);
	connect(exit, SIGNAL(activated()), qApp, SLOT(closeAllWindows()));
	
// Для овражной функции убираю действие "Начать заново"
	if(F->metaObject()->className() == QString("RavinaFunkcio")){
		recomenci_acn->setEnabled(false);
	}

	qDebug()<<trUtf8("Покоординатный спуск с минимизацией по направлению"); // Вывожу дебажныю инфу на консоль.
	
	//Вывожу формулу функции.
	func->setText(textoFunkcio());
	
	// Создаю карту.
	// centralwidget->layout() - указатель на компановщик центрального виджета
	// static_cast<QGridLayout*>(centralwidget->layout()) - обьясняю компилятору, что это именно QGridLayout
	// добавляю вижет карты в позицию 1,1. Компановщик сам позаботится о назначении новому виджету родителя.
	static_cast<QGridLayout*>(centralwidget->layout())->addWidget(MapoWdg, 2, 1, 2, 1);

//	MapoWdg->setScale(20);// Ставлю масштаб побольше. Надо будет определться с оптимальным значением.
	
	Sp = new spuroHuGi(Qt::blue);
	MapoWdg->difiniSpuro(Sp);
//	MapoWdg->difiniFonaKoloro(Qt::green);
	
//===Соединяю точки и надписи на форме=========================================
	SignalantoPorPointF * sB1 = new SignalantoPorPointF(&B1, F, this);
	connect(sB1, SIGNAL(proviziXValoro(const QString &)), x1_b1_lb, SLOT(setText(const QString &)));
	connect(sB1, SIGNAL(proviziYValoro(const QString &)), x2_b1_lb, SLOT(setText(const QString &)));
	connect(sB1, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), fsign_b1_lb, SLOT(setText(const QString &)));

	SignalantoPorPointF * sB2 = new SignalantoPorPointF(&B2, F, this);
	connect(sB2, SIGNAL(proviziXValoro(const QString &)), x1_b2_lb, SLOT(setText(const QString &)));
	connect(sB2, SIGNAL(proviziYValoro(const QString &)), x2_b2_lb, SLOT(setText(const QString &)));
	connect(sB2, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), fsign_b2_lb, SLOT(setText(const QString &)));

	SignalantoPorPointF * sP = new SignalantoPorPointF(&P, F, this);
	connect(sP, SIGNAL(proviziXValoro(const QString &)), x1_p_lb, SLOT(setText(const QString &)));
	connect(sP, SIGNAL(proviziYValoro(const QString &)), x2_p_lb, SLOT(setText(const QString &)));
	connect(sP, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), fsign_p_lb, SLOT(setText(const QString &)));

	SignalantoPorPointF * sNP = new SignalantoPorPointF(&NP, F, this);
	connect(sNP, SIGNAL(proviziXValoro(const QString &)), x1_new_lb, SLOT(setText(const QString &)));
	connect(sNP, SIGNAL(proviziYValoro(const QString &)), x2_new_lb, SLOT(setText(const QString &)));
	connect(sNP, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), fsign_new_lb, SLOT(setText(const QString &)));

	SignalantoPorPointF * sPX1 = new SignalantoPorPointF(&PX1, F, this);
	connect(sPX1, SIGNAL(proviziXValoro(const QString &)), x1_step_lb, SLOT(setText(const QString &)));

	SignalantoPorPointF * sPX2 = new SignalantoPorPointF(&PX2, F, this);
	connect(sPX2, SIGNAL(proviziYValoro(const QString &)), x2_step_lb, SLOT(setText(const QString &)));
//=============================================================================

//===Прикручиваю карту=========================================================
	connect(sB1, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(difiniB1(const QPointF &)));
	connect(sB2, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(difiniB2(const QPointF &)));
	connect(sP, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(difiniP(const QPointF &)));
//=============================================================================

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
	QState * s10 = new QState(so);
	QState * s11 = new QState(so);
	QState * s12 = new QState(so);
	QState * s13 = new QState(so);
	QState * s14 = new QState(so);
	QState * s15 = new QState(so);
	QState * s16 = new QState(so);
	QState * s17 = new QState(so);
	QState * s18 = new QState(so);
	QState * sf = new QState(/*so*/);
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
	connect(s10, SIGNAL(entered()), SLOT(s10_entered()));
	connect(s11, SIGNAL(entered()), SLOT(s11_entered()));
	connect(s12, SIGNAL(entered()), SLOT(s12_entered()));
	connect(s13, SIGNAL(entered()), SLOT(s13_entered()));
	connect(s14, SIGNAL(entered()), SLOT(s14_entered()));
	connect(s15, SIGNAL(entered()), SLOT(s15_entered()));
	connect(s16, SIGNAL(entered()), SLOT(s16_entered()));
	connect(s17, SIGNAL(entered()), SLOT(s17_entered()));
	connect(s18, SIGNAL(entered()), SLOT(s18_entered()));
	connect(sf, SIGNAL(entered()), SLOT(sf_entered()));

//---Создаю переходы, согласно диаграмме.--------------------------------------
	s1->addTransition(found_bt, SIGNAL(clicked()), s2);
	s2s3Transiro * s2s3 = new s2s3Transiro(&FLG, investigate_rb, next1_bt, SIGNAL(clicked()), s2);
	s2s3->setTargetState(s3);
	s2s4Transiro * s2s4 = new s2s4Transiro(&FLG, model_rb, next1_bt, SIGNAL(clicked()), s2);
	s2s4->setTargetState(s4);
	s3s5s4s5Transiro * s3s5 = new s3s5s4s5Transiro(up_x1_rb, next2_bt, SIGNAL(clicked()), s3);
	s3s5->setTargetState(s5);
	s3s5s4s5Transiro * s4s5 = new s3s5s4s5Transiro(up_x1_rb, next2_bt, SIGNAL(clicked()), s4);
	s4s5->setTargetState(s5);
	NoKonsideriPointoTransiro * s5s6 = new NoKonsideriPointoTransiro(&IP, &NP, F, not_accept_bt, SIGNAL(clicked()), s5);
	s5s6->setTargetState(s6);
	KonsideriPointoTransiro * s5s8 = new KonsideriPointoTransiro(&IP, &NP, F, accept_bt, SIGNAL(clicked()), s5);
	s5s8->setTargetState(s8);
	s6s7Transiro * s6s7 = new s6s7Transiro(down_x1_rb, next2_bt, SIGNAL(clicked()), s6);
	s6s7->setTargetState(s7);
	KonsideriPointoTransiro * s7s8 = new KonsideriPointoTransiro(&IP, &NP, F, accept_bt, SIGNAL(clicked()), s7);
	s7s8->setTargetState(s8);
	NoKonsideriPointoTransiro * s7s9 = new NoKonsideriPointoTransiro(&IP, &NP, F, not_accept_bt, SIGNAL(clicked()), s7);
	s7s9->setTargetState(s9);
	s8s10s9s10Transiro * s8s10 = new s8s10s9s10Transiro(up_x2_rb, next2_bt, SIGNAL(clicked()), s8);
	s8s10->setTargetState(s10);
	s8s10s9s10Transiro * s9s10 = new s8s10s9s10Transiro(up_x2_rb, next2_bt, SIGNAL(clicked()), s9);
	s9s10->setTargetState(s10);
	NoKonsideriPointoTransiro * s10s11 = new NoKonsideriPointoTransiro(&IP, &NP, F, not_accept_bt, SIGNAL(clicked()), s10);
	s10s11->setTargetState(s11);
	KonsideriPointoTransiro * s10s13 = new KonsideriPointoTransiro(&IP, &NP, F, accept_bt, SIGNAL(clicked()), s10);
	s10s13->setTargetState(s13);
	s11s12Transiro * s11s12 = new s11s12Transiro(down_x2_rb, next2_bt, SIGNAL(clicked()), s11);
	s11s12->setTargetState(s12);
	KonsideriPointoTransiro * s12s13 = new KonsideriPointoTransiro(&IP, &NP, F, accept_bt, SIGNAL(clicked()), s12);
	s12s13->setTargetState(s13);
	s12s14Transiro * s12s14 = new s12s14Transiro(&FLG, &IP, &NP, F, not_accept_bt, SIGNAL(clicked()), s12);
	s12s14->setTargetState(s14);
	s12s17Transiro * s12s17 = new s12s17Transiro(&FLG, &IP, &NP, F, not_accept_bt, SIGNAL(clicked()), s12);
	s12s17->setTargetState(s17);
	s13s14Transiro * s13s14 = new s13s14Transiro(&FLG, s13, SIGNAL(entered()), s13);
	s13s14->setTargetState(s14);
	s13s17Transiro * s13s17 = new s13s17Transiro(&FLG, s13, SIGNAL(entered()), s13);
	s13s17->setTargetState(s17);
	s14s15Transiro * s14s15 = new s14s15Transiro(&IP, &B1, &PX1, &PX2, strikteco, change_step_bt, SIGNAL(clicked()), s14);
	s14s15->setTargetState(s15);
	s14s16Transiro * s14s16 = new s14s16Transiro(&IP, &B1, &PX1, &PX2, strikteco, s14, SIGNAL(entered()), s14);
	s14s16->setTargetState(s16);
	s14sfTransiro * s14sf = new s14sfTransiro(&PX1, &PX2, strikteco, end_bt, SIGNAL(clicked()), s14);
	s14sf->setTargetState(sf);
	s15->addTransition(found_bt, SIGNAL(clicked()), s2);
	s16->addTransition(found_bt, SIGNAL(clicked()), s2);
	s17s18Transiro * s17s18 = new s17s18Transiro( &IP, &B2, F, ok_rb, next3_bt, SIGNAL(clicked()), s17);
	s17s18->setTargetState(s18);
	s17s1Transiro * s17s1 = new s17s1Transiro( &IP, &B2, F, no_rb, next3_bt, SIGNAL(clicked()), s17);
	s17s1->setTargetState(s1);
	s18->addTransition(found_bt, SIGNAL(clicked()), s2);

	//---Создаю переходы не имеющие цели. С помощью них фиксирую ошибки ползователя
	QSignalTransition * te1 = new QSignalTransition(found_bt, SIGNAL(clicked()));
	so->addTransition(te1);
	connect(te1, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te2 = new QSignalTransition(accept_bt, SIGNAL(clicked()));
	so->addTransition(te2);
	connect(te2, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te3 = new QSignalTransition(not_accept_bt, SIGNAL(clicked()));
	so->addTransition(te3);
	connect(te3, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te4 = new QSignalTransition(change_step_bt, SIGNAL(clicked()));
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

	//---Настраиваю некоторые состояния, чтоб затирали надпись со значениями новой точки, дабы не смущать пользователя.
	s1->assignProperty(x1_b2_lb, "text", trUtf8(""));
	s1->assignProperty(x2_b2_lb, "text", trUtf8(""));
	s1->assignProperty(fsign_b2_lb, "text", trUtf8(""));

	s1->assignProperty(x1_p_lb, "text", trUtf8(""));
	s1->assignProperty(x2_p_lb, "text", trUtf8(""));
	s1->assignProperty(fsign_p_lb, "text", trUtf8(""));

	s6->assignProperty(x1_new_lb, "text", trUtf8(""));
	s6->assignProperty(x2_new_lb, "text", trUtf8(""));
	s6->assignProperty(fsign_new_lb, "text", trUtf8(""));

	s8->assignProperty(x1_new_lb, "text", trUtf8(""));
	s8->assignProperty(x2_new_lb, "text", trUtf8(""));
	s8->assignProperty(fsign_new_lb, "text", trUtf8(""));

	s9->assignProperty(x1_new_lb, "text", trUtf8(""));
	s9->assignProperty(x2_new_lb, "text", trUtf8(""));
	s9->assignProperty(fsign_new_lb, "text", trUtf8(""));

	s11->assignProperty(x1_new_lb, "text", trUtf8(""));
	s11->assignProperty(x2_new_lb, "text", trUtf8(""));
	s11->assignProperty(fsign_new_lb, "text", trUtf8(""));

	s14->assignProperty(x1_new_lb, "text", trUtf8(""));
	s14->assignProperty(x2_new_lb, "text", trUtf8(""));
	s14->assignProperty(fsign_new_lb, "text", trUtf8(""));

	s16->assignProperty(x1_new_lb, "text", trUtf8(""));
	s16->assignProperty(x2_new_lb, "text", trUtf8(""));
	s16->assignProperty(fsign_new_lb, "text", trUtf8(""));

	s17->assignProperty(x1_new_lb, "text", trUtf8(""));
	s17->assignProperty(x2_new_lb, "text", trUtf8(""));
	s17->assignProperty(fsign_new_lb, "text", trUtf8(""));

	s18->assignProperty(x1_p_lb, "text", trUtf8(""));
	s18->assignProperty(x2_p_lb, "text", trUtf8(""));
	s18->assignProperty(fsign_p_lb, "text", trUtf8(""));

	//---Добавляю состояния в автомат и запускаю его.------------------------------
	SM->addState(so);
	SM->addState(sf);
	SM->setInitialState(so);
	init();
	SM->start();
//=============================================================================
}

void HuGiImpl::on_about_action_activated()
{
	aboutProgramImpl * about = new aboutProgramImpl(this);
	about->show();
}

void HuGiImpl::on_difiniFonto_act_activated(){
	bool b;
	QFont fnt = QFontDialog::getFont(&b, font());
	if(b){
		// Была нажата кнопка ОК.
		setFont(fnt);
	}
}

void HuGiImpl::on_helpo_action_activated()
{
	helpBrowserImpl * hb = new helpBrowserImpl( "doc/", "method4.htm", this);
	hb->resize(900, 600);
	hb->show();
}

void HuGiImpl::init(){
	qDebug()<<trUtf8("Вхожу в init()"); // Вывожу дебажную инфу на консоль.

	static_cast<spuroHuGi*>(Sp)->senspurigi();

	precision_lb->setText(QString::number(strikteco));
	KvantoEraroj = 0;
	NumeroIteracio = 0;
	B2 = QPointF(D[4],D[5]);
	PX1 = QPointF(D[1], 0);
	PX2 = QPointF(0, D[2]);
//	ModPX = D[3];
	LogTxtBrsr->setText("");

	qDebug()<<trUtf8("Задаю переменным начальные значения"); // Вывожу дебажную инфу на консоль.
}

void HuGiImpl::registriEraro()
{
  ++KvantoEraroj;
  LogTxtBrsr->append(trUtf8("    Совершена ошибка. Общее количество ошибок: %1").arg(KvantoEraroj));
  QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Неправильное действие"));
  msg.exec();

	qDebug()<<trUtf8("User has wrong"); // Вывожу дебажную инфу на консоль.
}

void HuGiImpl::sf_entered()
{
	LogTxtBrsr->append(trUtf8("Конец алгоритма. Найден минимум функции: %1 Количество ошибок: <b>%2</b>.").arg(F->rezulto(B2)).arg(KvantoEraroj));
	if(F->metaObject()->className() == QString("RavinaFunkcio"))
	{
		if(D[7] == -1)
			LogTxtBrsr->append(trUtf8("Квадратичная функция не пройдена."));
		else
			LogTxtBrsr->append(trUtf8("Количество ошибок в квадратичной функции: <b>%1</b>.").arg(D[7]));
	}
	
	QString str = trUtf8("Найден минимум. ");

	qDebug()<<trUtf8("Конец алгоритма. Найден минимум"); // Вывожу дебажную инфу на консоль.

	if(KvantoEraroj > D[6]){
		// Слишком много ошибок.
		str += trUtf8("Ваше количество ошибок (<b>%1</b>) превысило допустимый предел (%2). Начните заново.").arg(KvantoEraroj).arg(D[6]);
		QMessageBox::information(this, trUtf8("Внимание"), str);
		if(F->metaObject()->className() == QString("RavinaFunkcio"))
			close();
		else recomenci_acn->trigger();
	}else{
		str += trUtf8("Вы прошли тест. ");
		if(F->metaObject()->className() == QString("KvadratigantoFunkcio"))
		{
			str += trUtf8("Сообщите преподавателю и перейдите к овражной функции. Количество ошибок: <b>%1</b>.").arg(KvantoEraroj);
			emit usiloPlenumis(A::HuGi, KvantoEraroj);
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
}

void HuGiImpl::s1_entered()
{
	stackedWidget->setCurrentIndex(3);
	
	FLG=false;
	B1=B2;
	LogTxtBrsr->append(trUtf8("Итерация № %1.").arg(++NumeroIteracio));
	qDebug()<<trUtf8("come in s1"); // Вывожу дебажную инфу на консоль.
}

void HuGiImpl::s2_entered()
{
	stackedWidget->setCurrentIndex(0);
	
	investigate_rb->setChecked(true);
	up_x1_rb->setChecked(true);
	ok_rb->setChecked(true);
	
	qDebug()<<trUtf8("come in s2"); // Вывожу дебажную инфу на консоль.
	//emit stateHasEntered();
}

void HuGiImpl::s3_entered()
{
	stackedWidget->setCurrentIndex(1);
	
	IP=&B2;
	qDebug()<<trUtf8("come in s3"); // Вывожу дебажную инфу на консоль.
	//emit stateHasEntered();
}

void HuGiImpl::s4_entered()
{
	stackedWidget->setCurrentIndex(1);
	
	qDebug()<<trUtf8("come in s4"); // Вывожу дебажную инфу на консоль.
	P= QPointF((B1.x() + 2*(B2.x() - B1.x())), (B1.y() + 2*(B2.y() - B1.y())));
	IP=&P;
	label_14->setText("P1");
	//emit stateHasEntered();
}


void HuGiImpl::s5_entered()
{
	NP = *IP + PX1;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в положительном направлении оси Х1."));
	qDebug()<<trUtf8("come in s5"); // Вывожу дебажную инфу на консоль.
	//emit stateHasEntered();
}

void HuGiImpl::s6_entered()
{
	qDebug()<<trUtf8("come in s6"); // Вывожу дебажную инфу на консоль.
	//emit stateHasEntered();
}

void HuGiImpl::s7_entered()
{
	NP = *IP - PX1;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в отрицательном направлении оси Х1."));
	qDebug()<<trUtf8("come in s7"); // Вывожу дебажную инфу на консоль.
	//emit stateHasEntered();
}

void HuGiImpl::s8_entered()
{
	*IP = NP;
	LogTxtBrsr->append(trUtf8("  Точка (%1; %2) принята").arg(NP.x()).arg(NP.y()));
	qDebug()<<trUtf8("come in s8"); // Вывожу дебажную инфу на консоль.
	//emit stateHasEntered();
}

void HuGiImpl::s9_entered()
{
	qDebug()<<trUtf8("come in s9"); // Вывожу дебажную инфу на консоль.
	//emit stateHasEntered();
}

void HuGiImpl::s10_entered()
{
	NP = *IP + PX2;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в положительном направлении оси Х2."));
	qDebug()<<trUtf8("come in s10"); // Вывожу дебажную инфу на консоль.
	//emit stateHasEntered();
}

void HuGiImpl::s11_entered()
{
	qDebug()<<trUtf8("come in s11"); // Вывожу дебажную инфу на консоль.
	//emit stateHasEntered();
}

void HuGiImpl::s12_entered()
{
	NP = *IP - PX2;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в отрицательном направлении оси Х2."));
	qDebug()<<trUtf8("come in s12"); // Вывожу дебажную инфу на консоль.
	//emit stateHasEntered();
}

void HuGiImpl::s13_entered()
{
	*IP = NP;
	LogTxtBrsr->append(trUtf8("  Точка (%1; %2) принята").arg(NP.x()).arg(NP.y()));
	qDebug()<<trUtf8("come in s13"); // Вывожу дебажную инфу на консоль.
	//emit stateHasEntered();
}

void HuGiImpl::s14_entered()
{
	stackedWidget->setCurrentIndex(3);
	
	qDebug()<<trUtf8("come in s2"); // Вывожу дебажную инфу на консоль.
	//emit stateHasEntered();
}

void HuGiImpl::s15_entered()
{
	PX1 *= ModPX;
	PX2 *= ModPX;
	LogTxtBrsr->append(trUtf8("  Изменена длина шагов: %1; %2.").arg(PX1.x()).arg(PX2.y()));
	qDebug()<<trUtf8("Come in s15"); // Вывожу дебажную инфу на консоль.
	//emit stateHasEntered();
}

void HuGiImpl::s16_entered()
{
	FLG=true;
	qDebug()<<trUtf8("Come in s16"); // Вывожу дебажную инфу на консоль.
	//emit stateHasEntered();
}

void HuGiImpl::s17_entered()
{
	stackedWidget->setCurrentIndex(2);
	
	label_14->setText("P");
	qDebug()<<trUtf8("Come in s17"); // Вывожу дебажную инфу на консоль.
	//emit stateHasEntered();
}

void HuGiImpl::s18_entered()
{
	stackedWidget->setCurrentIndex(3);
	
	B1=B2;
	B2=P;
	FLG=true;
	qDebug()<<trUtf8("Come in s18"); // Вывожу дебажную инфу на консоль.
	//emit stateHasEntered();
}

void HuGiImpl::so_entered()
{
	MapoWdg->setScale(10);// Ставлю масштаб побольше. Надо будет определться с оптимальным значением.

	qDebug()<<trUtf8("Come in so"); // Вывожу дебажную инфу на консоль.
}


namespace HuGi
{
	
	
bool KonsideriPointoTransiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){

			qDebug()<<trUtf8("Check  f(np) < f(*ip) ");
			// Проверяю своё условие.
			QString nps = QString::number(f->rezulto(*np));
			QString ips = QString::number(f->rezulto(**ip));
			if(nps.toDouble()< ips.toDouble())
				return true;
			else
				return false;
			//return f->rezulto(*np) < f->rezulto(**ip);
		}else{
			return false;
		}
	}

bool NoKonsideriPointoTransiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("Check f(np) >= f(*ip)  ");
			// Проверяю своё условие.
			QString nps = QString::number(f->rezulto(*np));
			QString ips = QString::number(f->rezulto(**ip));
			if(nps.toDouble() >= ips.toDouble())
				return true;
			else
				return false;
			//return f->rezulto(*np) >= f->rezulto(**ip);
		}else{
			return false;
		}
	}	


bool s2s3Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s2s3  flag == false && investigate search has chosen");
			// Проверяю своё условие.
			return !(*flag) && rb->isChecked();
		}else{
			return false;
		}
	}

bool s2s4Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s2s4  flag == true && model search has chosen");
			// Проверяю своё условие.
			return *flag && rb->isChecked();
		}else{
			return false;
		}
	}

bool s3s5s4s5Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s3s5s4s5   up to x1  has chosen");
			// Проверяю своё условие.
			return rb->isChecked();
		}else{
			return false;
		}
	}


bool s6s7Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s6s7Transiro   down to x1  has chosen");
			// Проверяю своё условие.
			return rb->isChecked();
		}else{
			return false;
		}
	}

bool s8s10s9s10Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s8s10s9s10Transiro   up to x2  has chosen");
			// Проверяю своё условие.
			return rb->isChecked();
		}else{
			return false;
		}
	}

bool s11s12Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s11s12Transiro   down to x2  has chosen");
			// Проверяю своё условие.
			return rb->isChecked();
		}else{
			return false;
		}
	}

bool s12s14Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s12s14Transiro   Check f(np) >= f(*ip) and flag==false");
			// Проверяю своё условие.
			QString nps = QString::number(f->rezulto(*np));
			QString ips = QString::number(f->rezulto(**ip));
			return nps.toDouble() >= ips.toDouble() && !(*flag);	
			
			//return f->rezulto(*np) >= f->rezulto(**ip) && !(*flag);
		}else{
			return false;
		}
	}


bool s12s17Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s12s17Transiro   Check f(np) >= f(*ip) and flag==true");
			// Проверяю своё условие.
			QString nps = QString::number(f->rezulto(*np));
			QString ips = QString::number(f->rezulto(**ip));
			return nps.toDouble() >= ips.toDouble() && *flag;
			//return f->rezulto(*np) >= f->rezulto(**ip) && *flag;
		}else{
			return false;
		}
	}

bool s13s14Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s13s14Transiro   flag==false");
			// Проверяю своё условие.
			return !(*flag);
		}else{
			return false;
		}
	}
bool s13s17Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s13s17Transiro flag==true");
			// Проверяю своё условие.
			return *flag;
		}else{
			return false;
		}
	}

bool s14s15Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s14s15Transiro *ip == B1 and (px1 >= е || px2 >= е)");
			// Проверяю своё условие.
			return **ip==*b1 && (px1->x() >= s || px2->y() >= s);
		}else{
			return false;
		}
	}
	
bool s14s16Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s14s16Transiro *ip != B1 and (px1 >= е || px2 >= е)");
			// Проверяю своё условие.
			return **ip!=*b1 && (px1->x() >= s || px2->y() >= s);
		}else{
			return false;
		}
	}

bool s14sfTransiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s14sfTransiro  (px1 < е || px2 < е)");
			// Проверяю своё условие.
			return px1->x() < s && px2->y() < s;
		}else{
			return false;
		}
	}

bool s17s18Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s17s18Transiro f(*ip)<f(b2) ");
			// Проверяю своё условие.
			QString bps = QString::number(f->rezulto(*b2));
			QString ips = QString::number(f->rezulto(**ip));
			return ips.toDouble() < bps.toDouble() && rb->isChecked();
			
			//return f->rezulto(**ip)<f->rezulto(*b2) && rb->isChecked();
		}else{
			return false;
		}
}

bool s17s1Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s17s1Transiro f(*ip)<f(b2) ");
			// Проверяю своё условие.
			QString bps = QString::number(f->rezulto(*b2));
			QString ips = QString::number(f->rezulto(**ip));
			return ips.toDouble() >= bps.toDouble() && rb->isChecked();
			
			//return f->rezulto(**ip)>=f->rezulto(*b2) && rb->isChecked();
		}else{
			return false;
		}
}


}

//

