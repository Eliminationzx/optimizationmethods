#include "cwdescentwinimpl.h"
#include "mapoporfunkcioimpl.h"
#include "Konstantoj.h"
#include "funkcio.h"
#include "spuro.h"
#include "spurosinkolauxkoordinatoj.h"
#include "demonstrataqpointf.h"
#include "math.h"
#include <QTextBrowser>
#include <QString>
#include <QMessageBox>
//
CWdescentWinImpl::CWdescentWinImpl( funkcio *f, QVector<double> *d, QWidget * parent, Qt::WFlags flags) 
	: AlgoritmoWin(f, d, parent, flags), MomentaPointo((*d)[4],(*d)[5]),
    NovaPointo(MomentaPointo), PasxoX1((*d)[1], 0), PasxoX2(0, (*d)[2]),
    NumeroIteracio(0), FlagEtapo(1), KvantoEraroj(0), strikteco((*d)[0]){
	setupUi(this);
  
  // Создаю карту.
  // centralwidget->layout() - указатель на компановщик центрального виджета
  // static_cast<QGridLayout*>(centralwidget->layout()) - обьясняю компилятору, что это именно QGridLayout
  // добавляю вижет карты в позицию 1,1. Компановщик сам позаботится о назначении новому виджету родителя.
  static_cast<QGridLayout*>(centralwidget->layout())->addWidget(MapoWdg, 1, 1);
  
  MapoWdg->kreiSpuro(A::CWdescent_fix, Qt::blue);
  Sp = MapoWdg->proviziSpuro();
  
  //Вывожу значения.
  precision_lb->setText(QString::number((*d)[0]));
  x1_lb->setText(QString::number(MomentaPointo.x()));
  x2_lb->setText(QString::number(MomentaPointo.y()));
//  new_x1_lb->setText(trUtf8("Неопределено"));
//  new_x2_lb->setText(trUtf8("Неопределено"));
  x1_step_lb->setText(QString::number(PasxoX1.x()));
  x2_step_lb->setText(QString::number(PasxoX2.y()));
  fsign_lb->setText(QString::number(F->rezulto(MomentaPointo)));
//  new_fsign_lb->setText(trUtf8("Неопределено"));
  
  
  
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
  if(FlagEtapo == 1 && up_x1_rb->isChecked()){
    // Нажата calculate_bt и выбрана up_x1_rb - соответствует этапу 1.
    NovaPointo = MomentaPointo + PasxoX1;
    new_x1_lb->setText(QString::number(NovaPointo.x()));
    new_x2_lb->setText(QString::number(NovaPointo.y()));
    new_fsign_lb->setText(QString::number(F->rezulto(NovaPointo)));
    static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(NovaPointo);
    FlagEtapo = 2;
  }else if(FlagEtapo == 3 && down_x1_rb->isChecked()){
    // Нажата calculate_bt и выбрана down_x1_rb - соответствует этапу 3.
    NovaPointo = MomentaPointo - PasxoX1;
    new_x1_lb->setText(QString::number(NovaPointo.x()));
    new_x2_lb->setText(QString::number(NovaPointo.y()));
    new_fsign_lb->setText(QString::number(F->rezulto(NovaPointo)));
    static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(NovaPointo);
    FlagEtapo = 4;
  }else if(FlagEtapo == 5 && up_x2_rb->isChecked()){
    // Нажата calculate_bt и выбрана up_x2_rb - соответствует этапу 5.
    NovaPointo = MomentaPointo + PasxoX2;
    new_x1_lb->setText(QString::number(NovaPointo.x()));
    new_x2_lb->setText(QString::number(NovaPointo.y()));
    new_fsign_lb->setText(QString::number(F->rezulto(NovaPointo)));
    static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(NovaPointo);
    FlagEtapo = 6;
  }else if(FlagEtapo == 7 && down_x2_rb->isChecked()){
    // Нажата calculate_bt и выбрана down_x2_rb - соответствует этапу 7.
    NovaPointo = MomentaPointo - PasxoX2;
    new_x1_lb->setText(QString::number(NovaPointo.x()));
    new_x2_lb->setText(QString::number(NovaPointo.y()));
    new_fsign_lb->setText(QString::number(F->rezulto(NovaPointo)));
    static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->aldoniSercxantaPointo(NovaPointo);
    FlagEtapo = 8;
  }else{
    //Пользователь ошибся.
    registriEraro();
  }
  
  
  emit proviziFlagEtapo(FlagEtapo);
}

//Пользователь принимает точку.
void CWdescentWinImpl::on_accept_bt_clicked(){
  if((FlagEtapo == 2 ||
      FlagEtapo == 4 ||
      FlagEtapo == 6 ||
      FlagEtapo == 8)
      // Нажата accept_bt - соответствует 2,4,6 или 8 этапу.
     && F->rezulto(NovaPointo) < F->rezulto(MomentaPointo)
  ){
    // Ожидается приняте точки и пользователь нажал "Принять"
    QPointF AntPnt = MomentaPointo;// Запоминаю предыдущую точку
    MomentaPointo = NovaPointo;// Устанавливаю новую
    x1_lb->setText(QString::number(MomentaPointo.x()));
    x2_lb->setText(QString::number(MomentaPointo.y()));
    distance_lb->setText( QString::number(abs(F->rezulto(MomentaPointo) - F->rezulto(AntPnt))) );
    fsign_lb->setText(QString::number(F->rezulto(MomentaPointo)));
    // Сразу выполняю этап 10 - проверяю условие выхода.
    if(abs(F->rezulto(MomentaPointo) - F->rezulto(AntPnt)) < strikteco){
      FlagEtapo = 11;//Перехожу к ожиданию выхода. 
    }else{
      static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->finisxiIteracio();
      new_x1_lb->setText(trUtf8("Неопределено"));
      new_x2_lb->setText(trUtf8("Неопределено"));
      new_fsign_lb->setText(trUtf8("Неопределено"));
      ++NumeroIteracio;
      FlagEtapo = 1;//Перехожу к новой итерации.
    }
    
  }else{
    //Пользователь ошибся.
    registriEraro();
  }
  
  emit proviziFlagEtapo(FlagEtapo);
}

//Пользователь не принимает точку.
void CWdescentWinImpl::on_not_accept_bt_clicked(){
  bool flag = F->rezulto(NovaPointo) >= F->rezulto(MomentaPointo);
  if(FlagEtapo == 2 && flag){
    new_x1_lb->setText(trUtf8("Неопределено"));
    new_x2_lb->setText(trUtf8("Неопределено"));
    new_fsign_lb->setText(trUtf8("Неопределено"));
    static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
    FlagEtapo = 3;
  }else if(FlagEtapo == 4 && flag){
    new_x1_lb->setText(trUtf8("Неопределено"));
    new_x2_lb->setText(trUtf8("Неопределено"));
    new_fsign_lb->setText(trUtf8("Неопределено"));
    static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
    FlagEtapo = 5;
  }else if(FlagEtapo == 6 && flag){
    new_x1_lb->setText(trUtf8("Неопределено"));
    new_x2_lb->setText(trUtf8("Неопределено"));
    new_fsign_lb->setText(trUtf8("Неопределено"));
    static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
    FlagEtapo = 7;
  }else if(FlagEtapo == 8 && flag){
    new_x1_lb->setText(trUtf8("Неопределено"));
    new_x2_lb->setText(trUtf8("Неопределено"));
    new_fsign_lb->setText(trUtf8("Неопределено"));
    static_cast<spuroSinkoLauxKoordinatoj*>(Sp)->reveniAlMomentoPointo();
    FlagEtapo = 9;
  }else{
    //Пользователь ошибся.
    registriEraro();
  }
  
  emit proviziFlagEtapo(FlagEtapo);
}

void CWdescentWinImpl::on_end_bt_clicked(){
  if(FlagEtapo == 11){
    //Нажата end_bt - соответствует этапу 11.
  }else{
    //Пользователь ошибся.
    registriEraro();
  }
  
  emit proviziFlagEtapo(FlagEtapo);
}

void CWdescentWinImpl::on_change_step_bt_clicked(){
  if(FlagEtapo == 9){
    //Нажата change_step_bt - соответствует этапу 9.
    PasxoX1 *= strikteco;
    PasxoX2 *= strikteco;
    x1_step_lb->setText(QString::number(PasxoX1.x()));
    x2_step_lb->setText(QString::number(PasxoX2.y()));
    FlagEtapo = 1;
  }else{
    //Пользователь ошибся.
    registriEraro();
  }
  
  emit proviziFlagEtapo(FlagEtapo);
}


void CWdescentWinImpl::registriEraro(){
  ++KvantoEraroj;
  LogTxtBrsr->append(trUtf8("Совершена ошибка. Общее количество ошибок: %1").arg(KvantoEraroj));
  QMessageBox msg(QMessageBox::Warning, trUtf8("Ошибка"), trUtf8("Неправильное действие"));
  msg.exec();  
}
