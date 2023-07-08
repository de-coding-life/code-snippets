#include <bits/stdc++.h>
using namespace std;
class dsu
{
public:
    int n;
    vector<int> par;
    dsu(int nn)
    {
        n = nn;
        for (int i = 0; i < nn; i++)
        {
            par.push_back(i);
        }
    }
    int find(int x)
    {
        if (par[x] == x)
            return x;
        return find(par[x]);
    }
    void unio(int a, int b)
    {
        int ra = find(a);
        int rb = find(b);
        par[ra] = rb;
    }
};
int main()
{
    dsu my(5);
    cout << my.find(0);
    cout << my.find(2);
    my.unio(0, 2);
    my.unio(1, 4);
    cout << my.find(0);
    cout << my.find(2);
    cout << my.find(1);
    cout << my.find(4);
    my.unio(1, 2);
    cout << my.find(0);
    cout << my.find(2);
    cout << my.find(1);
    cout << my.find(4);
    return 0;
}