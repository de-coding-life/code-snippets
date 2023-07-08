#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
#define nl cout << endl
class min_heap
{
public:
   vector<int> v;     // For i'th element , parent = ((i-1)/2)    ,    l = (2*i) + 1    ,    r = (2*i) + 2
   void insert(int d) // Time Complexity is O(logn)
   {
      v.push_back(d);
      int i = v.size() - 1;
      while (i > 0 and v[i] < v[(i - 1) / 2])
      {
         swap(v[i], v[(i - 1) / 2]);
         i = (i - 1) / 2;
      }
   }
   void print()
   {
      cout << endl
           << "Min Heap Array -->\n";
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
   void heapify(int i) // Time Complexity is O(logn)
   {
      int mini = i;
      if ((2 * i) + 1 < v.size() && v[(2 * i) + 1] < v[i])
         mini = (2 * i) + 1;
      if ((2 * i) + 2 < v.size() && v[(2 * i) + 2] < v[mini])
         mini = (2 * i) + 2;
      if (mini != i)
      {
         swap(v[i], v[mini]);
         heapify(mini);
      }
   }
   int extractmin() // Time Complexity is O(logn)   // Getmin is O(1)
   {
      if (v.size() == 0)
         return INT_MAX;
      int ans = v[0];
      swap(v[0], v[v.size() - 1]);
      v.pop_back();
      heapify(0);
      return ans;
   }
   void decreasekey(int i, int k) // Time Complexity is O(logn)
   {
      v[i] = k;
      while (i > 0 && v[i] < v[(i - 1) / 2])
      {
         swap(v[i], v[(i - 1) / 2]);
         i = (i - 1) / 2;
      }
   }
   void deletekey(int ind) // Time Complexity is O(logn)
   {
      decreasekey(ind, INT_MIN);
      extractmin();
   }
   // void heapifybt(int n, int a[], int i)
   // {
   //    while (i > 0 and a[i] < a[(i - 1) / 2])
   //    {
   //       swap(a[i], a[(i - 1) / 2]);
   //       i = (i - 1) / 2;
   //    }
   // }
   void buildheap(int n, int a[]) // Time Complexity is O(n) ---- Important
   {
      for (int i = (n - 2) / 2; i >= 0; i--)
         heapify(n, a, i);
      // for (int i = 0; i < n; i++)
      //    heapifybt(n, a, i);
   }

   /*
   Remember there are two types of heapify =
   Heapify Up == reapetedly compare with parent untill small is found. (used when key is decreased) (as upper portion of heap is distorted)
   Heapify Down == recursively compare with children , replace with smallest children (<node) , do same on children untill children (>node) (used when key is increased) (as lower portion of heap is distorted)

   To build heap we can use both methods --
   0 --> n (heapify up)               or               (n-1)/2 --> 0 (heapify down)
    */
};
int main()
{
   min_heap h;
   h.insert(10);
   h.insert(1);
   h.insert(5);
   h.insert(15);
   h.insert(11);
   h.insert(9);
   h.insert(3);
   h.insert(-1);
   h.print();
   h.extractmin();
   nl;
   cout << h.extractmin();
   nl;
   h.print();
   nl;
   h.decreasekey(5, 1);
   h.print();
   h.deletekey(3);
   h.print();
   h.v = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
   h.print();
   h.buildheap();
   h.print();
   return 0;
}