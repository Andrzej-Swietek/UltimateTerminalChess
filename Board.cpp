#include <iostream>
using namespace std;

#include "Board.h"
#include "Pawn.h"

Board::Board(){
    for( int i= 0 ; i< 8; i++){
        vector<Field> tmp;
        for( int j= 0 ; j< 8; j++){
            tmp.push_back(Pawn( j, i, j, i, (i > 4)));
        }
        fields.push_back(tmp);
    }
}


Board::~Board(){
    cout << "Board destroyed" <<endl;
}

void Board::print() {

     int a = 0;
     for( vector<Field>row : fields ) { 
         for ( auto f : row )
            if(a % 8 == 0) cout << "-------------------------------" <<endl;
            if ( a % 8 == 0) cout << "|| ";
//        cout << f.name + " | " ; // TODO : dorobić dla kazdej klasy pole nazwa
            if ( a % 8 == 7) cout << " ||";
         }
         a++;
   }

}
