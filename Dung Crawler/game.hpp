#ifndef Game_h
#define Game_h
#include <string>
#include <vector>
#include <string>
#include "space.hpp"
using namespace std;
#define SIZE 4
//Simple set up of public,private and maybe protected classes in order
//to declare methods/functions before hand and includes potential inheritance
//for this "class"
class Game {
public:
Game();
~Game();
void playgame();
void displaymap();
void displayinstruct();
int pickdir();
void move(int dir);
void gamerules();


private:
int steplim;
int x;
int y;
Space * board [SIZE][SIZE]; 
Player * player;

};
#endif