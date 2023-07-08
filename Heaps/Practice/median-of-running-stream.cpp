#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin >> n;
   ld a[n];
   for (int i = 0; i < n; i++)
      cin >> a[i];
   if (n == 1)
   {
      cout << setprecision(10) << a[0] << " ";
      return 0;
   }
   priority_queue<ld> pq1;
   priority_queue<ld, vector<ld>, greater<ld>> pq2;
   pq1.push(a[0]);
   cout << setprecision(10) << a[0] << " ";
   if (a[1] >= a[0])
   {
      pq2.push(a[1]);
   }
   else
   {
      pq1.pop();
      pq2.push(a[0]);
      pq1.push(a[1]);
   }
   cout << setprecision(10) << (a[0] + a[1]) / 2 << " ";
   for (int i = 2; i < n; i++)
   {
      if (a[i] <= pq2.top())
      {
         pq1.push(a[i]);
         if (pq1.size() - pq2.size() >= 2)
         {
            pq2.push(pq1.top());
            pq1.pop();
         }
      }
      else
      {
         pq2.push(a[i]);
         if (pq2.size() - pq1.size() >= 1)
         {
            pq1.push(pq2.top());
            pq2.pop();
         }
      }
      if (pq1.size() == pq2.size())
      {
         cout << setprecision(10) << (pq1.top() + pq2.top()) / 2 << " ";
      }
      else
      {
         cout << setprecision(10) << pq1.top() << " ";
      }
   }
   return 0;
}