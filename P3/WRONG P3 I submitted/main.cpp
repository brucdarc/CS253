#include <StringTest.h>
#include <FileCount.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
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
	
	if (argc != 2) return Usage(argv[0]);
  
	ifstream istr(argv[1]);
	if (istr.fail()) return Usage(argv[0]);


	FileCount counter;


	if(!counter.ReadIn(istr))
	{
	cerr << "File not formatted correctly" << endl;
	Usage(argv[0]);
	return -1;
	}

	if(!counter.Write(cout))
	{
	cerr << "program error" << endl;
	return -1;
	}
	return 0;
	

	/*
	StringTest tester;
	//string a = argv[1];
	string a = "'dsar";
	int period = 2;
	cout << a << endl;
	//cout << tester.isPeriodValid(a,period) << endl;
	cout << tester.isAlphaNumeric(a) << endl;
	*/	
}



