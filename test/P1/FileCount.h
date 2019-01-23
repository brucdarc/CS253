#ifndef AYLMAY
#define AYLMAY

#include<iostream>
#include<fstream>
using std::istream;
using std::ostream;


class FileCount {


public:

	FileCount()
	{
	
	}
	bool ReadIn(istream& instrm);		//reads file and counts numbers
	bool Write(ostream& out) const;		//prints numbers to output stream

private:

	int numCount [20] = {0};		//array used to store numbers

};


#endif // skips to this if AYLMAY is already defined
