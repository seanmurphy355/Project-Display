#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
using std :: string;
using std :: cin;
using std :: cout;
using std :: endl; 
#include "displayboard.hpp"

// Function : Displayboard
// Description: allows user to see current board and status takes in row col board
// and x y cord of ant  loop is used to create board
// black space  = #
// ant  = *
// how the print works is it will print out the starting board of the users desired
// location of the ant or starting random location and the first movement of the ant you will then need to
// enter a char to see the next phase of the board it will run for use desired turns


void displayboard(int &row, int &col, int **&board,int x, int y){
    for (int i = 0; i < row ; i++){
        for (int j = 0; j < col ; j++){
            if (i == y && j == x){
                cout << "| * ";

            }
            else{
                cout << "| " << char(board[i][j]) << " ";
            }
        }
        cout << "| "  << endl;
    }
    cout << endl;
}