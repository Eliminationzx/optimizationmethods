/********************************************************************************
** Form generated from reading UI file 'CWdescent_fixwindow.ui'
**
** Created: Fri 21. May 00:17:23 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CWDESCENT_FIXWINDOW_H
#define UI_CWDESCENT_FIXWINDOW_H

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
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CWdescentWin
{
public:
    QAction *recomenci_acn;
    QAction *action_2;
    QAction *difiniFonto_act;
    QAction *BroHelp;
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QPushButton *calculate_bt;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *up_x1_rb;
    QRadioButton *down_x1_rb;
    QRadioButton *up_x2_rb;
    QRadioButton *down_x2_rb;
    QPushButton *accept_bt;
    QPushButton *not_accept_bt;
    QPushButton *end_bt;
    QPushButton *change_step_bt;
    QTextBrowser *LogTxtBrsr;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_6;
    QLabel *label_12;
    QLabel *label_5;
    QLabel *x1_lb;
    QLabel *new_x1_lb;
    QLabel *label_6;
    QLabel *x2_lb;
    QLabel *new_x2_lb;
    QLabel *label_10;
    QLabel *fsign_lb;
    QLabel *new_fsign_lb;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *distance_lb;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *precision_lb;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *x1_step_lb;
    QLabel *label_7;
    QLabel *x2_step_lb;
    QMenuBar *menubar;
    QMenu *testo_menu;
    QMenu *view_menu;
    QMenu *inform;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CWdescentWin)
    {
        if (CWdescentWin->objectName().isEmpty())
            CWdescentWin->setObjectName(QString::fromUtf8("CWdescentWin"));
        CWdescentWin->setWindowModality(Qt::ApplicationModal);
        CWdescentWin->resize(870, 574);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(16);
        CWdescentWin->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        CWdescentWin->setWindowIcon(icon);
        recomenci_acn = new QAction(CWdescentWin);
        recomenci_acn->setObjectName(QString::fromUtf8("recomenci_acn"));
        action_2 = new QAction(CWdescentWin);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        difiniFonto_act = new QAction(CWdescentWin);
        difiniFonto_act->setObjectName(QString::fromUtf8("difiniFonto_act"));
        BroHelp = new QAction(CWdescentWin);
        BroHelp->setObjectName(QString::fromUtf8("BroHelp"));
        centralwidget = new QWidget(CWdescentWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setCheckable(false);
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        calculate_bt = new QPushButton(groupBox_3);
        calculate_bt->setObjectName(QString::fromUtf8("calculate_bt"));

        gridLayout->addWidget(calculate_bt, 0, 0, 1, 1);

        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        groupBox->setFont(font1);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        up_x1_rb = new QRadioButton(groupBox);
        up_x1_rb->setObjectName(QString::fromUtf8("up_x1_rb"));

        verticalLayout_2->addWidget(up_x1_rb);

        down_x1_rb = new QRadioButton(groupBox);
        down_x1_rb->setObjectName(QString::fromUtf8("down_x1_rb"));

        verticalLayout_2->addWidget(down_x1_rb);

        up_x2_rb = new QRadioButton(groupBox);
        up_x2_rb->setObjectName(QString::fromUtf8("up_x2_rb"));

        verticalLayout_2->addWidget(up_x2_rb);

        down_x2_rb = new QRadioButton(groupBox);
        down_x2_rb->setObjectName(QString::fromUtf8("down_x2_rb"));

        verticalLayout_2->addWidget(down_x2_rb);


        gridLayout->addWidget(groupBox, 0, 1, 6, 1);

        accept_bt = new QPushButton(groupBox_3);
        accept_bt->setObjectName(QString::fromUtf8("accept_bt"));

        gridLayout->addWidget(accept_bt, 1, 0, 1, 1);

        not_accept_bt = new QPushButton(groupBox_3);
        not_accept_bt->setObjectName(QString::fromUtf8("not_accept_bt"));

        gridLayout->addWidget(not_accept_bt, 2, 0, 1, 1);

        end_bt = new QPushButton(groupBox_3);
        end_bt->setObjectName(QString::fromUtf8("end_bt"));

        gridLayout->addWidget(end_bt, 4, 0, 1, 1);

        change_step_bt = new QPushButton(groupBox_3);
        change_step_bt->setObjectName(QString::fromUtf8("change_step_bt"));

        gridLayout->addWidget(change_step_bt, 3, 0, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);

        gridLayout_4->addWidget(groupBox_3, 0, 1, 1, 1);

        LogTxtBrsr = new QTextBrowser(centralwidget);
        LogTxtBrsr->setObjectName(QString::fromUtf8("LogTxtBrsr"));
        QFont font2;
        font2.setPointSize(14);
        LogTxtBrsr->setFont(font2);

        gridLayout_4->addWidget(LogTxtBrsr, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFrameShape(QFrame::Box);
        label_12->setAlignment(Qt::AlignCenter);
        label_12->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(label_12, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFrameShape(QFrame::Box);
        label_5->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(label_5, 1, 0, 1, 1);

        x1_lb = new QLabel(groupBox_2);
        x1_lb->setObjectName(QString::fromUtf8("x1_lb"));
        x1_lb->setFrameShape(QFrame::Box);
        x1_lb->setAlignment(Qt::AlignCenter);
        x1_lb->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(x1_lb, 1, 1, 1, 1);

        new_x1_lb = new QLabel(groupBox_2);
        new_x1_lb->setObjectName(QString::fromUtf8("new_x1_lb"));
        new_x1_lb->setFrameShape(QFrame::Box);
        new_x1_lb->setAlignment(Qt::AlignCenter);
        new_x1_lb->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(new_x1_lb, 1, 2, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFrameShape(QFrame::Box);
        label_6->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(label_6, 2, 0, 1, 1);

        x2_lb = new QLabel(groupBox_2);
        x2_lb->setObjectName(QString::fromUtf8("x2_lb"));
        x2_lb->setFrameShape(QFrame::Box);
        x2_lb->setAlignment(Qt::AlignCenter);
        x2_lb->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(x2_lb, 2, 1, 1, 1);

        new_x2_lb = new QLabel(groupBox_2);
        new_x2_lb->setObjectName(QString::fromUtf8("new_x2_lb"));
        new_x2_lb->setFrameShape(QFrame::Box);
        new_x2_lb->setAlignment(Qt::AlignCenter);
        new_x2_lb->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(new_x2_lb, 2, 2, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFrameShape(QFrame::Box);
        label_10->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(label_10, 3, 0, 1, 1);

        fsign_lb = new QLabel(groupBox_2);
        fsign_lb->setObjectName(QString::fromUtf8("fsign_lb"));
        fsign_lb->setFrameShape(QFrame::Box);
        fsign_lb->setAlignment(Qt::AlignCenter);
        fsign_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(fsign_lb, 3, 1, 1, 1);

        new_fsign_lb = new QLabel(groupBox_2);
        new_fsign_lb->setObjectName(QString::fromUtf8("new_fsign_lb"));
        new_fsign_lb->setFrameShape(QFrame::Box);
        new_fsign_lb->setAlignment(Qt::AlignCenter);
        new_fsign_lb->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(new_fsign_lb, 3, 2, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFrameShape(QFrame::Box);
        label_11->setAlignment(Qt::AlignCenter);
        label_11->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(label_11, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_6, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFrameShape(QFrame::Box);
        label_4->setWordWrap(true);
        label_4->setTextInteractionFlags(Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(label_4);

        distance_lb = new QLabel(groupBox_2);
        distance_lb->setObjectName(QString::fromUtf8("distance_lb"));
        distance_lb->setFrameShape(QFrame::Box);
        distance_lb->setAlignment(Qt::AlignCenter);
        distance_lb->setTextInteractionFlags(Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(distance_lb);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::Box);
        label->setTextInteractionFlags(Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(label);

        precision_lb = new QLabel(groupBox_2);
        precision_lb->setObjectName(QString::fromUtf8("precision_lb"));
        precision_lb->setFrameShape(QFrame::Box);
        precision_lb->setAlignment(Qt::AlignCenter);
        precision_lb->setTextInteractionFlags(Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(precision_lb);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFrameShape(QFrame::Box);
        label_3->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        x1_step_lb = new QLabel(groupBox_2);
        x1_step_lb->setObjectName(QString::fromUtf8("x1_step_lb"));
        x1_step_lb->setFrameShape(QFrame::Box);
        x1_step_lb->setAlignment(Qt::AlignCenter);
        x1_step_lb->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(x1_step_lb, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFrameShape(QFrame::Box);
        label_7->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        x2_step_lb = new QLabel(groupBox_2);
        x2_step_lb->setObjectName(QString::fromUtf8("x2_step_lb"));
        x2_step_lb->setFrameShape(QFrame::Box);
        x2_step_lb->setAlignment(Qt::AlignCenter);
        x2_step_lb->setTextInteractionFlags(Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(x2_step_lb, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 3, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 1);

        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 1);
        CWdescentWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CWdescentWin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 870, 21));
        testo_menu = new QMenu(menubar);
        testo_menu->setObjectName(QString::fromUtf8("testo_menu"));
        view_menu = new QMenu(menubar);
        view_menu->setObjectName(QString::fromUtf8("view_menu"));
        inform = new QMenu(menubar);
        inform->setObjectName(QString::fromUtf8("inform"));
        CWdescentWin->setMenuBar(menubar);
        statusbar = new QStatusBar(CWdescentWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CWdescentWin->setStatusBar(statusbar);

        menubar->addAction(testo_menu->menuAction());
        menubar->addAction(view_menu->menuAction());
        menubar->addAction(inform->menuAction());
        testo_menu->addAction(recomenci_acn);
        testo_menu->addSeparator();
        testo_menu->addAction(action_2);
        view_menu->addAction(difiniFonto_act);
        inform->addAction(BroHelp);

        retranslateUi(CWdescentWin);

        QMetaObject::connectSlotsByName(CWdescentWin);
    } // setupUi

    void retranslateUi(QMainWindow *CWdescentWin)
    {
        CWdescentWin->setWindowTitle(QApplication::translate("CWdescentWin", "\320\237\320\276\320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\275\321\213\320\271 \321\201\320\277\321\203\321\201\320\272 \321\201 \321\204\320\270\320\272\321\201\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\274 \321\210\320\260\320\263\320\276\320\274", 0, QApplication::UnicodeUTF8));
        recomenci_acn->setText(QApplication::translate("CWdescentWin", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\267\320\260&\320\275\320\276\320\262\320\276", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("CWdescentWin", "&\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", 0, QApplication::UnicodeUTF8));
        difiniFonto_act->setText(QApplication::translate("CWdescentWin", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214 &\321\210\321\200\320\270\321\204\321\202", 0, QApplication::UnicodeUTF8));
        BroHelp->setText(QApplication::translate("CWdescentWin", "\320\237\320\276\320\274\320\276\321\211\321\214", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("CWdescentWin", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\321\200\320\260\320\262\320\270\320\273\321\214\320\275\320\276\320\265 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        calculate_bt->setToolTip(QApplication::translate("CWdescentWin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:13pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\271 \320\262 \320\277\321\200\320\260\320\262\320\276\320\274 \321\201\320\277\320\270\321\201\320\272\320\265 \321\210\320\260\320\263.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        calculate_bt->setText(QApplication::translate("CWdescentWin", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CWdescentWin", "\320\235\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\264\320\262\320\270\320\266\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        up_x1_rb->setText(QApplication::translate("CWdescentWin", "+ \320\277\320\276 \320\2451", 0, QApplication::UnicodeUTF8));
        down_x1_rb->setText(QApplication::translate("CWdescentWin", "- \320\277\320\276 \320\2451", 0, QApplication::UnicodeUTF8));
        up_x2_rb->setText(QApplication::translate("CWdescentWin", "+ \320\277\320\276 \320\2452", 0, QApplication::UnicodeUTF8));
        down_x2_rb->setText(QApplication::translate("CWdescentWin", "- \320\277\320\276 \320\2452", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        accept_bt->setToolTip(QApplication::translate("CWdescentWin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:13pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \321\202\320\276\321\207\320\272\321\203 \320\262 \320\272\320\260\321\207\320\265\321\201\321\202\320\262\320\265 \321\202\320\265\320\272\321\203\321\211\320\265\320\271.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        accept_bt->setText(QApplication::translate("CWdescentWin", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        not_accept_bt->setToolTip(QApplication::translate("CWdescentWin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:13pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">\320\236\321\202\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \321\202\320\276\321\207\320\272\321\203 \320\270 \320\277\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\274\321\203 \321\210\320\260\320\263\321\203 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        not_accept_bt->setText(QApplication::translate("CWdescentWin", "\320\235\320\265 \320\277\321\200\320\270\320\275\320\270\320\274\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        end_bt->setToolTip(QApplication::translate("CWdescentWin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:13pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">\320\227\320\260\320\272\320\276\320\275\321\207\320\270\321\202\321\214 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274, \320\277\321\200\320\270\320\275\321\217\320\262 \321\202\320\265\320\272\321\203\321\211\321\203\321\216 \321\202\320\276\321\207\320\272\321\203 \320\262 \320\272\320\260\321\207\320\265\321\201\321\202\320\262\320\265 \320\274\320\270\320\275\320\270\320\274\321\203\320\274\320\260.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        end_bt->setText(QApplication::translate("CWdescentWin", "\320\227\320\260\320\272\320\276\320\275\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        change_step_bt->setToolTip(QApplication::translate("CWdescentWin", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:13pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">\320\243\320\274\320\265\320\275\321\214\321\210\320\270\321\202\321\214 \321\210\320\260\320\263</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        change_step_bt->setText(QApplication::translate("CWdescentWin", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\210\320\260\320\263", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CWdescentWin", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\270", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("CWdescentWin", "\320\235\320\276\320\262\320\260\321\217 \321\202\320\276\321\207\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CWdescentWin", "\320\2451", 0, QApplication::UnicodeUTF8));
        x1_lb->setText(QApplication::translate("CWdescentWin", "\321\217", 0, QApplication::UnicodeUTF8));
        new_x1_lb->setText(QApplication::translate("CWdescentWin", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CWdescentWin", "\320\2452", 0, QApplication::UnicodeUTF8));
        x2_lb->setText(QApplication::translate("CWdescentWin", "\321\217", 0, QApplication::UnicodeUTF8));
        new_x2_lb->setText(QApplication::translate("CWdescentWin", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("CWdescentWin", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
        fsign_lb->setText(QApplication::translate("CWdescentWin", "\321\217", 0, QApplication::UnicodeUTF8));
        new_fsign_lb->setText(QApplication::translate("CWdescentWin", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("CWdescentWin", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \321\202\320\276\321\207\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CWdescentWin", "\320\240\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\276\321\202 c\321\202\320\260\321\200\320\276\320\271 \320\261\320\260\320\267\320\276\320\262\320\276\320\271 \321\202\320\276\321\207\320\272\320\270 \320\264\320\276 \321\202\320\265\320\272\321\203\321\211\320\265\320\271:", 0, QApplication::UnicodeUTF8));
        distance_lb->setText(QApplication::translate("CWdescentWin", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CWdescentWin", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        precision_lb->setText(QApplication::translate("CWdescentWin", "\321\213", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CWdescentWin", "\320\250\320\260\320\263 \320\277\320\276 \320\2451", 0, QApplication::UnicodeUTF8));
        x1_step_lb->setText(QApplication::translate("CWdescentWin", "\321\213", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("CWdescentWin", "\320\250\320\260\320\263 \320\277\320\276 \320\2452", 0, QApplication::UnicodeUTF8));
        x2_step_lb->setText(QApplication::translate("CWdescentWin", "\321\213", 0, QApplication::UnicodeUTF8));
        testo_menu->setTitle(QApplication::translate("CWdescentWin", "\320\242\320\265\321\201\321\202", 0, QApplication::UnicodeUTF8));
        view_menu->setTitle(QApplication::translate("CWdescentWin", "\320\222\320\270\320\264", 0, QApplication::UnicodeUTF8));
        inform->setTitle(QApplication::translate("CWdescentWin", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CWdescentWin: public Ui_CWdescentWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CWDESCENT_FIXWINDOW_H
