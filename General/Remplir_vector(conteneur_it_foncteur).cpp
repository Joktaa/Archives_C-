#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Remplir
{
    int m_valeur = 0;
    int m_fin;

public:

    void operator()(int a, int b, vector<int>& tab)
    {
        m_valeur = a;
        m_fin = b;

        do
        {
            tab.push_back(m_valeur);
            ++m_valeur;
        } while (m_valeur < m_fin);
    }
};


int main(int argc, char const *argv[])
{
    Remplir remplir;
    vector<int> a;
    vector<int>::iterator it;

    remplir(1,10, a);

    for(it=a.begin(); it!=a.end(); ++it)
    {
        cout<<*it<<endl;
    }

    return 0;
}
