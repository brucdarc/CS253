#include <Except.h>
#include <StringTest.h>
#include <iostream>
using std::endl;
using std::cout;

#include <vector>
#include <string>
using std:: string;
using std::vector;




bool Except::capsTest(vector<string> &words){
//in this function, if we find a word with a +, we call our helper on it to see if it should
//remain caps or become lower case
//cout << "inside capsTesting size: " << words.size() << endl;
for(unsigned int i=0; i< words.size();i++)
{
if(isPlus(words.at(i)))
{
//cout << " index: " << i << " current word: " << words.at(i)  << endl;
string temp = words[i].substr(1,words[i].size()-1);
capsFind(words,temp);
words[i] = temp;
}
}
//end of forloop1

return true;
}

bool Except::capsFind(const vector<string> &words, string &testStr){
//looks through the vector and makes testStr lower case starting
//if it does not appear capitalized
for(unsigned int k=0; k< words.size();k++)
{

string test = words[k];

//test if uppercase version appears
if(testStr == test)
{
if(capsTest(words[k]))
{ 
return true;
}
}
//end if if statements

}
//end of for loop
makeLower(testStr);
return false;
}




bool Except::isPlus(const string &testStr){
if(testStr.size() == 0) return false;
if(testStr.at(0) == '+') return true;
else return false;
}

bool Except::capsTest(const string &testStr){
if(testStr.size() == 0) return false;
StringTest t;
if(t.isCaps(testStr.at(0))) return true;
return false;
}

bool Except::makeLower(string &testStr){
if(testStr.size() == 0) return false;
char test = testStr.at(0);
StringTest t;
if(t.isCaps(test))
{
testStr[0] = test+32;
}
return true;
}

