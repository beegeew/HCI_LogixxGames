#include "gamehub.h"
#include "ui_gamehub.h"
#include <QDebug>

gameHub::gameHub(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameHub)
{
    ui->setupUi(this);

    ui->Easy->setChecked(true);

    mainButtons = new mainScreen();
    mainButtons->setPalette(this->palette());
    ticTacGame = new ticTacToe();
    ticTacGame->setPalette(this->palette());
    kakuroGame = new kakuro();
    kakuroGame->setPalette(this->palette());
    sudokuGame = new sudoku();
    sudokuGame->setPalette(this->palette());
    akariGame = new akari();
    akariGame->setPalette(this->palette());

    ui->gamePages->insertWidget(1,mainButtons);
    ui->gamePages->addWidget(akariGame);
    ui->gamePages->addWidget(kakuroGame);
    ui->gamePages->addWidget(sudokuGame);
    ui->gamePages->addWidget(ticTacGame);
    ui->gamePages->setCurrentIndex(1);

    connect(mainButtons,SIGNAL(clickedButton(int,int)),this,SLOT(loadNewModule(int,int)));
    connect(ticTacGame, SIGNAL(returnToMain()),this,SLOT(loadMain()));
    connect(kakuroGame, SIGNAL(returnToMain()),this,SLOT(loadMain()));
    connect(sudokuGame, SIGNAL(returnToMain()),this,SLOT(loadMain()));
    connect(akariGame, SIGNAL(returnToMain()), this, SLOT(loadMain()));
    connect(this,SIGNAL(setMode(char)),ticTacGame,SLOT(modeChanged(char)));
    connect(this, SIGNAL(setMode(char)),kakuroGame,SLOT(modeChanged(char)));
    connect(kakuroGame,SIGNAL(startClock()),this,SLOT(startTimer()));
    connect(kakuroGame,SIGNAL(stopClock()),this,SLOT(stopTimer()));
    connect(this,SIGNAL(sendScore(int)),kakuroGame,SLOT(receiveScore(int)));
    connect(kakuroGame,SIGNAL(usedHint(int)),this,SLOT(hintUpdateScore(int)));
    connect(kakuroGame,SIGNAL(usedSolve(int)),this,SLOT(hintUpdateScore(int)));

    scoreTimer = new QTimer(this);
    scoreTimer->connect(scoreTimer, SIGNAL(timeout()), this, SLOT(updateScore()));
    scoreTimer->stop();

    gameInPlay = 'n';
    gameMode = 'e';

    ui->score->setVisible(false);
}

void gameHub::loadNewModule(int row, int col)
{
    if ( row == 0 && col == 0) {
        gameInPlay = 'a';
        ui->gamePages->setCurrentIndex(2);
    } else if (row == 0 && col == 1) {
        gameInPlay = 'k';
        ui->gamePages->setCurrentIndex(3);
    } else if (row == 1 && col == 0) {
        gameInPlay = 's';
        ui->gamePages->setCurrentIndex(4);
    } else if (row == 1 && col == 1) {
        gameInPlay = 't';
        ui->gamePages->setCurrentIndex(5);
    }
}

void gameHub::loadMain()
{
    ui->gamePages->setCurrentIndex(1);
    scoreTimer->stop();
    gameInPlay = 'n';
    ui->score->setVisible(false);
}

void gameHub::updateScore()
{
    if (currScore == 0)
        return;

    switch (gameMode)
    {
    case 'e': currScore-=5;
        break;
    case 'm': currScore-=3;
        break;
    case 'h': currScore-=1;
        break;
    default:
        break;
    }

    ui->score->display(currScore);
}

void gameHub::hintUpdateScore(int pointsLost) {
    if (pointsLost == 10000 || (currScore - pointsLost <= 0))
        currScore = 0;
    else
        currScore-=pointsLost;

    ui->score->display(currScore);
}

void gameHub::startTimer()
{
    scoreTimer->start(1000);
    currScore = 10000;
    ui->score->setVisible(true);
    ui->score->display(currScore);

}

void gameHub::stopTimer()
{
    scoreTimer->stop();
    emit sendScore(currScore);
}

gameHub::~gameHub()
{
    delete ticTacGame;
    delete mainButtons;
    delete kakuroGame;
    delete sudokuGame;
    delete akariGame;
    delete ui;
}

void gameHub::on_setMode_released()
{
    if (ui->Easy->isChecked()) {
        gameMode = 'e';
    } else if (ui->Medium->isChecked()) {
        gameMode = 'm';
    } else if (ui->Hard->isChecked()) {
        gameMode = 'h';
    }

    emit setMode(gameMode);
}
