#include "character.hpp"
#include "die.hpp"
#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
#include <climits> 
// Function:basic character constructor
// Description:intilization 
Character::Character(int arm,int str, string def,string att,int life,string type){
this -> arm = arm;
this -> str = str;
this -> att = att;
this -> def = def;
this -> life = life;
this -> type = type;

}
// Function:void Character::setarm(int arm)
// Description:setter for armor
void Character::setarm(int arm){
    this ->arm = arm;

}
// Function:int Character::getarm ()
// Description:returns armor
int Character::getarm (){
    return arm;

}
// Function:void Character::setdef(string def)
// Description:setter for def
void Character::setdef(string def){
    this ->def = def;

}
// Function:string Character::getdef ()
// Description:returns def
string Character::getdef (){
    return def;

}
// Function:void Character::setatt(string att)
// Description:sets attack
void Character::setatt(string att){
    this ->att = att;
}
// Function:string Character::getatt ()
// Description:returns attack
string Character::getatt (){
    return att;

}
// Function:void Character::setstr(int str)
// Description:setter for str
void Character::setstr(int str){
    this ->str = str;

}
// Function:int Character::getstr ()
// Description:returns str
int Character::getstr (){
    return str;

}
// Function:getlife
// Description:returns life

int Character::getlife(){
    return life;
}
// Function:setlife
// Description:setter for life
void Character::setlife(int life){
    this -> life = life;
}
// Function:void Character::dedlifepts
// Description:calculates new str level

void Character::dedlifepts(int dedpts){
    str -= dedpts;

}
// Function:bool Character::isdead()
// Description:tells if characters has anymore lifes or is dead

bool Character::isdead(){
    return life <= 0;
}
// Function:string Character::gettype()
// Description:gets the type of character

string Character::gettype(){
    return type;

}
// Function:int Character::attack()
// Description:returns attack die roll

int Character::attack(){
    return Die::rolldice(getatt());

}
// Function:int Character::defend()
// Description:returns def die roll

int Character::defend(){
    return Die::rolldice(getdef());

}