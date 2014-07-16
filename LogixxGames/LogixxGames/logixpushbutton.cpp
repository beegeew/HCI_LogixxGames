#include "logixpushbutton.h"
#include <QDebug>

logixPushButton::logixPushButton(QWidget *parent) :
    QPushButton(parent)
{
    row = 0;
    col = 0;
    connect(this,SIGNAL(clicked()),this,SLOT(emitClicked()));
}

logixPushButton::logixPushButton(QWidget *parent,int incRow, int incCol) :
    QPushButton(parent)
{
    row = incRow;
    col = incCol;
    connect(this,SIGNAL(clicked()),this,SLOT(emitClicked()));
}

int logixPushButton::getCol()
{
    return col;
}

int logixPushButton::getRow()
{
    return row;
}

void logixPushButton::emitClicked() {
    emit buttonClicked(row, col);
}

logixPushButton &logixPushButton::operator=(const logixPushButton& rhs)
{
    if (this != &rhs)
    {
        row = rhs.row;
        col = rhs.col;
    }

    return *this;
}

logixPushButton::~logixPushButton()
{
}
