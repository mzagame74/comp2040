CC = g++
CFLAGS = -std=c++11 -c -g -O1 -Wall -Werror -pedantic
LIBS = -lboost_unit_test_framework
OBJS = TextGenerator.o MModel.o
EXE = TextGenerator

all : $(EXE)

$(EXE) : $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LIBS)

%.o : %.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean :
	\rm $(EXE) $(OBJS)
