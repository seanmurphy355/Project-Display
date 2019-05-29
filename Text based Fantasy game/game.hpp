#ifndef Game_h
#define Game_h
#include <string>
#include <vector>
#include <string>
#include "character.hpp"
using namespace std;
// decleration of constructor, functions/methods , potential inheritance that this class might use
// including public and private data types

class Game {
public:
Game();
void combat(Character * c1, Character * c2);
void attack(Character * c1, Character * c2);
void playgame();
Character *pickchar();





private:



};
#endif