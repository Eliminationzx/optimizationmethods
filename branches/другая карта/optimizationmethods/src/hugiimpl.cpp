#include "hugiimpl.h"
#include "mapoporfunkcioimpl.h"
#include "Konstantoj.h"
#include "funkcio.h"
#include "spuro.h"
#include "spurosinkolauxkoordinatoj.h"
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
//#include <QTextCodec>
//
using namespace SinkoLauxKoordinatoj_hugi;
HuGiImpl::HuGiImpl(  funkcio *f, QVector<double> d, QWidget * parent, Qt::WFlags flags) 
	: AlgoritmoWin(f, d, parent, flags){
	setupUi(this);
connect(exit, SIGNAL(activated()), qApp, SLOT(closeAllWindows()));
// Для овражной функции убираю действие "Начать заново"
	if(F->metaObject()->className() == QString("RavinaFunkcio")){
		menubar->removeAction(recomenci_acn);
	}	
	//QTextCodec *codec = QTextCodec::codecForName("KOI8-R");
	//QCString dest = codec->fromUnicode(src);

	
	qDebug()<<trUtf8("============Method HuGi go on"); // Вывожу дебажную инфу на консоль.
	
	
 	stackedWidget->setCurrentIndex(3);
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
	SignalantoPorPointF * sMP = new SignalantoPorPointF(&MP, F, this);
	connect(sMP, SIGNAL(proviziXValoro(const QString &)), x1_b1_lb, SLOT(setText(const QString &)));
	connect(sMP, SIGNAL(proviziYValoro(const QString &)), x2_b1_lb, SLOT(setText(const QString &)));
	connect(sMP, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), fsign_b1_lb, SLOT(setText(const QString &)));
	
	SignalantoPorPointF * sMP2 = new SignalantoPorPointF(&MP2, F, this);
	connect(sMP, SIGNAL(proviziXValoro(const QString &)), x1_b2_lb, SLOT(setText(const QString &)));
	connect(sMP, SIGNAL(proviziYValoro(const QString &)), x2_b2_lb, SLOT(setText(const QString &)));
	connect(sMP, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), fsign_b2_lb, SLOT(setText(const QString &)));	
	
	SignalantoPorPointF * sPP = new SignalantoPorPointF(&PP, F, this);
	connect(sMP, SIGNAL(proviziXValoro(const QString &)), x1_p_lb, SLOT(setText(const QString &)));
	connect(sMP, SIGNAL(proviziYValoro(const QString &)), x2_p_lb, SLOT(setText(const QString &)));
	connect(sMP, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), fsign_p_lb, SLOT(setText(const QString &)));
	
	SignalantoPorPointF * sNP = new SignalantoPorPointF(&NP, F, this);
	connect(sNP, SIGNAL(proviziXValoro(const QString &)), x1_new_lb, SLOT(setText(const QString &)));
	connect(sNP, SIGNAL(proviziYValoro(const QString &)), x2_new_lb, SLOT(setText(const QString &)));
	connect(sNP, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), fsign_new_lb, SLOT(setText(const QString &)));
	
	SignalantoPorPointF * sPX1 = new SignalantoPorPointF(&PX1, F, this);
	connect(sPX1, SIGNAL(proviziXValoro(const QString &)), x1_step_lb, SLOT(setText(const QString &)));
	
	SignalantoPorPointF * sPX2 = new SignalantoPorPointF(&PX2, F, this);
	connect(sPX2, SIGNAL(proviziYValoro(const QString &)), x2_step_lb, SLOT(setText(const QString &)));

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
	QState * s19 = new QState(so);
	QState * sf = new QState(/*so*/);
	so->setInitialState(s1);
	
	//---Соединяю состояния и обработчики входа в них.-----------------------------
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
	connect(s19, SIGNAL(entered()), SLOT(s19_entered()));
	connect(sf, SIGNAL(entered()), SLOT(sf_entered()));
	
	//---Создаю переходы, согласно диаграмме.--------------------------------------
	//s1->addTransition(this, SIGNAL(stateHasEntered()), s2);
	
	s3s4Transiro * s3s4 = new s3s4Transiro(up_x1_rb, next2_bt, SIGNAL(clicked()), s3);
	s3s4->setTargetState(s4);
	
	NoKonsideriPointoTransiro * s4s5 = new NoKonsideriPointoTransiro(&MP, &NP, F, not_accept_bt, SIGNAL(clicked()), s4);
	s4s5->setTargetState(s5);
	
	KonsideriPointoTransiro * s4s7 = new KonsideriPointoTransiro(&MP, &NP, F, accept_bt, SIGNAL(clicked()), s4);
	s4s7->setTargetState(s7);
	
	s5s6Transiro * s5s6 = new s5s6Transiro(down_x1_rb, next2_bt, SIGNAL(clicked()), s5);
	s5s6->setTargetState(s6);
	
	KonsideriPointoTransiro * s6s7 = new KonsideriPointoTransiro(&MP, &NP, F, accept_bt, SIGNAL(clicked()), s6);
	s6s7->setTargetState(s7);
	
	NoKonsideriPointoTransiro * s6s8 = new NoKonsideriPointoTransiro(&MP, &NP, F, not_accept_bt, SIGNAL(clicked()), s6);
	s6s8->setTargetState(s8);
	
	s7s9_s8s9Transiro * s7s9 = new s7s9_s8s9Transiro(up_x2_rb, next2_bt, SIGNAL(clicked()), s7);
	s7s9->setTargetState(s9);
	
	s7s9_s8s9Transiro * s8s9 = new s7s9_s8s9Transiro(up_x2_rb, next2_bt, SIGNAL(clicked()), s8);
	s8s9->setTargetState(s9);
	//======
	NoKonsideriPointoTransiro * s9s10 = new NoKonsideriPointoTransiro(&MP, &NP, F, not_accept_bt, SIGNAL(clicked()), s9);
	s9s10->setTargetState(s10);
	
	KonsideriPointoTransiro * s9s12 = new KonsideriPointoTransiro(&MP, &NP, F, accept_bt, SIGNAL(clicked()), s9);
	s9s12->setTargetState(s12);
	
	s10s11Transiro * s10s11 = new s10s11Transiro(down_x2_rb, next2_bt, SIGNAL(clicked()), s10);
	s10s11->setTargetState(s11);
	
	KonsideriPointoTransiro * s11s12 = new KonsideriPointoTransiro(&MP, &NP, F, accept_bt, SIGNAL(clicked()), s11);
	s11s12->setTargetState(s12);
	
	NoKonsideriPointoTransiro * s11s13 = new NoKonsideriPointoTransiro(&MP, &NP, F, not_accept_bt, SIGNAL(clicked()), s11);
	s11s13->setTargetState(s13);
	
	s12->addTransition(this, SIGNAL(stateHasEntered()), s13); // Переход s12s13 совершается сразу при входе в s12.
	
	s13s16Transiro*s13s16 = new s13s16Transiro(ok_rb,&BP,&MP,&MP2,&TEMP_B,&FLAG_SO,F,next3_bt,SIGNAL(clicked()),s13);
	s13s16->setTargetState(s16);
	
	s15s18_s17s18Transiro*s15s18 = new s15s18_s17s18Transiro(model_rb, next1_bt, SIGNAL(clicked()), s15);
	s15s18->setTargetState(s18);
	
	s15s18_s17s18Transiro*s17s18 = new s15s18_s17s18Transiro(model_rb, next1_bt, SIGNAL(clicked()), s17);
	s17s18->setTargetState(s18);
	
	s13s19Transiro*s13s19 = new s13s19Transiro(no_rb,&BP,&MP,&MP2,&TEMP_B,&FLAG_SO,F,next3_bt,SIGNAL(clicked()),s13 );
	s13s19->setTargetState(s19);
	
	s13s14Transiro * s13s14 = new s13s14Transiro(&BP, &MP, &MP2, &PX1, &PX2, strikteco, change_step_bt, SIGNAL(clicked()), s11);
	s13s14->setTargetState(s14);
	
	
	s13sfTransiro * s13sf = new s13sfTransiro( &PX1, &PX2, strikteco, end_bt, SIGNAL(clicked()), s13);
	s13sf->setTargetState(sf);
	
	s2s3Transiro * s2s3 = new s2s3Transiro(investigate_rb, next1_bt, SIGNAL(clicked()), s2);
	s2s3->setTargetState(s3);
	
	//s2s3Transiro*s2s3 = new s2s3Transiro( found_bt, SIGNAL(clicked()), s2);
	//s2s3->setTargetState(s3);
	
	s1->addTransition(found_bt, SIGNAL(clicked()), s2);
	s13->addTransition(found_bt, SIGNAL(clicked()), s15);
	s14->addTransition(found_bt, SIGNAL(clicked()), s2);
	s19->addTransition(found_bt, SIGNAL(clicked()), s2);
	s16->addTransition(found_bt, SIGNAL(clicked()), s17);
	s14->addTransition(this, SIGNAL(stateHasEntered()), s2);
	s12->addTransition(this, SIGNAL(stateHasEntered()), s13);
	s18->addTransition(this, SIGNAL(stateHasEntered()), s3);
	
//---Создаю переход по действию "Начать заново"
	connect(so->addTransition(recomenci_acn, SIGNAL(activated()), s1), SIGNAL(triggered()), SLOT(init()));
	connect(sf->addTransition(recomenci_acn, SIGNAL(activated()), s1), SIGNAL(triggered()), SLOT(init()));
	
	
	
//---Создаю переходы не имеющие цели. С помощью них фиксирую ошибки пользователя
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


/*---Настраиваю некоторые состояния, чтоб затирали надпись со значениями новой точки, дабы не смущать пользователя.
	s1->assignProperty(distance_lb, "text", trUtf8(""));
	s1->assignProperty(new_x1_lb, "text", trUtf8(""));
	s1->assignProperty(new_x2_lb, "text", trUtf8(""));
	s1->assignProperty(new_fsign_lb, "text", trUtf8(""));
	s3->assignProperty(new_x1_lb, "text", trUtf8(""));
	s3->assignProperty(new_x2_lb, "text", trUtf8(""));
	s3->assignProperty(new_fsign_lb, "text", trUtf8(""));
	s5->assignProperty(new_x1_lb, "text", trUtf8(""));
	s5->assignProperty(new_x2_lb, "text", trUtf8(""));
	s5->assignProperty(new_fsign_lb, "text", trUtf8(""));
	s6->assignProperty(new_x1_lb, "text", trUtf8(""));
	s6->assignProperty(new_x2_lb, "text", trUtf8(""));
	s6->assignProperty(new_fsign_lb, "text", trUtf8(""));
	s8->assignProperty(new_x1_lb, "text", trUtf8(""));
	s8->assignProperty(new_x2_lb, "text", trUtf8(""));
	s8->assignProperty(new_fsign_lb, "text", trUtf8(""));
	s11->assignProperty(new_x1_lb, "text", trUtf8(""));
	s11->assignProperty(new_x2_lb, "text", trUtf8(""));
	s11->assignProperty(new_fsign_lb, "text", trUtf8(""));
	s10->assignProperty(new_x1_lb, "text", trUtf8(""));
	s10->assignProperty(new_x2_lb, "text", trUtf8(""));
	s10->assignProperty(new_fsign_lb, "text", trUtf8(""));
	s12->assignProperty(distance_lb, "text", trUtf8(""));
//---Настраиваю выделение цветом растояния между точками.
	s1->assignProperty(distance_lb, "palette", this->palette());
*/
/*---Прикручиваю карту---------------------------------------------------------
	connect(sNP, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(aldoniSercxantaPointo(QPointF)));
	connect(sMP, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(difiniMomentaPointo(QPointF)));

	connect(s3, SIGNAL(entered()), Sp, SLOT(reveniAlMomentoPointo()));
	connect(s6, SIGNAL(entered()), Sp, SLOT(reveniAlMomentoPointo()));
	connect(s8, SIGNAL(entered()), Sp, SLOT(reveniAlMomentoPointo()));
	connect(s9s11, SIGNAL(triggered()), Sp, SLOT(reveniAlMomentoPointo()));

	connect(s1, SIGNAL(entered()), Sp, SLOT(finisxiIteracio()));
//-------------------------------------------------------------------------------*/

//---Добавляю состояния в автомат и запускаю его.------------------------------
	SM->addState(so);
	SM->addState(sf);
	SM->setInitialState(so);
	init();
	SM->start();
//=============================================================================
}
//


void HuGiImpl::registriEraro()
{
  ++KvantoEraroj;
  LogTxtBrsr->append(trUtf8("    Совершена ошибка. Общее количество ошибок: %1").arg(KvantoEraroj));
  QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Неправильное действие"));
  msg.exec();

	qDebug()<<trUtf8("Пользователь ошибся"); // Вывожу дебажную инфу на консоль.
}

void HuGiImpl::sf_entered()
{
	LogTxtBrsr->append(trUtf8("Конец алгоритма. Найден: %1").arg(F->rezulto(MP)));
	if(F->metaObject()->className() == QString("RavinaFunkcio"))
		LogTxtBrsr->append(trUtf8("Количество ошибок в квадратичной функции: %1.").arg(D[7]));
	QString str = trUtf8("Найден минимум. ");

	qDebug()<<trUtf8("The end. Minimum found"); // Вывожу дебажную инфу на консоль.

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
			str += trUtf8("Сообщите преподавателю и перейдите к овражной функции. Количество ошибок: %1.").arg(KvantoEraroj);
			emit usiloPlenumis(A::HuGi, KvantoEraroj);
			close();
		}
		else if(F->metaObject()->className() == QString("RavinaFunkcio"))
		{
			str += trUtf8("Позовите преподавателя. Количество ошибок: %1.").arg(KvantoEraroj);
			QMessageBox::information(this, trUtf8("Поздравляем"), str);
		}
	}
}

void HuGiImpl::s19_entered()
{
	FLAG_SO=false;
	MP=PP;
	MP2=PP;
	stackedWidget->setCurrentIndex(3);
	qDebug()<<trUtf8("Come in s19"); // Вывожу дебажную инфу на консоль.

	emit stateHasEntered();
}

void HuGiImpl::s18_entered()
{
	PP=MP+2*(MP2-MP);
	FLAG_SO=true;
	MP=PP;
	TEMP_B=MP2;
	MP2=PP;
	stackedWidget->setCurrentIndex(3);
	qDebug()<<trUtf8("Come in s18"); // Вывожу дебажную инфу на консоль.

	emit stateHasEntered();
}

void HuGiImpl::s17_entered()
{
	stackedWidget->setCurrentIndex(0);
	qDebug()<<trUtf8("Come in s17"); // Вывожу дебажную инфу на консоль.

	emit stateHasEntered();
}

void HuGiImpl::s16_entered()
{
	MP = TEMP_B;
	stackedWidget->setCurrentIndex(3);
	qDebug()<<trUtf8("Come in s16"); // Вывожу дебажную инфу на консоль.

	emit stateHasEntered();
}

void HuGiImpl::s15_entered()
{
	//LogTxtBrsr->append(trUtf8("  новая точка: (%1; %2) не принята").arg(MP.x()).arg(MP.y()));
	stackedWidget->setCurrentIndex(0);
	qDebug()<<trUtf8("Come in s15"); // Вывожу дебажную инфу на консоль.

	emit stateHasEntered();
}

void HuGiImpl::s14_entered()
{
	PX1 /= ModPX;
	PX2 /= ModPX;
	LogTxtBrsr->append(trUtf8("  Изменена длина шагов: %1; %2.").arg(PX1.x()).arg(PX2.y()));

	qDebug()<<trUtf8("Come in s12"); // Вывожу дебажную инфу на консоль.

	emit stateHasEntered();
}

void HuGiImpl::s13_entered()
{
	if(FLAG_SO==true)
	stackedWidget->setCurrentIndex(2);
	else
	stackedWidget->setCurrentIndex(4);
	qDebug()<<trUtf8("Come in s13"); // Вывожу дебажную инфу на консоль.
	// Вывожу на форму значение расстояния между предыдущей базовой точкой и
	// текущей, только если была принята новая точка.
	//if(BP != MP){
		//distance_lb->setPalette(QPalette(Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red));
		//distance_lb->setText(QString::number(Length(BP - MP), 'f'));
	}


void HuGiImpl::s12_entered()
{
	MP = NP;
	stackedWidget->setCurrentIndex(3);
	LogTxtBrsr->append(trUtf8("  новая точка: (%1; %2) Принята").arg(MP.x()).arg(MP.y()));
	qDebug()<<trUtf8("Come in s12"); // Вывожу дебажную инфу на консоль.

	emit stateHasEntered(); // Переход по этому сигналу произойдёт, только если выполнится его условие.
}

void HuGiImpl::s11_entered()
{
	NP = MP - PX2;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в отрицательном направлении оси Х2."));

	qDebug()<<trUtf8("Come in s11"); // Вывожу дебажную инфу на консоль.
}

void HuGiImpl::s10_entered()
{
	LogTxtBrsr->append(trUtf8("  новая точка: (%1; %2) не принята").arg(MP.x()).arg(MP.y()));

	qDebug()<<trUtf8("Come in s10"); // Вывожу дебажную инфу на консоль.
}

void HuGiImpl::s9_entered()
{
	NP = MP + PX2;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в положительном направлении оси Х2."));

	qDebug()<<trUtf8("Come in s9"); // Вывожу дебажную инфу на консоль.
}

void HuGiImpl::s8_entered()
{
	LogTxtBrsr->append(trUtf8("  новая точка: (%1; %2) не принята").arg(MP.x()).arg(MP.y()));

	qDebug()<<trUtf8("Come in s8"); // Вывожу дебажную инфу на консоль.
}

void HuGiImpl::s7_entered()
{
	MP = NP;
	LogTxtBrsr->append(trUtf8("  новая точка: (%1; %2) Принята").arg(MP.x()).arg(MP.y()));

	qDebug()<<trUtf8("Come in s7"); // Вывожу дебажную инфу на консоль.
}

void HuGiImpl::s6_entered()
{
	NP = MP - PX1;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в отрицательном направлении оси Х1."));

	qDebug()<<trUtf8("Come in s6"); // Вывожу дебажную инфу на консоль.
}

void HuGiImpl::s5_entered()
{
	LogTxtBrsr->append(trUtf8("  новая точка: (%1; %2) не принята").arg(MP.x()).arg(MP.y()));

	qDebug()<<trUtf8("Come in s5"); // Вывожу дебажную инфу на консоль.
}

void HuGiImpl::s4_entered()
{
	NP = MP + PX1;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в положительном направлении оси Х1."));

	qDebug()<<trUtf8("Come in s4"); // Вывожу дебажную инфу на консоль.
}


void HuGiImpl::s3_entered()
{
	stackedWidget->setCurrentIndex(1);
	BP = MP;
	NP = BP;
	LogTxtBrsr->append(trUtf8("Итерация № %1.").arg(++NumeroIteracio));
	qDebug()<<trUtf8("Come in s3"); // Вывожу дебажную инфу на консоль.
}


void HuGiImpl::s2_entered()
{
stackedWidget->setCurrentIndex(0);
	qDebug()<<trUtf8("Come in s2"); // Вывожу дебажную инфу на консоль.
}

void HuGiImpl::s1_entered()
{
	FLAG_SO=false;
	qDebug()<<trUtf8("Come in s1 flag="+FLAG_SO); // Вывожу дебажную инфу на консоль.
}


void HuGiImpl::so_entered()
{
	qDebug()<<trUtf8("Come in so"); // Вывожу дебажную инфу на консоль.
	stackedWidget->setCurrentIndex(3);
}

void HuGiImpl::init()
{
	qDebug()<<trUtf8("Come in init()"); // Вывожу дебажную инфу на консоль.

//	strikteco = (*D)[0];
	precision_lb->setText(QString::number(strikteco));
	KvantoEraroj = 0;
	NumeroIteracio = 0;
	MP = QPointF(D[4],D[5]);
	MP2 = QPointF(0,0);
	PP = QPointF(0,0);
	PX1 = QPointF(D[1], 0);
	PX2 = QPointF(0, D[2]);
	ModPX = 10;
	LogTxtBrsr->setText("");
	static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->senspurigi();
	static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->difiniUnuaPointo(MP);

	qDebug()<<trUtf8("Задаю переменным начальные значения"); // Вывожу дебажную инфу на консоль.
}





namespace SinkoLauxKoordinatoj_hugi{
	
	bool KonsideriPointoTransiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Check f(np) < f(mp)");
			// Проверяю своё условие.
			return f->rezulto(*np) < f->rezulto(*mp);
		}else{
			return false;
		}
	}

	bool NoKonsideriPointoTransiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Check f(np) >= f(mp)");
			// Проверяю своё условие.
			return f->rezulto(*np) >= f->rezulto(*mp);
		}else{
			return false;
		}
	}

	bool s3s4Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Check, that chose +  X1");
			// Проверяю своё условие.
			return up_x1->isChecked();
		}else{
			return false;
		}
	}

	bool s5s6Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Check, that chose - X1");
			// Проверяю своё условие и вызываю реализацию по умолчанию.
			return down_x1->isChecked();
		}else{
			return false;
		}
	}

	bool s7s9_s8s9Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Check, that chose + X2");
			// Проверяю своё условие.
			return up_x2->isChecked();
		}else{
			return false;
		}
	}

	bool s10s11Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Check, that chose - X2");
			// Проверяю своё условие.
			return down_x2->isChecked();
		}else{
			return false;
		}
	}

	bool s13sfTransiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Check sX1 < е && sX2 < е");
			// Проверяю своё условие.
			return px1->x() < s && px2->y() < s;
		}else{
			return false;
		}
	}

	bool s13s14Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s13s14 Check, that бт ==тт && (шХ1 >= е || шХ2 >= е) ");
			// Проверяю своё условие.
			return *bp == *mp && (px1->x() >= s || px2->y() >= s);
		}else{
			return false;
		}
	}
	
	bool s13s16Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s13s16  пройден поиск по образцу = true && Выбран пункт принять образец &&  f(b2)<f(temp_b2)  ");
			qDebug()<<trUtf8("======FBP=")<<(f->rezulto(*bp));
			qDebug()<<trUtf8("======FTB=")<<(f->rezulto(*temp_b));
			qDebug()<<trUtf8("======FLAG=")<<flag_so;
			// Проверяю своё условие.
			return &flag_so && ok_rb_->isChecked() && (f->rezulto(*bp)) < f->rezulto(*temp_b);
		}else{
			return false;
		}
	}
	
	bool s13s19Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("s13s19  пройден поиск по образцу = true && Выбран пункт не принимать образец &&  f(b2)<f(temp_b2) ");
			// Проверяю своё условие.
			return &flag_so && no_rb_->isChecked() && f->rezulto(*bp) >=f->rezulto(*temp_b);
		}else{
			return false;
		}
	}
	
	bool s15s18_s17s18Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("s15s18_s17s18 нажата кнопка далее выбран поиск по образцу");
			// Проверяю своё условие.
			return model->isChecked() ;
		}else{
			return false;
		}
	}

bool s2s3Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("s2s3 нажата кнопка далее выбран поиск по образцу");
			// Проверяю своё условие.
			return investigate->isChecked() ;
		}else{
			return false;
		}
	}

};

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
	helpBrowserImpl * hb = new helpBrowserImpl( "doc/", "method1.htm", this);
	hb->resize(900, 600);
	hb->show();
}

void HuGiImpl::on_about_action_activated()
{
	aboutProgramImpl * about = new aboutProgramImpl(this);
	about->show();
}
