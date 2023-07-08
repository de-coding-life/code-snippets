#include<bits/stdc++.h>
using namespace std;
void inc(int* p)
{
   (*p)++;
}
int main()
{
   int a=1;
   inc(&a);
   cout<<a;
   return 0;
}