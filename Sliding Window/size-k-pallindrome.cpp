#include <bits/stdc++.h>
using namespace std;
bool pall(string sts)
{
   for (int qq = 0; qq < sts.size() / 2; qq++)
   {
      if (sts[qq] != sts[sts.size() - 1 - qq])
         return 0;
   }
   return 1;
}
int main()
{
   int k;
   cin >> k;
   string a;
   cin >> a;
   bool ck = 0;
   for (int i = 0; i < a.size() - k + 1; i++)
   {
      if (pall(a.substr(i, k)))
      {
         ck = 1;
         break;
      }
   }
   if (ck)
      cout << "YES\n";
   else
      cout << "NO\n";
   return 0;
}