#include "spurosinkolauxkoordinatoj.h"
#include "Konstantoj.h"
#include <QPolygonF>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
//
spuroSinkoLauxKoordinatoj::spuroSinkoLauxKoordinatoj(QColor momentaKoloro, QColor bazaKoloro, qreal Skalo, QGraphicsItem * parent) 
	: spuro( A::CWdescent_fix, bazaKoloro, Skalo, parent), MomentaKoloro(momentaKoloro){}
//

QRectF spuroSinkoLauxKoordinatoj::boundingRect() const{
	// Размер элемента - обьединённый размер "хвоста" и текущей итерации * на
	// масштаб + поправка, чтоб не остался старый "указатель"
	QRectF rez = MomentaPointoj.boundingRect() | Vosto.boundingRect();
//	rez.setTopLeft(rez.topLeft() * skalo - QPointF(2, 2));
//	rez.setBottomRight(rez.bottomRight() * skalo + QPointF(2, 2));
	return rez;
}

void spuroSinkoLauxKoordinatoj::finisxiIteracio(){
//	MomentaPointo = MomentaPointoj.back();
//	Vosto += MomentaPointoj;
//	MomentaPointoj.clear();
//	MomentaPointoj.append(MomentaPointo);
//	update();// Планирую перерисовку.
}

void spuroSinkoLauxKoordinatoj::reveniAlMomentoPointo(){
	MomentaPointoj.append(MomentaPointo);
	update();// Планирую перерисовку.
}

void spuroSinkoLauxKoordinatoj::aldoniSercxantaPointo(QPointF p){
//	MomentaPointoj.append(p);
//	// Прокручиваю карту, чтобы не скрывать последнюю точку.
//	this->scene()->views()[0]->ensureVisible(p.x() * skalo, p.y() * skalo, 1, 1);
//	update();// Планирую перерисовку.
}
void spuroSinkoLauxKoordinatoj::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widge*/){
//	painter->save();
	
//	painter->setPen(BazaKoloro);
//	painter->drawPolyline(aplikiScalo(Vosto));
//	painter->setPen(MomentaKoloro);
//	painter->drawPolyline(aplikiScalo(MomentaPointoj));
//	painter->setPen(BazaKoloro);
//	painter->drawEllipse(MomentaPointoj.last() * skalo, 2, 2);
	
//	painter->restore();
}

void spuroSinkoLauxKoordinatoj::difiniUnuaPointo(QPointF p){
//	MomentaPointo = p;
//	MomentaPointoj.append(p);
//	// Центрирую карту на последней точке.
//	this->scene()->views()[0]->centerOn(p * skalo);
//	update();// Планирую перерисовку.
}

void spuroSinkoLauxKoordinatoj::difiniUnuaPointo( qreal x, qreal y ){
//	difiniUnuaPointo(QPointF(x, y));
}


void spuroSinkoLauxKoordinatoj::difiniBazaKoloro(QColor c){
//	BazaKoloro = c;
}


void spuroSinkoLauxKoordinatoj::difiniMomentaKoloro(QColor c){
//	MomentaKoloro = c;
}


void spuroSinkoLauxKoordinatoj::difiniMomentaPointo(QPointF p){
//	MomentaPointo = p;
}


void spuroSinkoLauxKoordinatoj::senspurigi(){
//	prepareGeometryChange ();
//	MomentaPointoj.clear();
//	Vosto.clear();
}