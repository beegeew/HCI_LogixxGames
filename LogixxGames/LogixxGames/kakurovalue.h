#ifndef CROSSSUMVALUE_H
#define CROSSSUMVALUE_H

#include "includes.h"

using std::istream;

class kakuroValue
{
    friend istream& operator>>(istream &in, kakuroValue &cell);

public:
    kakuroValue();
    kakuroValue(int*, int*, int*);
    ~kakuroValue();

    kakuroValue &operator=(const kakuroValue& rhs);

    void setValue(int*);
    void setRow(int*);
    void setColumn(int*);

    int getValue();
    int getRow();
    int getColumn();

private:
    int value;
    int row;
    int column;
};

#endif // CROSSSUMVALUE_H
