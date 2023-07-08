#include <bits/stdc++.h>
using namespace std;
class dsu
{
public:
    int n;
    vector<int> par, rank;
    dsu(int nn)
    {
        n = nn;
        for (int i = 0; i < nn; i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int x)
    {
        if (par[x] == x)
            return x;
        par[x] = find(par[x]);
        return par[x];
    }
    void unio(int a, int b)
    {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb)
            return;
        if (rank[ra] > rank[rb])
            par[rb] = ra;
        else if (rank[ra] < rank[rb])
            par[ra] = rb;
        else
        {
            par[rb] = ra;
            rank[ra]++;
        }
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