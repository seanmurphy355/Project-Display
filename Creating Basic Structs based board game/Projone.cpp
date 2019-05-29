// program: Project 1
// author:Sean Murphy 
// date: 07/05/2018
// description: project 1 Langston's Ant goal of this project
// is to review programming with dynamic arrays, convert program  requirments
// for design and implement the program design 
// input: This program will take in user input
// output: output will be a response to user input for our "ant"

#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
#include <climits> 
using std :: string;
using std :: cin;
using std :: cout;
using std :: endl; 
#include "ant.hpp"
#include "menu.hpp"
#include "displayboard.hpp"
#include "generateboard.hpp"


// above the includes / using call different tools we will need for this
// program to run 
// Proto types are below 
// Function : Main
// Description : all calls for other functions will ask user for several inputs
// and makes calls to mainmenu and to ant class that was created 
// this function has a error check at line 66 feel free to remove this allows to check
// each phase change of the board by enter a char into the terminal and will progress

int main (int argc, char *argv[]) {
while (1){
cout << "Welcome to Langston's Ant simulation please enter : " << endl;
int value = Mainmenu("enter 1 to start 2 to quit : ", 1 , 2);
if (value == 2){
    exit(0);
}
int row, col;
int **board;
generateBoard(row,col,board);
cout << "the ant will always start out facing north" << endl;
int steps = Mainmenu("enter how many steps you would like to take : ",1,INT_MAX);
value = Mainmenu("enter 1 for random ant enter 2 to pick starting location of ant : ", 1 , 2);
Ant*ant;
if (value == 1){
    int x = rand()%col;
    int y = rand()%row;
    ant = new Ant(x,y);
    
}
else {

    int x = Mainmenu("please enter the x cord smallest value being 1 : ",1,col);

    int y = Mainmenu("please enter the y cord smallest value being 1s : ",1,row);
    ant = new Ant(x-1,y-1);
//not random     
}
//game start
string answer;
displayboard(row, col,board,ant -> getx(), ant -> gety());
for (int i = 0; i < steps ; i++){
ant -> moveant(board,row,col);
displayboard(row, col,board,ant -> getx(), ant -> gety());
ant -> displayori();
cin >> answer;// error check

}
value = Mainmenu("enter 1 to go back to menu or enter 2 to quit program : ", 1 , 2);
if (value == 2){
    exit(0);
}
}
return 0;
}






