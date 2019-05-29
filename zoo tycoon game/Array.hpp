#ifndef Array_h
#define Array_h
#include "Animal.hpp"
// basic initialization of the array used for the game 

class Array{

    public:
    Array ();
    void addanimal(Animal *);
    // dynamic array creation
    Animal *getanimal(int index);
    int getsize();
    void removeanimal();
    ~Array(); //method is used for delete invoc 


    private:
    Animal **animals;
    int cap;
    int count;
    
};



#endif