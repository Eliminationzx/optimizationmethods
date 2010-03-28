#include <QApplication>
#include "dialogimpl.h"
#include "funkcio.h"
#include <QLabel>
#include <QString>
//
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	QLabel win;
  KvadratigantoFunkcio f( 1, 0, 1, 0, 0, 0, 0, &win);
  win.setText(QString::number(f.rezulto(f.minPoint(0.05))));
  win.show(); 
  app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
  return app.exec();
}
