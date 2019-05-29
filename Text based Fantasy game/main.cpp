// program: Lab 6
// author:Sean Murphy 
// date: 08/05/2018
// description:building a doubly-linked list that utilizes pointers
// learning how to modify data in linked list


#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
#include <climits> 
using std :: string;
using std :: cin;
using std :: cout;
using std :: endl; 
#include "game.hpp"
#include "harrypotter.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"

using namespace std;
// Function:Main()
// Description:all it does is make a simple play game call other then that main does nothing

int main (int argc, char *argv[]) {

    Game game;
    game.playgame();
    
}