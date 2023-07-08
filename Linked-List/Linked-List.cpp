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
void InsertAtTail(int d,node* &head)
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

void InsertAtHead(int d,node* &head)
{
   node* n= new node(d);
   n->next=head;
   head=n;
}

void print(node* temp)
{
   while (temp!=NULL)
   {  
      cout<<temp->data<<" -> ";
      temp=(temp->next);
   }
   cout<<"NULL"<<endl;
}

bool seek(int d,node* temp)
{
   while (temp!=NULL and temp->data!=d)
   temp=temp->next;
   if (temp==NULL)
   return 0;
   return 1;
}

void del(int value,node* &head)
{
   if (head==NULL)
   {return;}
   else
   {  node* temp=head;
      node* prev=NULL;
      while (temp!=NULL and temp->data!=value)
      {
         prev=temp;
         temp=temp->next;
      }
      if (prev==NULL)
      {
         head=temp->next;
         delete temp;
      }
      else if (temp!=NULL)
      {
         prev->next=temp->next;
         delete temp;
      }
      return;
   }
}

void delall(node* temp)
{
   while (temp!=NULL)
   {  
      node* prev=temp;
      temp=(temp->next);
      delete prev;
   }
}
void rev(node* &head)
{
   node* temp=head;
   node* prev=NULL;
   node* nxt;
   while (temp!=NULL)
   {
      nxt=temp->next;
      temp->next=prev;
      prev=temp;
      temp=nxt;
   }
   head=prev;
}
node* revrec(node* &head)
{
   if (head->next==NULL or head==NULL)
   return head;

   node* nh = revrec(head->next);
   head->next->next=head;
   head->next=NULL;
   return nh;
}
int len(node* temp)
{
   int i=0;
   while (temp!=NULL)
   {temp=temp->next;
   i++;}
   return i;
}
node* revk(int k , node* &head)
{
   node* curr=head;
   node* prev=NULL;
   node* nxt;
   int cnt=0;
   while (curr!=NULL and cnt<k)
   {
      nxt=curr->next;
      curr->next=prev;
      prev=curr;
      curr=nxt;
      cnt++;
   }

   if (k>=len(nxt))
   head->next=nxt;
   else if (curr!=NULL)
   {head->next = revk(k,nxt);}
   return prev;
}

// Floyd cycle detection Algorithm
bool detectcycle(node* temp)
{
   node* slow=temp;
   node* fast=temp;
   while (fast!=NULL and fast->next!=NULL)
   {
      fast=fast->next->next;
      slow=slow->next;
      if (fast==slow)
      return 1;
   }
   return 0;
}
// Floyd cycle removal Algorithm
void removecycle(node* temp)
{
   node* slow=temp;
   node* fast=temp;
   node* prev;
   while (fast!=NULL and fast->next!=NULL)
   {
      fast=fast->next->next;
      prev=slow;
      slow=slow->next;
      if (fast==slow)
      break;
   }
   if (slow==temp) //If cycle starts at head
   {
      prev->next=NULL;
      return;
   }
   else if (fast==slow) // if a cycle is found then only
   {
      fast=temp;
   }
   else // if no cycle found
   return;
   while (fast->next!=slow->next)  // if condition not satisfies , we will reach edge of loop
   {
      fast=fast->next;
      slow=slow->next;
   }
   slow->next=NULL;
}

void lastk(int k, node* &head ) //bring last k to front
{
   int l=len(head);
   if (l<=k)
   rev(head);
   else
   {
      node* temp=head;
      int cnt=1;
      node* prev;
      while (cnt!=l-k+1)
      {
         prev=temp;
         temp=temp->next;
         cnt++;
      }
      swap(head,temp);
      prev->next=NULL;

      node* headit=head;
      while(headit->next!=NULL)
      headit=headit->next;
      headit->next=temp;

   }
}
bool findintersection(node* head1 , node* head2)
{
   if (head2<head1)
   swap(head1,head2);
   int l=len(head2)-len(head1);
   for(int i=0;i<l;i++)
   head2=head2->next;
   while (head2->next!=NULL) // or head1->next!=NULL
   {
      if (head2->next==head1->next)
      {
         head2->next=NULL;
         return 1;
      }
      head1=head1->next;
      head2=head2->next;
   }
   return 0;
}
node* mergetwosorted(node* head1,node* head2)
{
   if (head1->data<head2->data)
   swap(head1,head2);
   node* head=head2;
   node* lst=head2;
   head2=head2->next;
   while (true)
   {  
      if (head1==NULL)
      {
         lst->next=head2;
         break;
      }
      else if (head2==NULL)
      {
         lst->next=head1;
         break;
      }
      else if ((head1->data)<(head2->data))
      {
         lst->next=head1;
         lst=lst->next;
         head1=head1->next;
      }
      else
      {
         lst->next=head2;
         lst=lst->next;
         head2=head2->next;
      }
   }
   return head;
}
void evenafterodd(node* head)
{
   node* temp=head;
   node* nxt=temp->next;
   node* even=nxt;
   while (temp->next!=NULL)
   {
         temp->next=temp->next->next;
         temp=nxt;
         nxt=nxt->next;
   }
   temp=head;
   while (temp->next!=NULL)
   temp=temp->next;
   temp->next=even;
}
int main()
{
   node* head=NULL;
   InsertAtTail(4,head);
   InsertAtTail(411,head);
   InsertAtTail(33,head);
   InsertAtHead(55,head);
   InsertAtHead(72,head);
   InsertAtHead(432,head);
   print(head);
   evenafterodd(head);
   print(head);

   rev(head);
   print(head);

   head = revrec(head);
   print(head);

   // revk(1,head);
   // print(head);
   head = revk(4,head);
   print(head);

   lastk(5,head);
   print(head);

   node* head2=NULL;
   InsertAtTail(1,head2);
   InsertAtTail(3,head2);
   InsertAtTail(5,head2);
   InsertAtTail(6,head2);
   head2->next->next->next->next=head->next->next; // Creating a Intersection
   print(head);
   print(head2);
   cout<<findintersection(head,head2)<<endl;
   print(head);
   print(head2);

   node* head3=NULL;
   InsertAtTail(3,head3);
   InsertAtTail(4,head3);
   InsertAtTail(10,head3);
   print(mergetwosorted(head2,head3));

   // revk(3,head);
   // print(head);
   cout<<seek(33,head)<<seek(432,head)<<seek(43333,head)<<seek(432,head)<<endl;

   head->next->next->next->next->next->next=head->next; // Creating a cycle in existing Linked list
   cout<<detectcycle(head)<<endl;
   removecycle(head);
   print(head);

   del(432,head);
   print(head);

   del(33,head);
   print(head);

   del(56,head); //Del 56 wont generate error as we return if temp is null
   print(head);
   delall(head);
   return 0;
}