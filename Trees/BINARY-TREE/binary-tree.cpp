#include<bits/stdc++.h>
using namespace std;
class node
{
   public:
   int data;
   node* l;
   node* r;
   node(int d) {
      data=d;
      l=NULL;
      r=NULL;
   }
};
class bt
{
   public:
   node* root;
   bt (int d)
   {
      root=new node(d);
   }

   void add(int le=0,int rt=0,string lvl=" ",string ck="lr")
   {
   node* temp=root;
   for (int i=0;i<lvl.size();i++)
   {
      if (lvl[i]=='l')
      temp=temp->l;
      else if (lvl[i]=='r')
      temp=temp->r;
   }
   if (ck=="l")
   temp->l=new node(le);
   else if (ck=="r")
   temp->r=new node(rt);
   else
   {temp->l=new node(le);
   temp->r=new node(rt);}
   }

   void inorder(node* cur,vector<int> &vec){
      if (cur==NULL)
      return;
      inorder(cur->l,vec);
      vec.push_back(cur->data);
      inorder(cur->r,vec);
   }

   void preorder(node* cur,vector<int> &vec){
      if (cur==NULL)
      return;
      vec.push_back(cur->data);
      preorder(cur->l,vec);
      preorder(cur->r,vec);
   }

   void postorder(node* cur,vector<int> &vec){
      if (cur==NULL)
      return;
      postorder(cur->l,vec);
      postorder(cur->r,vec);
      vec.push_back(cur->data);
   }

   node* buildpi(vector<int> &p,vector<int> &in, int s=0,int e=0, int *ptr = new int(0)){

      if (*ptr==0)
      e=p.size()-1;

      if ((*ptr)>=p.size() or s>e)
      return NULL;
      int div=-1;

      for (int i=s;i<=e;i++)
      {
         if (in[i]==p[*ptr])
         div=i;
      }

      node* curr = new node(p[*ptr]);
      (*ptr)++;

      curr->l = buildpi(p, in ,s,div-1,ptr);
      curr->r = buildpi(p,in,div+1,e,ptr);
      return curr;
   } 


   node* buildposti(vector<int> &p,vector<int> &in, int s=0,int e=0, int *ptr = new int(0)){

      if (*ptr==0)
      e=p.size()-1;

      if ((*ptr)>=p.size() or s>e)
      return NULL;
      int div=-1;

      for (int i=s;i<=e;i++)
      {
         if (in[i]==p[p.size()-(*ptr)-1])
         div=i;
      }

      node* curr = new node(p[p.size()-(*ptr)-1]);
      (*ptr)++;

      curr->r = buildposti(p,in,div+1,e,ptr);
      curr->l = buildposti(p, in ,s,div-1,ptr);

      
      return curr;
   }
   void lvltrvl()
   {
      if (root==NULL)
      return;
      cout<<endl;
      queue<node*> q;
      q.push(root);
      q.push(NULL);
      node* temp=root;
      int lvl=1;
      cout<<"Level "<<lvl<<" --> ";
      while (q.size()!=1)
      {
         if (q.front()!=NULL)
         {cout<<q.front()->data<<" ";
         if (q.front()->l!=NULL)
         q.push(q.front()->l);
         if (q.front()->r!=NULL)
         q.push(q.front()->r);
         q.pop();}
         else
         {
            cout<<endl;
            cout<<"Level "<<++lvl<<" --> ";
            q.pop();
            q.push(NULL);
         }
      }
      cout<<endl;
   }

   void lvlsum()
   {
      if (root==NULL)
      return;
      cout<<endl;
      queue<node*> q;
      q.push(root);
      q.push(NULL);
      node* temp=root;
      int lvl=1;
      int sm=0;
      while (q.size()!=1)
      {
         if (q.front()!=NULL)
         {sm+=q.front()->data;
         if (q.front()->l!=NULL)
         q.push(q.front()->l);
         if (q.front()->r!=NULL)
         q.push(q.front()->r);
         q.pop();}
         else
         {
            cout<<"Sum of Level "<<lvl++<<" --> "<<sm;
            cout<<endl;
            sm=0;
            q.pop();
            q.push(NULL);
         }
      }
      cout<<"Sum of Level "<<lvl++<<" --> "<<sm<<endl;
   }
   int cnnode(node* curr)
   {
      if (curr==NULL)
      return 0;
      return cnnode(curr->l) + cnnode(curr->r) + 1 ;
   }
   int sumnode(node* curr)
   {
      if (curr==NULL)
      return 0;
      return sumnode(curr->l) + sumnode(curr->r) + curr->data ;
   }
   int height(node* curr)
   {
      if (curr==NULL)
      return 0;
      return max(height(curr->l),height(curr->r)) + 1 ;
   }
   int diameter(node* curr,int* ans=new int(0) )
   {
      if (curr==NULL)
      return 0;

      int hl=diameter(curr->l,ans);
      int hr=diameter(curr->r,ans);

      *ans=max(*ans,hl+hr+1);
      if (curr==root) // in first case return ans
      return *ans;
      return  max(hl,hr)+1; // In all cases return height
   }

   int sumreplacement(node* temp)
   {  if (temp==NULL)
      return 0;
      temp->data+=(sumreplacement(temp->l)+sumreplacement(temp->r));
      return temp->data;
   }
   int isBalanced(node* curr, bool* ans=new bool(true))
   {
      if (curr==NULL)
      return 0;
      int hl=isBalanced(curr->l,ans);
      int hr=isBalanced(curr->r,ans);
      if (abs(hl-hr)>1)
      *ans=false;
      if (curr==root)
      return *ans;
      return max(hl,hr)+1;
   }
   void rightview()
   {
      cout<<endl;
      if (root==NULL)
      return;
      queue<node*> q;
      q.push(root);
      q.push(NULL);
      int ans;
      while (q.size()!=1)
      {
         if (q.front()!=NULL)
         {
            ans=q.front()->data;
            if (q.front()->l!=NULL)
            q.push(q.front()->l);
            if (q.front()->r!=NULL)
            q.push(q.front()->r);
            q.pop();
         }
         else{
            cout<<ans<<" ";
            q.pop();
            q.push(NULL);
         }
      }
      cout<<ans<<endl;
   }
   void leftview()
   {
      cout<<endl;
      if (root==NULL)
      return;
      queue<node*> q;
      q.push(root);
      q.push(NULL);
      int ans;
      while (q.size()!=1)
      {
         if (q.front()!=NULL)
         {
            ans=q.front()->data;
            if (q.front()->r!=NULL)
            q.push(q.front()->r);
            if (q.front()->l!=NULL)
            q.push(q.front()->l);
            q.pop();
         }
         else{
            cout<<ans<<" ";
            q.pop();
            q.push(NULL);
         }
      }
      cout<<ans<<endl;
   }
   node* lca(node* curr,int d1,int d2)
   {
      if (curr==NULL)
      return NULL;
      else if (curr->data==d1 or curr->data==d2)
      return curr;

      node* llca=lca(curr->l,d1,d2);
      node* rlca=lca(curr->r,d1,d2);

      if (llca && rlca)
      return curr;
      else if (llca!=NULL)
      return llca;
      else
      return rlca;
   }
   string path(node* curr,int d)
   {  
      if (curr==NULL)
      return "" ;
      if (curr->data==d)
      return " ";
      if (path(curr->r,d).size()>0)
      return 'r' + path(curr->r,d);
      else if (path(curr->l,d).size()>0)
      return 'l' + path(curr->l,d);
      else
      return "";
   }
   int shortdis(int d1,int d2)
   {
      string s1=path(root,d1);
      string s2=path(root,d2);
      int ans=s1.size()+s2.size()-2;
      for (int i=0;i<min(s1.size(),s2.size())-1;i++)
      {
         if (s1[i]!=s2[i])
         break;
         ans-=2;
      }
      return ans;
   }
   void flatten(node* curr,node* &prev)
   {
      if (curr==NULL)
      return ;

      node* a=curr->l;
      node* b=curr->r;
      curr->l=NULL;

      if (prev!=NULL)
      prev->r=curr;
      prev=curr;

      flatten(a,prev);
      flatten(b,prev);
   }
   void hlpr(node* root, vector<int> &v,int knew, string marg)
   {
      if (root==NULL)
      return;
      else if (knew==0)
      v.push_back(root->data);
      if (marg=="" or marg ==" "){
         hlpr(root->l,v,knew-1,marg);
         hlpr(root->r,v,knew-1,marg);
      }
      else if (marg[0]=='l')
     {hlpr(root->l,v,knew+1,marg.substr(1));
      hlpr(root->r,v,knew-1,"");}
      else if (marg[0]=='r')
      {hlpr(root->r,v,knew+1,marg.substr(1));
      hlpr(root->l,v,knew-1,"");}
   }
   void nodesatk(node* root , node* tgt , int k)
   {
      string marg=path(root,tgt->data);
      int knew=k-(marg.size()-1);
      vector<int> vctr;
      hlpr(root,vctr,knew,marg);
      cout<<endl;
      for (int i=0;i<vctr.size();i++)
      {
         cout<<vctr[i]<<" ";
      }
      cout<<endl;
   }
   int maxpathsum(node* root,int &maxpath)
   {
      if (root==NULL)
      return INT_MIN;
      int a=maxpathsum(root->l,maxpath);
      int b=maxpathsum(root->r,maxpath);
      
      maxpath=max(maxpath,root->data + max(max(a,b),0));
      maxpath=max(maxpath,root->data + a + b);
      return root->data + max(max(a,b),0);
   }
};
int main()
{
   bt a(1);
   a.add(2,3);
   a.add(4,5,"l");
   a.add(6,7,"r");

   vector<int> pre;
   a.preorder(a.root,pre);
   for (auto i : pre)
   cout<<i<<" ";
   cout<<endl;

   vector<int> post;
   a.postorder(a.root,post);
   for (auto i : post)
   cout<<i<<" ";
   cout<<endl;

   vector<int> in;
   a.inorder(a.root,in);
   for (auto i : in)
   cout<<i<<" ";
   cout<<endl;
   
   //       1
   //     /   \
   //    2     3
   //   / \   / \
   //  4   5 6   7

   a.nodesatk(a.root,a.root->l->r,3);

   int ans;
   a.maxpathsum(a.root,ans);
   cout<<endl<<ans<<endl;

   node* c = NULL;
   a.flatten(a.root,c);
   c=a.root;
   while (c!=NULL)
   {cout<<c->data<<" -> ";
   c=c->r;}
   cout<<endl;
   
   bt nw(2);
   nw.root=nw.buildpi(pre,in);

   cout<<endl;
   vector<int> post2;
   nw.postorder(nw.root,post2);
   for (auto ii : post2)
   cout<<ii<<" ";
   cout<<endl;

   bt nx(3);
   nx.root=nx.buildposti(post,in);

   cout<<endl;
   vector<int> pre2;
   nx.preorder(nx.root,pre2);
   for (auto ii : pre2)
   cout<<ii<<" ";
   cout<<endl;

   nx.lvltrvl();
   nx.lvlsum();
   cout<<endl<<nx.cnnode(nx.root)<<endl;
   cout<<endl<<nx.sumnode(nx.root)<<endl;
   cout<<endl<<nx.height(nx.root)<<endl;
   cout<<endl<<nx.diameter(nx.root)<<endl;
   nx.sumreplacement(nx.root);
   nx.lvltrvl();
   cout<<endl<<nx.isBalanced(nx.root)<<endl;
   nx.add(8,0,"ll","l");
   cout<<endl<<nx.isBalanced(nx.root)<<endl;
   nx.add(9,0,"lll","l");
   cout<<endl<<nx.isBalanced(nx.root)<<endl;
   nx.lvltrvl();
   nx.rightview();
   nx.leftview();
   cout<<endl<<nx.lca(nx.root,28,16)->data<<endl;
   cout<<endl<<nx.shortdis(28,16)<<endl;
   
   return 0;
}