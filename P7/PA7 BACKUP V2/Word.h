#ifndef Word_H
#define Word_H


#include <vector>
#include <string>
#include <StringTest.h>
using std::string;
using std::vector;
#include <iostream>
using std::endl;
using std::cout;









class Word {


public:

Word(string w)
: word(w), frequency(1), TFIDF(0)	//constructor with just word passed default frequency is 1
{}

Word(string w, int f)
: word(w), frequency(f), TFIDF(0)	//constructor that sets the frequency of a word as well
{}


inline int operator< (const Word w) const {return word < w.getWord();};		//overloading operator to allow sorting algorithms to sort instances of this object
										//makes it sort based on only the string data field
inline bool operator== (const Word w) const {return word == w.getWord();};	//overloaded operator to be able to tell if string data fields are equal and used by some STD functions
inline const string& getWord() const {return word;};				//accessor for word string
inline int getfrequency() const {return frequency;};				//accessor for frequency
inline void setfrequency(int f) {frequency = f;}; 				//mutator for frequency

inline void incrFreq(int i) {frequency = frequency+i;};				//increments frequency by 1
inline bool isPunctuation() const {return ST.isPunctOnly(word);};		//returns true if this word is punctuation only. used to skip punctuation in comparing simularity
//inline bool isAlphaNumeric() const {return ST.isAlphaNumeric(word);};

void setTI( double n );					//sets tfidf 
inline double getTFIDF() const {return TFIDF;};		//gets tfidf

inline bool isSentEnd() {return ST.isSentEnd(word);};

inline bool isAlphaNumeric() {return ST.isAlphaNumeric(word);};

inline int size() {return word.size();};


private:

string word;		//word for this object
int frequency;		//frequency of that word
double TFIDF;		//tfidf value of this word based on the doc it is in and docs it is with
static StringTest ST;	//a stringtest object to call some methods from within it





};


#endif
