#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){

	int x;
	int cnt[20];
  
	//check for correct number of args
	if (argc !=2)
	{
		cerr << "Usage: PA1 <filename>!" << endl;
		return -1;
	}

	ifstream istr(argv[1]);

	//Check if this file opens or if it is an empty file
	if (istr.fail())
	{
		cerr << "Cannot open file or Empty file!" << endl;
		return -1;
	}
	
	//Read characters until it fails
	while (!istr.fail())
	{
		istr >> x;
		if ((x >= 0) && (x < 20))
			++cnt[x];
		else
		{
			cerr << "Number not in range!" << endl;
			return -1;
		}
	}

//Print values
	for (int  i = 0; i < 20; i++){
		cout << i << " " << cnt[i]<< endl;
	}

	istr.close();
	return 0;

}







	//Print values
	for (int  i = 0; i < 20; i++){
		cout << i << " " << cnt[i]<< endl;
	}

	istr.close();
	return 0;
}
