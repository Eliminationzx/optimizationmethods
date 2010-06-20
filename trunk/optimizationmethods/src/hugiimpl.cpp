#include "hugiimpl.h"
#include <QRadioButton>
//
HuGiImpl::HuGiImpl( funkcio *f, QVector<double> d, QWidget * parent, Qt::WFlags flags ) 
	: AlgoritmoWin(f, d, parent, flags){
	setupUi(this);
}
//

