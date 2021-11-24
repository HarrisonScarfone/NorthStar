#include "../src/utilities.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace {
TEST(UtilitiesTest, correctly_tokenizes_string_based_on_delimeter_into_vector) {
    std::string test_string = "this - test";
    std::string test_delimiter = " ";
    std::vector<std::string> expected_result = {"this", "-", "test"};

    std::vector<std::string> result = Utilities::StringHandlers::TokenizeByDelimiter(test_string, test_delimiter);

    EXPECT_EQ(expected_result.at(0), result.at(0));
    EXPECT_EQ(expected_result.at(1), result.at(1));
    EXPECT_EQ(expected_result.at(2), result.at(2));
    EXPECT_THROW(expected_result.at(3), std::out_of_range);
}
}  // namespace