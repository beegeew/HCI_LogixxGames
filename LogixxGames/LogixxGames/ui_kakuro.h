/********************************************************************************
** Form generated from reading UI file 'kakuro.ui'
**
** Created: Mon Dec 12 02:13:42 2011
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
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
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
    QGroupBox *promptWindow;
    QPushButton *playNowButton;
    QLabel *backgroundWindow;
    QLabel *gameInfoLabel;
    QLabel *winLabel;

    void setupUi(QWidget *kakuro)
    {
        if (kakuro->objectName().isEmpty())
            kakuro->setObjectName(QString::fromUtf8("kakuro"));
        kakuro->resize(600, 450);
        kakuro->setMinimumSize(QSize(600, 450));
        kakuro->setMaximumSize(QSize(600, 450));
        gridLayoutWidget = new QWidget(kakuro);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-1, -1, 451, 451));
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
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        one->setFont(font);
        one->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        two = new QPushButton(kakuro);
        two->setObjectName(QString::fromUtf8("two"));
        two->setGeometry(QRect(500, 10, 31, 31));
        two->setMinimumSize(QSize(0, 0));
        two->setMaximumSize(QSize(125, 31));
        two->setFont(font);
        two->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        three = new QPushButton(kakuro);
        three->setObjectName(QString::fromUtf8("three"));
        three->setGeometry(QRect(550, 10, 31, 31));
        three->setMinimumSize(QSize(0, 0));
        three->setMaximumSize(QSize(125, 31));
        three->setFont(font);
        three->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        four = new QPushButton(kakuro);
        four->setObjectName(QString::fromUtf8("four"));
        four->setGeometry(QRect(450, 50, 31, 31));
        four->setMinimumSize(QSize(0, 0));
        four->setMaximumSize(QSize(125, 31));
        four->setFont(font);
        four->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        five = new QPushButton(kakuro);
        five->setObjectName(QString::fromUtf8("five"));
        five->setGeometry(QRect(500, 50, 31, 31));
        five->setMinimumSize(QSize(0, 0));
        five->setMaximumSize(QSize(125, 31));
        five->setFont(font);
        five->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        six = new QPushButton(kakuro);
        six->setObjectName(QString::fromUtf8("six"));
        six->setGeometry(QRect(550, 50, 31, 31));
        six->setMinimumSize(QSize(0, 0));
        six->setMaximumSize(QSize(125, 31));
        six->setFont(font);
        six->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        seven = new QPushButton(kakuro);
        seven->setObjectName(QString::fromUtf8("seven"));
        seven->setGeometry(QRect(450, 90, 31, 31));
        seven->setMinimumSize(QSize(0, 0));
        seven->setMaximumSize(QSize(125, 31));
        seven->setFont(font);
        seven->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        eight = new QPushButton(kakuro);
        eight->setObjectName(QString::fromUtf8("eight"));
        eight->setGeometry(QRect(500, 90, 31, 31));
        eight->setMinimumSize(QSize(0, 0));
        eight->setMaximumSize(QSize(125, 31));
        eight->setFont(font);
        eight->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        nine = new QPushButton(kakuro);
        nine->setObjectName(QString::fromUtf8("nine"));
        nine->setGeometry(QRect(550, 90, 31, 31));
        nine->setMinimumSize(QSize(0, 0));
        nine->setMaximumSize(QSize(125, 31));
        nine->setFont(font);
        nine->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        howToPlay = new QPushButton(kakuro);
        howToPlay->setObjectName(QString::fromUtf8("howToPlay"));
        howToPlay->setGeometry(QRect(460, 170, 125, 31));
        howToPlay->setMinimumSize(QSize(125, 31));
        howToPlay->setMaximumSize(QSize(125, 31));
        howToPlay->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        promptWindow = new QGroupBox(kakuro);
        promptWindow->setObjectName(QString::fromUtf8("promptWindow"));
        promptWindow->setGeometry(QRect(110, 130, 241, 191));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush2(QColor(255, 255, 220, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        promptWindow->setPalette(palette);
        playNowButton = new QPushButton(promptWindow);
        playNowButton->setObjectName(QString::fromUtf8("playNowButton"));
        playNowButton->setGeometry(QRect(60, 140, 111, 23));
        playNowButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        backgroundWindow = new QLabel(promptWindow);
        backgroundWindow->setObjectName(QString::fromUtf8("backgroundWindow"));
        backgroundWindow->setGeometry(QRect(0, 0, 241, 191));
        backgroundWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        gameInfoLabel = new QLabel(promptWindow);
        gameInfoLabel->setObjectName(QString::fromUtf8("gameInfoLabel"));
        gameInfoLabel->setGeometry(QRect(10, 50, 211, 81));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        gameInfoLabel->setFont(font1);
        gameInfoLabel->setAlignment(Qt::AlignCenter);
        winLabel = new QLabel(promptWindow);
        winLabel->setObjectName(QString::fromUtf8("winLabel"));
        winLabel->setGeometry(QRect(20, 20, 211, 41));
        winLabel->setFont(font1);
        winLabel->setAlignment(Qt::AlignCenter);
        backgroundWindow->raise();
        playNowButton->raise();
        gameInfoLabel->raise();
        winLabel->raise();

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
        promptWindow->setTitle(QString());
        playNowButton->setText(QApplication::translate("kakuro", "Play Now!", 0, QApplication::UnicodeUTF8));
        backgroundWindow->setText(QString());
        gameInfoLabel->setText(QApplication::translate("kakuro", "TextLabel", 0, QApplication::UnicodeUTF8));
        winLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class kakuro: public Ui_kakuro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KAKURO_H
