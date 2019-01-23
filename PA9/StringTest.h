#ifndef StringTest_H
#define StringTest_H

#include<iostream>
#include<fstream>
using std::istream;
using std::ostream;
#include <vector>
#include <string>
using std::string;
using std::vector;

class StringTest {


public:

StringTest()
{
}



bool isAcronym(const string testStr);

static bool isAlphaNumeric(const string& testStr);		//tests for special comma, period, apostrophe cases
static bool isAlphaNumeric(char testChar);

bool isStartOfSentence(const vector<string> words, unsigned int index);	

bool needsPlusMarking(const vector<string> words, unsigned int index);		//to be able to mark some words with +

bool needsToBeBroken(const string testStr);		

static bool isPeriodValid(const string& testStr, unsigned int index);
static bool isCommaValid(const string& testStr, unsigned int index);







//CHANGE
bool BreakUpWord(string testStr, vector<string> &words); // breaks the first valid word off of an input string and adds both to words vector

//CHANGE
bool BreakUp(vector<string> &words);		//should contain recursive call if remaining needs to be broken

//CHANGE
bool MarkSentStarts(vector<string> &words); 








static bool hasPEQ(const string& testStr);	//has period exclamation and/or questionmark

inline static bool isSentEnd(const string& testStr) {return hasPEQ(testStr) && isPunctOnly(testStr);};

bool isValidStart(const string& testStr);	//checks if has only one caps at start
static bool isCaps(char testChar);
static bool isLetter(char testChar);
static bool isNumber(char testChar);
bool isSpecialPunctuation(char testChar);	//checks if special punctuation cases are needed
static bool isPunctOnly(const string& testStr);
bool isCharValid(const string& testStr, unsigned int index);
private:











};



#endif