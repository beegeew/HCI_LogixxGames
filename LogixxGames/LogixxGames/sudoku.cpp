#include "sudoku.h"
#include "ui_sudoku.h"
#include <QDebug>
#include <QMessageBox>
#include <QSet>
#include <QPixmap>
#include <fstream>

#define SUDOKU "font-size: 25px;;min-width:38px;max-width:38px;min-height: 43px; color: rgb(0, 0, 200);background-color: rgb(255, 255, 255);border: 2px solid #000000;"
#define SUDOKUWRONG "font-size: 25px;;min-width:38px;max-width:38px;min-height: 43px; color: rgb(200, 0, 0);background-color: rgb(255, 255, 255);border: 2px solid #000000;"
#define SUDOKUVALUE "font-size: 25px;;min-width:38px;max-width:38px;min-height: 43px; color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);border: 2px solid #000000;"
#define SUDOKUSELECT "font-size:25px;border: 2px solid #f4c50a; min-width:38px; max-width:38px;min-height: 43px; color: rgb(0, 0, 127);background-color: rgb(255, 255, 255);"
#define SUDOKUSELECTWRONG "font-size:25px;border: 2px solid #f4c50a; min-width:38px; max-width:38px;min-height: 43px; color: rgb(200, 0, 0);background-color: rgb(255, 255, 255);"


char sudoku::easySolution[9][9]    =   {{'8','v','2','v','4','v','3','1','5'},
                        {'1','3','v','2','5','8','v','6','v'},
                        {'v','5','9','1','v','7','4','v','2'},
                        {'5','v','v','8','v','4','7','v','1'},
                        {'v','v','7','9','v','5','2','v','v'},
                        {'4','v','8','7','v','3','v','v','6'},
                        {'2','v','3','5','v','1','8','7','v'},
                        {'v','4','v','3','8','6','v','2','9'},
                        {'9','8','1','v','7','v','6','v','3'}};

sudoku::sudoku(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sudoku)
{
    ui->setupUi(this);

    QPics[1] = new QImage(":/sudokubackground");

    QRect * rectSetup = new QRect(0,0,450,450);

    ui->sudokuLayout->setGeometry((*rectSetup));

    sudokuBackground = new QLabel(this);

    sudokuBackground->setPixmap(QPixmap::fromImage((*QPics[1])));
    sudokuBackground->setMaximumSize(450,450);
    sudokuBackground->setMinimumSize(450,450);
    ui->mainLayout->addWidget(sudokuBackground);
    sudokuBackground->show();

    connect(this, SIGNAL(sendButtonClicked(int)), this, SLOT(setNumber(int)));

    selected[0]=selected[1]=-1;

    for (int i = 0; i<9; i++)
        for (int j = 0; j <9; j++) {
            sudokuGrid[i][j] = new logixPushButton(this,i,j);
            connect(sudokuGrid[i][j],SIGNAL(buttonClicked(int,int)),this,SLOT(makeMove(int, int)));
            sudokuGrid[i][j]->setFlat(true);
            sudokuGrid[i][j]->setStyleSheet(SUDOKU);
            ui->sudokuLayout->addWidget(sudokuGrid[i][j],i,j);
            gameBoard[i][j] = 'b';
        }

    std::ifstream sudBoard;
    int value, row, col;

    sudBoard.open("sudokuboardeasy.txt");

    bool sudokuboard = true;

    while(sudokuboard)
    {
        while (!sudBoard.eof() && sudBoard.peek() != 'v')
            sudBoard.get();

        if (sudBoard.eof())
            sudokuboard = false;
        if (sudBoard.peek() == 'v'){
            for (int i=0;i<6;i++) {
                sudBoard.get();
            }
                sudBoard >> value;
                sudBoard.get();
                sudBoard >> row;
                sudBoard.get();
                sudBoard >> col;

                sudokuGrid[row-1][col-1]->setText(QString("%1").arg(value));
                sudokuGrid[row-1][col-1]->setStyleSheet(SUDOKUVALUE);
                gameBoard[row-1][col-1] = 'v';
        }
    }

    sudBoard.close();
}

void sudoku::setNumber(int num)
{
    if (selected[0] != -1){
        sudokuGrid[selected[0]][selected[1]]->setText(QString("%1").arg(num));
        gameBoard[selected[0]][selected[1]] = num + '0';
        checkSolution();
    }
}

void sudoku::makeMove(int row, int col) {
    char cellChar = gameBoard[row][col];
    if (cellChar == 'b') {
        if (sudokuGrid[row][col]->styleSheet() == SUDOKUWRONG)
            sudokuGrid[row][col]->setStyleSheet(SUDOKUSELECTWRONG);
        else
            sudokuGrid[row][col]->setStyleSheet(SUDOKUSELECT);

        if (selected[0]!=-1) {
            if (sudokuGrid[selected[0]][selected[1]]->styleSheet() == SUDOKUSELECT)
                sudokuGrid[selected[0]][selected[1]]->setStyleSheet(SUDOKU);
            else if (sudokuGrid[selected[0]][selected[1]]->styleSheet() == SUDOKUSELECTWRONG)
                sudokuGrid[selected[0]][selected[1]]->setStyleSheet(SUDOKUWRONG);
        }
        selected[0] = row;
        selected[1] = col;
    }
}

void sudoku::checkSolution()
{
    bool win = true;

    if (gameBoard[selected[0]][selected[1]] !=easySolution[selected[0]][selected[1]]) {
        win = false;
        sudokuGrid[selected[0]][selected[1]]->setStyleSheet(SUDOKUWRONG);
        gameBoard[selected[0]][selected[1]] = 'b';
    }
    else
        sudokuGrid[selected[0]][selected[1]]->setStyleSheet(SUDOKU);

    for (int i = 0; win && i < 9; i++)
        for (int j = 0; win && j < 9; j++)
        {
            if (gameBoard[i][j]!=easySolution[i][j])
            {
                win = false;
            }
        }

    if (win == true)
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                QMessageBox msgBox;
                msgBox.setText("YOU WIN!!! Great Job!");
                msgBox.setInformativeText("Do you want to play again?");
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                msgBox.setDefaultButton(QMessageBox::No);
                int ret = msgBox.exec();

                switch(ret){
                case QMessageBox::Yes:
                    on_resetButton_released();
                    break;
                case QMessageBox::No:
                    on_resetButton_released();
                    emit returnToMain();
                    break;
                default:
                    break;
                }
            }
    }
}

sudoku::~sudoku()
{

    delete [] sudokuGrid;
    delete ui;
}

void sudoku::on_resetButton_released()
{
    for (int i = 0; i<9; i++)
        for (int j = 0; j <9; j++) {
            sudokuGrid[i][j]->setStyleSheet(SUDOKU);
            sudokuGrid[i][j]->setText(QString(""));
            gameBoard[i][j] = 'b';
        }

    std::ifstream sudBoard;
    int value, row, col;

    sudBoard.open("sudokuboardeasy.txt");

    bool sudokuboard = true;

    while(sudokuboard)
    {
        while (!sudBoard.eof() && sudBoard.peek() != 'v')
            sudBoard.get();

        if (sudBoard.eof())
            sudokuboard = false;
        if (sudBoard.peek() == 'v'){
            for (int i=0;i<6;i++) {
                sudBoard.get();
            }
                sudBoard >> value;
                sudBoard.get();
                sudBoard >> row;
                sudBoard.get();
                sudBoard >> col;

                sudokuGrid[row-1][col-1]->setText(QString("%1").arg(value));
                sudokuGrid[row-1][col-1]->setStyleSheet(SUDOKUVALUE);
                gameBoard[row-1][col-1] = 'v';

        }
    }

    sudBoard.close();
}

void sudoku::on_mainScreen_released()
{
    emit returnToMain();
}

void sudoku::on_pushButton_1_released()
{
    emit sendButtonClicked(1);
}

void sudoku::on_pushButton_2_released()
{
    emit sendButtonClicked(2);
}
void sudoku::on_pushButton_3_released()
{
    emit sendButtonClicked(3);
}

void sudoku::on_pushButton_4_released()
{
    emit sendButtonClicked(4);
}

void sudoku::on_pushButton_5_released()
{
    emit sendButtonClicked(5);
}

void sudoku::on_pushButton_6_released()
{
    emit sendButtonClicked(6);
}
void sudoku::on_pushButton_7_released()
{
    emit sendButtonClicked(7);
}
void sudoku::on_pushButton_8_released()
{
    emit sendButtonClicked(8);
}
void sudoku::on_pushButton_9_released()
{
    emit sendButtonClicked(9);
}
