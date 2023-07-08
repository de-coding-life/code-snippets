#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
int main()
{
   int n, x, k;
   cin >> n >> x >> k;
   ll temp;
   priority_queue<ll, vector<ll>, greater<ll>> pp, pn;
   pp.push(LLONG_MAX);
   pn.push(LLONG_MAX);
   for (int i = 0; i < n; i++)
   {
      cin >> temp;
      temp -= x;
      if (temp >= 0)
         pp.push(temp);
      else
         pn.push(-1 * temp);
   }
   while (k--)
   {
      if (pp.top() < pn.top())
      {
         cout << x + pp.top() << " ";
         pp.pop();
      }
      else
      {
         cout << x - pn.top() << " ";
         pn.pop();
      }
   }
   return 0;
}