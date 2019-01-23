#include <stem.h>
#include <gtest/gtest.h>


TEST(portAlg, step1)
{
	Stem ss;
	EXPECT_EQ("abc", ss.step1("abc"));
	EXPECT_EQ("def", ss.step1("\'def"));
}

TEST(portAlg, step2)
{
	Stem ss;
	string t = "abcsses";
	ss.step2(t);
	EXPECT_EQ("abcss", t);
}

TEST(portAlg, step3)	//disables test
{
	
	

	Stem ss;
	ASSERT_TRUE(ss.isVowel('a'));
	ASSERT_FALSE(ss.isVowel('c'));
	string test = "conditioning";
	ss.step3(test);
	EXPECT_EQ("condition" , test);	//expect equal
	EXPECT_NE("conditioning" , test);	//expect notequal

}
