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
        string where = move.substr(move.find("-") + 1, move.length());
        cout << what << "    |   " << where << endl;

        string sWhatY = &what[1];
        int whatY = stoi(sWhatY) - 1;
        int whatX = 7-(int(what[0]) - int('a'));

        cout << "[ Chosen Piece ]: " << fields[whatY][whatX].name << endl;

        string sWhereY = &where[1];
        int whereY = stoi(sWhereY) - 1;
        int whereX = 7-(int(where[0]) - int('a'));

        if (whereX > 7 || whereX < 0 || whereY > 7 || whereY < 0) {
            cout << RED << "Wrong format." << RESET << endl;
            return;
        } else if (fields[whatY][whatX].name == "R") {
            if(whatX==whereX && whatY!=whereY)
            {
                int tmp_x = whatX;
                int tmp_y = whatY;
                int dY = (whatY > whereY) ? -1 : 1;
                tmp_y += dY;
                while(tmp_y!=whereY)
                {
                    if (fields[tmp_y][tmp_x].name != "E") {
                        cout << RED << "ERROR" << RESET << endl;
                        return;}
                    tmp_y += dY;
                }
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";

            }
            else if(whatX!=whereX && whatY==whereY)
            {
                int tmp_x = whatX;
                int tmp_y = whatY;
                int dX = (whatX > whereX) ? -1 : 1;
                tmp_x += dX;
                while(tmp_x!=whereX)
                {
                    if (fields[tmp_y][tmp_x].name != "E") {
                        cout << RED << "ERROR" << RESET << endl;
                        return;}
                    tmp_x += dX;
                }
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
            }
            else
            {
                cout << RED << "Wrong format" << RESET << endl;
                return;}


        } else if (fields[whatY][whatX].name == "N") {

            if(whereX-whatX==1 && whereY-whatY==2)
            {
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                return;}
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
            }
            else if(whereX-whatX==1 && whereY-whatY==-2)
            {
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return;}
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
            }
            else if(whereX-whatX==-1 && whereY-whatY==2)
            {
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return;}
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
            }
            else if(whereX-whatX==-1 && whereY-whatY==-2)
            {
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return;}
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
            }
            else if(whereX-whatX==2 && whereY-whatY==1)
            {
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return;}
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
            }
            else if(whereX-whatX==2 && whereY-whatY==-1)
            {
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return;}
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
            }
            else if(whereX-whatX==-2 && whereY-whatY==1)
            {
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return;}
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
            }
            else if(whereX-whatX==-2 && whereY-whatY==-1)
            {
                if(fields[whereY][whereX].name!="E" && fields[whereY][whereX].color==fields[whatY][whatX].color){
                    cout << RED << "ERROR" << RESET << endl;
                    return;}
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
            }
            else{
                cout << RED << "Wrong format" << RESET << endl;
                return;}


        } else if (fields[whatY][whatX].name == "B") {

            cout << whatY << endl;
            cout << whatX << endl;
            cout << whereY << endl;
            cout << whereX << endl;

            int tmp_x = whatX;
            int tmp_y = whatY;
            if (abs(whereX - whatX) != abs(whereY - whatY)) {
                cout << RED << "Wrong format" << RESET << endl;
                return;}
            else {
                int dX = (whatX > whereX) ? -1 : 1;
                int dY = (whatY > whereY) ? -1 : 1;
                tmp_x += dX;
                tmp_y += dY;
                while (tmp_x != whereX && tmp_y != whereY) {
                    if (fields[tmp_y][tmp_x].name != "E") {
                        cout << RED << "ERROR" << RESET << endl;
                        return;}
                tmp_x += dX;
                tmp_y += dY;}
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";

                }
    }

        else if (fields[ whatY ][ whatX ].name == "Q") {
            if(whatX==whereX && whatY!=whereY)
            {
                int tmp_x = whatX;
                int tmp_y = whatY;
                int dY = (whatY > whereY) ? -1 : 1;
                tmp_y += dY;
                while(tmp_y!=whereY)
                {
                    if (fields[tmp_y][tmp_x].name != "E") {
                        cout << RED << "ERROR" << RESET << endl;
                        return;}
                    tmp_y += dY;
                }
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";

            }
            else if(whatX!=whereX && whatY==whereY)
            {
                int tmp_x = whatX;
                int tmp_y = whatY;
                int dX = (whatX > whereX) ? -1 : 1;
                tmp_x += dX;
                while(tmp_x!=whereX)
                {
                    if (fields[tmp_y][tmp_x].name != "E") {
                        cout << RED << "ERROR" << RESET << endl;
                        return;}
                    tmp_x += dX;
                }
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";
            }
            else if(abs(whereX - whatX) == abs(whereY - whatY))
            {
                int tmp_x = whatX;
                int tmp_y = whatY;
                int dX = (whatX > whereX) ? -1 : 1;
                int dY = (whatY > whereY) ? -1 : 1;
                tmp_x += dX;
                tmp_y += dY;
                while (tmp_x != whereX && tmp_y != whereY) {
                    if (fields[tmp_y][tmp_x].name != "E") {
                        cout << RED << "ERROR" << RESET << endl;
                        return;}
                    tmp_x += dX;
                    tmp_y += dY;}
                fields[whereY][whereX] = fields[whatY][whatX];
                fields[whatY][whatX].name = "E";

            }
            else{
                cout << RED << "Wrong format" << RESET << endl;
                return;}



        } else if (fields[ whatY ][ whatX ].name == "K") {

        } else if (fields[ whatY ][ whatX ].name == "P") {
            /**
             * dir                               - direction up/down [int]
             * fields[ whatY + dir ][ whatX ]    - the field where we want to move
             * fields[ whatY ][ whatX ]          - the field with a piece we are moving
             */

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
    cout <<BOLDMAGENTA <<  "    | H | G | F | E | D | C | B | A |" << RESET;
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
    cout <<BOLDMAGENTA <<  "    | H | G | F | E | D | C | B | A |" << RESET <<endl;
}
