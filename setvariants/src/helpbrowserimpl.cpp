#include "helpbrowserimpl.h"
//
helpBrowserImpl::helpBrowserImpl(const QString& strPath, const QString& strFileName, QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);

	textBrowser->setSearchPaths(QStringList() << strPath);
	textBrowser->setSource(QString(strFileName));
}
//

