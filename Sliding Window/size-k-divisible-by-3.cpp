#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
int main()
{
   /*
      NOTE if sum of digits is div by 3 then number is also div by 3
      but if we directly add number sequentially and it is div by 3 , then also num is div by 3
      hence no need to find sum of digits
   */
   int t;
   cin >> t;
   for (int ii = 0; ii < t; ii++)
   {
      int n, k;
      cin >> n >> k;
      ll a[n];
      for (int i = 0; i < n; i++)
         cin >> a[i];
      ll dsm = 0;
      for (int i = 0; i < k; i++)
         dsm += a[i];
      if (dsm % 3 == 0)
      {
         for (int i = 0; i < k; i++)
            cout << a[i] << " ";
         cout << "\nYES\n";
         continue;
      }
      bool ck = 0;
      for (int i = k; i < n; i++)
      {
         dsm += a[i];
         dsm -= a[i - k];
         if (dsm % 3 == 0)
         {
            for (int j = i - k + 1; j <= i; j++)
               cout << a[j] << " ";
            ck = 1;
            break;
         }
      }
      if (ck)
         cout << "\nYES\n";
      else
         cout << "NO\n";
   }
   return 0;
}