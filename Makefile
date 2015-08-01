CC = g++

CCFLAGS = -Wall -std=c++11 -O1 -I/usr/include/freetype2
LDFLAGS = -lSDL2 -lSDL2_image -lGL -lGLU `pkg-config --cflags --libs ftgl`

SRCDIR = src/
OBJDIR = obj/

SRC = $(wildcard $(SRCDIR)*.cpp)
OBJ = $(addprefix obj/,$(notdir $(SRC:.cpp=.o)))



EXECUTABLE = castles


$(EXECUTABLE):$(OBJ)
	$(CC) $(OBJ) -o $(EXECUTABLE) $(LDFLAGS)

obj/%.o:src/%.cpp

	$(CC) -c $(CCFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
