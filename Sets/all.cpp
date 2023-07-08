#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
int main()
{

   set<int> st; // default order is ascending , use greater<int> for descending , Implemented through BST

   // Only unique , otherwise same as multiset
   st.insert(1);
   st.insert(2);
   st.insert(3);
   pair<set<int>::iterator, bool> pr = st.insert(3);
   if (pr.second)
      cout << "The Element was added\n";
   else
      cout << "The element was not added\n";

   // Same as Set but it can store duplicates , implemented through BST
   multiset<int> ml;

   // Same as Set , but not ordered, hence (insertion,find,deletion) O(n) //Average 1 // Uses hashing
   unordered_set<int> ust;

   // Same as Multiset , but not ordered, hence (insertion,find,deletion) O(n)  // Average 1  // Uses hashing
   unordered_multiset<int> uml;

   return 0;
}