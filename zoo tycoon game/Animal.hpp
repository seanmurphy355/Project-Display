#ifndef Animal_h
#define Animal_h
// animal class initilizations 

class Animal{

    public:
    bool isadult();
    Animal();
    int getage();
    int getbabies();
    int getcost();
    void ageAnimal();
    float getfeedingcost();
    int getpayoff();
    void setage(int age);
    

   

    protected:
    int age;
    int cost;
    int baby;
    float feedingcost;
    int payoff;

    
};


// a class tree -----> what 
#endif