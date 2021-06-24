#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;
#include <typeinfo>
#include "Board.h"
#include "Pawn.h"
#include "Queen.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Empty.h"

#include "colors.h"

Board::Board(){
    for( int i= 0 ; i< 8; i++){
        vector<Field> tmp;
        bool color = ( i >= 4 )? true : false;
        //cout << "KOLOR : " << color << endl;
        for( int j= 0 ; j< 8; j++){
           if(i==1 || i==6) {
               tmp.push_back(Pawn(j, i, j, i, color));
               tmp[j].name = "P";
               tmp[j].color = color;
           }
           else if((i == 0 || i == 7) && (j == 0 || j == 7) ){
               tmp.push_back(Rook(j, i, j, i, color));
               tmp[j].name = "R";
               tmp[j].color = color;
           }
           else if((i==0 || i==7) && (j==1 || j==6)){
               tmp.push_back(Knight(j, i, j, i, color));
               tmp[j].name = "N";
               tmp[j].color = color;
           }
           else if((i==0 || i==7)&&(j==2 || j==5)){
               tmp.push_back(Bishop(j, i, j, i, color));
               tmp[j].name = "B";
               tmp[j].color = color;
           }
           else if((i==0 && j==3)||(i==7 && j==3)){
               tmp.push_back(Queen(j, i, j, i, color));
               tmp[j].name = "Q";
               tmp[j].color = color;
           }
           else if((i==0 && j==4)||(i==7 && j==4)){
               tmp.push_back(King(j, i, j, i, color));
               tmp[j].name = "K";
               tmp[j].color = color;
           }
           else{
               tmp.push_back( Empty(j, i, j, i, color) );
               tmp[j].name = "E";
               tmp[j].color = color;
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
    else if ( move.length() != 5 ) { cout << "Wrong Format" <<endl;return; }
    else {
        string what = move.substr(0, move.find("-"));
        string where = move.substr(move.find("-")+1, move.length());
        cout << what << "    |   " << where << endl;

        string sWhatY = &what[1];
        int whatY = stoi(sWhatY)-1;
        int whatX = int(what[0]) - int('a');

//        cout << whatX <<"  "<< whatY << endl;
        cout<< "[ Chosen Piece ]: " <<fields[ whatY ][ whatX ].name << endl;


        if ( fields[ whatY ][ whatX ].name == "R" ){

        } else if (fields[ whatY ][ whatX ].name == "N") {

        } else if (fields[ whatY ][ whatX ].name == "B") {
            string sWhereY = &where[1];
            int whereY = stoi(sWhereY)-1;
            int whereX = int(where[0]) - int('a');
            if(whereX>7 || whereX<0 || whereY>7 || whereY<0){
                cout<<RED<<"Wrong format."<<RESET<<endl;
            }
            //int px=whatX;
            //int py=whatY;
            //bool czyWszystkoOk = false;



            cout<<whatY<<endl;
            cout<<whatX<<endl;
            cout<<whereY<<endl;
            cout<<whereX<<endl;

/* 1 cw
     cout << "CW1 "<<endl;
            while ( px < 7 && py > 0 ) {
                if(py==whereY && px==whereX){

                    czyWszystkoOk= true;
                    break;
                }
                else{
                    py--;
                    px++;
                }
            }
             px=whatX;
             py=whatY;
// 2 cw
            cout << "CW2 "<<endl;
            while ( px > 0 && py > 0 ) {
                if(px==whereX && py==whereY){
                    czyWszystkoOk= true;
                    break;
                }
                else{
                    px--;
                    py--;
                }
            }
             px=whatX;
             py=whatY;
// 3 cw
            cout << "CW3 "<<endl;
            while ( px > 0 && py < 7 ) {
                if(px==whereX && py==whereY){
                    czyWszystkoOk= true;
                    break;
                }
                else{
                    px--;
                    py++;
                }
            }
             px=whatX;
             py=whatY;
// 4 cw
            cout << "CW4 "<<endl;
            while ( px < 7 && py < 7 ) {
                if(px==whereX && py==whereY){
                    czyWszystkoOk= true;
                    break;
                }
                else{
                    px++;
                    py++;
                }
            }

            if(czyWszystkoOk==0 ){
                cout<<"Wrong format..."<<endl;
                return;
            }
*/

            int tmp_x = whatX;
            int tmp_y = whatY;
            if(abs(whereX-whatX)!=abs(whereY-whatY)){
                cout<<RED<<"Wrong format"<<RESET<<endl;
                return;
            }
            else{
                int dX = (whatX > whereX)? -1 : 1;
                int dY = (whatY > whereY)? -1 : 1;
                tmp_x += dX;   tmp_y += dY;
                while( tmp_x != whereX && tmp_y != whereY) {
                    if( fields[tmp_y][tmp_x].name != "E" ) {
                        cout << RED << "ERROR" << RESET << endl; return; }
                    tmp_x += dX;   tmp_y += dY;

                }
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";

            }

// Delta X i Y







        } else if (fields[ whatY ][ whatX ].name == "Q") {

        } else if (fields[ whatY ][ whatX ].name == "K") {

        } else if (fields[ whatY ][ whatX ].name == "P") {
            /**
             * dir                               - direction up/down [int]
             * fields[ whatY + dir ][ whatX ]    - the field where we want to move
             * fields[ whatY ][ whatX ]          - the field with a piece we are moving
             */

            string sWhereY = &where[1];
            int whereY = stoi(sWhereY)-1;
            int whereX = int(where[0]) - int('a');

            int dir = ( fields[ whatY ][ whatX ].color )? -1 : 1;
            cout << "[ move ]: " << fields[ whatY ][ whatX ].name << endl;
            if ( fields[ whereY ][ whereX ].name == "E" )
            {

                 // Podmianka pól
                    swap(fields[ whereY ][ whereX ],fields[ whatY ][ whatX ]);

                 cout << fields[ whereY ][ whereX ].name <<endl;
                 cout<<fields[whatY][whatX].name<<endl;
            }
        } else { cout << "No piece there" <<endl; }

    }


}
void Board::print() {
    cout <<BOLDMAGENTA <<  "    | A | B | C | D | E | F | G | H |" << RESET;
    int a = 0;
    for( vector<Field>row : fields ) {

        for ( Field f : row )
        {
            if(a % 8 == 0) cout <<endl<<BOLDMAGENTA<< "-----------------------------------------" <<RESET<<endl;
            if ( a % 8 == 0) cout << "| "<< a/8+1 << " | ";
            if (f.name != "E"){
                if (f.color == true) cout << RED;
                else if (f.color != true) cout << GREEN;
            }
            if (f.name == "E") cout << "E";
            else cout << f.name;
            cout << RESET;
            if( a % 8 != 7) cout << " | " ;
            if ( a % 8 == 7) cout << " | "<< a/8+1 << " | ";
            a++;
        }

    }
    cout <<endl<< BOLDMAGENTA << "-----------------------------------------"<< RESET <<endl;
    cout <<BOLDMAGENTA <<  "    | A | B | C | D | E | F | G | H |" << RESET <<endl;
}
