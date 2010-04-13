#include <QApplication>
#include "mainwindowimpl.h"
#include "optimizationmethodsimpl.h"
//
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	optimizationmethodsImpl win;
	win.show(); 
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
