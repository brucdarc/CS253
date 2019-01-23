#include <AddExceptions.h>

#include <StringTest.h>
#include <GrammarMachine.h>

#include <iostream>
#include <sstream>
using std::endl;
using std::cout;

#include <vector>
#include <string>
using std:: string;
using std::vector;
using std::stringstream;

bool AddExceptions::readIn(istream& eStr)
{
if(eStr.fail()) 		//test if file is empty before starting
{
	// stop the method if the file is empty
	return true;
}
string current;
string word;
int i =1;
do{
std::getline(eStr,current);	//read one line into current
if(eStr.fail() && !eStr.eof()) return false;
//cout << "current string:: " << current << endl;
//if( (current.size() == 0) && eStr.eof() ) return true;
stringstream line(current);	//create a stringstream off of string give it to helper
if(!stringB(line)) return false;
i++;
}
while(!eStr.eof());
//cout << "exiting adding words to vectors" << endl;
return true;
}



bool AddExceptions::stringB(stringstream& line){
/*
checks if the line is empty by checking if the first word doesnt read in
if it doesnt returns true because that is an ok line in a file

checks the second word. if there is no second word returns false and prints that file is
incorrectly formatted

checks if there is a third word. if there is, returns error and tells
formating is incorrect

*/
//cout << "entering stringline breakup" << endl;
string word1;
line >> word1;


if(word1.size() == 0) return true;
string word2;
line >> word2;

if(word2.size() == 0){
std::cerr << "file formatted incorrectly" << endl;
 return false;
}

string word3;
line >> word3;

if(word3.size() != 0){
std::cerr << "file formatted incorrectly" << endl;
 return false;
}

exceptions.push_back(word1);
stems.push_back(word2);
return true;
}


bool AddExceptions::stem(vector<string> &words){

for(unsigned int i=0;i<words.size();i++)
{
stem(words[i]);
}
return true;
}

bool AddExceptions::stem(string& word){

GrammarMachine h;
if(h.needsGrammarification(word))
{

if(!checkAndReplace(word))
{
h.doSteps(word);
}
}
return true;
}

bool AddExceptions::checkAndReplace(string& word)
{
for(unsigned int i = 0;i<exceptions.size();i++)
{
if(word == exceptions.at(i))
{
word = stems.at(i);
return true;
}
//end of if statement

}
//end of for loop
return false;
}






