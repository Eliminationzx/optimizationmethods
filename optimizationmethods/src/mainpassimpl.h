#ifndef MAINPASSIMPL_H
#define MAINPASSIMPL_H
//
#include <QDialog>
#include "ui_mainwindowPass.h"
//
class mainPassImpl : public QDialog, public Ui::mainPass
{
Q_OBJECT

public:
	mainPassImpl( QWidget * parent = 0, Qt::WFlags f = 0 );

private slots:
};
#endif





