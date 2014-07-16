#ifndef AKARI_H
#define AKARI_H

#include <string>
#include <QWidget>
#include <QImage>
#include <QMessageBox>
#include "logixpushbutton.h"

namespace Ui {
    class akari;
}

class akari : public QWidget
{
    Q_OBJECT

public:
    explicit akari(QWidget *parent = 0);
    ~akari();

public slots:
    void placeMarker(int, int);

private slots:
    void on_mainScreen_released();

    void on_resetButton_released();

    void on_randomBoard_released();

signals:
    void returnToMain();

private:
    Ui::akari *ui;
    char gameBoard[8][8];
    std::string currentFile;
    QImage *QPics[10];
    std::string fileNames[5];
    logixPushButton *akariGrid[8][8];
    void getBoard();
    void checkSolution();
    void clearBoard();
    void highlight(int,int);
    void unHighlight(int,int);
};

#endif // AKARI_H
