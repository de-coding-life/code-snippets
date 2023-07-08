#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
#define nl cout << endl
void heapify(int n, int a[], int i)
{
   int mini = i;
   if (n > (2 * i) + 1 && a[i] > a[(2 * i) + 1])
      mini = (2 * i) + 1;
   if (n > (2 * i) + 2 && a[mini] > a[(2 * i) + 2])
      mini = (2 * i) + 2;
   if (i != mini)
   {
      swap(a[i], a[mini]);
      heapify(n, a, mini);
   }
}
void buildheap(int n, int a[])
{
   for (int i = (n - 2) / 2; i >= 0; i--)
      heapify(n, a, i);
}
int heapsort(int n, int a[]) // O(nlogn)
{
   buildheap(n, a);                // O(n)
   for (int i = 0; i < n - 1; i++) // O(nlogn)
   {
      swap(a[0], a[n - 1 - i]);
      heapify(n - 1 - i, a, 0); // O(logn)
   }
   for (int i = 0; i < n / 2; i++)
      swap(a[i], a[n - 1 - i]);
}
int main()
{
   int arr[] = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
   heapsort(10, arr);
   for (int i = 0; i < 10; i++)
      cout << arr[i] << " ";
   return 0;
}
