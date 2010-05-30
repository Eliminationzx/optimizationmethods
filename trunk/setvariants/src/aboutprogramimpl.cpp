#include "aboutprogramimpl.h"
#include "licensedlgimpl.h"
//
aboutProgramImpl::aboutProgramImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
}
//

void aboutProgramImpl::on_label_4_linkActivated(QString link)
{
	LicenseDlgImpl * l = new LicenseDlgImpl(this);
	l->resize(900, 600);
	l->exec();
}
