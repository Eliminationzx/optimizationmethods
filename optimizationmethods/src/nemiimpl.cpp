#include "nemiimpl.h"
#include "demonstrataqpointf.h"
#include "signalantoporpointf.h"
#include "HelpBrowser.h"
#include "mapoporfunkcioimpl.h"
#include "Konstantoj.h"
#include "funkcio.h"
#include "spuroNeMi.h"
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
	qDebug()<<trUtf8("Покоординатный спуск с фиксированным шагом"); // Вывожу дебажную инфу на консоль.

	//Вывожу формулу функции.
	QString formul = "f(X) = ";
	if(F->metaObject()->className() == QString("KvadratigantoFunkcio"))
		formul += QString::number(F->getA()) + "*(x1-" + QString::number(F->getB()) + ")^2 + " + 
			QString::number(F->getC()) + "*(x2-" + QString::number(F->getD()) + ")^2 + " + 
			QString::number(F->getE()) + "*(x1-" + QString::number(F->getF()) + ")*(x2-" + 
			QString::number(F->getG()) + ")";
	else if(F->metaObject()->className() == QString("RavinaFunkcio"))
		formul += QString::number(F->getA()) + "*(x2-x1^2)^2 + " + QString::number(F->getB()) + "*(1-x1)^2";
	func->setText(formul);

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
	connect(ss, SIGNAL(entered()), SLOT(ss_entered()));
	connect(s6, SIGNAL(entered()), SLOT(s6_entered()));
	connect(s7, SIGNAL(entered()), SLOT(s7_entered()));
	connect(s8, SIGNAL(entered()), SLOT(s8_entered()));
	connect(s9, SIGNAL(entered()), SLOT(s9_entered()));
	connect(s10, SIGNAL(entered()), SLOT(s10_entered()));
	connect(s11, SIGNAL(entered()), SLOT(s11_entered()));
	connect(sf, SIGNAL(entered()), SLOT(sf_entered()));

//---Создаю переходы, согласно диаграмме.--------------------------------------
	s1->addTransition(reflexion_bt, SIGNAL(clicked()), s2);
	s2s3Transiro * s2s3 = new s2s3Transiro( t1_ref_rb, t2_ref_rb, t3_ref_rb, &Ph, &P1, &P2, &P3, F, next1_bt, SIGNAL(clicked()), s2);
	s2s3->setTargetState(s3);
	s3s1Transiro * s3s1 = new s3s1Transiro( &Pl, &PR, &Pm, F, this, SIGNAL(stateHasEntered()), s3);
	s3s1->setTargetState(s1);
	connect(s3s1, SIGNAL(triggered()), SLOT(s3s1_triggered()));
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
	sss1Transiro * sss1 = new sss1Transiro( strikteco, &Ph, &Pl, &Pm, &Pc, F, next2_bt, SIGNAL(clicked()), ss);
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

//---Добавляю состояния в автомат и запускаю его.------------------------------
	SM->addState(so);
	SM->addState(sf);
	SM->setInitialState(so);
	init();
	SM->start();
//=============================================================================
}
//

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

	t1_ref_rb->setChecked(true);
	t2_ref_rb->setChecked(false);
	t3_ref_rb->setChecked(false);
	t1_str_rb->setChecked(true);
	t2_str_rb->setChecked(false);
	t3_str_rb->setChecked(false);
	totr_str_rb->setChecked(false);
	tras_str_rb->setChecked(false);
	t1_com_rb->setChecked(true);
	t2_com_rb->setChecked(false);
	t3_com_rb->setChecked(false);
	tsj_com_rb->setChecked(false);
	t1_red_rb->setChecked(true);
	t2_red_rb->setChecked(false);
	t3_red_rb->setChecked(false);
	totr_red_rb->setChecked(false);	
	
	qDebug()<<trUtf8("Вошёл в s1"); // Вывожу дебажную инфу на консоль.
}


void NeMiImpl::s2_entered(){
	stackedWidget->setCurrentIndex(0);

	qDebug()<<trUtf8("Вошёл в s2"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s3_entered(){
	Pc = (*Pm + *Pl)/2;
	PR = Pc + a*(Pc - *Ph);

	qDebug()<<trUtf8("Вошёл в s3"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s5_entered(){
	PK = Pc + (*Ph - Pc);
	stackedWidget->setCurrentIndex(2);

	qDebug()<<trUtf8("Вошёл в s5"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s6_entered(){
	PD = Pc + b*(PR - Pc);
	stackedWidget->setCurrentIndex(1);

	qDebug()<<trUtf8("Вошёл в s6"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s7_entered(){
	*Ph = *Pl + 0.5*(*Ph - *Pl);
	*Pm = *Pl + 0.5*(*Pm - *Pl);

	qDebug()<<trUtf8("Вошёл в s7"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s8_entered(){
	*Ph = PD;

	qDebug()<<trUtf8("Вошёл в s8"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s9_entered(){
	*Ph = PR;

	qDebug()<<trUtf8("Вошёл в s9"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s10_entered(){
	*Ph = PK;

	qDebug()<<trUtf8("Вошёл в s10"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s11_entered(){
	stackedWidget->setCurrentIndex(3);

	qDebug()<<trUtf8("Вошёл в s11"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::sf_entered(){
	LogTxtBrsr->append(trUtf8("Конец алгоритма. Найден: %1"));
	QString str = trUtf8("Найден минимум. ");

	qDebug()<<trUtf8("Конец алгоритма. Найден минимум"); // Вывожу дебажную инфу на консоль.

	if(KvantoEraroj > D[6]){
		// Слишком много ошибок.
		str += trUtf8("Ваше количество ошибок (%1) превысило допустимый предел (%2). Начните заново.").arg(KvantoEraroj).arg(D[6]);
		QMessageBox::information(this, trUtf8("Внимание"), str);
		if(F->metaObject()->className() == QString("RavinaFunkcio"))
			emit usiloPlenumis(A::NeMi);
//		else recomenci_acn->trigger();
	}else{
		str += trUtf8("Вы прошли тест. ");
		if(F->metaObject()->className() == QString("KvadratigantoFunkcio"))
		{
			str += trUtf8("Сообщите преподавателю и перейдите к овражной функции. Количество ошибок: %1.").arg(KvantoEraroj);
			emit usiloPlenumis(A::NeMi);
		}
		else if(F->metaObject()->className() == QString("RavinaFunkcio"))
		{
			str += trUtf8("Позовите преподавателя. Количество ошибок: %1.").arg(KvantoEraroj);
		}
		QMessageBox::information(this, trUtf8("Поздравляем"), str);
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

void NeMiImpl::s3s1_triggered(){
	*Ph = PR;
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
	bool s3s1Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю , что F(Xl) < F(Хотр) < F(Xm).");
			// Проверяю своё условие.
			return f->rezulto(**pl) < f->rezulto(*ps)
			       && f->rezulto(*ps) < f->rezulto(**pm);
		}
		return false;
	}
	bool s3s5Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю , что F(Xm) < F(Хотр) < F(Xh).");
			// Проверяю своё условие.
			return f->rezulto(**pm) < f->rezulto(*ps)
			       && f->rezulto(*ps) < f->rezulto(**ph);
		}
		return false;
	}
	bool s3s6Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю , что F(Хотр) < F(Хl)");
			// Проверяю своё условие.
			return f->rezulto(*ps) < f->rezulto(**pl);
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
			qDebug()<<trUtf8("  Проверяю , что Выбрана min{T1, T2, T3}");
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
			return (1/4)*((f->rezulto(**pl) - f->rezulto(*pc))*(f->rezulto(**pl) - f->rezulto(*pc))
			              + (f->rezulto(**ph) - f->rezulto(*pc))*(f->rezulto(**ph) - f->rezulto(*pc))
			              + (f->rezulto(**pm) - f->rezulto(*pc))*(f->rezulto(**pm) - f->rezulto(*pc))
			             ) >= s;
		}
		return false;
	}
	bool sssfTransiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю , что (1/4)*((F(Xl)-(F(Xc))^2 + ((F(Xh)-(F(Xc)))^2 + ((F(Xm)-(F(Xc)))^2) < e");
			// Проверяю своё условие.
			return (1/4)*((f->rezulto(**pl) - f->rezulto(*pc))*(f->rezulto(**pl) - f->rezulto(*pc))
			              + (f->rezulto(**ph) - f->rezulto(*pc))*(f->rezulto(**ph) - f->rezulto(*pc))
			              + (f->rezulto(**pm) - f->rezulto(*pc))*(f->rezulto(**pm) - f->rezulto(*pc))
			             ) < s;
		}
		return false;
	}
}