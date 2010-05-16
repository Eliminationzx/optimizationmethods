#ifndef NOTWENIMPL_H
#define NOTWENIMPL_H
//
#include <QMainWindow>
#include "ui_NotWen.h"
//
class NotWenImpl : public QMainWindow, public Ui::NotWen
{
Q_OBJECT
public:
	NotWenImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:
};
#endif





