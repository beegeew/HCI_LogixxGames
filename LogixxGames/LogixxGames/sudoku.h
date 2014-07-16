#ifndef SUDOKU_H
#define SUDOKU_H

#include <QWidget>
#include <QImage>
#include <QLabel>
#include <logixpushbutton.h>

namespace Ui {
    class sudoku;
}

class sudoku : public QWidget
{
    Q_OBJECT

public:
    explicit sudoku(QWidget *parent = 0);
    ~sudoku();

public slots:
    void setNumber(int);

signals:
    void returnToMain();
    void sendButtonClicked(int);
private slots:
    void makeMove(int,int);
    void on_mainScreen_released();
    void on_resetButton_released();

    void on_pushButton_1_released();
    void on_pushButton_2_released();
    void on_pushButton_3_released();
    void on_pushButton_4_released();
    void on_pushButton_5_released();
    void on_pushButton_6_released();
    void on_pushButton_7_released();
    void on_pushButton_8_released();
    void on_pushButton_9_released();

private:
    void checkSolution();

    Ui::sudoku *ui;
    static char easySolution[9][9];
    QLabel *sudokuBackground;
    char gameMode;
    int selected[2];
    char gameBoard[9][9];
    logixPushButton* sudokuGrid[9][9];
    QImage *QPics[1];
};

#endif // SUDOKU_H
