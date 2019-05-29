#ifndef Space_h
#define Space_h
#include <string>
#include <vector>
#include <string>
#include "player.hpp"
#include "item.hpp"
using namespace std;
//Simple set up of public,private and maybe protected classes in order
//to declare methods/functions before hand and includes potential inheritance
//for this "class"

class Space {
public:
Space();
virtual~Space();
Space * getup();
Space * getdown();
Space * getright();
Space * getleft();
void setup(Space * s);
void setdown(Space * s);
void setright(Space * s);
void setleft(Space * s);
static int getxindex(int index);
static int getyindex(int index);
Player * getplayer();
void setplayer(Player * p);
virtual bool enter(Player *p) = 0;
void additems(Item * i);
vector <Item *> getitems();
virtual string display() = 0;
virtual bool look(Player *p);
void listitems();


private:
Space * up;
Space * down;
Space * left;
Space * right;
vector <Item *> items;
Player * player;


};
#endif