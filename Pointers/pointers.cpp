#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a=1;
   int* p1=&a;
   int* p1p=p1;
   int** p2=&p1;
   int array[]={1,3,3};
   cout<<&p1<<" "<<p1<<" "<<*p1<<endl;
   cout<<&p1p<<" "<<p1p<<" "<<*p1p<<endl;
   cout<<&p2<<" "<<p2<<" "<<*p2<<" "<<**p2<<endl;
   //
   cout<<&p1<<" "<<p1<<" "<<(*p1)<<endl;
   cout<<&p1p<<" "<<p1p<<" "<<*p1p<<endl;
   cout<<&p2<<" "<<p2--<<" "<<*p2<<" "<<**p2<<endl;
   cout<<array<<endl;
   cout<<*array<<endl;
   cout<<*(array+1)<<endl;
   cout<<*array<<endl;
   //0-->&
   //1-->
   //2-->*
   //3-->**
   return 0;
}