#include "cwdescentwinimpl.h"
#include "mapoporfunkcioimpl.h"
//
CWdescentWinImpl::CWdescentWinImpl( funkcio *f, QVector<double> *d, QWidget * parent, Qt::WFlags flags) 
	: AlgoritmoWin(f, d, parent, flags), MomentaPointo((*d)[4],(*d)[5]),
    NovaPointo(MomentaPointo), PasxoX1((*d)[1], 0), PasxoX2(0, (*d)[2]){
	setupUi(this);
  
  // Создаю карту.
  // centralwidget->layout() - указатель на компановщик центрального виджета
  // static_cast<QGridLayout*>(centralwidget->layout()) - обьясняю компилятору, что это именно QGridLayout
  // добавляю вижет карты в позицию 1,1. Компановщик сам позаботится о назначении новому виджету родителя.
  static_cast<QGridLayout*>(centralwidget->layout())->addWidget(new MapoPorFunkcioImpl(F), 1, 1);
  
  // Присоединяю точки к надписям для отображения их значения.
  connect( &MomentaPointo, SIGNAL(proviziXValoro(QString & )), x1_lb, SLOT(setText(const QString & ))); 
  connect( &MomentaPointo, SIGNAL(proviziYValoro(QString & )), x2_lb, SLOT(setText(const QString & ))); 
  connect( &NovaPointo, SIGNAL(proviziXValoro(QString & )), new_x1_lb, SLOT(setText(const QString & ))); 
  connect( &NovaPointo, SIGNAL(proviziYValoro(QString & )), new_x2_lb, SLOT(setText(const QString & ))); 
  connect( &PasxoX1, SIGNAL(proviziXValoro(QString & )), x1_step_lb, SLOT(setText(const QString & ))); 
  connect( &PasxoX2, SIGNAL(proviziYValoro(QString & )), x2_step_lb, SLOT(setText(const QString & ))); 
}
//

