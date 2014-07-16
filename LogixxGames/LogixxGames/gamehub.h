#ifndef GAMEHUB_H
#define GAMEHUB_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QtSql>
#include <QTime>
#include <mainscreen.h>
#include <tictactoe.h>
#include <kakuro.h>
#include <sudoku.h>
#include <akari.h>

namespace Ui {
    class gameHub;
}

class gameHub : public QMainWindow
{
    Q_OBJECT

public:
    explicit gameHub(QWidget *parent = 0);
    ~gameHub();

public slots:
    void loadNewModule(int,int);
    void loadMain();
    void updateScore();
    void startTimer();
    void stopTimer();
    void hintUpdateScore(int);

signals:
    void setMode(char);
    void sendScore(int);

private slots:
    void on_setMode_released();

private:
    char gameInPlay;
    char gameMode;
    int currScore;
    QTimer *scoreTimer;
    mainScreen *mainButtons;
    ticTacToe *ticTacGame;
    kakuro *kakuroGame;
    sudoku *sudokuGame;
    akari *akariGame;
    Ui::gameHub *ui;
};

#endif // GAMEHUB_H
