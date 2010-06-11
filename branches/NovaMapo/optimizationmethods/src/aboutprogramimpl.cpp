#include "aboutprogramimpl.h"
#include "licenzodlgimpl.h"
//
aboutProgramImpl::aboutProgramImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f){
	setupUi(this);
}
//


void aboutProgramImpl::on_label_4_linkActivated(QString link){
	LicenzoDlgImpl * l = new LicenzoDlgImpl(this);
	l->resize(900, 600);
	l->exec();
}


