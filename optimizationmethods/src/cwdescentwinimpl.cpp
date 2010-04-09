#include "cwdescentwinimpl.h"
//
CWdescentWinImpl::CWdescentWinImpl( funkcio *f, QVector<double> *d, QWidget * parent, Qt::WFlags flags) 
	: AlgoritmoWin(f, d, parent, flags){
	setupUi(this);
}
//

