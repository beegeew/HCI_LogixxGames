#include "includes.h"

using std::ostream;

kakuroHead::kakuroHead()
{
    value = -1;
    row = -1;
    column = -1;
    length = -1;
    direction = 'n';
    id = -1;
}

kakuroHead::kakuroHead(int * val, int * r, int * c, int * len,
                           char * dir, int * idIn)
{
    value = *val;
    row = *r;
    column = *c;
    length = *len;
    direction = *dir;
    id = *idIn;
}

kakuroHead::kakuroHead(const kakuroHead &rhs):
    value(rhs.value), row(rhs.row), column(rhs.column), length(rhs.length), direction(rhs.direction),
    id(rhs.id)
{}

kakuroHead::~kakuroHead() {}

void kakuroHead::setValue(int *v)
{
    value = *v;
}

void kakuroHead::setRow(int *r)
{
    row = *r;
}

void kakuroHead::setColumn(int *c)
{
    column = *c;
}

void kakuroHead::setLength(int *l)
{
    length = *l;
}

void kakuroHead::setDirection(char *d)
{
    direction = *d;
}

void kakuroHead::setId(int *i)
{
    id = *i;
}

int kakuroHead::getValue()
{
    return value;
}

int kakuroHead::getRow()
{
    return row;
}

int kakuroHead::getColumn()
{
    return column;
}

int kakuroHead::getLength()
{
    return length;
}

char kakuroHead::getDirection()
{
    return direction;
}

int kakuroHead::getId()
{
    return id;
}

ostream& operator <<(ostream &out, const kakuroHead &head)
{
    out <<"head(" << head.value << ',' << head.row << ','
        << head.column << ',' << head.length << ',' << head.direction
        << ',' << head.id << ").\n";

    return out;
}

kakuroHead& kakuroHead::operator =(const kakuroHead &rhs)
{
    if (this != &rhs)
    {   value = rhs.value;
        row = rhs.row;
        column = rhs.column;
        length = rhs.length;
        direction = rhs.direction;
        id = rhs.id;
    }

    return *this;
}
