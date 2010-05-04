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
//
using namespace SinkoLauxKoordinatoj;

CWdescentWinImpl::CWdescentWinImpl( funkcio *f, QVector<double> *d, QWidget * parent, Qt::WFlags flags) 
	: AlgoritmoWin(f, d, parent, flags), strikteco((*d)[0]), KvantoEraroj(0),
		NumeroIteracio(0), MP((*d)[4],(*d)[5]),
    PX1((*d)[1], 0), PX2(0, (*d)[2]){
	setupUi(this);
/*  
  // Создаю карту.
  // centralwidget->layout() - указатель на компановщик центрального виджета
  // static_cast<QGridLayout*>(centralwidget->layout()) - обьясняю компилятору, что это именно QGridLayout
  // добавляю вижет карты в позицию 1,1. Компановщик сам позаботится о назначении новому виджету родителя.
  static_cast<QGridLayout*>(centralwidget->layout())->addWidget(MapoWdg, 1, 1);
  
  MapoWdg->setScale(6);// Ставлю масштаб побольше. Надо будет определться с оптимальным значением.
  
  MapoWdg->kreiSpuro(A::CWdescent_fix, Qt::blue);
  Sp = MapoWdg->proviziSpuro();
  
  // Создаю конечный автомат.
  QStateMachine * SM = new QStateMachine(this); 
  // Создаю состояния, согласно диаграмме.
  QState * s1 = new QState();
  QState * s2 = new QState();
  QState * s3 = new QState();
  QState * s4 = new QState();
  QState * s5 = new QState();
  QState * s6 = new QState();
  QState * s7 = new QState();
  QState * s8 = new QState();
  QState * sf = new QState();
  
  // Создаю переходы, согласно диаграмме.
  s1s2Transiro * s1s2 = new s1s2Transiro(calculate_bt, SIGNAL(clicked()), s1);
  s1s2->setTargetState(s2);
  s2s3Transiro * s2s3 = new s2s3Transiro(calculate_bt, SIGNAL(clicked()), s2);
  s2s3->setTargetState(s3);  
  KonsideriPointoTransiro * s2s4 = new KonsideriPointoTransiro(accept_bt, SIGNAL(clicked()), s2);
  s2s4->setTargetState(s4);  
  KonsideriPointoTransiro * s3s4 = new KonsideriPointoTransiro(accept_bt, SIGNAL(clicked()), s3);
  s3s4->setTargetState(s4);  
  s3s5Transiro * s3s5 = new s3s5Transiro(calculate_bt, SIGNAL(clicked()), s3);
  s3s5->setTargetState(s5);  
  s4s5Transiro * s4s5 = new s4s5Transiro(calculate_bt, SIGNAL(clicked()), s4);
  s4s5->setTargetState(s5);  
  s5s6Transiro * s5s6 = new s5s6Transiro(calculate_bt, SIGNAL(clicked()), s5);
  s5s6->setTargetState(s6);  
  KonsideriPointoTransiro * s5s7 = new KonsideriPointoTransiro(accept_bt, SIGNAL(clicked()), s5);
  s5s7->setTargetState(s7);  
  KonsideriPointoTransiro * s6s7 = new KonsideriPointoTransiro(accept_bt, SIGNAL(clicked()), s6);
  s6s7->setTargetState(s7);  
  s6s8Transiro * s6s8 = new s6s8Transiro(end_bt, SIGNAL(clicked()), s6);
  s6s8->setTargetState(s8);  
/*  
  
  //Вывожу значения.
  precision_lb->setText(QString::number((*d)[0]));
  x1_lb->setText(QString::number(MomentaPointo.x()));
  x2_lb->setText(QString::number(MomentaPointo.y()));
//  new_x1_lb->setText(trUtf8("Неопределено"));
//  new_x2_lb->setText(trUtf8("Неопределено"));
  x1_step_lb->setText(QString::number(PasxoX1.x()));
  x2_step_lb->setText(QString::number(PasxoX2.y()));
  fsign_lb->setText(QString::number(F->rezulto(MomentaPointo)));
//  new_fsign_lb->setText(trUtf8("Неопределено"));
  
  LogTxtBrsr->append(trUtf8("Начало поиска минимума Покоординатным спуском с  фиксированным шагом."));
*/  
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
  QMessageBox::information(this, trUtf8("Конец"), trUtf8("Найден минимум"));
	
}

void CWdescentWinImpl::s8_entered(){
	PX1 *= ModPX;
	PX2 *= ModPX;
	LogTxtBrsr->append(trUtf8("  Изменена длина шагов: %1; %2.").arg(PX1.x()).arg(PX2.y()));
}

void CWdescentWinImpl::s7_entered(){
	MP = NP;
	LogTxtBrsr->append(trUtf8("  Принята новая текущая точка. Текущая точка: %1; %2. Расстояние от базовой точки до текущей: %3").arg(MP.x()).arg(MP.y()).arg(Length(BP - MP)));
}

void CWdescentWinImpl::s6_entered(){
	NP = MP - PX2;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в - по оси Х2. Новая точка: %1; %2").arg(NP.x()).arg(NP.y()));
}

void CWdescentWinImpl::s5_entered(){
	NP = MP + PX2;
	LogTxtBrsr->append(trUtf8("  Сделан шаг в + по оси Х2. Новая точка: %1; %2").arg(NP.x()).arg(NP.y()));
}

void CWdescentWinImpl::s4_entered(){
	MP = NP;
	LogTxtBrsr->append(trUtf8("  Принята новая текущая точка. Текущая точка: %1; %2").arg(MP.x()).arg(MP.y()));
}


void CWdescentWinImpl::s3_entered(){
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
