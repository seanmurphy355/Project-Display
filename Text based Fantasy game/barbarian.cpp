#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
#include <climits> 
#include "barbarian.hpp"

// Function:Barbarian::Barbarian(): Character
// Description: Inherits from character class and gives the items to the program that are needed
// for the barbarian

Barbarian::Barbarian(): Character(0,12 ,"2d6","2d6",1,"Barbarian"){

}
// Function:dedlifepts(int dedpts)
// Description:used to get new characters life points

void Barbarian::dedlifepts(int dedpts){
    Character::dedlifepts(dedpts);

}