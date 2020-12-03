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

TEST(ParseTests, SubAddTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "-",
        "1",
        "+",
        "1"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 - 1.000000 + 1.000000");
    EXPECT_EQ(result->evaluate(), 2);
}


TEST(ParseTests, SubSubTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "-",
        "2",
        "-",
        "1"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 - 2.000000 - 1.000000");
    EXPECT_EQ(result->evaluate(), -1);
}

TEST(ParseTests, SubMultTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "-",
        "1",
        "*",
        "5"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 - 1.000000 * 5.000000");
    EXPECT_EQ(result->evaluate(), 5);
}

#endif // BASEFACTORY_TESTS_HPP
