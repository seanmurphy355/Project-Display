#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
using std :: string;
using std :: cin;
using std :: cout;
using std :: endl; 
#include "menu.hpp"

// Function : Mainmenu
// Description: Start Langton’s Ant simulation,	Quits program
// If the user decided to quit, the program should quit. Otherwise, start the Langton’s Ant simulation. After the simulation starts, the program should prompt user for all the information to run the simulation, including:
// The number of rows for the board.
// The number of columns for the board the number of steps during simulation.
// The starting row of the ant.
//The starting column of the ant. After game ends should ask user to play agai.
// black space  = #
// ant  = *

int Mainmenu (char* message, int min, int max){

int userchar;
char Mychar[256];

    cout << message;
 
    int value = 0;
 
	while (true) {
		cin.getline(Mychar, 256, '\n');
		value = (int)atoi(Mychar);
		
   
    if (value < min || value > max){  
      cout << "You did not enter a valid input please try again make sure to select one of the options above : " << endl;
    }
 
	else {
        return value;
    }

	}
}