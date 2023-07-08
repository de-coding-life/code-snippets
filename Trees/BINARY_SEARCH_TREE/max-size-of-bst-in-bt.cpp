#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *l;
    node *r;
    node(int d)
    {
        data = d;
        l = NULL;
        r = NULL;
    }
};
void inorder(node *temp)
{
    if (temp == NULL)
        return;
    inorder(temp->l);
    cout << " " << temp->data;
    inorder(temp->r);
}
void preorder(node *temp)
{
    if (temp == NULL)
        return;
    cout << " " << temp->data;
    preorder(temp->l);
    preorder(temp->r);
}
class info
{
public:
    int mn = INT_MAX, mx = INT_MIN, ans = 0;
    bool ck = 1;
};
info bstinbt(node *root)
{
    info aa;
    if (root == NULL)
        return aa;
    info ll = bstinbt(root->l);
    info rr = bstinbt(root->r);
    aa.mn = min(min(ll.mn, rr.mn), root->data);
    aa.mx = max(max(ll.mx, rr.mx), root->data);
    if (ll.ck == 0 or rr.ck == 0 or root->data <= ll.mx or root->data >= rr.mn)
    {
        aa.ck = 0;
        aa.ans = max(ll.ans, rr.ans);
    }
    else
        aa.ans = ll.ans + rr.ans + 1;
    return aa;
}
int main()
{
    node *head = new node(30);
    head->l = new node(30);
    head->r = new node(100);
    head->l->r = new node(25);
    head->r->r = new node(200);
    head->l->r->l = new node(21);
    head->l->r->r = new node(30);

    info fa = bstinbt(head);
    cout << endl
         << fa.ans << endl;
    return 0;
}