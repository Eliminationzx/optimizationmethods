/********************************************************************************
** Form generated from reading UI file 'HuGi.ui'
**
** Created: Fri 21. May 00:17:23 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUGI_H
#define UI_HUGI_H

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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HuGi
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_3;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_13;
    QLabel *label_5;
    QLabel *x1_b1_lb;
    QLabel *x1_b2_lb;
    QLabel *x1_p_lb;
    QLabel *x1_new_lb;
    QLabel *label_6;
    QLabel *x2_b1_lb;
    QLabel *x2_b2_lb;
    QLabel *x2_p_lb;
    QLabel *x2_new_lb;
    QLabel *label_10;
    QLabel *fsign_b1_lb;
    QLabel *fsign_b2_lb;
    QLabel *fsign_p_lb;
    QLabel *fsign_new_lb;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *precision_lb;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *x1_step_lb;
    QLabel *label_7;
    QLabel *x2_step_lb;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QPushButton *found_bt;
    QStackedWidget *stackedWidget;
    QWidget *type_found;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QRadioButton *grad_fx;
    QRadioButton *agrad_fx;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *next1_bt;
    QSpacerItem *horizontalSpacer_2;
    QWidget *cwdescent;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *up_x1_rb;
    QRadioButton *down_x1_rb;
    QRadioButton *up_x2_rb;
    QRadioButton *down_x2_rb;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *next2_bt;
    QSpacerItem *horizontalSpacer_4;
    QWidget *result;
    QGridLayout *gridLayout_10;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_9;
    QRadioButton *ok_rb;
    QRadioButton *no_rb;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *next3_bt;
    QSpacerItem *horizontalSpacer_6;
    QWidget *blank;
    QPushButton *accept_bt;
    QPushButton *not_accept_bt;
    QPushButton *change_step_bt;
    QPushButton *end_bt;
    QTextBrowser *LogTxtBrsr;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HuGi)
    {
        if (HuGi->objectName().isEmpty())
            HuGi->setObjectName(QString::fromUtf8("HuGi"));
        HuGi->setWindowModality(Qt::ApplicationModal);
        HuGi->resize(1035, 524);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(16);
        HuGi->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        HuGi->setWindowIcon(icon);
        centralwidget = new QWidget(HuGi);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_8 = new QGridLayout(centralwidget);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
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

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFrameShape(QFrame::Box);
        label_5->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        x1_b1_lb = new QLabel(groupBox_2);
        x1_b1_lb->setObjectName(QString::fromUtf8("x1_b1_lb"));
        x1_b1_lb->setFrameShape(QFrame::Box);
        x1_b1_lb->setAlignment(Qt::AlignCenter);
        x1_b1_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x1_b1_lb, 1, 1, 1, 1);

        x1_b2_lb = new QLabel(groupBox_2);
        x1_b2_lb->setObjectName(QString::fromUtf8("x1_b2_lb"));
        x1_b2_lb->setFrameShape(QFrame::Box);
        x1_b2_lb->setAlignment(Qt::AlignCenter);
        x1_b2_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x1_b2_lb, 1, 2, 1, 1);

        x1_p_lb = new QLabel(groupBox_2);
        x1_p_lb->setObjectName(QString::fromUtf8("x1_p_lb"));
        x1_p_lb->setFrameShape(QFrame::Box);
        x1_p_lb->setAlignment(Qt::AlignCenter);
        x1_p_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x1_p_lb, 1, 3, 1, 1);

        x1_new_lb = new QLabel(groupBox_2);
        x1_new_lb->setObjectName(QString::fromUtf8("x1_new_lb"));
        x1_new_lb->setFrameShape(QFrame::Box);
        x1_new_lb->setAlignment(Qt::AlignCenter);
        x1_new_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x1_new_lb, 1, 4, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFrameShape(QFrame::Box);
        label_6->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        x2_b1_lb = new QLabel(groupBox_2);
        x2_b1_lb->setObjectName(QString::fromUtf8("x2_b1_lb"));
        x2_b1_lb->setFrameShape(QFrame::Box);
        x2_b1_lb->setAlignment(Qt::AlignCenter);
        x2_b1_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x2_b1_lb, 2, 1, 1, 1);

        x2_b2_lb = new QLabel(groupBox_2);
        x2_b2_lb->setObjectName(QString::fromUtf8("x2_b2_lb"));
        x2_b2_lb->setFrameShape(QFrame::Box);
        x2_b2_lb->setAlignment(Qt::AlignCenter);
        x2_b2_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x2_b2_lb, 2, 2, 1, 1);

        x2_p_lb = new QLabel(groupBox_2);
        x2_p_lb->setObjectName(QString::fromUtf8("x2_p_lb"));
        x2_p_lb->setFrameShape(QFrame::Box);
        x2_p_lb->setAlignment(Qt::AlignCenter);
        x2_p_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x2_p_lb, 2, 3, 1, 1);

        x2_new_lb = new QLabel(groupBox_2);
        x2_new_lb->setObjectName(QString::fromUtf8("x2_new_lb"));
        x2_new_lb->setFrameShape(QFrame::Box);
        x2_new_lb->setAlignment(Qt::AlignCenter);
        x2_new_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(x2_new_lb, 2, 4, 1, 1);

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

        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 1);
        gridLayout_3->setColumnStretch(2, 1);
        gridLayout_3->setColumnStretch(3, 1);
        gridLayout_3->setColumnStretch(4, 1);

        gridLayout_6->addLayout(gridLayout_3, 0, 0, 1, 1);

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


        gridLayout_6->addLayout(horizontalLayout, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFrameShape(QFrame::Box);
        label_3->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        x1_step_lb = new QLabel(groupBox_2);
        x1_step_lb->setObjectName(QString::fromUtf8("x1_step_lb"));
        x1_step_lb->setFrameShape(QFrame::Box);
        x1_step_lb->setAlignment(Qt::AlignCenter);
        x1_step_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(x1_step_lb, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFrameShape(QFrame::Box);
        label_7->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        x2_step_lb = new QLabel(groupBox_2);
        x2_step_lb->setObjectName(QString::fromUtf8("x2_step_lb"));
        x2_step_lb->setFrameShape(QFrame::Box);
        x2_step_lb->setAlignment(Qt::AlignCenter);
        x2_step_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(x2_step_lb, 1, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_2, 2, 0, 1, 1);


        gridLayout_8->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setCheckable(false);
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        found_bt = new QPushButton(groupBox_3);
        found_bt->setObjectName(QString::fromUtf8("found_bt"));

        gridLayout->addWidget(found_bt, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(groupBox_3);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        type_found = new QWidget();
        type_found->setObjectName(QString::fromUtf8("type_found"));
        gridLayout_4 = new QGridLayout(type_found);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(type_found);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        groupBox->setFont(font1);
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        grad_fx = new QRadioButton(groupBox);
        grad_fx->setObjectName(QString::fromUtf8("grad_fx"));
        QFont font2;
        font2.setPointSize(14);
        grad_fx->setFont(font2);

        gridLayout_5->addWidget(grad_fx, 0, 0, 1, 1);

        agrad_fx = new QRadioButton(groupBox);
        agrad_fx->setObjectName(QString::fromUtf8("agrad_fx"));
        agrad_fx->setFont(font2);

        gridLayout_5->addWidget(agrad_fx, 1, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        next1_bt = new QPushButton(type_found);
        next1_bt->setObjectName(QString::fromUtf8("next1_bt"));
        QFont font3;
        font3.setPointSize(12);
        next1_bt->setFont(font3);

        horizontalLayout_2->addWidget(next1_bt);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        gridLayout_4->setRowStretch(0, 1);
        stackedWidget->addWidget(type_found);
        cwdescent = new QWidget();
        cwdescent->setObjectName(QString::fromUtf8("cwdescent"));
        gridLayout_7 = new QGridLayout(cwdescent);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupBox_4 = new QGroupBox(cwdescent);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setFont(font1);
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        up_x1_rb = new QRadioButton(groupBox_4);
        up_x1_rb->setObjectName(QString::fromUtf8("up_x1_rb"));
        up_x1_rb->setFont(font2);

        verticalLayout_2->addWidget(up_x1_rb);

        down_x1_rb = new QRadioButton(groupBox_4);
        down_x1_rb->setObjectName(QString::fromUtf8("down_x1_rb"));
        down_x1_rb->setFont(font2);

        verticalLayout_2->addWidget(down_x1_rb);

        up_x2_rb = new QRadioButton(groupBox_4);
        up_x2_rb->setObjectName(QString::fromUtf8("up_x2_rb"));
        up_x2_rb->setFont(font2);

        verticalLayout_2->addWidget(up_x2_rb);

        down_x2_rb = new QRadioButton(groupBox_4);
        down_x2_rb->setObjectName(QString::fromUtf8("down_x2_rb"));
        down_x2_rb->setFont(font2);

        verticalLayout_2->addWidget(down_x2_rb);


        gridLayout_7->addWidget(groupBox_4, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        next2_bt = new QPushButton(cwdescent);
        next2_bt->setObjectName(QString::fromUtf8("next2_bt"));
        next2_bt->setFont(font3);

        horizontalLayout_3->addWidget(next2_bt);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        gridLayout_7->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        stackedWidget->addWidget(cwdescent);
        result = new QWidget();
        result->setObjectName(QString::fromUtf8("result"));
        gridLayout_10 = new QGridLayout(result);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        groupBox_5 = new QGroupBox(result);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_9 = new QGridLayout(groupBox_5);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        ok_rb = new QRadioButton(groupBox_5);
        ok_rb->setObjectName(QString::fromUtf8("ok_rb"));
        ok_rb->setFont(font2);

        gridLayout_9->addWidget(ok_rb, 0, 0, 1, 1);

        no_rb = new QRadioButton(groupBox_5);
        no_rb->setObjectName(QString::fromUtf8("no_rb"));
        no_rb->setFont(font2);

        gridLayout_9->addWidget(no_rb, 1, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_5, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        next3_bt = new QPushButton(result);
        next3_bt->setObjectName(QString::fromUtf8("next3_bt"));
        next3_bt->setFont(font3);

        horizontalLayout_6->addWidget(next3_bt);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        gridLayout_10->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        gridLayout_10->setRowStretch(0, 1);
        stackedWidget->addWidget(result);
        blank = new QWidget();
        blank->setObjectName(QString::fromUtf8("blank"));
        stackedWidget->addWidget(blank);

        gridLayout->addWidget(stackedWidget, 0, 1, 5, 1);

        accept_bt = new QPushButton(groupBox_3);
        accept_bt->setObjectName(QString::fromUtf8("accept_bt"));

        gridLayout->addWidget(accept_bt, 1, 0, 1, 1);

        not_accept_bt = new QPushButton(groupBox_3);
        not_accept_bt->setObjectName(QString::fromUtf8("not_accept_bt"));

        gridLayout->addWidget(not_accept_bt, 2, 0, 1, 1);

        change_step_bt = new QPushButton(groupBox_3);
        change_step_bt->setObjectName(QString::fromUtf8("change_step_bt"));

        gridLayout->addWidget(change_step_bt, 3, 0, 1, 1);

        end_bt = new QPushButton(groupBox_3);
        end_bt->setObjectName(QString::fromUtf8("end_bt"));

        gridLayout->addWidget(end_bt, 4, 0, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);

        gridLayout_8->addWidget(groupBox_3, 0, 1, 1, 1);

        LogTxtBrsr = new QTextBrowser(centralwidget);
        LogTxtBrsr->setObjectName(QString::fromUtf8("LogTxtBrsr"));
        LogTxtBrsr->setFont(font2);

        gridLayout_8->addWidget(LogTxtBrsr, 1, 0, 1, 1);

        gridLayout_8->setColumnStretch(0, 1);
        gridLayout_8->setColumnStretch(1, 1);
        HuGi->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HuGi);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1035, 23));
        HuGi->setMenuBar(menubar);
        statusbar = new QStatusBar(HuGi);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HuGi->setStatusBar(statusbar);

        retranslateUi(HuGi);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(HuGi);
    } // setupUi

    void retranslateUi(QMainWindow *HuGi)
    {
        HuGi->setWindowTitle(QApplication::translate("HuGi", "\320\234\320\265\321\202\320\276\320\264 \320\245\321\203\320\272\320\260-\320\224\320\266\320\270\320\262\321\201\320\260", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("HuGi", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\270", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("HuGi", "B1", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("HuGi", "B2", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("HuGi", "P", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("HuGi", "New", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("HuGi", "\320\2451", 0, QApplication::UnicodeUTF8));
        x1_b1_lb->setText(QApplication::translate("HuGi", "\321\217", 0, QApplication::UnicodeUTF8));
        x1_b2_lb->setText(QApplication::translate("HuGi", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        x1_p_lb->setText(QApplication::translate("HuGi", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        x1_new_lb->setText(QApplication::translate("HuGi", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("HuGi", "\320\2452", 0, QApplication::UnicodeUTF8));
        x2_b1_lb->setText(QApplication::translate("HuGi", "\321\217", 0, QApplication::UnicodeUTF8));
        x2_b2_lb->setText(QApplication::translate("HuGi", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        x2_p_lb->setText(QApplication::translate("HuGi", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        x2_new_lb->setText(QApplication::translate("HuGi", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("HuGi", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
        fsign_b1_lb->setText(QApplication::translate("HuGi", "\321\217", 0, QApplication::UnicodeUTF8));
        fsign_b2_lb->setText(QApplication::translate("HuGi", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        fsign_p_lb->setText(QApplication::translate("HuGi", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        fsign_new_lb->setText(QApplication::translate("HuGi", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HuGi", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        precision_lb->setText(QApplication::translate("HuGi", "\321\213", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("HuGi", "\320\250\320\260\320\263 \320\277\320\276 \320\2451", 0, QApplication::UnicodeUTF8));
        x1_step_lb->setText(QApplication::translate("HuGi", "\321\213", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("HuGi", "\320\250\320\260\320\263 \320\277\320\276 \320\2452", 0, QApplication::UnicodeUTF8));
        x2_step_lb->setText(QApplication::translate("HuGi", "\321\213", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("HuGi", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\321\200\320\260\320\262\320\270\320\273\321\214\320\275\320\276\320\265 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        found_bt->setToolTip(QApplication::translate("HuGi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Times New Roman'; font-size:13pt;\">\320\222\321\213\320\261\320\276\321\200 \321\202\320\270\320\277\320\260 \320\277\320\276\320\270\321\201\320\272\320\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        found_bt->setText(QApplication::translate("HuGi", "\320\237\320\276\320\270\321\201\320\272", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("HuGi", "\320\242\320\270\320\277 \320\277\320\276\320\270\321\201\320\272\320\260", 0, QApplication::UnicodeUTF8));
        grad_fx->setText(QApplication::translate("HuGi", "\320\230\321\201\321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\271", 0, QApplication::UnicodeUTF8));
        agrad_fx->setText(QApplication::translate("HuGi", "\320\237\320\276 \320\276\320\261\321\200\320\260\320\267\321\206\321\203", 0, QApplication::UnicodeUTF8));
        next1_bt->setText(QApplication::translate("HuGi", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("HuGi", "\320\235\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\264\320\262\320\270\320\266\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        up_x1_rb->setText(QApplication::translate("HuGi", "+ \320\277\320\276 \320\2451", 0, QApplication::UnicodeUTF8));
        down_x1_rb->setText(QApplication::translate("HuGi", "- \320\277\320\276 \320\2451", 0, QApplication::UnicodeUTF8));
        up_x2_rb->setText(QApplication::translate("HuGi", "+ \320\277\320\276 \320\2452", 0, QApplication::UnicodeUTF8));
        down_x2_rb->setText(QApplication::translate("HuGi", "- \320\277\320\276 \320\2452", 0, QApplication::UnicodeUTF8));
        next2_bt->setText(QApplication::translate("HuGi", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("HuGi", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214 \320\276\320\261\321\200\320\260\320\267\320\265\321\206", 0, QApplication::UnicodeUTF8));
        ok_rb->setText(QApplication::translate("HuGi", "\320\224\320\260", 0, QApplication::UnicodeUTF8));
        no_rb->setText(QApplication::translate("HuGi", "\320\235\320\265\321\202", 0, QApplication::UnicodeUTF8));
        next3_bt->setText(QApplication::translate("HuGi", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        accept_bt->setToolTip(QApplication::translate("HuGi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:13pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \321\202\320\276\321\207\320\272\321\203 \320\262 \320\272\320\260\321\207\320\265\321\201\321\202\320\262\320\265 \321\202\320\265\320\272\321\203\321\211\320\265\320\271.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        accept_bt->setText(QApplication::translate("HuGi", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        not_accept_bt->setToolTip(QApplication::translate("HuGi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:13pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">\320\236\321\202\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \321\202\320\276\321\207\320\272\321\203 \320\270 \320\277\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\274\321\203 \321\210\320\260\320\263\321\203 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        not_accept_bt->setText(QApplication::translate("HuGi", "\320\235\320\265 \320\277\321\200\320\270\320\275\321\217\321\202\321\214", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        change_step_bt->setToolTip(QApplication::translate("HuGi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:13pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">\320\243\320\274\320\265\320\275\321\214\321\210\320\270\321\202\321\214 \321\210\320\260\320\263</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        change_step_bt->setText(QApplication::translate("HuGi", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\210\320\260\320\263", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        end_bt->setToolTip(QApplication::translate("HuGi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:13pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">\320\227\320\260\320\272\320\276\320\275\321\207\320\270\321\202\321\214 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274, \320\277\321\200\320\270\320\275\321\217\320\262 \321\202\320\265\320\272\321\203\321\211\321\203\321\216 \321\202\320\276\321\207\320\272\321\203 \320\262 \320\272\320\260\321\207\320\265\321\201\321\202\320\262\320\265 \320\274\320\270\320\275\320\270\320\274\321\203\320\274\320\260.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        end_bt->setText(QApplication::translate("HuGi", "\320\227\320\260\320\272\320\276\320\275\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HuGi: public Ui_HuGi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUGI_H
