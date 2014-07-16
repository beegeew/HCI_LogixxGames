/********************************************************************************
** Form generated from reading UI file 'sudoku.ui'
**
** Created: Sun Dec 11 21:11:41 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDOKU_H
#define UI_SUDOKU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sudoku
{
public:
    QPushButton *mainScreen;
    QPushButton *pushButton_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_1;
    QPushButton *pushButton_5;
    QPushButton *resetButton;
    QWidget *gridLayoutWidget;
    QGridLayout *mainLayout;
    QWidget *gridLayoutWidget_2;
    QGridLayout *sudokuLayout;

    void setupUi(QWidget *sudoku)
    {
        if (sudoku->objectName().isEmpty())
            sudoku->setObjectName(QString::fromUtf8("sudoku"));
        sudoku->resize(600, 450);
        sudoku->setMinimumSize(QSize(16, 0));
        mainScreen = new QPushButton(sudoku);
        mainScreen->setObjectName(QString::fromUtf8("mainScreen"));
        mainScreen->setGeometry(QRect(420, 410, 161, 31));
        mainScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        pushButton_3 = new QPushButton(sudoku);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(540, 20, 40, 40));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        pushButton_7 = new QPushButton(sudoku);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(420, 140, 40, 40));
        pushButton_7->setFont(font);
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(sudoku);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(480, 20, 40, 40));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        pushButton_9 = new QPushButton(sudoku);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(540, 140, 40, 40));
        pushButton_9->setFont(font);
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        pushButton_4 = new QPushButton(sudoku);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(420, 80, 40, 40));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        pushButton_6 = new QPushButton(sudoku);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(540, 80, 40, 40));
        pushButton_6->setFont(font);
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        pushButton_8 = new QPushButton(sudoku);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(480, 140, 40, 40));
        pushButton_8->setFont(font);
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        pushButton_1 = new QPushButton(sudoku);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(420, 20, 40, 40));
        pushButton_1->setFont(font);
        pushButton_1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        pushButton_5 = new QPushButton(sudoku);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(480, 80, 40, 40));
        pushButton_5->setFont(font);
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        resetButton = new QPushButton(sudoku);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(420, 370, 161, 31));
        resetButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);"));
        gridLayoutWidget = new QWidget(sudoku);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 411, 451));
        mainLayout = new QGridLayout(gridLayoutWidget);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_2 = new QWidget(sudoku);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(-1, -1, 411, 451));
        sudokuLayout = new QGridLayout(gridLayoutWidget_2);
        sudokuLayout->setObjectName(QString::fromUtf8("sudokuLayout"));
        sudokuLayout->setHorizontalSpacing(0);
        sudokuLayout->setVerticalSpacing(1);
        sudokuLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(sudoku);

        QMetaObject::connectSlotsByName(sudoku);
    } // setupUi

    void retranslateUi(QWidget *sudoku)
    {
        sudoku->setWindowTitle(QApplication::translate("sudoku", "Form", 0, QApplication::UnicodeUTF8));
        mainScreen->setText(QApplication::translate("sudoku", "Return to Main Screen", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("sudoku", "3", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("sudoku", "7", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("sudoku", "2", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("sudoku", "9", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("sudoku", "4", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("sudoku", "6", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("sudoku", "8", 0, QApplication::UnicodeUTF8));
        pushButton_1->setText(QApplication::translate("sudoku", "1", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("sudoku", "5", 0, QApplication::UnicodeUTF8));
        resetButton->setText(QApplication::translate("sudoku", "Reset Board", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sudoku: public Ui_sudoku {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKU_H
