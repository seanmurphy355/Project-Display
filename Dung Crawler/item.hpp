#ifndef Item_h
#define Item_h
#include <string>
#include <vector>
#include <string>
using namespace std;
//Simple set up of public,private and maybe protected classes in order
//to declare methods/functions before hand and includes potential inheritance
//for this "class"
class Item {
public:
Item(int n);
string getname();

private:
string name;


};
#endif