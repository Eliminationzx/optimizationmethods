#include <QApplication>
#include "mainwindowimpl.h"

#include "demonstrataqpointf.h"
#include "funkcio.h"
#include "signalantoporpointf.h"
//

void provoDemonstrataQPointF(){
	KvadratigantoFunkcio f ;
	QPoint p(5,7);
	QPointF pf(8,4);
	DemonstrataQPointF dp;
	DemonstrataQPointF dp1(p);
	DemonstrataQPointF dp2(pf);
	DemonstrataQPointF dp3(3,6);
	
	SignalantoPorPointF sp(&dp3, &f);
	
	DemonstrataQPointF dp4(dp3);
	QPointF pf2(dp3);

	dp = dp2 *= 5;
	pf = dp2 *= 5;

	dp = dp2 /= 5;
	pf = dp2 /= 5;

	dp = dp2 += dp;
	dp = dp2 += p;
	dp = dp2 += pf;
	pf = dp2 += dp;
	pf = dp2 += p;
	pf = dp2 += pf;

	dp = dp2 -= dp;
	dp = dp2 -= p;
	dp = dp2 -= pf;
	pf = dp2 -= dp;
	pf = dp2 -= p;
	pf = dp2 -= pf;

	dp = dp2 * 5;
	pf = dp2 * 5;

	dp = dp2 / 5;
	pf = dp2 / 5;

	dp = dp2 + dp;
	dp = dp2 + p;
	dp = dp2 + pf;
	pf = dp2 + dp;
	pf = dp2 + p;
	pf = dp2 + pf;

	dp = dp2 - dp;
	dp = dp2 - p;
	dp = dp2 - pf;
	pf = dp2 - dp;
	pf = dp2 - p;
	pf = dp2 - pf;
}

//
int main(int argc, char ** argv)
{
//	QApplication app( argc, argv );
//	MainWindowImpl win;
//	win.show();
	
	provoDemonstrataQPointF();
	
//	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
//	return app.exec();
}
