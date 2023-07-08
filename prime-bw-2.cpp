#include<iostream>
#include<cmath>
using namespace std;
void prime(int a ,int b)
{
   for (int i=a;i<=b;i++)
   {
      for (int j=2;j<=sqrt(i)+1;j++)
      {  
         if (i%j==0)
         {
            break;
         }
         if (j>=sqrt(i))
         {
            cout<<"The Number "<<i<<" is Prime"<<endl;
         }
      }
   }
   return;
}
int main()
{
   int x,y;
   cin>>x>>y;
   prime(x,y);
   return 0;
}