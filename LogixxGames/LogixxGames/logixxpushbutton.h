#ifndef LOGIXXPUSHBUTTON_H
#define LOGIXXPUSHBUTTON_H

#include <QPushButton>

class logixxPushButtonData;

class logixxPushButton : public QPushButton
{
    Q_OBJECT
public:
    logixxPushButton();
    logixxPushButton(int,int);
    ~logixxPushButton();

    //accessors
    int getRow();
    int getCol();

public slots:
    void mouseReleaseEvent(QMouseEvent *e);

signals:
    void buttonClicked(const int& outRow, const int& outCol);

private:
    int row;
    int col;
};

#endif // LOGIXXPUSHBUTTON_H
