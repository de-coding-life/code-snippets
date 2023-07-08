#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t;
   cin >> t;
   for (int ii = 0; ii < t; ii++)
   {
      int n, k;
      cin >> n >> k;
      k++;
      ll a[n];
      for (int i = 0; i < n; i++)
         cin >> a[i];
      priority_queue<int, vector<int>, greater<int>> p;
      for (int i = 0; i < k; i++)
         p.push(a[i]);
      for (int i = k; i < n; i++)
      {
         a[i - k] = p.top();
         p.pop();
         p.push(a[i]);
      }
      for (int i = n - k; i < n; i++)
      {
         a[i] = p.top();
         p.pop();
      }
      for (int i = 0; i < n; i++)
         cout << a[i] << " ";
      cout << endl;
   }
   return 0;
}