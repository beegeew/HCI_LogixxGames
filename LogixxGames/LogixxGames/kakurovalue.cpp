#include "includes.h"

kakuroValue::kakuroValue()
{
    value = 0;
    row = 0;
    column = 0;
}

kakuroValue::kakuroValue(int *v, int *r, int *c)
{
    value = *v;
    row = *r;
    column = *c;
}

kakuroValue::~kakuroValue()
{}

kakuroValue& kakuroValue::operator =(const kakuroValue &rhs)
{
    if (this != &rhs)
    {
        column = rhs.column;
        row = rhs.row;
        value = rhs.value;
    }

    return *this;
}

void kakuroValue::setValue(int* v)
{
    value = *v;
}

void kakuroValue::setRow(int* r)
{
    row = *r;
}

void kakuroValue::setColumn(int* c)
{
    column = *c;
}

int kakuroValue::getRow()
{
    return row;
}

int kakuroValue::getColumn()
{
    return column;
}

int kakuroValue::getValue()
{
    return value;
}

std::istream& operator>>(std::istream &in, kakuroValue &cell)
{
    for (int i = 0; i < 6; i++)
        in.get();
    in >> cell.value;
    in.get();
    in >> cell.row;
    in.get();
    in >> cell.column;

    while (in.peek() != 'v')
        in.get();

    return in;
}
