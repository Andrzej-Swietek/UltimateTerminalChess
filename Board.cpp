#include <iostream>
using namespace std;

#include "Board.h"

Board::Board(){

}

Board::~Board(){
    cout << "Board destroyed" <<endl;
}

void Board::print() {


    //    for( char a: this.boardArr ) { // nwm jak chcemy tego boarda przechowywacczy objekty w wektorze czy chary
//        if(a % 8 == 0) cout << "-------------------------------" <<endl;
//        if ( a % 8 == 0) cout << "|| ";
//        cout << a + " | " ;
//        if ( a % 8 == 7) cout << " ||";
//    }

}