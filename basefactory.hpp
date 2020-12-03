#ifndef __BASE_FACTORY__
#define __BASE_FACTORY__

#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"
#include <stdexcept>
#include <iostream>

class BaseFactory
{
    public:
        Base* parse(char** input, int length)
        {
            Base* result = nullptr;

            // check if the leftOp is a number (cstring of digits)
            char temp = input[1][0];
            int i = 0;
            do {
                if (!isdigit(temp))
                    return nullptr;
                ++i;
                temp = input[1][i];
            } while (temp != '\0');

            Base* leftOp = new Op(atoi(input[1]));  // set leftOp
            int arrayIndex = 2;
            if (arrayIndex >= length) // if user only enters a single Op, return leftOp
                return leftOp;

            while (arrayIndex < length)
            {
                // check that the operator character is 1 character
                // if not, check that the operator is the Pow (**) operator 
                // otherwise, it is an invalid input
                if (input[arrayIndex][1] != '\0')
                    if (input[arrayIndex][0] != '*' || input[arrayIndex][1] != '*')
                        return nullptr;
                
                char op = input[arrayIndex][0]; // op is an operator
                ++arrayIndex;
                if (arrayIndex >= length)       // if there is no right Op, it is invalid input
                    return nullptr;

                // check if the rightOp is a number (cstring of digits)
                char temp = input[arrayIndex][0];
                int i = 0;
                do {
                    if (!isdigit(temp))
                        return nullptr;
                    ++i;
                    temp = input[arrayIndex][i];
                } while (temp != '\0');

                Base* rightOp = new Op(atoi(input[arrayIndex]));    // set rightOp

                if (op == '+')
                    result = new Add(leftOp, rightOp);
                else if (op == '-')
                    result = new Sub(leftOp, rightOp);
                else if (op == '*')
                {
                    if (input[arrayIndex - 1][1] != '*')
                        result = new Mult(leftOp, rightOp);
                    else
                        result = new Pow(leftOp, rightOp);
                }
                else if (op == '/')
                    result = new Div(leftOp, rightOp);
                else    // if not an operator character, it is invalid input
                    return nullptr;

                ++arrayIndex;
                leftOp = result;
            }
            return result;
        }
};

#endif // __BASE_FACTORY__