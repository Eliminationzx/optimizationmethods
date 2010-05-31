#ifndef HUGIIMPL_H
#define HUGIIMPL_H
//
#include <QMainWindow>
#include "ui_HuGi.h"
//
class HuGiImpl : public QMainWindow, public Ui::HuGi
{
Q_OBJECT
public:
	HuGiImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:
	void on_difiniFonto_act_activated();
};
#endif






