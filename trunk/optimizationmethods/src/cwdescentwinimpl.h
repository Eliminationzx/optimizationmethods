#ifndef CWDESCENTWINIMPL_H
#define CWDESCENTWINIMPL_H
//
#include "algoritmowin.h"
#include "ui_CWdescent_fixwindow.h"
//
//! Окно для прохождения Покоординатного спуска с фиксированным шагом.
/*!
 * @author Александр Белоконь, Василий Почкаенко.
 * @file cwdescentwinimpl.h
 */
class CWdescentWinImpl : public AlgoritmoWin, public Ui::CWdescentWin
{
Q_OBJECT
public:
	CWdescentWinImpl( funkcio *f, QVector<double> *d, QWidget * parent = 0, Qt::WFlags flags = 0 );
private slots:
};
#endif





