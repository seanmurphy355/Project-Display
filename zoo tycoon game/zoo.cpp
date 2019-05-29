#include "zoo.hpp"
#include "tiger.hpp"
#include "turtle.hpp"
#include "penguin.hpp"
#include "Array.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
#include <climits> 
using namespace std;

// Function : Zoo : Zoo()
// Description :creates array of each specfic animal that is dynamicly allocated

Zoo::Zoo(){
     tigers = new Array ();
     turtles = new Array ();
     penguins = new Array ();


}

Zoo::~Zoo(){
    delete tigers;
    delete turtles;
    delete penguins;
}

// Function : handlebloom()
// Description : handles tiger bonuses for a random even that the game has

float Zoo::handleboom(){
    int bonus = rand()%251 + 250;
    float totalbonus = 0;
    for (int i = 0; i < tigers->getsize(); i ++){
        totalbonus += bonus ;  
    }
    return totalbonus;

}
//Function : handlebirth()
// looks for animals that can have babies and checks for the types of animals that can if it rolls
// the animals number it will add a new born animal to the array (does this for all animals)

void Zoo::handlebirth(){
    int randomnumber =  rand()%3;
    //looks for a animals to have babies and 
    for (int i = 0; i < 3 ; i++){
        if (randomnumber == 0){
            if (tigers -> getsize() > 0){
                for (int j = 0; j < tigers -> getsize(); j++){
                    Animal *a = tigers -> getanimal(j);
                    if (a -> getage()>=3){
                        for (int j = 0 ; j < a -> getbabies(); j++){
                            Tiger *t = new Tiger();
                            addtiger(t);
                        }
                        string message = readtext("birth.text");
                        printf (message.c_str(),a -> getbabies(), "tiger");
                        cout << endl;
                        return;
                        
                    }
                }

            }
        }
        else if (randomnumber == 1){
            if (turtles -> getsize() > 0){
                for (int j = 0; j < turtles -> getsize(); j++){
                    Animal *a = turtles -> getanimal(j);
                    if (a -> getage()>=3){
                        for (int j = 0 ; j < a -> getbabies(); j++){
                            Turtle *t = new Turtle();
                            addturtle(t);
                        }
                        string message = readtext("birth.text");
                        printf (message.c_str(),a -> getbabies(), "turtle");
                        cout << endl;
                        return;
                        
                    }
                }

            }



        }
        else if (randomnumber == 2){
            if (penguins -> getsize() > 0){
                for (int j = 0; j < penguins -> getsize(); j++){
                    Animal *a = penguins -> getanimal(j);
                     if (a -> getage()>=3){
                        for (int j = 0 ; j < a -> getbabies(); j++){
                            Penguin *t = new Penguin();
                            addpenguin(t);
                        }
                        string message = readtext("birth.text");
                        printf (message.c_str(),a -> getbabies(), "penguin");
                        cout << endl;
                        return;
                        
                    }
                }

            }
            
        }
        randomnumber = (randomnumber+1)%3;
    }

cout << "you have no way to make babies" << endl;
}
//Function : handlesick()
// this function randomly picks an living animal and makes them sick which deletes if from the array
// it will also inform the user

string Zoo::handlesick(){
    int randomnumber = rand()%3;
    if (randomnumber == 0){
        if (tigers -> getsize() > 0){
            tigers -> removeanimal();
            return "tiger";
            
        }

    }
    else if (randomnumber == 1){
        if (penguins -> getsize() > 0){
            penguins -> removeanimal();
            return "penguin";
            
        }
        
    }
    else {
        if (turtles -> getsize() > 0){
            turtles -> removeanimal();
            return "turtle";
            
        }

    }

    return "";
}
// add functions will add animals of that specific type

void Zoo::addturtle(Animal *a){
      turtles -> addanimal(a);
}

void Zoo::addtiger(Animal *a){
      tigers -> addanimal(a);
}

  void Zoo::addpenguin(Animal *a){
      penguins -> addanimal(a);
  }

// zoo class has all animals 
// function: ageallanimals()
// will handle increaing a animals age over time
  void Zoo::ageallanimals(){
      // get size is a method gets the number of animals in that animal type
      for (int i = 0; i < tigers -> getsize();i++ ){
        tigers -> getanimal(i) -> ageAnimal();
        
          // gets an animal from animal array and then ages the animal from the animal class
      }

      for (int i = 0; i < turtles -> getsize();i++ ){
        turtles -> getanimal(i) -> ageAnimal();
    
      }

    for (int i = 0; i < penguins -> getsize();i++ ){
          penguins -> getanimal(i) -> ageAnimal();
    
      }

  }

    float  Zoo::feedallanimals(float basecost){
        float total = 0.0;
        for (int i = 0; i < penguins -> getsize();i++ ){
        
            total += penguins -> getanimal(i) -> getfeedingcost() * basecost;
            // gets feeding price and adds to total

        }

         for (int i = 0; i < tigers -> getsize();i++ ){
            
            total += tigers -> getanimal(i) -> getfeedingcost() * basecost;
       
         }

      for (int i = 0; i < turtles -> getsize();i++ ){
            
            total += turtles -> getanimal(i) -> getfeedingcost() * basecost;
    
      }
    return total;

    }
    //function : Payoffforallanimals
    // claculates pay off for animal per day and will assist with editing the user balance

    float  Zoo::payoffforallanimals(){

        float total = 0.0;
        for (int i = 0; i < penguins -> getsize();i++ ){
            float cost = penguins -> getanimal(i) -> getcost();
            // gets the cost of the animal
        
            total += penguins -> getanimal(i) -> getpayoff() * cost/100.0;
            // changes payoff to % 

        }

         for (int i = 0; i < tigers -> getsize();i++ ){
            
             float cost = tigers -> getanimal(i) -> getcost();
            // gets the cost of the animal
        
            total += tigers -> getanimal(i) -> getpayoff() * cost/100.0;
       
         }

      for (int i = 0; i < turtles -> getsize();i++ ){
            
           float cost = turtles -> getanimal(i) -> getcost();
            // gets the cost of the animal
        
            total += turtles -> getanimal(i) -> getpayoff() * cost/100.0;
      }
    return total;

    }

    string Zoo::readtext(string filename){
        string line = "";
        
        ifstream myfile (filename.c_str());
        if (myfile.is_open())
        {
            getline(myfile,line);
            myfile.close();
            return line;
        }
        return line;
    }
    