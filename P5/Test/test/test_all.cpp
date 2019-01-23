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


TEST(DISABLED_helperTest, DISABLED_isVowel) //either place disables test
{

Stem ss;
EXPECT_TRUE(ss.isVowel('a'));
EXPECT_TRUE(ss.isVowel('e'));
EXPECT_FALSE(ss.isVowel('c'));
	for(char c = 'a'; c<='z'; c++)
	{
		if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
			EXPECT_TRUE(ss.isVowel(c));
		else 
		EXPECT_FALSE(ss.isVowel(c));

	}

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







int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
