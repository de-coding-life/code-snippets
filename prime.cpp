#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   for (int i=2;i<=100;i++)
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
   return 0;
}