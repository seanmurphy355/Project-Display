#include "harrypotter.hpp"
#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
#include <climits> 
using namespace std;
// Function:Harrypotter::Harrypotter(): Character
// Description:inherits from charcter class is constructor and gives needed data to character
Harrypotter::Harrypotter(): Character(0,10 ,"2d6","2d6",2,"Harry Potter") {


}
// Function:Harrypotter::dedlifepts(int dedpts)
// Description:helps see harry's hps and factors in hogwarts to the game

void Harrypotter::dedlifepts(int dedpts){
    Character::dedlifepts(dedpts);
    //calls dedlifepts , after the call 
    if (getlife() > 1 && getstr() <= 0){
        cout << "Harry has come back from the dead!" << endl;
        setlife(1);
        setstr(20);
    }
    if (getlife() < 2 && getstr() <= 0){
        setlife(0);
        setstr(0);
    }


}