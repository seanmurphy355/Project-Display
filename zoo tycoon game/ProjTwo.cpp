// program: Zoo Tycoon
// author: Sean Murphy 
// date: 07/13/2018
// description: Create a zoo tycoon game using classes and inheritance. zoo tycoon allows for players
// to run a zoo business. Different types of animals cost different prices, maintenance costs and
// return of profit at the the end of each day. Player will be the owner of a virtual zoo housing
// tigers penguins and turtles
// input: user input creating fluid game play
// output: responses 

#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
#include <climits> 
#include <stdio.h>
#include "mainmenu.hpp"
#include "zoo.hpp"
#include "tiger.hpp"
#include "turtle.hpp"
#include "penguin.hpp"
using std :: string;
using std :: cin;
using std :: cout;
using std :: endl; 


// Function : Main
// Description : calls all other functions to run the entire game asks user several questions
// as well as asks for user inputs such as how many tigers they would like. The function also updates
// the user on the current balance as well as calls random events
// basicly this part of the program calls all other parts and then has several if else statments
// that the user can pick from in order to "play the game"

int main (int argc, char *argv[]) {
    while(1){
    int days = Mainmenu("how many days would you like to play (1-100): " ,1,100);
    
    float balance = 100000;
    float basecost = 10;
    Zoo zoo;
    int numbertigers = Mainmenu("how many tigers do you want to buy : " ,1,2);
    int numberturtles = Mainmenu("how many turtles do you want to buy : " ,1,2);
    int numberpenguins = Mainmenu ("how many penguins do you want to buy : " ,1,2);
    float purchcost;
    cout << "buying " << numbertigers << " tiger." << endl;
    purchcost = 0;
    //this loop # of animals clalcs cost and adds animal to the zoo
    for (int i = 0; i < numbertigers; i++){
        Tiger *t = new Tiger();
        purchcost += t -> getcost();
        zoo.addtiger(t);
    }
    for (int i = 0; i < numberpenguins; i++){
        Penguin *t = new Penguin();
        purchcost += t -> getcost();
        zoo.addpenguin(t);
    }
    for (int i = 0; i < numberturtles; i++){
        Turtle *t = new Turtle();
        purchcost += t -> getcost();
        zoo.addturtle(t);
    }
    
    int feedtype = Mainmenu ("what type of feed would you like? (1) for cheap (2) for generic and (3) for premuim :  " ,1 ,3 );
    float sickperc = 10;
    // feeding types intigration
    if (feedtype  == 1){
        basecost = basecost / 2;
        sickperc = 2 * sickperc;

    }
    else if (feedtype == 2){
        basecost = basecost;
        sickperc = 1 * sickperc;


    }
    else {
        basecost = basecost * 2;
        sickperc = sickperc/2;

    }

    for (int i = 0; i < days ; i++){

        float bonus = 0.0;
        cout << "day number :  " << i + 1 << endl;

        zoo.ageallanimals();
        float cost = zoo.feedallanimals(basecost);
        balance = balance - cost;
        float payoff = zoo.payoffforallanimals();
        cout << "cost of feeding animals :  " << cost << endl;
        cout << "payoff for animals is :  " << payoff << endl;
        balance = balance + payoff;
        cout << "new balance is :   " << balance << endl;
        // ages animal by 1 each "day"
        int randomnumber = rand()%100;
        if (randomnumber <= sickperc){
        cout << "an animal is sick " << endl;
        string name = zoo.handlesick();
        string message = zoo.readtext("sick.text");
        printf(message.c_str(),name.c_str());
        cout << endl;
        
    


        }
         else if (randomnumber < 60){
        cout << " there has been a boom in attendance " << endl;
        bonus = zoo.handleboom();
        string message = zoo.readtext("bonus.text");
        printf(message.c_str(),bonus);
        cout << endl;
        balance = balance + bonus;

        }
        else if (randomnumber < 80){
        zoo.handlebirth();

        

        }
        else {
            cout << "nothing happened today" << endl;

        }
        // animal purchase prompt
        int answer = Mainmenu("do you want you buy an animal (1) = yes , 2 = (no) : ",1,2);
        if (answer == 1){
            int type = Mainmenu("what animal would you like to buy (1) tiger, (2) penguin , (3) turtle",1,3);
            Animal *a;
            if (type == 1){
                a = new Tiger();
                a -> setage(3);
                cout << "you bought a adult tiger" << endl;
                balance -= a -> getcost();
                zoo.addtiger(a);
            }
            if (type == 2){
                a = new Penguin();
                a -> setage(3);
                cout << "you bought a adult penguin" << endl;
                balance -= a -> getcost();
                zoo.addpenguin(a);
            }
            if (type == 3){
                a = new Turtle();
                a -> setage(3);
                cout << "you bought a adult turtle" << endl;
                balance -= a -> getcost();
                zoo.addturtle(a);
            }
          


        }
        cout << "you have a current balance of : " << balance << endl;
        cout << "----------------------------------------------------" << endl;
        cout << endl;

    }
    int yes = Mainmenu("do you want to keep playing (1) = yes , 2 = (no) : ",1,2);
    if (yes == 2){
        return 0;
    }
    }

    return 0;
}
