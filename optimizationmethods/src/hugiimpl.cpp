#include "hugiimpl.h"
#include "mapoporfunkcioimpl.h"
#include "Konstantoj.h"
#include "funkcio.h"
#include "spurosinkolauxkoordinatoj.h"
#include "demonstrataqpointf.h"
#include "signalantoporpointf.h"
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
			return !(*flag) && investigate_rb->isChecked();
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
			return *flag && model_rb->isChecked();
		}else{
			return false;
		}
	}

bool s3s5s4s5Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e)){
			qDebug()<<trUtf8(" s3s5s4s5  flag == true && up to x1  has chosen");
			// Проверяю своё условие.
			return up_x1->isChecked();
		}else{
			return false;
		}
	}
}




//

