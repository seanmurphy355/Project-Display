#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
#include <climits>
using namespace std;
#include "toolroom.hpp"
//function:Tool room()
//description:inherits from space class
Toolroom::Toolroom() : Space (){

}

Toolroom::~Toolroom(){
    
}
//function:enter()
//description: allows user to enter tool room
bool Toolroom::enter(Player *p){
    return true;

}

//function:display()
//description:displays what a tool room looks like on map
string Toolroom::display(){
    return "I";
}
