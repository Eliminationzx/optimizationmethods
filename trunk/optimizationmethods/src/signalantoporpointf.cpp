#include "signalantoporpointf.h"
#include "demonstrataqpointf.h"
#include "funkcio.h"
//
SignalantoPorPointF::SignalantoPorPointF( DemonstrataQPointF * P, funkcio * F, QObject * parent )
	: QObject(parent), p(P), f(F){
	p->difiniSignalantoPorPointF(this);
};
//

void SignalantoPorPointF::SendiSignaloj(){
  if(p != 0){
		emit proviziValoro(*p);
	  emit proviziValoro(trUtf8("%1; %2").arg(QString::number(p->x(), 'f')).arg(QString::number(p->y(), 'f')));
	  emit proviziXValoro(p->toPoint().x());
	  emit proviziXValoro(p->x());
	  emit proviziXValoro(QString::number(p->x(), 'f', 2));
	  emit proviziYValoro(p->y());
	  emit proviziYValoro(p->y());
	  emit proviziYValoro(QString::number(p->y(), 'f', 2));
	  if(f != 0){
		  emit proviziValoroFukcioEnPointo(f->rezulto(*p));
		  emit proviziValoroFukcioEnPointo(QString::number(f->rezulto(*p), 'f', 3));
	  }
  }
}
