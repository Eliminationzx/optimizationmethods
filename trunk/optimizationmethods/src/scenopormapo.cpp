#include "scenopormapo.h"
#include <QRect>
#include "funkcio.h"
#include <QColor>
#include <QPainter>
#include "spuro.h"
#include "Konstantoj.h"
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
	// со значением целевой функции. Беру область с запасом на 1, иначе на краях
	// могут возникать непрорисованные линии
	for(int i = r.x()-1; i <= r.right()+1; ++i){
		for(int j = r.y()-1; j <= r.bottom()+1; ++j){
			v = ((int)(((F->rezulto(i / skalo, j / skalo)-min)/1000)/0.025))*0.025;
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
	using namespace std;
	update(-ampleksoMapo, -ampleksoMapo, ampleksoMapo*2, ampleksoMapo*2);
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