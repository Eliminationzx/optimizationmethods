#ifndef ABOUTPROGRAMIMPL_H
#define ABOUTPROGRAMIMPL_H
//
#include <QDialog>
#include "ui_aboutProgram.h"
//
class aboutProgramImpl : public QDialog, public Ui::aboutProgram
{
Q_OBJECT

public:
	aboutProgramImpl( QWidget * parent = 0, Qt::WFlags f = 0 );

private slots:
	void on_Ok_clicked();
};
#endif






