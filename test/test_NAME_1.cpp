#include <../gtest/gtest.h>
#include "NAME_1.h"

TEST(TEST_NAME_1, even)
{
	int value = even(8);
	EXPECT_EQ(0, value);
}