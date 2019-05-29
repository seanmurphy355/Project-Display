#ifndef Lockedspace_h
#define Lockedspace_h
#include <string>
#include <vector>
#include <string>
#include "space.hpp"
#include "item.hpp"
#include "player.hpp"
#include "lockedspace.hpp"
using namespace std;
//Simple set up of public,private and maybe protected classes in order
//to declare methods/functions before hand and includes potential inheritance
//for this "class"
class Lockedspace : public Space {
public: 
Lockedspace();
~Lockedspace();
virtual bool enter(Player *p);
string display();
void addreq(Item * i);
vector<Item *> getreq();
bool checkforitem(string name,Player * player);
Item * getreq(int index);
int getreqcount();

private:
vector <Item *> req;



};
#endif