#ifndef CROSSSUMHEAD_H
#define CROSSSUMHEAD_H

#include "includes.h"

using std::ostream;

class kakuroHead
{
    friend ostream& operator <<(ostream &os,const kakuroHead &head);
public:
    kakuroHead();
    kakuroHead(int*, int*, int*, int*, char*, int*);
    kakuroHead(const kakuroHead&);
    ~kakuroHead();

    //assignment
    kakuroHead &operator=(const kakuroHead &rhs);

    //mutators
    void setValue(int*);
    void setRow(int*);
    void setColumn(int*);
    void setLength(int*);
    void setDirection(char*);
    void setId(int*);

    //accessors
    int getValue();
    int getRow();
    int getColumn();
    int getLength();
    char getDirection();
    int getId();

private:
    int value;
    int row;
    int column;
    int length;
    char direction;
    int id;
};

#endif // CROSSSUMHEAD_H
