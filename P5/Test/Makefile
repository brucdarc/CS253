CC = g++
CFLAGS = -Wall -c
#new lflags to link gtest and pthread -l stands for library
LFLAGS = -Wall -lgtest -lpthread
#new include for other directory
INCLUDE = -I../PA5
OBJS = ../PA5/Except.o ../PA5/GrammarMachine.o ../PA5/StringTest.o test_GrammarMachine.o  test_AddExceptions.o test_main.o

testAll :$(OBJS)
	$(CC) $(INCLUDE) $(LFLAGS) $(OBJS) -o testAll
#have to add ../PA4?stem.o needed to locate stem.o

test_main.o: test_main.cpp
	$(CC) $(CFLAGS) $(INCLUDE) test_main.cpp

test_GrammarMachine.o: test_GrammarMachine.cpp
	$(CC) $(CFLAGS) $(INCLUDE) test_GrammarMachine.cpp

test_AddExceptions.o: test_AddExceptions.cpp
	$(CC) $(CFLAGS) $(INCLUDE) test_AddExceptions.cpp

