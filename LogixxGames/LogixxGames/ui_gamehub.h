/********************************************************************************
** Form generated from reading UI file 'gamehub.ui'
**
** Created: Sun Dec 11 20:28:20 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEHUB_H
#define UI_GAMEHUB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameHub
{
public:
    QWidget *OverallLayout;
    QLabel *logo;
    QFrame *frame;
    QRadioButton *Easy;
    QRadioButton *Medium;
    QRadioButton *Hard;
    QPushButton *setMode;
    QStackedWidget *gamePages;
    QWidget *mainPage;
    QGridLayout *gameLayout;
    QLCDNumber *score;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *gameHub)
    {
        if (gameHub->objectName().isEmpty())
            gameHub->setObjectName(QString::fromUtf8("gameHub"));
        gameHub->resize(732, 565);
        gameHub->setMinimumSize(QSize(732, 565));
        gameHub->setMaximumSize(QSize(732, 565));
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
        gameHub->setPalette(palette);
        gameHub->setStyleSheet(QString::fromUtf8(""));
        OverallLayout = new QWidget(gameHub);
        OverallLayout->setObjectName(QString::fromUtf8("OverallLayout"));
        logo = new QLabel(OverallLayout);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(150, 0, 391, 71));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/logixxlogo")));
        frame = new QFrame(OverallLayout);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(610, 80, 120, 131));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Easy = new QRadioButton(frame);
        Easy->setObjectName(QString::fromUtf8("Easy"));
        Easy->setGeometry(QRect(10, 10, 82, 17));
        Medium = new QRadioButton(frame);
        Medium->setObjectName(QString::fromUtf8("Medium"));
        Medium->setGeometry(QRect(10, 40, 82, 17));
        Hard = new QRadioButton(frame);
        Hard->setObjectName(QString::fromUtf8("Hard"));
        Hard->setGeometry(QRect(10, 70, 82, 17));
        setMode = new QPushButton(frame);
        setMode->setObjectName(QString::fromUtf8("setMode"));
        setMode->setGeometry(QRect(10, 100, 101, 23));
        setMode->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
"color: rgb(255, 255, 255);"));
        gamePages = new QStackedWidget(OverallLayout);
        gamePages->setObjectName(QString::fromUtf8("gamePages"));
        gamePages->setGeometry(QRect(10, 90, 600, 450));
        gamePages->setMinimumSize(QSize(600, 450));
        gamePages->setMaximumSize(QSize(600, 450));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush3(QColor(127, 127, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        gamePages->setPalette(palette1);
        mainPage = new QWidget();
        mainPage->setObjectName(QString::fromUtf8("mainPage"));
        gameLayout = new QGridLayout(mainPage);
        gameLayout->setSpacing(6);
        gameLayout->setContentsMargins(11, 11, 11, 11);
        gameLayout->setObjectName(QString::fromUtf8("gameLayout"));
        gamePages->addWidget(mainPage);
        score = new QLCDNumber(OverallLayout);
        score->setObjectName(QString::fromUtf8("score"));
        score->setGeometry(QRect(550, 10, 171, 51));
        gameHub->setCentralWidget(OverallLayout);
        statusBar = new QStatusBar(gameHub);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setSizeGripEnabled(false);
        gameHub->setStatusBar(statusBar);

        retranslateUi(gameHub);

        QMetaObject::connectSlotsByName(gameHub);
    } // setupUi

    void retranslateUi(QMainWindow *gameHub)
    {
        gameHub->setWindowTitle(QApplication::translate("gameHub", "Logixx Games", 0, QApplication::UnicodeUTF8));
        logo->setText(QString());
        Easy->setText(QApplication::translate("gameHub", "Easy", 0, QApplication::UnicodeUTF8));
        Medium->setText(QApplication::translate("gameHub", "Medium", 0, QApplication::UnicodeUTF8));
        Hard->setText(QApplication::translate("gameHub", "Hard", 0, QApplication::UnicodeUTF8));
        setMode->setText(QApplication::translate("gameHub", "Set Mode", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class gameHub: public Ui_gameHub {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEHUB_H
