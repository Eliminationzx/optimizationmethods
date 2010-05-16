#ifndef FASTERDESCENTIMPL_H
#define FASTERDESCENTIMPL_H
//
#include <QMainWindow>
#include "ui_FasterDescent.h"
//
class FasterDescentImpl : public QMainWindow, public Ui::FasterDescent
{
Q_OBJECT
public:
	FasterDescentImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:
};
#endif





