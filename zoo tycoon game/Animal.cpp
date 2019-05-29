#include "Animal.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
#include <climits> 
using namespace std;

// Function : Animal 
// Description : all items in animal.cpp create parameters for the animal that is used in order to
// play this game such as intilization of age,cost, baby , feedingcost, payoff. each animal will inherit from
// this , is adult checks for adult hood, get age gets age of the animal, gets baby gets a baby , get cost
// gets the cost of an animal, age animal increases animal age by +1 after each day, feeding cost (animals feeding cost)
// get pay off will get the pay off of an animal

Animal :: Animal(){
    age = 0;
    cost = 0;
    baby = 0;
    feedingcost = 0;
    payoff = 0;
}
bool Animal::isadult(){
    if (age >= 3){
        return true;
    }
    return false;
}
 void Animal::setage(int age){
     this -> age = age;
 }
    

 int Animal::getage(){
     return age;

 }
 
 int Animal::getbabies(){

     return baby;
 }


int Animal::getcost(){
    return cost;


}
// adds 1 to animals age
void Animal::ageAnimal(){
    age ++;


 }

float Animal::getfeedingcost(){
    return feedingcost;
}

int Animal::getpayoff(){

    return payoff;
}