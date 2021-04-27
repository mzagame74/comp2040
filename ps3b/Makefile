CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
LIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
OBJS = KSGuitarSim.o StringSound.o CircularBuffer.o
EXE = KSGuitarSim

all : $(EXE)

$(EXE) : $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(LIBS)

%.o : %.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean :
	\rm $(OBJS) $(EXE)