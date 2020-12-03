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

TEST(ParseTests, PowTest)
{
    const int LENGTH = 4;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "**",
        "6",
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 ** 6.000000");
    EXPECT_EQ(result->evaluate(), 64);
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


TEST(ParseTests, PowMultTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "**",
        "6",
        "*",
        "2"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 ** 6.000000 * 2.000000");
    EXPECT_EQ(result->evaluate(), 128);
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

TEST(ParseTests, PowDivTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "**",
        "6",
        "/",
        "2"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 ** 6.000000 / 2.000000");
    EXPECT_EQ(result->evaluate(), 32);
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

TEST(ParseTests, PowPowTest)
{
    const int LENGTH = 6;
    char* input[LENGTH] = {
        "./calculator.exe",
        "2",
        "**",
        "2",
        "**",
        "2"
    };

    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);

    EXPECT_EQ(result->stringify(), "2.000000 ** 2.000000 ** 2.000000");
    EXPECT_EQ(result->evaluate(), 16);
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

TEST(ParseTests, InputLengthIsOne)
{
    const int LENGTH = 1;
    char* input[LENGTH] = {
        "./calculator.exe"
    };
    
    BaseFactory basefactory;
    Base* result = basefactory.parse(input, LENGTH);    
    EXPECT_TRUE(result == nullptr);
}

#endif // BASEFACTORY_TESTS_HPP
