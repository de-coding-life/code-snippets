#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a=1;
   int* ptr=new int();
   *ptr=10;
   cout<<*ptr<<endl;
   cout<<ptr<<endl;
   delete(ptr);
   cout<<*ptr<<endl;
   cout<<ptr<<endl;
   ptr=new int[2];
   *(ptr)=10;
   *(ptr+1)=20;
   cout<<*ptr<<endl;
   cout<<ptr+1<<endl;
   cout<<ptr<<endl;
   cout<<&a<<endl;
   delete[]ptr;
   cout<<*(ptr+1)<<endl;
   cout<<*ptr<<endl;
   return 0;
}