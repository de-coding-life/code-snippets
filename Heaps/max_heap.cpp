#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
class max_heap
{
   vector<int> v; // For i'th element , parent = ((i-1)/2)    ,    l = (2*i) + 1    ,    r = (2*i) + 2
public:
   void insert(int d)
   {
      v.push_back(d);
      int i = v.size() - 1;
      while (i > 0 and v[i] > v[(i - 1) / 2])
      {
         swap(v[i], v[(i - 1) / 2]);
         i = (i - 1) / 2;
      }
   }
   void print()
   {
      cout << endl
           << "Max Heap Array -->\n";
      for (int i = 0; i < v.size(); i++)
      {
         cout << v[i] << " -->  ";
         if (i == 0)
            cout << "Parent -- No  ||  ";
         else
            cout << "Parent -- " << v[(i - 1) / 2] << "  ||  ";
         if ((2 * i) + 1 >= v.size())
            cout << "Left -- No  ||  ";
         else
            cout << "Left -- " << v[(2 * i) + 1] << "  ||  ";
         if ((2 * i) + 2 >= v.size())
            cout << "Right -- No  ||  ";
         else
            cout << "Right -- " << v[(2 * i) + 2] << "  ||  ";
         cout << endl;
      }
   }
};
int main()
{
   max_heap h;
   h.insert(10);
   h.insert(1);
   h.insert(5);
   h.insert(15);
   h.insert(11);
   h.insert(9);
   h.insert(3);
   h.insert(-1);
   h.print();
   return 0;
}