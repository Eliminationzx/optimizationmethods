#include "spurosinkolauxkoordinatoj_md.h"
#include "Konstantoj.h"
#include <qwt_plot_curve.h>
#include <QPolygonF>
//
spuroSinkoLauxKoordinatoj_md::spuroSinkoLauxKoordinatoj_md(QColor momentaKoloro, QColor bazaKoloro) 
	: spuro(bazaKoloro), MomentaKoloro(momentaKoloro){}
//

void spuroSinkoLauxKoordinatoj_md::difiniUnuaPointo(const QPointF & p){
}

void spuroSinkoLauxKoordinatoj_md::difiniUnuaPointo( qreal x, qreal y ){
	difiniUnuaPointo(QPointF(x, y));
}

void spuroSinkoLauxKoordinatoj_md::difiniMomentaKoloro(QColor c){
	MomentaKoloro = c;
}

void spuroSinkoLauxKoordinatoj_md::senspurigi(){
}

void spuroSinkoLauxKoordinatoj_md::aldoniPointo(const QPointF & p){
}