#include "generateboard.hpp"
#include "menu.hpp"
#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
using std :: string;
using std :: cin;
using std :: cout;
using std :: endl; 

// Function :generateBoard
// Description:creates the intial board asks user to enter number of rows for the board size
//and asks for number of columns the user would like to generate calls menu fucntion
//in order to validate user input

void generateBoard(int &row, int &col, int **&board){

    row = Mainmenu("please enter number of rows for the board size less than 100 and greater than 2 : ", 3, 99);
    col = Mainmenu("please enter number of columns for the board size less than 100 and greater than 2 : ", 3, 99);
    board = new int * [row];// 2 D array
    for (int i = 0; i < row ; i++){
        board[i] = new int [col];
        for (int j = 0 ; j < col ; j++){
            board[i][j] = ' ';

        }
    }
//* = ant , ' ' white, # black space
}