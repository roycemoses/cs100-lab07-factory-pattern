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

TEST(ParseTests, SingleOpParseTest)
{
    const int LENGTH = 2;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000");
    EXPECT_EQ(result->evaluate(), 2);
}

TEST(ParseTests, InvalidInputNoRightOpTest)
{
    const int LENGTH = 3;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "*"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_TRUE(result == nullptr);
}

TEST(ParseTests, InvalidInputNoLeftOpTest)
{
    const int LENGTH = 3;
    char* input[LENGTH] = {
        "./calculator.exe",
        "*",
        "2"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_TRUE(result == nullptr);
}

TEST(ParseTests, InvalidInputNoOperatorTest)
{
    const int LENGTH = 3;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "2"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_TRUE(result == nullptr);
}

TEST(ParseTests, InvalidInputInvalidOperatorTest)
{
    const int LENGTH = 4;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "^",
        "2"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_TRUE(result == nullptr);
}

TEST(ParseTests, InvalidInputInvalidLeftOpTest)
{
    const int LENGTH = 4;
    char* input[LENGTH] = {
        "./calculator.exe",
        "a",
        "*",
        "2"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_TRUE(result == nullptr);
}

TEST(ParseTests, InvalidInputInvalidRightOpTest)
{
    const int LENGTH = 4;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "*",
        "x"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_TRUE(result == nullptr);
}

TEST(ParseTests, InvalidInputPowCheckTest)
{
    const int LENGTH = 4;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "+*",
        "3"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_TRUE(result == nullptr);
}

TEST(ParseTests, AddAddParseTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "+",
        "2",
        "+",
        "4"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 + 2.000000 + 4.000000");
    EXPECT_EQ(result->evaluate(), 8);
}

TEST(ParseTests, AddSubParseTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "+",
        "10",
        "-",
        "3"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 + 10.000000 - 3.000000");
    EXPECT_EQ(result->evaluate(), 9);
}

TEST(ParseTests, AddMultParseTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "+",
        "10",
        "*",
        "3"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 + 10.000000 * 3.000000");
    EXPECT_EQ(result->evaluate(), 36);
}

TEST(ParseTests, AddDivParseTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "+",
        "10",
        "/",
        "4"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 + 10.000000 / 4.000000");
    EXPECT_EQ(result->evaluate(), 3);
}

TEST(ParseTests, AddPowParseTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "+",
        "3",
        "**",
        "3"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 + 3.000000 ** 3.000000");
    EXPECT_EQ(result->evaluate(), 125);
}

TEST(ParseTests, MultAddParseTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "*",
        "3",
        "+",
        "3"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);
    EXPECT_EQ(result->stringify(), "2.000000 * 3.000000 + 3.000000");
    EXPECT_EQ(result->evaluate(), 9);
}

TEST(ParseTests, MultSubParseTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "*",
        "3",
        "-",
        "3"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 * 3.000000 - 3.000000");
    EXPECT_EQ(result->evaluate(), 3);
}

TEST(ParseTests, MultMultParseTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "*",
        "3",
        "*",
        "3"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 * 3.000000 * 3.000000");
    EXPECT_EQ(result->evaluate(), 18);
}

TEST(ParseTests, MultDivParseTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "*",
        "16",
        "/",
        "8"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 * 16.000000 / 8.000000");
    EXPECT_EQ(result->evaluate(), 4);
}

TEST(ParseTests, MultPowParseTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "*",
        "2",
        "**",
        "4"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 * 2.000000 ** 4.000000");
    EXPECT_EQ(result->evaluate(), 256);
}

#endif // BASEFACTORY_TESTS_HPP
