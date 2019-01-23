#include <StringTest.h>
#include <GrammarMachine.h>
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
	GrammarMachine tester;
	string a = argv[1];
	//string b = argv[2];
	//string c = argv[3];
	//string a = "eedly";
	//unsigned int period = 1;
	cout << a << endl;
	//cout << b << endl;
	//cout << tester.isPeriodValid(a,period) << endl;
	//cout << tester.needsGrammarification(a) << endl;
	//cout << tester.hasSuffix(a,b) << endl;
	//cout << tester.getPreceder(a,b) << endl;
	cout << tester.getRegion1(a) << endl;
	cout << tester.getRegion2(a) << endl;
	//cout << tester.replaceSuffix(a,b,c) << endl;	
	//cout << tester.getRegionOfSuffix(a, b) << endl;
	//cout << tester.endsInSS(a) << endl;
	//cout << tester.isShort(a) << endl;
	a = tester.step1(a);
	
	cout << "Step1: " <<a << endl;
	a = tester.step2(a);
	cout <<"Step2: "<< a << endl;
	a = tester.step3(a);
	cout << "Step3: "<<a << endl;
	a = tester.step4(a);
	cout << "Step4: "<<a << endl;
	a = tester.step5(a);
	cout << "Step5: "<<a << endl;
	a = tester.step6(a);
	cout << "Step6: "<<a << endl;
	a = tester.step7(a);
	cout << "Step7: "<<a << endl;

	a = tester.step8(a);
	cout << "Step8: "<<a << endl;
	*/	
	
}



