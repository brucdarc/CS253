#include <FileCount.h>
#include <iostream>
using std::endl;
using std::cout;
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <Except.h>
#include <AddExceptions.h>
#include <StringTest.h>
#include <GrammarMachine.h>
#include <Document.h>
#include <Word.h>


bool FileCount::ReadIn(istream& instrm, istream& exceptStrm, string fileName)
{
FileName = fileName;


//cout << "entering readin" << endl;

std::string current;
instrm >> current; 		// read first number
//cout << "first Word: " << current << endl;
if(instrm.fail()) 		//test if file is empty before starting
{
	cout << "file empty" << endl;
	// stop the method if the file is empty
	return false;
}
words.push_back(current);
originals.push_back(current);

while(!instrm.eof())		//while the stream is not at the end
{
//cout << "reading numbers " << endl;

instrm >> current; 			//read one number into current
if(instrm.fail())
{
	if(instrm.eof())
	{
	
	if(!breakStemSort(words, exceptStrm)) return false;
	 return true;	// stop the method if the file has ended
	}
	cout << "failed before end of file" << endl;
	return false;
}		//make sure the in from the file can be a string

words.push_back(current);
originals.push_back(current);
}
if(!breakStemSort(words, exceptStrm)) return false;
return true;

}

bool FileCount::breakStemSort(vector<string> &strs, istream& eStrm)
{
	//cout << "entering breakstemsort" << endl;

	
	StringTest j;
	j.BreakUp(strs);
	readingLevel = Document::getReadingLevel(strs);	
	
	j.MarkSentStarts(strs);
	//cout << "entering execpt capstesting" << endl;
	Except q;
	//cout << "created except object" << endl;
	q.capsTest(strs);
	AddExceptions a;
	//cout << "preparing to enter readin execptions" << endl;
	if(!a.readIn(eStrm)) return false;
	a.stem(strs);
	


	
	std::sort (strs.begin(), (strs.end()));
return true;
}



Document FileCount::Write() const // takes output stream as arg to print to
{
vector<Word> res;
StringTest j;
 //stops if the output is in a fail state
int numOfWord =1;		//default for a word appearing
std::string last = words.at(0); //load in first word before loop
for(unsigned int i = 1; i<words.size(); i++)
//print each word out followed by a space and the count of it found in the file
{
if(last != words.at(i))		//see if the next word is a repeat
{
//cout << last << " " << numOfWord  << endl;	//print the word and the number of the word
Word w(last, numOfWord); 
res.push_back(w);
numOfWord = 1;					//reset the number of the word for the next loop
}

else			//if the word is a repeat raise the count of it and loop to the next iteration of it
{
numOfWord++;
}
last = words.at(i);	//change last to be the next word in vector


}

//cout << last << " " << numOfWord << endl;
Word w(last, numOfWord); 
res.push_back(w);
Document result(res, readingLevel, FileName);



return result;
}
