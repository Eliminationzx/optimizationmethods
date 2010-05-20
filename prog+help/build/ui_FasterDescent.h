/********************************************************************************
** Form generated from reading UI file 'FasterDescent.ui'
**
** Created: Fri 21. May 00:17:23 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FASTERDESCENT_H
#define UI_FASTERDESCENT_H

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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FasterDescent
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_14;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_6;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_5;
    QLabel *x1_lb;
    QLabel *s_x1_lb;
    QLabel *label_6;
    QLabel *x2_lb;
    QLabel *s_x2_lb;
    QLabel *label_10;
    QLabel *fsign_lb;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *precision_lb;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *length_step_a_lb;
    QLabel *label_7;
    QLabel *length_grad_lb;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QPushButton *inserts_bt;
    QStackedWidget *stackedWidget;
    QWidget *ins_s;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QRadioButton *grad_fx;
    QRadioButton *agrad_fx;
    QRadioButton *one_one;
    QRadioButton *aone_one;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *next1_bt;
    QSpacerItem *horizontalSpacer_2;
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
    QPushButton *next2_bt;
    QSpacerItem *horizontalSpacer_4;
    QWidget *compare;
    QGridLayout *gridLayout_10;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_9;
    QRadioButton *fxk_fx;
    QRadioButton *xk_x;
    QRadioButton *gradfx;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *next3_bt;
    QSpacerItem *horizontalSpacer_6;
    QWidget *a;
    QGridLayout *gridLayout_12;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_11;
    QRadioButton *two;
    QRadioButton *half;
    QRadioButton *maxf;
    QRadioButton *minf;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *next4_bt;
    QSpacerItem *horizontalSpacer_8;
    QWidget *blank;
    QPushButton *calcula_bt;
    QPushButton *check_bt;
    QPushButton *step_bt;
    QPushButton *end_bt;
    QTextBrowser *LogTxtBrsr;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FasterDescent)
    {
        if (FasterDescent->objectName().isEmpty())
            FasterDescent->setObjectName(QString::fromUtf8("FasterDescent"));
        FasterDescent->setWindowModality(Qt::ApplicationModal);
        FasterDescent->resize(908, 524);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(16);
        FasterDescent->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        FasterDescent->setWindowIcon(icon);
        centralwidget = new QWidget(FasterDescent);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_14 = new QGridLayout(centralwidget);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFrameShape(QFrame::Box);
        label_11->setAlignment(Qt::AlignCenter);
        label_11->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(label_11, 0, 1, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFrameShape(QFrame::Box);
        label_12->setAlignment(Qt::AlignCenter);
        label_12->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(label_12, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFrameShape(QFrame::Box);
        label_5->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(label_5, 1, 0, 1, 1);

        x1_lb = new QLabel(groupBox_2);
        x1_lb->setObjectName(QString::fromUtf8("x1_lb"));
        x1_lb->setFrameShape(QFrame::Box);
        x1_lb->setAlignment(Qt::AlignCenter);
        x1_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(x1_lb, 1, 1, 1, 1);

        s_x1_lb = new QLabel(groupBox_2);
        s_x1_lb->setObjectName(QString::fromUtf8("s_x1_lb"));
        s_x1_lb->setFrameShape(QFrame::Box);
        s_x1_lb->setAlignment(Qt::AlignCenter);
        s_x1_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(s_x1_lb, 1, 2, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFrameShape(QFrame::Box);
        label_6->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(label_6, 2, 0, 1, 1);

        x2_lb = new QLabel(groupBox_2);
        x2_lb->setObjectName(QString::fromUtf8("x2_lb"));
        x2_lb->setFrameShape(QFrame::Box);
        x2_lb->setAlignment(Qt::AlignCenter);
        x2_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(x2_lb, 2, 1, 1, 1);

        s_x2_lb = new QLabel(groupBox_2);
        s_x2_lb->setObjectName(QString::fromUtf8("s_x2_lb"));
        s_x2_lb->setFrameShape(QFrame::Box);
        s_x2_lb->setAlignment(Qt::AlignCenter);
        s_x2_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(s_x2_lb, 2, 2, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFrameShape(QFrame::Box);
        label_10->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(label_10, 3, 0, 1, 1);

        fsign_lb = new QLabel(groupBox_2);
        fsign_lb->setObjectName(QString::fromUtf8("fsign_lb"));
        fsign_lb->setFrameShape(QFrame::Box);
        fsign_lb->setAlignment(Qt::AlignCenter);
        fsign_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(fsign_lb, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_6);

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


        verticalLayout->addLayout(horizontalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFrameShape(QFrame::Box);
        label_3->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        length_step_a_lb = new QLabel(groupBox_2);
        length_step_a_lb->setObjectName(QString::fromUtf8("length_step_a_lb"));
        length_step_a_lb->setFrameShape(QFrame::Box);
        length_step_a_lb->setAlignment(Qt::AlignCenter);
        length_step_a_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(length_step_a_lb, 0, 1, 1, 1);

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


        verticalLayout->addLayout(gridLayout_2);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_14->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setCheckable(false);
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        inserts_bt = new QPushButton(groupBox_3);
        inserts_bt->setObjectName(QString::fromUtf8("inserts_bt"));

        gridLayout->addWidget(inserts_bt, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(groupBox_3);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        ins_s = new QWidget();
        ins_s->setObjectName(QString::fromUtf8("ins_s"));
        gridLayout_4 = new QGridLayout(ins_s);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(ins_s);
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

        one_one = new QRadioButton(groupBox);
        one_one->setObjectName(QString::fromUtf8("one_one"));
        one_one->setFont(font2);

        gridLayout_5->addWidget(one_one, 2, 0, 1, 1);

        aone_one = new QRadioButton(groupBox);
        aone_one->setObjectName(QString::fromUtf8("aone_one"));
        aone_one->setFont(font2);

        gridLayout_5->addWidget(aone_one, 3, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        next1_bt = new QPushButton(ins_s);
        next1_bt->setObjectName(QString::fromUtf8("next1_bt"));
        QFont font3;
        font3.setPointSize(12);
        next1_bt->setFont(font3);

        horizontalLayout_2->addWidget(next1_bt);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        gridLayout_4->setRowStretch(0, 1);
        stackedWidget->addWidget(ins_s);
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

        next2_bt = new QPushButton(in_grad);
        next2_bt->setObjectName(QString::fromUtf8("next2_bt"));
        next2_bt->setFont(font3);

        horizontalLayout_3->addWidget(next2_bt);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        gridLayout_8->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        gridLayout_8->setRowStretch(0, 1);
        stackedWidget->addWidget(in_grad);
        compare = new QWidget();
        compare->setObjectName(QString::fromUtf8("compare"));
        gridLayout_10 = new QGridLayout(compare);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        groupBox_5 = new QGroupBox(compare);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_9 = new QGridLayout(groupBox_5);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        fxk_fx = new QRadioButton(groupBox_5);
        fxk_fx->setObjectName(QString::fromUtf8("fxk_fx"));
        fxk_fx->setFont(font2);

        gridLayout_9->addWidget(fxk_fx, 0, 0, 1, 1);

        xk_x = new QRadioButton(groupBox_5);
        xk_x->setObjectName(QString::fromUtf8("xk_x"));
        xk_x->setFont(font2);

        gridLayout_9->addWidget(xk_x, 1, 0, 1, 1);

        gradfx = new QRadioButton(groupBox_5);
        gradfx->setObjectName(QString::fromUtf8("gradfx"));
        gradfx->setFont(font2);

        gridLayout_9->addWidget(gradfx, 2, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_5, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        next3_bt = new QPushButton(compare);
        next3_bt->setObjectName(QString::fromUtf8("next3_bt"));
        next3_bt->setFont(font3);

        horizontalLayout_6->addWidget(next3_bt);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        gridLayout_10->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        gridLayout_10->setRowStretch(0, 1);
        stackedWidget->addWidget(compare);
        a = new QWidget();
        a->setObjectName(QString::fromUtf8("a"));
        gridLayout_12 = new QGridLayout(a);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        groupBox_6 = new QGroupBox(a);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_11 = new QGridLayout(groupBox_6);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        two = new QRadioButton(groupBox_6);
        two->setObjectName(QString::fromUtf8("two"));
        two->setFont(font2);

        gridLayout_11->addWidget(two, 0, 0, 1, 1);

        half = new QRadioButton(groupBox_6);
        half->setObjectName(QString::fromUtf8("half"));
        half->setFont(font2);

        gridLayout_11->addWidget(half, 1, 0, 1, 1);

        maxf = new QRadioButton(groupBox_6);
        maxf->setObjectName(QString::fromUtf8("maxf"));
        maxf->setFont(font2);

        gridLayout_11->addWidget(maxf, 2, 0, 1, 1);

        minf = new QRadioButton(groupBox_6);
        minf->setObjectName(QString::fromUtf8("minf"));
        minf->setFont(font2);

        gridLayout_11->addWidget(minf, 3, 0, 1, 1);


        gridLayout_12->addWidget(groupBox_6, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        next4_bt = new QPushButton(a);
        next4_bt->setObjectName(QString::fromUtf8("next4_bt"));
        next4_bt->setFont(font3);

        horizontalLayout_7->addWidget(next4_bt);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        gridLayout_12->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        gridLayout_12->setRowStretch(0, 1);
        stackedWidget->addWidget(a);
        blank = new QWidget();
        blank->setObjectName(QString::fromUtf8("blank"));
        stackedWidget->addWidget(blank);

        gridLayout->addWidget(stackedWidget, 0, 1, 5, 1);

        calcula_bt = new QPushButton(groupBox_3);
        calcula_bt->setObjectName(QString::fromUtf8("calcula_bt"));

        gridLayout->addWidget(calcula_bt, 1, 0, 1, 1);

        check_bt = new QPushButton(groupBox_3);
        check_bt->setObjectName(QString::fromUtf8("check_bt"));

        gridLayout->addWidget(check_bt, 2, 0, 1, 1);

        step_bt = new QPushButton(groupBox_3);
        step_bt->setObjectName(QString::fromUtf8("step_bt"));

        gridLayout->addWidget(step_bt, 3, 0, 1, 1);

        end_bt = new QPushButton(groupBox_3);
        end_bt->setObjectName(QString::fromUtf8("end_bt"));

        gridLayout->addWidget(end_bt, 4, 0, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);

        gridLayout_14->addWidget(groupBox_3, 0, 1, 1, 1);

        LogTxtBrsr = new QTextBrowser(centralwidget);
        LogTxtBrsr->setObjectName(QString::fromUtf8("LogTxtBrsr"));
        LogTxtBrsr->setFont(font2);

        gridLayout_14->addWidget(LogTxtBrsr, 1, 0, 1, 1);

        gridLayout_14->setColumnStretch(0, 1);
        gridLayout_14->setColumnStretch(1, 1);
        FasterDescent->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FasterDescent);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 908, 23));
        FasterDescent->setMenuBar(menubar);
        statusbar = new QStatusBar(FasterDescent);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FasterDescent->setStatusBar(statusbar);

        retranslateUi(FasterDescent);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(FasterDescent);
    } // setupUi

    void retranslateUi(QMainWindow *FasterDescent)
    {
        FasterDescent->setWindowTitle(QApplication::translate("FasterDescent", "\320\234\320\265\321\202\320\276\320\264 \320\275\320\260\320\270\321\201\320\272\320\276\321\200\320\265\320\271\321\210\320\265\320\263\320\276 \321\201\320\277\321\203\321\201\320\272\320\260", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("FasterDescent", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\270", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("FasterDescent", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \321\202\320\276\321\207\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("FasterDescent", "S-\320\275\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("FasterDescent", "\320\2451", 0, QApplication::UnicodeUTF8));
        x1_lb->setText(QApplication::translate("FasterDescent", "\321\217", 0, QApplication::UnicodeUTF8));
        s_x1_lb->setText(QApplication::translate("FasterDescent", "\320\235\320\265\320\270\320\267\320\262\320\265\321\201\321\202\320\275\320\276", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("FasterDescent", "\320\2452", 0, QApplication::UnicodeUTF8));
        x2_lb->setText(QApplication::translate("FasterDescent", "\321\217", 0, QApplication::UnicodeUTF8));
        s_x2_lb->setText(QApplication::translate("FasterDescent", "\320\235\320\265\320\270\320\267\320\262\320\265\321\201\321\202\320\275\320\276", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("FasterDescent", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
        fsign_lb->setText(QApplication::translate("FasterDescent", "\321\217", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FasterDescent", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        precision_lb->setText(QApplication::translate("FasterDescent", "\321\213", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FasterDescent", "\320\260 - \320\264\320\273\320\270\320\275\320\260 \321\210\320\260\320\263\320\260", 0, QApplication::UnicodeUTF8));
        length_step_a_lb->setText(QApplication::translate("FasterDescent", "\320\235\320\265\320\270\320\267\320\262\320\265\321\201\321\202\320\275\320\276", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("FasterDescent", "\320\224\320\273\320\270\320\275\320\260 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202\320\260", 0, QApplication::UnicodeUTF8));
        length_grad_lb->setText(QApplication::translate("FasterDescent", "\320\235\320\265\320\270\320\267\320\262\320\265\321\201\321\202\320\275\320\276", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("FasterDescent", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\321\200\320\260\320\262\320\270\320\273\321\214\320\275\320\276\320\265 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        inserts_bt->setToolTip(QApplication::translate("FasterDescent", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Times New Roman'; font-size:13pt;\">\320\222\320\262\320\265\321\201\321\202\320\270 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202\320\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        inserts_bt->setText(QApplication::translate("FasterDescent", "\320\222\320\262\320\265\321\201\321\202\320\270 S", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("FasterDescent", "\320\232\320\260\320\272 \321\201\321\207\320\270\321\202\320\260\321\202\321\214 S", 0, QApplication::UnicodeUTF8));
        grad_fx->setText(QApplication::translate("FasterDescent", "S = grad f(X)", 0, QApplication::UnicodeUTF8));
        agrad_fx->setText(QApplication::translate("FasterDescent", "S = - grad f(X)", 0, QApplication::UnicodeUTF8));
        one_one->setText(QApplication::translate("FasterDescent", "S = (1; 1)", 0, QApplication::UnicodeUTF8));
        aone_one->setText(QApplication::translate("FasterDescent", "S = (-1; 1)", 0, QApplication::UnicodeUTF8));
        next1_bt->setText(QApplication::translate("FasterDescent", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("FasterDescent", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        next2_bt->setText(QApplication::translate("FasterDescent", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("FasterDescent", "\320\241 \321\207\320\265\320\274 \321\201\321\200\320\260\320\262\320\275\320\270\320\262\320\260\321\202\321\214 \321\202\320\276\321\207\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        fxk_fx->setText(QApplication::translate("FasterDescent", "|| f(xk) - f(x) ||", 0, QApplication::UnicodeUTF8));
        xk_x->setText(QApplication::translate("FasterDescent", "|| xk - x ||", 0, QApplication::UnicodeUTF8));
        gradfx->setText(QApplication::translate("FasterDescent", "|| grad f(x) ||", 0, QApplication::UnicodeUTF8));
        next3_bt->setText(QApplication::translate("FasterDescent", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("FasterDescent", "a  =", 0, QApplication::UnicodeUTF8));
        two->setText(QApplication::translate("FasterDescent", "2", 0, QApplication::UnicodeUTF8));
        half->setText(QApplication::translate("FasterDescent", "0.5", 0, QApplication::UnicodeUTF8));
        maxf->setText(QApplication::translate("FasterDescent", "max f(x + a*S)", 0, QApplication::UnicodeUTF8));
        minf->setText(QApplication::translate("FasterDescent", "min f(x + a*S)", 0, QApplication::UnicodeUTF8));
        next4_bt->setText(QApplication::translate("FasterDescent", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        calcula_bt->setToolTip(QApplication::translate("FasterDescent", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Times New Roman'; font-size:13pt;\">\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214 \320\264\320\273\320\270\320\275\321\203 \321\210\320\260\320\263\320\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        calcula_bt->setText(QApplication::translate("FasterDescent", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214 \320\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        check_bt->setToolTip(QApplication::translate("FasterDescent", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Times New Roman'; font-size:13pt;\">\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214 \320\264\320\273\320\270\320\275\321\203 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202\320\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        check_bt->setText(QApplication::translate("FasterDescent", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        step_bt->setToolTip(QApplication::translate("FasterDescent", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Times New Roman'; font-size:13pt;\">\320\241\320\264\320\265\320\273\320\260\321\202\321\214 \321\210\320\260\320\263 \320\277\320\276 \320\275\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\216 S \320\275\320\260 \320\264\320\273\320\270\320\275\321\203 \320\260</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        step_bt->setText(QApplication::translate("FasterDescent", "\320\241\320\264\320\265\320\273\320\260\321\202\321\214 \321\210\320\260\320\263", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        end_bt->setToolTip(QApplication::translate("FasterDescent", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:13pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">\320\227\320\260\320\272\320\276\320\275\321\207\320\270\321\202\321\214 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274, \320\277\321\200\320\270\320\275\321\217\320\262 \321\202\320\265\320\272\321\203\321\211\321\203\321\216 \321\202\320\276\321\207\320\272\321\203 \320\262 \320\272\320\260\321\207\320\265\321\201\321\202\320\262\320\265 \320\274\320\270\320\275\320\270\320\274\321\203\320\274\320\260.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        end_bt->setText(QApplication::translate("FasterDescent", "\320\227\320\260\320\272\320\276\320\275\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FasterDescent: public Ui_FasterDescent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FASTERDESCENT_H
