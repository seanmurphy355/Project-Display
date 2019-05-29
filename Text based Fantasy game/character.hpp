#ifndef Character_h
#define Character_h
#include <string>
#include <vector>
#include <string>
using namespace std;
// decleration of constructor, functions/methods , potential inheritance that this class might use
// including public and private data types

class Character  {
public:
Character(int arm,int str, string def,string att,int life,string type);
void setarm(int arm);
int getarm ();
void setdef(string def);
string getdef ();
void setatt(string att);
string getatt ();
void setstr(int str);
int getstr ();
int getlife();
void setlife(int life);
virtual void dedlifepts(int dedpts);
bool isdead();
string gettype();
virtual int attack();
virtual int defend();



private:
int arm;
int life;
int str;
string def;
string att;
string type;



};
#endif