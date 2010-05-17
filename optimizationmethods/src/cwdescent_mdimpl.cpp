#include "cwdescent_mdimpl.h"
#include "mapoporfunkcioimpl.h"
#include "Konstantoj.h"
#include "funkcio.h"
#include "spuro.h"
#include "spurosinkolauxkoordinatoj.h"
#include "demonstrataqpointf.h"
#include "signalantoporpointf.h"
#include "math.h"
#include <QTextBrowser>
#include <QString>
#include <QMessageBox>
#include <QStateMachine>
#include <QFinalState>
#include <QLabel>
#include <QDebug>
//
//using namespace SinkoLauxKoordinatoj2;

CWdescent_mdImpl::CWdescent_mdImpl(funkcio *f, QVector<double> *d, QWidget * parent, Qt::WFlags flags) 
	: AlgoritmoWin(f, d, parent, flags)
{
	setupUi(this);
	
	qDebug()<<trUtf8("Покоординатный спуск с минимизацией по направлению"); // Вывожу дебажныю инфу на консоль.

	// Создаю карту.
	// centralwidget->layout() - указатель на компановщик центрального виджета
	// static_cast<QGridLayout*>(centralwidget->layout()) - обьясняю компилятору, что это именно QGridLayout
	// добавляю вижет карты в позицию 1,1. Компановщик сам позаботится о назначении новому виджету родителя.
	static_cast<QGridLayout*>(centralwidget->layout())->addWidget(MapoWdg, 1, 1, 2, 1);

	MapoWdg->setScale(6);// Ставлю масштаб побольше. Надо будет определться с оптимальным значением.
}
//

