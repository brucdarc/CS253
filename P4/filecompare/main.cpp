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
	///*
	if (argc != 3) return Usage(argv[0]);
  
	ifstream istr1(argv[1]);
	if (istr1.fail()) return Usage(argv[0]);

	ifstream istr2(argv[2]);
	if (istr2.fail()) return Usage(argv[0]);
	
	while(!istr1.fail() && !istr2.fail())
{

string a;
string b;
istr1 >> a;
istr2 >> b;

if(a != b) cout << a << " : " << b << endl;


}
	
	//*/
}
