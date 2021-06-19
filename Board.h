

#ifndef ULTIMATETERMINALCHESS_BOARD_H
#define ULTIMATETERMINALCHESS_BOARD_H
#include <iostream>
#include <vector>
#include "Field.h"

using namespace std;

class Board {
public:
     Board();
    ~Board();
    vector<vector<Field>>fields; // klasa pole - poli
    void print();
    void turn(); // tu będzie parametr jaki ruch
    bool checkmate= false;

};
#endif //ULTIMATETERMINALCHESS_BOARD_H
