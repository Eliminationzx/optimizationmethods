#include "scenopormapo.h"
#include "funkcio.h"
#include "spuro.h"
#include "Konstantoj.h"
#include <QColor>
#include <QPainter>
#include <QRect>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QImage>

#include <QMessageBox>
//
ScenoPorMapo::ScenoPorMapo( const funkcio * Funkcio, QObject * parent)
	: QGraphicsScene(parent), F(Funkcio), skalo(1), koloro(Qt::red){}
ScenoPorMapo::ScenoPorMapo( const funkcio * Funkcio, const QRectF & sceneRect, QObject * parent)
	: QGraphicsScene(sceneRect, parent), F(Funkcio), skalo(1), koloro(Qt::red){}
ScenoPorMapo::ScenoPorMapo( const funkcio * Funkcio, qreal x, qreal y, qreal width, qreal height, QObject * parent)
	: QGraphicsScene(x, y, width, height, parent), F(Funkcio), skalo(1),
		koloro(Qt::red){}
ScenoPorMapo::~ScenoPorMapo(){
	delete m;
}
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
	limoj<<F->rezulto(minP + p * l)<<F->rezulto(minP + p * l * 2)
	     <<F->rezulto(minP + p * l * 3)<<F->rezulto(minP + p * l * 4)
	     <<F->rezulto(minP + p * l * 5)<<F->rezulto(minP + p * l * 6)
	     <<F->rezulto(minP + p * l * 7)<<F->rezulto(minP + p * l * 8)
	     <<F->rezulto(minP + p * l * 9)<<F->rezulto(minP + p * l * 10)
	     <<F->rezulto(minP + p * l * 11)<<F->rezulto(minP + p * l * 12)
	     <<F->rezulto(minP + p * l * 13)<<F->rezulto(minP + p * l * 14)
	     <<F->rezulto(minP + p * l * 15)<<F->rezulto(minP + p * l * 16)
	     <<F->rezulto(minP + p * l * 17)<<F->rezulto(minP + p * l * 18)
	     <<F->rezulto(minP + p * l * 19)<<F->rezulto(minP + p * l * 20)
	     <<F->rezulto(minP + p * l * 21)<<F->rezulto(minP + p * l * 22)
	     <<F->rezulto(minP + p * l * 23)<<F->rezulto(minP + p * l * 24)
	     <<F->rezulto(minP + p * l * 25)<<F->rezulto(p * l * 26)
	     <<F->rezulto(minP + p * l * 27)<<F->rezulto(minP + p * l * 28)
	     <<F->rezulto(minP + p * l * 29)<<F->rezulto(minP + p * l * 30)
	     <<F->rezulto(minP + p * l * 31)<<F->rezulto(minP + p * l * 32)
	     <<F->rezulto(minP + p * l * 33)<<F->rezulto(minP + p * l * 34)
	     <<F->rezulto(minP + p * l * 35)<<F->rezulto(minP + p * l * 36)
	     <<F->rezulto(minP + p * l * 37)<<F->rezulto(minP + p * l * 38)
	     <<F->rezulto(minP + p * l * 39)<<F->rezulto(minP + p * l * 40);
	// Перебираю видимую область и каждую точку заполняю цветом в соответствии
	// со значением целевой функции. Беру область с запасом на 1, иначе на краях
	// могут возникать непрорисованные линии
	for(int i = r.x()-1; i <= r.right()+1; ++i){
		for(int j = r.y()-1; j <= r.bottom()+1; ++j){
			qreal f = F->rezulto(i / skalo, j / skalo);
			// Ради скорости использую взаимоисключающие ветви вместо перебора в
			// цикле.
			if(f < limoj[0]) v = l;
			else if(f < limoj[1]) v = l * 2;
			else if(f < limoj[2]) v = l * 3;
			else if(f < limoj[3]) v = l * 4;
			else if(f < limoj[4]) v = l * 5;
			else if(f < limoj[5]) v = l * 6;
			else if(f < limoj[6]) v = l * 7;
			else if(f < limoj[7]) v = l * 8;
			else if(f < limoj[8]) v = l * 9;
			else if(f < limoj[9]) v = l * 10;
			else if(f < limoj[10]) v = l * 11;
			else if(f < limoj[11]) v = l * 12;
			else if(f < limoj[12]) v = l * 13;
			else if(f < limoj[13]) v = l * 14;
			else if(f < limoj[14]) v = l * 15;
			else if(f < limoj[15]) v = l * 16;
			else if(f < limoj[16]) v = l * 17;
			else if(f < limoj[17]) v = l * 18;
			else if(f < limoj[18]) v = l * 19;
			else if(f < limoj[19]) v = l * 20;
			else if(f < limoj[20]) v = l * 21;
			else if(f < limoj[21]) v = l * 22;
			else if(f < limoj[22]) v = l * 23;
			else if(f < limoj[23]) v = l * 24;
			else if(f < limoj[24]) v = l * 25;
			else if(f < limoj[25]) v = l * 26;
			else if(f < limoj[26]) v = l * 27;
			else if(f < limoj[27]) v = l * 28;
			else if(f < limoj[28]) v = l * 29;
			else if(f < limoj[29]) v = l * 30;
			else if(f < limoj[30]) v = l * 31;
			else if(f < limoj[31]) v = l * 32;
			else if(f < limoj[32]) v = l * 33;
			else if(f < limoj[33]) v = l * 34;
			else if(f < limoj[34]) v = l * 35;
			else if(f < limoj[35]) v = l * 36;
			else if(f < limoj[36]) v = l * 37;
			else if(f < limoj[37]) v = l * 38;
			else if(f < limoj[38]) v = l * 39;
			else if(f < limoj[39]) v = l * 40;
			else v = 1;
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


void ScenoPorMapo::difiniKoloro(QColor & k){
	koloro = k;
}


void ScenoPorMapo::desegniMapo(){
	QRect r(sceneRect().toRect());// Округляю до целых
	m = new QImage(r.size(), QImage::Format_ARGB32_Premultiplied);
	QPainter painter(m);
// Нахожу вектор из минимальной в максимальную точку, "нарезаю" на равные куски
// и каждый уровень крашу своим оттенком. 
	qreal h, s, v;
	koloro.getHsvF(&h, &s, &v);
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
	limoj<<F->rezulto(minP + p * l)<<F->rezulto(minP + p * l * 2)
	     <<F->rezulto(minP + p * l * 3)<<F->rezulto(minP + p * l * 4)
	     <<F->rezulto(minP + p * l * 5)<<F->rezulto(minP + p * l * 6)
	     <<F->rezulto(minP + p * l * 7)<<F->rezulto(minP + p * l * 8)
	     <<F->rezulto(minP + p * l * 9)<<F->rezulto(minP + p * l * 10)
	     <<F->rezulto(minP + p * l * 11)<<F->rezulto(minP + p * l * 12)
	     <<F->rezulto(minP + p * l * 13)<<F->rezulto(minP + p * l * 14)
	     <<F->rezulto(minP + p * l * 15)<<F->rezulto(minP + p * l * 16)
	     <<F->rezulto(minP + p * l * 17)<<F->rezulto(minP + p * l * 18)
	     <<F->rezulto(minP + p * l * 19)<<F->rezulto(minP + p * l * 20)
	     <<F->rezulto(minP + p * l * 21)<<F->rezulto(minP + p * l * 22)
	     <<F->rezulto(minP + p * l * 23)<<F->rezulto(minP + p * l * 24)
	     <<F->rezulto(minP + p * l * 25)<<F->rezulto(p * l * 26)
	     <<F->rezulto(minP + p * l * 27)<<F->rezulto(minP + p * l * 28)
	     <<F->rezulto(minP + p * l * 29)<<F->rezulto(minP + p * l * 30)
	     <<F->rezulto(minP + p * l * 31)<<F->rezulto(minP + p * l * 32)
	     <<F->rezulto(minP + p * l * 33)<<F->rezulto(minP + p * l * 34)
	     <<F->rezulto(minP + p * l * 35)<<F->rezulto(minP + p * l * 36)
	     <<F->rezulto(minP + p * l * 37)<<F->rezulto(minP + p * l * 38)
	     <<F->rezulto(minP + p * l * 39)<<F->rezulto(minP + p * l * 40);
	// Перебираю видимую область и каждую точку заполняю цветом в соответствии
	// со значением целевой функции. Беру область с запасом на 1, иначе на краях
	// могут возникать непрорисованные линии
	for(int i = r.x()-1; i <= r.right()+1; ++i){
		for(int j = r.y()-1; j <= r.bottom()+1; ++j){
			qreal f = F->rezulto(i / skalo, j / skalo);
			// Ради скорости использую взаимоисключающие ветви вместо перебора в
			// цикле.
			if(f < limoj[0]) v = l;
			else if(f < limoj[1]) v = l * 2;
			else if(f < limoj[2]) v = l * 3;
			else if(f < limoj[3]) v = l * 4;
			else if(f < limoj[4]) v = l * 5;
			else if(f < limoj[5]) v = l * 6;
			else if(f < limoj[6]) v = l * 7;
			else if(f < limoj[7]) v = l * 8;
			else if(f < limoj[8]) v = l * 9;
			else if(f < limoj[9]) v = l * 10;
			else if(f < limoj[10]) v = l * 11;
			else if(f < limoj[11]) v = l * 12;
			else if(f < limoj[12]) v = l * 13;
			else if(f < limoj[13]) v = l * 14;
			else if(f < limoj[14]) v = l * 15;
			else if(f < limoj[15]) v = l * 16;
			else if(f < limoj[16]) v = l * 17;
			else if(f < limoj[17]) v = l * 18;
			else if(f < limoj[18]) v = l * 19;
			else if(f < limoj[19]) v = l * 20;
			else if(f < limoj[20]) v = l * 21;
			else if(f < limoj[21]) v = l * 22;
			else if(f < limoj[22]) v = l * 23;
			else if(f < limoj[23]) v = l * 24;
			else if(f < limoj[24]) v = l * 25;
			else if(f < limoj[25]) v = l * 26;
			else if(f < limoj[26]) v = l * 27;
			else if(f < limoj[27]) v = l * 28;
			else if(f < limoj[28]) v = l * 29;
			else if(f < limoj[29]) v = l * 30;
			else if(f < limoj[30]) v = l * 31;
			else if(f < limoj[31]) v = l * 32;
			else if(f < limoj[32]) v = l * 33;
			else if(f < limoj[33]) v = l * 34;
			else if(f < limoj[34]) v = l * 35;
			else if(f < limoj[35]) v = l * 36;
			else if(f < limoj[36]) v = l * 37;
			else if(f < limoj[37]) v = l * 38;
			else if(f < limoj[38]) v = l * 39;
			else if(f < limoj[39]) v = l * 40;
			else v = 1;
			koloro.setHsvF(h, s, v);
			painter.setPen(koloro);
			painter.drawPoint(i, j);
		}
	}	
}