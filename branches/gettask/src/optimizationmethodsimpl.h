#ifndef OPTIMIZATIONMETHODSTIMPL_H
#define OPTIMIZATIONMETHODSTIMPL_H
//
#include <QStackedWidget>
#include "ui_optimizationmethods.h"
//
class optimizationmethodsImpl : public QStackedWidget, public Ui::Main
{
Q_OBJECT
public:

	optimizationmethodsImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:
};
#endif





