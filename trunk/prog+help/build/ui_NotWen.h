/********************************************************************************
** Form generated from reading UI file 'NotWen.ui'
**
** Created: Fri 21. May 00:17:23 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTWEN_H
#define UI_NOTWEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotWen
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_17;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_3;
    QLabel *label_11;
    QLabel *label_5;
    QLabel *x1_lb;
    QLabel *label_6;
    QLabel *x2_lb;
    QLabel *label_10;
    QLabel *fsign_lb;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *precision_lb;
    QLabel *label_7;
    QLabel *length_grad_lb;
    QStackedWidget *stackedWidget;
    QWidget *direction_search;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *gxk;
    QLabel *label_8;
    QRadioButton *gradfxk;
    QLabel *label_9;
    QRadioButton *_g_xkgradfxk;
    QLabel *label_12;
    QRadioButton *g_xkgradfxk;
    QLabel *label_13;
    QRadioButton *gxkgradfxk;
    QLabel *label_14;
    QRadioButton *gradfxkgxk;
    QLabel *label_15;
    QRadioButton *gradfxkg_xk;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *next1_bt;
    QSpacerItem *horizontalSpacer_2;
    QWidget *definitions;
    QGridLayout *gridLayout_10;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_5;
    QRadioButton *proizvod_first;
    QRadioButton *part_proizvod_first;
    QRadioButton *proizvod_second;
    QRadioButton *part_proizvod_second;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *next2_bt;
    QSpacerItem *horizontalSpacer_6;
    QWidget *in_grad;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *dfdx1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *dfdx2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *next3_bt;
    QSpacerItem *horizontalSpacer_4;
    QWidget *criterion_stop;
    QGridLayout *gridLayout_12;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_9;
    QRadioButton *fxk1_fxk;
    QLabel *label_17;
    QRadioButton *gradfxk_more;
    QLabel *label_18;
    QRadioButton *xk1_xk;
    QLabel *label_19;
    QRadioButton *gradfxk_less;
    QLabel *label_20;
    QRadioButton *gxk_less;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *next4_bt;
    QSpacerItem *horizontalSpacer_8;
    QWidget *change_action;
    QGridLayout *gridLayout_13;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_11;
    QRadioButton *to_continue;
    QRadioButton *stop;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *next5_bt;
    QSpacerItem *horizontalSpacer_10;
    QWidget *gessian;
    QGridLayout *gridLayout_16;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_15;
    QLabel *label_3;
    QLineEdit *dfdx1dx1;
    QLineEdit *dfdx1dx2;
    QLineEdit *dfdx2dx1;
    QLineEdit *dfdx2dx2;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_14;
    QLabel *label_22;
    QLineEdit *gess11;
    QLineEdit *gess12;
    QLineEdit *gess21;
    QLineEdit *gess22;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *next6_bt;
    QSpacerItem *horizontalSpacer_12;
    QTextBrowser *LogTxtBrsr;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *NotWen)
    {
        if (NotWen->objectName().isEmpty())
            NotWen->setObjectName(QString::fromUtf8("NotWen"));
        NotWen->setWindowModality(Qt::ApplicationModal);
        NotWen->resize(1125, 783);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(16);
        NotWen->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        NotWen->setWindowIcon(icon);
        centralwidget = new QWidget(NotWen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_17 = new QGridLayout(centralwidget);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_6 = new QGridLayout(groupBox_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFrameShape(QFrame::Box);
        label_11->setAlignment(Qt::AlignCenter);
        label_11->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(label_11, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFrameShape(QFrame::Box);
        label_5->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        x1_lb = new QLabel(groupBox_2);
        x1_lb->setObjectName(QString::fromUtf8("x1_lb"));
        x1_lb->setFrameShape(QFrame::Box);
        x1_lb->setAlignment(Qt::AlignCenter);
        x1_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x1_lb, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFrameShape(QFrame::Box);
        label_6->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        x2_lb = new QLabel(groupBox_2);
        x2_lb->setObjectName(QString::fromUtf8("x2_lb"));
        x2_lb->setFrameShape(QFrame::Box);
        x2_lb->setAlignment(Qt::AlignCenter);
        x2_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x2_lb, 2, 1, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFrameShape(QFrame::Box);
        label_10->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(label_10, 3, 0, 1, 1);

        fsign_lb = new QLabel(groupBox_2);
        fsign_lb->setObjectName(QString::fromUtf8("fsign_lb"));
        fsign_lb->setFrameShape(QFrame::Box);
        fsign_lb->setAlignment(Qt::AlignCenter);
        fsign_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(fsign_lb, 3, 1, 1, 1);

        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 1);

        gridLayout_6->addLayout(gridLayout_3, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::Box);
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        precision_lb = new QLabel(groupBox_2);
        precision_lb->setObjectName(QString::fromUtf8("precision_lb"));
        precision_lb->setFrameShape(QFrame::Box);
        precision_lb->setAlignment(Qt::AlignCenter);
        precision_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(precision_lb, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFrameShape(QFrame::Box);
        label_7->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        length_grad_lb = new QLabel(groupBox_2);
        length_grad_lb->setObjectName(QString::fromUtf8("length_grad_lb"));
        length_grad_lb->setFrameShape(QFrame::Box);
        length_grad_lb->setAlignment(Qt::AlignCenter);
        length_grad_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(length_grad_lb, 1, 1, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);

        gridLayout_6->addLayout(gridLayout_2, 1, 0, 1, 1);


        gridLayout_17->addWidget(groupBox_2, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        direction_search = new QWidget();
        direction_search->setObjectName(QString::fromUtf8("direction_search"));
        gridLayout_4 = new QGridLayout(direction_search);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(direction_search);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        groupBox->setFont(font1);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gxk = new QRadioButton(groupBox);
        gxk->setObjectName(QString::fromUtf8("gxk"));
        QFont font2;
        font2.setPointSize(14);
        gxk->setFont(font2);

        gridLayout->addWidget(gxk, 0, 0, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/icon/NotWen/g(xk).bmp")));

        gridLayout->addWidget(label_8, 0, 1, 1, 1);

        gradfxk = new QRadioButton(groupBox);
        gradfxk->setObjectName(QString::fromUtf8("gradfxk"));
        gradfxk->setFont(font2);

        gridLayout->addWidget(gradfxk, 1, 0, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/icon/NotWen/gradf(xk).bmp")));

        gridLayout->addWidget(label_9, 1, 1, 1, 1);

        _g_xkgradfxk = new QRadioButton(groupBox);
        _g_xkgradfxk->setObjectName(QString::fromUtf8("_g_xkgradfxk"));
        _g_xkgradfxk->setFont(font2);

        gridLayout->addWidget(_g_xkgradfxk, 2, 0, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font2);
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/icon/NotWen/_g_(xk)gradf(xk).bmp")));

        gridLayout->addWidget(label_12, 2, 1, 1, 1);

        g_xkgradfxk = new QRadioButton(groupBox);
        g_xkgradfxk->setObjectName(QString::fromUtf8("g_xkgradfxk"));
        g_xkgradfxk->setFont(font2);

        gridLayout->addWidget(g_xkgradfxk, 3, 0, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font2);
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/icon/NotWen/g_(xk)gradf(xk).bmp")));

        gridLayout->addWidget(label_13, 3, 1, 1, 1);

        gxkgradfxk = new QRadioButton(groupBox);
        gxkgradfxk->setObjectName(QString::fromUtf8("gxkgradfxk"));
        gxkgradfxk->setFont(font2);

        gridLayout->addWidget(gxkgradfxk, 4, 0, 1, 1);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font2);
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/icon/NotWen/g(xk)gradf(xk).bmp")));

        gridLayout->addWidget(label_14, 4, 1, 1, 1);

        gradfxkgxk = new QRadioButton(groupBox);
        gradfxkgxk->setObjectName(QString::fromUtf8("gradfxkgxk"));
        gradfxkgxk->setFont(font2);

        gridLayout->addWidget(gradfxkgxk, 5, 0, 1, 1);

        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font2);
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/icon/NotWen/gradf(xk)g(xk).bmp")));

        gridLayout->addWidget(label_15, 5, 1, 1, 1);

        gradfxkg_xk = new QRadioButton(groupBox);
        gradfxkg_xk->setObjectName(QString::fromUtf8("gradfxkg_xk"));
        gradfxkg_xk->setFont(font2);

        gridLayout->addWidget(gradfxkg_xk, 6, 0, 1, 1);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font2);
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/icon/NotWen/gradf(xk)g_(xk).bmp")));

        gridLayout->addWidget(label_16, 6, 1, 1, 1);

        gridLayout->setColumnStretch(1, 1);

        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        next1_bt = new QPushButton(direction_search);
        next1_bt->setObjectName(QString::fromUtf8("next1_bt"));
        QFont font3;
        font3.setPointSize(12);
        next1_bt->setFont(font3);

        horizontalLayout_2->addWidget(next1_bt);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        gridLayout_4->setRowStretch(0, 1);
        stackedWidget->addWidget(direction_search);
        definitions = new QWidget();
        definitions->setObjectName(QString::fromUtf8("definitions"));
        gridLayout_10 = new QGridLayout(definitions);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        groupBox_5 = new QGroupBox(definitions);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_5 = new QGridLayout(groupBox_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        proizvod_first = new QRadioButton(groupBox_5);
        proizvod_first->setObjectName(QString::fromUtf8("proizvod_first"));
        proizvod_first->setFont(font2);

        gridLayout_5->addWidget(proizvod_first, 0, 0, 1, 1);

        part_proizvod_first = new QRadioButton(groupBox_5);
        part_proizvod_first->setObjectName(QString::fromUtf8("part_proizvod_first"));
        part_proizvod_first->setFont(font2);

        gridLayout_5->addWidget(part_proizvod_first, 1, 0, 1, 1);

        proizvod_second = new QRadioButton(groupBox_5);
        proizvod_second->setObjectName(QString::fromUtf8("proizvod_second"));
        proizvod_second->setFont(font2);

        gridLayout_5->addWidget(proizvod_second, 2, 0, 1, 1);

        part_proizvod_second = new QRadioButton(groupBox_5);
        part_proizvod_second->setObjectName(QString::fromUtf8("part_proizvod_second"));
        part_proizvod_second->setFont(font2);

        gridLayout_5->addWidget(part_proizvod_second, 3, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_5, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        next2_bt = new QPushButton(definitions);
        next2_bt->setObjectName(QString::fromUtf8("next2_bt"));
        next2_bt->setFont(font3);

        horizontalLayout_6->addWidget(next2_bt);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        gridLayout_10->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        gridLayout_10->setRowStretch(0, 1);
        stackedWidget->addWidget(definitions);
        in_grad = new QWidget();
        in_grad->setObjectName(QString::fromUtf8("in_grad"));
        gridLayout_8 = new QGridLayout(in_grad);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        groupBox_4 = new QGroupBox(in_grad);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_7 = new QGridLayout(groupBox_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/icon/dfdx1.bmp")));

        horizontalLayout_4->addWidget(label_2);

        dfdx1 = new QLineEdit(groupBox_4);
        dfdx1->setObjectName(QString::fromUtf8("dfdx1"));
        dfdx1->setFont(font2);

        horizontalLayout_4->addWidget(dfdx1);

        horizontalLayout_4->setStretch(1, 1);

        gridLayout_7->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/icon/dfdx2.bmp")));

        horizontalLayout_5->addWidget(label_4);

        dfdx2 = new QLineEdit(groupBox_4);
        dfdx2->setObjectName(QString::fromUtf8("dfdx2"));
        dfdx2->setFont(font2);

        horizontalLayout_5->addWidget(dfdx2);


        gridLayout_7->addLayout(horizontalLayout_5, 1, 0, 1, 1);


        gridLayout_8->addWidget(groupBox_4, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        next3_bt = new QPushButton(in_grad);
        next3_bt->setObjectName(QString::fromUtf8("next3_bt"));
        next3_bt->setFont(font3);

        horizontalLayout_3->addWidget(next3_bt);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        gridLayout_8->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        gridLayout_8->setRowStretch(0, 1);
        stackedWidget->addWidget(in_grad);
        criterion_stop = new QWidget();
        criterion_stop->setObjectName(QString::fromUtf8("criterion_stop"));
        gridLayout_12 = new QGridLayout(criterion_stop);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        groupBox_6 = new QGroupBox(criterion_stop);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_9 = new QGridLayout(groupBox_6);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        fxk1_fxk = new QRadioButton(groupBox_6);
        fxk1_fxk->setObjectName(QString::fromUtf8("fxk1_fxk"));
        fxk1_fxk->setFont(font2);

        gridLayout_9->addWidget(fxk1_fxk, 0, 0, 1, 1);

        label_17 = new QLabel(groupBox_6);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/icon/NotWen/f(xk1)_f(xk).bmp")));

        gridLayout_9->addWidget(label_17, 0, 1, 1, 1);

        gradfxk_more = new QRadioButton(groupBox_6);
        gradfxk_more->setObjectName(QString::fromUtf8("gradfxk_more"));
        gradfxk_more->setFont(font2);

        gridLayout_9->addWidget(gradfxk_more, 1, 0, 1, 1);

        label_18 = new QLabel(groupBox_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setPixmap(QPixmap(QString::fromUtf8(":/icon/NotWen/gradf(xk)_more.bmp")));

        gridLayout_9->addWidget(label_18, 1, 1, 1, 1);

        xk1_xk = new QRadioButton(groupBox_6);
        xk1_xk->setObjectName(QString::fromUtf8("xk1_xk"));
        xk1_xk->setFont(font2);

        gridLayout_9->addWidget(xk1_xk, 2, 0, 1, 1);

        label_19 = new QLabel(groupBox_6);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setPixmap(QPixmap(QString::fromUtf8(":/icon/NotWen/xk1_xk.bmp")));

        gridLayout_9->addWidget(label_19, 2, 1, 1, 1);

        gradfxk_less = new QRadioButton(groupBox_6);
        gradfxk_less->setObjectName(QString::fromUtf8("gradfxk_less"));
        gradfxk_less->setFont(font2);

        gridLayout_9->addWidget(gradfxk_less, 3, 0, 1, 1);

        label_20 = new QLabel(groupBox_6);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setPixmap(QPixmap(QString::fromUtf8(":/icon/NotWen/gradf(xk)_less.bmp")));

        gridLayout_9->addWidget(label_20, 3, 1, 1, 1);

        gxk_less = new QRadioButton(groupBox_6);
        gxk_less->setObjectName(QString::fromUtf8("gxk_less"));

        gridLayout_9->addWidget(gxk_less, 4, 0, 1, 1);

        label_21 = new QLabel(groupBox_6);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setPixmap(QPixmap(QString::fromUtf8(":/icon/NotWen/g(xk)_less.bmp")));

        gridLayout_9->addWidget(label_21, 4, 1, 1, 1);

        gridLayout_9->setColumnStretch(1, 1);

        gridLayout_12->addWidget(groupBox_6, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        next4_bt = new QPushButton(criterion_stop);
        next4_bt->setObjectName(QString::fromUtf8("next4_bt"));
        next4_bt->setFont(font3);

        horizontalLayout_7->addWidget(next4_bt);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        gridLayout_12->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        gridLayout_12->setRowStretch(0, 1);
        stackedWidget->addWidget(criterion_stop);
        change_action = new QWidget();
        change_action->setObjectName(QString::fromUtf8("change_action"));
        gridLayout_13 = new QGridLayout(change_action);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        groupBox_3 = new QGroupBox(change_action);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_11 = new QGridLayout(groupBox_3);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        to_continue = new QRadioButton(groupBox_3);
        to_continue->setObjectName(QString::fromUtf8("to_continue"));
        to_continue->setFont(font2);

        gridLayout_11->addWidget(to_continue, 0, 0, 1, 1);

        stop = new QRadioButton(groupBox_3);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setFont(font2);

        gridLayout_11->addWidget(stop, 1, 0, 1, 1);


        gridLayout_13->addWidget(groupBox_3, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);

        next5_bt = new QPushButton(change_action);
        next5_bt->setObjectName(QString::fromUtf8("next5_bt"));
        next5_bt->setFont(font3);

        horizontalLayout_8->addWidget(next5_bt);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);


        gridLayout_13->addLayout(horizontalLayout_8, 1, 0, 1, 1);

        gridLayout_13->setRowStretch(0, 1);
        stackedWidget->addWidget(change_action);
        gessian = new QWidget();
        gessian->setObjectName(QString::fromUtf8("gessian"));
        gridLayout_16 = new QGridLayout(gessian);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        groupBox_7 = new QGroupBox(gessian);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        gridLayout_15 = new QGridLayout(groupBox_7);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        label_3 = new QLabel(groupBox_7);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/icon/NotWen/g(x)_rav.bmp")));

        gridLayout_15->addWidget(label_3, 0, 0, 2, 1);

        dfdx1dx1 = new QLineEdit(groupBox_7);
        dfdx1dx1->setObjectName(QString::fromUtf8("dfdx1dx1"));
        dfdx1dx1->setFont(font2);

        gridLayout_15->addWidget(dfdx1dx1, 0, 1, 1, 1);

        dfdx1dx2 = new QLineEdit(groupBox_7);
        dfdx1dx2->setObjectName(QString::fromUtf8("dfdx1dx2"));
        dfdx1dx2->setFont(font2);

        gridLayout_15->addWidget(dfdx1dx2, 0, 2, 1, 1);

        dfdx2dx1 = new QLineEdit(groupBox_7);
        dfdx2dx1->setObjectName(QString::fromUtf8("dfdx2dx1"));
        dfdx2dx1->setFont(font2);

        gridLayout_15->addWidget(dfdx2dx1, 1, 1, 1, 1);

        dfdx2dx2 = new QLineEdit(groupBox_7);
        dfdx2dx2->setObjectName(QString::fromUtf8("dfdx2dx2"));
        dfdx2dx2->setFont(font2);

        gridLayout_15->addWidget(dfdx2dx2, 1, 2, 1, 1);

        gridLayout_15->setColumnStretch(1, 1);
        gridLayout_15->setColumnStretch(2, 1);

        gridLayout_16->addWidget(groupBox_7, 0, 0, 1, 1);

        groupBox_8 = new QGroupBox(gessian);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout_14 = new QGridLayout(groupBox_8);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        label_22 = new QLabel(groupBox_8);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font2);
        label_22->setPixmap(QPixmap(QString::fromUtf8(":/icon/NotWen/g_(x)_rav.bmp")));

        gridLayout_14->addWidget(label_22, 0, 0, 2, 1);

        gess11 = new QLineEdit(groupBox_8);
        gess11->setObjectName(QString::fromUtf8("gess11"));
        gess11->setFont(font2);

        gridLayout_14->addWidget(gess11, 0, 1, 1, 1);

        gess12 = new QLineEdit(groupBox_8);
        gess12->setObjectName(QString::fromUtf8("gess12"));
        gess12->setFont(font2);

        gridLayout_14->addWidget(gess12, 0, 2, 1, 1);

        gess21 = new QLineEdit(groupBox_8);
        gess21->setObjectName(QString::fromUtf8("gess21"));
        gess21->setFont(font2);

        gridLayout_14->addWidget(gess21, 1, 1, 1, 1);

        gess22 = new QLineEdit(groupBox_8);
        gess22->setObjectName(QString::fromUtf8("gess22"));
        gess22->setFont(font2);

        gridLayout_14->addWidget(gess22, 1, 2, 1, 1);

        gridLayout_14->setColumnStretch(1, 1);
        gridLayout_14->setColumnStretch(2, 1);

        gridLayout_16->addWidget(groupBox_8, 1, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_11);

        next6_bt = new QPushButton(gessian);
        next6_bt->setObjectName(QString::fromUtf8("next6_bt"));
        next6_bt->setFont(font3);

        horizontalLayout_9->addWidget(next6_bt);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_12);


        gridLayout_16->addLayout(horizontalLayout_9, 2, 0, 1, 1);

        stackedWidget->addWidget(gessian);

        gridLayout_17->addWidget(stackedWidget, 0, 1, 1, 1);

        LogTxtBrsr = new QTextBrowser(centralwidget);
        LogTxtBrsr->setObjectName(QString::fromUtf8("LogTxtBrsr"));
        LogTxtBrsr->setFont(font2);

        gridLayout_17->addWidget(LogTxtBrsr, 1, 0, 1, 1);

        gridLayout_17->setColumnStretch(0, 1);
        gridLayout_17->setColumnStretch(1, 1);
        NotWen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NotWen);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1125, 23));
        NotWen->setMenuBar(menubar);
        statusbar = new QStatusBar(NotWen);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        NotWen->setStatusBar(statusbar);

        retranslateUi(NotWen);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(NotWen);
    } // setupUi

    void retranslateUi(QMainWindow *NotWen)
    {
        NotWen->setWindowTitle(QApplication::translate("NotWen", "\320\234\320\265\321\202\320\276\320\264 \320\235\321\214\321\216\321\202\320\276\320\275\320\260", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("NotWen", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\270", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("NotWen", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \321\202\320\276\321\207\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NotWen", "\320\2451", 0, QApplication::UnicodeUTF8));
        x1_lb->setText(QApplication::translate("NotWen", "\321\217", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("NotWen", "\320\2452", 0, QApplication::UnicodeUTF8));
        x2_lb->setText(QApplication::translate("NotWen", "\321\217", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("NotWen", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
        fsign_lb->setText(QApplication::translate("NotWen", "\321\217", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NotWen", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        precision_lb->setText(QApplication::translate("NotWen", "\321\213", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("NotWen", "\320\224\320\273\320\270\320\275\320\260 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202\320\260", 0, QApplication::UnicodeUTF8));
        length_grad_lb->setText(QApplication::translate("NotWen", "\320\235\320\265\320\270\320\267\320\262\320\265\321\201\321\202\320\275\320\276", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("NotWen", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\275\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\320\270\321\201\320\272\320\260", 0, QApplication::UnicodeUTF8));
        next1_bt->setText(QApplication::translate("NotWen", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("NotWen", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \320\262\320\265\320\272\321\202\320\276\321\200\320\260 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202\320\260 - \321\215\321\202\320\276...", 0, QApplication::UnicodeUTF8));
        proizvod_first->setText(QApplication::translate("NotWen", "\320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\275\321\213\320\265 \320\277\320\265\321\200\320\262\320\276\320\263\320\276 \320\277\320\276\321\200\321\217\320\264\320\272\320\260", 0, QApplication::UnicodeUTF8));
        part_proizvod_first->setText(QApplication::translate("NotWen", "\321\207\320\260\321\201\321\202\320\275\321\213\320\265 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\275\321\213\320\265 \320\277\320\265\321\200\320\262\320\276\320\263\320\276 \320\277\320\276\321\200\321\217\320\264\320\272\320\260", 0, QApplication::UnicodeUTF8));
        proizvod_second->setText(QApplication::translate("NotWen", "\320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\275\321\213\320\265 \320\262\321\202\320\276\321\200\320\276\320\263\320\276 \320\277\320\276\321\200\321\217\320\264\320\272\320\260", 0, QApplication::UnicodeUTF8));
        part_proizvod_second->setText(QApplication::translate("NotWen", "\321\207\320\260\321\201\321\202\320\275\321\213\320\265 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\275\321\213\320\265 \320\262\321\202\320\276\321\200\320\276\320\263\320\276 \320\277\320\276\321\200\321\217\320\264\320\272\320\260", 0, QApplication::UnicodeUTF8));
        next2_bt->setText(QApplication::translate("NotWen", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("NotWen", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        next3_bt->setText(QApplication::translate("NotWen", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("NotWen", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\272\321\200\320\270\321\202\320\265\321\200\320\270\320\271 \320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\270", 0, QApplication::UnicodeUTF8));
        next4_bt->setText(QApplication::translate("NotWen", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("NotWen", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265", 0, QApplication::UnicodeUTF8));
        to_continue->setText(QApplication::translate("NotWen", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214\321\201\321\217", 0, QApplication::UnicodeUTF8));
        stop->setText(QApplication::translate("NotWen", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        next5_bt->setText(QApplication::translate("NotWen", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("NotWen", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\263\320\265\321\201\321\201\320\270\320\260\320\275", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("NotWen", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\320\261\321\200\320\260\321\202\320\275\321\213\320\271 \320\263\320\265\321\201\321\201\320\270\320\260\320\275", 0, QApplication::UnicodeUTF8));
        next6_bt->setText(QApplication::translate("NotWen", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NotWen: public Ui_NotWen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTWEN_H
