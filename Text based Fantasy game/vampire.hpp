#ifndef Vampire_h
#define Vampire_h
#include <string>
#include <vector>
#include <string>
#include "character.hpp"
using namespace std;

// decleration of constructor, functions/methods , potential inheritance that this class might use
// including public and private data types
class Vampire : public Character  {
public:
Vampire();
void dedlifepts(int dedpts);
bool charm();
int defend();



private:



};
#endif