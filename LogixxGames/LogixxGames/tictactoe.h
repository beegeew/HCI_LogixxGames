#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QWidget>
#include <QImage>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QRect>
#include "logixpushbutton.h"

namespace Ui {
    class ticTacToe;
}

class ticTacToe : public QWidget
{
    Q_OBJECT

public:
    explicit ticTacToe(QWidget *parent = 0);
    ~ticTacToe();

public slots:
    void makeMove(int,int);

private slots:
    void on_mainScreen_released();
    void modeChanged(char);
    void on_resetButton_released();

    void on_playerX_released();

    void on_playerO_released();

    void on_playNowButton_released();

signals:
    void returnToMain();

private:
    void checkMove(char, int, int);
    int scoreCompMove(int,int,int);
    void makeCompMove();
    void drawBoard();
    void incBoard();
    void executeCompMove(int,int);
    int randNum(int);
    void resetBoard();

    int movesMade;
    QString gameModeVerbose;
    bool gameInPlay;
    char gameMode;
    char playerChar;
    char currBoard;
    char gameBoard[10][3][3];
    QImage *QPics[5];
    Ui::ticTacToe *ui;
    logixPushButton *ticTacToeGrid[3][3];
};

#endif // TICTACTOE_H
