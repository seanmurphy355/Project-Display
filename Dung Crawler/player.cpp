#include "player.hpp"
#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
#include <climits> 
using namespace std;
//function:Player()
//description:player construct
Player::Player(){

}
//function:~player()
//description:player destructor

Player::~Player(){
    for (int i = 0; i < items.size();i++){
        delete items[i];
    }
}

//function:additem()
//description:adds to list of items

void Player::additem(Item * i){
    items.push_back(i);
    //adds to list of items
}
//function:vector
//description:returns items
vector <Item *> Player::getitems(){
    return items;

}

//function:dropitem(int n)
//description:drops n item

void Player::dropitem(int n){
    cout << "dropping : " << items[n] -> getname() << endl;
    items.erase(items.begin()+ n);
}
//function:listitems()
//description:lists users items 
void Player::listitems(){
    for (int i = 0; i < items.size();i++){
        cout << i + 1 << ". " << items[i] -> getname() << endl;
    }
}

//function:getitemcount
//description:counts items

int Player::getitemcount(){
    return items.size();
}

