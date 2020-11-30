#ifndef __BASE_FACTORY__
#define __BASE_FACTORY__

#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"

class BaseFactory
{
    public:
        Base* parse(char** input, int length);
}

#endif // __BASE_FACTORY__