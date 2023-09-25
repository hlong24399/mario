
#include "Position.h"
#include <iostream>
using namespace std;


Position::Position()
{
    r = 0;
    c = 0;
}

Position::Position(int r, int c)
{
    this->r = r;
    this->c = c;
}

void Position::setPosition(int r, int c)
{
    this->r = r;
    this->c = c;
}

int Position::getRow()
{
    return r;
}

int Position::getCol()
{
    return c;
}

void Position::print()
{
    cout << "(" << r << ", " << c << ")" << endl;
}
