#include <iostream>
#include <string>
#include "Fraction.h"

using namespace std;

int main()
{
    Fraction a(10,6), b(10,6);

    if(a > b)
        cout << "oui" << endl;
    else
        cout << "non" << endl;
}