#include "spurosinkolauxkoordinatoj.h"
#include "Konstantoj.h"
#include <qwt_plot_curve.h>
#include <QPolygonF>
//
spuroSinkoLauxKoordinatoj::spuroSinkoLauxKoordinatoj(QColor momentaKoloro, QColor bazaKoloro) 
	: spuro( bazaKoloro), MomentaKoloro(momentaKoloro){}
//

void spuroSinkoLauxKoordinatoj::finisxiIteracio(){
}

//void spuroSinkoLauxKoordinatoj::reveniAlMomentoPointo(){
//	MomentaPointoj.append(MomentaPointo);
//	update();// Планирую перерисовку.
//}

void spuroSinkoLauxKoordinatoj::aldoniSercxantaPointo(QPointF p){
}

void spuroSinkoLauxKoordinatoj::difiniUnuaPointo(QPointF p){
}

void spuroSinkoLauxKoordinatoj::difiniUnuaPointo( qreal x, qreal y ){
	difiniUnuaPointo(QPointF(x, y));
}

void spuroSinkoLauxKoordinatoj::difiniMomentaKoloro(QColor c){
	MomentaKoloro = c;
}


void spuroSinkoLauxKoordinatoj::difiniMomentaPointo(QPointF p){
}


void spuroSinkoLauxKoordinatoj::senspurigi(){
}