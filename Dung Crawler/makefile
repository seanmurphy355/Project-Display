# Declaration of variables
CC = g++
CC_FLAGS = -w -Wall
 
# File names
EXEC = final
SOURCES = main.cpp space.cpp mainmenu.cpp lockedspace.cpp game.cpp player.cpp boss.cpp toolroom.cpp item.cpp
OBJECTS = $(SOURCES:.cpp=.o)
 
# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)
 
# To obtain object files
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
