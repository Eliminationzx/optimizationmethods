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
// Нахожу вектор из минимальной в максимальную точку, "нарезаю" на равные куски
// и каждый уровень крашу своим оттенком. 
	qreal h, s, v;
	koloro.getHsvF(&h, &s, &v);
	QRect r(rect.toRect());// Округляю до целых
//==Вычисляю вектор из минимальной в максимальную точку.=======================
	QPointF minP(F->minPoint(0.1)[0], F->minPoint(0.1)[1]);
//--Ищу точку приближенную к максимальной в области карты.---------------------
	double max = F->rezulto(ampleksoMapo, ampleksoMapo);
	QPointF maxP = QPointF(ampleksoMapo, ampleksoMapo);
	if (F->rezulto(ampleksoMapo, -ampleksoMapo) > max){
		max = F->rezulto(ampleksoMapo, -ampleksoMapo);
		maxP = QPointF(ampleksoMapo, -ampleksoMapo);
	}
	if (F->rezulto(-ampleksoMapo, ampleksoMapo) > max){
		max = F->rezulto(-ampleksoMapo, ampleksoMapo);
		maxP = QPointF(-ampleksoMapo, ampleksoMapo);
	}
	if (F->rezulto(-ampleksoMapo, -ampleksoMapo) > max){
		max = F->rezulto(-ampleksoMapo, -ampleksoMapo);
		maxP = QPointF(-ampleksoMapo, -ampleksoMapo);
	}
	if (F->rezulto(0, ampleksoMapo) > max){
		max = F->rezulto(0, ampleksoMapo);
		maxP = QPointF(0, ampleksoMapo);
	}
	if (F->rezulto(0, -ampleksoMapo) > max){
		max = F->rezulto(0, -ampleksoMapo);
		maxP = QPointF(0, -ampleksoMapo);
	}
	if (F->rezulto(ampleksoMapo, 0) > max){
		max = F->rezulto(ampleksoMapo, 0);
		maxP = QPointF(ampleksoMapo, 0);
	}
	if (F->rezulto(-ampleksoMapo, 0) > max){
		max = F->rezulto(-ampleksoMapo, 0);
		maxP = QPointF(-ampleksoMapo, 0);
	}
//-----------------------------------------------------------------------------
	QPointF p = maxP - minP;
//=============================================================================

	QList<qreal> limoj;
	limoj<<F->rezulto(minP + p * 0.025)<<F->rezulto(minP + p * 0.05)
	     <<F->rezulto(minP + p * 0.075)<<F->rezulto(minP + p * 0.1)
	     <<F->rezulto(minP + p * 0.125)<<F->rezulto(minP + p * 0.15)
	     <<F->rezulto(minP + p * 0.175)<<F->rezulto(minP + p * 0.2)
	     <<F->rezulto(minP + p * 0.225)<<F->rezulto(minP + p * 0.25)
	     <<F->rezulto(minP + p * 0.275)<<F->rezulto(minP + p * 0.3)
	     <<F->rezulto(minP + p * 0.325)<<F->rezulto(minP + p * 0.35)
	     <<F->rezulto(minP + p * 0.375)<<F->rezulto(minP + p * 0.4)
	     <<F->rezulto(minP + p * 0.425)<<F->rezulto(minP + p * 0.45)
	     <<F->rezulto(minP + p * 0.475)<<F->rezulto(minP + p * 0.5)
	     <<F->rezulto(minP + p * 0.525)<<F->rezulto(minP + p * 0.55)
	     <<F->rezulto(minP + p * 0.575)<<F->rezulto(minP + p * 0.6)
	     <<F->rezulto(minP + p * 0.625)<<F->rezulto(p * 0.65)
	     <<F->rezulto(minP + p * 0.675)<<F->rezulto(minP + p * 0.7)
	     <<F->rezulto(minP + p * 0.725)<<F->rezulto(minP + p * 0.75)
	     <<F->rezulto(minP + p * 0.775)<<F->rezulto(minP + p * 0.8)
	     <<F->rezulto(minP + p * 0.825)<<F->rezulto(minP + p * 0.85)
	     <<F->rezulto(minP + p * 0.875)<<F->rezulto(minP + p * 0.9)
	     <<F->rezulto(minP + p * 0.925)<<F->rezulto(minP + p * 0.95)
	     <<F->rezulto(minP + p * 0.975)<<F->rezulto(minP + p * 1);
	// Перебираю видимую область и каждую точку заполняю цветом в соответствии
	// со значением целевой функции. Беру область с запасом на 1, иначе на краях
	// могут возникать непрорисованные линии
	for(int i = r.x()-1; i <= r.right()+1; ++i){
		for(int j = r.y()-1; j <= r.bottom()+1; ++j){
			qreal f = F->rezulto(i / skalo, j / skalo);
			// Ради скорости использую взаимоисключающие ветви вместо перебора в
			// цикле.
			if(f < limoj[0]) v = 0;
			else if(f < limoj[1]) v = 0.025;
			else if(f < limoj[2]) v = 0.05;
			else if(f < limoj[3]) v = 0.075;
			else if(f < limoj[4]) v = 0.1;
			else if(f < limoj[5]) v = 0.125;
			else if(f < limoj[6]) v = 0.15;
			else if(f < limoj[7]) v = 0.175;
			else if(f < limoj[8]) v = 0.2;
			else if(f < limoj[9]) v = 0.225;
			else if(f < limoj[10]) v = 0.25;
			else if(f < limoj[11]) v = 0.275;
			else if(f < limoj[12]) v = 0.3;
			else if(f < limoj[13]) v = 0.325;
			else if(f < limoj[14]) v = 0.35;
			else if(f < limoj[15]) v = 0.375;
			else if(f < limoj[16]) v = 0.4;
			else if(f < limoj[17]) v = 0.425;
			else if(f < limoj[18]) v = 0.45;
			else if(f < limoj[19]) v = 0.475;
			else if(f < limoj[20]) v = 0.5;
			else if(f < limoj[21]) v = 0.525;
			else if(f < limoj[22]) v = 0.55;
			else if(f < limoj[23]) v = 0.575;
			else if(f < limoj[24]) v = 0.6;
			else if(f < limoj[25]) v = 0.625;
			else if(f < limoj[26]) v = 0.65;
			else if(f < limoj[27]) v = 0.675;
			else if(f < limoj[28]) v = 0.7;
			else if(f < limoj[29]) v = 0.725;
			else if(f < limoj[30]) v = 0.75;
			else if(f < limoj[31]) v = 0.775;
			else if(f < limoj[32]) v = 0.8;
			else if(f < limoj[33]) v = 0.825;
			else if(f < limoj[34]) v = 0.85;
			else if(f < limoj[35]) v = 0.875;
			else if(f < limoj[36]) v = 0.9;
			else if(f < limoj[37]) v = 0.925;
			else if(f < limoj[38]) v = 0.95;
			else if(f < limoj[39]) v = 0.975;
			koloro.setHsvF(h, s, v);
			painter->setPen(koloro);
			painter->drawPoint(i, j);
		}
	}
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