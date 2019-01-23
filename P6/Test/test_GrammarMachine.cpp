#include <GrammarMachine.h>
#include <Except.h>
#include <gtest/gtest.h>
#include <StringTest.h>
#include <vector>
#include <iostream>
using std::endl;
using std::cout;


// macro defineby google testd
TEST(portAlg, step1)
{
	GrammarMachine ss;
	EXPECT_EQ("abc", ss.step1("abc"));
	//compare expected output to actual output
	EXPECT_EQ("abc", ss.step1("\'abc"));
	
}


TEST(portAlg, step2)
{
	GrammarMachine ss;
	string t = "abcsses";
	
	EXPECT_EQ("abcss", ss.step2(t));
}


TEST(portAlg, sentiment)
{
	GrammarMachine ss;
	string t = "sentiment";
	ss.doSteps(t);
	EXPECT_EQ("sentiment", t);
}

TEST(portAlg, step1RECIT)
{
	GrammarMachine ss;
	EXPECT_EQ("cause", ss.step1("\'cause"));
	//compare expected output to actual output
	EXPECT_EQ("ole", ss.step1("ole\'"));
	EXPECT_EQ("programmer", ss.step1("programmer\'s"));
}


TEST(portAlg, step2RECIT)
{
	GrammarMachine ss;
	string t = "masses";
	
	EXPECT_EQ("mass", ss.step2(t));
}

TEST(portAlg, step3RECIT)
{
	GrammarMachine ss;
	string t = "goateedly";
	
	EXPECT_EQ("goatee", ss.step3(t));

	t = "exceed";
	
	EXPECT_EQ("excee", ss.step3(t));

}

TEST(portAlg, step4RECIT)
{
	GrammarMachine ss;
	string t = "decry";
	
	EXPECT_EQ("decri", ss.step4(t));
}

TEST(portAlg, step5RECIT)
{
	GrammarMachine ss;
	string t = "exceptional";
	
	EXPECT_EQ("exception", ss.step5(t));

	t = "anxiousness";
	
	EXPECT_EQ("anxious", ss.step5(t));

	t = "irrational";
	
	EXPECT_EQ("irrate", ss.step5(t));

}



TEST(portAlg, step2T)
{
	GrammarMachine ss;
	string t = "are";
	cout << ss.getRegion1(t);
	EXPECT_EQ("are", ss.step8(t));
}


















