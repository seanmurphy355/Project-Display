// program: Project 1
// author:Sean Murphy 
// date: 07/05/2018
// description: project 1 Langston's Ant goal of this project
// is to review programming with dynamic arrays, convert program  requirments
// for design and implement the program design 
// input: This program will take in user input
// output: output will be a response to user input for our "ant"

#include <iostream>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
using std :: cin;
using std :: cout;
using std :: endl; 
// up = 0 down = 2 right = 1 left = 3
// this is the ant class 
 class Ant
{
    public:
    Ant (int x, int y); //use if user picks location
    Ant(); // random location
    void moveant(int **&board, int row,int col);
    int getx();
    void displayori();
    int gety();
    private:
    int x ,y , ori; 
};
