#ifndef AYLMAY
#define AYLMAY

#include<iostream>
#include<fstream>
using std::istream;
using std::ostream;
#include <vector>
#include <string>
using std::string;
using std::vector;
#include <Document.h>


class FileCount {


public:

	FileCount()
	{
	
	}
	bool ReadIn(istream& textStrm, istream& execptStrm);		//reads file and counts numbers
	Document Write() const;		//prints numbers to output stream
	bool breakStemSort(vector<string> &strs, istream& exceptStrm);

private:

	std::vector<std::string> words;		//array used to store numbers
	std::vector<int> wordCounts;
};


#endif // skips to this if AYLMAY is already defined
