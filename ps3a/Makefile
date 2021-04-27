CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
LIBS = -lboost_unit_test_framework
OBJS = test.o CircularBuffer.o
EXE = ps3a

all : $(EXE)

$(EXE) : $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(LIBS)

%.o : %.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean :
	\rm $(OBJS) $(EXE)