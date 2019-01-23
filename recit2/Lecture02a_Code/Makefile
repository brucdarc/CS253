#demo : 
#	g++ main.cpp Complex.cpp -I. -o demo
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall
OBJS = main.o Complex.o
INCLUDE = -I.

demo : $(OBJS)
#compile objects into one program file
	$(CC) $(OBJS) $(INCLUDE) $(LFLAGS) -o demo


#check main dependencies
main.o : main.cpp Complex.h
#compile main
	$(CC) main.cpp $(INCLUDE) $(CFLAGS)


#check Complex dependencies
Complex.o : Complex.cpp Complex.h
#Compile Complex
	$(CC) Complex.cpp $(INCLUDE) $(CFLAGS)

clean:
#remove everything after -rm
	-rm *.o demo



