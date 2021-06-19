//
// Created by Grand on 2021-06-19.
//

#ifndef ULTIMATETERMINALCHESS_KNIGHT_H
#define ULTIMATETERMINALCHESS_KNIGHT_H
#include <iostream>
#include <vector>
using namespace std;

class Knight: public Field {
    int x, int y;
    int x0, int y0;
    bool color;
    string type = Knight;
public:
    Knight(int x, int y, int x0, int y0,bool color);
    ~Knight();
};


#endif //ULTIMATETERMINALCHESS_KNIGHT_H
