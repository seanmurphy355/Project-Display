#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
using std :: string;
using std :: cin;
using std :: cout;
using std :: endl; 
#include "mainmenu.hpp"

// Function : Mainmenu
// Description: 
// If the user decided to quit, the program should quit. Otherwise, the game will play
// will check user input and make sure it is validated called several times in the projtwo.cpp

int Mainmenu (string message, int min, int max){

int userchar;
char Mychar[256];

    cout << message;
 
    int value = 0;
 
	while (true) {
		cin >> value;

        if (cin.fail())
        {
            cout << " Please enter a valid integer " << endl;
            cin.clear();
            cin.ignore(80, '\n');
            continue;
         }

		
    if (value < min || value > max){  
      cout << "You did not enter a valid input please try again make sure to select one of the options above : " << endl;
    }
 
	else {
        return value;
    }

	}
}