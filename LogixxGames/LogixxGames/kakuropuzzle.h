#ifndef CROSSSUMPUZZLE_H
#define CROSSSUMPUZZLE_H

#include "includes.h"

class kakuroPuzzle
{
    friend ostream& operator<<(ostream&,const kakuroPuzzle&);
    friend istream& operator>>(istream&, kakuroPuzzle&);

public:
    kakuroPuzzle(int);
    ~kakuroPuzzle();

    bool inputHead(int*,int*,int*,int*,char*);
    bool removeHead(int*,int*,char*);
    bool isSolvable() {return solvable;}
    istream& inputPuzzle(istream&);

    void solve();
    bool validValue(int*,int*,int*);
    char cellType(int*,int*);


    int  getHeadValue(int*,int*,char*);
    int  getValue(int*,int*);
    int getHeadLength(int*,int*,char*);

private:
    bool isValidHead(int,int);
    bool found(int,int,char,int&);

    char** cells;               //Have values of b for blank, h for head, and v for value
    kakuroValue* csValues;    //Storage of values for the puzzle
    kakuroHead* csHeads;      //Storage of heads for the puzzle
    int size;                   //Puzzle will be of a size n by n, where n = size
    int numHeads;               //We need to keep track of the # of hints to properly number the hints
    int numValues;              //to help us keep track of the number of values found
    bool solvable;              //If this is set to false by the solve() function, then the user will be notified
};

#endif // CROSSSUMPUZZLE_H
