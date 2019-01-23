#include <FileCount.h>
#include <iostream>
using std::endl;
using std::cout;
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>



bool FileCount::ReadIn(istream& instrm)
{

//cout << "entering readin" << endl;

std::string current;
instrm >> current; 		// read first number
if(instrm.fail()) 		//test if file is empty before starting
{
	// stop the method if the file is empty
	return false;
}
words.push_back(current);
wordCounts.push_back(1);








while(!instrm.eof())		//while the stream is not at the end
{
//cout << "reading numbers " << endl;

instrm >> current; 			//read one number into current
if(instrm.fail())
{
	if(instrm.eof()) return true;	// stop the method if the file has ended
	return false;
}		//make sure the in from the file can be a string

words.push_back(current);

}

std::sort (words.begin(), (words.end()));
return true;

}





bool FileCount::Write(ostream& out) const // takes output stream as arg to print to
{

if (out.fail()) return false; //stops if the output is in a fail state

int numOfWord =1;		//default for a word appearing
std::string last = words.at(0); //load in first word before loop
for(unsigned int i = 1; i<words.size(); i++)
//print each word out followed by a space and the count of it found in the file
{


if(last != words.at(i))		//see if the next word is a repeat
{
cout << last << " " << numOfWord << endl;	//print the word and the number of the word
numOfWord = 1;					//reset the number of the word for the next loop
}


else			//if the word is a repeat raise the count of it and loop to the next iteration of it
{
numOfWord++;
}

last = words.at(i);	//change last to be the next word in vector

}

cout << last << " " << numOfWord << endl; 

return true;

}
