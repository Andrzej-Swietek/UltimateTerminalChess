//
// Created by Grand on 2021-06-19.
//

#ifndef ULTIMATETERMINALCHESS_PAWN_H
#define ULTIMATETERMINALCHESS_PAWN_H
#include <iostream>
#include <vector>
using namespace std;

class Pawn: public Field {
    int x, int y;
    int x0, int y0;
    bool color;
    string type = Pawn;
    public:
    Pawn(int x, int y, int x0, int y0,bool color);
    ~Pawn();
};


#endif //ULTIMATETERMINALCHESS_PAWN_H
