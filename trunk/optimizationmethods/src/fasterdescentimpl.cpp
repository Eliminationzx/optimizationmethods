#include "fasterdescentimpl.h"
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
using namespace SinkoFD;

FasterDescentImpl::FasterDescentImpl( funkcio *f, QVector<double> *d, QWidget * parent, Qt::WFlags flags)
	: AlgoritmoWin(f, d, parent, flags)
{
	setupUi(this);
	qDebug()<<trUtf8("Наискорейший спуск"); // Вывожу дебажную инфу на консоль.

	NumeroIteracio = 1;

	// Создаю карту.
	// centralwidget->layout() - указатель на компановщик центрального виджета
	// static_cast<QGridLayout*>(centralwidget->layout()) - обьясняю компилятору, что это именно QGridLayout
	// добавляю вижет карты в позицию 1,1. Компановщик сам позаботится о назначении новому виджету родителя.
	static_cast<QGridLayout*>(centralwidget->layout())->addWidget(MapoWdg, 1, 1);

	MapoWdg->setScale(20);// Ставлю масштаб побольше. Надо будет определться с оптимальным значением.

	Sp = new spuroSinkoLauxKoordinatoj(Qt::white, Qt::blue);
	MapoWdg->difiniSpuro(Sp);
	MapoWdg->difiniFonaKoloro(Qt::green);

	connect(MapoWdg, SIGNAL(MusaPos(const QString &)), statusBar(), SLOT(showMessage( const QString &)));

	//===Соединяю точки и надписи на форме=========================================
	SignalantoPorPointF * sBP = new SignalantoPorPointF(&BP, F, this);
	connect(sBP, SIGNAL(proviziXValoro(const QString &)), x1_lb, SLOT(setText(const QString &)));
	connect(sBP, SIGNAL(proviziYValoro(const QString &)), x2_lb, SLOT(setText(const QString &)));
	connect(sBP, SIGNAL(proviziValoroFukcioEnPointo(const QString &)), fsign_lb, SLOT(setText(const QString &)));
	SignalantoPorPointF * sGRAD = new SignalantoPorPointF(&grad, F, this);
	connect(sGRAD, SIGNAL(proviziXValoro(const QString &)), s_x1_lb, SLOT(setText(const QString &)));
	connect(sGRAD, SIGNAL(proviziYValoro(const QString &)), s_x2_lb, SLOT(setText(const QString &)));

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
	QState * sf = new QState();
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
	connect(sf, SIGNAL(entered()), SLOT(sf_entered()));

	//---Создаю переходы, согласно диаграмме.--------------------------------------
	s1s2Transiro * s1s2 = new s1s2Transiro(inserts_bt, SIGNAL(clicked()), s1);
	s1s2->setTargetState(s2);
	s2s3Transiro * s2s3 = new s2s3Transiro(&NumeroIteracio, agrad_fx, next1_bt, SIGNAL(clicked()), s2);
	s2s3->setTargetState(s3);
	s2s4Transiro * s2s4 = new s2s4Transiro(&NumeroIteracio, agrad_fx, next1_bt, SIGNAL(clicked()), s2);
	s2s4->setTargetState(s4);
	s3s4Transiro * s3s4 = new s3s4Transiro(F, dfdx1, dfdx2, next2_bt, SIGNAL(clicked()), s3);
	s3s4->setTargetState(s4);
	s4s5Transiro * s4s5 = new s4s5Transiro(check_bt, SIGNAL(clicked()), s4);
	s4s5->setTargetState(s5);
	s5s6Transiro * s5s6 = new s5s6Transiro(gradfx, next3_bt, SIGNAL(clicked()), s5);
	s5s6->setTargetState(s6);
	s6s7Transiro * s6s7 = new s6s7Transiro(&grad, strikteco, calcula_bt, SIGNAL(clicked()), s6);
	s6s7->setTargetState(s7);
	s6sfTransiro * s6sf = new s6sfTransiro(&grad, strikteco, end_bt, SIGNAL(clicked()), s6);
	s6sf->setTargetState(sf);
	s7s8Transiro * s7s8 = new s7s8Transiro(minf, next4_bt, SIGNAL(clicked()), s7);
	s7s8->setTargetState(s8);
	s8s9Transiro * s8s9 = new s8s9Transiro(&BP, &grad, step_bt, SIGNAL(clicked()), s8);
	s8s9->setTargetState(s9);
	s9->addTransition(this, SIGNAL(stateHasEntered()), s1);

	//---Создаю переход по действию "Начать заново"
	connect(so->addTransition(recomenc_acn, SIGNAL(activated()), s1), SIGNAL(triggered()), SLOT(init()));
	connect(sf->addTransition(recomenc_acn, SIGNAL(activated()), s1), SIGNAL(triggered()), SLOT(init()));

	//---Создаю переходы не имеющие цели. С помощью них фиксирую ошибки ползователя
	QSignalTransition * te1 = new QSignalTransition(inserts_bt, SIGNAL(clicked()));
	so->addTransition(te1);
	connect(te1, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te2 = new QSignalTransition(calcula_bt, SIGNAL(clicked()));
	so->addTransition(te2);
	connect(te2, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te3 = new QSignalTransition(check_bt, SIGNAL(clicked()));
	so->addTransition(te3);
	connect(te3, SIGNAL(triggered()), SLOT(registriEraro()));
	QSignalTransition * te4 = new QSignalTransition(step_bt, SIGNAL(clicked()));
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
	QSignalTransition * te9 = new QSignalTransition(next4_bt, SIGNAL(clicked()));
	so->addTransition(te9);
	connect(te9, SIGNAL(triggered()), SLOT(registriEraro()));

	//---Настраиваю выделение цветом растояния между точками.
/*	s4->assignProperty(dx_lb, "palette", QPalette(Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red));
	s4->assignProperty(df_lb, "palette", QPalette(Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red, Qt::red));
	s1->assignProperty(dx_lb, "palette", this->palette());
	s1->assignProperty(df_lb, "palette", this->palette());
*/

//---Прикручиваю карту---------------------------------------------------------
	connect(sBP, SIGNAL(proviziValoro(const QPointF &)), Sp, SLOT(difiniMomentaPointo(QPointF)));

	connect(s9, SIGNAL(entered()), Sp, SLOT(reveniAlMomentoPointo()));

	connect(s1, SIGNAL(entered()), Sp, SLOT(finisxiIteracio()));
	
	//---Добавляю состояния в автомат и запускаю его.------------------------------
	SM->addState(so);
	SM->addState(sf);
	SM->setInitialState(so);
	init();
	SM->start();
}
//

void FasterDescentImpl::registriEraro()
{
	++KvantoEraroj;
	LogTxtBrsr->append(trUtf8("    Совершена ошибка. Общее количество ошибок: %1").arg(KvantoEraroj));
	QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Неправильное действие"));
	msg.exec();
	
	qDebug()<<trUtf8("Пользователь ошибся"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::sf_entered()
{
	LogTxtBrsr->append(trUtf8("Конец алгоритма. Найден минимум функции: %1").arg(F->rezulto(BP)));
	
	QString str = trUtf8("Найден минимум. ");
	
	if (KvantoEraroj <= quanError)
	{
		str += trUtf8("Вы прошли тест. ");
		if(F->metaObject()->className() == QString("KvadratigantoFunkcio"))
		{
			str += trUtf8("Сообщите преподавателю и перейдите к овражной функции.");
			emit usiloPlenumis(2);
		}
		else if(F->metaObject()->className() == QString("RavinaFunkcio"))
		{
			str += trUtf8("Позовите преподавателя.");
		}
		QMessageBox::information(this, trUtf8("Поздравляем"), str);
	}
	else
	{
		QMessageBox::information(this, trUtf8("Внимание"), trUtf8("Вы допустили слишком большое количество ошибок. Начните заново."));
		recomenc_acn->trigger();
	}

	qDebug()<<trUtf8("Вошёл в Финальное состояние, сложного состояния"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::s9_entered()
{
	BP = QPointF(BP.x() - lengthStep*grad.x(), BP.y() - lengthStep*grad.y()); 

	qDebug()<<trUtf8("Вошёл в s9"); // Вывожу дебажную инфу на консоль.
	
	emit stateHasEntered(); // Переход по этому сигналу произойдёт, только если выполнится его условие.
}

void FasterDescentImpl::s8_entered()
{
	stackedWidget->setCurrentIndex(4);
	
	lengthStep = F->lengthOfStep(grad);
	
	length_step_a_lb->setText(QString::number(lengthStep, 'f'));

	LogTxtBrsr->append(trUtf8("  а вычислено успешно"));

	qDebug()<<trUtf8("Вошёл в s8"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::s7_entered()
{
	stackedWidget->setCurrentIndex(3);
	
//	minf->setChecked(false);
	
	LogTxtBrsr->append(trUtf8("  Вычисляем а"));

	qDebug()<<trUtf8("Вошёл в s7"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::s6_entered()
{
	stackedWidget->setCurrentIndex(4);
	
	length_grad_lb->setText(QString::number(Length(grad), 'f'));
	
	LogTxtBrsr->append(trUtf8("  Проверка точности выполнена"));

	qDebug()<<trUtf8("Вошёл в s6"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::s5_entered()
{
	stackedWidget->setCurrentIndex(2);
	
//	gradfx->setChecked(false);

	LogTxtBrsr->append(trUtf8("  Проверка точности"));

	qDebug()<<trUtf8("Вошёл в s5"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::s4_entered()
{
	stackedWidget->setCurrentIndex(4);
	
	grad = QPointF(F->df_dx1(BP), F->df_dx2(BP));
	
	if (NumeroIteracio == 1)
		LogTxtBrsr->append(trUtf8("  Введён градиент"));
	else if (NumeroIteracio > 1)
		LogTxtBrsr->append(trUtf8("  S определено успешно"));

	qDebug()<<trUtf8("Вошёл в s4"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::s3_entered()
{
	stackedWidget->setCurrentIndex(1);
	
	LogTxtBrsr->append(trUtf8("  S определено успешно"));

	qDebug()<<trUtf8("Вошёл в s3"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::s2_entered()
{
//	agrad_fx->setChecked(false);

	stackedWidget->setCurrentIndex(0);
	
	LogTxtBrsr->append(trUtf8("  Определяем S"));

	qDebug()<<trUtf8("Вошёл в s2"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::s1_entered()
{
	agrad_fx->setChecked(false);
	gradfx->setChecked(false);
	minf->setChecked(false);
	
	stackedWidget->setCurrentIndex(4);
	
	LogTxtBrsr->append(trUtf8("Начало итерации № %1. Базовая точка: %2; %3.").arg(++NumeroIteracio).arg(BP.x()).arg(BP.y()));

	qDebug()<<trUtf8("Вошёл в s1"); // Вывожу дебажную инфу на консоль.
}

void FasterDescentImpl::so_entered()
{
	qDebug()<<trUtf8("Вошёл в so"); // Вывожу дебажныю инфу на консоль.
}

void FasterDescentImpl::init()
{
	precision_lb->setText(QString::number(strikteco));
	KvantoEraroj = 0;
	NumeroIteracio = 0;
	BP = QPointF(D[4],D[5]);
	quanError = (int)D[6];
	LogTxtBrsr->setText("");

	static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->senspurigi();
	static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->difiniUnuaPointo(BP);

	qDebug()<<trUtf8("Задаю переменным начальные значения"); // Вывожу дебажную инфу на консоль.
}

namespace SinkoFD
{
	bool s1s2Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбран ввод S");
			// Проверяю своё условие.
			return true;
		}
		else
			return false;
	}

	bool s2s3Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбран антиградиент и первая итерация");
			// Проверяю своё условие.
			return aGrad_fx->isChecked() && *numberIterac == 1;
		}
		else
			return false;
	}

	bool s2s4Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбран антиградиент и не первая итерация");
			// Проверяю своё условие.
			return aGrad_fx->isChecked() && *numberIterac > 1;
		}
		else
			return false;
	}

	bool s3s4Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что введен градиент");
			// Проверяю своё условие.
			
			QString tmpX1;
			QString tmpX2;
			
			if(f->metaObject()->className() == QString("KvadratigantoFunkcio"))
			{
				tmpX1 = QString("%1*(x1-%2)+%3*(x2-%4)").arg(2*f->getA()).arg(f->getB()).arg(f->getE()).arg(f->getG()); 
				tmpX2 = QString("%1*(x2-%2)+%3*(x1-%4)").arg(2*f->getC()).arg(f->getD()).arg(f->getE()).arg(f->getF());
			}
			else if(f->metaObject()->className() == QString("RavinaFunkcio"))
			{
				tmpX1 = QString("%1*(x2*x1-x1^3)+%2*(1-x1)").arg(-4*f->getA()).arg(2*f->getB());
				tmpX2 = QString("%1*(x2-x1^2)").arg(f->getA());
			}

			if(df_dx1->text() != tmpX1)
			{
//				QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Не правильно введена производная df/dx1"));
				return false;
			}
			else if(df_dx2->text() != tmpX2)
			{
//				QMessageBox::information(this, trUtf8("Ошибка"), trUtf8("Не правильно введена производная df/dx2"));
				return false;
			}
			else
				return true;
		}
		else
			return false;
	}

	bool s4s5Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбрана проверка градиента");
			// Проверяю своё условие.
			return true;
		}
		else
			return false;
	}

	bool s5s6Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбрана длина градиент для проверки точности");
			// Проверяю своё условие.
			return Gradfx->isChecked();
		}
		else
			return false;
	}

	bool s6s7Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю |grad f(X)| >= e");
			// Проверяю своё условие.
			return Length(*Grad) >= s;
		}
		else
			return false;
	}

	bool s6sfTransiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю |grad f(X)| < e");
			// Проверяю своё условие.
			return Length(*Grad) < s;
		}
		else
			return false;
	}

	bool s7s8Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбрана a = min f(X + a*S)");
			// Проверяю своё условие.
			return minF->isChecked();
		}
		else
			return false;
	}

	bool s8s9Transiro::eventTest(QEvent *e)
	{
		// Реализация по умолчанию проверяет, что сигнал пришёл от связанной кнопки.
		if(QSignalTransition::eventTest(e))
		{
			qDebug()<<trUtf8("  Проверяю, что выбран сделать шаг");
			// Проверяю своё условие.
			return true;
		}
		else
			return false;
	}

};

void FasterDescentImpl::on_difiniFonto_act_activated()
{
	bool b;
	QFont fnt = QFontDialog::getFont(&b, font());
	if(b){
		// Была нажата кнопка ОК.
		setFont(fnt);
	}
}

void FasterDescentImpl::on_helpo_action_activated()
{
	HelpBrowser *hb = new HelpBrowser( "doc/", "method3.htm", this);
	hb->resize(800, 600);
	hb->show();
}
//
