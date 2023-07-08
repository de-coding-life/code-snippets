#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
ll madd(ll aa, ll bb)
{
    return (((aa % md) + (bb % md)) % md);
}
ll msub(ll aa, ll bb)
{
    return (((aa % md) - (bb % md) + md) % md);
}
ll mmul(ll aa, ll bb)
{
    return (((aa % md) * (bb % md)) % md);
}
int main()
{
    cout << mmul(10, 9);
    return 0;
}