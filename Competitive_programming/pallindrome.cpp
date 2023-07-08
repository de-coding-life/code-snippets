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
   string s;
   cin >> s;
   cout << pall(s);
   return 0;
}