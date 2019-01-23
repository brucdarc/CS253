#include <GrammarMachine.h>

#include <iostream>
using std::endl;
using std::cout;

#include <vector>
#include <string>
using std:: string;
using std::vector;



bool GrammarMachine::needsGrammarification (const string& testStr)
//checks if word is longer than 3 char, and contains only letters that are lower case
{
if(testStr.size() < 3) return false;
for(unsigned int i=0;i<testStr.size();i++)
{
char t = testStr.at(i);
if(sTest.isCaps(t)) return false;
if(!sTest.isLetter(t)) return false;
}
return true;
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

bool isEmpty(const string& testStr){
if(testStr == "") return true;
return false;
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------


bool GrammarMachine::isVowel(const string& testStr, unsigned int index)
//if char is a a e i o u returns ture, if y returns true only if follows consonant
{
char t = testStr.at(index);
if( (t == 'a') || (t == 'e') || (t == 'i') || (t == 'o') || (t == 'u')) return true;

if(t== 'y') 
{
if(index==0) return false;
if( isVowel(testStr, index-1 )) return false;
return true;
}

return false;
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

bool GrammarMachine::isRegion1Empty(const string& testStr)
{
if(getRegion1(testStr) == "") return true;
return false;
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------


bool GrammarMachine::isRegion2Empty(const string& testStr)
{
if(getRegion2(testStr) == "") return true;
return false;
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------


bool GrammarMachine::isDouble(const string& testStr)
//if size isnt 2, prints error and returns false
//if char is one of the 9 valid, checks if second char matches, if so returns true
{
if(testStr.size() != 2)
{
cout << "Wrong string size in isDouble" << endl;
return false;
}

char t = testStr.at(0);
if( (t == 'b') || (t == 'd') || (t == 'f') || (t == 'g') || (t == 'm') || (t == 'n') || (t == 'p') || (t == 'r') || (t == 't') ) 
{
if(testStr.at(0) == testStr.at(1)) return true;
}

return false;
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

bool GrammarMachine::isLIending(char test)
//checks if char is one of the 10 valid ones
{
char t = test;
if( (t == 'c') || (t == 'd') || (t == 'e') || (t == 'g') || (t == 'h') || (t == 'k') || (t == 'm') || (t == 'n') || (t == 'r') || (t == 't'))
return true;
return false;

}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

string GrammarMachine::getRegion1(const string& testStr)
/*This method iterates through the string, finds the first vowel, then finds the first consonant after that, and breaks the end of the word not including that consonant off and returns it

*/
{
for(unsigned int index=0;index<testStr.size();index++)
{
//cout << "in region 1" << endl;
if(testStr.size() <3) return "";
if(isVowel(testStr,index))
{
index++;
while(index<testStr.size())
{
if(!isVowel(testStr,index))
{
if(index==testStr.size()) return "";
return(testStr.substr( (index+1), (testStr.size() - index)));


}
index++;
}

}

}

return "";
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

string GrammarMachine::getRegion2(const string& testStr)
{
//gets region1 of region1 which is region 2
string result = getRegion1(testStr);
//if there is a y, make sure it is treated as vowel
if(result.size()==0) return "";
if(result.at(0) != 'y') return getRegion1(result);

int index = testStr.size() - result.size(); 
if(index > 0)
{
if(!isVowel(testStr,index-1))
result[0] = 'a';
}
return getRegion1(result);
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

bool GrammarMachine::hasSuffix(const string& testStr, const string& suffix)
{
//checks from the end of both strings until the suffix ends to make sure they match
//suffix can be whole word

if(suffix.size() > testStr.size()) return false;
int Tindex = testStr.size()-1;
int Sindex = suffix.size()-1;

while(Sindex>=0)
{
if(! (testStr.at(Tindex)==suffix.at(Sindex)) ) return false;
Tindex--;
Sindex--;
}
return true;
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

string GrammarMachine::getPreceder(const string& testStr, const string& suffix)
{
//if the string has the suffix makes a substring without the suffix on it
if(!hasSuffix(testStr,suffix)) return testStr;

return testStr.substr(0, (testStr.size()-suffix.size()) );
}


//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

string GrammarMachine::replaceSuffix(const string& testStr, const string& suffix, const string& replacement)
{
//if a word has the passed suffix, this chops it off, then adds the replacement to the word
if(!hasSuffix(testStr, suffix)) return testStr;

return (getPreceder(testStr, suffix) + replacement);
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

int GrammarMachine::getRegionOfSuffix(const string& testStr, const string& suffix)
{

if(hasSuffix( getRegion2(testStr) , suffix)) return 2;
if(hasSuffix( getRegion1(testStr) , suffix)) return 1;
return 0;
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

bool GrammarMachine::endsInSS(const string& testStr)
{
//if the string is 3+ chars, must end in consonant, vowel, consonant that isnt w x or y
//if the string is 2 chars, does not test w, x, or y ending, and only checks the last 2 chars
//if the string is less than 2 chars returns false;
if(testStr.size()>= 2){

int index = testStr.size() -1;

if(isVowel(testStr, index)) return false;

if(testStr.size() != 2)
if( (testStr.at(index) == 'w') || (testStr.at(index) == 'x') || (testStr.at(index) == 'y')) return false;

index--;
if(!isVowel(testStr,index)) return false;


if(testStr.size() != 2){
index--;
if(isVowel(testStr, index)) return false;
}

return true;
}

return false;
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

bool GrammarMachine::isShort(const string& testStr){
//returns true if the word end is a short syllable, and has a nontrivial region 1
if(!endsInSS(testStr)) return false;

if(! (getRegion1(testStr).size() ==0 )) return false;

return true;
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

bool GrammarMachine::containsVowel(const string& testStr)
{
//returns true if the word contains a vowel
for(unsigned int i=0; i<testStr.size(); i++)
if(isVowel(testStr,i))return true;
return false;
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

string GrammarMachine::step1(const string& testStr){
string test = testStr;
if(testStr.at(0) == 39) test = test.substr(1,test.size()-1); 

vector<string> suffixes { "'s'" , "'s" , "'" };

for(unsigned int i = 0; i<suffixes.size(); i++)
{
if(hasSuffix(test, suffixes.at(i))) return getPreceder(test, suffixes.at(i));
}
return test;
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------


string GrammarMachine::step2(const string& testStr){
vector<string> suffixes { "sses" , "ied" , "ies", "us", "ss", "s" };
//-----------------------------------------
//test ssus
//-----------------------------------------
if(hasSuffix(testStr, suffixes.at(0))) return replaceSuffix(testStr,suffixes.at(0),"ss");
//-----------------------------------------
// test ied and ies
//-----------------------------------------
for(unsigned int i = 1; i<3; i++)
{
if(hasSuffix(testStr, suffixes.at(i)))
{
if( getPreceder(testStr, suffixes.at(i)).size() > 1) 
return replaceSuffix(testStr,suffixes.at(i),"i");
return replaceSuffix(testStr,suffixes.at(i),"ie");
}
}
//-----------------------------------------
//test us and ss
//-----------------------------------------
for(unsigned int i = 3; i<5; i++)
{
if(hasSuffix(testStr, suffixes.at(i)))
return replaceSuffix(testStr,suffixes.at(i), suffixes.at(i));
}
//-----------------------------------------
//test s
//-----------------------------------------
if(hasSuffix(testStr, suffixes.at(5)))
{
string helper = testStr.substr(0,testStr.size()-2);
if(containsVowel(helper))
return getPreceder(testStr, suffixes.at(5));
}

//return the word if it matched no suffix
return testStr;
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

string GrammarMachine::step3(const string& testStr){
vector<string> suffixes { "eed" , "eedly" , "ed", "edly", "ing", "ingly" };
//-----------------------------------------
//test eed and eedly
//-----------------------------------------

for(unsigned int i = 0; i<2; i++)
{
if(hasSuffix(testStr, suffixes.at(i)))
{
//if the suffix occurs in region 1 we replace it with ee

if(getRegionOfSuffix(testStr,suffixes.at(i)) > 0)
{

return replaceSuffix(testStr,suffixes.at(i),"ee"); 
}
return testStr;
}
}
//-----------------------------------------
//test ed, edly, ing, ingly
//-----------------------------------------
for(unsigned int i = 2; i<suffixes.size(); i++)
{

string suf = suffixes.at(i);
if(hasSuffix(testStr, suf))
{
if( containsVowel(getPreceder(testStr, suf)) )
{
//if it has the suffix and the predecessor contains a vowel we choose what to do to it here
//only one of these rules will apply to something
string prec = getPreceder(testStr, suf);
//if preceder ends in at iz or bl add an e and return it
if(hasSuffix(prec, "at")) return prec+"e";
if(hasSuffix(prec, "iz")) return prec+"e";
if(hasSuffix(prec, "bl")) return prec+"e";
//if preceder ends in double take off the last letter and return it
if(prec.size() >1)
if(isDouble( prec.substr(prec.size()-2, 2) )) return prec.substr(0, prec.size()-1);
//if preceder is short and an e to it and return
if(isShort(prec)) return prec + "e";
//if the preceder matched none of those conditions return it as is
return prec;
}
}
}

//if the word did not have any of the suffixes return it as is
return testStr;
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

string GrammarMachine::testAndReplace(const string& testStr, vector<string> suffixes, vector<string> replacements){

if(suffixes.size() != replacements.size())
cout<< "error ERROR in testAndReplace: vectors different lengths" << endl;

for(unsigned int i = 0; i<suffixes.size(); i++)
{
if(hasSuffix(testStr,suffixes.at(i)))
return replaceSuffix(testStr,suffixes.at(i),replacements.at(i));
}
return testStr;
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

string GrammarMachine::testAndReplace(const string& testStr, vector<string> suffixes, vector<string> replacements, int region){

if(suffixes.size() != replacements.size())
cout<< "error ERROR in testAndReplace: vectors different lengths" << endl;

for(unsigned int i = 0; i<suffixes.size(); i++)
{
if(hasSuffix(testStr,suffixes.at(i)))
{

if(getRegionOfSuffix(testStr,suffixes.at(i)) >= region)
return replaceSuffix(testStr,suffixes.at(i),replacements.at(i));
else return testStr;
}
}
return testStr;
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

string GrammarMachine::testAndReplace(const string& testStr, vector<string> suffixes, int region){
for(unsigned int i = 0; i<suffixes.size(); i++)
{
if(hasSuffix(testStr,suffixes.at(i)))
{
if(getRegionOfSuffix(testStr,suffixes.at(i)) >= region)
return getPreceder(testStr,suffixes.at(i));
else return testStr;
}
}
return testStr;
}



//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

string GrammarMachine::step4(const string& testStr){
//if the suffix is y, and the last letter before it is a nonvowel and not the start of the word,
//y becomes i
if(!hasSuffix(testStr, "y")) return testStr;
string prec = getPreceder(testStr, "y");
if(prec.size() < 2) return testStr;
if(isVowel( prec, prec.size()-1 )) return testStr;
return replaceSuffix(testStr, "y" , "i");


}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

string GrammarMachine::step5(const string& testStr){
vector<string> suffixes {"ational", "tional" , "enci" , "anci", "abli", "entli", "izer" , "ization", "ation", "ator", "alism", "aliti", "alli", "fulness", "ousli", "ousness", "iveness", "iviti", "biliti", "bli", "fulli", "lessli"};
vector<string> replacements {"ate", "tion", "ence", "ance", "able", "ent", "ize", "ize", "ate", "ate", "al", "al", "al", "ful", "ous", "ous", "ive", "ive", "ble", "ble", "ful", "less"};

string result = testAndReplace(testStr, suffixes, replacements);
if(result != testStr) return result;


if(hasSuffix(testStr,"ogi"))
{

if(!getPreceder(testStr,"ogi").size())return testStr;

if(testStr.at(testStr.size()-4) == 'l') return replaceSuffix(testStr,"ogi","og");
}


if(hasSuffix(testStr,"li"))
{

if(!getPreceder(testStr,"li").size())return testStr;

if(isLIending(testStr.at(testStr.size()-3))) return getPreceder(testStr,"li");
}


return testStr;

}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------

string GrammarMachine::step6(const string& testStr)
{
vector<string> suffixes {"ational","tional","alize","icate","iciti","ical","ful","ness"};
vector<string> replacements {"ate","tion","al","ic","ic","ic","",""};

string result = testAndReplace(testStr, suffixes, replacements, 1);
if(result != testStr) return result;

vector<string> suffix {"ative"};

result = testAndReplace(testStr, suffix, 2);
if(result != testStr) return result;

return testStr;

}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------


string GrammarMachine::step7(const string& testStr)
{
vector<string> suffixes {"al" , "ance", "ence", "er", "ic" , "ic", "able", "ible", "ant", "ant", "ement", "ment","ent","ism","ate","iti","ous","ive","ize"};


string result = testAndReplace(testStr, suffixes, 2);
if(result != testStr) return result;


if(hasSuffix(testStr,"ion")){
if(getRegionOfSuffix(testStr,"ion") >= 2)
{
string prec = getPreceder(testStr,"ion");
char end = prec.at(prec.size()-1);
if(end == 's' || end == 't')
return prec;
}
}


return testStr;
}

//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------


string GrammarMachine::step8(const string& testStr){

if(hasSuffix(testStr,"e"))
{
string prec = getPreceder(testStr,"e");
int region = getRegionOfSuffix(testStr,"e");

if(region ==2) return prec;

if(region ==1) 
	if(!endsInSS(prec)) return prec;

}


if(hasSuffix(testStr,"l"))
{
string prec = getPreceder(testStr,"l");
if(prec.size() <1) return testStr;
if(getRegionOfSuffix(testStr,"l") ==2)
if(prec.at(prec.size()-2))
	if(prec.at(prec.size()-1) == 'l')
		return prec;



}

return testStr;
}


//-------------------------------------------------------------
//=============================================================
//-------------------------------------------------------------




bool GrammarMachine::doSteps(vector<string> &words){
/*
for(unsigned int i =0; i<words.size();i++){
cout<< "current word: " << words.at(i) << endl;
}
*/

for(unsigned int i =0; i<words.size();i++){
//cout<< "current word: " << words.at(i) << endl;

//if the word is valid for stemming, do all 8 steps in order
doSteps(words[i]);
}
return true;
}

bool GrammarMachine::doSteps(string &word)
{
if(needsGrammarification(word))
{
string result = word;
result = step1(result);
result = step2(result);
result = step3(result);
result = step4(result);
result = step5(result);
result = step6(result);
result = step7(result);
result = step8(result);
word = result;
}

return true;
}







