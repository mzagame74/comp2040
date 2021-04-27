CC = g++
CFLAGS = -std=c++11 -c -g -O1 -Wall -Werror -pedantic
LIBS = -lboost_regex -lboost_date_time
OBJS = main.o
EXE = ps6

all : $(EXE)

$(EXE) : $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LIBS)

%.o : %.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean :
	\rm $(EXE) $(OBJS)
