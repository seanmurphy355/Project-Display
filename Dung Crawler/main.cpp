// program: Final project
// author:Sean Murphy 
// date: 08/13/2018
// description: Create a game on any type using specfic classes such as space
// it must be turn based and have at least 6 spaces

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
#include "game.hpp"
#include "mainmenu.hpp"


// all main does is run the program and the programs main contents resideds in the game class
int main (int argc, char *argv[]) {
   
    int choice = 1;
    do{
        Game game;
        game.displayinstruct();
        game.playgame();
    //plays game
        choice = Mainmenu("play again 1 = yes, 2 = exit",1,2);

    }while (choice == 1);
    return 0;
}
