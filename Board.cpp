#include <iostream>
#include <string>
using namespace std;
#include <typeinfo>
#include "Board.h"
#include "Pawn.h"
#include "Queen.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
Board::Board(){
    for( int i= 0 ; i< 8; i++){
        vector<Field> tmp;
        for( int j= 0 ; j< 8; j++){
           if(i==1 || i==6) {
               tmp.push_back(Pawn(j, i, j, i, (i > 4)));
               tmp[j].name = "P";
           }
           else if((i == 0 || i == 7) && (j == 0 || j == 7) ){
               tmp.push_back(Rook(j, i, j, i, (i > 4)));
               tmp[j].name = "R";
           }
           else if((i==0 || i==7) && (j==1 || j==6)){
               tmp.push_back(Knight(j, i, j, i, (i > 4)));
               tmp[j].name = "N";
           }
           else if((i==0 || i==7)&&(j==2 || j==5)){
               tmp.push_back(Bishop(j, i, j, i, (i > 4)));
               tmp[j].name = "B";
           }
           else if((i==0 && j==3)||(i==7 && j==3)){
               tmp.push_back(Queen(j, i, j, i, (i > 4)));
               tmp[j].name = "Q";
           }
           else if((i==0 && j==4)||(i==7 && j==4)){
               tmp.push_back(King(j, i, j, i, (i > 4)));
               tmp[j].name = "K";
           }
           else{
               tmp.push_back(Field(j,i));
               tmp[j].name = " ";
           }

        }
        fields.push_back(tmp);
    }
}


Board::~Board(){
    cout << "Board destroyed" <<endl;
}
void Board::turn(string move) {

    if ( move.find("-") == string::npos ) { cout << "Wrong Format" <<endl;return; }
    if ( move.length() != 5 ) { cout << "Wrong Format" <<endl;return; }
    string co = move.substr(0, move.find("-"));
    string gdzie = move.substr(move.find("-")+1, move.length());
    cout << co << "    |   " << gdzie <<endl;
    //cout<<fields[int(co[1])][int(co[0])-int('a')].name;
}
void Board::print() {

    int a = 0;
     for( vector<Field>row : fields ) {

         for ( Field f : row )
         {


            if(a % 8 == 0) cout <<endl<< "-----------------------------------" <<endl;
            if ( a % 8 == 0) cout << "|| ";
            if(a%8!=7)
                cout << f.name + " | " ; // TODO : dorobić dla kazdej klasy pole nazwa
            if ( a % 8 == 7) cout <<f.name + " ||";
             a++;
         }

   }
    cout <<endl<< "-----------------------------------" <<endl;
}
