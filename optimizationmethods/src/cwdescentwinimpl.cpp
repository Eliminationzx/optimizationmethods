#include "cwdescentwinimpl.h"
#include "mapoporfunkcioimpl.h"
#include "Konstantoj.h"
#include "spuro.h"
#include "spurosinkolauxkoordinatoj.h"
//
CWdescentWinImpl::CWdescentWinImpl( funkcio *f, QVector<double> *d, QWidget * parent, Qt::WFlags flags) 
	: AlgoritmoWin(f, d, parent, flags), MomentaPointo((*d)[4],(*d)[5]),
    NovaPointo(MomentaPointo), PasxoX1((*d)[1], 0), PasxoX2(0, (*d)[2]),
    NumeroIteracio(0), FlagEtapo(PasxiDekstren){
	setupUi(this);
  
  // Создаю карту.
  // centralwidget->layout() - указатель на компановщик центрального виджета
  // static_cast<QGridLayout*>(centralwidget->layout()) - обьясняю компилятору, что это именно QGridLayout
  // добавляю вижет карты в позицию 1,1. Компановщик сам позаботится о назначении новому виджету родителя.
  static_cast<QGridLayout*>(centralwidget->layout())->addWidget(MapoWdg, 1, 1);
  
  // Присоединяю точки к надписям для отображения их значения.
  connect( &MomentaPointo, SIGNAL(proviziXValoro(QString & )), x1_lb, SLOT(setText(const QString & ))); 
  connect( &MomentaPointo, SIGNAL(proviziYValoro(QString & )), x2_lb, SLOT(setText(const QString & ))); 
  connect( &NovaPointo, SIGNAL(proviziXValoro(QString & )), new_x1_lb, SLOT(setText(const QString & ))); 
  connect( &NovaPointo, SIGNAL(proviziYValoro(QString & )), new_x2_lb, SLOT(setText(const QString & ))); 
  connect( &PasxoX1, SIGNAL(proviziXValoro(QString & )), x1_step_lb, SLOT(setText(const QString & ))); 
  connect( &PasxoX2, SIGNAL(proviziYValoro(QString & )), x2_step_lb, SLOT(setText(const QString & )));
  
  MapoWdg->kreiSpuro(A::CWdescent_fix, Qt::blue);
  Sp = MapoWdg->proviziSpuro();
/*//=========Пример==============================================================
  //------Итерация 1-----------------------------------------------------------
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->difiniUnuaPointo(QPoint(0, 0));
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10, 0));
  //spuroSinkoLauxKoordinatoj не проверяет логику.
  //Он соединяет подрят все переданные ему точки.
  //В следующей строке совершена ошибка с точки зрения алгоритма.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(20, 10));
  //! Завершаю итерацию.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->finisxiIteracio();
  
  //------Итерация 2-----------------------------------------------------------
  //! Далее буду следовать алгоритму Покоординатного спуска.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(20+10, 10));
  //Пусть значение в новой точке неменьше чем в базовой.
  //Вернусь назад.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(20-10, 10));  
  //Пусть значение в новой точке меньше чем в базовой.
  //Ура, завершаю итерацию.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->finisxiIteracio();
  //------Итерация 3-----------------------------------------------------------
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10+5, 10));  
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10-5, 10));  
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10, 10+5));  
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10, 10-5));  
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  //Надо уменьшить шаг и прейти к следующей итерации.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->finisxiIteracio();
  //------Итерация 4-----------------------------------------------------------
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10+2.5, 10));  
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10-2.5, 10));  
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10, 10+2.5));  
  //Пусть значение в новой точке меньше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->finisxiIteracio();
  //------Итерация 5-----------------------------------------------------------
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10+1.25, 12.5));  
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10-1.25, 12.5));  
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10, 12.5+1.25));  
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(QPoint(10, 12.5-1.25));  
  //Пусть значение в новой точке неменьше чем в базовой.
  static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
  //Надо уменьшить шаг.
  //Пусть новый шаг меньше заданой тосности.
  //!!!!!!Ура, нашли минимум!!!!!!!!!!!!!!!!
//=============================================================================
*/
}
//

