#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QGroupBox>
#include <QPushButton>
#include <QWidget>
#include <QImage>
#include "logixpushbutton.h"

namespace Ui {
    class mainScreen;
}

class mainScreen : public QGroupBox
{
    Q_OBJECT

public:
    explicit mainScreen(QWidget *parent = 0);
    ~mainScreen();

public slots:
    void detectButtonClicked(int i, int j);

signals:
    void clickedButton(const int & row, const int & col);

private:
    Ui::mainScreen *ui;
    QImage *QPics[4];
    logixPushButton *buttonGrid[3][2];
};

#endif // MAINSCREEN_H
