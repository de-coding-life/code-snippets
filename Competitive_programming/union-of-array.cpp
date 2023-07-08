#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
vector<ll> unionn(vector<ll> v11, vector<ll> v22)
{
    set<ll> ss1;
    for (int nn = 0; nn < v11.size(); nn++)
        ss1.insert(v11[nn]);
    for (int nn = 0; nn < v22.size(); nn++)
        ss1.insert(v22[nn]);
    vector<ll> aans;
    for (auto nn = ss1.begin(); nn != ss1.end(); nn++)
        aans.push_back(*nn);
    return aans;
}
int main()
{
    vector<ll> v = unionn({1, 2, 2, 3, 4}, {2, 2, 5, 6});
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}