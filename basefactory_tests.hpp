#ifndef BASEFACTORY_TESTS_HPP
#define BASEFACTORY_TESTS_HPP

#include "gtest/gtest.h"
#include "basefactory.hpp"

TEST(ParseTests, LargeOpTest)
{
    const int LENGTH = 2;
    char* input[LENGTH] = {
        "./calculator.exe",
        "991827"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "991827.000000");
    EXPECT_EQ(result->evaluate(), 991827);
}

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

TEST(ParseTests, SubDivTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "-",
        "0",
        "/",
        "2"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 - 0.000000 / 2.000000");
    EXPECT_EQ(result->evaluate(), 1);
}

TEST(ParseTests, SubPowTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "-",
        "0",
        "**",
        "4"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 - 0.000000 ** 4.000000");
    EXPECT_EQ(result->evaluate(), 16);
}

TEST(ParseTests, DivTest)
{
    const int LENGTH = 4;
    char* input[LENGTH] = {
        "./calculator.exe",
        "100",
        "/",
        "25"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "100.000000 / 25.000000");
    EXPECT_EQ(result->evaluate(), 4);
}

TEST(ParseTests, DivAddTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "10",
        "/",
        "2",
        "+",
        "4"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "10.000000 / 2.000000 + 4.000000");
    EXPECT_EQ(result->evaluate(), 9);
}


#endif // BASEFACTORY_TESTS_HPP
