#ifndef Document_H
#define Document_H
#include<iostream>
#include <Word.h>
#include <vector>
#include <string>
#include <StringTest.h>
using std::string;
using std::vector;



class Document {


public:

Document (vector<Word> words);		//initialized wds then sorts it to be in lexographical order

bool contains(const Word &w) const;	//uses binary seach and returns true if the string in word matches a string in another word in the wds array
bool add(Word w);			//not implemented
bool setTFIDFs( vector<Document> &Docs);		//sets the TFIDFS by calling setTFIDF for every word in this document
bool setTFIDF( vector<Document> &Docs, Word &w);	//sets the TFIDF by getting the idf of a word, and using the frequency of it in this document
double getIDF( vector<Document> &Docs, Word &w);	//uses contains method on all the other docs to find out if they have this word then calculates if 
							//IDF based on the docs that contain it and num of docs
double Sim( Document &Other);				//multiplies the TFIDFs of all words that this doc and the parameter have in common. uses the find method on other document
inline Word& at(int index) {return wds.at(index);};	//accessor that works like at for other data structures, but returns a non constant reference
Word& find( Word &w);					//binary searches with an implimentation i wrote myself and returns a word whose string matches the args string and returns a reference 
							//to the word in this doc
int findIndex( Word &w, int min, int max);		//helper recursive method to help find binary search for something






private:

vector<Word> wds;


};

#endif
