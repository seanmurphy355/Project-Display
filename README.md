# Terminal-Games
This repository holds my past coding projects using C++ object oriented programing


### Built With
* [Microsoft Visual Studio](https://visualstudio.microsoft.com/pl/) - IDE
* [C++](https://en.wikipedia.org/wiki/C%2B%2B) -Standard Language 

# Introduction to Structs
In C++, classes and structs are used as blueprints in order to create an instance of a class. Structs are used as low level objects which allow for the programer to group variables of mixed data types togther into a single unit. Unlike a class, structs in C++ are value type rather than reference type. Structs allow for a programer to bunch smaller variables into one larger entity such as a "Player".Our player might have several different attributes the struct keyword allows for us to glue togther a player. We are able to give our player a name as well as health points while using a struct the struct keyword. 

# Example Implementation of a Struct
- This implementation defines a Player as a structure of type Player
```sh
struct Player
{
  string name;
  int healthPoints;
};
```
# Introduction to the Constructor
The C++ constructor is a member function of a class which allows for the initialization of  class objects. Constructors are used to eliminate default values by user defined values.Whenever we generate an object of a class the constructor then allocates memory for all the data properties to be initialized to their default values.The general purpose of a constructor is to initialize the object of a class note: constructors do not have a return type.

# Example Implementation of a Constructor
```sh
// decleration of constructor, functions/methods , potential inheritance that this class might use
// including public and private data types
class Medusa : public Character {
public:
Medusa();
void dedlifepts(int dedpts);
int attack();



private:



};
#endif
```

# Dungeon Crawler Explanation!
This is a low level implementaion of a dungeon crawler game. There is only one floor to the game and the user gets 11 turns to move.The user must find all of the keys and items in order to defeat the boss that is in the final room. 
```sh
I - Depicts tool room.
L - Depicts a locked room.
B - Depicts the boss room.
p - Depicts the players location.
```
# Preview of the Dungeon Crawler game 
About: Each of the games in this repository were built only to run on in the terminal. The goal of these projects were to improve my skills in object oriented programing.  

![Game](https://user-images.githubusercontent.com/51139158/74704553-a234d500-51c5-11ea-8da5-0e01b5d93408.gif)

### Contributor

* **Sean Murphy** - [SeanMurphy355](https://github.com/Seanmurphy355)

##
