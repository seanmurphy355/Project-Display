# Declaration of variables
CC = g++
iCC_FLAGS = -w
 
# File names
EXEC = two
SOURCES = ProjTwo.cpp mainmenu.cpp Animal.cpp tiger.cpp penguin.cpp turtle.cpp zoo.cpp Array.cpp
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