#include <QApplication>
#include "mainwindowimpl.h"

#include "demonstrataqpointf.h"
#include "funkcio.h"
//
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	MainWindowImpl win;
	win.show();
	
	QPointF pf(6,7);
	QPointF p(86,74);
	DemonstrataQPointF dp, dp2(p);
	dp = pf;
	dp = dp2;
	pf = dp;
	KvadratigantoFunkcio f;
	f.rezulto(pf);
	f.rezulto(dp);
	 	
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
