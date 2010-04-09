#ifndef DEMONSTRATAQPOINTF_H
#define DEMONSTRATAQPOINTF_H
//
#include <QPointF>
#include <QObject>
//
//! Расширение QPointF, дла автоматического отображения его значений в окне.
class DemonstrataQPointF : public QObject, public QPointF
{
Q_OBJECT
public:
	DemonstrataQPointF(qreal x, qreal y);
	
};
#endif
