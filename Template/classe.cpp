#include "classe.h"

template <class T>
testTemplate<T>::testTemplate(T x, T y) : a(x), b(y){}

template <class T>
T testTemplate<T>::bigger()
{
    return a>b?a:b;
}

template <class T>
T testTemplate<T>::smaller()
{
    return a<b?a:b;
}

template <class T>
void testTemplate<T>::aIsAChar()
{
    cout<<a<<" is not a char"<<endl;
}

template class testTemplate<int>;
template class testTemplate<float>;
template class testTemplate<string>;