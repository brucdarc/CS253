CC = g++
CFLAGS = -Wall -c
#new lflags to link gtest and pthread -l stands for library
LFLAGS = -Wall -lgtest -lpthread
#new include for other directory
INCLUDE = -I../

testAll : test_all.cpp
	$(CC) $(INCLUDE) $(LFLAGS) test_all.cpp ../stem.o -o testAll
#have to add ../PA4?stem.o needed to locate stem.o
