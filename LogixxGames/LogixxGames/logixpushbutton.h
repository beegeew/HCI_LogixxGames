#ifndef LOGIXPUSHBUTTON_H
#define LOGIXPUSHBUTTON_H

#include <QPushButton>

class logixPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit logixPushButton(QWidget *parent = 0);
    logixPushButton(QWidget*,int,int);
    ~logixPushButton();

    logixPushButton &operator=(const logixPushButton& rhs);

    //accessors
    int getRow();
    int getCol();

public slots:
    void emitClicked();

signals:
    void buttonClicked(const int& outRow, const int& outCol);

private:
    int row;
    int col;
};

#endif // LOGIXPUSHBUTTON_H
