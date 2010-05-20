/********************************************************************************
** Form generated from reading UI file 'NeMi.ui'
**
** Created: Fri 21. May 00:17:23 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEMI_H
#define UI_NEMI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
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

class Ui_NeMi
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_3;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *label_5;
    QLabel *x1_t1_lb;
    QLabel *x1_t2_lb;
    QLabel *x1_t3_lb;
    QLabel *x1_totr_lb;
    QLabel *x1_tras_lb;
    QLabel *label_6;
    QLabel *x2_t1_lb;
    QLabel *x2_t2_lb;
    QLabel *x2_t3_lb;
    QLabel *x2_totr_lb;
    QLabel *x2_tras_lb;
    QLabel *label_10;
    QLabel *fsign_b1_lb;
    QLabel *fsign_b2_lb;
    QLabel *fsign_p_lb;
    QLabel *fsign_new_lb;
    QLabel *fsign_new_lb_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *precision_lb;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLabel *x1_step_lb;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *reflexion;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QRadioButton *t1_ref_rb;
    QRadioButton *t2_ref_rb;
    QRadioButton *t3_ref_rb;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *next1_bt;
    QSpacerItem *horizontalSpacer_2;
    QWidget *stretching;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_9;
    QRadioButton *t1_str_rb;
    QRadioButton *t2_str_rb;
    QRadioButton *t3_str_rb;
    QRadioButton *totr_str_rb;
    QRadioButton *tras_str_rb;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *next2_bt;
    QSpacerItem *horizontalSpacer_4;
    QWidget *compression;
    QGridLayout *gridLayout_10;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_8;
    QRadioButton *t1_com_rb;
    QRadioButton *t2_com_rb;
    QRadioButton *t3_com_rb;
    QRadioButton *tsj_com_rb;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *next3_bt;
    QSpacerItem *horizontalSpacer_6;
    QWidget *reduction;
    QGridLayout *gridLayout_12;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_11;
    QRadioButton *t1_red_rb;
    QRadioButton *t2_red_rb;
    QRadioButton *t3_red_rb;
    QRadioButton *totr_red_rb;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *next4_bt;
    QSpacerItem *horizontalSpacer_8;
    QWidget *blank;
    QPushButton *stretching_bt;
    QPushButton *compression_bt;
    QPushButton *reduction_bt;
    QPushButton *end_bt;
    QPushButton *reflexion_bt;
    QTextBrowser *LogTxtBrsr;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *NeMi)
    {
        if (NeMi->objectName().isEmpty())
            NeMi->setObjectName(QString::fromUtf8("NeMi"));
        NeMi->setWindowModality(Qt::ApplicationModal);
        NeMi->resize(875, 555);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(16);
        NeMi->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        NeMi->setWindowIcon(icon);
        centralwidget = new QWidget(NeMi);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_6 = new QGridLayout(centralwidget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFrameShape(QFrame::Box);
        label_11->setAlignment(Qt::AlignCenter);
        label_11->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(label_11, 0, 1, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFrameShape(QFrame::Box);
        label_12->setAlignment(Qt::AlignCenter);
        label_12->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(label_12, 0, 2, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFrameShape(QFrame::Box);
        label_14->setAlignment(Qt::AlignCenter);
        label_14->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(label_14, 0, 3, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFrameShape(QFrame::Box);
        label_13->setAlignment(Qt::AlignCenter);
        label_13->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(label_13, 0, 4, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFrameShape(QFrame::Box);
        label_15->setAlignment(Qt::AlignCenter);
        label_15->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(label_15, 0, 5, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFrameShape(QFrame::Box);
        label_5->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        x1_t1_lb = new QLabel(groupBox_2);
        x1_t1_lb->setObjectName(QString::fromUtf8("x1_t1_lb"));
        x1_t1_lb->setFrameShape(QFrame::Box);
        x1_t1_lb->setAlignment(Qt::AlignCenter);
        x1_t1_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x1_t1_lb, 1, 1, 1, 1);

        x1_t2_lb = new QLabel(groupBox_2);
        x1_t2_lb->setObjectName(QString::fromUtf8("x1_t2_lb"));
        x1_t2_lb->setFrameShape(QFrame::Box);
        x1_t2_lb->setAlignment(Qt::AlignCenter);
        x1_t2_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x1_t2_lb, 1, 2, 1, 1);

        x1_t3_lb = new QLabel(groupBox_2);
        x1_t3_lb->setObjectName(QString::fromUtf8("x1_t3_lb"));
        x1_t3_lb->setFrameShape(QFrame::Box);
        x1_t3_lb->setAlignment(Qt::AlignCenter);
        x1_t3_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x1_t3_lb, 1, 3, 1, 1);

        x1_totr_lb = new QLabel(groupBox_2);
        x1_totr_lb->setObjectName(QString::fromUtf8("x1_totr_lb"));
        x1_totr_lb->setFrameShape(QFrame::Box);
        x1_totr_lb->setAlignment(Qt::AlignCenter);
        x1_totr_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x1_totr_lb, 1, 4, 1, 1);

        x1_tras_lb = new QLabel(groupBox_2);
        x1_tras_lb->setObjectName(QString::fromUtf8("x1_tras_lb"));
        x1_tras_lb->setFrameShape(QFrame::Box);
        x1_tras_lb->setAlignment(Qt::AlignCenter);
        x1_tras_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x1_tras_lb, 1, 5, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFrameShape(QFrame::Box);
        label_6->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        x2_t1_lb = new QLabel(groupBox_2);
        x2_t1_lb->setObjectName(QString::fromUtf8("x2_t1_lb"));
        x2_t1_lb->setFrameShape(QFrame::Box);
        x2_t1_lb->setAlignment(Qt::AlignCenter);
        x2_t1_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x2_t1_lb, 2, 1, 1, 1);

        x2_t2_lb = new QLabel(groupBox_2);
        x2_t2_lb->setObjectName(QString::fromUtf8("x2_t2_lb"));
        x2_t2_lb->setFrameShape(QFrame::Box);
        x2_t2_lb->setAlignment(Qt::AlignCenter);
        x2_t2_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x2_t2_lb, 2, 2, 1, 1);

        x2_t3_lb = new QLabel(groupBox_2);
        x2_t3_lb->setObjectName(QString::fromUtf8("x2_t3_lb"));
        x2_t3_lb->setFrameShape(QFrame::Box);
        x2_t3_lb->setAlignment(Qt::AlignCenter);
        x2_t3_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x2_t3_lb, 2, 3, 1, 1);

        x2_totr_lb = new QLabel(groupBox_2);
        x2_totr_lb->setObjectName(QString::fromUtf8("x2_totr_lb"));
        x2_totr_lb->setFrameShape(QFrame::Box);
        x2_totr_lb->setAlignment(Qt::AlignCenter);
        x2_totr_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x2_totr_lb, 2, 4, 1, 1);

        x2_tras_lb = new QLabel(groupBox_2);
        x2_tras_lb->setObjectName(QString::fromUtf8("x2_tras_lb"));
        x2_tras_lb->setFrameShape(QFrame::Box);
        x2_tras_lb->setAlignment(Qt::AlignCenter);
        x2_tras_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x2_tras_lb, 2, 5, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFrameShape(QFrame::Box);
        label_10->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(label_10, 3, 0, 1, 1);

        fsign_b1_lb = new QLabel(groupBox_2);
        fsign_b1_lb->setObjectName(QString::fromUtf8("fsign_b1_lb"));
        fsign_b1_lb->setFrameShape(QFrame::Box);
        fsign_b1_lb->setAlignment(Qt::AlignCenter);
        fsign_b1_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(fsign_b1_lb, 3, 1, 1, 1);

        fsign_b2_lb = new QLabel(groupBox_2);
        fsign_b2_lb->setObjectName(QString::fromUtf8("fsign_b2_lb"));
        fsign_b2_lb->setFrameShape(QFrame::Box);
        fsign_b2_lb->setAlignment(Qt::AlignCenter);
        fsign_b2_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(fsign_b2_lb, 3, 2, 1, 1);

        fsign_p_lb = new QLabel(groupBox_2);
        fsign_p_lb->setObjectName(QString::fromUtf8("fsign_p_lb"));
        fsign_p_lb->setFrameShape(QFrame::Box);
        fsign_p_lb->setAlignment(Qt::AlignCenter);
        fsign_p_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(fsign_p_lb, 3, 3, 1, 1);

        fsign_new_lb = new QLabel(groupBox_2);
        fsign_new_lb->setObjectName(QString::fromUtf8("fsign_new_lb"));
        fsign_new_lb->setFrameShape(QFrame::Box);
        fsign_new_lb->setAlignment(Qt::AlignCenter);
        fsign_new_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(fsign_new_lb, 3, 4, 1, 1);

        fsign_new_lb_2 = new QLabel(groupBox_2);
        fsign_new_lb_2->setObjectName(QString::fromUtf8("fsign_new_lb_2"));
        fsign_new_lb_2->setFrameShape(QFrame::Box);
        fsign_new_lb_2->setAlignment(Qt::AlignCenter);
        fsign_new_lb_2->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(fsign_new_lb_2, 3, 5, 1, 1);

        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 1);
        gridLayout_3->setColumnStretch(2, 1);
        gridLayout_3->setColumnStretch(3, 1);
        gridLayout_3->setColumnStretch(4, 1);
        gridLayout_3->setColumnStretch(5, 1);

        gridLayout_2->addLayout(gridLayout_3, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::Box);
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(label);

        precision_lb = new QLabel(groupBox_2);
        precision_lb->setObjectName(QString::fromUtf8("precision_lb"));
        precision_lb->setFrameShape(QFrame::Box);
        precision_lb->setAlignment(Qt::AlignCenter);
        precision_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(precision_lb);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFrameShape(QFrame::Box);
        label_3->setWordWrap(true);
        label_3->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_4->addWidget(label_3);

        x1_step_lb = new QLabel(groupBox_2);
        x1_step_lb->setObjectName(QString::fromUtf8("x1_step_lb"));
        x1_step_lb->setFrameShape(QFrame::Box);
        x1_step_lb->setAlignment(Qt::AlignCenter);
        x1_step_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_4->addWidget(x1_step_lb);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        gridLayout_2->addLayout(horizontalLayout_4, 2, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setCheckable(false);
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(groupBox_3);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        reflexion = new QWidget();
        reflexion->setObjectName(QString::fromUtf8("reflexion"));
        gridLayout_4 = new QGridLayout(reflexion);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(reflexion);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        groupBox->setFont(font1);
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        t1_ref_rb = new QRadioButton(groupBox);
        t1_ref_rb->setObjectName(QString::fromUtf8("t1_ref_rb"));
        QFont font2;
        font2.setPointSize(14);
        t1_ref_rb->setFont(font2);

        gridLayout_5->addWidget(t1_ref_rb, 0, 0, 1, 1);

        t2_ref_rb = new QRadioButton(groupBox);
        t2_ref_rb->setObjectName(QString::fromUtf8("t2_ref_rb"));
        t2_ref_rb->setFont(font2);

        gridLayout_5->addWidget(t2_ref_rb, 1, 0, 1, 1);

        t3_ref_rb = new QRadioButton(groupBox);
        t3_ref_rb->setObjectName(QString::fromUtf8("t3_ref_rb"));
        t3_ref_rb->setFont(font2);

        gridLayout_5->addWidget(t3_ref_rb, 2, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        next1_bt = new QPushButton(reflexion);
        next1_bt->setObjectName(QString::fromUtf8("next1_bt"));
        QFont font3;
        font3.setPointSize(12);
        next1_bt->setFont(font3);

        horizontalLayout_2->addWidget(next1_bt);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        gridLayout_4->setRowStretch(0, 1);
        stackedWidget->addWidget(reflexion);
        stretching = new QWidget();
        stretching->setObjectName(QString::fromUtf8("stretching"));
        gridLayout_7 = new QGridLayout(stretching);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupBox_4 = new QGroupBox(stretching);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setFont(font1);
        gridLayout_9 = new QGridLayout(groupBox_4);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        t1_str_rb = new QRadioButton(groupBox_4);
        t1_str_rb->setObjectName(QString::fromUtf8("t1_str_rb"));
        t1_str_rb->setFont(font2);

        gridLayout_9->addWidget(t1_str_rb, 0, 0, 1, 1);

        t2_str_rb = new QRadioButton(groupBox_4);
        t2_str_rb->setObjectName(QString::fromUtf8("t2_str_rb"));
        t2_str_rb->setFont(font2);

        gridLayout_9->addWidget(t2_str_rb, 1, 0, 1, 1);

        t3_str_rb = new QRadioButton(groupBox_4);
        t3_str_rb->setObjectName(QString::fromUtf8("t3_str_rb"));
        t3_str_rb->setFont(font2);

        gridLayout_9->addWidget(t3_str_rb, 2, 0, 1, 1);

        totr_str_rb = new QRadioButton(groupBox_4);
        totr_str_rb->setObjectName(QString::fromUtf8("totr_str_rb"));
        totr_str_rb->setFont(font2);

        gridLayout_9->addWidget(totr_str_rb, 3, 0, 1, 1);

        tras_str_rb = new QRadioButton(groupBox_4);
        tras_str_rb->setObjectName(QString::fromUtf8("tras_str_rb"));
        tras_str_rb->setFont(font2);

        gridLayout_9->addWidget(tras_str_rb, 4, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_4, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        next2_bt = new QPushButton(stretching);
        next2_bt->setObjectName(QString::fromUtf8("next2_bt"));
        next2_bt->setFont(font3);

        horizontalLayout_3->addWidget(next2_bt);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        gridLayout_7->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        stackedWidget->addWidget(stretching);
        compression = new QWidget();
        compression->setObjectName(QString::fromUtf8("compression"));
        gridLayout_10 = new QGridLayout(compression);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        groupBox_5 = new QGroupBox(compression);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_8 = new QGridLayout(groupBox_5);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        t1_com_rb = new QRadioButton(groupBox_5);
        t1_com_rb->setObjectName(QString::fromUtf8("t1_com_rb"));
        t1_com_rb->setFont(font2);

        gridLayout_8->addWidget(t1_com_rb, 0, 0, 1, 1);

        t2_com_rb = new QRadioButton(groupBox_5);
        t2_com_rb->setObjectName(QString::fromUtf8("t2_com_rb"));
        t2_com_rb->setFont(font2);

        gridLayout_8->addWidget(t2_com_rb, 1, 0, 1, 1);

        t3_com_rb = new QRadioButton(groupBox_5);
        t3_com_rb->setObjectName(QString::fromUtf8("t3_com_rb"));
        t3_com_rb->setFont(font2);

        gridLayout_8->addWidget(t3_com_rb, 2, 0, 1, 1);

        tsj_com_rb = new QRadioButton(groupBox_5);
        tsj_com_rb->setObjectName(QString::fromUtf8("tsj_com_rb"));
        tsj_com_rb->setFont(font2);

        gridLayout_8->addWidget(tsj_com_rb, 3, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_5, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        next3_bt = new QPushButton(compression);
        next3_bt->setObjectName(QString::fromUtf8("next3_bt"));
        next3_bt->setFont(font3);

        horizontalLayout_6->addWidget(next3_bt);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        gridLayout_10->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        gridLayout_10->setRowStretch(0, 1);
        stackedWidget->addWidget(compression);
        reduction = new QWidget();
        reduction->setObjectName(QString::fromUtf8("reduction"));
        gridLayout_12 = new QGridLayout(reduction);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        groupBox_6 = new QGroupBox(reduction);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_11 = new QGridLayout(groupBox_6);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        t1_red_rb = new QRadioButton(groupBox_6);
        t1_red_rb->setObjectName(QString::fromUtf8("t1_red_rb"));
        t1_red_rb->setFont(font2);

        gridLayout_11->addWidget(t1_red_rb, 0, 0, 1, 1);

        t2_red_rb = new QRadioButton(groupBox_6);
        t2_red_rb->setObjectName(QString::fromUtf8("t2_red_rb"));
        t2_red_rb->setFont(font2);

        gridLayout_11->addWidget(t2_red_rb, 1, 0, 1, 1);

        t3_red_rb = new QRadioButton(groupBox_6);
        t3_red_rb->setObjectName(QString::fromUtf8("t3_red_rb"));
        t3_red_rb->setFont(font2);

        gridLayout_11->addWidget(t3_red_rb, 2, 0, 1, 1);

        totr_red_rb = new QRadioButton(groupBox_6);
        totr_red_rb->setObjectName(QString::fromUtf8("totr_red_rb"));
        totr_red_rb->setFont(font2);

        gridLayout_11->addWidget(totr_red_rb, 3, 0, 1, 1);


        gridLayout_12->addWidget(groupBox_6, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        next4_bt = new QPushButton(reduction);
        next4_bt->setObjectName(QString::fromUtf8("next4_bt"));
        next4_bt->setFont(font3);

        horizontalLayout_7->addWidget(next4_bt);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        gridLayout_12->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        gridLayout_12->setRowStretch(0, 1);
        stackedWidget->addWidget(reduction);
        blank = new QWidget();
        blank->setObjectName(QString::fromUtf8("blank"));
        stackedWidget->addWidget(blank);

        gridLayout->addWidget(stackedWidget, 0, 1, 5, 1);

        stretching_bt = new QPushButton(groupBox_3);
        stretching_bt->setObjectName(QString::fromUtf8("stretching_bt"));

        gridLayout->addWidget(stretching_bt, 1, 0, 1, 1);

        compression_bt = new QPushButton(groupBox_3);
        compression_bt->setObjectName(QString::fromUtf8("compression_bt"));

        gridLayout->addWidget(compression_bt, 2, 0, 1, 1);

        reduction_bt = new QPushButton(groupBox_3);
        reduction_bt->setObjectName(QString::fromUtf8("reduction_bt"));

        gridLayout->addWidget(reduction_bt, 3, 0, 1, 1);

        end_bt = new QPushButton(groupBox_3);
        end_bt->setObjectName(QString::fromUtf8("end_bt"));

        gridLayout->addWidget(end_bt, 4, 0, 1, 1);

        reflexion_bt = new QPushButton(groupBox_3);
        reflexion_bt->setObjectName(QString::fromUtf8("reflexion_bt"));

        gridLayout->addWidget(reflexion_bt, 0, 0, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);

        gridLayout_6->addWidget(groupBox_3, 0, 1, 1, 1);

        LogTxtBrsr = new QTextBrowser(centralwidget);
        LogTxtBrsr->setObjectName(QString::fromUtf8("LogTxtBrsr"));
        LogTxtBrsr->setFont(font2);

        gridLayout_6->addWidget(LogTxtBrsr, 1, 0, 1, 1);

        gridLayout_6->setColumnStretch(0, 1);
        gridLayout_6->setColumnStretch(1, 1);
        NeMi->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NeMi);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 875, 23));
        NeMi->setMenuBar(menubar);
        statusbar = new QStatusBar(NeMi);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        NeMi->setStatusBar(statusbar);

        retranslateUi(NeMi);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(NeMi);
    } // setupUi

    void retranslateUi(QMainWindow *NeMi)
    {
        NeMi->setWindowTitle(QApplication::translate("NeMi", "\320\234\320\265\321\202\320\276\320\264 \320\235\320\265\320\273\320\264\320\265\321\200\320\260-\320\234\320\270\320\264\320\260", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("NeMi", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\270", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("NeMi", "T1", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("NeMi", "T2", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("NeMi", "T3", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("NeMi", "T\320\276\321\202\321\200", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("NeMi", "T\321\200\320\260\321\201", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NeMi", "\320\2451", 0, QApplication::UnicodeUTF8));
        x1_t1_lb->setText(QApplication::translate("NeMi", "\321\217", 0, QApplication::UnicodeUTF8));
        x1_t2_lb->setText(QApplication::translate("NeMi", "\321\217", 0, QApplication::UnicodeUTF8));
        x1_t3_lb->setText(QApplication::translate("NeMi", "\321\217", 0, QApplication::UnicodeUTF8));
        x1_totr_lb->setText(QApplication::translate("NeMi", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        x1_tras_lb->setText(QApplication::translate("NeMi", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("NeMi", "\320\2452", 0, QApplication::UnicodeUTF8));
        x2_t1_lb->setText(QApplication::translate("NeMi", "\321\217", 0, QApplication::UnicodeUTF8));
        x2_t2_lb->setText(QApplication::translate("NeMi", "\321\217", 0, QApplication::UnicodeUTF8));
        x2_t3_lb->setText(QApplication::translate("NeMi", "\321\217", 0, QApplication::UnicodeUTF8));
        x2_totr_lb->setText(QApplication::translate("NeMi", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        x2_tras_lb->setText(QApplication::translate("NeMi", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("NeMi", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
        fsign_b1_lb->setText(QApplication::translate("NeMi", "\321\217", 0, QApplication::UnicodeUTF8));
        fsign_b2_lb->setText(QApplication::translate("NeMi", "\321\217", 0, QApplication::UnicodeUTF8));
        fsign_p_lb->setText(QApplication::translate("NeMi", "\321\217", 0, QApplication::UnicodeUTF8));
        fsign_new_lb->setText(QApplication::translate("NeMi", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        fsign_new_lb_2->setText(QApplication::translate("NeMi", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NeMi", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        precision_lb->setText(QApplication::translate("NeMi", "\321\213", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NeMi", "\320\241\321\200\320\265\320\264\320\275\320\265\320\265 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\276\321\202 \321\206\320\265\320\275\321\202\321\200\320\260 \321\202\321\217\320\266\320\265\321\201\321\202\320\270 \320\264\320\276 \320\262\320\265\321\200\321\210\320\270\320\275:", 0, QApplication::UnicodeUTF8));
        x1_step_lb->setText(QApplication::translate("NeMi", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\275\320\276", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("NeMi", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\321\200\320\260\320\262\320\270\320\273\321\214\320\275\320\276\320\265 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("NeMi", "\320\222\320\265\321\200\321\210\320\270\320\275\321\213", 0, QApplication::UnicodeUTF8));
        t1_ref_rb->setText(QApplication::translate("NeMi", "T1", 0, QApplication::UnicodeUTF8));
        t2_ref_rb->setText(QApplication::translate("NeMi", "T2", 0, QApplication::UnicodeUTF8));
        t3_ref_rb->setText(QApplication::translate("NeMi", "T3", 0, QApplication::UnicodeUTF8));
        next1_bt->setText(QApplication::translate("NeMi", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("NeMi", "\320\222\320\265\321\200\321\210\320\270\320\275\321\213", 0, QApplication::UnicodeUTF8));
        t1_str_rb->setText(QApplication::translate("NeMi", "T1", 0, QApplication::UnicodeUTF8));
        t2_str_rb->setText(QApplication::translate("NeMi", "T2", 0, QApplication::UnicodeUTF8));
        t3_str_rb->setText(QApplication::translate("NeMi", "T3", 0, QApplication::UnicodeUTF8));
        totr_str_rb->setText(QApplication::translate("NeMi", "T\320\276\321\202\321\200", 0, QApplication::UnicodeUTF8));
        tras_str_rb->setText(QApplication::translate("NeMi", "\320\242\321\200\320\260\321\201", 0, QApplication::UnicodeUTF8));
        next2_bt->setText(QApplication::translate("NeMi", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("NeMi", "\320\222\320\265\321\200\321\210\320\270\320\275\321\213", 0, QApplication::UnicodeUTF8));
        t1_com_rb->setText(QApplication::translate("NeMi", "\320\2421", 0, QApplication::UnicodeUTF8));
        t2_com_rb->setText(QApplication::translate("NeMi", "\320\2422", 0, QApplication::UnicodeUTF8));
        t3_com_rb->setText(QApplication::translate("NeMi", "\320\2423", 0, QApplication::UnicodeUTF8));
        tsj_com_rb->setText(QApplication::translate("NeMi", "\320\242\321\201\320\266", 0, QApplication::UnicodeUTF8));
        next3_bt->setText(QApplication::translate("NeMi", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("NeMi", "\320\222\320\265\321\200\321\210\320\270\320\275\321\213", 0, QApplication::UnicodeUTF8));
        t1_red_rb->setText(QApplication::translate("NeMi", "\320\2421", 0, QApplication::UnicodeUTF8));
        t2_red_rb->setText(QApplication::translate("NeMi", "\320\2422", 0, QApplication::UnicodeUTF8));
        t3_red_rb->setText(QApplication::translate("NeMi", "\320\2423", 0, QApplication::UnicodeUTF8));
        totr_red_rb->setText(QApplication::translate("NeMi", "\320\242\320\276\321\202\321\200", 0, QApplication::UnicodeUTF8));
        next4_bt->setText(QApplication::translate("NeMi", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        stretching_bt->setToolTip(QApplication::translate("NeMi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Times New Roman'; font-size:13pt;\">\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \321\200\320\260\321\201\321\202\321\217\320\266\320\265\320\275\320\270\320\265</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        stretching_bt->setText(QApplication::translate("NeMi", "\320\240\320\260\321\201\321\202\321\217\320\266\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        compression_bt->setToolTip(QApplication::translate("NeMi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Times New Roman'; font-size:13pt;\">\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \321\201\320\266\320\260\321\202\320\270\320\265</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        compression_bt->setText(QApplication::translate("NeMi", "\320\241\320\266\320\260\321\202\320\270\320\265", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        reduction_bt->setToolTip(QApplication::translate("NeMi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Times New Roman'; font-size:13pt;\">\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \321\200\320\265\320\264\321\203\320\272\321\206\320\270\321\216</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        reduction_bt->setText(QApplication::translate("NeMi", "\320\240\320\265\320\264\321\203\320\272\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        end_bt->setToolTip(QApplication::translate("NeMi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:13pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">\320\227\320\260\320\272\320\276\320\275\321\207\320\270\321\202\321\214 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274, \320\277\321\200\320\270\320\275\321\217\320\262 \321\202\320\265\320\272\321\203\321\211\321\203\321\216 \321\202\320\276\321\207\320\272\321\203 \320\262 \320\272\320\260\321\207\320\265\321\201\321\202\320\262\320\265 \320\274\320\270\320\275\320\270\320\274\321\203\320\274\320\260.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        end_bt->setText(QApplication::translate("NeMi", "\320\227\320\260\320\272\320\276\320\275\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        reflexion_bt->setToolTip(QApplication::translate("NeMi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Times New Roman'; font-size:13pt;\">\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        reflexion_bt->setText(QApplication::translate("NeMi", "\320\236\321\202\321\200\320\260\320\266\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NeMi: public Ui_NeMi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEMI_H
