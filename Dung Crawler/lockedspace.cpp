#include "lockedspace.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
#include <string>
#include <cmath> 
#include <sstream>
#include <cstdlib>
#include <climits> 

using namespace std;
//function: Lockedspace()
//description: constructor inherits from space object

Lockedspace::Lockedspace(): Space (){

}
//destructor
Lockedspace::~Lockedspace(){
    for (int i = 0; i < req.size();i++){
        delete req[i];
    }
    cout << "cleaned up locked space" << endl;
}

//function: enter(Player *p)
//description:checks to see if the player can enter the locked room
// based of if the player has the spefic key or not needed to enter the room


bool Lockedspace::enter(Player *p){
    for (int i = 0; i < req.size();i++){
        string itemname = req[i] -> getname();
        if (itemname.substr(0,3) == "Key" || itemname == "Boss Key"){
            cout << "looking for " << itemname << endl;
            if (!checkforitem(itemname,p)){
                cout << "you not able to enter" << endl;
                return false;
            }
        }
    }
    cout << "you are able to enter" << endl;
    return true;
}
//function: display()
//description:displays what a lockedroom looks like on map
string Lockedspace::display(){
    return "L";
}
//function: addreq(Item * i)
//description:adds a req
void Lockedspace::addreq(Item * i){
    req.push_back(i);
}
//returns a req
vector<Item *> Lockedspace::getreq(){
    return req;
}
//function: checkforitem (string name,Player * player)
//description: checks for valid item  returens true or false

bool Lockedspace::checkforitem(string name,Player * player){
    for (int i = 0; i < player -> getitems().size();i++){
        string itemname = player -> getitems()[i] -> getname();
        if (name == itemname){
            cout << "found " << itemname << endl;
            return true;
        }    
    }
    cout << "could not find " << name << endl;
    return false;
}
//used for boss rooms
Item * Lockedspace::getreq(int index){
    return req[index];
}
int Lockedspace::getreqcount(){
    return req.size();
}

