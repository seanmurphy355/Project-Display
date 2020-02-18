# Terminal-Games
This repository holds my past coding projects using C++ object oriented programing


### Built With
* [Microsoft Visual Studio](https://visualstudio.microsoft.com/pl/) - IDE
* [C++](https://en.wikipedia.org/wiki/C%2B%2B) -Standard Language 

# Introduction to Structs
In C++,classes and structs are used as blueprints in order to create an instance of a class.Structs are used as low level objects which allow for the programer to group variables of a mixed data type togther into a single unit.Unlike a class, stucts in C++ are value type rather than reference type.These user defined data types allow for us to create objects such as entities in a game.

# Example Implementation of a Struct
- This implementation defines a dynamic array as a structure of type DynArr
```sh
struct DynArr
{
	TYPE *data;	/* pointer to the array containing data */
	int size;	/* Number of elements in the array */
	int capacity;	/* capacity of the array */
};
```

# Dungeon Crawler Explanation!
This is a low level implementaion of a dungeon crawler game. There is only 1 floor to the game and the user gets 11 turns to move.The user must find all of the keys and items in order to defeat the boss that is in the final room. 
```sh
I - Depicts tool room.
L - Depicts a locked room.
B - Depicts the boss room.
p - Depicts the players location.
```
# Preview of the Dungeon Crawler game 
About:Each game in this repository was built using the same tools and function similarly to the example below. 

![Game](https://user-images.githubusercontent.com/51139158/74704553-a234d500-51c5-11ea-8da5-0e01b5d93408.gif)

### Contributor

* **Sean Murphy** - [SeanMurphy355](https://github.com/Seanmurphy355)

##
