//
// Created by Grand on 2021-06-19.
//

#ifndef ULTIMATETERMINALCHESS_QUEEN_H
#define ULTIMATETERMINALCHESS_QUEEN_H
#include <iostream>
#include <vector>
using namespace std;

class Queen: public Field {
    int x, int y;
    int x0, int y0;
    bool color;
    string type = Queen;
public:
    Queen(int x, int y, int x0, int y0,bool color);
    ~Queen();
};



#endif //ULTIMATETERMINALCHESS_QUEEN_H
