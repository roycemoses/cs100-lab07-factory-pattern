#include <iostream>
#include "basefactory.hpp"
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    BaseFactory basefactory;    

    Base* root = basefactory.parse(argv, argc);

    cout << root->stringify() << " = " << root->evaluate() << endl;

    delete root;
}