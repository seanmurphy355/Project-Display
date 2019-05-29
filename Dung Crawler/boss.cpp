#include "boss.hpp"
#include <iostream>
#include <string>
#include <cmath> 
#include <sstream>
#include <cstdlib>
#include <climits> 
using namespace std;
//Function: Boss 
//Description: inherits from locked space this is the constructor
Boss::Boss(): Lockedspace (){

}

Boss::~Boss(){
    
}
//Function: enter(Player *p)
//Description: allows player to enter boss room
bool Boss::enter(Player *p){
    return Lockedspace::enter(p);
}
//Function: Display
//Description: displays Boss room on map
string Boss::display(){
    return "B";
}

//Function: Look
//Description: checks to see if user has correct items to enter and defeat the boss in the boss room
bool Boss::look(Player * p){
    cout << "The boss is here! you better have the right items! for this!" << endl;
    for (int i = 0; i < getreqcount(); i++){
        string musthave = getreq(i) -> getname();
        if (!checkforitem(musthave,p)){
            cout << "your dead!!!" << endl;
            return false;
        }
    }
    cout << "you have all the items!!" << endl;
    cout << "You beat the boss!" << endl;
    return true;   
}



