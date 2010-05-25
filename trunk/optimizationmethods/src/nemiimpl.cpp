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
NeMiImpl::NeMiImpl(  funkcio *f, QVector<double> *d, QWidget * parent, Qt::WFlags flags)
	: AlgoritmoWin(f, d, parent, flags){
	setupUi(this);
	qDebug()<<trUtf8("Покоординатный спуск с фиксированным шагом"); // Вывожу дебажную инфу на консоль.

	// Создаю карту.
	// centralwidget->layout() - указатель на компановщик центрального виджета
	// static_cast<QGridLayout*>(centralwidget->layout()) - обьясняю компилятору, что это именно QGridLayout
	// добавляю вижет карты в позицию 1,1. Компановщик сам позаботится о назначении новому виджету родителя.
	static_cast<QGridLayout*>(centralwidget->layout())->addWidget(MapoWdg, 1, 1);

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
	SignalantoPorPointF * sPR = new SignalantoPorPointF(&PR, F, this);
	connect(sPR, SIGNAL(proviziXValoro(const QString &)), x1_totr_lb, SLOT(setText(const QString &)));
	connect(sPR, SIGNAL(proviziYValoro(const QString &)), x2_totr_lb, SLOT(setText(const QString &)));
	connect(sPR, SIGNAL(proviziValoroFukcioEnPointo(const QString &)),fsign_totr_lb , SLOT(setText(const QString &)));
	SignalantoPorPointF * sPK = new SignalantoPorPointF(&PK, F, this);
	connect(sPK, SIGNAL(proviziXValoro(const QString &)), x1_tras_lb, SLOT(setText(const QString &)));
	connect(sPK, SIGNAL(proviziYValoro(const QString &)), x2_tras_lb, SLOT(setText(const QString &)));
	connect(sPK, SIGNAL(proviziValoroFukcioEnPointo(const QString &)),fsign_tras_lb , SLOT(setText(const QString &)));
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
	QState * s7 = new QState(so);
	QState * s8 = new QState(so);
	QState * s9 = new QState(so);
	QState * s10 = new QState(so);
	QState * s11 = new QState(so);
	QState * sf = new QState();
	so->setInitialState(s1);
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

	qDebug()<<trUtf8("Вошёл в sf"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::registriEraro(){
  ++KvantoEraroj;
  LogTxtBrsr->append(trUtf8("    Совершена ошибка. Общее количество ошибок: %1").arg(KvantoEraroj));
  QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Неправильное действие"));
  msg.exec();

	qDebug()<<trUtf8("Пользователь ошибся"); // Вывожу дебажную инфу на консоль.
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