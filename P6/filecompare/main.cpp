#include <StringTest.h>
#include <GrammarMachine.h>
#include <FileCount.h>
#include <iostream>
#include <DocManager.h>
using std::cout;
using std::endl;
using std::cerr;
using std::vector;
// tell the compiler what in iosteam im using

#include <string>
using std:: string;

#include <fstream>
using std::ifstream;


// using might have to come after the include that it specifies the stream from


int Usage(char* arg0)
{
  cout << "Usage: " << arg0 << " filename" << endl;
  cout << "File should contain words seperated by spaces" << endl;
  return -1;
}

int main(int argc, char* argv[])
{
	///*
	if (argc != 3) return Usage(argv[0]);
  
	ifstream istr1(argv[1]);
	if (istr1.fail()) return Usage(argv[0]);

	ifstream istr2(argv[2]);
	if (istr2.fail()) return Usage(argv[0]);
	
	vector<Word> words1;
	vector<Word> words2;
	string w1;
	string w2; 
	int f1;
	int f2;	



	while(!istr1.fail() && !istr2.fail())
	{

	istr1 >> w1;
	istr2 >> w2;

	istr1 >> f1; 
	istr2 >> f2; 

	words1.push_back(Word(w1,f1));
	words2.push_back(Word(w2,f2));
	}



	Document D1(words1);
	Document D2(words2);



	for(int i = 0; i<D1.getSize(); i++)
	{
	if(!D2.contains(D1.at(i))) cout << D1.at(i).getWord() << " : " << D2.find(D1.at(i)).getWord() << endl;
	}










}
