#ifndef BASEFACTORY_TESTS_HPP
#define BASEFACTORY_TESTS_HPP

#include "gtest/gtest.h"
#include "basefactory.hpp"

TEST(ParseTests, AddParseTest)
{
    const int LENGTH = 4;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "+",
        "2"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 + 2.000000");
    EXPECT_EQ(result->evaluate(), 4);
}

TEST(ParseTests, MultParseTest)
{
    const int LENGTH = 4;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "*",
        "2"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 * 2.000000");
    EXPECT_EQ(result->evaluate(), 4);
}

TEST(ParseTests, PowParseTest)
{
    const int LENGTH = 4;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "**",
        "2"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 ** 2.000000");
    EXPECT_EQ(result->evaluate(), 4);
}
#endif // BASEFACTORY_TESTS_HPP
