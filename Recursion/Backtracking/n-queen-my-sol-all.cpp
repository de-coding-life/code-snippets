#include<bits/stdc++.h>
using namespace std;
int plc(int n,int c1,int c2,int** cs)
{ 
   if (cs[c1][c2]!=0)
   return 0;
   int m=n-1;
   while (m>=0)                     // My solution is bit lengthy for small solution 80 lines
   {                                // Visit https://www.youtube.com/watch?v=1OkZKjxRokU&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=45
      if (cs[c1][m]<=0)
      cs[c1][m]-=1;
      if (cs[m][c2]<=0)
      cs[m][c2]-=1;
      m--;
   }
   m=0;
   while (c1-m>=0 and c2-m>=0)
   {
      if (cs[c1-m][c2-m]<=0)
      cs[c1-m][c2-m]-=1;
      m++;
   }
   m=0;
   while (c1-m>=0 and c2+m<n)
   {
      if (cs[c1-m][c2+m]<=0)
      cs[c1-m][c2+m]-=1;
      m++;
   }
   m=0;
   while (c1+m<n and c2+m<n)
   {
      if (cs[c1+m][c2+m]<=0)
      cs[c1+m][c2+m]-=1;
      m++;
   }
   m=0;
   while (c1+m<n and c2-m>=0)
   {
      if (cs[c1+m][c2-m]<=0)
      cs[c1+m][c2-m]-=1;
      m++;
   }
   cs[c1][c2]=c1+1;
   return 1;
}
void unplc(int n,int c1,int c2,int** cs)
{
   int m=n-1;
   while (m>=0)
   {
      if (cs[c1][m]<0)
      cs[c1][m]+=1;
      if (cs[m][c2]<0)
      cs[m][c2]+=1;
      m--;
   }
   m=0;
   while (c1-m>=0 and c2-m>=0)
   {
      if (cs[c1-m][c2-m]<0)
      cs[c1-m][c2-m]+=1;
      m++;
   }
   m=0;
   while (c1-m>=0 and c2+m<n)
   {
      if (cs[c1-m][c2+m]<0)
      cs[c1-m][c2+m]+=1;
      m++;
   }
   m=0;
   while (c1+m<n and c2+m<n)
   {
      if (cs[c1+m][c2+m]<0)
      cs[c1+m][c2+m]+=1;
      m++;
   }
   m=0;
   while (c1+m<n and c2-m>=0)
   {
      if (cs[c1+m][c2-m]<0)
      cs[c1+m][c2-m]+=1;
      m++;
   }
   cs[c1][c2]=0;
}
void print(int n, int** p)
{
   cout<<endl;
   for (int i=0;i<n;i++)
   {
      for (int j=0;j<n;j++)
      {
         if (p[i][j]<=0)
            cout<<0<<" ";
         else
         {
            cout<<1<<" ";
         }
      }
      cout<<endl;
   }
}
int chss(int n,int** chs,int c1,int c2,int x=0)
{  if (c1>n-1 or c2>n-1)
   return 0;
   for (int i=0;i<n;i++)
   {
      if (plc(n,c1,i,chs))
      {
         x++;
         if (x==n)
         print(n,chs);
         chss(n,chs,c1+1,0,x);
         unplc(n,c1,i,chs);
         x--;
      }
   }return 0;
}

int main()
{
   int n,x;
   cin>>n;
   x=0;
   int** p=new int * [n];
   for (int i=0;i<n;i++)
   {
   p[i]=new int[n];
   for (int j=0;j<n;j++)
   p[i][j]=0;
   }
   chss(n,p,0,0);
   //print(n,p);
   return 0;
}