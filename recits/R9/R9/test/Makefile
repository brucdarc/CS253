CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall -lgtest -lpthread
OBJS = test_main.o test_portAlg.o test_helperFunct.o ../PA4/stem.o
INCLUDE = -I../PA4

testAll: $(OBJS)
	$(CC) $(LFLAGS) $(INCLUDE) $(OBJS) -o testAll



test_main.o: test_main.cpp
	$(CC) $(CFLAGS) $(INCLUDE) test_main.cpp


test_portAlg.o: test_portAlg.cpp
	$(CC) $(CFLAGS) $(INCLUDE) test_portAlg.cpp

test_helperFunct.o: test_helperFunct.cpp
	$(CC) $(CFLAGS) $(INCLUDE) test_helperFunct.cpp
