#include "bluemen.hpp"
#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
#include <climits> 
using namespace std;
// Function:luemen::Bluemen(): Character
// Description:Inherits from character class and gives the items to the program that are needed
// for the blue man

Bluemen::Bluemen(): Character(3,12 ,"3d6","2d10",1,"Blue Men"){


}
// Function:dedlifepts(int dedpts)
// Description:looks at new life pts for bluemen and then gives the new amount of def dice for
// this character

void Bluemen::dedlifepts(int dedpts){
    Character::dedlifepts(dedpts);
    if (getstr() > 0){
        int diecount = (getstr() + 3)/4;
        if (diecount == 3){
            setdef("3d6");
        }
        else if (diecount == 2){
            setdef("2d6");
        }
        else if (diecount == 1){
            setdef("1d6");
        }
        cout << "blue mens health is at "<< getstr() << endl;
        cout << "diceroll = " << getdef() << endl;
    }
}