#include <iostream>
#include <string>

using namespace std;

template <class T>
class testTemplate
{
private:
    T a, b;

public:
    testTemplate(T x, T y);
    T bigger();
    T smaller();
    void aIsAChar();
};

template < >
class testTemplate<char>
{
private:
    char a, b;
public : 
    testTemplate(char x, char y) : a(x), b(y){}
    void aIsAChar()
    {
        cout<<a<<" is a char"<<endl;
    }
};