#include "algoritmowin.h"
#include "funkcio.h"
//
AlgoritmoWin::AlgoritmoWin( funkcio *f, QVector<double> *d, QWidget * parent, Qt::WindowFlags flags ) 
	: QMainWindow(parent, flags), F(f), D(d){}
//
