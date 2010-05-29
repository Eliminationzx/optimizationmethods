#include "aboutprogramimpl.h"
//
aboutProgramImpl::aboutProgramImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
}
//


void aboutProgramImpl::on_Ok_clicked()
{
	// TODO
	this->close();
}

