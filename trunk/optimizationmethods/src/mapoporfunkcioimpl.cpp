#include "mapoporfunkcioimpl.h"
#include "funkcio.h"
#include "scenopormapo.h"
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

	grphVw->setMatrix(QMatrix(1, 0, 0, -1, 0, 0));
	
	s->setSceneRect(-ampleksoMapo, -ampleksoMapo, ampleksoMapo*2, ampleksoMapo*2);
	grphVw->setScene(s);
	Spuro = new spuro();
	connect(s, SIGNAL(MusaPosX(const qreal)), SIGNAL(MusaPosX(const qreal)));
	connect(s, SIGNAL(MusaPosY(const qreal)), SIGNAL(MusaPosY(const qreal)));
	connect(s, SIGNAL(MusaPos(const QString &)), SIGNAL(MusaPos(const QString &)));
}
MapoPorFunkcioImpl::MapoPorFunkcioImpl( QWidget * parent, Qt::WFlags f){
	MapoPorFunkcioImpl(new KvadratigantoFunkcio(0,0,0,0,0,0,0,parent), parent, f);
}
//


void MapoPorFunkcioImpl::on_PligrandigiBtn_clicked(){
	s->setScale((s->scale() * 1.1));
	Spuro->setScale((s->scale() * 1.1));
}

void MapoPorFunkcioImpl::on_MalpliigiBtn_clicked(){
	s->setScale((s->scale() * 0.9));
	Spuro->setScale((s->scale() * 0.9));
}


void MapoPorFunkcioImpl::difiniFunkcio(funkcio * f){
	F = f;
}

const spuro * MapoPorFunkcioImpl::proviziSpuro() const{
	return Spuro;
}


void MapoPorFunkcioImpl::setScale(qreal factor){
	// Перед изменением масштаба сцены, установлю его для следа.
	// В ScenoPorMapo::setScale изменить масштаб "следа" не возможно из-за
	// проблем с приведением типа.
	Spuro->setScale(factor);
	s->setScale(factor);
}


qreal MapoPorFunkcioImpl::Scale() const {
	return s->scale();
}


void MapoPorFunkcioImpl::difiniSpuro(spuro * S){
	s->removeItem(Spuro);
	delete Spuro;
	Spuro = S;
	Spuro->setScale(s->scale());
	s->addItem(Spuro);
}


void MapoPorFunkcioImpl::difiniFonaKoloro(QColor k){
	s->difiniKoloro(k);
}


QColor MapoPorFunkcioImpl::fonaKoloro() const {
	return s->Koloro();
}