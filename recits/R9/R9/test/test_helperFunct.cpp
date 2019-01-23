#include <stem.h>
#include <gtest/gtest.h>


TEST(helperTest, isVowel) //either place disables test
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
