#include "mainscreen.h"
#include "ui_mainscreen.h"
#include <QImage>
#include <QDebug>

#define MAINSCREENBUTTON "min-width:300px; min-height:225px; background-color: rgb(0, 0, 127);color: rgb(255, 255, 255);font-size: 25px"

mainScreen::mainScreen(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::mainScreen)
{
    ui->setupUi(this);


    QPics[0] = new QImage(":/tictac");
    QPics[1] = new QImage(":/sudokuIcon");
    QPics[2] = new QImage(":/kakuross");
    QPics[3] = new QImage(":/akari");



    for (int i = 0; i<2; i++)
        for (int j = 0; j < 2; j++) {
            buttonGrid[i][j] = new logixPushButton(this,i,j);
            connect(buttonGrid[i][j],SIGNAL(buttonClicked(int,int)),this,SLOT(detectButtonClicked(int, int)));
            buttonGrid[i][j]->setStyleSheet(MAINSCREENBUTTON);
            ui->buttonGridLayout->addWidget(buttonGrid[i][j],i,j);
        }
    buttonGrid[0][0]->setIcon(QPixmap::fromImage((*QPics[3])));
    buttonGrid[0][0]->setIconSize(QSize(300,225));
    buttonGrid[0][1]->setIcon(QPixmap::fromImage((*QPics[2])));
    buttonGrid[0][1]->setIconSize(QSize(300,225));
    buttonGrid[1][0]->setIcon(QPixmap::fromImage((*QPics[1])));
    buttonGrid[1][0]->setIconSize(QSize(300,225));
    buttonGrid[1][1]->setIcon(QPixmap::fromImage((*QPics[0])));
    buttonGrid[1][1]->setIconSize(QSize(300,225));

}

void mainScreen::detectButtonClicked(int row, int col) {
    emit clickedButton(row,col);
}

mainScreen::~mainScreen()
{
    delete [] QPics;
    delete **buttonGrid;
    delete ui;
}
