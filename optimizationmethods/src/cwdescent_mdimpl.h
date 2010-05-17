#ifndef CWDESCENT_MDIMPL_H
#define CWDESCENT_MDIMPL_H
//
#include <QMainWindow>
#include "ui_CWdescent_md.h"
#include "algoritmowin.h"
#include "demonstrataqpointf.h"
#include <QSignalTransition>
#include <QState>
#include <QRadioButton>
//
class funkcio;
//
//! Окно для прохождения Покоординатного спуска с минимизацией по направлению.
class CWdescent_mdImpl : public AlgoritmoWin, public Ui::CWdescent_md
{
Q_OBJECT

public:
	CWdescent_mdImpl( funkcio *f, //!< Указатель на целевую функцию. CWdescent_mdImpl не заботится о назначении Funkcio родителя.
                    QVector<double> *d, //!< Массив с данными задания.
                    QWidget * parent = 0, //!< Родитель.
                    Qt::WFlags flags = 0 //!< Флаги параметров окна.
                  );

};
#endif

