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


bool CompAndPrint();
bool PrintOne(int index);


private:

vector<Document> DOCS;



};

#endif
