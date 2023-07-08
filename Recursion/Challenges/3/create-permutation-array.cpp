#include<bits/stdc++.h>
using namespace std;
void pr(vector<int> a,string ans="\n")
{  if (a.size()==0)
   cout<<ans;
   for (int i=0;i<a.size();i++)
   {
      string x=to_string(a[i]);
      a.erase(a.begin()+i);
      pr(a,ans+" "+x);
      a.insert((a.begin()+i),stoi(x));
   }
}
int main()
{
   int n,x;
   cin>>n;
   vector <int> arr;
   for (int i=0;i<n;i++)
   {   
      cin>>x;
      arr.push_back(x);
   }
   pr(arr);
   return 0;
}