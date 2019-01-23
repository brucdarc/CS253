# : 
#	g++ main.cpp FileCount.cpp -I. -o demo
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall
OBJS = main.o FileCount.o StringTest.o GrammarMachine.o
INCLUDE = -I.

PA4 : main.o FileCount.o StringTest.o GrammarMachine.o
	$(CC) $(OBJS) $(INCLUDE) $(LFLAGS) -o PA4

main.o : main.cpp FileCount.h StringTest.h GrammarMachine.h
	$(CC) main.cpp $(INCLUDE) $(CFLAGS)

FileCount.o : FileCount.cpp FileCount.h StringTest.h GrammarMachine.h
	$(CC) FileCount.cpp $(INCLUDE) $(CFLAGS)

StringTest.o : StringTest.cpp StringTest.h
	$(CC) StringTest.cpp $(INCLUDE) $(CFLAGS)

GrammarMachine.o : GrammarMachine.cpp GrammarMachine.h StringTest.h
	$(CC) GrammarMachine.cpp $(INCLUDE) $(CFLAGS)

