#include <GrammarMachine.h>
#include <gtest/gtest.h>
#include <StringTest.h>
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


int main(int argc, char** argv)
{
	//  :: before means global scope
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}
