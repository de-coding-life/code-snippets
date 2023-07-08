#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
int isperfect(ll temp)
{
   if (temp == 1)
      return 0;
   ll ans = 1;
   for (int i = 2; i <= sqrt(temp); i++)
   {
      if (temp % i == 0)
      {
         ans += i;
         if ((temp / i) != i)
            ans += temp / i;
      }
   }
   if (temp == ans)
      return 1;
   else
      return 0;
}
int main()
{
   int n, k;
   cin >> n >> k;
   int a[n];
   ll temp;
   ll sm = 0;
   for (int i = 0; i < n; i++)
   {
      cin >> temp;
      a[i] = isperfect(temp);
      if (i < k)
         sm += a[i];
   }
   ll ans = sm;
   for (int i = k; i < n; i++)
   {
      sm += a[i];
      sm -= a[i - k];
      ans = max(ans, sm);
   }
   cout << ans << endl;
   return 0;
}