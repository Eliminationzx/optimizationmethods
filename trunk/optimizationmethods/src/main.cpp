#include <QApplication>
#include "mainwindowimpl.h"

#include "demonstrataqpointf.h"
#include "funkcio.h"
#include "signalantoporpointf.h"
//
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	MainWindowImpl win;
	win.show();
	
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
