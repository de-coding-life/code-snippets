#include<bits/stdc++.h>
using namespace std;
#define per 1000
class que
{
   private:
   int a[per];
   int e=-1,d=0;
   public:
   bool empty()
   {return (d>e);}
   void enqueue(int data)
   {
      a[++e]=data;
   }
   void dequeue()
   {
      if (!empty())
      d++;
   }
   int peek()
   {
      if (!empty())
      return a[e];
   }
   int display() // Custom function not present in STL
   {  
      cout<<endl<<"\n---Queue Display Starts-------\n";
      for (int i=e;i>=d;i--)
      {
         cout<<endl<<"| "<<a[i]<<" |";
         if (i==e or i==d)
         cout<<" <------ "<<i;
         cout<<endl<<"-------------";
      }
   cout<<endl<<"\n---Queue Display Ends-------\n"<<endl;
   }
};
int main()
{
   que x;
   x.enqueue(5);
   x.enqueue(10);
   x.enqueue(15);
   x.display();
   x.dequeue();
   cout<<x.peek()<<endl;
   x.dequeue();
   x.display();
   x.dequeue();
   cout<<x.empty();
   x.enqueue(10);
   x.enqueue(15);
   x.display();
   return 0;
}