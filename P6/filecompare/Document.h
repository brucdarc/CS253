#ifndef Document_H
#define Document_H
#include<iostream>
#include <Word.h>
#include <vector>
#include <string>
#include <StringTest.h>
using std::string;
using std::vector;



class Document {


public:

Document (vector<Word> words);

bool contains(const Word &w) const;
bool add(Word w);
bool setTFIDFs( vector<Document> &Docs);
bool setTFIDF( vector<Document> &Docs, Word &w);
double getIDF( vector<Document> &Docs, Word &w);
double Sim( Document &Other);
inline Word& at(int index) {return wds.at(index);};
Word& find( Word &w);
int findIndex( Word &w, int min, int max);
inline int getSize() {return wds.size();};





private:

vector<Word> wds;


};

#endif
