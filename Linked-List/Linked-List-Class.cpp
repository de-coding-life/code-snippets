#include<bits/stdc++.h>
using namespace std;
class node
{
   public:
   int data;
   node* next;
   node (int d)
   {
      data=d;
      next=NULL;
   }
};
class linkedlist
{
   public:
   node* head=NULL;
   void InsertAtTail(int d)
   {
      node* n= new node(d);
      if (head==NULL)
      {head=n;
      return;}
      node* temp=head;
      while ((temp->next)!=NULL)
      temp=(temp->next);
      (temp->next)=n;

   }
   void InsertAtHead(int d)
   {
      node* n= new node(d);
      n->next=head;
      head=n;
   }
   void print()
   {
      node* temp=head;
      while (temp!=NULL)
      {  
         cout<<temp->data<<" -> ";
         temp=(temp->next);
      }
      cout<<"NULL";
   }
   bool seek(int d)
   {
      node* temp=head;
      while (temp!=NULL and temp->data!=d)
      temp=temp->next;
      if (temp==NULL)
      return 0;
      return 1;
   }
   void del()
   {
      node* temp=head;
      while (temp!=NULL)
      {  
         node* prev=temp;
         temp=(temp->next);
         delete prev;
      }
   }
};
int main()
{
   linkedlist ll;
   ll.InsertAtTail(4);
   ll.InsertAtTail(411);
   ll.InsertAtTail(33);
   ll.InsertAtHead(432);
   ll.print();
   cout<<endl<<ll.seek(33)<<ll.seek(432)<<ll.seek(43333)<<ll.seek(432);
   ll.del();
   return 0;
}