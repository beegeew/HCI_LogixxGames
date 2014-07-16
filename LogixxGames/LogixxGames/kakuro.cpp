#include "kakuro.h"
#include "ui_kakuro.h"
#include "kakurohead.h"
#include "includes.h"
#include <QDesktopServices>
#include <QUrl>
#include <QDateTime>
#include <QMessageBox>

#define KAKUROHINT "min-width:32px; min-height: 32px;color: rgb(255,255,255);background-color: rgb(0,0,0);border: 1px solid #ffffff"
#define KAKUROVALUE "font: 15px;font-weight:bold;min-width:32px; min-height: 32px;color: rgb(0,0,127);background-color: rgb(255,255,255);border: 1px solid #000000"
#define KAKUROWRONG "font: 15px;font-weight:bold;min-width:32px; min-height: 32px;color: rgb(255,0,0);background-color: rgb(255,255,255);border: 1px solid #000000"
#define KAKUROSELECT "font: 15px;font-weight:bold;min-width:32px; min-height: 32px;color: rgb(0,0,127);background-color: rgb(255,255,255);border: 1px solid #f4c50a"

kakuro::kakuro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kakuro)
{
    ui->setupUi(this);

    QRect * rectSetup = new QRect(0,0,450,450);

    kPuz = new kakuroPuzzle(14);

    ui->kakuroLayout->setGeometry((*rectSetup));

    connect(this,SIGNAL(numButtonClicked(int)),this,SLOT(changeCellValue(int)));

    for (int i = 0; i<14; i++)
        for (int j = 0; j <14; j++) {
            kakuroCells[i][j] = new logixPushButton(this,i,j);
            connect(kakuroCells[i][j],SIGNAL(buttonClicked(int,int)),this,SLOT(selectCell(int, int)));
            kakuroCells[i][j]->setStyleSheet(KAKUROHINT);
            ui->kakuroLayout->addWidget(kakuroCells[i][j],i,j);
            gameBoard[i][j] = 'v';
        }

    cellSelected = false;
    inPlay = false;
    gameMode = 'e';

    if (gameMode == 'e')
        gameModeVerbose = "Easy";
    else if (gameMode == 'm')
        gameModeVerbose = "Medium";
    else
        gameModeVerbose = "Hard";

    ui->gameInfoLabel->setText(QString("The game mode is set to %1\nHit play now to start the game!").arg(gameModeVerbose));
    score = 0;
}

kakuro::~kakuro()
{
    delete [] kakuroCells;
    delete kPuz;
    delete ui;
}

void kakuro::selectCell(int row, int col)
{
    if (gameBoard[row][col] != 'v')
        return;

    if (cellSelected) {
        kakuroCells[selectedCell[0]][selectedCell[1]]->setStyleSheet(KAKUROVALUE);
    }
    cellSelected = true;
    selectedCell[0] = row; selectedCell[1] = col;
    kakuroCells[row][col]->setStyleSheet(KAKUROSELECT);
}

void kakuro::changeCellValue(int newValue) {

    if (!inPlay || !cellSelected)
        return;

    bool winGame = true;

    if (newValue != kPuz->getValue(&selectedCell[0],&selectedCell[1]))
        kakuroCells[selectedCell[0]][selectedCell[1]]->setStyleSheet(KAKUROWRONG);
    else{
        kakuroCells[selectedCell[0]][selectedCell[1]]->setStyleSheet(KAKUROSELECT);
        winGame = false;
    }
    kakuroCells[selectedCell[0]][selectedCell[1]]->setText(QString("%1").arg(newValue));

    checkWin();
}

void kakuro::checkWin() {
    bool winGame = true;

    for(int i = 0; winGame && i < 14; i++)
        for (int j = 0; j < 14; j++) {
            if (gameBoard[i][j] == 'v' && kPuz->getValue(&i,&j) != kakuroCells[i][j]->text().toInt())
                winGame = false;
        }

    if (winGame)
        gameWon();
}

void kakuro::gameWon() {
    emit stopClock();
    inPlay = false;
    ui->promptWindow->setVisible(true);
    ui->winLabel->setText(QString("You won!\nYour score was %1.").arg(score));
}

void kakuro::receiveScore(int incScore) {
    score = incScore;
}

void kakuro::modeChanged(char newMode) {
    if (inPlay)
        return;

    gameMode = newMode;
    if (gameMode == 'e')
        gameModeVerbose = "Easy";
    else if (gameMode == 'm')
        gameModeVerbose = "Medium";
    else
        gameModeVerbose = "Hard";

    ui->gameInfoLabel->setText(QString("The game mode is set to %1\nHit play now to start the game!").arg(gameModeVerbose));
}

void kakuro::loadHints() {
     int i,j,k,vr,vc,lr,lc;
     char dr = 'r',dc = 'c';

     for (i = 0; i<14;i++)
         for(j = 0; j<14;j++)
         {
             if((kPuz->cellType(&i,&j)) == 'h'){
                 gameBoard[i][j] = 'h';
                 vr = (kPuz->getHeadValue(&i,&j,&dr));
                 lr = (kPuz->getHeadLength(&i,&j,&dr));
                 vc = (kPuz->getHeadValue(&i,&j,&dc));
                 lc = (kPuz->getHeadLength(&i,&j,&dc));

                 if(vr != 0 && vc != 0)
                     kakuroCells[i][j]->setText(QString("%1\\%2").arg(vc).arg(vr));
                 else if (vr == 0 && vc != 0)
                     kakuroCells[i][j]->setText(QString("%1\\N").arg(vc));
                 else if (vr != 0 && vc == 0)
                     kakuroCells[i][j]->setText(QString("N\\%1").arg(vr));
                 if (vr != 0)
                     for(k = j+1; k<= j+lr; k++){
                         kakuroCells[i][k]->setStyleSheet(KAKUROVALUE);
                 } else if (vc != 0)
                     for(k = i+1; k<= i+lc; k++){
                         kakuroCells[i][j]->setStyleSheet(KAKUROVALUE);
                     }
             }
         }
     kPuz->solve();
}

void kakuro::drawBoard() {
    char cellType;
    for (int i = 0; i < 14; i++)
        for (int j = 0; j < 14; j++) {
            cellType = gameBoard[i][j] = kPuz->cellType(&i,&j);
            if (cellType == 'h' || cellType == 'b')
                kakuroCells[i][j]->setStyleSheet(KAKUROHINT);
            else
                kakuroCells[i][j]->setStyleSheet(KAKUROVALUE);
        }
}

void kakuro::on_returnMain_released()
{
    QMessageBox msgBox;
    msgBox.setText("Return to main screen.");
    msgBox.setInformativeText("Are you sure you want to quit? \nAll progress will be lost!");
    msgBox.setStandardButtons(QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret = msgBox.exec();

    switch(ret){
        case QMessageBox::Discard:
        {
            on_reset_released();
            emit returnToMain();
        }
            break;
            case QMessageBox::Cancel:
                break;
            default:
                break;
        }
}

void kakuro::on_one_released()
{
    emit numButtonClicked(1);
}

void kakuro::on_two_released()
{
    emit numButtonClicked(2);
}

void kakuro::on_three_released()
{
    emit numButtonClicked(3);
}

void kakuro::on_four_released()
{
    emit numButtonClicked(4);
}

void kakuro::on_five_released()
{
    emit numButtonClicked(5);
}

void kakuro::on_six_released()
{
    emit numButtonClicked(6);
}

void kakuro::on_seven_released()
{
    emit numButtonClicked(7);
}

void kakuro::on_eight_released()
{
    emit numButtonClicked(8);
}

void kakuro::on_nine_released()
{
    emit numButtonClicked(9);
}

void kakuro::on_reset_released()
{
    delete kPuz;
    kPuz = new kakuroPuzzle(14);

    for (int i = 0; i<14; i++)
        for (int j = 0; j <14; j++) {
            kakuroCells[i][j] = new logixPushButton(this,i,j);
            connect(kakuroCells[i][j],SIGNAL(buttonClicked(int,int)),this,SLOT(selectCell(int, int)));
            kakuroCells[i][j]->setStyleSheet(KAKUROHINT);
            kakuroCells[i][j]->setText("");
            kakuroCells[i][j]->setIconSize(QSize(32,32));
            ui->kakuroLayout->addWidget(kakuroCells[i][j],i,j);
            gameBoard[i][j] = 'v';
        }

    inPlay = false;
}

void kakuro::on_solve_released()
{
    //showing all the values;
    for (int i = 0; i < 14; i++)
        for (int j = 0; j < 14; j++) {
            if (kPuz->cellType(&i,&j) == 'v') {
                kakuroCells[i][j]->setText(QString("%1").arg(kPuz->getValue(&i,&j)));
                kakuroCells[i][j]->setStyleSheet(KAKUROVALUE);
            }
        }

    emit usedSolve(10000);
    checkWin();
}

void kakuro::on_hint_released()
{
    int randHint = randNum(654987);
    int row, col;
    bool success = false;
    while (!success && inPlay) {
        row = randHint/14;
        col = randHint%14;

        if (gameBoard[row][col] == 'v' && kakuroCells[row][col]->text() == "") {
            success = true;
            kakuroCells[row][col]->setText(QString("%1").arg(kPuz->getValue(&row,&col)));
        }
        if (randHint == 195)
            randHint = 0;
        else
            randHint++;
    }

    if (gameMode == 'e')
        emit usedHint(100);
    else if (gameMode == 'm')
        emit usedHint(75);
    else
        emit usedHint(50);

    checkWin();
}

int kakuro::randNum(int seed) {
    QTime now = QTime::currentTime();
    qsrand (now.msec()+ seed );
    return qrand() %195;
}

void kakuro::on_howToPlay_released()
{
    QDesktopServices::openUrl(QUrl("http://www.kakuro.com/howtoplay.php"));
}

void kakuro::on_playNowButton_released()
{
    ui->promptWindow->setVisible(false);

    on_reset_released();

    std::ifstream readPuzzle;

    if (gameMode == 'e')
        readPuzzle.open("kareasy.lp");
    else if (gameMode == 'm')
        readPuzzle.open("karmed.lp");
    else if (gameMode == 'h')
        readPuzzle.open("karhard.lp");

    kPuz->inputPuzzle(readPuzzle);

    readPuzzle.close();

    loadHints();
    drawBoard();

    inPlay = true;
    emit startClock();
    ui->promptWindow->setVisible(false);
}
