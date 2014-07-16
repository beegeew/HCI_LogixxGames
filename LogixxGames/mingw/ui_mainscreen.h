/********************************************************************************
** Form generated from reading UI file 'mainscreen.ui'
**
** Created: Sun Dec 11 20:29:58 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainScreen
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *buttonGridLayout;

    void setupUi(QGroupBox *mainScreen)
    {
        if (mainScreen->objectName().isEmpty())
            mainScreen->setObjectName(QString::fromUtf8("mainScreen"));
        mainScreen->resize(600, 450);
        mainScreen->setMinimumSize(QSize(600, 450));
        mainScreen->setMaximumSize(QSize(600, 450));
        gridLayoutWidget = new QWidget(mainScreen);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-1, -1, 601, 451));
        buttonGridLayout = new QGridLayout(gridLayoutWidget);
        buttonGridLayout->setSpacing(0);
        buttonGridLayout->setObjectName(QString::fromUtf8("buttonGridLayout"));
        buttonGridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        buttonGridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(mainScreen);

        QMetaObject::connectSlotsByName(mainScreen);
    } // setupUi

    void retranslateUi(QGroupBox *mainScreen)
    {
        mainScreen->setWindowTitle(QApplication::translate("mainScreen", "Main Menu", 0, QApplication::UnicodeUTF8));
        mainScreen->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class mainScreen: public Ui_mainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
