CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
OBJS = PhotoMagic.o FibLFSR.o
EXE = PhotoMagic

all : $(EXE)

PhotoMagic : $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(LIBS)

PhotoMagic.o : PhotoMagic.cpp
	$(CC) $(CFLAGS) PhotoMagic.cpp

FibLFSR.o : FibLFSR.cpp FibLFSR.h
	$(CC) $(CFLAGS) FibLFSR.cpp

clean :
	\rm *.o $(EXE)