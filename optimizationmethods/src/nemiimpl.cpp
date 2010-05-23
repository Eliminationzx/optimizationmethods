#include "nemiimpl.h"
#include "demonstrataqpointf.h"
#include "signalantoporpointf.h"
#include "HelpBrowser.h"
#include "mapoporfunkcioimpl.h"
#include "Konstantoj.h"
#include "funkcio.h"
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

	qDebug()<<trUtf8("Вошёл в s1"); // Вывожу дебажную инфу на консоль.
}


void NeMiImpl::s2_entered(){

	qDebug()<<trUtf8("Вошёл в s2"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s3_entered(){

	qDebug()<<trUtf8("Вошёл в s3"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s5_entered(){

	qDebug()<<trUtf8("Вошёл в s5"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s6_entered(){

	qDebug()<<trUtf8("Вошёл в s6"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s7_entered(){

	qDebug()<<trUtf8("Вошёл в s7"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s8_entered(){

	qDebug()<<trUtf8("Вошёл в s8"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s9_entered(){

	qDebug()<<trUtf8("Вошёл в s9"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s10_entered(){

	qDebug()<<trUtf8("Вошёл в s10"); // Вывожу дебажную инфу на консоль.
}

void NeMiImpl::s11_entered(){

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
