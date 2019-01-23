
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

bool Document::failed = false;

Document::Document (vector<Word> words, double readL, string FN)
: wds(words), readingLevel(readL), fileName(FN)
{

//cout << "making document" << endl;
std::sort(wds.begin(), wds.end());
}






double Document::getReadingLevel(const vector<string> &words)
{
double result;
//cout << "letters " << getNumAlphaWordsChars(words) << endl;
//cout << "words " << getNumAlphaWords(words) << endl;
//cout << "sents " << getNumSents(words) << endl;
//cout << getL() << endl;
//cout << getS() << endl;
result = 0.0588 * getL(words) - .296 * getS(words) - 15.8;
return result;
}






double Document::getS(const vector<string> &words)
{
return  ((double)getNumSents(words)) / (((double)getNumAlphaWords(words))/100.0 );
}






double Document::getL(const vector<string> &words)
{




return  ((double)getNumAlphaWordsChars(words) * 100.0) / ((double)getNumAlphaWords(words));
}


//===============================================================

int Document::getNumAlphaWordsChars(const vector<string> &words)
{
int count = 0;

for(unsigned int i = 0; i<words.size(); i++)
{
//cout << wds.at(i).getWord() << endl;
if(StringTest::isAlphaNumeric(words.at(i))) count += words.at(i).size();
}
return count;
}







//===============================================================

int Document::getNumAlphaWords(const vector<string> &words)
{
int count = 0;

for(unsigned int i = 0; i<words.size(); i++)
{
if(StringTest::isAlphaNumeric(words.at(i))) count++;
}

if(count == 0)
{
count = 1;
failed = true;
}

return count;
}

//===============================================================

int Document::getNumSents(const vector<string> &words)
{
int count = 0;

for(unsigned int i = 0; i<words.size(); i++)
{
if(StringTest::isSentEnd(words.at(i))) count++;
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



