//
// Created by Grand on 2021-06-19.
//

#ifndef ULTIMATETERMINALCHESS_KING_H
#define ULTIMATETERMINALCHESS_KING_H
#include <iostream>
#include <vector>
using namespace std;

class King: public Field {
    int x, int y;
    int x0, int y0;
    bool color;
    string type = King;
public:
    King(int x, int y, int x0, int y0,bool color);
    ~King();
};


#endif //ULTIMATETERMINALCHESS_KING_H
