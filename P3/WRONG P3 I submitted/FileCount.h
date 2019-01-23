#ifndef AYLMAY
#define AYLMAY

#include<iostream>
#include<fstream>
using std::istream;
using std::ostream;
#include <vector>
#include <string>



class FileCount {


public:

	FileCount()
	{
	
	}
	bool ReadIn(istream& instrm);		//reads file and counts numbers
	bool Write(ostream& out) const;		//prints numbers to output stream

private:

	std::vector<std::string> words;		//array used to store numbers
	std::vector<int> wordCounts;
};


#endif // skips to this if AYLMAY is already defined
