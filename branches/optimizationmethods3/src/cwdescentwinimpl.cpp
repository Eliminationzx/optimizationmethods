#include "cwdescentwinimpl.h"
#include "mapoporfunkcioimpl.h"
#include "Konstantoj.h"
#include "funkcio.h"
#include "spuro.h"
#include "spurosinkolauxkoordinatoj.h"
#include "demonstrataqpointf.h"
#include <QString>
#include <QMessageBox>
//
CWdescentWinImpl::CWdescentWinImpl( funkcio *f, QVector<double> *d, QWidget * parent, Qt::WFlags flags) 
	: AlgoritmoWin(f, d, parent, flags), MomentaPointo((*d)[4],(*d)[5]),
    NovaPointo(MomentaPointo), PasxoX1((*d)[1], 0), PasxoX2(0, (*d)[2]),
    NumeroIteracio(0), FlagEtapo(PasxiDekstren), KonsideradoPointo(false),
    KvantoEraroj(0) {
	setupUi(this);
  
  // Создаю карту.
  // centralwidget->layout() - указатель на компановщик центрального виджета
  // static_cast<QGridLayout*>(centralwidget->layout()) - обьясняю компилятору, что это именно QGridLayout
  // добавляю вижет карты в позицию 1,1. Компановщик сам позаботится о назначении новому виджету родителя.
  static_cast<QGridLayout*>(centralwidget->layout())->addWidget(MapoWdg, 1, 1);
  
  MapoWdg->kreiSpuro(A::CWdescent_fix, Qt::blue);
  Sp = MapoWdg->proviziSpuro();
  
  // Присоединяю точки к надписям для отображения их значения.
  if(connect( &MomentaPointo, SIGNAL(proviziXValoro(const QString & )),
              x1_lb, SLOT(setText(const QString & )) ));else{
    QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Не удалось соединить &MomentaPointo, SIGNAL(proviziXValoro(const QString & )), x1_lb, SLOT(setText(const QString & ))"));
    msg.exec();
  }
  if(connect( &MomentaPointo, SIGNAL(proviziYValoro(const QString & )),
              x2_lb, SLOT(setText(const QString & )) )); else{
    QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Не удалось соединить &MomentaPointo, SIGNAL(proviziYValoro(const QString & )), x2_lb, SLOT(setText(const QString & ))"));
    msg.exec();
  }
  if(connect( &NovaPointo, SIGNAL(proviziXValoro(const QString & )),
              new_x1_lb, SLOT(setText(const QString & )) )); else{
    QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Не удалось соединить &NovaPointo, SIGNAL(proviziXValoro(const QString & )), new_x1_lb, SLOT(setText(const QString & ))"));
    msg.exec();
  }
  if(connect( &NovaPointo, SIGNAL(proviziYValoro(const QString & )),
              new_x2_lb, SLOT(setText(const QString & )) )); else{
    QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Не удалось соединить &NovaPointo, SIGNAL(proviziYValoro(const QString & )), new_x2_lb, SLOT(setText(const QString & ))"));
    msg.exec();
  }
  if(connect( &PasxoX1, SIGNAL(proviziXValoro(const QString & )),
              x1_step_lb, SLOT(setText(const QString & )) )); else{
    QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Не удалось соединить &PasxoX1, SIGNAL(proviziXValoro(const QString & )), x1_step_lb, SLOT(setText(const QString & ))"));
    msg.exec();
  }
  if(connect( &PasxoX2, SIGNAL(proviziYValoro(const QString & )),
              x2_step_lb, SLOT(setText(const QString & )) ));else{
    QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Не удалось соединить &PasxoX2, SIGNAL(proviziYValoro(const QString & )), x2_step_lb, SLOT(setText(const QString & ))"));
    msg.exec();
  }
  if(connect( &NovaPointo, SIGNAL(proviziValoro(QPointF)),
              Sp, SLOT(aldoniSercxantaPointo(QPointF)) ));else{
    QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Не удалось соединить &NovaPointo, SIGNAL(proviziValoro(QPointF)), Sp, SLOT(aldoniSercxantaPointo(QPointF))"));
    msg.exec();
  }
  
  //Вывожу значения.
  precision_lb->setText(QString::number((*d)[0]));
  MomentaPointo *= 1;
  NovaPointo *= 1;
  PasxoX1 *= 1;
  PasxoX2 *= 1;
  fsign_lb->setText(QString::number(F->rezulto(MomentaPointo)));
  new_fsign_lb->setText(QString::number(F->rezulto(NovaPointo)));
  
  
  
/*//=========Пример======================================================================================Дальше прога что-то кастует.)
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
//======================================================================================================Вунш пунш*/
}
//


//Пользователь делает шаг вдоль оси.
void CWdescentWinImpl::on_calculate_bt_clicked()
{
  //Проверяю соответствие состояния этапа алгоритма и действия пользователя.
  //Перевожу этап в следующее состояние в соответствии с алгоритмом.
  if(FlagEtapo == PasxiDekstren && up_x1_rb->isChecked()){
    //Ожидается шаг в + по Х1 и выбран шаг в + по Х1.
    NovaPointo = MomentaPointo + PasxoX1;
    KonsideradoPointo = true; // Начинаю ждать принятия точки.
  }else if(FlagEtapo == PasxiMaldekstren && down_x1_rb->isChecked()){
    //Ожидается шаг в - по Х1 и выбран шаг в - по Х1.
    NovaPointo = MomentaPointo - PasxoX1;
    KonsideradoPointo = true; // Начинаю ждать принятия точки.
  }else if(FlagEtapo == PasxiSupren && up_x2_rb->isChecked()){
    //Ожидается шаг в + по Х2 и выбран шаг в + по Х2.
    NovaPointo = MomentaPointo + PasxoX2;
    KonsideradoPointo = true; // Начинаю ждать принятия точки.
  }else if(FlagEtapo == PasxiMalsupren && down_x2_rb->isChecked()){
    //Ожидается шаг в - по Х2 и выбран шаг в - по Х2.
    NovaPointo = MomentaPointo - PasxoX2;
    KonsideradoPointo = true; // Начинаю ждать принятия точки.
  }else{
    // Ползователь ошибся.
    registriEraro();
  }
  
  
  new_fsign_lb->setText(QString::number(F->rezulto(NovaPointo)));
}

//Пользователь принимает точку.
void CWdescentWinImpl::on_accept_bt_clicked()
{
  //Проверяю соответствие состояния этапа алгоритма и действия пользователя.
  //Перевожу этап в следующее состояние в соответствии с алгоритмом.
  if(KonsideradoPointo){
    //Ожидается принятие точки.
    MomentaPointo = NovaPointo;
    //Итерация закончилась.
    ++NumeroIteracio;
    static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->finisxiIteracio();
    KonsideradoPointo = false; // Заканчиваю ждать принятия точки.
  }else{
    // Ползователь ошибся.
    registriEraro();
  }
}

//Пользователь не принимает точку.
void CWdescentWinImpl::on_not_accept_bt_clicked(){
  //Проверяю соответствие состояния этапа алгоритма и действия пользователя.
  //Перевожу этап в следующее состояние в соответствии с алгоритмом.
  if(KonsideradoPointo){
    //Ожидается принятие точки.
    MomentaPointo = NovaPointo;
    //Итерация закончилась.
    ++NumeroIteracio;
    static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->finisxiIteracio();
    KonsideradoPointo = false; // Заканчиваю ждать принятия точки.
  }else{
    // Ползователь ошибся.
    registriEraro();
  }
}

void CWdescentWinImpl::on_end_bt_clicked(){
  // TODO
}

void CWdescentWinImpl::on_change_step_bt_clicked(){
  // TODO
}


void CWdescentWinImpl::registriEraro(){
  ++KvantoEraroj;
  LogLstWd->addItem(trUtf8("Совершена ошибка. Общее количество ошибок: %1").arg(KvantoEraroj));
  QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Неправильное действие"));
  msg.exec();  
}