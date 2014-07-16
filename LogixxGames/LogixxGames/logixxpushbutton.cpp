#include "logixxpushbutton.h"
#include <QPushButton>

class logixxPushButtonData : public QPushButton {
public:
};

logixxPushButton::logixxPushButton(int incRow, int incCol) {
    row = incRow;
    col = incCol;
}

logixxPushButton::logixxPushButton()
{
    row = 0;
    col = 0;
}

int logixxPushButton::getCol()
{
    return col;
}

int logixxPushButton::getRow()
{
    return row;
}

void logixxPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    logixxPushButton::mouseReleaseEvent(e);

    emit buttonClicked(row, col);
}

logixxPushButton::~logixxPushButton()
{
}
