#include "medusa.hpp"
#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
#include <climits> 
using namespace std;
// Function:Medusa::Medusa(): Character
// Description: inherits from character class and gives defining traits of a medusa

Medusa::Medusa(): Character(3,8,"1d6", "2d6",1,"Medusa"){

}
// Function:dedlifepts()
// Description:looks at medusas dedpts 

void Medusa::dedlifepts(int dedpts){
    Character::dedlifepts(dedpts);

}
// Function:Medusa::attack()
// Description:this code is used to factor in medusas glare move

int Medusa::attack(){
    int attack = Character :: attack();
    if (attack == 12){
        attack = 1000;
        cout << "Medusa uses Glare and the attack is lethal! " << endl;
    }
    return attack;
}