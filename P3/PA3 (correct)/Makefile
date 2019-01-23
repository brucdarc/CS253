# : 
#	g++ main.cpp FileCount.cpp -I. -o demo
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall
OBJS = main.o FileCount.o StringTest.o
INCLUDE = -I.

PA3 : main.o FileCount.o StringTest.o
	$(CC) $(OBJS) $(INCLUDE) $(LFLAGS) -o PA3

main.o : main.cpp FileCount.h StringTest.h
	$(CC) main.cpp $(INCLUDE) $(CFLAGS)

FileCount.o : FileCount.cpp FileCount.h
	$(CC) FileCount.cpp $(INCLUDE) $(CFLAGS)

StringTest.o : StringTest.cpp StringTest.h
	$(CC) StringTest.cpp $(INCLUDE) $(CFLAGS)

