#ifndef Zoo_h
#define Zoo_h
#include "Array.hpp"
#include <string>
using namespace std;
class Zoo{
    public:
    Zoo();
    void addpenguin(Animal *a);
    void addturtle(Animal *a);
    void addtiger(Animal *a);
    //will add a animal.... 
    void ageallanimals();
    float feedallanimals(float basecost);
    float payoffforallanimals();
    float handleboom();
    void handlebirth();
    string handlesick();
    string readtext(string filename);
    ~Zoo();

    


    private:
    Array *tigers;
    Array *turtles;
    Array *penguins;
    // array class handles array spacing rather then the zoo class
    
    
};



#endif