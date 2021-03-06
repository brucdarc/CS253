
#include <FileCount.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
// tell the compiler what in iosteam im using

#include <fstream>
using std::ifstream;

// using might have to come after the include that it specifies the stream from


int Usage(char* arg0)
{
  cout << "Usage: " << arg0 << " filename" << endl;
  cout << "File should contain numbers from 0 to 19 seperated by space tab or newline" << endl;
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
}



