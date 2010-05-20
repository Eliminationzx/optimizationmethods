#ifndef NEMIIMPL_H
#define NEMIIMPL_H
//
#include <QMainWindow>
#include "ui_NeMi.h"
//
class NeMiImpl : public QMainWindow, public Ui::NeMi
{
Q_OBJECT
public:
	NeMiImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:
};
#endif





