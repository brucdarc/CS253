#include <GrammarMachine.h>
#include <Except.h>
#include <gtest/gtest.h>
#include <StringTest.h>
#include <vector>

int main(int argc, char** argv)
{
	//  :: before means global scope
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}
