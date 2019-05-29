#define _GLIBCXX_USE_C99 1
// had to use glibcxx to get stoi to work........
#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
#include <climits> 
#include "die.hpp"
using namespace std;


// Function:int Die::rolldice(string roll)
// Description: basicly does character dice rolls and reutrns the total it factors in]
// the specail number of die each characters has

int Die::rolldice(string roll){
    string diecount = roll.substr(0,1);
    string side = roll.substr(2);
    string::size_type sz;
    //converts to int
    int count = std::stoi (diecount,&sz);
    int sides = std::stoi (side,&sz);
    int total  = 0;
    for (int i = 0 ; i < count ; i++){
        total += rand()%sides + 1;
    }
    return total;
}