#include <iostream>
#include "Board.h"
using namespace std;
int main() {
    Board *board = new Board();
    cout<<board->fields[5][5].position().first;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
//  TODO: class Board, class Piece, class Pawn, class Figure: Kingg ,Queen, Bish, Rook, Knight