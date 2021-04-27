CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic 
LFLAGS = -lboost_unit_test_framework
OBJS = test.o FibLFSR.o
EXE = ps1a

all : $(EXE)

ps1a : $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(LFLAGS)

test.o : test.cpp
	$(CC) $(CFLAGS) test.cpp

FibLFSR.o : FibLFSR.cpp FibLFSR.h
	$(CC) $(CFLAGS) FibLFSR.cpp

clean :
	\rm *.o $(EXE)