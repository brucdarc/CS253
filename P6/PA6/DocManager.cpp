
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

for(unsigned int i =0; i<DOCS.size();i++)
{
DOCS[i].setTFIDFs(DOCS);
}

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
