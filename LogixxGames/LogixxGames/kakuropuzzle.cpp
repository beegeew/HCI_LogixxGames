#include "includes.h"

kakuroPuzzle::kakuroPuzzle(int s)
{
    size = s;
    cells = new char*[size];

    for ( int i = 0; i < size; i++)
        cells[i] = new char[size];

    for (int i = 0; i < size; i++)
         for (int j = 0; j < size; j++)
            cells[i][j] = 'b';


    csHeads = new kakuroHead[100];
    csValues = new kakuroValue[size*size];

    solvable = false;
    numHeads = 0, numValues = 0;
}

kakuroPuzzle::~kakuroPuzzle()
{
    delete [] cells;
    delete [] csValues;
    delete [] csHeads;
}

void kakuroPuzzle::solve()
{
    std::ofstream out;
    out.open("cpuz.txt");
    out << *this;
    out.close();

    system("clingo karlogic.lp cpuz.txt | mkatoms > out.txt");

    std::ifstream in;
    in.open("out.txt");
    in >> *this;
    in.close();
}

std::istream& kakuroPuzzle::inputPuzzle(std::istream& in)

{
    int curInt, row, col;
    char curChar;
    bool test = true;

    if (in.eof())
        return in;

    while (test) {

        while(!in.eof() && in.peek() != 'h')
        {   in.get();}

        if (in.eof())
             test = false;
        else if(in.peek() == 'h'){
            numHeads++;
            for (int i = 0; i<5;i++)
               in.get();

            //We now read in the head and set all of it's attributes
            in >> curInt;
            csHeads[numHeads].setValue(&curInt);
            in.get();
            in >> curInt;
            row = curInt;
            csHeads[numHeads].setRow(&curInt);
            in.get();
            in >> curInt;
            col = curInt;
            csHeads[numHeads].setColumn(&curInt);
            in.get();
            in >> curInt;
            csHeads[numHeads].setLength(&curInt);
            in.get();
            in >> curChar;
            csHeads[numHeads].setDirection(&curChar);
            csHeads[numHeads].setId(&numHeads);
            cells[row][col] = 'h';
            }
    }

    return in;
}

char kakuroPuzzle::cellType(int* r, int* c)
{
    return cells[*r][*c];
}

bool kakuroPuzzle::inputHead(int* v, int* r, int* c, int* l, char* d)
{

    if (numHeads == 100 || cells[*r][*c] == 'v' || !isValidHead(*v,*l) ||
            (*d == 'r' && *r == 0) || (*d == 'c' && *c == 0))
        return false;
    else if (*d == 'r' && ((*c + *l) >= size || *r < 0 || *l < 2 || *c < 0 || *c > size) )
        return false;
    else if (*d == 'c' && ((*r + *l) >= size || *c < 0 || *l < 2 || *r < 0 || *r > size) )
        return false;
    else if (*d == 'r')
        for (int i = *c+1; i <= (*c + *l); i++)
            if (cells[*r][i] == 'h')
                return false;
    else if (*d == 'c')
        for (int i = *c+1; i <= (*r + *l); i++)
            if (cells[i][*c] == 'h')
                return false;

    int i;
    kakuroHead *tempHead;

    if (cells[*r][*c] == 'b')
    {
        numHeads++;
        tempHead = new kakuroHead(v,r,c,l,d, &numHeads);
        csHeads[numHeads] = *tempHead;
        cells[*r][*c] = 'h';
        delete tempHead;
    }
    else if (found(*r,*c,*d,i) && cells[*r][*c] == 'h')
    {
        tempHead = new kakuroHead(v,r,c,l,d,&i);
        csHeads[i] = *tempHead;
        delete tempHead;
    } else if (cells[*r][*c] == 'h')
    {
        numHeads++;
        tempHead = new kakuroHead(v,r,c,l,d,&numHeads);
        csHeads[numHeads] = *tempHead;
        delete tempHead;
    }

    if (*d == 'r')
        for (int i = *c+1; i <= (*c + *l); i++)
            cells[*r][i] = 'v';
    else if (*d == 'c')
        for (int i = *c+1; i <= (*r + *l); i++)
            cells[i][*c] = 'v';
    return true;
}

bool kakuroPuzzle::isValidHead(int v, int l)
{
    if(l == 2 && v >= 3 && v <=17)
        return true;
    if(l == 3 && v >= 6 && v <=24)
        return true;
    if(l == 4 && v >= 10 && v <=30)
        return true;
    if(l == 5 && v >= 15 && v <=35)
        return true;
    if(l == 6 && v >= 21 && v <=39)
        return true;
    if(l == 7 && v >= 28 && v <=42)
        return true;
    if(l == 8 && v >= 36 && v <=44)
        return true;
    if(l == 9 && v >= 45 && v <=45)
        return true;
    return false;
}

bool kakuroPuzzle::found(int r, int c, char d, int &index)
{
    for (int i = 0; i < numHeads; i++)
    {
        if (csHeads[i].getRow() == r && csHeads[i].getColumn() == c && csHeads[i].getDirection() == d)
        {
            index = i;
            return true;
        }
    }
    return false;
}

bool kakuroPuzzle::removeHead(int *r, int*c, char *d)
{
    int i = 0;
    char f;
    if (*d == 'c')
        f = 'r';
    else
        f = 'c';

    if (found(*r,*c,*d,i))
    {
        if (!found(*r,*c,f,i))
            cells[*r][*c] = 'b';
        if (numHeads > 0)
        {
            csHeads[i] = csHeads[numHeads];
            csHeads[i].setId(&i);
            numHeads--;
            return true;
        }
    }
    return false;
}

bool kakuroPuzzle::validValue(int *v, int *r, int *c)
{
    if (cells[*r][*c] != 'v' || !isSolvable())
        return false;
    else
    {
        for (int i = 0; i <= numValues; i++)
            if (csValues[i].getValue() == *v && csValues[i].getRow() == *r && csValues[i].getColumn() == *c)
                return true;
    }
    return false;
}

int kakuroPuzzle::getHeadValue(int *r, int *c, char *d)
{
    int id =0;

    if(found(*r,*c,*d,id))
        return csHeads[id].getValue();

    return 0;
}

int kakuroPuzzle::getHeadLength(int *r, int *c, char *d)
{
    int id = 0;

    if(found(*r,*c,*d,id))
        return csHeads[id].getLength();

    return 0;
}

int kakuroPuzzle::getValue(int *r, int *c)
{
    if (cells[*r][*c] == 'v'){
        for(int i = 0; i<=size*size; i++)
            if(*r == csValues[i].getRow() && *c == csValues[i].getColumn())
                return csValues[i].getValue();
    }
    else
        return 0;
    return 0;
}

ostream& operator<< (ostream& out, const kakuroPuzzle& cpuz)
{
    out << "row(1.." << cpuz.size-1 << ").\n";
    out << "col(1.." << cpuz.size-1 << ").\n";
    out << "num(1..9).\n";

    int i;
    for (i = 1; i <= cpuz.numHeads;i++)
         out << (cpuz.csHeads[i]);

    out << "head(0,0,0,0,0,0).";
    return out;
}

std::istream& operator>> (std::istream& in, kakuroPuzzle& cpuz)

{
    int v, r, c;
    kakuroValue *tempCsValue;
    if (in.peek() == ':' || in.peek() == '*')
    {
        cpuz.solvable = false;
        return in;
    }
    else
        while (in.peek() == 'v')

        {
            for (int i = 0; i < 6; i++)
                in.get();

            in >> v;
            in.get();
            in >> r;
            in.get();
            in >> c;

            tempCsValue = new kakuroValue(&v,&r,&c);
            cpuz.cells[r][c] = 'v';
            cpuz.csValues[cpuz.numValues] = *tempCsValue;
            delete tempCsValue;
            cpuz.numValues++;

            while (in.peek() != 'v' && in.peek() != ':')
                in.get();
         }

    cpuz.solvable = true;

    return in;
}
