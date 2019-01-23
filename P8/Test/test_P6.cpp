#include <GrammarMachine.h>
#include <Except.h>
#include <gtest/gtest.h>
#include <StringTest.h>
#include <vector>
#include <Document.h>
#include <Word.h>
#include <algorithm> 
#include <iostream>
using std::endl;
using std::cout;


TEST(Word, opLessThan)
{
Word w1("BALLS");
Word w2("BALLSS");
Word w3("BALL");
string s1("BALLS");
string s2("BALLSS");
string s3("BALL");


EXPECT_EQ(s1<s3, w1<w3 );
EXPECT_EQ(s2<s3, w2<w3 );
EXPECT_EQ(s3<s3, w3<w3 );
EXPECT_EQ(s1<s2, w1<w2 );
EXPECT_EQ(s2<s2, w2<w2 );
EXPECT_EQ(s3<s2, w3<w2 );
EXPECT_EQ(s1<s1, w1<w1 );
EXPECT_EQ(s2<s1, w2<w1 );
EXPECT_EQ(s3<s1, w3<w1 );
}

TEST(DOC, constructorSort)
{
Word w1("BALLS");
Word w2("Apple");
Word w3("Cat");
Word w4("-*/*-*/");

vector<Word> V1 = {w1,w2,w3,w4};
Document D1(V1);
std::sort(V1.begin(), V1.end());

cout << D1.at(0).getWord() << " : " << V1.at(0).getWord() << endl;
cout << D1.at(1).getWord() << " : " << V1.at(1).getWord() << endl;
cout << D1.at(2).getWord() << " : " << V1.at(2).getWord() << endl;
cout << D1.at(3).getWord() << " : " << V1.at(3).getWord() << endl;

EXPECT_EQ(D1.at(0).getWord(), V1.at(0).getWord());
EXPECT_EQ(D1.at(1).getWord(), V1.at(1).getWord());
EXPECT_EQ(D1.at(2).getWord(), V1.at(2).getWord());
EXPECT_EQ(D1.at(3).getWord(), V1.at(3).getWord());

}



TEST(DOC, find)
{
Word w1("BALLS");
Word w2("Apple");
Word w3("Cat");
Word w4("-*/*-*/");

vector<Word> V1 = {w1,w2,w3,w4};
Document D1(V1);


EXPECT_EQ(D1.find(w1), V1[0]);


}

TEST(DOC, BS)
{
Word w1("BALLS");
Word w2("Apple");
Word w3("Cat");
Word w4("-*/*-*/");
Word w5("haha");
Word w6("BALLS");

vector<Word> V1 = {w1,w2,w3,w4};
Document D1(V1);


EXPECT_EQ(D1.contains(w1), true);
EXPECT_EQ(D1.contains(w5), false);
EXPECT_EQ(D1.contains(w6), true);


}


TEST(DOC, IDF)
{
Word w1("BALLS");
Word w2("Apple");
Word w3("Cat");
Word w4("-*/*-*/");
Word w5("haha");
Word w6("BALLS");

vector<Word> V1 = {w1,w2,w3,w4};
Document D1(V1);

vector<Word> V2 = {w1,w2,w3,w5};
Document D2(V2);

vector<Word> V3 = {w1,w2,w3,w6};
Document D3(V3);

vector<Document> DOCS = {D1, D2, D3};

cout << D1.getIDF(DOCS, w1) << endl;
cout << D1.getIDF(DOCS, w4) << endl;
cout << D1.getIDF(DOCS, w6) << endl;
cout << D1.getIDF(DOCS, w5) << endl;

EXPECT_EQ(D1.getIDF(DOCS, w1), 0);
EXPECT_NEAR(D1.getIDF(DOCS, w4), 0.477121, .0001);
EXPECT_EQ(D1.getIDF(DOCS, w6), 0);


}


TEST(DOC, TFIDF)
{
Word w1("BALLS");
Word w2("Apple");
Word w3("Cat");
Word w4("-*/*-*/");
Word w5("haha");
Word w6("BALLS");

vector<Word> V1 = {w1,w2,w3,w4};
Document D1(V1);

vector<Word> V2 = {w1,w2,w3,w5};
Document D2(V2);

vector<Word> V3 = {w1,w2,w3,w6};
Document D3(V3);

vector<Document> DOCS = {D1, D2, D3};
D1.setTFIDF(DOCS, w1);
D1.setTFIDF(DOCS, w6);
D1.setTFIDF(DOCS, w4);
D1.setTFIDF(DOCS, w5);

cout << w1.getTFIDF() << endl;
cout << w4.getTFIDF() << endl;
cout << w6.getTFIDF() << endl;
cout << w5.getTFIDF() << endl;
cout << w5.getfrequency() << endl;

EXPECT_NEAR(0, w1.getTFIDF(), .0001);
EXPECT_NEAR(0, w4.getTFIDF(), .0001);
EXPECT_NEAR(0, w6.getTFIDF(), .0001);
EXPECT_NEAR(.477121, w5.getTFIDF(), .0001);



}


TEST(DOC, TFIDF2)
{
Word w1("BALLS");
Word w2("Apple");
Word w3("Cat");
Word w4("-*/*-*/");
Word w5("haha");
Word w6("BALLS");

vector<Word> V1 = {w1,w2,w3,w4};
Document D1(V1);

vector<Word> V2 = {w1,w2,w3,w5};
Document D2(V2);

vector<Word> V3 = {w1,w2,w3,w6};
Document D3(V3);

vector<Document> DOCS = {D1, D2, D3};

D2.setTFIDFs(DOCS);

EXPECT_NEAR(0, D2.at(0).getTFIDF(), .0001);
EXPECT_NEAR(0, D2.at(1).getTFIDF(), .0001);
EXPECT_NEAR(0, D2.at(2).getTFIDF(), .0001);
EXPECT_NEAR(.477121, D2.at(3).getTFIDF(), .0001);
}



TEST(DOC, setfreq)
{
Word w1("BALLS");

cout << w1.getTFIDF() << endl;
w1.setTI(3);
cout << w1.getTFIDF() << endl;
}

TEST(DOC, sim)
{
Word w1("BALLS");
Word w2("Apple");
Word w3("Cat");
Word w4("-*/*-*/");
Word w5("haha");
Word w6("BALLS");
w1.setfrequency(4);
w6.setfrequency(2);
vector<Word> V1 = {w1,w2,w3,w4};
Document D1(V1);

vector<Word> V2 = {w2,w2,w3,w5};
Document D2(V2);

vector<Word> V3 = {w2,w2,w3,w6};
Document D3(V3);

vector<Document> DOCS = {D1, D2, D3};

D1.setTFIDFs(DOCS);
D2.setTFIDFs(DOCS);
D3.setTFIDFs(DOCS);

cout << "D1 " << endl;

cout << D1.at(0).getTFIDF() << D1.at(0).getWord() << endl;
cout << D1.at(1).getTFIDF() << D1.at(1).getWord() << endl;
cout << D1.at(2).getTFIDF() << D1.at(2).getWord() << endl;
cout << D1.at(3).getTFIDF() << D1.at(3).getWord() << endl;

cout << "D3 " << endl;

cout << D3.at(0).getTFIDF() << D3.at(0).getWord() << endl;
cout << D3.at(1).getTFIDF() << D3.at(1).getWord() << endl;
cout << D3.at(2).getTFIDF() << D3.at(2).getWord() << endl;
cout << D3.at(3).getTFIDF() << D3.at(3).getWord() << endl;

cout << "output" << endl;

cout << D1.Sim(D2) << endl;
cout << D1.Sim(D3) << endl;

EXPECT_NEAR(0, D1.Sim(D2), .0001);
EXPECT_NEAR(.248065, D1.Sim(D3), .0001);


}

TEST(DOC, find2)
{
Word w1("BALLS");
Word w2("Apple");
Word w3("Cat");
Word w4("-*/*-*/");
Word w5("haha");
Word w6("BALLS");

vector<Word> V1 = {w1,w2,w3,w4};
Document D1(V1);

cout << D1.find(w6).getWord() << endl;
cout << w6.getWord() << endl;
EXPECT_EQ(D1.find(w1), w6);
EXPECT_EQ(D1.find(w2), V1[1]);
}

TEST(DOC, sim2)
{
Word w1("BALLS");
Word w2("Apple");
Word w3("Cat");
Word w4("-*/*-*/");
Word w5("haha");
Word w6("BALLS");
w1.setfrequency(2);
w6.setfrequency(2);
vector<Word> V1 = {w1,w2,w3,w4};
Document D1(V1);

vector<Word> V2 = {w2,w2,w3,w5};
Document D2(V2);

vector<Word> V3 = {w2,w2,w3,w6};
Document D3(V3);

vector<Document> DOCS = {D1, D2, D3};

D1.setTFIDFs(DOCS);
D2.setTFIDFs(DOCS);
D3.setTFIDFs(DOCS);

cout << "D1 " << endl;

cout << D1.at(0).getTFIDF() << D1.at(0).getWord() << endl;
cout << D1.at(1).getTFIDF() << D1.at(1).getWord() << endl;
cout << D1.at(2).getTFIDF() << D1.at(2).getWord() << endl;
cout << D1.at(3).getTFIDF() << D1.at(3).getWord() << endl;

cout << "D3 " << endl;

cout << D3.at(0).getTFIDF() << D3.at(0).getWord() << endl;
cout << D3.at(1).getTFIDF() << D3.at(1).getWord() << endl;
cout << D3.at(2).getTFIDF() << D3.at(2).getWord() << endl;
cout << D3.at(3).getTFIDF() << D3.at(3).getWord() << endl;

cout << "output" << endl;

cout << D1.Sim(D2) << endl;
cout << D1.Sim(D3) << endl;

EXPECT_NEAR(0, D1.Sim(D2), .0001);
EXPECT_NEAR(.12403, D1.Sim(D3), .0001);
EXPECT_NEAR(.12403, D3.Sim(D1), .0001);

}



TEST(DOC, TFIDFEDGE)
{
Word w1("BALLS");
Word w2("Apple");
Word w3("Cat");
Word w4("-*/*-*/");
Word w5(".1");
Word w6("20,000");
Word w7("123456");
Word w8("1.2");
Word w9("bruce's");

vector<Word> V1 = {w1,w2,w3,w4,w5,w6,w7,w8,w9};
Document D1(V1);

vector<Word> V2 = {w1};
Document D2(V2);

vector<Word> V3 = {w1};
Document D3(V3);

vector<Document> DOCS = {D1, D2, D3};
D1.setTFIDF(DOCS, w1);
D1.setTFIDF(DOCS, w2);
D1.setTFIDF(DOCS, w3);
D1.setTFIDF(DOCS, w4);
D1.setTFIDF(DOCS, w5);
D1.setTFIDF(DOCS, w6);
D1.setTFIDF(DOCS, w7);
D1.setTFIDF(DOCS, w8);
D1.setTFIDF(DOCS, w9);


cout << w1.getTFIDF() << endl;
cout << w2.getTFIDF() << endl;
cout << w3.getTFIDF() << endl;
cout << w4.getTFIDF() << endl;
cout << w5.getTFIDF() << endl;
cout << w6.getTFIDF() << endl;
cout << w7.getTFIDF() << endl;
cout << w8.getTFIDF() << endl;
cout << w9.getTFIDF() << endl;


EXPECT_NEAR(0, w1.getTFIDF(), .0001);
EXPECT_NE(0, w2.getTFIDF());
EXPECT_NE(0, w3.getTFIDF());
EXPECT_NEAR(0, w4.getTFIDF(), .0001);
EXPECT_NE(0, w5.getTFIDF());
EXPECT_NE(0, w6.getTFIDF());
EXPECT_NE(0, w7.getTFIDF());
EXPECT_NE(0, w8.getTFIDF());
EXPECT_NE(0, w9.getTFIDF());

}



TEST(DOC, TFIDFEDGE2)
{
Word w1("AAA.AAA.AAA");
Word w2("/");
Word w3(".");
Word w4("-*/*-*/");
Word w10("0bb???");

Word w5(".1");

Word w6("20,000");
Word w7("123456");
Word w8("1.2");
Word w9("bruce's");

vector<Word> V1 = {w1,w2,w3,w4,w5,w6,w7,w8,w9};
Document D1(V1);

vector<Word> V2 = {w1};
Document D2(V2);

vector<Word> V3 = {w1};
Document D3(V3);

vector<Document> DOCS = {D1, D2, D3};
D1.setTFIDF(DOCS, w1);
D1.setTFIDF(DOCS, w2);
D1.setTFIDF(DOCS, w3);
D1.setTFIDF(DOCS, w4);
D1.setTFIDF(DOCS, w5);
D1.setTFIDF(DOCS, w6);
D1.setTFIDF(DOCS, w7);
D1.setTFIDF(DOCS, w8);
D1.setTFIDF(DOCS, w9);


cout << w1.getTFIDF() << endl;
cout << w2.getTFIDF() << endl;
cout << w3.getTFIDF() << endl;
cout << w4.getTFIDF() << endl;
cout << w5.getTFIDF() << endl;
cout << w6.getTFIDF() << endl;
cout << w7.getTFIDF() << endl;
cout << w8.getTFIDF() << endl;
cout << w9.getTFIDF() << endl;
cout << w10.getTFIDF() << endl;

EXPECT_NEAR(0, w1.getTFIDF(), .0001);
EXPECT_NEAR(0, w2.getTFIDF(), .0001);
EXPECT_NEAR(0, w3.getTFIDF(), .0001);
EXPECT_NEAR(0, w4.getTFIDF(), .0001);
EXPECT_NEAR(0, w10.getTFIDF(), .0001);
EXPECT_NE(0, w5.getTFIDF());
EXPECT_NE(0, w6.getTFIDF());
EXPECT_NE(0, w7.getTFIDF());
EXPECT_NE(0, w8.getTFIDF());
EXPECT_NE(0, w9.getTFIDF());

}





TEST(DOC, sim3)
{
Word w1("BALLS");
Word w2("Apple");
Word w3("Cat");
Word w4("-*/*-*/");
Word w5("haha");
Word w6("BALLS");
w1.setfrequency(2);
w6.setfrequency(2);
vector<Word> V1 = {w1,w2,w3,w4};
Document D1(V1);

vector<Word> V2 = {w2,w2,w3,w5};
Document D2(V2);

vector<Word> V3 = {w2,w2,w3,w6};
Document D3(V3);

vector<Document> DOCS = {D1, D2, D3};

D1.setTFIDFs(DOCS);
D2.setTFIDFs(DOCS);
D3.setTFIDFs(DOCS);

cout << "D1 " << endl;

cout << D1.at(0).getTFIDF() << D1.at(0).getWord() << endl;
cout << D1.at(1).getTFIDF() << D1.at(1).getWord() << endl;
cout << D1.at(2).getTFIDF() << D1.at(2).getWord() << endl;
cout << D1.at(3).getTFIDF() << D1.at(3).getWord() << endl;

cout << "D3 " << endl;

cout << D3.at(0).getTFIDF() << D3.at(0).getWord() << endl;
cout << D3.at(1).getTFIDF() << D3.at(1).getWord() << endl;
cout << D3.at(2).getTFIDF() << D3.at(2).getWord() << endl;
cout << D3.at(3).getTFIDF() << D3.at(3).getWord() << endl;

cout << "output" << endl;

cout << D1.Sim(D2) << endl;
cout << D1.Sim(D3) << endl;

EXPECT_NEAR(0, D1.Sim(D2), .0001);
EXPECT_NEAR(.12403, D1.Sim(D3), .0001);
EXPECT_NEAR(.12403, D3.Sim(D1), .0001);

}














