#include "spurosinkolauxkoordinatoj_md.h"
#include "Konstantoj.h"
#include <QPolygonF>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <QColor>
//
spuroSinkoLauxKoordinatoj_md::spuroSinkoLauxKoordinatoj_md(QColor bazaKoloro, qreal Skalo, QGraphicsItem * parent) 
	: spuro( A::CWdescent_md, bazaKoloro, Skalo, parent), MomentaKoloro(Qt::white){}
//

QRectF spuroSinkoLauxKoordinatoj_md::boundingRect() const{
	// Размер элемента - обьединённый размер "хвоста" и текущей итерации * на
	// масштаб + поправка, чтоб не остался старый "указатель"
	QRectF rez = MomentaPointoj.boundingRect() | Vosto.boundingRect();
//	rez.setTopLeft(rez.topLeft() * skalo - QPointF(2, 2));
//	rez.setBottomRight(rez.bottomRight() * skalo + QPointF(2, 2));
	return rez;
}

void spuroSinkoLauxKoordinatoj_md::finisxiIteracio(){
//	Vosto += MomentaPointoj;
//	MomentaPointoj.clear();
//	MomentaPointoj.append(MomentaPointo);
//	update();// Планирую перерисовку.
}


void spuroSinkoLauxKoordinatoj_md::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widge*/){
//	painter->save();
	
//	painter->setPen(BazaKoloro);
//	painter->drawPolyline(aplikiScalo(Vosto));
//	painter->setPen(MomentaKoloro);
//	painter->drawPolyline(aplikiScalo(MomentaPointoj));
//	painter->setPen(BazaKoloro);
//	painter->drawEllipse(MomentaPointoj.last() * skalo, 2, 2);
	
//	painter->restore();
}

void spuroSinkoLauxKoordinatoj_md::difiniUnuaPointo(const QPointF & p){
//	MomentaPointo = p;
//	MomentaPointoj.append(p);
//	// Центрирую карту на последней точке.
//	this->scene()->views()[0]->centerOn(p * skalo);
//	update();// Планирую перерисовку.
}

void spuroSinkoLauxKoordinatoj_md::difiniUnuaPointo( qreal x, qreal y ){
//	difiniUnuaPointo(QPointF(x, y));
}


void spuroSinkoLauxKoordinatoj_md::difiniBazaKoloro(QColor c){
//	BazaKoloro = c;
}


void spuroSinkoLauxKoordinatoj_md::difiniMomentaKoloro(QColor c){
//	MomentaKoloro = c;
}


void spuroSinkoLauxKoordinatoj_md::senspurigi(){
//	prepareGeometryChange ();
//	MomentaPointoj.clear();
//	Vosto.clear();
}


void spuroSinkoLauxKoordinatoj_md::aldoniPointo(const QPointF & p){
//	MomentaPointo = p;
//	MomentaPointoj.append(p);
//	// Прокручиваю карту, чтобы не скрывать последнюю точку.
//	this->scene()->views()[0]->ensureVisible(p.x() * skalo, p.y() * skalo, 1, 1);
//	update();
}