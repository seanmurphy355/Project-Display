#include "vampire.hpp"
#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
#include <climits> 
using namespace std;
// Function:Vampire::Vampire():Character(1,18,"1d6","1d12",1,"Vampire")
// Description:constructor inherits from character class and gives traits of a vampire

Vampire::Vampire():Character(1,18,"1d6","1d12",1,"Vampire"){

}

// Function:void Vampire::dedlifepts(int dedpts)
// Description:keeps track of dedpts

void Vampire::dedlifepts(int dedpts){
    Character::dedlifepts(dedpts);
}
// Function:int Vampire::charm()
// Description: calculates to see if vampire rolled a charm
bool Vampire::charm(){
    int charm = rand () % 2;
    return charm == 1; 
}

// Function:int Vampire::defend()
// Description: allows vampire to use charm move

int Vampire::defend(){
    int defend = Character :: defend();
    if (charm()){
        defend = 1000;
        cout << "vampire charms attacker and avoids attack! " << endl;
        
    }
    return defend;


}