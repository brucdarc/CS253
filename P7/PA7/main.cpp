#include <StringTest.h>
#include <GrammarMachine.h>
#include <FileCount.h>
#include <iostream>
#include <DocManager.h>
using std::cout;
using std::endl;
using std::cerr;
// tell the compiler what in iosteam im using

#include <string>
using std:: string;

#include <vector>


#include <fstream>
using std::ifstream;

// using might have to come after the include that it specifies the stream from


int Usage(char* arg0)
{
  cout << "Usage: " << arg0 << " filename filename" << endl;
  cout << "File should contain words seperated by spaces" << endl;
  return -1;
}

int main(int argc, char* argv[])
{
	
	if (argc != 2) 
	{cout << "too few args" << endl;
	return Usage(argv[0]);
	}
	ifstream exceptStr(argv[1]);
	if (exceptStr.fail()) 
	{cout << "exceptions file failed" << endl;
	return Usage(argv[0]);
	
	}

	

	// CODE FOR PA7 ONLY




	
	FileCount counter;
	if(!counter.ReadIn(exceptStr, exceptStr)) return -1;

	Document book = counter.Write();
	double RL = book.getReadingLevel();
	if(book.getFail())
	return Usage(argv[0]);
	
	cout << RL << endl;







	//END CODE FOR PA7 ONLY


	/* PA4-6 code
	std::vector<ifstream> files;

	for(int i = 2; i<argc; i++)
	{ 
	files.push_back(ifstream (argv[i]));
	//ifstream textStr(argv[2]);
	
	
	if (files[i-2].fail()) 
	{cout << "file failed to open number : " << i-2 << endl;
	return Usage(argv[0]);
	}
	
	}


	vector<Document> DOCS;

	for(unsigned int i = 0; i<files.size(); i++)
	{

	ifstream exceptionStreamTemp(argv[1]);
	
	FileCount counter;
	//cout << "reading new file: " << i << endl;
	if(!counter.ReadIn(files[i],exceptionStreamTemp))
	{
	cerr << "File not formatted correctly file number :" << i << endl;
	Usage(argv[0]);
	return -1;
	}

	DOCS.push_back(counter.Write());
	}

	DocManager MAN(DOCS);
	
	MAN.CompAndPrint();
	

	*/
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
	//a = tester.step1(a);
	

	//cout << "Step1: " <<a << endl;
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



