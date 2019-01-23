#include <stem.h>
#include <gtest/gtest.h>
// macro defineby google testd
TEST(portAlg, step1)
{
	Stem ss;
	EXPECT_EQ("abc", ss.step1("abc"));
	//compare expected output to actual output
	EXPECT_EQ("abc", ss.step1("\'abc"));
	
}


TEST(portAlg, step2)
{
	Stem ss;
	string t = "abcsses";
	ss.step2(t);
	EXPECT_EQ("abcss", t);
}


int main(int argc, char** argv)
{
	//  :: before means global scope
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}
