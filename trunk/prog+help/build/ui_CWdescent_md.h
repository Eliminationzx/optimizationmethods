/********************************************************************************
** Form generated from reading UI file 'CWdescent_md.ui'
**
** Created: Fri 21. May 00:17:23 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CWDESCENT_MD_H
#define UI_CWDESCENT_MD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CWdescent_md
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_6;
    QLabel *label_11;
    QLabel *label_5;
    QLabel *x1_lb;
    QLabel *label_6;
    QLabel *x2_lb;
    QLabel *label_10;
    QLabel *fsign_lb;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *dx_lb;
    QLabel *df_lb;
    QGridLayout *gridLayout_7;
    QLabel *label;
    QLabel *precision_lb;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *calculate_bt;
    QPushButton *end_bt;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *min_x1_rb;
    QRadioButton *min_x2_rb;
    QTextBrowser *LogTxtBrsr;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CWdescent_md)
    {
        if (CWdescent_md->objectName().isEmpty())
            CWdescent_md->setObjectName(QString::fromUtf8("CWdescent_md"));
        CWdescent_md->setWindowModality(Qt::ApplicationModal);
        CWdescent_md->resize(812, 581);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(16);
        CWdescent_md->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        CWdescent_md->setWindowIcon(icon);
        centralwidget = new QWidget(CWdescent_md);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFrameShape(QFrame::Box);
        label_11->setAlignment(Qt::AlignCenter);
        label_11->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(label_11, 0, 1, 1, 1);

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


        gridLayout_4->addLayout(gridLayout_6, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFrameShape(QFrame::Box);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFrameShape(QFrame::Box);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFrameShape(QFrame::Box);
        label_4->setWordWrap(true);
        label_4->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        dx_lb = new QLabel(groupBox_2);
        dx_lb->setObjectName(QString::fromUtf8("dx_lb"));
        dx_lb->setFrameShape(QFrame::Box);
        dx_lb->setAlignment(Qt::AlignCenter);
        dx_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(dx_lb, 1, 1, 1, 1);

        df_lb = new QLabel(groupBox_2);
        df_lb->setObjectName(QString::fromUtf8("df_lb"));
        df_lb->setFrameShape(QFrame::Box);
        df_lb->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(df_lb, 1, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::Box);
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_7->addWidget(label, 0, 0, 1, 1);

        precision_lb = new QLabel(groupBox_2);
        precision_lb->setObjectName(QString::fromUtf8("precision_lb"));
        precision_lb->setFrameShape(QFrame::Box);
        precision_lb->setAlignment(Qt::AlignCenter);
        precision_lb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_7->addWidget(precision_lb, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_7, 2, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 0, 0, 2, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setCheckable(false);
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        calculate_bt = new QPushButton(groupBox_3);
        calculate_bt->setObjectName(QString::fromUtf8("calculate_bt"));

        verticalLayout_3->addWidget(calculate_bt);

        end_bt = new QPushButton(groupBox_3);
        end_bt->setObjectName(QString::fromUtf8("end_bt"));

        verticalLayout_3->addWidget(end_bt);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        groupBox->setFont(font1);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        min_x1_rb = new QRadioButton(groupBox);
        min_x1_rb->setObjectName(QString::fromUtf8("min_x1_rb"));

        verticalLayout_2->addWidget(min_x1_rb);

        min_x2_rb = new QRadioButton(groupBox);
        min_x2_rb->setObjectName(QString::fromUtf8("min_x2_rb"));

        verticalLayout_2->addWidget(min_x2_rb);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 1, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);

        gridLayout_5->addWidget(groupBox_3, 0, 1, 1, 1);

        LogTxtBrsr = new QTextBrowser(centralwidget);
        LogTxtBrsr->setObjectName(QString::fromUtf8("LogTxtBrsr"));
        QFont font2;
        font2.setPointSize(14);
        LogTxtBrsr->setFont(font2);

        gridLayout_5->addWidget(LogTxtBrsr, 2, 0, 1, 1);

        gridLayout_5->setColumnStretch(0, 1);
        gridLayout_5->setColumnStretch(1, 1);
        CWdescent_md->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CWdescent_md);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 812, 23));
        CWdescent_md->setMenuBar(menubar);
        statusbar = new QStatusBar(CWdescent_md);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CWdescent_md->setStatusBar(statusbar);

        retranslateUi(CWdescent_md);

        QMetaObject::connectSlotsByName(CWdescent_md);
    } // setupUi

    void retranslateUi(QMainWindow *CWdescent_md)
    {
        CWdescent_md->setWindowTitle(QApplication::translate("CWdescent_md", "\320\237\320\276\320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\275\321\213\320\271 \321\201\320\277\321\203\321\201\320\272 \321\201 \320\274\320\270\320\275\320\270\320\274\320\270\320\267\320\260\321\206\320\270\320\265\320\271 \320\277\320\276 \320\275\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\216", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CWdescent_md", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\270", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("CWdescent_md", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \321\202\320\276\321\207\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CWdescent_md", "\320\2451", 0, QApplication::UnicodeUTF8));
        x1_lb->setText(QApplication::translate("CWdescent_md", "\321\217", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CWdescent_md", "\320\2452", 0, QApplication::UnicodeUTF8));
        x2_lb->setText(QApplication::translate("CWdescent_md", "\321\217", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("CWdescent_md", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
        fsign_lb->setText(QApplication::translate("CWdescent_md", "\321\217", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CWdescent_md", "dX", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CWdescent_md", "dF", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CWdescent_md", "\320\240\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\276\321\202 \321\201\321\202\320\260\321\200\320\276\320\271 \321\202\320\276\321\207\320\272\320\270 \320\264\320\276 \321\202\320\265\320\272\321\203\321\211\320\265\320\271:", 0, QApplication::UnicodeUTF8));
        dx_lb->setText(QApplication::translate("CWdescent_md", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        df_lb->setText(QApplication::translate("CWdescent_md", "\320\235\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\276", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CWdescent_md", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        precision_lb->setText(QApplication::translate("CWdescent_md", "\321\213", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("CWdescent_md", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\321\200\320\260\320\262\320\270\320\273\321\214\320\275\320\276\320\265 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        calculate_bt->setToolTip(QApplication::translate("CWdescent_md", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:13pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\271 \320\262 \320\277\321\200\320\260\320\262\320\276\320\274 \321\201\320\277\320\270\321\201\320\272\320\265 \321\210\320\260\320\263.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        calculate_bt->setText(QApplication::translate("CWdescent_md", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        end_bt->setToolTip(QApplication::translate("CWdescent_md", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Times New Roman'; font-size:13pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">\320\227\320\260\320\272\320\276\320\275\321\207\320\270\321\202\321\214 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274, \320\277\321\200\320\270\320\275\321\217\320\262 \321\202\320\265\320\272\321\203\321\211\321\203\321\216 \321\202\320\276\321\207\320\272\321\203 \320\262 \320\272\320\260\321\207\320\265\321\201\321\202\320\262\320\265 \320\274\320\270\320\275\320\270\320\274\321\203\320\274\320\260.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        end_bt->setText(QApplication::translate("CWdescent_md", "\320\227\320\260\320\272\320\276\320\275\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CWdescent_md", "\320\235\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        min_x1_rb->setText(QApplication::translate("CWdescent_md", "\320\274\320\270\320\275\320\270\320\274\320\270\320\267\320\260\321\206\320\270\321\217 \320\277\320\276 \320\2451", 0, QApplication::UnicodeUTF8));
        min_x2_rb->setText(QApplication::translate("CWdescent_md", "\320\274\320\270\320\275\320\270\320\274\320\270\320\267\320\260\321\206\320\270\321\217 \320\277\320\276 \320\2452", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CWdescent_md: public Ui_CWdescent_md {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CWDESCENT_MD_H
