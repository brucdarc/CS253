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
/**
*	@brief Document constructor
*
*Takes in a vector of words, and sorts in using the standard sort algorithm
*Some operators in the word class are overloaded to support standard 
*functions being able to work on the words.
*
*@code
*std::sort(wds.begin(), wds.end());
*@endcode
*
*
*
*@param words Vector of words that will be sorted
*
*@return its a constructor
*
*
*@warning words vector should have no words with duplicate strings
*
*
*/
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

/**
*@ brief getNumSents
*
*uses the definition of sentence ending punctuation from stringtest 
*to decide if something ends a sentence and counts how many strings have that
*property
*
*@return number of sentences in the file. 
*@warning sentence can be empty
*/

int getNumSents();	// returns the number of PEQ punct words that break sentences
int getNumAlphaWords();	// returns number of alphanumeric words according to definition
int getNumAlphaWordsChars();	// counts the chars in each alphanumeric word
double getS();	//returns sentence calculation part of readinglevel calculation
double getL();	//returns words part of calculation in reading level
inline bool getFail() {return failed;}	//tells if anything as failed in processes done on the doc
double getReadingLevel(); // returns from equation, .whatever * L - .whatever * S - 15.whatever




private:

vector<Word> wds;
bool failed; //keeps tract of if things done on document have failed

};

#endif
