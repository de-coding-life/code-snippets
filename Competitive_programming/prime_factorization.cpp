#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll, ll> prf(ll tnx) // Handle 1 Carefully  O(_/n)
{
   ll qq = 2;
   map<ll, ll> tmpt;
   while (tnx > 1)
   {
      if ((tnx % qq) == 0)
      {
         tmpt[qq]++;
         tnx /= qq;
      }
      else
         qq++;
   }
   return tmpt;
}
int main()
{
   ll n;
   cin >> n;
   map<ll, ll> mp = prf(n);
   for (auto i : mp)
   {
      cout << i.first << " ^ " << i.second << endl;
   }
   return 0;
}