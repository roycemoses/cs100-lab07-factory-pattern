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
            std::cout << "length: " << length << std::endl;
            Base* result = nullptr;

            // check if the input[1] is a number (cstring of digits)
            char temp = input[1][0];
            int i = 0;
            do {
                if (!isdigit(temp))
                {
                    std::invalid_argument ia("Invalid argument: Expected a left operand.");
                    throw ia;
                }
                ++i;
                temp = input[1][i];
            } while (temp != '\0');

            Base* leftOp = new Op(atoi(input[1]));

            int arrayIndex = 2;

            while (arrayIndex < length)
            {
                // check that the operator character is 1 character
                if (input[arrayIndex][1] != '\0')
                {
                    if (input[arrayIndex][1] != '^')
                    {
                        std::invalid_argument ia("Invalid argument. Expected an operator.");
                        throw ia;
                    }
                }
                
                char op = input[arrayIndex][0]; // op is an operator

                ++arrayIndex;

                if (arrayIndex >= length)
                {
                    std::invalid_argument ia("Invalid argument. Expected a right operand.");
                    throw ia;
                }

                // check if the input[arrayIndex] is a number (cstring of digits)
                char temp = input[arrayIndex][0];
                int i = 0;
                do {
                    if (!isdigit(temp))
                    {
                        std::invalid_argument ia("Invalid argument: Expected a left operand.");
                        throw ia;
                    }
                    ++i;
                    temp = input[arrayIndex][i];
                } while (temp != '\0');

                Base* rightOp = new Op(atoi(input[arrayIndex]));

                if (op == '+')
                    result = new Add(leftOp, rightOp);
                else if (op == '-')
                    result = new Sub(leftOp, rightOp);
                else if (op == 'x')
                {
                    if (input[arrayIndex - 1][1] != '^')
                        result = new Mult(leftOp, rightOp);
                    else
                        result = new Pow(leftOp, rightOp);
                }
                else if (op == '/')
                    result = new Div(leftOp, rightOp);
                else
                {
                    std::invalid_argument ia("Invalid argument: Expected an operator.");
                    throw ia;
                }

                ++arrayIndex;
                leftOp = result;
            }

            return result;
        }

};

#endif // __BASE_FACTORY__