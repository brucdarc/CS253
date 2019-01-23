#ifndef AddExceptions_H
#define EddExceptions_H

#include<iostream>
#include<fstream>
using std::istream;
using std::ostream;
#include <vector>
#include <string>
#include <StringTest.h>
#include <GrammarMachine.h>

#include <sstream>
using std::stringstream;
using std::string;
using std::vector;



class AddExceptions {



public:


bool readIn(istream& eStr);
bool stringB(stringstream& line);
bool stem(vector<string> &words);
bool stem(string &word);
bool checkAndReplace(string& word);








private: 

vector<std::string> exceptions;
vector<std::string> stems;



};

#endif
