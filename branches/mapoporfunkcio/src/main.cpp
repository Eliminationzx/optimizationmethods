#include <QApplication>
//#include "mainwindowimpl.h"
#include "mapoporfunkcioimpl.h"
#include "funkcio.h"
//
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	MapoPorFunkcioImpl win(new KvadratigantoFunkcio(1, 0, 1, 0, 0, 0, 0, &app));
	win.show(); 
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
