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
: word(w), frequency(1), TFIDF(0)
{}

Word(string w, int f)
: word(w), frequency(f), TFIDF(0)
{}


inline int operator< (const Word w) const {return word < w.getWord();};
inline bool operator== (const Word w) const {return word == w.getWord();};
inline const string& getWord() const {return word;};
inline int getfrequency() const {return frequency;};
inline void setfrequency(int f) {frequency = f;}; 

inline void incrFreq(int i) {frequency = frequency+i;};
inline bool isPunctuation() const {return ST.isPunctOnly(word);};
//inline bool isAlphaNumeric() const {return ST.isAlphaNumeric(word);};

void setTI( double n );
inline double getTFIDF() const {return TFIDF;};



private:

string word;
int frequency;
double TFIDF;
static StringTest ST;





};


#endif
