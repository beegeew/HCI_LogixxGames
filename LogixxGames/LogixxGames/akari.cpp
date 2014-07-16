#include "akari.h"
#include "ui_akari.h"
#include "fstream"
#include "ctime"
#include <string>
#include <QDebug>

akari::akari(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::akari)
{
    ui->setupUi(this);

    QPics[0] = new QImage(":/tictacblank");
    QPics[1] = new QImage(":/lamp");
    QPics[2] = new QImage(":/zero");
    QPics[3] = new QImage(":/one");
    QPics[4] = new QImage(":/two");
    QPics[5] = new QImage(":/three");
    QPics[6] = new QImage(":/four");
    QPics[7] = new QImage(":/random");
    QPics[8] = new QImage(":/highlight");
    QPics[9] = new QImage(":/akariwin");

    fileNames[0] = "board1.txt";
    fileNames[1] = "board2.txt";
    fileNames[2] = "board3.txt";
    fileNames[3] = "board4.txt";
    fileNames[4] = "board5.txt";

    srand(time(0));
    getBoard();
}

void akari::getBoard()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            akariGrid[i][j] = new logixPushButton(this,i,j);
            connect(akariGrid[i][j],SIGNAL(buttonClicked(int,int)),this,SLOT(placeMarker(int, int)));
            akariGrid[i][j]->setIcon(QPixmap::fromImage((*QPics[0])));
            akariGrid[i][j]->setIconSize(QSize(64,64));
            akariGrid[i][j]->resize(QPics[0]->size());
            ui->akariLayout->addWidget(akariGrid[i][j],i,j);
            gameBoard[i][j] = 'b';
        }

    std::ifstream board;
        int value, row, col;

    currentFile = fileNames[rand() % 5];
    const char* newCstr = currentFile.c_str();

    board.open(newCstr);

    bool test = true;
    while(test)
    {
        while (!board.eof() && board.peek() != 'v')
            board.get();
        if (board.eof())
            test = false;
        if (board.peek() =='v'){
            for (int i=0;i<6;i++) {
                board.get();
            }
                board >> value;
                board.get();
                board >> row;
                board.get();
                board >> col;
                akariGrid[row-1][col-1]->setIcon(QPixmap::fromImage(*QPics[value+2]));
                gameBoard[row-1][col-1] = 'v';
        }
       }

       board.close();
}

void akari::placeMarker(int row, int col) {
    char cellChar = gameBoard[row][col];
    if ((cellChar == 'b')||(cellChar == 'h')) {
        (*akariGrid[row][col]).setIcon(QPixmap::fromImage((*QPics[1])));
        gameBoard[row][col] = 'o';
        highlight(row,col);
    }

    else if (cellChar == 'v'){
        gameBoard[row][col] = 'v';
    }

    else {
            (*akariGrid[row][col]).setIcon(QPixmap::fromImage((*QPics[0])));
            gameBoard[row][col] = 'b';
            unHighlight(row,col);
    }

    checkSolution();
}

void akari::checkSolution()
{
    bool win = true;

    char solution1[8][8] =
                          {{'h','o','h','h','h','v','o','h'},
                           {'o','v','v','h','h','h','h','o'},
                           {'h','o','h','h','h','h','v','h'},
                           {'v','h','h','o','v','o','h','h'},
                           {'h','h','o','v','o','h','h','v'},
                           {'o','v','h','o','h','h','h','h'},
                           {'h','o','h','h','h','v','v','o'},
                           {'h','h','v','h','h','o','h','h'}};

    char solution2[8][8] =
                           {{'o','h','h','h','h','h','h','h'},
                            {'v','h','o','v','o','h','h','h'},
                            {'o','h','h','h','h','h','h','h'},
                            {'h','h','h','v','h','h','o','v'},
                            {'h','o','v','h','v','h','h','o'},
                            {'h','h','h','o','h','h','h','v'},
                            {'h','v','h','h','h','o','h','h'},
                            {'h','o','h','v','o','h','h','h'}};

    char solution3[8][8] =
                           {{'h','h','o','h','h','h','v','o'},
                            {'h','o','v','o','h','h','h','h'},
                            {'v','h','o','h','v','v','o','h'},
                            {'h','h','h','v','o','h','h','h'},
                            {'o','v','v','h','h','o','v','h'},
                            {'h','h','o','h','v','h','o','h'},
                            {'v','o','h','h','h','h','h','h'},
                            {'o','h','h','h','h','h','h','h'}};

    char solution4[8][8] =
                           {{'o','v','o','h','h','h','v','h'},
                            {'h','o','v','h','o','v','h','h'},
                            {'h','h','h','v','v','v','o','h'},
                            {'h','h','h','o','v','v','v','o'},
                            {'v','h','o','h','v','o','h','v'},
                            {'o','h','h','v','o','h','h','h'},
                            {'h','h','v','h','h','h','o','h'},
                            {'v','h','o','h','h','h','v','o'}};

    char solution5[8][8] =
                           {{'h','h','o','h','v','v','o','v'},
                            {'o','h','v','o','h','h','h','h'},
                            {'v','h','o','h','h','h','h','h'},
                            {'o','h','h','h','v','o','h','h'},
                            {'v','o','h','h','h','h','v','o'},
                            {'v','h','h','v','h','h','o','h'},
                            {'h','h','h','h','o','v','h','h'},
                            {'o','v','h','h','h','o','h','h'}};

    if(currentFile == "board1.txt")
    {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                if ((gameBoard[i][j]!=solution1[i][j]))
                {
                    win = false;
                    goto stop;
                }
            }
    }

    if(currentFile == "board2.txt")
    {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                if ((gameBoard[i][j]!=solution2[i][j]))
                {
                    win = false;
                    goto stop;
                }
            }
    }

    if(currentFile == "board3.txt")
    {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                if ((gameBoard[i][j]!=solution3[i][j]))
                {
                    win = false;
                    goto stop;
                }
            }
    }

    if(currentFile == "board4.txt")
    {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                if ((gameBoard[i][j]!=solution4[i][j]))
                {
                    win = false;
                    goto stop;
                }
            }
    }

    if(currentFile == "board5.txt")
    {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                if ((gameBoard[i][j]!=solution5[i][j]))
                {
                    win = false;
                    goto stop;
                }
            }
    }

    if (win == true)
    {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                if (gameBoard[i][j] == 'h'||gameBoard[i][j] == 'b')
                {
                    (*akariGrid[i][j]).setIcon(QPixmap::fromImage((*QPics[9])));
                }
            }
    }
    stop:
    ;
}

void akari::on_mainScreen_released()
{
    QMessageBox msgBox;
    msgBox.setText("Returning to main screen...");
    msgBox.setInformativeText("Are you sure you want to quit? Your current game will be discarded.");
    msgBox.setStandardButtons(QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret = msgBox.exec();

    switch(ret){
    case QMessageBox::Discard:
    {
        delete **akariGrid;
        getBoard();
        emit returnToMain();
    }
        break;
    case QMessageBox::Cancel:
        break;
    default:
        break;
    }
}

void akari::clearBoard()
{
    for (int i = 0; i<8; i++)
        for (int j = 0; j <8; j++) {
            if(gameBoard[i][j]=='o')
            {
                akariGrid[i][j]->setIcon(QPixmap::fromImage((*QPics[0])));
                gameBoard[i][j] = 'b';
            }

            if(gameBoard[i][j]=='h')
            {
                akariGrid[i][j]->setIcon(QPixmap::fromImage((*QPics[0])));
                gameBoard[i][j] = 'b';
            }
        }
}

akari::~akari()
{
    delete **akariGrid;
    delete ui;
}

void akari::on_resetButton_released()
{
    clearBoard();
}

void akari::highlight(int row, int col)
{
    int x = row;
    int y = col;

    while((x>=0)&&(x<7)&&(gameBoard[x+1][y]!='v')&&(gameBoard[x+1][y]!='o'))
    {
        (*akariGrid[x+1][y]).setIcon(QPixmap::fromImage((*QPics[8])));
        gameBoard[x+1][y] = 'h';
        x++;
    }

    x = row;

    while((x>0)&&(x<=7)&&(gameBoard[x-1][y]!='v')&&(gameBoard[x-1][y]!='o'))
    {
        (*akariGrid[x-1][y]).setIcon(QPixmap::fromImage((*QPics[8])));
        gameBoard[x-1][y] = 'h';
        x--;
    }

    x = row;

    while((y>=0)&&(y<7)&&(gameBoard[x][y+1]!='v')&&(gameBoard[x][y+1]!='o'))
    {
        (*akariGrid[x][y+1]).setIcon(QPixmap::fromImage((*QPics[8])));
        gameBoard[x][y+1] = 'h';
        y++;
    }

    y = col;

    while((y>0)&&(y<=7)&&(gameBoard[x][y-1]!='v')&&(gameBoard[x][y-1]!='o'))
    {
        (*akariGrid[x][y-1]).setIcon(QPixmap::fromImage((*QPics[8])));
        gameBoard[x][y-1] = 'h';
        y--;
    }
}

void akari::unHighlight(int row, int col)
{
    int x = row;
    int y = col;

    while((x>=0)&&(x<7)&&(gameBoard[x+1][y]!='v')&&(gameBoard[x+1][y]!='o'))
    {
        (*akariGrid[x+1][y]).setIcon(QPixmap::fromImage((*QPics[0])));
        gameBoard[x+1][y] = 'b';
        x++;
    }

    x = row;

    while((x>0)&&(x<=7)&&(gameBoard[x-1][y]!='v')&&(gameBoard[x-1][y]!='o'))
    {
        (*akariGrid[x-1][y]).setIcon(QPixmap::fromImage((*QPics[0])));
        gameBoard[x-1][y] = 'b';
        x--;
    }

    x = row;

    while((y>=0)&&(y<7)&&(gameBoard[x][y+1]!='v')&&(gameBoard[x][y+1]!='o'))
    {
        (*akariGrid[x][y+1]).setIcon(QPixmap::fromImage((*QPics[0])));
        gameBoard[x][y+1] = 'b';
        y++;
    }

    y = col;

    while((y>0)&&(y<=7)&&(gameBoard[x][y-1]!='v')&&(gameBoard[x][y-1]!='o'))
    {
        (*akariGrid[x][y-1]).setIcon(QPixmap::fromImage((*QPics[0])));
        gameBoard[x][y-1] = 'b';
        y--;
    }

    y = col;

    for (int a = 0; a<8; a++)
        for (int b = 0; b<8; b++)
        {
            if(gameBoard[a][b] == 'o')
                highlight(a,b);
        }
}

void akari::on_randomBoard_released()
{
    std::string lastBoard = currentFile;
    delete **akariGrid;

    getBoard();
    if(lastBoard==currentFile)
    {
        while(lastBoard==currentFile)
        {
            delete **akariGrid;
            getBoard();
        }
    }
}
