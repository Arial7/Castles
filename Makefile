CFLAGS = -Wall -std=c++11 -O1
LDFLAGS = -lSDL2 -lSDL2_image -lGL -lGLU `pkg-config --cflags --libs ftgl`

SRCDIR = src/
OBJDIR = obj/

SRC = $(wildcard $(SRCDIR)*.cpp)
OBJ = $(wildcard $(OBJDIR)*.o)

#will compile and link all the above source files
all:
	g++ $(SRC) -o game $(CFLAGS) $(LDFLAGS) 
#will do the same as all and afterwards run the game
run:
	g++ $(SRC) -o game $(CFLAGS) $(LDFLAGS) 
	./game
#will only link the .o files
link:
	g++ $(OBJ) -o game $(LDFLAGS)
#will only compile the .cpp files
compile:
	g++ $(SRC) -c $(CFLAGS) 
	mv *.o $(OBJDIR)
#make a single .o file (and link it afterwards)
%.o: $(SRCDIR)%.cpp 
	g++ $< -c $(CFLAGS) 
	mv *.o $(OBJDIR)
	g++ $(OBJ) -o game $(LDFLAGS)
#make a single .o file (and DON'T link)
%.o-: $(SRCDIR)%.cpp
	g++ $< -c $(CFLAGS) 		
	mv *.o $(OBJDIR)
clean:
	rm $(OBJDIR)/*.o 
	rm game
