#include <GrammarMachine.h>
#include <Except.h>
#include <gtest/gtest.h>
#include <StringTest.h>
#include <vector>

TEST(P5, isPlus)
{
Except ss;
string t = "+Abcsses";
EXPECT_EQ(true, ss.isPlus(t));

}

TEST(P5, isPlus2)
{
Except ss;
string t = "Abcsses";
EXPECT_EQ(false, ss.isPlus(t));

}

TEST(P5, isCaps)
{
Except ss;
string t = "Abcsses";

EXPECT_EQ(true, ss.capsTest(t));

}


TEST(P5, isCaps2)
{
Except ss;
string t = "abcsses";

EXPECT_EQ(false, ss.capsTest(t));

}

TEST(P5, MakeLower)
{
Except ss;
string t = "Abcsses";
ss.makeLower(t);
EXPECT_EQ("abcsses", t);

}

TEST(P5, MakeLower2)
{
Except ss;
string t = "abcsses";
ss.makeLower(t);
EXPECT_EQ("abcsses", t);

}


TEST(P5, capsFind)
{
Except ss;
string t = "Abcsses";
vector<string> r = {"Abcsses","abcsses","Abcsses"};
ss.capsFind(r,t);
EXPECT_EQ("Abcsses", t);

}

TEST(P5, capsFind2)
{
Except ss;
string t = "Abcsses";
vector<string> r = {"abcsses","abcsses","abcsses"};
ss.capsFind(r,t);
EXPECT_EQ("abcsses", t);

}

TEST(P5, capsFind3)
{
Except ss;
string t = "Abcsses";
vector<string> r = {"abcsses","abcsses","Abcsses"};
ss.capsFind(r,t);
EXPECT_EQ("Abcsses", t);

}



TEST(P5, testCaps)
{
Except ss;
vector<string> t = {"Abcsses","abcsses","+Abcsses"};
vector<string> r = {"Abcsses","abcsses","Abcsses"};
ss.capsTest(t);
EXPECT_EQ(r, t);

}

TEST(P5, testCaps2)
{
Except ss;
vector<string> t = {"abcsses","Abcsses","+Abcsses"};
vector<string> r = {"abcsses","Abcsses","Abcsses"};
ss.capsTest(t);
EXPECT_EQ(r, t);

}

TEST(P5, testCaps3)
{
Except ss;
vector<string> t = {"abcsses","abcsses","+Abcsses"};
vector<string> r = {"abcsses","abcsses","abcsses"};
ss.capsTest(t);
EXPECT_EQ(r, t);

}

TEST(P5, testCaps4)
{
Except ss;
vector<string> t = {"abcsses","abcsses","Abcsses"};
vector<string> r = {"abcsses","abcsses","Abcsses"};
ss.capsTest(t);
EXPECT_EQ(r, t);

}

TEST(P5, testCaps5)
{
Except ss;
vector<string> t = {"abcsses","+Abcsses","+Abcsses"};
vector<string> r = {"abcsses","abcsses","abcsses"};
ss.capsTest(t);
EXPECT_EQ(r, t);

}

TEST(P5, emptyTests)
{
Except ss;
vector<string> t = {"","","+Abcsses"};
vector<string> r = {"","","abcsses"};
string a = "";
ss.capsFind(t,a);
EXPECT_EQ("", a);
ss.capsTest(t);
EXPECT_EQ(r, t);
EXPECT_EQ(false, ss.isPlus(""));
EXPECT_EQ(false, ss.capsTest(""));
string b = "";
ss.makeLower(b);
EXPECT_EQ("", b);
}
