#include<bits/stdc++.h>
using namespace std;
class node
{
   public:
   int data;
   node* prev=NULL;
   node* next=NULL;
   node (int d)
   {data=d;}
};
void insertattail(int d,node* &head)
{
   if (head==NULL)
   head=new node(d);
   else
   {
      node* temp=head;
      while (temp->next!=NULL)
      temp=temp->next;
      temp->next=new node(d);
      temp->next->prev=temp;
   }
}
void insertathead(int d,node* &head)
{
   if (head==NULL)
   head=new node(d);
   else
   {
   node* n=new node(d);
   head->prev=n;
   n->next=head;
   head=n;
   }
}
node* print(node* temp)
{
   while (temp->next!=NULL)
   {
      cout<<temp->data<<" <--> ";
      temp=temp->next;
   }
   cout<<temp->data<<endl;
   return temp;
}
node* printrev(node* temp)
{
   while (temp->prev!=NULL)
   {
      cout<<temp->data<<" <--> ";
      temp=temp->prev;
   }
   cout<<temp->data<<endl;
   return temp;
}
void del(int d,node* &head)
{
   node* temp=head;
   while (temp->data!=d and temp->next!=NULL)
   temp=temp->next;
   if (temp->data!=d)
   return;

   if (temp->next==temp->prev) //only 1 element in dll and that too deleted
   head=NULL;
   else if (temp->next==NULL) // last element deleted
   temp->prev->next=NULL;
   else if (temp->prev==NULL) //head deleted , but size of dll > 1
   {
      temp->next->prev=NULL;
      head=temp->next;
   }
   else // not a corner case
   {
      temp->prev->next=temp->next;
      temp->next->prev=temp->prev;
   }
   delete temp;
}
int main()
{
   node* head=NULL;
   insertathead(1,head);
   // del(1,head);
   insertattail(12,head);
   del(1,head);
   insertathead(50,head);
   insertattail(90,head);
   insertattail(54,head);
   del(90,head);
   del(89,head);
   insertattail(95,head);
   del(95,head);
   node* tail=print(head);
   printrev(tail);
   return 0;
}