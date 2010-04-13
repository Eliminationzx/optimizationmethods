#include "algoritmowin.h"
#include "funkcio.h"
#include "mapoporfunkcioimpl.h"
//
AlgoritmoWin::AlgoritmoWin( funkcio *f, QVector<double> *d, QWidget * parent, Qt::WindowFlags flags ) 
	: QMainWindow(parent, flags), F(f), D(d), MapoWdg(new MapoPorFunkcioImpl(f, this)) {}
//
