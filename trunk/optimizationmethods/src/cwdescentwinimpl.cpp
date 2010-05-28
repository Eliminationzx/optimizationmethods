#include "cwdescentwinimpl.h"
#include "mapoporfunkcioimpl.h"
#include "Konstantoj.h"
#include "funkcio.h"
#include "spuro.h"
#include "spurosinkolauxkoordinatoj.h"
#include "demonstrataqpointf.h"
#include "signalantoporpointf.h"
#include "HelpBrowser.h"
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
using namespace SinkoLauxKoordinatoj;

CWdescentWinImpl::CWdescentWinImpl( funkcio *f, QVector<double> *d, QWidget * parent, Qt::WFlags flags)
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
	verticalLayout_4->addWidget(MapoWdg, 2);

	MapoWdg->setScale(20);// Ставлю масштаб побольше. Надо будет определиться с оптимальным значением.

	Sp = new spuroSinkoLauxKoordinatoj(Qt::white, Qt::blue);
	MapoWdg->difiniSpuro(Sp);
	MapoWdg->difiniFonaKoloro(Qt::green);

	connect(MapoWdg, SIGNAL(MusaPos(const QString &)), statusBar(), SLOT(showMessage( const QString &)));

//===Соединяю точки и надписи на форме=========================================
	SignalantoPorPointF * sMP = new SignalantoPorPointF(&MP, F, this);
	connect(sMP, SIGNAL(proviziXValoro(const QString &)), x1_lb, SLOT(setText(const QString &)));
	connect(sMP, SIGNAL(proviziYValoro(const QString &)), x2_lb, SLOT(setText(const QString &)));
	connect(sMP, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), fsign_lb, SLOT(setText(const QString &)));
	SignalantoPorPointF * sNP = new SignalantoPorPointF(&NP, F, this);
	connect(sNP, SIGNAL(proviziXValoro(const QString &)), new_x1_lb, SLOT(setText(const QString &)));
	connect(sNP, SIGNAL(proviziYValoro(const QString &)), new_x2_lb, SLOT(setText(const QString &)));
	connect(sNP, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), new_fsign_lb, SLOT(setText(const QString &)));
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
	connect(sf, SIGNAL(entered()), SLOT(sf_entered()));

//---Создаю переходы, согласно диаграмме.--------------------------------------
	s1s2Transiro * s1s2 = new s1s2Transiro(up_x1_rb, calculate_bt, SIGNAL(clicked()), s1);
	s1s2->setTargetState(s2);
	NoKonsideriPointoTransiro * s2s3 = new NoKonsideriPointoTransiro(&MP, &NP, F, not_accept_bt, SIGNAL(clicked()), s2);
	s2s3->setTargetState(s3);
	KonsideriPointoTransiro * s2s5 = new KonsideriPointoTransiro(&MP, &NP, F, accept_bt, SIGNAL(clicked()), s2);
	s2s5->setTargetState(s5);
	s3s4Transiro * s3s4 = new s3s4Transiro(down_x1_rb, calculate_bt, SIGNAL(clicked()), s3);
	s3s4->setTargetState(s4);
	KonsideriPointoTransiro * s4s5 = new KonsideriPointoTransiro(&MP, &NP, F, accept_bt, SIGNAL(clicked()), s4);
	s4s5->setTargetState(s5);
	NoKonsideriPointoTransiro * s4s6 = new NoKonsideriPointoTransiro(&MP, &NP, F, not_accept_bt, SIGNAL(clicked()), s4);
	s4s6->setTargetState(s6);
	s5s7_s6s7Transiro * s5s7 = new s5s7_s6s7Transiro(up_x2_rb, calculate_bt, SIGNAL(clicked()), s5);
	s5s7->setTargetState(s7);
	s5s7_s6s7Transiro * s6s7 = new s5s7_s6s7Transiro(up_x2_rb, calculate_bt, SIGNAL(clicked()), s6);
	s6s7->setTargetState(s7);
	NoKonsideriPointoTransiro * s7s8 = new NoKonsideriPointoTransiro(&MP, &NP, F, not_accept_bt, SIGNAL(clicked()), s7);
	s7s8->setTargetState(s8);
	KonsideriPointoTransiro * s7s10 = new KonsideriPointoTransiro(&MP, &NP, F, accept_bt, SIGNAL(clicked()), s7);
	s7s10->setTargetState(s10);
	s8s9Transiro * s8s9 = new s8s9Transiro(down_x2_rb, calculate_bt, SIGNAL(clicked()), s8);
	s8s9->setTargetState(s9);
	KonsideriPointoTransiro * s9s10 = new KonsideriPointoTransiro(&MP, &NP, F, accept_bt, SIGNAL(clicked()), s9);
	s9s10->setTargetState(s10);
	NoKonsideriPointoTransiro * s9s11 = new NoKonsideriPointoTransiro(&MP, &NP, F, not_accept_bt, SIGNAL(clicked()), s9);
	s9s11->setTargetState(s11);
	s10->addTransition(this, SIGNAL(stateHasEntered()), s11);// Переход s10s11 совершается
	                                                // сразу при входе в s10.
	s11s1Transiro * s11s1 = new s11s1Transiro(&BP, &MP, &PX1, &PX2, strikteco, s11, SIGNAL(entered()), s11);
	s11s1->setTargetState(s1);
	s11s12Transiro * s11s12 = new s11s12Transiro(&BP, &MP, &PX1, &PX2, strikteco, change_step_bt, SIGNAL(clicked()), s11);
	s11s12->setTargetState(s12);
	s11sfTransiro * s11sf = new s11sfTransiro( &PX1, &PX2, strikteco, end_bt, SIGNAL(clicked()), s11);
	s11sf->setTargetState(sf);
	s12->addTransition(this, SIGNAL(stateHasEntered()), s1);
//---Создаю переход по действию "Начать заново"
	connect(so->addTransition(recomenci_acn, SIGNAL(activated()), s1), SIGNAL(triggered()), SLOT(init()));
	connect(sf->addTransition(recomenci_acn, SIGNAL(activated()), s1), SIGNAL(triggered()), SLOT(init()));
//---Создаю переходы не имеющие цели. С помощью них фиксирую ошибки пользователя
	QSignalTransition * te1 = new QSignalTransition(calculate_bt, SIGNAL(clicked()));
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


//---Настраиваю некоторые состояния, чтоб затирали надпись со значениями новой точки, дабы не смущать пользователя.
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

//---Прикручиваю карту---------------------------------------------------------
	connect(sNP, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(aldoniSercxantaPointo(QPointF)));
	connect(sMP, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(difiniMomentaPointo(QPointF)));

	connect(s3, SIGNAL(entered()), Sp, SLOT(reveniAlMomentoPointo()));
	connect(s6, SIGNAL(entered()), Sp, SLOT(reveniAlMomentoPointo()));
	connect(s8, SIGNAL(entered()), Sp, SLOT(reveniAlMomentoPointo()));
	connect(s9s11, SIGNAL(triggered()), Sp, SLOT(reveniAlMomentoPointo()));

	connect(s1, SIGNAL(entered()), Sp, SLOT(finisxiIteracio()));
//-------------------------------------------------------------------------------

//---Добавляю состояния в автомат и запускаю его.------------------------------
	SM->addState(so);
	SM->addState(sf);
	SM->setInitialState(so);
	init();
	SM->start();
//=============================================================================

/*//=========Пример======================================================================================Дальше прога что-то кастует.)
  //------Итерация 1-----------------------------------------------------------
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->difiniUnuaPointo(QPoint(0, 0));
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10, 0));
  //spuroSinkoLauxKoordinatoj не проверяет логику.
  //Он соединяет подрят все переданные ему точки.
  //В следующей строке совершена ошибка с точки зрения алгоритма.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(20, 10));
  //! Завершаю итерацию.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->finisxiIteracio();

  //------Итерация 2-----------------------------------------------------------
  //! Далее буду следовать алгоритму Покоординатного спуска.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(20+10, 10));
  //Пусть значение в новой точке неменьше чем в базовой.
  //Вернусь назад.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(20-10, 10));
  //Пусть значение в новой точке меньше чем в базовой.
  //Ура, завершаю итерацию.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->finisxiIteracio();
  //------Итерация 3-----------------------------------------------------------
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10+5, 10));
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10-5, 10));
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10, 10+5));
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10, 10-5));
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  //Надо уменьшить шаг и прейти к следующей итерации.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->finisxiIteracio();
  //------Итерация 4-----------------------------------------------------------
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10+2.5, 10));
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10-2.5, 10));
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10, 10+2.5));
  //Пусть значение в новой точке меньше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->finisxiIteracio();
  //------Итерация 5-----------------------------------------------------------
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10+1.25, 12.5));
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10-1.25, 12.5));
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10, 12.5+1.25));
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10, 12.5-1.25));
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  //Надо уменьшить шаг.
  //Пусть новый шаг меньше заданой тосности.
  //!!!!!!Ура, нашли минимум!!!!!!!!!!!!!!!!
//======================================================================================================Вунш пунш*/
}
//


void CWdescentWinImpl::registriEraro(){
  ++KvantoEraroj;
  LogTxtBrsr->append(trUtf8("    Совершена ошибка. Общее количество ошибок: %1").arg(KvantoEraroj));
  QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Неправильное действие"));
  msg.exec();

	qDebug()<<trUtf8("Пользователь ошибся"); // Вывожу дебажную инфу на консоль.
}

void CWdescentWinImpl::sf_entered(){
	LogTxtBrsr->append(trUtf8("Конец алгоритма. Найден: %1").arg(F->rezulto(MP)));
	QString str = trUtf8("Найден минимум. ");

	qDebug()<<trUtf8("Конец алгоритма. Найден минимум"); // Вывожу дебажную инфу на консоль.

	if(KvantoEraroj > D[6]){
		// Слишком много ошибок.
		str += trUtf8("Ваше количество ошибок (%1) превысило допустимый предел (%2). Начните заново.").arg(KvantoEraroj).arg(D[6]);
		QMessageBox::information(this, trUtf8("Внимание"), str);
		if(F->metaObject()->className() == QString("RavinaFunkcio"))
			emit usiloPlenumis(A::CWdescent_fix);
		else recomenci_acn->trigger();
	}else{
		str += trUtf8("Вы прошли тест. ");
		if(F->metaObject()->className() == QString("KvadratigantoFunkcio"))
		{
			str += trUtf8("Сообщите преподавателю и перейдите к овражной функции. Количество ошибок: %1.").arg(KvantoEraroj);
			emit usiloPlenumis(A::CWdescent_fix);
		}
		else if(F->metaObject()->className() == QString("RavinaFunkcio"))
		{
			str += trUtf8("Позовите преподавателя. Количество ошибок: %1.").arg(KvantoEraroj);
		}
		QMessageBox::information(this, trUtf8("Поздравляем"), str);
	}
}

void CWdescentWinImpl::s12_entered(){
	PX1 *= ModPX;
	PX2 *= ModPX;
	LogTxtBrsr->append(trUtf8("  Изменена длина шагов: %1; %2.").arg(PX1.x()).arg(PX2.y()));

	qDebug()<<trUtf8("Вошёл в s12"); // Вывожу дебажную инфу на консоль.

	emit stateHasEntered();
}

void CWdescentWinImpl::s11_entered(){
	// Вывожу на форму значение расстояния между предыдущей базовой точкой и
	// текущей, только если была принята новая точка.
	if(BP != MP){
		distance_lb->setPalette(QPalette(Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red));
		distance_lb->setText(QString::number(Length(BP - MP), 'f'));
	}

	qDebug()<<trUtf8("Вошёл в s11"); // Вывожу дебажную инфу на консоль.
}

void CWdescentWinImpl::s10_entered(){
	MP = NP;
	LogTxtBrsr->append(trUtf8("  новая точка: (%1; %2) Принята").arg(MP.x()).arg(MP.y()));
	qDebug()<<trUtf8("Вошёл в s10"); // Вывожу дебажную инфу на консоль.

	emit stateHasEntered(); // Переход по этому сигналу произойдёт, только если выполнится его условие.
}

void CWdescentWinImpl::s9_entered(){
	NP = MP - PX2;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в отрицательном направлении оси Х2."));

	qDebug()<<trUtf8("Вошёл в s9"); // Вывожу дебажную инфу на консоль.
}

void CWdescentWinImpl::s8_entered(){
	LogTxtBrsr->append(trUtf8("  новая точка: (%1; %2) не принята").arg(MP.x()).arg(MP.y()));

	qDebug()<<trUtf8("Вошёл в s8"); // Вывожу дебажную инфу на консоль.
}

void CWdescentWinImpl::s7_entered(){
	NP = MP + PX2;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в положительном направлении оси Х2."));

	qDebug()<<trUtf8("Вошёл в s7"); // Вывожу дебажную инфу на консоль.
}

void CWdescentWinImpl::s6_entered(){
	LogTxtBrsr->append(trUtf8("  новая точка: (%1; %2) не принята").arg(MP.x()).arg(MP.y()));

	qDebug()<<trUtf8("Вошёл в s6"); // Вывожу дебажную инфу на консоль.
}

void CWdescentWinImpl::s5_entered(){
	MP = NP;
	LogTxtBrsr->append(trUtf8("  новая точка: (%1; %2) Принята").arg(MP.x()).arg(MP.y()));

	qDebug()<<trUtf8("Вошёл в s5"); // Вывожу дебажную инфу на консоль.
}

void CWdescentWinImpl::s4_entered(){
	NP = MP - PX1;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в отрицательном направлении оси Х1."));

	qDebug()<<trUtf8("Вошёл в s4"); // Вывожу дебажную инфу на консоль.
}

void CWdescentWinImpl::s3_entered(){
	LogTxtBrsr->append(trUtf8("  новая точка: (%1; %2) не принята").arg(MP.x()).arg(MP.y()));

	qDebug()<<trUtf8("Вошёл в s3"); // Вывожу дебажную инфу на консоль.
}

void CWdescentWinImpl::s2_entered(){
	NP = MP + PX1;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в положительном направлении оси Х1."));

	qDebug()<<trUtf8("Вошёл в s2"); // Вывожу дебажную инфу на консоль.
}


void CWdescentWinImpl::s1_entered(){
	BP = MP;
	NP = BP;
	LogTxtBrsr->append(trUtf8("Итерация № %1.").arg(++NumeroIteracio));

	qDebug()<<trUtf8("Вошёл в s1"); // Вывожу дебажную инфу на консоль.
}

void CWdescentWinImpl::so_entered(){
	qDebug()<<trUtf8("Вошёл в so"); // Вывожу дебажную инфу на консоль.
}

void CWdescentWinImpl::init(){
	qDebug()<<trUtf8("Вхожу в init()"); // Вывожу дебажную инфу на консоль.

//	strikteco = (*D)[0];
	precision_lb->setText(QString::number(strikteco));
	KvantoEraroj = 0;
	NumeroIteracio = 0;
	MP = QPointF(D[4],D[5]);
	PX1 = QPointF(D[1], 0);
	PX2 = QPointF(0, D[2]);
	ModPX = D[3];
	LogTxtBrsr->setText("");
	static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->senspurigi();
	static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->difiniUnuaPointo(MP);

	qDebug()<<trUtf8("Задаю переменным начальные значения"); // Вывожу дебажную инфу на консоль.
}

namespace SinkoLauxKoordinatoj{
	bool KonsideriPointoTransiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю f(np) < f(mp)");
			// Проверяю своё условие.
			return f->rezulto(*np) < f->rezulto(*mp);
		}else{
			return false;
		}
	}

	bool NoKonsideriPointoTransiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю f(np) >= f(mp)");
			// Проверяю своё условие.
			return f->rezulto(*np) >= f->rezulto(*mp);
		}else{
			return false;
		}
	}

	bool s1s2Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю, что выбран шаг в + по X1");
			// Проверяю своё условие.
			return up_x1->isChecked();
		}else{
			return false;
		}
	}

	bool s3s4Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю, что выбран шаг в - по X1");
			// Проверяю своё условие и вызываю реализацию по умолчанию.
			return down_x1->isChecked();
		}else{
			return false;
		}
	}

	bool s5s7_s6s7Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю, что выбран шаг в + по X2");
			// Проверяю своё условие.
			return up_x2->isChecked();
		}else{
			return false;
		}
	}

	bool s8s9Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю, что выбран шаг в - по X2");
			// Проверяю своё условие.
			return down_x2->isChecked();
		}else{
			return false;
		}
	}

	bool s11sfTransiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю шХ1 < е && шХ2 < е");
			// Проверяю своё условие.
			return px1->x() < s && px2->y() < s;
		}else{
			return false;
		}
	}

	bool s11s1Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю бт !=тт && (шХ1 >= е || шХ2 >= е)");
			// Проверяю своё условие.
			return *bp != *mp && (px1->x() >= s || px2->y() >= s);
		}else{
			return false;
		}
	}

	bool s11s12Transiro::eventTest(QEvent *e){
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8("  Проверяю, что бт ==тт && (шХ1 >= е || шХ2 >= е) ");
			// Проверяю своё условие.
			return *bp == *mp && (px1->x() >= s || px2->y() >= s);
		}else{
			return false;
		}
	}

};

void CWdescentWinImpl::on_difiniFonto_act_activated()
{
	bool b;
	QFont fnt = QFontDialog::getFont(&b, font());
	if(b){
		// Была нажата кнопка ОК.
		setFont(fnt);
	}
}

void CWdescentWinImpl::on_helpo_action_activated()
{
	HelpBrowser * hb = new HelpBrowser( "doc/", "method1.htm", this);
	hb->resize(800, 600);
	hb->show();
}
