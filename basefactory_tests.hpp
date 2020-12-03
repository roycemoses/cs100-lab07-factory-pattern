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

TEST(ParseTests, DivSubTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "10",
        "/",
        "5",
        "-",
        "4"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "10.000000 / 5.000000 - 4.000000");
    EXPECT_EQ(result->evaluate(), -2);
}

TEST(ParseTests, DivMultTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "20",
        "/",
        "5",
        "*",
        "4"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "20.000000 / 5.000000 * 4.000000");
    EXPECT_EQ(result->evaluate(), 16);
}

TEST(ParseTests, DivDivTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "20",
        "/",
        "5",
        "/",
        "4"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "20.000000 / 5.000000 / 4.000000");
    EXPECT_EQ(result->evaluate(), 1);
}

TEST(ParseTests, DivPowTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "100",
        "/",
        "5",
        "**",
        "3"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "100.000000 / 5.000000 ** 3.000000");
    EXPECT_EQ(result->evaluate(), 8000);
}

TEST(ParseTests, PowAddTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "**",
        "4",
        "+",
        "3"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 ** 4.000000 + 3.000000");
    EXPECT_EQ(result->evaluate(), 19);
}

TEST(ParseTests, PowSubTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "**",
        "5",
        "-",
        "31"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 ** 5.000000 - 31.000000");
    EXPECT_EQ(result->evaluate(), 1);
}

#endif // BASEFACTORY_TESTS_HPP
