#ifndef LICENSEDLGIMPL_H
#define LICENSEDLGIMPL_H
//
#include <QDialog>
#include "ui_license.h"
//
class LicenseDlgImpl : public QDialog, public Ui::LicenseDlg
{
Q_OBJECT
public:
	LicenseDlgImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:
};
#endif





