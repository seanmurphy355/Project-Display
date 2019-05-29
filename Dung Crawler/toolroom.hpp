#ifndef Toolroom_h
#define Toolroom_h
#include <string>
#include <vector>
#include <string>
#include "space.hpp"
#include "player.hpp"
using namespace std;
//Simple set up of public,private and maybe protected classes in order
//to declare methods/functions before hand and includes potential inheritance
//for this "class"

class Toolroom : public Space{
public:
virtual ~Toolroom();
Toolroom();
bool enter(Player *p);
string display();


private:



};
#endif