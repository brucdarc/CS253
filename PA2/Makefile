# : 
#	g++ main.cpp FileCount.cpp -I. -o demo
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall
OBJS = main.o FileCount.o
INCLUDE = -I.

PA1 : main.o FileCount.o
	$(CC) $(OBJS) $(INCLUDE) $(LFLAGS) -o PA2

main.o : main.cpp FileCount.h
	$(CC) main.cpp $(INCLUDE) $(CFLAGS)

FileCount.o : FileCount.cpp FileCount.h
	$(CC) FileCount.cpp $(INCLUDE) $(CFLAGS)

