#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
class triplet
{
public:
   ll data, arr, ind;
   triplet(ll d, ll a, ll ii)
   {
      data = d;
      arr = a;
      ind = ii;
   }
};
struct mycomp
{
   bool operator()(triplet a, triplet b)
   {
      return (a.data > b.data);
   }
};
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int k;
   cin >> k;
   vector<vector<ll>> v(k);
   for (int i = 0; i < k; i++)
   {
      int n;
      cin >> n;
      ll temp;
      for (int j = 0; j < n; j++)
      {
         cin >> temp;
         v[i].push_back(temp);
      }
   }
   priority_queue<triplet, vector<triplet>, mycomp> pq;
   for (int i = 0; i < k; i++)
   {
      triplet tt(v[i][0], i, 0);
      pq.push(tt);
   }
   while (!pq.empty())
   {
      triplet tt = pq.top();
      pq.pop();
      cout << tt.data << " ";
      if (v[tt.arr].size() - 1 > tt.ind)
      {
         tt.ind++;
         tt.data = v[tt.arr][tt.ind];
         pq.push(tt);
      }
   }
   return 0;
}