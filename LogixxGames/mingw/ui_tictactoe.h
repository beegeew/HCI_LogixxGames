/********************************************************************************
** Form generated from reading UI file 'tictactoe.ui'
**
** Created: Sun Dec 11 20:29:58 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICTACTOE_H
#define UI_TICTACTOE_H

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

class Ui_ticTacToe
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *ticTacToeLayout;
    QPushButton *mainScreen;
    QPushButton *playerX;
    QPushButton *playerO;
    QPushButton *resetButton;
    QLabel *selectPlayerPieceLabel;
    QGroupBox *promptWindow;
    QPushButton *playNowButton;
    QLabel *backgroundWindow;
    QLabel *gameInfoLabel;
    QLabel *winLabel;
    QLabel *currPlayerPieceLabelDisplay;
    QLabel *currPlayerPiece;
    QLabel *whoGoesLabel;

    void setupUi(QWidget *ticTacToe)
    {
        if (ticTacToe->objectName().isEmpty())
            ticTacToe->setObjectName(QString::fromUtf8("ticTacToe"));
        ticTacToe->resize(600, 450);
        ticTacToe->setMinimumSize(QSize(600, 450));
        ticTacToe->setMaximumSize(QSize(600, 450));
        gridLayoutWidget = new QWidget(ticTacToe);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 401, 451));
        ticTacToeLayout = new QGridLayout(gridLayoutWidget);
        ticTacToeLayout->setSpacing(1);
        ticTacToeLayout->setObjectName(QString::fromUtf8("ticTacToeLayout"));
        ticTacToeLayout->setContentsMargins(0, 0, 0, 0);
        mainScreen = new QPushButton(ticTacToe);
        mainScreen->setObjectName(QString::fromUtf8("mainScreen"));
        mainScreen->setGeometry(QRect(430, 402, 161, 31));
        mainScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        playerX = new QPushButton(ticTacToe);
        playerX->setObjectName(QString::fromUtf8("playerX"));
        playerX->setGeometry(QRect(410, 50, 81, 91));
        QFont font;
        font.setPointSize(51);
        playerX->setFont(font);
        playerX->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        playerO = new QPushButton(ticTacToe);
        playerO->setObjectName(QString::fromUtf8("playerO"));
        playerO->setGeometry(QRect(510, 50, 81, 91));
        playerO->setFont(font);
        playerO->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        resetButton = new QPushButton(ticTacToe);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(430, 350, 161, 31));
        resetButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        selectPlayerPieceLabel = new QLabel(ticTacToe);
        selectPlayerPieceLabel->setObjectName(QString::fromUtf8("selectPlayerPieceLabel"));
        selectPlayerPieceLabel->setGeometry(QRect(410, 10, 181, 16));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        selectPlayerPieceLabel->setFont(font1);
        promptWindow = new QGroupBox(ticTacToe);
        promptWindow->setObjectName(QString::fromUtf8("promptWindow"));
        promptWindow->setGeometry(QRect(69, 69, 241, 191));
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
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        gameInfoLabel->setFont(font2);
        winLabel = new QLabel(promptWindow);
        winLabel->setObjectName(QString::fromUtf8("winLabel"));
        winLabel->setGeometry(QRect(10, 20, 211, 21));
        winLabel->setFont(font2);
        winLabel->setAlignment(Qt::AlignCenter);
        backgroundWindow->raise();
        playNowButton->raise();
        gameInfoLabel->raise();
        winLabel->raise();
        currPlayerPieceLabelDisplay = new QLabel(ticTacToe);
        currPlayerPieceLabelDisplay->setObjectName(QString::fromUtf8("currPlayerPieceLabelDisplay"));
        currPlayerPieceLabelDisplay->setGeometry(QRect(410, 150, 181, 41));
        currPlayerPieceLabelDisplay->setFont(font1);
        currPlayerPiece = new QLabel(ticTacToe);
        currPlayerPiece->setObjectName(QString::fromUtf8("currPlayerPiece"));
        currPlayerPiece->setGeometry(QRect(410, 190, 101, 31));
        currPlayerPiece->setFont(font1);
        whoGoesLabel = new QLabel(ticTacToe);
        whoGoesLabel->setObjectName(QString::fromUtf8("whoGoesLabel"));
        whoGoesLabel->setGeometry(QRect(410, 250, 171, 71));
        whoGoesLabel->setFont(font1);

        retranslateUi(ticTacToe);

        QMetaObject::connectSlotsByName(ticTacToe);
    } // setupUi

    void retranslateUi(QWidget *ticTacToe)
    {
        ticTacToe->setWindowTitle(QApplication::translate("ticTacToe", "Tic Tac Toe", 0, QApplication::UnicodeUTF8));
        mainScreen->setText(QApplication::translate("ticTacToe", "Return to Main Screen", 0, QApplication::UnicodeUTF8));
        playerX->setText(QApplication::translate("ticTacToe", "X", 0, QApplication::UnicodeUTF8));
        playerO->setText(QApplication::translate("ticTacToe", "O", 0, QApplication::UnicodeUTF8));
        resetButton->setText(QApplication::translate("ticTacToe", "Reset Board", 0, QApplication::UnicodeUTF8));
        selectPlayerPieceLabel->setText(QApplication::translate("ticTacToe", "Select Player Piece:", 0, QApplication::UnicodeUTF8));
        promptWindow->setTitle(QString());
        playNowButton->setText(QApplication::translate("ticTacToe", "Play Now!", 0, QApplication::UnicodeUTF8));
        backgroundWindow->setText(QString());
        gameInfoLabel->setText(QApplication::translate("ticTacToe", "TextLabel", 0, QApplication::UnicodeUTF8));
        winLabel->setText(QString());
        currPlayerPieceLabelDisplay->setText(QApplication::translate("ticTacToe", "Current Player Piece: ", 0, QApplication::UnicodeUTF8));
        currPlayerPiece->setText(QApplication::translate("ticTacToe", "TextLabel", 0, QApplication::UnicodeUTF8));
        whoGoesLabel->setText(QApplication::translate("ticTacToe", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ticTacToe: public Ui_ticTacToe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICTACTOE_H
