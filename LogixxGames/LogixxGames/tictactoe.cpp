#include "tictactoe.h"
#include "ui_tictactoe.h"
#include <time.h>
#include <QDateTime>
#include <QDebug>

#define TICTACTOEBUTTON "color: rgb(0, 0, 127);background-color: rgb(255, 255, 255); min-width:135px;max-width:135;min-height:135px;min-width:135px;font-size:85px;border: 2px solid #000000;"
#define TICTACWIN "color: rgb(0, 0, 127);background-color: rgb(139, 255, 139); min-width:135px;max-width:135;min-height:135px;min-width:135px;font-size:85px;border: 2px solid #000000;"

#define PLAYERSELECTBUTTON "color: rgb(255,255,255);color: rgb(0,0,127);"
#define PLAYERSELECTPRESSED "color: rgb(191, 191, 255);background-color: rbg(0,0,0);"

ticTacToe::ticTacToe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ticTacToe)
{
    ui->setupUi(this);

    QRect * rectSetup = new QRect(0,0,450,450);

    ui->ticTacToeLayout->setGeometry((*rectSetup));

    currBoard = 0;
    playerChar = 'X';
    gameInPlay = false;
    gameMode = 'e';

    if (gameMode == 'e')
        gameModeVerbose = "Easy";
    else if (gameMode == 'm')
        gameModeVerbose = "Medium";
    else
        gameModeVerbose = "Hard";

    ui->currPlayerPiece->setText(QString("%1").arg(playerChar));
    ui->gameInfoLabel->setText(QString("Your piece is currently: %1\n\nThe game mode is set to %2\nHit play now to start the game!").arg(playerChar).arg(gameModeVerbose));

    for (int k = 0; k <10; k++) {
        for (int i = 0; i<3; i++)
            for (int j = 0; j <3; j++) {
                ticTacToeGrid[i][j] = new logixPushButton(this,i,j);
                connect(ticTacToeGrid[i][j],SIGNAL(buttonClicked(int,int)),this,SLOT(makeMove(int, int)));
                ticTacToeGrid[i][j]->setText("");
                ticTacToeGrid[i][j]->setStyleSheet(TICTACTOEBUTTON);
                ui->ticTacToeLayout->addWidget(ticTacToeGrid[i][j],i,j);
                gameBoard[k][i][j] = 'b';
            }
    }

    movesMade = 0;

    ui->whoGoesLabel->setText("");
}

void ticTacToe::makeMove(int row, int col) {
    //player only function
    if (!gameInPlay)
        return;
    if (gameBoard[currBoard][row][col] != 'b')
        return;

    char cellChar = gameBoard[currBoard][row][col];
    if (cellChar == 'b') {
        (*ticTacToeGrid[row][col]).setText(QString("%1").arg(playerChar));
        gameBoard[currBoard][row][col] = playerChar;
        checkMove(playerChar,row,col);
    }
    if (gameInPlay)
        makeCompMove();
}

void ticTacToe::executeCompMove(int row, int col) {
    //computer only function
    char cellChar = gameBoard[currBoard][row][col];

    char compPiece;

    if (playerChar == 'X')
        compPiece = 'O';
    else
        compPiece = 'X';

    if (cellChar == 'b') {
        incBoard();
        (*ticTacToeGrid[row][col]).setText(QString("%1").arg(compPiece));
        gameBoard[currBoard][row][col] = compPiece;
        checkMove(compPiece,row,col);
    }
}

void ticTacToe::checkMove(char pieceMoved, int row, int col)
{
    movesMade++;

    incBoard();
    bool checkDiags = false, win = false;
    int cells[] = {0,0,0,0,0,0};

    if (gameBoard[currBoard][1][1] == pieceMoved)
        checkDiags = true;

    if (checkDiags == true)
    {
        //check each diagonal separately
        if (gameBoard[currBoard][0][0] == gameBoard[currBoard][1][1] && gameBoard[currBoard][1][1] == gameBoard[currBoard][2][2] &&
                gameBoard[currBoard][2][2] == pieceMoved) {
            win = true;
            cells[0] = 0, cells[1] = 0, cells[2] = 1, cells[3] = 1, cells[4] = 2, cells[5] = 2;
        }
        if (!win && gameBoard[currBoard][0][2] == gameBoard[currBoard][1][1] && gameBoard[currBoard][1][1] == gameBoard[currBoard][2][0] &&
                gameBoard[currBoard][2][0] == pieceMoved) {
            win = true;
            cells[0] = 0, cells[1] = 2, cells[2] = 1, cells[3] = 1, cells[4] = 2, cells[5] = 0;
        }
    }
    if (!win && gameBoard[currBoard][0][col] == gameBoard[currBoard][1][col] && gameBoard[currBoard][1][col] == gameBoard[currBoard][2][col] &&
            gameBoard[currBoard][2][col] == pieceMoved) {
        win = true;
        cells[0] = 0, cells[1] = col, cells[2] = 1, cells[3] = col, cells[4] = 2, cells[5] = col;
    }
    if (!win && gameBoard[currBoard][row][0] == gameBoard[currBoard][row][1] && gameBoard[currBoard][row][1] == gameBoard[currBoard][row][2] &&
            gameBoard[currBoard][row][2] == pieceMoved) {
        win = true;
        cells[0] = row, cells[1] = 0, cells[2] = row, cells[3] = 1, cells[4] = row, cells[5] = 2;
    }

    if (win) {
        (*ticTacToeGrid[cells[0]][cells[1]]).setStyleSheet(TICTACWIN);
        (*ticTacToeGrid[cells[2]][cells[3]]).setStyleSheet(TICTACWIN);
        (*ticTacToeGrid[cells[4]][cells[5]]).setStyleSheet(TICTACWIN);
        if (pieceMoved == playerChar)
            ui->winLabel->setText("You win!");
        else
            ui->winLabel->setText("Computer wins!");
        gameInPlay = false;
        ui->promptWindow->setVisible(true);
    }
    if (movesMade == 9 && !win)
    {
        ui->winLabel->setText("Cat Won. :(");
        gameInPlay = false;
        ui->promptWindow->setVisible(true);
    }
}

void ticTacToe::on_mainScreen_released()
{
    on_resetButton_released();
    emit returnToMain();
}

void ticTacToe::makeCompMove()
{
    int possMoves[3][3];
    int maxScore = -1, maxRow = 0, maxCol = 0;
    int randMove = randNum(randNum(randNum(9)))%9;
    bool movePossible = false;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            possMoves[i][j] = -1;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (gameBoard[currBoard][i][j] == 'b') {
                possMoves[i][j] = 1;
                movePossible = true;
            }

    if (gameMode == 'e' && movePossible) {
        while (maxScore <0) {
            if (randMove > 8)
                randMove = 0;
            maxRow = randMove /3;
            maxCol = randMove %3;
            if ( possMoves[maxRow][maxCol] == 1)
                maxScore = 5;
            else
                randMove++;
        }
    }   else if (gameMode == 'm' && movePossible) {
        if (gameBoard[currBoard][1][1] == 'b') {
            maxRow = 1;
            maxCol = 1;
            maxScore = 500;
        } for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                if (possMoves[i][j] > -1) {
                    possMoves[i][j] = scoreCompMove(i,j,1);
                } if (possMoves[i][j] > maxScore) {
                    maxRow = i;
                    maxCol = j;
                    maxScore = possMoves[i][j];
                }
            }
        while (maxScore <5) {
            if (randMove > 8)
                randMove = 0;
            maxRow = randMove /3;
            maxCol = randMove %3;
            if ( possMoves[maxRow][maxCol] == 1)
                maxScore = 5;
            else
                randMove++;
        }
    } else if (movePossible){
        if (gameBoard[currBoard][1][1] == 'b') {
            maxRow = 1;
            maxCol = 1;
            maxScore = 500;
        }
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                if (possMoves[i][j] > -1) {
                    possMoves[i][j] = scoreCompMove(i,j,3);
                } if (possMoves[i][j] > maxScore) {
                    maxRow = i;
                    maxCol = j;
                    maxScore = possMoves[i][j];
                }
            }
    }
    if (maxScore > 0)
        executeCompMove(maxRow,maxCol);
    if (!movePossible)
    {
        ui->winLabel->setText("Cat Won. :(");
        gameInPlay = false;
        ui->promptWindow->setVisible(true);
    }
}

int ticTacToe::scoreCompMove(int row, int col, int iter)
{
    iter--;
    incBoard();
    int score = 1;
    char compColor;
    bool checkDiags;
    char storeCurrentValue = gameBoard[currBoard][row][col];

    if (playerChar == 'X')
        compColor = gameBoard[currBoard][row][col] = 'O';
    else
        compColor = gameBoard[currBoard][row][col] = 'X';

    if (gameBoard[currBoard][1][1] == compColor)
        checkDiags = true;

    if (checkDiags == true)
    {
        //check each diagonal separately
        if (gameBoard[currBoard][0][0] == gameBoard[currBoard][1][1] && gameBoard[currBoard][1][1] == gameBoard[currBoard][2][2] &&
                gameBoard[currBoard][2][2] == compColor) {
            score+=10;
        }
        if (gameBoard[currBoard][0][2] == gameBoard[currBoard][1][1] && gameBoard[currBoard][1][1] == gameBoard[currBoard][2][0] &&
                gameBoard[currBoard][2][0] == compColor) {
            score+=10;
        }
    }
    if (gameBoard[currBoard][0][col] == gameBoard[currBoard][1][col] && gameBoard[currBoard][1][col] == gameBoard[currBoard][2][col] &&
            gameBoard[currBoard][2][col] == compColor) {
        score+=10;
    }
    if (gameBoard[currBoard][row][0] == gameBoard[currBoard][row][1] && gameBoard[currBoard][row][1] == gameBoard[currBoard][row][2] &&
            gameBoard[currBoard][row][2] == compColor) {
        score+=10;
    }

    if (iter > 0) {
        char currPlayerChar = playerChar;
        int possMoves[3][3];
        int maxScore;

        if (playerChar == 'X')
            playerChar = 'O';
        else
            playerChar = 'X';

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                possMoves[i][j] = -1;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                if (gameBoard[currBoard][i][j] == 'b') {
                    possMoves[i][j] = scoreCompMove(i,j,iter);
                }
                if (possMoves[i][j] > maxScore) {
                    maxScore = possMoves[i][j];
                }
            }
        if (iter % 2 == 0)
            score-=maxScore;
        else
            score+=maxScore;

        playerChar = currPlayerChar;
    }
    gameBoard[currBoard][row][col] = storeCurrentValue;
    currBoard--;
    return score;
}

void ticTacToe::incBoard()
{
    if ( currBoard < 9){
        currBoard++;
        for (int j = 0; j < 3; j++)
             for (int k = 0; k < 3; k++)
                gameBoard[currBoard][j][k] = gameBoard[currBoard-1][j][k];
    } else if (currBoard == 9) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    gameBoard[i][j][k] = gameBoard[i+1][j][k];
    }
}

void ticTacToe::modeChanged(char newMode)
{
    if (!gameInPlay) {
        gameMode = newMode;
        if (gameMode == 'e')
            gameModeVerbose = "Easy";
        else if (gameMode == 'm')
            gameModeVerbose = "Medium";
        else
            gameModeVerbose = "Hard";
        gameMode = newMode;
        ui->gameInfoLabel->setText(QString("Your piece is currently: %1\n\nThe game mode is set to %2\nHit play now to start the game!").arg(playerChar).arg(gameModeVerbose));
    }
}

ticTacToe::~ticTacToe()
{
    delete **ticTacToeGrid;
    delete ui;
}

void ticTacToe::resetBoard()
{
    for (int k = 0; k <10; k++) {
        for (int i = 0; i<3; i++)
            for (int j = 0; j <3; j++) {
                ticTacToeGrid[i][j]->setStyleSheet(TICTACTOEBUTTON);
                ticTacToeGrid[i][j]->setText("");
                gameBoard[k][i][j] = 'b';
            }
    }
    movesMade = 0;
}

void ticTacToe::on_resetButton_released()
{
    resetBoard();

    gameInPlay = false;
    ui->promptWindow->setVisible(true);
}

void ticTacToe::on_playerX_released()
{
    if (!gameInPlay) {
        ui->playerX->setDown(true);
        ui->playerO->setDown(false);
        playerChar = 'X';
        ui->currPlayerPiece->setText(QString("%1").arg(playerChar));
        ui->gameInfoLabel->setText(QString("Your piece is currently: %1\n\nThe game mode is set to %2\nHit play now to start the game!").arg(playerChar).arg(gameModeVerbose));
    }
}

void ticTacToe::on_playerO_released()
{
    if (!gameInPlay) {
        ui->playerO->setDown(true);
        ui->playerX->setDown(false);
        playerChar = 'O';
        ui->currPlayerPiece->setText(QString("%1").arg(playerChar));
        ui->gameInfoLabel->setText(QString("Your piece is currently: %1\n\nThe game mode is set to %2\nHit play now to start the game!").arg(playerChar).arg(gameModeVerbose));
    }
}

void ticTacToe::on_playNowButton_released()
{
    ui->promptWindow->setVisible(false);
    gameInPlay = true;
    ui->winLabel->setText("");
    resetBoard();

    int whoGoes;
    whoGoes = randNum(randNum(randNum(randNum(500))));

    if ( whoGoes % 2 == 0) {
        makeCompMove();
        ui->whoGoesLabel->setText("Computer won roll\nto play first.");
    } else
        ui->whoGoesLabel->setText("You won roll\nto play first.");
}

int ticTacToe::randNum( int num)
{
    QTime now = QTime::currentTime();
    qsrand (now.msec()+ num );
    return qrand();
}
