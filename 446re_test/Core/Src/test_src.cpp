#include "CppUTest/TestHarness.h"

TEST_GROUP(FirstTestGroup)
{

};

TEST(FirstTestGroup, FirstTest)
{
	FAIL("FAIL: FirstTestGroup, FirstTest\n");
}

TEST(FirstTestGroup, SecondTest)
{
	CHECK_EQUAL_ZERO(0);
}

TEST(FirstTestGroup, IntSize)
{
	LONGS_EQUAL(4, sizeof(int));
}
