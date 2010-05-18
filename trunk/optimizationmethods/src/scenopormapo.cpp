#include "scenopormapo.h"
#include <QRect>
#include "funkcio.h"
#include <QColor>
#include <QPainter>
#include "spuro.h"
#include <limits>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
//
ScenoPorMapo::ScenoPorMapo( const funkcio * Funkcio, QObject * parent)
	: QGraphicsScene(parent), F(Funkcio), skalo(1), koloro(Qt::red){}
ScenoPorMapo::ScenoPorMapo( const funkcio * Funkcio, const QRectF & sceneRect, QObject * parent)
	: QGraphicsScene(sceneRect, parent), F(Funkcio), skalo(1), koloro(Qt::red){}
ScenoPorMapo::ScenoPorMapo( const funkcio * Funkcio, qreal x, qreal y, qreal width, qreal height, QObject * parent)
	: QGraphicsScene(x, y, width, height, parent), F(Funkcio), skalo(1),
		koloro(Qt::red){}
//


void ScenoPorMapo::drawBackground(QPainter * painter, const QRectF & rect){
//  painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
	qreal h, s, v;
	koloro.getHsvF(&h, &s, &v);
	QRect r(rect.toRect());
	double min = F->rezulto(F->minPoint(0.1));
	// Перебираю видимую область и каждую точку заполняю цветом в соответствии
	// со значением целевой функции.
	for(int i = r.x(); i <= r.right(); ++i){
		for(int j = r.y(); j <= r.bottom(); ++j){
			v = (F->rezulto(i / skalo, j / skalo)-min)/1000;
			if(v > 1){
				v = 1;
			}else if(v < 0){
				v = 0;
			}
			koloro.setHsvF(h, s, v);
			painter->setPen(koloro);
			painter->drawPoint(i, j);
		}
	}
}


void ScenoPorMapo::setScale(qreal factor ){
	skalo = factor;
	// Для следа изменить масштаб не удасться из-за приведения типов. Есменяю
	// его масштаб в MapoPorFunkcioImpl.
//	//Устанавливаю масштаб для "следа".
//	for(int i = 0; i < items().count(); ++i){//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		
//	}
//	if(items().count() > 0){
//	  ((spuro*)(items()[0]))->setScale(factor);
//	}  
	using namespace std;
	update(-numeric_limits<int>::max()/2, -numeric_limits<int>::max()/2,
	       numeric_limits<int>::max(), numeric_limits<int>::max());
}


qreal ScenoPorMapo::scale() const{
	return skalo;
}



void ScenoPorMapo::mouseMoveEvent(QGraphicsSceneMouseEvent * mE)
{
	qDebug()<<trUtf8("%1; %2").arg(mE->pos().x()).arg(mE->pos().y());
	emit MusaPos(trUtf8("%1; %2").arg(mE->pos().x()).arg(mE->pos().y()));
	QGraphicsScene::mouseMoveEvent ( mE );// Вызываю реализацию по умолчанию.
}


void ScenoPorMapo::difiniKoloro(QColor & k){
	koloro = k;
}