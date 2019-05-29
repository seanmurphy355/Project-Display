#ifndef Player_h
#define Player_h
#include <string>
#include <vector>
#include <string>
#include "item.hpp"

using namespace std;
#define CAP 5
class Player {
public:
Player();
~Player();
void additem(Item * i);
vector <Item *> getitems();
void dropitem(int name);
void listitems();
int getitemcount();
//Simple set up of public,private and maybe protected classes in order
//to declare methods/functions before hand and includes potential inheritance
//for this "class"


private:
vector <Item *> items;
int cap;


};
#endif