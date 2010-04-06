#include <QApplication>
#include "mainwindowimpl.h"
#include "getvariantsImpl.h"
//
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	MainWindowImpl win;
	QVector<int> data(2);
	data[0] = 0;
	data[1] = 1;
	getvariantsImpl getV(data);
	getV.show();
//	win.show(); 
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
