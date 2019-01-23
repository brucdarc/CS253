
#include <math.h> 
#include <Word.h>
#include <vector>
#include <string>
#include <algorithm> 
#include <StringTest.h>
using std::string;
using std::vector;
#include <iostream>
using std::endl;
using std::cout;
using std::cerr;
#include <Document.h>






Document::Document (vector<Word> words)
: wds(words)
{
//cout << "making document" << endl;
std::sort(wds.begin(), wds.end());
}


double Document::getReadingLevel()
{
double result;
//cout << "letters " << getNumAlphaWordsChars() << endl;
//cout << "words " << getNumAlphaWords() << endl;
//cout << "sents " << getNumSents() << endl;
//cout << getL() << endl;
//cout << getS() << endl;
result = 0.0588 * getL() - .296 * getS() - 15.8;
return result;
}






double Document::getS()
{
return  ((double)getNumSents()) / (((double)getNumAlphaWords())/100.0 );
}






double Document::getL()
{




return  ((double)getNumAlphaWordsChars() * 100.0) / ((double)getNumAlphaWords());
}


//===============================================================

int Document::getNumAlphaWordsChars()
{
int count = 0;

for(unsigned int i = 0; i<wds.size(); i++)
{
//cout << wds.at(i).getWord() << endl;
if(wds.at(i).isAlphaNumeric()) count += wds.at(i).size() * wds.at(i).getfrequency();
}
return count;
}







//===============================================================

int Document::getNumAlphaWords()
{
int count = 0;

for(unsigned int i = 0; i<wds.size(); i++)
{
if(wds.at(i).isAlphaNumeric()) count += wds.at(i).getfrequency();
}
return count;
}

//===============================================================

int Document::getNumSents()
{
int count = 0;

for(unsigned int i = 0; i<wds.size(); i++)
{
if(wds.at(i).isSentEnd()) count += wds.at(i).getfrequency();
}
return count;
}




//===============================================================

int Document::findIndex( Word &w, int min, int max)
{
//cout << "find INdex" << "min: " << min << " max: " << max;
int middle = (max + min)/2;
//cout << " middle: " << middle << endl;
if(max < min) 
{cout << "error in findindex" << endl;
return -1;
}

if(wds.at(middle) < w)return findIndex(w, middle+1, max);
if(w < wds.at(middle))return findIndex(w, min, middle-1);
if(wds.at(middle) == w) return middle;
return -1;
}


//===============================================================

Word& Document::find( Word &w)
{
if(!contains(w)) 
{//cout << "error in find" << endl;
return wds.at(0);
}

int index = findIndex( w, 0, wds.size()-1);
return wds.at(index);
}
//===============================================================

double Document::Sim(Document &Other)
{
double result = 0;
//cout << "entering sim" << endl;
for(unsigned int i =0; i<wds.size(); i++)
{

if(Other.contains(wds.at(i)))
{

Word w1 = wds[i];

Word w2 = Other.find(w1);
//if( (w1.getTFIDF() * w2.getTFIDF()) > 1000)

//cout << " frequencies : " << w1.getfrequency() << " : " << w2.getfrequency() << " : " << w1.getTFIDF() * w2.getTFIDF() << " individual IFIDFS " << w1.getTFIDF() << " : " << w2.getTFIDF() << " WORD: " << w1.getWord() << " idf: " << endl;


result += w1.getTFIDF() * w2.getTFIDF();

}

}
return result;
}
//===============================================================

bool Document::setTFIDFs( vector<Document> &Docs)
{
//cout << "entering setTFIDF" << endl;
for(unsigned int i = 0; i<wds.size(); i++)
{
setTFIDF(Docs, wds.at(i));
}
//cout << "exiting setTFIDF" << endl;
return true;
}

//===============================================================

bool Document::setTFIDF(vector<Document> &Docs, Word &w)
{
//cout << "setTFIDF word: " << w.getWord() << endl;
if(w.isPunctuation())
{ w.setTI(0.0);
return true;
}

double res = (double)w.getfrequency() * getIDF(Docs, w);
//cout << "RESULT: " << res << endl;
w.setTI(res);
return true;
}

//===============================================================

double Document::getIDF( vector<Document> &Docs, Word &w)
{
int numDocs = Docs.size();
int numContDocs = 0;

for(int i =0;i<numDocs;i++)
{
if(Docs.at(i).contains(w)) numContDocs++;
}
//string b = "leave";
//if(w.getWord() == b) cout << numContDocs << endl;

double result = (double)numDocs/(double)numContDocs;

result = std::log10(result);
 return result;
}

//===============================================================


bool Document::contains(const Word &w) const
{
return std::binary_search(wds.begin(), wds.end(), w);
}

//===============================================================



