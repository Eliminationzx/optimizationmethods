#ifndef HELPBROWSERIMPL_H
#define HELPBROWSERIMPL_H
//
#include <QDialog>
#include "ui_helpBrowser.h"
//
class helpBrowserImpl : public QDialog, public Ui::helpBrowser
{
Q_OBJECT

public:
	helpBrowserImpl(const QString& strPath,
					const QString& strFileName,
					QWidget * parent = 0,
					Qt::WFlags f = 0 );

private slots:
};
#endif





