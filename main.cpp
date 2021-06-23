#include <iostream>
#include "Board.h"
#include <cstdlib>
using namespace std;

void getinput(Board *b){
    string move = "";
    cout<<"White turn:"<<endl;

        cin>>move;

    getchar();
    b->turn(move);
    system("clear");
    b->print();
    if(!b->checkmate){
        getinput(b);
    }

}
int main() {
    Board *board = new Board();
    board->print();
    getinput(board);

    //cout<<board->fields[5][5].position().first;

    return 0;
}
//  TODO: class Board, class Piece, class Pawn, class Figure: Kingg ,Queen, Bish, Rook, Knight