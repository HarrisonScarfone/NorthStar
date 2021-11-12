#include <gtest/gtest.h>
#include "../src/somefunctions.h"

TEST(AddTwoFunctionsTest, BasicAssertions)
{
    EXPECT_EQ(SomeFunctions::addTwoInts(2,2), 4);
}
