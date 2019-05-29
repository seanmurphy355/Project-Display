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
// Description: will check user input and make sure it is valid based of the parameters given when
// this function is called in main

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
