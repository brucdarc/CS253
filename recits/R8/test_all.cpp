#include <stem.h>
#include <gtest/gtest.h>

int main(int argc, char** argv)
{
	//  :: before means global scope
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}
