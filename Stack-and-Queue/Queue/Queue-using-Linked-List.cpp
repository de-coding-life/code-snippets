#include <bits/stdc++.h>
using namespace std;
class node
{
public:
   int data;
   node *next;
   node(int d)
   {
      data = d;
      next = NULL;
   }
};
class que
{
private:
   node *e = NULL;
   node *d = NULL;

public:
   bool empty()
   {
      return (e == NULL);
   }
   void enqueue(int dat)
   {
      node *n = new node(dat);
      if (e == NULL)
      {
         e = n;
         d = n;
      }
      else
      {
         e->next = n;
         e = n;
      }
   }
   void dequeue()
   {
      if (!empty())
      {
         node *des;
         des = d;
         if (d == e)
            e = e->next;
         d = d->next;
         delete des;
      }
   }
   int peek()
   {
      if (!empty())
         return e->data;
   }
   int display() // Custom function not present in STL
   {
      cout << endl
           << "\n---Queue Back-------\n";
      for (node *i = d; i != NULL; i = i->next)
      {
         cout << endl
              << "| " << i->data << " |";
         if (i == e or i == d)
            cout << " <------ " << i;
         cout << endl
              << "-------------";
      }
      cout << endl
           << "\n---Queue Peek-------\n"
           << endl;
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
   cout << x.peek() << endl;
   x.dequeue();
   x.display();
   x.dequeue();
   cout << x.empty();
   x.enqueue(10);
   x.enqueue(15);
   x.display();
   return 0;
}