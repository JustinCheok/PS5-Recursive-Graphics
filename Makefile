CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic -std=c++11 -l boost_unit_test_framework -o2
OBJ = TFractal.o Triangle.o
DEPS = TFractal.cpp Triangle.cpp
LIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
EXE = Triangle

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<
	
clean:
	rm $(OBJ) $(EXE)
