/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 21. May 00:17:23 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *help;
    QAction *about;
    QAction *allow;
    QAction *exit;
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QGridLayout *gridLayout_4;
    QComboBox *choiceMethods;
    QGroupBox *functions;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QRadioButton *quadFunction;
    QRadioButton *ravinFunction;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *exit_button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *next_button;
    QSpacerItem *horizontalSpacer_3;
    QWidget *page_4;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *choiceVar;
    QSpacerItem *horizontalSpacer_9;
    QRadioButton *inArm;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *comboBox;
    QGroupBox *quadKoef;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLineEdit *a;
    QLabel *label_3;
    QLineEdit *b;
    QLabel *label_4;
    QLineEdit *c;
    QLabel *label_5;
    QLineEdit *d;
    QLabel *label_6;
    QLineEdit *e;
    QLabel *label_7;
    QLineEdit *f;
    QLabel *label_8;
    QLineEdit *g;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *quadSimpleCon;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QLabel *label_9;
    QLineEdit *accuracy;
    QLabel *label_10;
    QLineEdit *stepx1;
    QLabel *label_11;
    QLineEdit *stepx2;
    QLabel *label_12;
    QLineEdit *stepChange;
    QLabel *label_13;
    QLineEdit *x1;
    QLabel *label_14;
    QLineEdit *x2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *back_button;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *next_button_2;
    QSpacerItem *horizontalSpacer_8;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(615, 505);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(14);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        help = new QAction(MainWindow);
        help->setObjectName(QString::fromUtf8("help"));
        about = new QAction(MainWindow);
        about->setObjectName(QString::fromUtf8("about"));
        allow = new QAction(MainWindow);
        allow->setObjectName(QString::fromUtf8("allow"));
        exit = new QAction(MainWindow);
        exit->setObjectName(QString::fromUtf8("exit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_4 = new QGridLayout(page_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        choiceMethods = new QComboBox(page_3);
        choiceMethods->setObjectName(QString::fromUtf8("choiceMethods"));

        gridLayout_4->addWidget(choiceMethods, 0, 0, 1, 1);

        functions = new QGroupBox(page_3);
        functions->setObjectName(QString::fromUtf8("functions"));
        verticalLayout_2 = new QVBoxLayout(functions);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        quadFunction = new QRadioButton(functions);
        quadFunction->setObjectName(QString::fromUtf8("quadFunction"));
        quadFunction->setChecked(true);

        verticalLayout->addWidget(quadFunction);

        ravinFunction = new QRadioButton(functions);
        ravinFunction->setObjectName(QString::fromUtf8("ravinFunction"));
        ravinFunction->setCheckable(false);

        verticalLayout->addWidget(ravinFunction);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 202, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout_4->addWidget(functions, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        exit_button = new QPushButton(page_3);
        exit_button->setObjectName(QString::fromUtf8("exit_button"));

        horizontalLayout->addWidget(exit_button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        next_button = new QPushButton(page_3);
        next_button->setObjectName(QString::fromUtf8("next_button"));

        horizontalLayout->addWidget(next_button);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalLayout->setStretch(2, 1);

        gridLayout_4->addLayout(horizontalLayout, 2, 0, 1, 1);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        gridLayout_6 = new QGridLayout(page_4);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        groupBox = new QGroupBox(page_4);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        choiceVar = new QRadioButton(groupBox);
        choiceVar->setObjectName(QString::fromUtf8("choiceVar"));
        choiceVar->setChecked(true);

        horizontalLayout_5->addWidget(choiceVar);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        inArm = new QRadioButton(groupBox);
        inArm->setObjectName(QString::fromUtf8("inArm"));

        horizontalLayout_5->addWidget(inArm);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBox, 0, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(page_4);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        comboBox = new QComboBox(page_4);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_4->addWidget(comboBox);


        gridLayout_6->addLayout(horizontalLayout_4, 1, 0, 1, 2);

        quadKoef = new QGroupBox(page_4);
        quadKoef->setObjectName(QString::fromUtf8("quadKoef"));
        quadKoef->setEnabled(false);
        verticalLayout_3 = new QVBoxLayout(quadKoef);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(quadKoef);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        a = new QLineEdit(quadKoef);
        a->setObjectName(QString::fromUtf8("a"));

        gridLayout_3->addWidget(a, 0, 1, 1, 1);

        label_3 = new QLabel(quadKoef);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        b = new QLineEdit(quadKoef);
        b->setObjectName(QString::fromUtf8("b"));

        gridLayout_3->addWidget(b, 1, 1, 1, 1);

        label_4 = new QLabel(quadKoef);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 2, 0, 1, 1);

        c = new QLineEdit(quadKoef);
        c->setObjectName(QString::fromUtf8("c"));

        gridLayout_3->addWidget(c, 2, 1, 1, 1);

        label_5 = new QLabel(quadKoef);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 3, 0, 1, 1);

        d = new QLineEdit(quadKoef);
        d->setObjectName(QString::fromUtf8("d"));

        gridLayout_3->addWidget(d, 3, 1, 1, 1);

        label_6 = new QLabel(quadKoef);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 4, 0, 1, 1);

        e = new QLineEdit(quadKoef);
        e->setObjectName(QString::fromUtf8("e"));

        gridLayout_3->addWidget(e, 4, 1, 1, 1);

        label_7 = new QLabel(quadKoef);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 5, 0, 1, 1);

        f = new QLineEdit(quadKoef);
        f->setObjectName(QString::fromUtf8("f"));

        gridLayout_3->addWidget(f, 5, 1, 1, 1);

        label_8 = new QLabel(quadKoef);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 6, 0, 1, 1);

        g = new QLineEdit(quadKoef);
        g->setObjectName(QString::fromUtf8("g"));

        gridLayout_3->addWidget(g, 6, 1, 1, 1);

        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 6);

        verticalLayout_3->addLayout(gridLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        gridLayout_6->addWidget(quadKoef, 2, 0, 1, 1);

        quadSimpleCon = new QGroupBox(page_4);
        quadSimpleCon->setObjectName(QString::fromUtf8("quadSimpleCon"));
        quadSimpleCon->setEnabled(false);
        verticalLayout_4 = new QVBoxLayout(quadSimpleCon);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_9 = new QLabel(quadSimpleCon);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        accuracy = new QLineEdit(quadSimpleCon);
        accuracy->setObjectName(QString::fromUtf8("accuracy"));

        gridLayout->addWidget(accuracy, 0, 1, 1, 1);

        label_10 = new QLabel(quadSimpleCon);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        stepx1 = new QLineEdit(quadSimpleCon);
        stepx1->setObjectName(QString::fromUtf8("stepx1"));

        gridLayout->addWidget(stepx1, 1, 1, 1, 1);

        label_11 = new QLabel(quadSimpleCon);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 2, 0, 1, 1);

        stepx2 = new QLineEdit(quadSimpleCon);
        stepx2->setObjectName(QString::fromUtf8("stepx2"));

        gridLayout->addWidget(stepx2, 2, 1, 1, 1);

        label_12 = new QLabel(quadSimpleCon);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 3, 0, 1, 1);

        stepChange = new QLineEdit(quadSimpleCon);
        stepChange->setObjectName(QString::fromUtf8("stepChange"));

        gridLayout->addWidget(stepChange, 3, 1, 1, 1);

        label_13 = new QLabel(quadSimpleCon);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 4, 0, 1, 1);

        x1 = new QLineEdit(quadSimpleCon);
        x1->setObjectName(QString::fromUtf8("x1"));

        gridLayout->addWidget(x1, 4, 1, 1, 1);

        label_14 = new QLabel(quadSimpleCon);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 5, 0, 1, 1);

        x2 = new QLineEdit(quadSimpleCon);
        x2->setObjectName(QString::fromUtf8("x2"));

        gridLayout->addWidget(x2, 5, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 5);

        verticalLayout_4->addLayout(gridLayout);

        verticalSpacer_3 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);


        gridLayout_6->addWidget(quadSimpleCon, 2, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        back_button = new QPushButton(page_4);
        back_button->setObjectName(QString::fromUtf8("back_button"));

        horizontalLayout_3->addWidget(back_button);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        next_button_2 = new QPushButton(page_4);
        next_button_2->setObjectName(QString::fromUtf8("next_button_2"));

        horizontalLayout_3->addWidget(next_button_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        horizontalLayout_3->setStretch(2, 1);

        gridLayout_6->addLayout(horizontalLayout_3, 3, 0, 1, 2);

        stackedWidget->addWidget(page_4);

        gridLayout_5->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 615, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(allow);
        menu->addSeparator();
        menu->addAction(exit);
        menu_2->addAction(help);
        menu_2->addSeparator();
        menu_2->addAction(about);

        retranslateUi(MainWindow);
        QObject::connect(exit, SIGNAL(activated()), MainWindow, SLOT(close()));
        QObject::connect(exit_button, SIGNAL(clicked()), MainWindow, SLOT(close()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264\321\213 \320\276\320\277\321\202\320\270\320\274\320\270\320\267\320\260\321\206\320\270\320\270 2010", 0, QApplication::UnicodeUTF8));
        help->setText(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
        about->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\265...", 0, QApplication::UnicodeUTF8));
        allow->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\321\200\320\265\321\210\320\270\321\202\321\214 \321\204\321\203\320\275\320\272\321\206\320\270\321\216", 0, QApplication::UnicodeUTF8));
        exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        functions->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\321\216", 0, QApplication::UnicodeUTF8));
        quadFunction->setText(QApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202\320\270\321\207\320\275\320\260\321\217 \321\204\321\203\320\275\320\272\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
        ravinFunction->setText(QApplication::translate("MainWindow", "\320\236\320\262\321\200\320\260\320\266\320\275\320\260\321\217 \321\204\321\203\320\275\320\272\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
        exit_button->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        next_button->setText(QApplication::translate("MainWindow", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271", 0, QApplication::UnicodeUTF8));
        choiceVar->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\262\320\260\321\200\320\270\320\260\320\275\321\202\320\260", 0, QApplication::UnicodeUTF8));
        inArm->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264 \320\262\321\200\321\203\321\207\320\275\321\203\321\216", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\262\320\260\321\200\320\270\320\260\320\275\321\202:", 0, QApplication::UnicodeUTF8));
        quadKoef->setTitle(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\321\213", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "A -", 0, QApplication::UnicodeUTF8));
        a->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "B -", 0, QApplication::UnicodeUTF8));
        b->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "C -", 0, QApplication::UnicodeUTF8));
        c->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "D -", 0, QApplication::UnicodeUTF8));
        d->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "E -", 0, QApplication::UnicodeUTF8));
        e->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "F -", 0, QApplication::UnicodeUTF8));
        f->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "G -", 0, QApplication::UnicodeUTF8));
        g->setText(QString());
        quadSimpleCon->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\265 \321\203\321\201\320\273\320\276\320\262\320\270\321\217", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "\321\202\320\276\321\207\320\275\320\276\321\201\321\202\321\214 -", 0, QApplication::UnicodeUTF8));
        accuracy->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "\321\210\320\260\320\263 \320\277\320\276 \321\2051 -", 0, QApplication::UnicodeUTF8));
        stepx1->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "\321\210\320\260\320\263 \320\277\320\276 \321\2052 -", 0, QApplication::UnicodeUTF8));
        stepx2->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "\320\270\320\267\320\274\320\265\320\275. \321\210\320\260\320\263\320\260 -", 0, QApplication::UnicodeUTF8));
        stepChange->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "\321\2051 -", 0, QApplication::UnicodeUTF8));
        x1->setText(QString());
        label_14->setText(QApplication::translate("MainWindow", "\321\2052 -", 0, QApplication::UnicodeUTF8));
        x2->setText(QString());
        back_button->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", 0, QApplication::UnicodeUTF8));
        next_button_2->setText(QApplication::translate("MainWindow", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
