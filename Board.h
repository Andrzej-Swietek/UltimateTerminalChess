//
// Created by Grand on 2021-06-19.
//

#ifndef ULTIMATETERMINALCHESS_BOARD_H
#define ULTIMATETERMINALCHESS_BOARD_H
#include <iostream>
#include <vector>
using namespace std;

class Board {
public:
    Board();
    ~Board();
    vector<vector<Field>>fields; // klasa pole - poli
    void print();
    void turn(); // tu będzie parametr jaki ruch

};
#endif //ULTIMATETERMINALCHESS_BOARD_H
