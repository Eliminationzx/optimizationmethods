#ifndef NEMIIMPL_H
#define NEMIIMPL_H
//
#include <QMainWindow>
#include "ui_NeMi.h"
#include "demonstrataqpointf.h"
#include <QSignalTransition>
#include <QState>
//
class NeMiImpl : public QMainWindow, public Ui::NeMi
{
Q_OBJECT
protected:
	//! Первая точка основного триугольника.
	DemonstrataQPointF P1;
	//! Вторая точка основного триугольника.
	DemonstrataQPointF P2;
	//! Третья точка основного триугольника.
	DemonstrataQPointF P3;
public:
	NeMiImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:
	
};
#endif





