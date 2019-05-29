#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
#include <climits> 
#include "game.hpp"
#include "die.hpp"
#include "Mainmenu.hpp"
#include "harrypotter.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"
#include "medusa.hpp"
#include "bluemen.hpp"
#include "character.hpp"
using namespace std;
// Function:Game()
// Description:constructor for game

Game::Game(){

}
// Function:Combat()
// Description:runs combat between c1 and c2 and checks to see if c2 is alive
void Game::combat(Character * c1, Character * c2){
    attack(c1,c2); 
    if (c2 -> getstr() > 0){
        attack(c2,c1); 
    }
    else {
        cout << "Character 2 is dead and can not attack! " << endl;
    }
}
// Function:attack()
// Description:stores data and claculate damage between 2 characters also returns a bunch of
// display messages to the user about the comabt it also helps factor in some special moves within
// if statements even though there is overide code within each character for special moves
void Game::attack(Character * c1, Character * c2){
    
    int attackerroll = c1 -> attack();
    int defroll = c1 -> defend();
    int armor = (c2->getarm());
    int str = (c2 -> getstr());
    int damage = 0;
    if (defroll == 1000){
        cout << "no damage done to Vampire" << endl;
    }
    
    else{
        damage =  attackerroll - defroll - armor;
    }
    if (damage < 0){
        damage = 0;
    }

    c2 -> dedlifepts(damage);
    cout << "1.Attacker type : " << c1 -> gettype() << endl;
    cout << "2.Defender type, Armor points, Strength points :  " << c2 -> gettype() << " " <<  armor <<  " " << str << endl;
    if (attackerroll != 1000){
        cout << "3.Attacker's attack dice roll : " << attackerroll << endl;
    }
    else {
        cout << "3.defender was killed by medusa no roll" << endl;
    }
    if (defroll != 1000){
        cout << "4.Defender's roll is : " << defroll << endl;
    }
    else {
        cout << "4.defender has no roll this turn" << endl;
    }
    if (attackerroll != 100){
        cout << "5.Total damage inflicted : " << damage << endl;
    }
   
    

    
    cout << "6.Defender's updated strength points : " << c2 -> getstr() << endl;
    
}
// Function:pickchar()
// Description:allows user to pick a character uses mainmenu to check user input and make sure
// it is valid

Character * Game::pickchar(){
    int done = 0;
    Character *c;
    int choice = Mainmenu ("\n1.Vampire\n2.Barbarian\n3.Blue Men\n4.Medusa\n5.Harry Potter\nenter choice : ",1,5);

        switch (choice){
            
            case 1:{
                c = new Vampire();
                done  = 1;   
                    }
                break;
            case 2:{
                c = new Barbarian();
                
                done = 1;
                    }
            
                break;
            case 3:
                {
                c = new Bluemen();
                done = 1;
                }
                break;
           case 4:
                {
                c = new Medusa();
                done = 1;
                
                }
                break;
            case 5:
                {
                c = new Harrypotter();
                
                done = 1;
               
                }
                break;
        }
        return c;
}
// Function:playgame()
// Description:runs the entire game and loops it until the user wants to quit the game
// the user gets this option after combat between 2 characters is finished.
void Game::playgame(){
    Character *c1;
    Character * c2;
    int end = 0;

while (!end){
    int done = 0;
    int donetwo = 0;
    cout << "Welcome to Fantasy Combat game!" << endl;
    
    cout << "pick Character for player One!" << endl;
    c1 = pickchar();
    cout << "pick Character for player Two!" << endl;
    c2 = pickchar();


    for (int i = 1; c1 ->getstr() > 0 && c2 -> getstr() > 0; i++){
        cout << "Turn number : " << i << endl;
        cout << "--------------------------------------------------------" << endl;
        combat(c1,c2);
        cout << "--------------------------------------------------------" << endl;
        char answer;
        cin >> answer;  
        cin.ignore(256,'\n');

    }
    delete c1;
    delete c2;
    cout << "game has ended a champion has fallen" << endl;
    end = Mainmenu ("1.Exit Game! \n2.Play Again!\nEnter Choice : ",1,2);
    if (end == 2){
        end = 0;
    }
}
}
// start adding characters at a basic level