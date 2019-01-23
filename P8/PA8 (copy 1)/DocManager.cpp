
#include<iostream>
#include <Word.h>
#include <vector>
#include <string>
#include <StringTest.h>
#include <Document.h>
#include <DocManager.h>
using std::string;
using std::vector;
using std::endl;
using std::cout;
using std::cerr;



DocManager::DocManager(vector<Document> d)
: DOCS(d)
{
failed = false;
for(unsigned int i =0; i<DOCS.size();i++)
{
DOCS[i].setTFIDFs(DOCS);
}

}




Document DocManager::getMostSimuliar(double lowestRL, double highestRL, unsigned int originalIndex)
{
double maxSim = -9999999999999.0;
int resultIndex = 0;
failed = true;
for(unsigned int i =0; i<DOCS.size();i++)
{
if(i != originalIndex)
{
	double readingLevel = DOCS[i].RL();
	if(readingLevel >= lowestRL && readingLevel <= highestRL)
	{
		failed = false;
		double sim = DOCS[i].Sim(DOCS[originalIndex]);
		if(maxSim < sim)
		{
		resultIndex = i;		
		maxSim = sim;
		}
	}
}
}

return DOCS[resultIndex];


}

//=======================================

bool DocManager::PrintSims(Document &c)
{
for(unsigned int i =0; i<DOCS.size();i++)
{
cout << DOCS[i].getName() << ": " << DOCS[0].Sim(DOCS[i]) << endl; 
}
return true;
}








//=======================================
bool DocManager::PrintDocs()
{
for(unsigned int i =0; i<DOCS.size();i++)
{
cout << "fileName: " << DOCS[i].getName() << " " << i << endl;
cout << "RL: " << DOCS[i].RL() << endl;
}
return true;
}

//=======================================
bool DocManager::CompAndPrint()
{

for(unsigned int i = 0; i<DOCS.size(); i++)
{
PrintOne(i);
cout << endl;
}
return true;
}

//==========================================

bool DocManager::PrintOne(int index)
{

for(unsigned int i = 0; i<DOCS.size(); i++)
{
cout << DOCS[index].Sim(DOCS[i]);
cout << " ";
}
return true;
}
