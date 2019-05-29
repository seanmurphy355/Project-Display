
#include "ant.hpp"
#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
using std :: cin;
using std :: cout;
using std :: endl; 

// didnt think it was logical to break these functions up into cpp and hpp files

Ant::Ant (int x, int y){
this->x = x;
this->y = y;
ori = 0;
//inti values / ants intial ori is north ie 0
}
//use if user picks location
Ant::Ant(){
    this -> x = 0;
    this -> y = 0;
ori = 0;
} // random location
// moveant moves ant around the board takes in ant sensitive info

void Ant::moveant(int **&board, int row, int col){
    if (board[y][x] == ' '){
        board[y][x] = '#';
        ori = (ori + 1)%4; // gets to 3 starts back at 0
    }
    else {
        board[y][x] = ' ';
        ori = (ori - 1 + 4)%4;   
    }
    if (ori == 0){
            y = y - 1;
    }
    else if (ori == 1){
            x = x + 1;
    }
    else if (ori == 2){
            y = y + 1;
    }
    else {
            x = x - 1;
        
    }
    if (x < 0){
    x = col - 1;
    }
    if (y < 0){
    y = row - 1;
    }
    if (x >= col){
    x = 0;
    }
    if (y >= row){
    y = 0;
    }

}
// tells user what ori the ant is currently in 
void Ant::displayori(){
    if (ori == 0){
        cout << "up" << endl;
    }
    if (ori == 1){
        cout << "right" << endl;
    }
    if (ori == 2){
        cout << "down" << endl;
    }
    if (ori == 3){
        cout << "left" << endl;
    }

}
//gets private values
int Ant::getx(){
return x;
 }
int Ant::gety(){
return y;
}