#include "Array.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath> 
#include <string> 
#include <sstream>
#include <cstdlib>
#include <climits> 
// Function : Array
// Description : array.cpp contains addanimal which will add animal to the array, removeanimal will
// remove an animal from the array also creates our "animal array" get animal returns the animal index
// get size returns the size of our animal array

Array::Array (){
cap = 10;
animals = new Animal * [10];
count  = 0;
}
//~Array is my destructor should remove all dynamic memory at the then of the program
Array::~Array(){
    for (int i = 0; i < count;i++){
        delete animals[i];
    }
    delete [] animals;
}

void Array::removeanimal(){
    if (count > 0){
        delete animals[count-1];
        count --;
    }

}

void Array::addanimal(Animal *a){
    // check the cap size of array and avoids mem leaks new needs a delete in order to clear array
    if (count >= cap){
        Animal **temp = new Animal * [cap * 2];
        for (int i = 0; i < cap; i ++){
            temp[i] = animals[i];
        }
        cap = 2 * cap;
        delete [] animals;
        animals = temp;

    }
    //places animal in array and figures re sizing
    animals [count] = a;
    count ++ ;

}

Animal *Array::getanimal(int index){

return animals[index];
}

int Array::getsize(){

return count;
 }