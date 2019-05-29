#include "space.hpp"
#include "player.hpp"
#include "mainmenu.hpp"
#include <string>
#include <iostream>
#include <cmath> 
#include <sstream>
#include <cstdlib>
#include <climits> 

using namespace std;
//function: Space()
//description:  constructor intilization of directions
Space::Space(){
    up = NULL;
    left = NULL;
    right = NULL;
    down = NULL;
}
//function:~Space()
//description: clears out memory that is dynamic
Space::~Space(){
    for (int i = 0; i < items.size();i++){
        delete items[i];
    }
}

//function:getup
//description:returns up

Space *Space::getup(){
    return up;
}
//function:getdown
//description:returns down
Space * Space::getdown(){
    return down;
}
//function:getright
//description:returns right 
Space * Space::getright(){
    return right;
}
//function:getleft
//description:returns left

Space * Space::getleft(){
    return left;
}   
//function:getplayer
//description: returns player
Player * Space::getplayer(){
    return player;

}
//function:setplayer(Player *p)
//description: sets player = p
void Space::setplayer(Player * p){
    player = p;

}
//function:additems
//description:adds to list
void Space::additems(Item * i){
    items.push_back(i);
    //adds to list of items
}
//function:setup
//description:sets up to s
void Space::setup(Space * s){
    this -> up = s;
}
//function:setdown
//description: sets down to s

void Space::setdown(Space * s){
    this -> down = s;
}
//function:setright
//description:sets right to s
void Space::setright(Space * s){
    this -> right = s;
}
//function:setleft
//description:sets left to s
void Space::setleft(Space * s){
    this -> left = s;
}
//function:getxindex
//description:retursn a int index basic math operation  for x cord
int Space::getxindex(int index){
    return (index - 1)% 4;
}
//function:getyindex
//description:retursn a int index basic math operation  for y cord
int Space::getyindex(int index){
    return (index - 1)/ 4;
}
//function:ItemSpace  (vector)
//description:returns items 

vector <Item *> Space::getitems(){
    return items;

}

//function:look(player *p)
//description: Gives user options after each turn to look for items in a room
// pick them up , add them to bag, drop them  or to exit the room and move on with the game
// this uses a series of other functions in order to carry this out!

bool Space::look(Player *p){
    for (;;){
        int choice = Mainmenu ("1. Search room , 2. Add item to bag , 3. drop item ,4.list items in bag 5. Leave room: enter option : ",1,5);
        if (choice == 1){
            if (items.size() > 0){
                listitems();
            }
            else {
                cout << "room is empty" << endl;
            }
    }
    else if (choice == 2){
         if (items.size() > 0){
            int n = Mainmenu("enter an item number!",1,items.size());
            Item * toadd = items [n-1];
            if (p -> getitemcount() >= CAP){
                cout << "no room in bag!" << endl;
            }
            else {
                p -> additem(toadd);
                cout << "picked up " << toadd -> getname() << endl;
            }
        }
        else {
            cout << "no items" << endl;
        }


    }
    else if (choice  == 3){
        if(p -> getitemcount() <= 0){
            cout << "you have no items to drop!" << endl;
        }
        else{
            p -> listitems();
            int n = Mainmenu("enter a item number to drop",1,p -> getitemcount());
            p -> dropitem(n);
        }
    }
        else if (choice == 4){
            if(p -> getitemcount() <= 0){
                cout << "you have no items" << endl;
            }
            else{
            p -> listitems();
            }

        }
        else {
            return true;
        }
    }
}
//listitems()
// lists items and gets name

void Space::listitems(){
     for (int i = 0; i < items.size();i++){
        cout << i + 1 << ". " << items[i] -> getname() << endl;
    }
}


  

