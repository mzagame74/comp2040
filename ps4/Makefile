CC = g++
CFLAGS = -std=c++11 -c -g -O2 -Wall -Werror -pedantic
LIBS = -lsfml-system
OBJS = main.o ED.o
EXE = ED

all : $(EXE)

$(EXE) : $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LIBS)

%.o : %.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean :
	\rm $(EXE) $(OBJS)