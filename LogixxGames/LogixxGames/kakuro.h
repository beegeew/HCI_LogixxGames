#ifndef KAKURO_H
#define KAKURO_H

#include <QWidget>
#include <QRect>
#include <logixpushbutton.h>
#include <includes.h>

namespace Ui {
    class kakuro;
}

class kakuro : public QWidget
{
    Q_OBJECT

public:
    explicit kakuro(QWidget *parent = 0);
    ~kakuro();

signals:
    void returnToMain();
    void numButtonClicked(int);
    void startClock();
    void stopClock();
    void usedHint(int);
    void usedSolve(int);

private slots:
    void selectCell(int,int);
    void on_returnMain_released();
    void changeCellValue(int);
    void modeChanged(char);
    void receiveScore(int);
    void loadHints();
    void drawBoard();
    void checkWin();


    void on_one_released();

    void on_two_released();

    void on_three_released();

    void on_four_released();

    void on_five_released();

    void on_six_released();

    void on_seven_released();

    void on_eight_released();

    void on_nine_released();

    void on_reset_released();

    void on_solve_released();

    void on_hint_released();

    void on_howToPlay_released();

    void on_playNowButton_released();

private:
    int randNum(int);
    void gameWon();

    int score;
    QString gameModeVerbose;
    char gameMode;
    bool inPlay;
    bool cellSelected;
    int selectedCell[2];
    Ui::kakuro *ui;
    kakuroPuzzle *kPuz;
    logixPushButton* kakuroCells[14][14];
    char gameBoard[14][14];
};

#endif // KAKURO_H
