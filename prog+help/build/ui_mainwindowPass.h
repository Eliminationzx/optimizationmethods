/********************************************************************************
** Form generated from reading UI file 'mainwindowPass.ui'
**
** Created: Fri 21. May 00:17:23 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWPASS_H
#define UI_MAINWINDOWPASS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_mainPass
{
public:
    QGridLayout *gridLayout;
    QComboBox *choiceMethods;
    QLabel *label;
    QLineEdit *Password;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *Ok;

    void setupUi(QDialog *mainPass)
    {
        if (mainPass->objectName().isEmpty())
            mainPass->setObjectName(QString::fromUtf8("mainPass"));
        mainPass->resize(199, 109);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        mainPass->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        mainPass->setWindowIcon(icon);
        gridLayout = new QGridLayout(mainPass);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        choiceMethods = new QComboBox(mainPass);
        choiceMethods->setObjectName(QString::fromUtf8("choiceMethods"));

        gridLayout->addWidget(choiceMethods, 0, 0, 1, 2);

        label = new QLabel(mainPass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        Password = new QLineEdit(mainPass);
        Password->setObjectName(QString::fromUtf8("Password"));

        gridLayout->addWidget(Password, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Ok = new QPushButton(mainPass);
        Ok->setObjectName(QString::fromUtf8("Ok"));

        horizontalLayout->addWidget(Ok);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);


        retranslateUi(mainPass);

        QMetaObject::connectSlotsByName(mainPass);
    } // setupUi

    void retranslateUi(QDialog *mainPass)
    {
        mainPass->setWindowTitle(QApplication::translate("mainPass", "\320\222\320\262\320\276\320\264 \320\277\320\260\321\200\320\276\320\273\321\217", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("mainPass", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", 0, QApplication::UnicodeUTF8));
        Password->setText(QString());
        Ok->setText(QApplication::translate("mainPass", "\320\236\320\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mainPass: public Ui_mainPass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWPASS_H
