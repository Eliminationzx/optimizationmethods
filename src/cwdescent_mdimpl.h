#ifndef CWDESCENT_MDIMPL_H
#define CWDESCENT_MDIMPL_H
//
#include <QMainWindow>
#include "ui_CWdescent_md.h"
//
class CWdescent_mdImpl : public QMainWindow, public Ui::CWdescent_md
{
Q_OBJECT
public:
	CWdescent_mdImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:
};
#endif





