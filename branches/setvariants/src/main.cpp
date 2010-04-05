#include <QApplication>
#include <QLabel>
#include "mainwindowimpl.h"
//
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	MainWindowImpl win;

//	QString str = "hr";
//	double s = str.toDouble();
//	QLabel lbl(QString::number(s));
//	lbl.show();
	win.show();

	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
