#include <QApplication>
#include "mainwindowimpl.h"
#include "mapoporfunkcioimpl.h"
//
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	MapoPorFunkcioImpl win;
	win.show(); 
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
