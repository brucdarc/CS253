#ifndef Except_H
#define Except_H

#include<iostream>
#include<fstream>
using std::istream;
using std::ostream;
#include <vector>
#include <string>
#include <StringTest.h>
using std::string;
using std::vector;



class Except{



public:


bool capsTest(vector<string> &words);
bool isPlus(const string &testStr);
bool capsTest(const string &testStr);
bool makeLower(string &testStr);
bool capsFind(const vector<string> &words, string &testStr);
















private: 






};

#endif

