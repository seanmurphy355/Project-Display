#include "game.hpp"
#include <iostream>
#include <string>
#include <cmath> 
#include <sstream>
#include <cstdlib>
#include <climits> 
#include "boss.hpp"
#include "lockedspace.hpp"
#include "space.hpp"
#include "toolroom.hpp"
#include "mainmenu.hpp"
#include "player.hpp"
using namespace std;
//defintion of map struct: declared here

struct map{
    int type;
    int items[4];  
    int req[4];

};
//what cells are connected to what cells
// link is used to link up down right left 
struct link{
    int from;
    int to;
};
//Function:Ganme()
//description: creates a player and creates the rooms that have items
//also creates the 3 types of rooms that are invloved within the game
// also links all the directions togther

Game::Game(){
    steplim = 10;
    //set location of player
    x = 0;
    y = 0;
    player = new Player();
    map plan[][4] = {
        {{1,{0}},{1,{40,0}},{2,{0},{40,0}},{1,{5,0}}},
        {{1,{0}},{1,{6,0}},{1,{0}},{2,{2,0},{20,0}}},
        {{1,{10,0}},{2,{1,20,0},{10,0}},{1,{30,0}},{1,{50,0}}},
        {{2,{7,0},{30,0}},{1,{0}},{1,{8,0}},{3,{4,0},{1,2,50,0}}}
        };
    link links[] = {{1,2},{2,3},{3,4},{1,5},{2,6},{3,7},{4,8},
                    {5,6},{6,7},{7,8},{5,9},{6,10},{7,11},{8,12},
                    {9,10},{10,11},{11,12},{9,13},{10,14},{11,15},{12,16},
                    {13,14},{14,15},{15,16}};

    for (int i = 0; i < SIZE ;i++){
        for (int j = 0; j < SIZE ;j++){
            map sqr = plan [i][j];
            if (sqr.type == 3){
                Boss *b = new Boss();
                board [j][i] = b;
                for (int * req = plan[i][j].req; *req != 0; req++ ){
                    b -> addreq(new Item(*req));
                }
            } 
            else if(sqr.type == 2){
                Lockedspace * L = new Lockedspace();
                board [j][i] =  L;
                for (int * req = plan[i][j].req; *req != 0; req++ ){
                    L -> addreq(new Item(*req));
                }   
            }
            else  if (sqr.type == 1){
                board [j][i] = new Toolroom();
            }
            else {
                cout << "type does not exist!" << endl;
                board [j][i] = NULL;
            } 
            for (int * items = plan[i][j].items; *items != 0; items++ ){
                board [j][i] -> additems(new Item(*items));
            }    
        }
    }
    //connects paths for sqrs
    //uses links to move in directions 
    for (int i = 0; i< 24; i++){
        int from = links[i].from;
        int to = links[i].to;
        int fromx = (from-1) % SIZE;
        int fromy = (from-1) / SIZE;
        int tox = (to-1) % SIZE;
        int toy = (to-1) / SIZE;
        if (to - from == 1){
            cout << from % 4 << endl;

            board [fromx][fromy] -> setright(board[tox][toy]);
            board [tox][toy] -> setleft(board[fromx][fromy]);
        }
        else{
            board [fromx][fromy] -> setdown(board[tox][toy]);
            board [tox][toy] -> setup(board[fromx][fromy]);
        }
    }
}
//function : ~Game()
//description : destructor for game!
Game::~Game(){
    delete player;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            delete board [i][j];
        }
    }
}
//function: playgame()
//description: play game runs the entire game defines step limit and calls
//other functions/ methods that are used in order to run the game.
void Game::playgame(){
    gamerules();
    displaymap(); 
    bool youwin = false;
    for (int i = 0; i < steplim; i++){
        cout << "step : " << i + 1 << endl;
        cout << "you have " << steplim - i << " steps left!" << endl;
        int choice  = pickdir();
        move(choice);
        displaymap();
        bool flag = board [x][y] -> look(player);
        if (flag != true){
            break;
        }
        if (x == SIZE - 1 && y == SIZE - 1){
            youwin = true;
            break;
        }
    }
    if (youwin){
        cout << "congrats you beat the boss and won the game!!!! NICE!" << endl;
    }
    else {
        cout << "Game over! better luck next time!" << endl;
    }
}

//Function: diplaymap():
//description: generates a map so player can visualize what is going on

void Game::displaymap(){
    for (int i = 0; i < SIZE ; i++){
        for (int j = 0; j < SIZE ; j++){
            if (x == j && y == i){
                cout << "| P"  << board [j][i] -> display() << " ";
            }
            else{
                cout << "| "  << board [j][i] -> display() << "  ";
            }
        }
        cout << "|" << endl;
    }   
}
//function: displayinstruct()
//description: prints a few couts

void Game::displayinstruct(){
    cout << "Welcome to game!" << endl;
    cout << "------------------------------------------------"<< endl;
    cout << endl;
}
//function: pickdir()
//description: prints user options for moving

int Game::pickdir(){
   return  Mainmenu("pick a direction to move 1.Up , 2. Down , 3.Left , 4.Right :  ",1,4);

}
//function: move(int dir)
//description:takes in pickdir and then moves the player in the direction they wanted to move
// also checks to see if its valid 
void Game::move(int dir){
    int directions [][4] = {{-1,0},{1,0},{0,-1},{0,1}};
    int trialx = x + directions[dir-1][1];
    int trialy = y + directions[dir-1][0];
    //if (trialx < 0 ||trialy < 0 || trialx >= SIZE || trialy >= SIZE){
    if ((dir == 1 && board[x][y] -> getup() == NULL)||(dir == 2 && board[x][y] -> getdown() == NULL)||
    (dir == 3 && board[x][y] -> getleft() == NULL)||(dir == 4 && board[x][y] -> getright() == NULL)){
        cout << "cannot move off board!"<< endl;
        return;
    }
    bool flag = board[trialx][trialy] -> enter(player);
    if (flag == true){
        cout << "entered a new room! " << endl;
        x = trialx;
        y = trialy;

    }
    else {
        cout << "could not enter room!" << endl;
    }
}
//function: gamerules():
//description:prints out the rules to the game for the user

void Game::gamerules(){
    cout << "welcome to dungeon crawler! there is only 1 floor to this game!"<< endl;
    cout << "the objective of this game is to collect two specific items in order to defeat the floor boss"<<endl;
    cout << "and obtain any keys needed in order to open up locked rooms! this all must be done in a matter of time you have"<< endl;
    cout << "11 steps in order to complete this game!" << endl;
    cout << "I - depicts a Tool room no key is needed to go here" << endl;
    cout << "L - depicts a locked room and you must have a key to get in" << endl;
    cout << "B - depicts the boss room! " << endl;
    cout << "Good luck!" << endl;
}

// move self validate
// try to enter room base off of cords and bool in enter method
// enter class takes 