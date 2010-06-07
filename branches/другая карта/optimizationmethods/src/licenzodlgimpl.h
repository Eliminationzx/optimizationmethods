#ifndef LICENZODLGIMPL_H
#define LICENZODLGIMPL_H
//
#include <QDialog>
#include "ui_licenzo.h"
//
class LicenzoDlgImpl : public QDialog, public Ui::LicenzoDlg
{
Q_OBJECT
public:
	LicenzoDlgImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:
};
#endif





