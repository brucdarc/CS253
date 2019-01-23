# : 
#	g++ main.cpp FileCount.cpp -I. -o demo
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall
OBJS = main.o FileCount.o StringTest.o GrammarMachine.o Except.o AddExceptions.o Word.o Document.o DocManager.o
HEADERS = FileCount.h StringTest.h GrammarMachine.h Except.h AddExceptions.h Word.h Document.h DocManager.h
INCLUDE = -I.

PA6 : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE) $(LFLAGS) -o PA7

main.o : main.cpp $(HEADERS)
	$(CC) main.cpp $(INCLUDE) $(CFLAGS)

FileCount.o : FileCount.cpp $(HEADERS)
	$(CC) FileCount.cpp $(INCLUDE) $(CFLAGS)

StringTest.o : StringTest.cpp StringTest.h
	$(CC) StringTest.cpp $(INCLUDE) $(CFLAGS)

GrammarMachine.o : GrammarMachine.cpp GrammarMachine.h StringTest.h
	$(CC) GrammarMachine.cpp $(INCLUDE) $(CFLAGS)

Except.o : Except.cpp Except.h GrammarMachine.h StringTest.h
	$(CC) Except.cpp $(INCLUDE) $(CFLAGS)

AddExceptions.o : AddExceptions.cpp AddExceptions.h GrammarMachine.h StringTest.h
	$(CC) AddExceptions.cpp $(INCLUDE) $(CFLAGS)

Word.o : StringTest.h Word.cpp Word.h
	$(CC) Word.cpp $(INCLUDE) $(CFLAGS)

Document.o : AddExceptions.h GrammarMachine.h StringTest.h Document.cpp Document.h Word.h
	$(CC) Document.cpp $(INCLUDE) $(CFLAGS)

DocManager.o : AddExceptions.h GrammarMachine.h StringTest.h Document.h Word.h DocManager.h DocManager.cpp
	$(CC) DocManager.cpp $(INCLUDE) $(CFLAGS)


Clean:
	rm -f $(OBJS) *.o
	rm -f PA7
	echo Clean done
