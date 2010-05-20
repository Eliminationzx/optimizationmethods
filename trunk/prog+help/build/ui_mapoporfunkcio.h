/********************************************************************************
** Form generated from reading UI file 'mapoporfunkcio.ui'
**
** Created: Fri 21. May 00:17:23 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPOPORFUNKCIO_H
#define UI_MAPOPORFUNKCIO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapoPorFunkcio
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *grphVw;
    QPushButton *PligrandigiBtn;
    QPushButton *MalpliigiBtn;

    void setupUi(QWidget *MapoPorFunkcio)
    {
        if (MapoPorFunkcio->objectName().isEmpty())
            MapoPorFunkcio->setObjectName(QString::fromUtf8("MapoPorFunkcio"));
        MapoPorFunkcio->resize(575, 392);
        gridLayout = new QGridLayout(MapoPorFunkcio);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        grphVw = new QGraphicsView(MapoPorFunkcio);
        grphVw->setObjectName(QString::fromUtf8("grphVw"));
        grphVw->viewport()->setProperty("cursor", QVariant(QCursor(Qt::OpenHandCursor)));
        grphVw->setDragMode(QGraphicsView::ScrollHandDrag);

        gridLayout->addWidget(grphVw, 0, 0, 1, 2);

        PligrandigiBtn = new QPushButton(MapoPorFunkcio);
        PligrandigiBtn->setObjectName(QString::fromUtf8("PligrandigiBtn"));

        gridLayout->addWidget(PligrandigiBtn, 1, 0, 1, 1);

        MalpliigiBtn = new QPushButton(MapoPorFunkcio);
        MalpliigiBtn->setObjectName(QString::fromUtf8("MalpliigiBtn"));

        gridLayout->addWidget(MalpliigiBtn, 1, 1, 1, 1);


        retranslateUi(MapoPorFunkcio);

        QMetaObject::connectSlotsByName(MapoPorFunkcio);
    } // setupUi

    void retranslateUi(QWidget *MapoPorFunkcio)
    {
        MapoPorFunkcio->setWindowTitle(QApplication::translate("MapoPorFunkcio", "\320\243\321\200\320\276\320\262\320\275\320\270 \321\206\320\265\320\273\320\265\320\262\320\276\320\271 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
        PligrandigiBtn->setText(QApplication::translate("MapoPorFunkcio", "+", 0, QApplication::UnicodeUTF8));
        MalpliigiBtn->setText(QApplication::translate("MapoPorFunkcio", "-", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MapoPorFunkcio: public Ui_MapoPorFunkcio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPOPORFUNKCIO_H
