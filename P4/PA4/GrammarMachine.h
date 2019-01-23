#ifndef GrammerMachine_H
#define GrammerMachine_H

#include<iostream>
#include<fstream>
using std::istream;
using std::ostream;
#include <vector>
#include <string>
#include <StringTest.h>
using std::string;
using std::vector;

class GrammarMachine {


public:



bool needsGrammarification (const string& testStr); 
//tests if a words should be sent through the grammar algorithim

bool isVowel(const string& testStr, unsigned int index);
//test if a char is a vowel

bool isDouble(const string& testStr);
//tests if a string of 2 chars is a double

bool isLIending(char test);
//tests if a char is an LI ending

bool isEmpty(const string& testStr);

bool isRegion1Empty(const string& testStr);

bool isRegion2Empty(const string& testStr);

string getRegion1(const string& testStr);
//returns region 1 of the word

string getRegion2(const string& testStr);
//returns region 2 of the word

bool hasSuffix(const string& testStr, const string& suffix);
//returns true if a word has the suffix, (even if suffix is whole word)

string getPreceder(const string& testStr, const string& suffix);
//chops the suffix off of a word and returns the preceder. 
//if the word doesnt have the suffix returns the word as is

string replaceSuffix(const string& testStr, const string& suffix, const string& replacement);

int getRegionOfSuffix(const string& testStr, const string& suffix);

bool endsInSS(const string& testStr);

bool isShort(const string& testStr);

bool containsVowel(const string& testStr);

string testAndReplace(const string& testStr, vector<string> suffixes, vector<string> replacements);

string testAndReplace(const string& testStr, vector<string> suffixes, vector<string> replacements, int region);

string testAndReplace(const string& testStr, vector<string> suffixes, int region);

string step1(const string& testStr);

string step2(const string& testStr);

string step3(const string& testStr);

string step4(const string& testStr);

string step5(const string& testStr);

string step6(const string& testStr);

string step7(const string& testStr);

string step8(const string& testStr);

bool doSteps(vector<string> &words);

private:



StringTest sTest;






};


#endif
