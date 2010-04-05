#include <QApplication>
#include <QLabel>
#include "mainwindowimpl.h"
//
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	MainWindowImpl win;

//	QVector<double> str;
//	str = win.AnalysisDirVariants(0);
//	QLabel lbl(QString::number(str[0]));
//	lbl.show();
	win.show();

	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
