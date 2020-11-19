#include <iostream>
#include <string>
#include "classe.h"

using namespace std;

int main(int argc, char const *argv[])
{
    testTemplate<int> x(7,3);
    testTemplate<char> y('x', 'a');
    testTemplate<string> z("edcsbcs", "zcsbiu");

    x.aIsAChar();
    y.aIsAChar();
    z.aIsAChar();

    return 0;
}