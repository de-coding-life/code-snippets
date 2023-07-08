#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
   priority_queue<ll> p;
   p.push(20);
   p.push(40); // O(logn)
   p.push(30);
   p.push(10);
   p.push(50);
   while (p.size() != 0)
   {
      cout << p.top() << " "; // O(1)
      p.pop();                // O(logn)
   }
   cout << endl;

   priority_queue<ll, vector<ll>, greater<ll>> q;
   q.push(20);
   q.push(40); // O(logn)
   q.push(30);
   q.push(10);
   q.push(50);
   while (q.size() != 0)
   {
      cout << q.top() << " "; // O(1)
      q.pop();                // O(logn)
   }
   cout << endl;

   int arr[] = {1, 2, 3, 4, 5, 6};
   priority_queue<ll> r(arr, arr + 6);
   while (r.size() != 0)
   {
      cout << r.top() << " "; // O(1)
      r.pop();                // O(logn)
   }

   // I can also create heap using custom class, it will require mycomp function
   return 0;
}