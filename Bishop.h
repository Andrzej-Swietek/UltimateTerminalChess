
#ifndef ULTIMATETERMINALCHESS_BISHOP_H
#define ULTIMATETERMINALCHESS_BISHOP_H
#include <iostream>
#include <vector>
#include "Field.h"
using namespace std;

class Bishop: public Field {
    int x=0; int y=0;
    int x0=0; int y0=0;
    bool color;
    string type = "Bishop";
public:
    Bishop( int x, int y, int x0, int y0, bool color);
    ~Bishop();
};




#endif //ULTIMATETERMINALCHESS_BISHOP_H
