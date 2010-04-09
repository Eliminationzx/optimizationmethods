#ifndef CWDESCENTWINIMPL_H
#define CWDESCENTWINIMPL_H
//
#include <QMainWindow>
#include "ui_CWdescent_fixwindow.h"
//
class CWdescentWinImpl : public QMainWindow, public Ui::CWdescentWin
{
Q_OBJECT
public:
	CWdescentWinImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:
};
#endif





