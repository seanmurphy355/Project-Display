#ifndef Boss_h
#define Boss_h
#include <string>
#include <vector>
#include <string>
#include "space.hpp"
#include "player.hpp"
#include "lockedspace.hpp"
using namespace std;
//Simple set up of public,private and maybe protected classes in order
//to declare methods/functions before hand and includes potential inheritance
//for this "class"

class Boss : public Lockedspace{
public:
Boss();
virtual ~Boss();
bool enter(Player *p);
string display();
bool look(Player * p);

private:



};
#endif