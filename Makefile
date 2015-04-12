CFLAGS = -Wall -std=c++11 -O1
LDFLAGS = -lSDL2 -lSDL2_image -lGL -lGLU `pkg-config --cflags --libs ftgl`

SRCDIR = src/
OBJDIR = obj/

SRC = $(wildcard $(SRCDIR)*.cpp)
OBJ = $(wildcard $(OBJDIR)*.o)

OUTPUT_FILE = game

#will compile and link all the above source files
all: 
	make $(OUTPUT_FILE)
#new rules for better compiling
$(OUTPUT_FILE): $(SRC)
	g++ $^ -o $@ $(CFLAGS) $(LDFLAGS)
$(OBJ): %: $(SRCDIR)%.cpp
	g++ $< $(CFLAGS) -o $@

#will do the same as all and afterwards run the game
run:
	g++ $(SRC) -o $(OUTPUT_FILE) $(CFLAGS) $(LDFLAGS) 
	./game
#will only link the .o files
link:
	g++ $(OBJ) -o $(OUTPUT_FILE) $(LDFLAGS)
#will only compile the .cpp files
compile:
	g++ $(SRC) -c $(CFLAGS) 
	mv *.o $(OBJDIR)
#make a single .o file (and link it afterwards)
%.o: $(SRCDIR)%.cpp 
	g++ $< -c $(CFLAGS) 
	mv *.o $(OBJDIR)
	g++ $(OBJ) -o $(OUTPUT_FILE) $(LDFLAGS)
#make a single .o file (and DON'T link)
%.o-: $(SRCDIR)%.cpp
	g++ $< -c $(CFLAGS) 		
	mv *.o $(OBJDIR)
clean:
	rm $(OBJDIR)*.o 
	if [ -f $(OUTPUT_FILE) ]; then rm OUTPUT_FILE; fi
