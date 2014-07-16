/********************************************************************************
** Form generated from reading UI file 'kakuro.ui'
**
** Created: Sun Dec 11 20:29:58 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KAKURO_H
#define UI_KAKURO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_kakuro
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *kakuroLayout;
    QPushButton *returnMain;
    QPushButton *reset;
    QPushButton *solve;
    QPushButton *hint;
    QPushButton *one;
    QPushButton *two;
    QPushButton *three;
    QPushButton *four;
    QPushButton *five;
    QPushButton *six;
    QPushButton *seven;
    QPushButton *eight;
    QPushButton *nine;
    QPushButton *howToPlay;

    void setupUi(QWidget *kakuro)
    {
        if (kakuro->objectName().isEmpty())
            kakuro->setObjectName(QString::fromUtf8("kakuro"));
        kakuro->resize(600, 450);
        kakuro->setMinimumSize(QSize(600, 450));
        kakuro->setMaximumSize(QSize(600, 450));
        gridLayoutWidget = new QWidget(kakuro);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-1, -1, 441, 451));
        kakuroLayout = new QGridLayout(gridLayoutWidget);
        kakuroLayout->setSpacing(1);
        kakuroLayout->setObjectName(QString::fromUtf8("kakuroLayout"));
        kakuroLayout->setContentsMargins(0, 0, 0, 0);
        returnMain = new QPushButton(kakuro);
        returnMain->setObjectName(QString::fromUtf8("returnMain"));
        returnMain->setGeometry(QRect(460, 400, 125, 31));
        returnMain->setMinimumSize(QSize(125, 31));
        returnMain->setMaximumSize(QSize(125, 31));
        returnMain->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        reset = new QPushButton(kakuro);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setGeometry(QRect(460, 350, 125, 31));
        reset->setMinimumSize(QSize(125, 31));
        reset->setMaximumSize(QSize(125, 31));
        reset->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        solve = new QPushButton(kakuro);
        solve->setObjectName(QString::fromUtf8("solve"));
        solve->setGeometry(QRect(460, 300, 125, 31));
        solve->setMinimumSize(QSize(125, 31));
        solve->setMaximumSize(QSize(125, 31));
        solve->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        hint = new QPushButton(kakuro);
        hint->setObjectName(QString::fromUtf8("hint"));
        hint->setGeometry(QRect(460, 250, 125, 31));
        hint->setMinimumSize(QSize(125, 31));
        hint->setMaximumSize(QSize(125, 31));
        hint->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        one = new QPushButton(kakuro);
        one->setObjectName(QString::fromUtf8("one"));
        one->setGeometry(QRect(450, 10, 31, 31));
        one->setMinimumSize(QSize(0, 0));
        one->setMaximumSize(QSize(125, 31));
        one->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        two = new QPushButton(kakuro);
        two->setObjectName(QString::fromUtf8("two"));
        two->setGeometry(QRect(500, 10, 31, 31));
        two->setMinimumSize(QSize(0, 0));
        two->setMaximumSize(QSize(125, 31));
        two->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        three = new QPushButton(kakuro);
        three->setObjectName(QString::fromUtf8("three"));
        three->setGeometry(QRect(550, 10, 31, 31));
        three->setMinimumSize(QSize(0, 0));
        three->setMaximumSize(QSize(125, 31));
        three->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        four = new QPushButton(kakuro);
        four->setObjectName(QString::fromUtf8("four"));
        four->setGeometry(QRect(450, 50, 31, 31));
        four->setMinimumSize(QSize(0, 0));
        four->setMaximumSize(QSize(125, 31));
        four->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        five = new QPushButton(kakuro);
        five->setObjectName(QString::fromUtf8("five"));
        five->setGeometry(QRect(500, 50, 31, 31));
        five->setMinimumSize(QSize(0, 0));
        five->setMaximumSize(QSize(125, 31));
        five->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        six = new QPushButton(kakuro);
        six->setObjectName(QString::fromUtf8("six"));
        six->setGeometry(QRect(550, 50, 31, 31));
        six->setMinimumSize(QSize(0, 0));
        six->setMaximumSize(QSize(125, 31));
        six->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        seven = new QPushButton(kakuro);
        seven->setObjectName(QString::fromUtf8("seven"));
        seven->setGeometry(QRect(450, 90, 31, 31));
        seven->setMinimumSize(QSize(0, 0));
        seven->setMaximumSize(QSize(125, 31));
        seven->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        eight = new QPushButton(kakuro);
        eight->setObjectName(QString::fromUtf8("eight"));
        eight->setGeometry(QRect(500, 90, 31, 31));
        eight->setMinimumSize(QSize(0, 0));
        eight->setMaximumSize(QSize(125, 31));
        eight->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        nine = new QPushButton(kakuro);
        nine->setObjectName(QString::fromUtf8("nine"));
        nine->setGeometry(QRect(550, 90, 31, 31));
        nine->setMinimumSize(QSize(0, 0));
        nine->setMaximumSize(QSize(125, 31));
        nine->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        howToPlay = new QPushButton(kakuro);
        howToPlay->setObjectName(QString::fromUtf8("howToPlay"));
        howToPlay->setGeometry(QRect(460, 170, 125, 31));
        howToPlay->setMinimumSize(QSize(125, 31));
        howToPlay->setMaximumSize(QSize(125, 31));
        howToPlay->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));

        retranslateUi(kakuro);

        QMetaObject::connectSlotsByName(kakuro);
    } // setupUi

    void retranslateUi(QWidget *kakuro)
    {
        kakuro->setWindowTitle(QApplication::translate("kakuro", "Form", 0, QApplication::UnicodeUTF8));
        returnMain->setText(QApplication::translate("kakuro", "Return to Main Screen", 0, QApplication::UnicodeUTF8));
        reset->setText(QApplication::translate("kakuro", "Reset", 0, QApplication::UnicodeUTF8));
        solve->setText(QApplication::translate("kakuro", "Solve", 0, QApplication::UnicodeUTF8));
        hint->setText(QApplication::translate("kakuro", "Hint", 0, QApplication::UnicodeUTF8));
        one->setText(QApplication::translate("kakuro", "1", 0, QApplication::UnicodeUTF8));
        two->setText(QApplication::translate("kakuro", "2", 0, QApplication::UnicodeUTF8));
        three->setText(QApplication::translate("kakuro", "3", 0, QApplication::UnicodeUTF8));
        four->setText(QApplication::translate("kakuro", "4", 0, QApplication::UnicodeUTF8));
        five->setText(QApplication::translate("kakuro", "5", 0, QApplication::UnicodeUTF8));
        six->setText(QApplication::translate("kakuro", "6", 0, QApplication::UnicodeUTF8));
        seven->setText(QApplication::translate("kakuro", "7", 0, QApplication::UnicodeUTF8));
        eight->setText(QApplication::translate("kakuro", "8", 0, QApplication::UnicodeUTF8));
        nine->setText(QApplication::translate("kakuro", "9", 0, QApplication::UnicodeUTF8));
        howToPlay->setText(QApplication::translate("kakuro", "How to play", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class kakuro: public Ui_kakuro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KAKURO_H
