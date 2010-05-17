#include "mapoporfunkcioimpl.h"
#include "funkcio.h"
//#include <QGraphicsItem>
#include "scenopormapo.h"
#include <limits>
#include <QGraphicsScene>
#include "spurosinkolauxkoordinatoj.h"
#include <QColor>
#include <QString>
#include <QMessageBox>
//
MapoPorFunkcioImpl::MapoPorFunkcioImpl( const funkcio * Funkcio, QWidget * parent, Qt::WFlags f) 
	: QWidget(parent, f), F(Funkcio){
  setupUi(this);
  s = new ScenoPorMapo(F, parent);
//  QMessageBox msg(QMessageBox::Information, trUtf8("Границы области"), QString::number(numeric_limits<int>::min()) + " " + QString::number(numeric_limits<int>::max()));
//  msg.exec();
  s->setSceneRect(-numeric_limits<int>::max()/2, -numeric_limits<int>::max()/2,
                  numeric_limits<int>::max(), numeric_limits<int>::max());
  grphVw->setScene(s);
}
MapoPorFunkcioImpl::MapoPorFunkcioImpl( QWidget * parent, Qt::WFlags f){
  MapoPorFunkcioImpl(new KvadratigantoFunkcio(0,0,0,0,0,0,0,parent), parent, f);
}
//


void MapoPorFunkcioImpl::on_PligrandigiBtn_clicked(){
  s->setScale((s->scale() * 1.1));
}

void MapoPorFunkcioImpl::on_MalpliigiBtn_clicked(){
  s->setScale((s->scale() * 0.9));
}


void MapoPorFunkcioImpl::difiniFunkcio(funkcio * f){
  F = f;
}

void MapoPorFunkcioImpl::kreiSpuro(int IdAlgoritmo, QColor bazaKoloro){
	// Создаю "след" в соответствии с указаным алгоритмом.
	switch(IdAlgoritmo){
		case A::CWdescent_fix : {
			Spuro = new spuroSinkoLauxKoordinatoj(Qt::white, bazaKoloro);
			break;
		}case A::CWdescent_md : {
			break;
		}case A::FasterDescent : {
			break;
		}case A::HuGi : {
			break;
		}case A::NeMi : {
			break;
		}case A::NotWen : {
			break;
		}
	}
	Spuro->setScale(s->scale());// Назначаю корректный масштаб вновь созданному "следу".
	s->addItem(Spuro);
}

const spuro * MapoPorFunkcioImpl::proviziSpuro() const{
  return Spuro;
}


void MapoPorFunkcioImpl::setScale(qreal factor){
	// Перед изменением масштаба сцены, установлю его для следа.
	// В ScenoPorMapo::setScale изменить масштаб "следа" не возможно из-зи
	// проблем с приведением типа.
	Spuro->setScale(factor);
	s->setScale(factor);
}


qreal MapoPorFunkcioImpl::Scale() const {
	return s->scale();
}