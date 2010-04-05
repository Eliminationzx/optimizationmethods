#include <QApplication>
#include <QLabel>
#include "mainwindowimpl.h"
//
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	MainWindowImpl win;

	QVector<QString> data(13);
//	data = win.ReadVariants(0,0);
//	QLabel lbl(data[0]);
//	lbl.show();
	win.show();

	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
