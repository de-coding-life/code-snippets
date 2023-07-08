#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
int main()
{
   int n, k;
   cin >> n >> k;
   ll temp;
   priority_queue<ll> p;
   for (int i = 0; i < n; i++)
   {
      cin >> temp;
      p.push(temp);
   }
   while (k--)
   {
      cout << p.top() << " ";
      p.pop();
   }
   return 0;
}

/*
We could also have used sorting --> O(nlogn)
Heaps --> O(k*logn)
*/