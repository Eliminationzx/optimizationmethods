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
	connect(sB1, SIGNAL(proviziXValoro(const QString &)), x2_b1_lb, SLOT(setText(const QString &)));
	connect(sB1, SIGNAL(proviziXValoro(const QString &)), fsign_b1_lb, SLOT(setText(const QString &)));

	SignalantoPorPointF * sB2 = new SignalantoPorPointF(&B2, F, this);
	connect(sB2, SIGNAL(proviziXValoro(const QString &)), x1_b2_lb, SLOT(setText(const QString &)));
	connect(sB2, SIGNAL(proviziXValoro(const QString &)), x2_b2_lb, SLOT(setText(const QString &)));
	connect(sB2, SIGNAL(proviziXValoro(const QString &)), fsign_b2_lb, SLOT(setText(const QString &)));

	SignalantoPorPointF * sP = new SignalantoPorPointF(&P, F, this);
	connect(sP, SIGNAL(proviziXValoro(const QString &)), x1_p_lb, SLOT(setText(const QString &)));
	connect(sP, SIGNAL(proviziXValoro(const QString &)), x2_p_lb, SLOT(setText(const QString &)));
	connect(sP, SIGNAL(proviziXValoro(const QString &)), fsign_p_lb, SLOT(setText(const QString &)));

	SignalantoPorPointF * sNP = new SignalantoPorPointF(&NP, F, this);
	connect(sNP, SIGNAL(proviziXValoro(const QString &)), x1_new_lb, SLOT(setText(const QString &)));
	connect(sNP, SIGNAL(proviziXValoro(const QString &)), x2_new_lb, SLOT(setText(const QString &)));
	connect(sNP, SIGNAL(proviziXValoro(const QString &)), fsign_new_lb, SLOT(setText(const QString &)));

	SignalantoPorPointF * sPX1 = new SignalantoPorPointF(&PX1, F, this);
	connect(sPX1, SIGNAL(proviziXValoro(const QString &)), x1_step_lb, SLOT(setText(const QString &)));

	SignalantoPorPointF * sPX2 = new SignalantoPorPointF(&PX2, F, this);
	connect(sPX2, SIGNAL(proviziXValoro(const QString &)), x2_step_lb, SLOT(setText(const QString &)));
//=============================================================================

//===Прикручиваю карту=========================================================
	connect(sB1, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(difiniB1));
	connect(sB2, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(difiniB1));
	connect(sP, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(difiniB1));
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
//===Создаю конечный автомат.==================================================
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
				str += trUtf8("Количество ошибок в квадратичной функции: не пройдена.");
			else
				str += trUtf8("Количество ошибок в квадратичной функции: <b>%1</b>.").arg(D[7]);

			QMessageBox::information(this, trUtf8("Поздравляем"), str);
		}
	}
}

void HuGiImpl::s1_entered()
{
	FLG=false;
	B1=B2;
	LogTxtBrsr->append(trUtf8("Итерация № %1.").arg(++NumeroIteracio));
	qDebug()<<trUtf8("come in s1"); // Вывожу дебажную инфу на консоль.
}


void HuGiImpl::s3_entered()
{
	IP=&B2;
	qDebug()<<trUtf8("come in s1"); // Вывожу дебажную инфу на консоль.
	//emit stateHasEntered();
}


namespace HuGi
{
	
	
	bool KonsideriPointoTransiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){

			qDebug()<<trUtf8("Check  f(np) < f(*ip) ");
			// Проверяю своё условие.
			return f->rezulto(*np) < f->rezulto(**ip);
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
			return f->rezulto(*np) >= f->rezulto(**ip);
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
			return f->rezulto(*np) >= f->rezulto(**ip) && !(*flag);
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
			return f->rezulto(*np) >= f->rezulto(**ip) && *flag;
		}else{
			return false;
		}
	}

}




//

