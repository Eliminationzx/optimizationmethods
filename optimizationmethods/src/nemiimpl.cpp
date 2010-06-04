#include "nemiimpl.h"
#include "demonstrataqpointf.h"
#include "signalantoporpointf.h"
#include "HelpBrowser.h"
#include "mapoporfunkcioimpl.h"
#include "Konstantoj.h"
#include "funkcio.h"
#include "spuroNeMi.h"
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
//
using namespace NeMi;
	
NeMiImpl::NeMiImpl(  funkcio *f, QVector<double> *d, QWidget * parent, Qt::WFlags flags)
	: AlgoritmoWin(f, d, parent, flags){
	setupUi(this);
	label_2->hide();
	x1_tk_lb->hide();
	x2_tk_lb->hide();
	fsign_tk_lb->hide();
	connect(exit, SIGNAL(activated()), qApp, SLOT(closeAllWindows()));

// Для овражной функции убираю действие "Начать заново"
	if(F->metaObject()->className() == QString("RavinaFunkcio")){
		recomenci_acn->setEnabled(false);
	}

	qDebug()<<trUtf8("Покоординатный спуск с фиксированным шагом"); // Вывожу дебажную инфу на консоль.

	//Вывожу формулу функции.
	func->setText(textoFunkcio());

	// Создаю карту.
	verticalLayout_3->addWidget(MapoWdg, 2);

	MapoWdg->setScale(20);// Ставлю масштаб побольше. Надо будет определться с оптимальным значением.

	Sp = new spuroNeMi(Qt::white, Qt::blue);
	MapoWdg->difiniSpuro(Sp);
	MapoWdg->difiniFonaKoloro(Qt::green);
	
//===Соединяю точки и надписи на форме=========================================
	SignalantoPorPointF * sP1 = new SignalantoPorPointF(&P1, F, this);
	connect(sP1, SIGNAL(proviziXValoro(const QString &)), x1_t1_lb, SLOT(setText(const QString &)));
	connect(sP1, SIGNAL(proviziYValoro(const QString &)), x2_t1_lb, SLOT(setText(const QString &)));
	connect(sP1, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), fsign_b1_lb, SLOT(setText(const QString &)));
	SignalantoPorPointF * sP2 = new SignalantoPorPointF(&P2, F, this);
	connect(sP2, SIGNAL(proviziXValoro(const QString &)), x1_t2_lb, SLOT(setText(const QString &)));
	connect(sP2, SIGNAL(proviziYValoro(const QString &)), x2_t2_lb, SLOT(setText(const QString &)));
	connect(sP2, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), fsign_b2_lb, SLOT(setText(const QString &)));
	SignalantoPorPointF * sP3 = new SignalantoPorPointF(&P3, F, this);
	connect(sP3, SIGNAL(proviziXValoro(const QString &)), x1_t3_lb, SLOT(setText(const QString &)));
	connect(sP3, SIGNAL(proviziYValoro(const QString &)), x2_t3_lb, SLOT(setText(const QString &)));
	connect(sP3, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), fsign_p_lb, SLOT(setText(const QString &)));
	SignalantoPorPointF * sPR = new SignalantoPorPointF(&PR, F, this);
	connect(sPR, SIGNAL(proviziXValoro(const QString &)), x1_totr_lb, SLOT(setText(const QString &)));
	connect(sPR, SIGNAL(proviziYValoro(const QString &)), x2_totr_lb, SLOT(setText(const QString &)));
	connect(sPR, SIGNAL(proviziValoroFukcioEnPointo(const QString &)),fsign_totr_lb , SLOT(setText(const QString &)));
	SignalantoPorPointF * sPD = new SignalantoPorPointF(&PD, F, this);
	connect(sPD, SIGNAL(proviziXValoro(const QString &)), x1_tras_lb, SLOT(setText(const QString &)));
	connect(sPD, SIGNAL(proviziYValoro(const QString &)), x2_tras_lb, SLOT(setText(const QString &)));
	connect(sPD, SIGNAL(proviziValoroFukcioEnPointo(const QString &)),fsign_tras_lb , SLOT(setText(const QString &)));
	SignalantoPorPointF * sPK = new SignalantoPorPointF(&PK, F, this);
	connect(sPK, SIGNAL(proviziXValoro(const QString &)), x1_tk_lb, SLOT(setText(const QString &)));
	connect(sPK, SIGNAL(proviziYValoro(const QString &)), x2_tk_lb, SLOT(setText(const QString &)));
	connect(sPK, SIGNAL(proviziValoroFukcioEnPointo(const QString &)),fsign_tk_lb , SLOT(setText(const QString &)));
//=============================================================================

//===Соединяю точки и карту====================================================
	connect(sP1, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(difiniP1(const QPointF &)));
	connect(sP2, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(difiniP2(const QPointF &)));
	connect(sP3, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(difiniP3(const QPointF &)));
	connect(sPR, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(difiniPRespegulo(const QPointF &)));
	connect(sPD, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(difiniPDilato(const QPointF &)));
	connect(sPK, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(difiniPKompakto(const QPointF &)));
//=============================================================================

//===Создаю конечный автомат.==================================================
	QStateMachine * SM = new QStateMachine();
//---Создаю состояния, согласно диаграмме.-------------------------------------
	QState * so = new QState();
	QState * s1 = new QState(so);
	QState * s2 = new QState(so);
	QState * s3 = new QState(so);
	QState * s5 = new QState(so);
	QState * s6 = new QState(so);
	QState * ss = new QState(so);
	QState * s7 = new QState(ss);
	QState * s8 = new QState(ss);
	QState * s9 = new QState(ss);
	QState * s10 = new QState(ss);
	QState * s11 = new QState(so);
	QState * sf = new QState();
	so->setInitialState(s1);

//---Соединяю состояния и обрабодчики входа в них.-----------------------------
	connect(so, SIGNAL(entered()), SLOT(so_entered()));
	connect(s1, SIGNAL(entered()), SLOT(s1_entered()));
	connect(s2, SIGNAL(entered()), SLOT(s2_entered()));
	connect(s3, SIGNAL(entered()), SLOT(s3_entered()));
	connect(s5, SIGNAL(entered()), SLOT(s5_entered()));
	connect(s5, SIGNAL(exited()), SLOT(s5_exited()));
	connect(ss, SIGNAL(entered()), SLOT(ss_entered()));
	connect(s6, SIGNAL(entered()), SLOT(s6_entered()));
	connect(s7, SIGNAL(entered()), SLOT(s7_entered()));
	connect(s8, SIGNAL(entered()), SLOT(s8_entered()));
	connect(s9, SIGNAL(entered()), SLOT(s9_entered()));
	connect(s10, SIGNAL(entered()), SLOT(s10_entered()));
	connect(s11, SIGNAL(entered()), SLOT(s11_entered()));
	connect(sf, SIGNAL(entered()), SLOT(sf_entered()));
	connect(s1, SIGNAL(entered()), Sp, SLOT(finisxiIteracio()));

//---Создаю переходы, согласно диаграмме.--------------------------------------
	s1->addTransition(reflexion_bt, SIGNAL(clicked()), s2);
	s2s3Transiro * s2s3 = new s2s3Transiro( t1_ref_rb, t2_ref_rb, t3_ref_rb, &Ph, &P1, &P2, &P3, F, next1_bt, SIGNAL(clicked()), s2);
	s2s3->setTargetState(s3);
	s3s2Transiro * s3s2 = new s3s2Transiro( &Pl, &PR, &Pm, F, reflexion_bt, SIGNAL(clicked()), s3);
	s3s2->setTargetState(s2);
	connect(s3s2, SIGNAL(triggered()), SLOT(s3s2_triggered()));
	s3s5Transiro * s3s5 = new s3s5Transiro( &Ph, &PR, &Pm, F, compression_bt, SIGNAL(clicked()), s3);
	s3s5->setTargetState(s5);
	s3s6Transiro * s3s6 = new s3s6Transiro( &Pl, &PR, F, stretching_bt, SIGNAL(clicked()), s3);
	s3s6->setTargetState(s6);
	s3s11Transiro * s3s11 = new s3s11Transiro( &Ph, &PR, F, reduction_bt, SIGNAL(clicked()), s3);
	s3s11->setTargetState(s11);
	s5s10Transiro * s5s10 = new s5s10Transiro( t1_com_rb, t2_com_rb, t3_com_rb, &Ph, &P1, &P2, &P3, F, next3_bt, SIGNAL(clicked()), s5);
	s5s10->setTargetState(s10);
	s6s8Transiro * s6s8 = new s6s8Transiro( tras_str_rb, &Pl, &PD, F, next2_bt, SIGNAL(clicked()), s6);
	s6s8->setTargetState(s8);
	s6s9Transiro * s6s9 = new s6s9Transiro( totr_str_rb, &Pl, &PD, F, next2_bt, SIGNAL(clicked()), s6);
	s6s9->setTargetState(s9);
	s11s7Transiro * s11s7 = new s11s7Transiro( t1_red_rb, t2_red_rb, t3_red_rb, &Pl, &P1, &P2, &P3, F, next4_bt, SIGNAL(clicked()), s11);
	s11s7->setTargetState(s7);
	sss1Transiro * sss1 = new sss1Transiro( strikteco, &Ph, &Pl, &Pm, &Pc, F, this, SIGNAL(stateHasEntered()), ss);
	sss1->setTargetState(s1);
	sssfTransiro * sssf = new sssfTransiro( strikteco, &Ph, &Pl, &Pm, &Pc, F, next2_bt, SIGNAL(clicked()), ss);
	sssf->setTargetState(sf);
//---Создаю переход по действию "Начать заново"
	connect(so->addTransition(recomenci_acn, SIGNAL(activated()), s1), SIGNAL(triggered()), SLOT(init()));
	connect(sf->addTransition(recomenci_acn, SIGNAL(activated()), s1), SIGNAL(triggered()), SLOT(init()));
//---Создаю переходы не имеющие цели. С помощью них фиксирую ошибки пользователя
	QSignalTransition * te1 = new QSignalTransition(reflexion_bt, SIGNAL(clicked()));
	so->addTransition(te1);
	connect(te1, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te2 = new QSignalTransition(stretching_bt, SIGNAL(clicked()));
	so->addTransition(te2);
	connect(te2, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te3 = new QSignalTransition(compression_bt, SIGNAL(clicked()));
	so->addTransition(te3);
	connect(te3, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te4 = new QSignalTransition(reduction_bt, SIGNAL(clicked()));
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

//---Настраиваю некоторые состояния, чтоб затирали надписи со значениями точек, дабы не смущать пользователя.
	s1->assignProperty(x1_totr_lb, "text", trUtf8(""));
	s1->assignProperty(x2_totr_lb, "text", trUtf8(""));
	s1->assignProperty(fsign_totr_lb, "text", trUtf8(""));
	s1->assignProperty(x1_tras_lb, "text", trUtf8(""));
	s1->assignProperty(x2_tras_lb, "text", trUtf8(""));
	s1->assignProperty(fsign_tras_lb, "text", trUtf8(""));
	s1->assignProperty(x1_tk_lb, "text", trUtf8(""));
	s1->assignProperty(x2_tk_lb, "text", trUtf8(""));
	s1->assignProperty(fsign_tk_lb, "text", trUtf8(""));
	s2->assignProperty(x1_totr_lb, "text", trUtf8(""));
	s2->assignProperty(x2_totr_lb, "text", trUtf8(""));
	s2->assignProperty(fsign_totr_lb, "text", trUtf8(""));
//---Настраиваю некоторые состояния для отображения нужной страницы выбора точки.
	s1->assignProperty(stackedWidget, "currentIndex", 4);
	s2->assignProperty(stackedWidget, "currentIndex", 0);
	s3->assignProperty(stackedWidget, "currentIndex", 4);
	s5->assignProperty(stackedWidget, "currentIndex", 2);
	s6->assignProperty(stackedWidget, "currentIndex", 1);
	s7->assignProperty(stackedWidget, "currentIndex", 4);
	s8->assignProperty(stackedWidget, "currentIndex", 4);
	s9->assignProperty(stackedWidget, "currentIndex", 4);
	s10->assignProperty(stackedWidget, "currentIndex", 4);
	s11->assignProperty(stackedWidget, "currentIndex", 3);
	

	

//---Добавляю состояния в автомат и запускаю его.------------------------------
	SM->addState(so);
	SM->addState(sf);
	SM->setInitialState(so);
	init();
	SM->start();
//=============================================================================
}
//

void NeMiImpl::on_difiniFonto_act_activated()
{
	bool b;
	QFont fnt = QFontDialog::getFont(&b, font());
	if(b){
		// Была нажата кнопка ОК.
		setFont(fnt);
	}
}

void NeMiImpl::on_helpo_action_activated()
{
	helpBrowserImpl *hb = new helpBrowserImpl( "doc/", "method5.htm", this);
	hb->resize(900, 600);
	hb->show();
}

void NeMiImpl::init(){
	qDebug()<<trUtf8("Вхожу в init()"); // Вывожу дебажную инфу на консоль.

	precision_lb->setText(QString::number(strikteco));
	KvantoEraroj = 0;
	NumeroIteracio = 0;
	P1 = QPointF(D[4],D[5]);
	P2 = QPointF(D[4] + D[1],D[5]);
	P3 = QPointF(D[4],D[5] + D[2]);
	LogTxtBrsr->setText("");
//	static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->senspurigi();

	qDebug()<<trUtf8("Задаю переменным начальные значения"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::so_entered(){

	qDebug()<<trUtf8("Вошёл в so"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::ss_entered(){

// Прячу надписи с точкой сжатия.
	label_2->setVisible(false);
	x1_tk_lb->setVisible(false);
	x2_tk_lb->setVisible(false);
	fsign_tk_lb->setVisible(false);

	qDebug()<<trUtf8("Вошёл в ss"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s1_entered(){
	if(F->rezulto(P1) >= F->rezulto(P2)){
		if(F->rezulto(P1) >= F->rezulto(P3)){
			Ph = &P1;
			if(F->rezulto(P2) >= F->rezulto(P3)){
				Pm = &P2;
				Pl = &P3;
			}else{
				Pm = &P3;
				Pl = &P2;
			}
		}else{
			Ph = &P3;
			Pm = &P1;
			Pl = &P2;
		}
	}else{
		if(F->rezulto(P2) >= F->rezulto(P3)){
			Ph = &P2;
			if(F->rezulto(P1) >= F->rezulto(P3)){
				Pm = &P1;
				Pl = &P3;
			}else{
				Pm = &P3;
				Pl = &P1;
			}
		}else{
			Ph = &P3;
			Pm = &P2;
			Pl = &P1;
		}
	}

// Обнулю выбор в группах радиобатонов.
	t1_ref_rb->setChecked(true);
	t1_com_rb->setChecked(true);
	t1_red_rb->setChecked(true);
	t1_str_rb->setChecked(true);

	LogTxtBrsr->append(trUtf8("Итерация № %1.").arg(++NumeroIteracio));
	
	qDebug()<<trUtf8("Вошёл в s1"); // Вывожу дебажную инфу на консоль.
}


void NeMiImpl::s2_entered(){
	LogTxtBrsr->append(trUtf8("  Отражение."));

	qDebug()<<trUtf8("Вошёл в s2"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s3_entered(){
	Pc = (*Pm + *Pl)/2;
	PR = Pc + a*(Pc - *Ph);

	qDebug()<<trUtf8("Вошёл в s3"); // Вывожу дебажную инфу на консоль.
	
	emit stateHasEntered();
}

void NeMiImpl::s5_entered(){
	PK = Pc + c*(*Ph - Pc);

// Скрываю надписи точки растяжения и отображаю точку сжатия. При выходе из
// состояния верну назад.
	label_15->hide();
	x1_tras_lb->hide();
	x2_tras_lb->hide();
	fsign_tras_lb->hide();
	label_2->show();
	x1_tk_lb->show();
	x2_tk_lb->show();
	fsign_tk_lb->show();

	LogTxtBrsr->append(trUtf8("  Сжатие"));

	qDebug()<<trUtf8("Вошёл в s5"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s5_exited(){
// Скрываю надписи точки сжатия и отображаю точку растяжения.
	label_2->hide();
	x1_tk_lb->hide();
	x2_tk_lb->hide();
	fsign_tk_lb->hide();
	label_15->show();
	x1_tras_lb->show();
	x2_tras_lb->show();
	fsign_tras_lb->show();
}

void NeMiImpl::s6_entered(){
	PD = Pc + b*(PR - Pc);

	LogTxtBrsr->append(trUtf8("  Растяжение"));

	qDebug()<<trUtf8("Вошёл в s6"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s7_entered(){
	*Ph = *Pl + 0.5*(*Ph - *Pl);
	*Pm = *Pl + 0.5*(*Pm - *Pl);

	x1_step_lb->setText(QString::number(averagxoDistanco(), 'f', 2));

	LogTxtBrsr->append(trUtf8("  Результат редукции: (%1; %2), (%3; %4), (%5; %6)").arg(P1.x()).arg(P1.y()).arg(P2.x()).arg(P2.y()).arg(P3.x()).arg(P3.y()));

	qDebug()<<trUtf8("Вошёл в s7"); // Вывожу дебажную инфу на консоль.
	
	emit stateHasEntered();
}

void NeMiImpl::s8_entered(){
	*Ph = PD;

	x1_step_lb->setText(QString::number(averagxoDistanco(), 'f', 2));

	LogTxtBrsr->append(trUtf8("  Принята точка: (%1; %2).").arg(Ph->x()).arg(Ph->y()));

	qDebug()<<trUtf8("Вошёл в s8"); // Вывожу дебажную инфу на консоль.
	
	emit stateHasEntered();
}

void NeMiImpl::s9_entered(){
	*Ph = PR;

	x1_step_lb->setText(QString::number(averagxoDistanco(), 'f', 2));

	LogTxtBrsr->append(trUtf8("  Принята точка: (%1; %2).").arg(Ph->x()).arg(Ph->y()));

	qDebug()<<trUtf8("Вошёл в s9"); // Вывожу дебажную инфу на консоль.
	
	emit stateHasEntered();
}

void NeMiImpl::s10_entered(){
	*Ph = PK;

	x1_step_lb->setText(QString::number(averagxoDistanco(), 'f', 2));

	LogTxtBrsr->append(trUtf8("  Принята точка: (%1; %2).").arg(Ph->x()).arg(Ph->y()));

	qDebug()<<trUtf8("Вошёл в s10"); // Вывожу дебажную инфу на консоль.
	
	emit stateHasEntered();
}

void NeMiImpl::s11_entered(){
	LogTxtBrsr->append(trUtf8("  Редукция."));

	qDebug()<<trUtf8("Вошёл в s11"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::sf_entered(){
	LogTxtBrsr->append(trUtf8("Конец алгоритма. Найден минимум функции: %1. Количество ошибок: %2.").arg(F->rezulto(*Pl)).arg(KvantoEraroj));
	QString str = trUtf8("Найден минимум. ");

	qDebug()<<trUtf8("Конец алгоритма."); // Вывожу дебажную инфу на консоль.

	if(KvantoEraroj > D[6]){
		// Слишком много ошибок.
		str += trUtf8("Ваше количество ошибок (%1) превысило допустимый предел (%2). Начните заново.").arg(KvantoEraroj).arg(D[6]);
		QMessageBox::information(this, trUtf8("Внимание"), str);
		if(F->metaObject()->className() == QString("RavinaFunkcio"))
			close();
		else recomenci_acn->trigger();
	}else{
		str += trUtf8("Вы прошли тест. ");
		if(F->metaObject()->className() == QString("KvadratigantoFunkcio"))
		{
			str += trUtf8("Сообщите преподавателю и перейдите к овражной функции. Количество ошибок: <b>%1</b>.").arg(KvantoEraroj);
			emit usiloPlenumis(A::NeMi);
			QMessageBox::information(this, trUtf8("Поздравляем"), str);
			close();
		}
		else if(F->metaObject()->className() == QString("RavinaFunkcio"))
		{
			str += trUtf8("Позовите преподавателя. Количество ошибок: <b>%1</b>.").arg(KvantoEraroj);
			QMessageBox::information(this, trUtf8("Поздравляем"), str);
		}
	}

	qDebug()<<trUtf8("Вошёл в sf"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::registriEraro(){
  ++KvantoEraroj;
  LogTxtBrsr->append(trUtf8("    Совершена ошибка. Общее количество ошибок: %1").arg(KvantoEraroj));
  QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Неправильное действие"));
  msg.exec();

	qDebug()<<trUtf8("Пользователь ошибся"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s3s2_triggered(){
	*Ph = PR;
	LogTxtBrsr->append(trUtf8("  Принята точка: (%1; %2).").arg(Ph->x()).arg(Ph->y()));

	s1_entered();
}

qreal NeMiImpl::averagxoDistanco(){
	qDebug()<<trUtf8("%1 %2 %9, %3 %4 %10, %5 %6 %11, %7 %8 %12").arg(Ph->x()).arg(Ph->y()).arg(Pm->x()).arg(Pm->y()).arg(Pl->x()).arg(Pl->y()).arg(Pc.x()).arg(Pc.y()).arg(F->rezulto(*Ph)).arg(F->rezulto(*Pm)).arg(F->rezulto(*Pl)).arg(F->rezulto(Pc)); // Вывожу дебажную инфу на консоль.
	
	return sqrt((1.0/3.0)*((F->rezulto(*Pl) - F->rezulto(Pc))*(F->rezulto(*Pl) - F->rezulto(Pc))
	                       + (F->rezulto(*Ph) - F->rezulto(Pc))*(F->rezulto(*Ph) - F->rezulto(Pc))
	                       + (F->rezulto(*Pm) - F->rezulto(Pc))*(F->rezulto(*Pm) - F->rezulto(Pc))));
}

namespace NeMi{
	bool s2s3Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю , что выбрана наибольшая точка.");
			// Проверяю своё условие.
			return (t1_ref->isChecked() && *ph == p1)
			       || (t2_ref->isChecked() && *ph == p2)
			       || (t3_ref->isChecked() && *ph == p3);
		}
		return false;
	}
	bool s3s2Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю , что F(Xl) < F(Хотр) < F(Xm).");
			// Проверяю своё условие.
			return f->rezulto(**pl) < f->rezulto(*pr)
			       && f->rezulto(*pr) < f->rezulto(**pm);
		}
		return false;
	}
	bool s3s5Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю , что F(Xm) < F(Хотр) < F(Xh).%1 %2 %3").arg(f->rezulto(**pm)).arg(f->rezulto(*pr)).arg(f->rezulto(**ph));
			// Проверяю своё условие.
			return f->rezulto(**pm) < f->rezulto(*pr)
			       && f->rezulto(*pr) < f->rezulto(**ph);
		}
		return false;
	}
	bool s3s6Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю , что F(Хотр) < F(Хl)");
			// Проверяю своё условие.
			return f->rezulto(*pr) < f->rezulto(**pl);
		}
		return false;
	}
	bool s3s11Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю , что F(Хh) < F(Хотр)");
			// Проверяю своё условие.
			return f->rezulto(**ph) < f->rezulto(*ps);
		}
		return false;
	}
	bool s5s10Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю , что выбрана max{T1, T2, T3}");
			// Проверяю своё условие.
			return (t1_com->isChecked() && *ph == p1)
			       || (t2_com->isChecked() && *ph == p2)
			       || (t3_com->isChecked() && *ph == p3);
		}
		return false;
	}
	bool s6s8Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю , что F(Xрас) < F(Xl) && выбрана Храс.");
			// Проверяю своё условие.
			return f->rezulto(*pd) < f->rezulto(**pl)
			       && tras_str->isChecked();
		}
		return false;
	}
	bool s6s9Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю , что F(Xрас) >= F(Xl) && выбрана Хотр");
			// Проверяю своё условие.
			return f->rezulto(*pd) >= f->rezulto(**pl)
			       && totr_str->isChecked();
		}
		return false;
	}
	bool s11s7Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю , что выбрана min{T1, T2, T3}");
			// Проверяю своё условие.
			return (t1_red->isChecked() && *pl == p1)
			       || (t2_red->isChecked() && *pl == p2)
			       || (t3_red->isChecked() && *pl == p3);
		}
		return false;
	}
	bool sss1Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю , что (1/4)*((F(Xl)-(F(Xc))^2 + ((F(Xh)-(F(Xc)))^2 + ((F(Xm)-(F(Xc)))^2) >= e");
			// Проверяю своё условие.
			return sqrt((1.0/3.0)*((f->rezulto(**pl) - f->rezulto(*pc))*(f->rezulto(**pl) - f->rezulto(*pc))
			              + (f->rezulto(**ph) - f->rezulto(*pc))*(f->rezulto(**ph) - f->rezulto(*pc))
			              + (f->rezulto(**pm) - f->rezulto(*pc))*(f->rezulto(**pm) - f->rezulto(*pc))
			             )) >= s;
		}
		return false;
	}
	bool sssfTransiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю , что (1/4)*((F(Xl)-(F(Xc))^2 + ((F(Xh)-(F(Xc)))^2 + ((F(Xm)-(F(Xc)))^2) < e");
			// Проверяю своё условие.
			return sqrt((1.0/3.0)*((f->rezulto(**pl) - f->rezulto(*pc))*(f->rezulto(**pl) - f->rezulto(*pc))
			              + (f->rezulto(**ph) - f->rezulto(*pc))*(f->rezulto(**ph) - f->rezulto(*pc))
			              + (f->rezulto(**pm) - f->rezulto(*pc))*(f->rezulto(**pm) - f->rezulto(*pc))
			             )) < s;
		}
		return false;
	}
}


void NeMiImpl::on_about_action_activated(){
	aboutProgramImpl * about = new aboutProgramImpl(this);
	about->show();
}
