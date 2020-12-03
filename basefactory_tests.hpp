#ifndef BASEFACTORY_TESTS_HPP
#define BASEFACTORY_TESTS_HPP

#include "gtest/gtest.h"
#include "basefactory.hpp"

TEST(ParseTests, SubTest)
{
    const int LENGTH = 4;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "-",
        "1"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 - 1.000000");
    EXPECT_EQ(result->evaluate(), 1);
}

#endif // BASEFACTORY_TESTS_HPP
