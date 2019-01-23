#include <StringTest.h>

#include <iostream>
using std::endl;
using std::cout;

#include <vector>
#include <string>
using std:: string;



bool StringTest::isCaps(char testChar){				//tests if char is capital letter
if(testChar > 64 && testChar<91) return true;
return false;
}


bool StringTest::isLetter(char testChar){				//tests if char is letter
if(isCaps(testChar) || (testChar>96 && testChar<123)) return true;
return false;
}
/*
bool StringTest::isNumber2(char testChar){	//tests if char is number
if(testChar > 47 && testChar<58) return true;
return false;
}
*/


bool StringTest::isNumber(char testChar){	//tests if char is number
if(testChar > 47 && testChar<58) return true;
return false;
}

bool StringTest::isPunctOnly(const string& testStr)	//tests if a string is only punctuation
{

for(unsigned int i = 0;i<testStr.size();i++)
{
if(isAlphaNumeric(testStr.at(i))) return false;
}
return true;
}

bool StringTest::isAlphaNumeric(char testChar){


if(isLetter(testChar) || isNumber(testChar) || testChar == 39) return true;	//39 is apostrophe
return false;
}



bool StringTest::isPeriodValid(const string& testStr, unsigned int index){		//tests if period is followed by number and preceded by number or blank space
//cout<< "In period test, current word: " << testStr << " index: " << index << endl;
	
if(index < 0 ) throw std::exception();
if(index > (testStr.size()-1) ) throw std::exception();			//throw exception if index is out of bounds

//cout<< "In period test, point 1 " << endl;

if(testStr.at(index) != 46) return false;	//makes sure index has period

//cout<< "In period test, point 2 " << endl;

if((testStr.size()-1) == index) return false;			//tests if period is at end of word

//cout<< "In period test, point 3 " << endl;

if(index == 0)
{
	if( isNumber(testStr.at(index+1)) ) return true;	//tests if period is at beggining and has number after
else return false;
}
//cout<< "In period test, point 4 " << endl;

if( isNumber(testStr.at(index-1)) && isNumber(testStr.at(index+1)) ) return true;	//tests if period has a number on both sides
//cout<< "In period test, point 5 " << endl;
return false;
}

bool StringTest::isCharValid(const string& testStr, unsigned int index)
{
if( (isCommaValid(testStr,index)) || (isPeriodValid(testStr,index)) || (isAlphaNumeric(testStr.at(index))) )
return true;
else return false;


}



bool StringTest::isCommaValid(const string& testStr, unsigned int index){		//tests if comma is between two numbers
if(index < 0 ) throw std::exception();
if(index > (testStr.size()-1) ) throw std::exception();			//throw exception if index is out of bounds

if(testStr.at(index) != 44) return false;	//makes sure index has comma

if((testStr.size()-1) == index) return false;				//tests if comma is at end
if(index == 0) return false;						//tests if comma is at beggining
if( isNumber(testStr.at(index-1)) && isNumber(testStr.at(index+1)) ) return true;	//test is comma has number on both sides
return false;
}



bool StringTest::isAlphaNumeric(const string& testStr){
for(unsigned int i=0;i<testStr.size();i++){		//loop through all chars in string
char current = testStr.at(i);
if(isAlphaNumeric(current));
				//test for alphanumeric
else{

if(! (current == 44 || current == 46)) return false;	//returns false if there are punctuations besides . ,

if(current == 44) 
	if(!(isCommaValid(testStr,i))) return false;	//test comma word validity
if(current == 46) 
		if(!(isPeriodValid(testStr,i))) return false;	//test period word validity
}
}
return true;		// if the program gets out of the loop without returning false the word is valid with the punctuation as it is
}

/*
this method breaks up a string into any valid words inside it according to the rules specified in P3
if a string is already a word it does nothing to it
*/
bool StringTest::BreakUpWord(string testStr, vector<string> &words)
{
if(isCharValid(testStr,0))	//tests if string starts with alphanumeric word or punctuation word
/*
following code if for the case where string starts with alphanumeric word
*/
{
int stopLength;



if(isAlphaNumeric(testStr))	//if the whole string is already a word add it and return
{
//cout << "adding: " << testStr <<endl;
words.push_back(testStr);
return true;
}
/*
iterate until a char is not valid for alphanumeric then split the string, 
add the alphanumeric word at the beggining to the vector
then recursive call on the remaining part of the string
*/
for(unsigned int i=0;i<testStr.size();i++)	
{

if(!isCharValid(testStr,i)) {
stopLength = i;
words.push_back(testStr.substr(0,stopLength));
int remLength = testStr.size() - (stopLength);

/*
cout<< "string : " << testStr << endl;
cout<< "part 1 : " << testStr.substr(0,stopLength) << endl;
cout<< "part 2 : " << testStr.substr(i,remLength) << endl;
cout<< "remlength: " << remLength << endl;
cout<< "i: " << i << endl;
*/

BreakUpWord(testStr.substr(i,remLength),words);
return true;
}
}
}
/*
code below is for beggining punctuation word case

*/
else
{
int stopLength;



//if string is valid punctuation word add it to vector
if(isPunctOnly(testStr))
{
//cout << "adding: " << testStr <<endl;
words.push_back(testStr);
return true;
}

/*
iterate until a char is not valid for punctuation then split the string, 
add the punctuation word at the beggining to the vector
then recursive call on the remaining part of the string
*/

for(unsigned int i=0;i<testStr.size();i++)
{

if(isCharValid(testStr,i)) {
stopLength = i;
words.push_back(testStr.substr(0,stopLength));
int remLength = testStr.size() - (stopLength);

/*
cout<< "string : " << testStr << endl;
cout<< "part 1 : " << testStr.substr(0,stopLength) << endl;
cout<< "part 2 : " << testStr.substr(i,remLength) << endl;
cout<< "remlength: " << remLength << endl;
cout<< "i: " << i << endl;
*/

BreakUpWord(testStr.substr(i,remLength),words);
return true;
}

}
}

return true;
}



bool StringTest::BreakUp(vector<string> &words)  //breaks up each string into words
{
string testStr = words.at(0); 
vector<string> result;

for(unsigned int i=0;i<words.size();i++)	//calls helper method on each word and adds it to a new vector
{
testStr = words.at(i);
//cout<< "current word: " << testStr << endl;
BreakUpWord(testStr,result);
//cout<< "reached end of breakupword" << endl;
}

//cout<< "reached end of breakupword" << endl;

words = result;			//make the parameter vector equal to the valid words vector
return true;
}


bool StringTest::MarkSentStarts(vector<string> &words)
{
string test = words.at(0);
if(isCaps(test.at(0)))
words[0] = "+" + words[0];

if(words.size() == 1) return true;

for(unsigned int i = 1; i<words.size();i++)
{
if(isPunctOnly(words.at(i-1)))
{
if(isCaps(words.at(i).at(0)))
words[i] = "+" + words[i];


}
}








return true;


}







