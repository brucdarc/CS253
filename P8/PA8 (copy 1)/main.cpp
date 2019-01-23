#include <StringTest.h>
#include <GrammarMachine.h>
#include <FileCount.h>
#include <iostream>
#include <DocManager.h>
#include <sstream>
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cerr;
using std::atof;
// tell the compiler what in iosteam im using

#include <string>
using std:: string;
using std::istringstream;
#include <vector>


#include <fstream>
using std::ifstream;












// using might have to come after the include that it specifies the stream from

bool getFiles(string holder, vector<string> &fileNames)
{
ifstream inStr(holder);
if(inStr.fail()) return false;

string current;

inStr >> current;
if(current.size() == 0) return false;
fileNames.push_back(current);

while(!inStr.fail())
{
inStr >> current;
if(inStr.fail()) return true;
//cout << current << endl;
fileNames.push_back(current);
}
return true;
}


int Usage(char* arg0)
{
  cout << "Usage: " << arg0 << " filename filename lowestLevel HighestLevel" << endl;
  cout << "File should contain words seperated by spaces" << endl;
  return -1;
}

int main(int argc, char* argv[])
{
	

	if (argc != 5) 
	{cout << "Wrong # of args" << endl;
	return Usage(argv[0]);
	}

	
	double low;
	double high;
	//check if args are valid doubles
	istringstream lowStr(argv[3]);
	istringstream highStr(argv[4]);
	if(!(lowStr>>low)) return Usage(argv[0]);	
	if(!(highStr>>high)) return Usage(argv[0]);
		
	//make sure low is less than high
	if(low>high) return Usage(argv[0]);
	//will countain all the filenames from the background files
	vector<string> fileNames;

	//add the file we are comparing to to the fileNames vector
	fileNames.push_back(argv[1]);


	

	//adds all the background files to the filenames vector
	if(!getFiles(argv[2],fileNames)) return Usage(argv[0]);


	//check the first file which is the exceptions file
	ifstream exceptStr(fileNames.at(1));
	if (exceptStr.fail()) 
	{cout << "exceptions file failed" << endl;
	return Usage(argv[0]);
	}
	//open a stream for the file we are gonna compare to
	ifstream compStr(argv[1]);
	if (compStr.fail()) 
	{cout << "given file failed" << endl;
	return Usage(argv[0]);
	}



	//stem, break, ect. the file we are comparing to
	FileCount counter;
	if(!counter.ReadIn(compStr, exceptStr, argv[1])) return -1;
	//get back a doc of the thing we gonna compare to
	Document compareDoc = counter.Write();
	//make sure nothing failed reading in the doc
	if(compareDoc.getFail())	
	return Usage(argv[0]);

	//document holder for everything that is going to be in my system
	vector<Document> DOCS;
	//put the doc we are comparing to everything in front of the container
	DOCS.push_back(compareDoc);
	
	for(unsigned int i = 2; i<fileNames.size(); i++)
	{
	
	//stream the second file which is the exceptions file
	//we have to make a new stream every time because the old one will be
	//empty
	ifstream TexStr(fileNames.at(1));
	if (TexStr.fail()) 
	{cout << "exceptions file failed" << endl;
	return Usage(argv[0]);
	}




	//set up the current document and check if it fails
	ifstream currentStream(fileNames.at(i));
	if (currentStream.fail()) 
	{cout << "a file failed" << endl;
	return Usage(argv[0]);
	}
	//new filecounter for each iteration
	FileCount counter;
	

	//read in the Ith doc and make sure it doesnt fail
	if(!counter.ReadIn(currentStream,TexStr,fileNames.at(i)))
	{
	cerr << "File not formatted correctly file number :" << i << endl;
	Usage(argv[0]);
	return -1;
	}
	//write the file to a document and make sure it didnt fail
	Document article = counter.Write();
	if(article.getFail()) return Usage(argv[0]);
	//add our document to our vector
	DOCS.push_back(article);
	}

	//the constructor for DocManager sets the TFIDFs for all the documents
	DocManager MAN(DOCS);


	string res = MAN.getMostSimuliar(low,high,0).getName();
	if(MAN.getFail())
	{
	cout << "no files found within given reading level" << endl;
	 return Usage(argv[0]);
	}
	cout << res << endl;



	//MAN.PrintDocs();
	//MAN.PrintSims(DOCS.at(0));



	

	// CODE FOR PA7 ONLY
	/*
	FileCount counter;
	if(!counter.ReadIn(exceptStr, exceptStr, argv[1])) return -1;

	Document book = counter.Write();
	double RL = book.RL();
	if(book.getFail())
	return Usage(argv[0]);
	
	cout << RL << endl;
	*/







	//END CODE FOR PA7 ONLY

	
	// change this for PA8
	//std::vector<ifstream> files;
	
	/*

	for(unsigned int i = 1; i<fileNames.size(); i++)
	{

	ifstream exceptionStreamTemp(fileNames.at(0));
	ifstream currentStream(fileNames.at(i));
	FileCount counter;
	//cout << "reading new file: " << i << endl;
	if(!counter.ReadIn(currentStream,exceptionStreamTemp,fileNames.at(i)))
	{
	cerr << "File not formatted correctly file number :" << i << endl;
	Usage(argv[0]);
	return -1;
	}
	Document article = counter.Write();
	if(article.getFail()) return Usage(argv[0]);
	DOCS.push_back(article);
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



