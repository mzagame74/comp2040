CC = g++
CFLAGS = -std=c++14 -c -g -Og -Wall -Werror -pedantic
OBJS = main.o CelestialBody.o Universe.o
LIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
EXE = NBody

all: $(EXE)

NBody: $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	\rm $(OBJS) $(EXE)