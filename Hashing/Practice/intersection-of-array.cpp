#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
vector<ll> intersection(vector<ll> v11, vector<ll> v22)
{
    set<ll> ss1;
    for (int nn = 0; nn < v11.size(); nn++)
        ss1.insert(v11[nn]);
    vector<ll> aans;
    for (int nn = 0; nn < v11.size(); nn++)
    {
        if (ss1.find(v22[nn]) != ss1.end())
        {
            aans.push_back(v22[nn]);
            ss1.erase(ss1.find(v22[nn]));
        }
    }
    sort(aans.begin(), aans.end());
    return aans;
}
int main()
{
    vector<ll> v = intersection({1, 2, 2, 3, 4}, {2, 2, 5, 6});
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}