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


#endif // BASEFACTORY_TESTS_HPP
