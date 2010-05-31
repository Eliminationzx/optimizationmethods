#include "hugiimpl.h"
#include <QFontDialog>
//
HuGiImpl::HuGiImpl( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{
	setupUi(this);
	connect(exit, SIGNAL(activated()), qApp, SLOT(closeAllWindows()));

}
//


void HuGiImpl::on_difiniFonto_act_activated(){
	bool b;
	QFont fnt = QFontDialog::getFont(&b, font());
	if(b){
		// Была нажата кнопка ОК.
		setFont(fnt);
	}
}

