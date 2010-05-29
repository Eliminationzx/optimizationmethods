#ifndef _HelpBrowser_h_
#define _HelpBrowser_h_

#include <QtGui>

// ======================================================================
class HelpBrowser : public QDialog {
	Q_OBJECT

public:
	HelpBrowser(const QString& strPath, 
				const QString& strFileName, 
				QWidget* pwgt = 0)
				 : QDialog(pwgt) 
	{
		QTextBrowser* ptxtBrowser = new QTextBrowser;

		ptxtBrowser->setSearchPaths(QStringList() << strPath);
		ptxtBrowser->setSource(QString(strFileName));
		
		//Layout setup
		QVBoxLayout* pvbxLayout = new QVBoxLayout;
		QHBoxLayout* phbxLayout = new QHBoxLayout;
		pvbxLayout->addLayout(phbxLayout);    
		pvbxLayout->addWidget(ptxtBrowser);
		setLayout(pvbxLayout);
	}
};

#endif  //_HelpBrowser_h_
