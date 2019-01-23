#ifndef DocManager_H
#define DocManager_H
#include<iostream>
#include <Word.h>
#include <vector>
#include <string>
#include <StringTest.h>
#include <Document.h>

using std::string;
using std::vector;



class DocManager {


public:

DocManager (std::vector<Document> D);


bool CompAndPrint();		//uses print one to print the matrix of all comparisons for everything
bool PrintOne(int index);	//compares one file to all the others and prints one line with all the comparisons in order of the documents order

bool PrintDocs();
bool PrintSims(Document &c);

Document getMostSimuliar(double lowestRL, double highestRL, unsigned int originalIndex); 
inline bool getFail() {return failed;}

private:

vector<Document> DOCS;
bool failed;


};

#endif
