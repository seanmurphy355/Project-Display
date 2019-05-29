#include "item.hpp"
#include <iostream>
#include <string>
#include <cmath> 
#include <sstream>
#include <cstdlib>
#include <climits> 
using namespace std;
//function: Item(int n)
//description:constructor for item defines items that are involved in the game
// based on numerical values

Item::Item(int n){
    if (n < 10){
        switch (n){
            case 1:
            this -> name = "Shield";
            break;
            case 2:
            this -> name = "Sword";
            break;
            case 3:
            this -> name = "Mirror";
            break;
            case 4:
            this -> name = "Wand";
            break;
            case 5:
            this -> name = "Plate legs";
            break;
            case 6:
            this -> name = "Plate body";
            break;
            case 7:
            this -> name = "bow";
            break;
            case 8:
            this -> name = "Plate body";
            break;
        }
    }
    else {
        switch (n){
            case 10:
            this -> name = "Key 1";
            break;
            case 20:
            this -> name = "Key 2";
            break;
            case 30:
            this -> name = "Key 3";
            break;
            case 40:
            this -> name = "Key 4";
            break;
            case 50:
            this -> name = "Boss Key";
            break;
        }
    }
}
//function: getname()
//description:gets the name of the item
string Item::getname(){
    return name;
}