#include<bits/stdc++.h>
using namespace std;
class node
{
   public:
   int data;
   node* next=NULL;
   node(int d)
   {
      data=d;
   }
};
void insert(int d,node* &head)
{
   if (head==NULL)
   {
      head=new node(d);
      head->next=head;
   }
   else
   {
      node* temp=head;
      while (temp->next!=head)
      temp=temp->next;
      temp->next=new node(d);
      temp->next->next=head;
   }
}
void print(node* head)
{  
   node* temp=head;
   while (temp->next!=head)
   {
      cout<<temp->data<<" --> ";
      temp=temp->next;
   }
   cout<<temp->data<<" --> HEAD"<<endl;
}
void del(int d, node* &head)
{  
   if (head==NULL)
   {return;}
   else if (head->data==d)
   {
      node* temp=head;
      head=head->next;
      if (head->next==head)
      head=NULL;
      delete temp;
   }
   else if (head->next==head)
   {return;}
   else
   {
      node* temp=head;
      node* prev=NULL;
      while (temp->next!=head)
      {
         prev=temp;
         temp=temp->next;
      }
      if (temp==head)
      {return;}
      prev->next=temp->next;
      delete temp;
   }
}
int main()
{
   node* head=NULL;

   insert(1,head);

   del(1,head);

   insert(2,head);
   insert(3,head);
   insert(4,head);

   del(3,head);

   del(4,head);

   print(head);

   return 0;
}