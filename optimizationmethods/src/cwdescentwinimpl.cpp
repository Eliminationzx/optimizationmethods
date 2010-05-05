#include "cwdescentwinimpl.h"
#include "mapoporfunkcioimpl.h"
#include "Konstantoj.h"
#include "funkcio.h"
#include "spuro.h"
#include "spurosinkolauxkoordinatoj.h"
#include "demonstrataqpointf.h"
#include "math.h"
#include <QTextBrowser>
#include <QString>
#include <QMessageBox>
#include <QStateMachine>
#include <QFinalState>
#include <QLabel>
//
using namespace SinkoLauxKoordinatoj;

CWdescentWinImpl::CWdescentWinImpl( funkcio *f, QVector<double> *d, QWidget * parent, Qt::WFlags flags)
	: AlgoritmoWin(f, d, parent, flags), strikteco((*d)[0]), KvantoEraroj(0),
		NumeroIteracio(0), MP((*d)[4],(*d)[5]),
    PX1((*d)[1], 0), PX2(0, (*d)[2]){
	setupUi(this);

	// Создаю карту.
	// centralwidget->layout() - указатель на компановщик центрального виджета
	// static_cast<QGridLayout*>(centralwidget->layout()) - обьясняю компилятору, что это именно QGridLayout
	// добавляю вижет карты в позицию 1,1. Компановщик сам позаботится о назначении новому виджету родителя.
	static_cast<QGridLayout*>(centralwidget->layout())->addWidget(MapoWdg, 1, 1);

	MapoWdg->setScale(6);// Ставлю масштаб побольше. Надо будет определться с оптимальным значением.

//  MapoWdg->kreiSpuro(A::CWdescent_fix, Qt::blue);
//  Sp = MapoWdg->proviziSpuro();

//===Соединяю точки и надписи на форме==========================================
	MP.connectProviziValoro_QString(x1_lb, SLOT(setText(const QString &)));
	MP.connectProviziValoro_QString(x2_lb, SLOT(setText(const QString &)));
	MP.connectProviziValoro_QString(fsign_lb, SLOT(setText(const QString &)));
	NP.connectProviziValoro_QString(new_x1_lb, SLOT(setText(const QString &)));
	NP.connectProviziValoro_QString(new_x2_lb, SLOT(setText(const QString &)));
	NP.connectProviziValoro_QString(new_fsign_lb, SLOT(setText(const QString &)));
//=============================================================================

//===Создаю конечный автомат.==================================================
	QStateMachine * SM = new QStateMachine(this);
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
	QFinalState * sf = new QFinalState(so);
	QFinalState * sfm = new QFinalState();

//---Создаю переходы, согласно диаграмме.--------------------------------------
	s1s2Transiro * s1s2 = new s1s2Transiro(calculate_bt, SIGNAL(clicked()), s1);
	s1s2->setTargetState(s2);
	NoKonsideriPointoTransiro * s2s3 = new NoKonsideriPointoTransiro(not_accept_bt, SIGNAL(clicked()), s2);
	s2s3->setTargetState(s3);
	s3s4Transiro * s3s4 = new s3s4Transiro(calculate_bt, SIGNAL(clicked()), s3);
	s3s4->setTargetState(s4);
	KonsideriPointoTransiro * s2s5 = new KonsideriPointoTransiro(accept_bt, SIGNAL(clicked()), s2);
	s2s5->setTargetState(s5);
	KonsideriPointoTransiro * s4s5 = new KonsideriPointoTransiro(accept_bt, SIGNAL(clicked()), s4);
	s4s5->setTargetState(s5);
	NoKonsideriPointoTransiro * s4s6 = new NoKonsideriPointoTransiro(not_accept_bt, SIGNAL(clicked()), s4);
	s4s6->setTargetState(s6);
	s5s7_s6s7Transiro * s6s7 = new s5s7_s6s7Transiro(calculate_bt, SIGNAL(clicked()), s6);
	s6s7->setTargetState(s7);
	s5s7_s6s7Transiro * s5s7 = new s5s7_s6s7Transiro(calculate_bt, SIGNAL(clicked()), s5);
	s5s7->setTargetState(s7);
	NoKonsideriPointoTransiro * s7s8 = new NoKonsideriPointoTransiro(not_accept_bt, SIGNAL(clicked()), s7);
	s7s8->setTargetState(s8);
	s8s9Transiro * s8s9 = new s8s9Transiro(calculate_bt, SIGNAL(clicked()), s8);
	s8s9->setTargetState(s9);
	KonsideriPointoTransiro * s9s10 = new KonsideriPointoTransiro(accept_bt, SIGNAL(clicked()), s9);
	s9s10->setTargetState(s10);
	KonsideriPointoTransiro * s7s10 = new KonsideriPointoTransiro(accept_bt, SIGNAL(clicked()), s7);
	s7s10->setTargetState(s10);
	NoKonsideriPointoTransiro * s9s11 = new NoKonsideriPointoTransiro(not_accept_bt, SIGNAL(clicked()), s9);
	s9s11->setTargetState(s11);
	QSignalTransition * s11s12 = new QSignalTransition(change_step_bt, SIGNAL(clicked()), s11);
	s11s12->setTargetState(s12);
	s12sfTransiro * s12sf = new s12sfTransiro(end_bt, SIGNAL(clicked()), s12);
	s12sf->setTargetState(sf);
	s10sfTransiro * s10sf = new s10sfTransiro(end_bt, SIGNAL(clicked()), s10);
	s10sf->setTargetState(sf);
	s12s1Transiro * s12s1 = new s12s1Transiro(this, SIGNAL((stateHasEntered)), s12);
	s12s1->setTargetState(s1);
	s10s1Transiro * s10s1 = new s10s1Transiro(this, SIGNAL((stateHasEntered)), s10);
	s10s1->setTargetState(s1);
//---Создаю переходы не имеющие цели. С помощью них проверяу ошибки ползоватнля-
	QSignalTransition * te1 = new QSignalTransition(calculate_bt, SIGNAL(clicked()));
	te1->setTargetState(so);
	QSignalTransition * te2 = new QSignalTransition(accept_bt, SIGNAL(clicked()));
	te2->setTargetState(so);
	QSignalTransition * te3 = new QSignalTransition(not_accept_bt, SIGNAL(clicked()));
	te3->setTargetState(so);
	QSignalTransition * te4 = new QSignalTransition(change_step_bt, SIGNAL(clicked()));
	te4->setTargetState(so);
	QSignalTransition * te5 = new QSignalTransition(end_bt, SIGNAL(clicked()));
	te5->setTargetState(so);
//---Создаю переход от сложного состояния к финалу автомата.
	so->addTransition(sfm);

//---Добавляю состояния в автомат и запускаю его.------------------------------
	SM->addState(so);
	SM->addState(sfm);
	so->setInitialState(s1);
	SM->setInitialState(so);
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
}

void CWdescentWinImpl::sf_entered(){
  LogTxtBrsr->append(trUtf8("Конец алгоритма. Найден: %1").arg(F->rezulto(MP)));
  QMessageBox::information(this, trUtf8("Конец"), trUtf8("Найден минимум"));
}

void CWdescentWinImpl::s12_entered(){
	PX1 *= ModPX;
	PX2 *= ModPX;
	LogTxtBrsr->append(trUtf8("  Изменена длина шагов: %1; %2.").arg(PX1.x()).arg(PX2.y()));
	emit stateHasEntered();
}

void CWdescentWinImpl::s10_entered(){
	MP = NP;
	LogTxtBrsr->append(trUtf8("  Принята новая текущая точка. Текущая точка: %1; %2").arg(MP.x()).arg(MP.y()));
	emit stateHasEntered();
}

void CWdescentWinImpl::s9_entered(){
	NP = MP - PX2;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в - по оси Х2. Новая точка: %1; %2").arg(NP.x()).arg(NP.y()));
}

void CWdescentWinImpl::s7_entered(){
	NP = MP + PX2;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в + по оси Х2. Новая точка: %1; %2").arg(NP.x()).arg(NP.y()));
}

void CWdescentWinImpl::s5_entered(){
	MP = NP;
	LogTxtBrsr->append(trUtf8("  Принята новая текущая точка. Текущая точка: %1; %2").arg(MP.x()).arg(MP.y()));
}

void CWdescentWinImpl::s4_entered(){
	NP = MP - PX1;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в - по оси Х1. Новая точка: %1; %2").arg(NP.x()).arg(NP.y()));
}

void CWdescentWinImpl::s2_entered(){
	NP = MP + PX1;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в + по оси Х1. Новая точка: %1; %2").arg(NP.x()).arg(NP.y()));
}


void CWdescentWinImpl::s1_entered(){
	BP = MP;
	NP = BP;
	LogTxtBrsr->append(trUtf8("Начало итерации № %1. Базовая точка: %2; %3. Текущая точка: %4; %5. Новая точка: %6; %7. Длина шагов: %8; %9.").arg(++NumeroIteracio).arg(BP.x()).arg(BP.y()).arg(MP.x()).arg(MP.y()).arg(NP.x()).arg(NP.y()).arg(PX1.x()).arg(PX2.y()));
}

namespace SinkoLauxKoordinatoj{
	bool KonsideriPointoTransiro::eventTest(QEvent *e){
		// Проверяю своё условие и вызываю реализацию поумолчанию.
		return o->f()->rezulto(o->np()) < o->f()->rezulto(o->mp())
		       && QSignalTransition::eventTest(e);
	}

	bool NoKonsideriPointoTransiro::eventTest(QEvent *e){
		// Проверяю своё условие и вызываю реализацию поумолчанию.
		return o->f()->rezulto(o->np()) >= o->f()->rezulto(o->mp())
		       && QSignalTransition::eventTest(e);
	}

	bool s1s2Transiro::eventTest(QEvent *e){
		// Проверяю своё условие и вызываю реализацию поумолчанию.
		return o->up_x1_rb->isChecked() && QSignalTransition::eventTest(e);
	}

	bool s3s4Transiro::eventTest(QEvent *e){
		// Проверяю своё условие и вызываю реализацию поумолчанию.
		return o->down_x1_rb->isChecked()
		       && QSignalTransition::eventTest(e);
	}

	bool s5s7_s6s7Transiro::eventTest(QEvent *e){
		// Проверяю своё условие и вызываю реализацию поумолчанию.
		return o->up_x2_rb->isChecked()
		       && QSignalTransition::eventTest(e);
	}

	bool s8s9Transiro::eventTest(QEvent *e){
		// Проверяю своё условие и вызываю реализацию поумолчанию.
		return o->down_x2_rb->isChecked()
		       && QSignalTransition::eventTest(e);
	}

	bool s10sfTransiro::eventTest(QEvent *e){
		// Проверяю своё условие и вызываю реализацию поумолчанию.
		return Length(o->mp() - o->bp()) < o->Strikteco()
		       && QSignalTransition::eventTest(e);
	}

	bool s10s1Transiro::eventTest(QEvent *e){
		// Проверяю своё условие и вызываю реализацию поумолчанию.
		return Length(o->mp() - o->bp()) >= o->Strikteco()
		       && QSignalTransition::eventTest(e);
	}

	bool s12sfTransiro::eventTest(QEvent *e){
		// Проверяю своё условие и вызываю реализацию поумолчанию.
		return o->pX1().x() < o->Strikteco()
		       && o->pX2().x() < o->Strikteco()
		       && QSignalTransition::eventTest(e);
	}

	bool s12s1Transiro::eventTest(QEvent *e){
		// Проверяю своё условие и вызываю реализацию поумолчанию.
		return (o->pX1().x() >= o->Strikteco() || o->pX2().x() >= o->Strikteco())
		       && QSignalTransition::eventTest(e);
	}

};
