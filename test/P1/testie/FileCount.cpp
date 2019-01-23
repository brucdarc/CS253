#include <FileCount.h>
#include <iostream>
using std::endl;
using std::cout;
#include <fstream>





bool FileCount::ReadIn(istream& instrm)
{

//cout << "entering readin" << endl;

int current;
instrm >> current; 		// read first number
if(instrm.fail()) 		//test if file is empty before starting
{
	if(instrm.eof()) return false;	// stop the method if the file is empty
	return false;
}

if(current > 19 || current < 0) return false; // bounds check number
numCount[current]++;		//increment the number








while(!instrm.eof())		//while the stream is not at the end
{
//cout << "reading numbers " << endl;

instrm >> current; 			//read one number into current
if(instrm.fail())
{
	if(instrm.eof()) return true;	// stop the method if the file has ended
	return false;
}		//make sure the in from the file can be a number

//cout << "reading numbers 2" << endl;
if(current > 19 || current < 0) return false; 		//make sure current is between 1 and 19
//cout << "reading numbers 3 current is " << current << endl;
numCount[current]++; 			//increment the array to show that that number appeared once
//cout << "reading numbers 4" << endl;

}
return true;

}

bool FileCount::Write(ostream& out) const // takes output stream as arg to print to
{

if (out.fail()) return false; //stops if the output is in a fail state

for(int i = 0;i<20;i++)
{
out << i << " " << numCount[i] << endl;	//prints the number and the number of it

}


return true;

}
