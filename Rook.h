//
// Created by Grand on 2021-06-19.
//

#ifndef ULTIMATETERMINALCHESS_ROOK_H
#define ULTIMATETERMINALCHESS_ROOK_H
#include <iostream>
#include <vector>
#include "Field.h"

using namespace std;


class Rook: public Field {
    int x=0;
    int y=0;
    int x0=0;
    int y0=0;
    bool color;
    string type = "Rook";
public:
    Rook( int x, int y, int x0, int y0, bool color);

    ~Rook();
};
#endif //ULTIMATETERMINALCHESS_ROOK_H
