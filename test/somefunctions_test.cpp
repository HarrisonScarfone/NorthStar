#include "../src/somefunctions.h"

#include <gtest/gtest.h>

TEST(AddTwoFunctionsTest, BasicAssertions) {
    EXPECT_EQ(SomeFunctions::addTwoInts(2, 2), 4);
}
