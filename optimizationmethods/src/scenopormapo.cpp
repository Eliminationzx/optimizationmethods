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

#include <QMessageBox>
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
// // Нахожу вектор из минимальной в максимальную точку, "нарезаю" на равные куски
// // и каждый уровень крашу своим оттенком.
// 	qreal h, s, v;
// 	koloro.getHsvF(&h, &s, &v);
// 	QRect r(rect.toRect());// Округляю до целых
// //==Вычисляю вектор из минимальной в максимальную точку.=======================
// 	QPointF minP(F->minPoint(0.1)[0], F->minPoint(0.1)[1]);
// //--Ищу точку приближенную к максимальной в области карты.---------------------
// 	double max = F->rezulto(ampleksoMapo, ampleksoMapo);
// 	QPointF maxP = QPointF(ampleksoMapo, ampleksoMapo);
// 	if (F->rezulto(ampleksoMapo, -ampleksoMapo) > max){
// 		max = F->rezulto(ampleksoMapo, -ampleksoMapo);
// 		maxP = QPointF(ampleksoMapo, -ampleksoMapo);
// 	}
// 	if (F->rezulto(-ampleksoMapo, ampleksoMapo) > max){
// 		max = F->rezulto(-ampleksoMapo, ampleksoMapo);
// 		maxP = QPointF(-ampleksoMapo, ampleksoMapo);
// 	}
// 	if (F->rezulto(-ampleksoMapo, -ampleksoMapo) > max){
// 		max = F->rezulto(-ampleksoMapo, -ampleksoMapo);
// 		maxP = QPointF(-ampleksoMapo, -ampleksoMapo);
// 	}
// 	if (F->rezulto(0, ampleksoMapo) > max){
// 		max = F->rezulto(0, ampleksoMapo);
// 		maxP = QPointF(0, ampleksoMapo);
// 	}
// 	if (F->rezulto(0, -ampleksoMapo) > max){
// 		max = F->rezulto(0, -ampleksoMapo);
// 		maxP = QPointF(0, -ampleksoMapo);
// 	}
// 	if (F->rezulto(ampleksoMapo, 0) > max){
// 		max = F->rezulto(ampleksoMapo, 0);
// 		maxP = QPointF(ampleksoMapo, 0);
// 	}
// 	if (F->rezulto(-ampleksoMapo, 0) > max){
// 		max = F->rezulto(-ampleksoMapo, 0);
// 		maxP = QPointF(-ampleksoMapo, 0);
// 	}
// //-----------------------------------------------------------------------------
// 	QPointF p = maxP - minP;
// //=============================================================================
//
// 	qreal limoj[10];
// 	limoj[0] = F->rezulto(minP + p * l);
// 	limoj[1] = F->rezulto(minP + p * l * 2);
// 	limoj[2] = F->rezulto(minP + p * l * 3);
// 	limoj[3] = F->rezulto(minP + p * l * 4);
// 	limoj[4] = F->rezulto(minP + p * l * 5);
// 	limoj[5] = F->rezulto(minP + p * l * 6);
// 	limoj[6] = F->rezulto(minP + p * l * 7);
// 	limoj[7] = F->rezulto(minP + p * l * 8);
// 	limoj[8] = F->rezulto(minP + p * l * 9);
// 	limoj[9] = F->rezulto(minP + p * l * 10);
// 	// Перебираю видимую область и каждую точку заполняю цветом в соответствии
// 	// со значением целевой функции. Беру область с запасом на 1, иначе на краях
// 	// могут возникать непрорисованные линии
// 	for(int i = r.x()-1; i <= r.right()+1; ++i){
// 		for(int j = r.y()-1; j <= r.bottom()+1; ++j){
// 			qreal f = F->rezulto(i / skalo, j / skalo);
// 			// Ради скорости использую взаимоисключающие ветви вместо перебора в
// 			// цикле.
// 			if(f < limoj[0]) v = l;
// 			else if(f < limoj[1]) v = l * 2;
// 			else if(f < limoj[2]) v = l * 3;
// 			else if(f < limoj[3]) v = l * 4;
// 			else if(f < limoj[4]) v = l * 5;
// 			else if(f < limoj[5]) v = l * 6;
// 			else if(f < limoj[6]) v = l * 7;
// 			else if(f < limoj[7]) v = l * 8;
// 			else if(f < limoj[8]) v = l * 9;
// 			else if(f < limoj[9]) v = l * 10;
// 			else v = 1;
// 			koloro.setHsvF(h, s, v);
// 			painter->setPen(koloro);
// 			painter->drawPoint(i, j);
// 		}
// 	}
}


void ScenoPorMapo::setScale(qreal factor ){
	skalo = factor;
	this->setSceneRect(-ampleksoMapo*factor, -ampleksoMapo*factor,
	                   ampleksoMapo*2*factor, ampleksoMapo*2*factor);
	update(-ampleksoMapo*factor, -ampleksoMapo*factor,
	       ampleksoMapo*2*factor, ampleksoMapo*2*factor);
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