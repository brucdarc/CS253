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

bool isAlphaNumeric(const string& testStr);		//tests for special comma, period, apostrophe cases
bool isAlphaNumeric(char testChar);

bool isStartOfSentence(const vector<string> words, unsigned int index);	

bool needsPlusMarking(const vector<string> words, unsigned int index);		//to be able to mark some words with +

bool needsToBeBroken(const string testStr);		

bool isPeriodValid(const string& testStr, unsigned int index);
bool isCommaValid(const string& testStr, unsigned int index);




bool BreakUpWord(string testStr, vector<string> &words); // breaks the first valid word off of an input string and adds both to words vector

bool BreakUp(vector<string> &words);		//should contain recursive call if remaining needs to be broken

bool MarkSentStarts(vector<string> &words);

bool hasPEQ(const string& testStr);

bool isValidStart(const string& testStr);
bool isCaps(char testChar);
bool isLetter(char testChar);
bool isNumber(char testChar);
bool isSpecialPunctuation(char testChar);
bool isPunctOnly(const string& testStr);
bool isCharValid(const string& testStr, unsigned int index);
private:











};



#endif
