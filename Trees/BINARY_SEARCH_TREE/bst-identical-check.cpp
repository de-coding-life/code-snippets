#include <bits/stdc++.h>
#define ll long long
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
bool bstcheck(node *a, node *b)
{
    if (a == NULL and b == NULL)
        return 1;
    else if (a == NULL or b == NULL or a->data != b->data)
        return 0;
    else
        return bstcheck(a->l, b->l) and bstcheck(a->r, b->r);
}
int main()
{
    node *head = new node(1);
    head->l = new node(2);
    head->r = new node(3);
    head->l->r = new node(4);
    head->r->r = new node(5);
    head->l->r->l = new node(6);
    head->l->r->r = new node(7);

    node *head2 = new node(1);
    head2->l = new node(2);
    head2->r = new node(3);
    head2->l->r = new node(4);
    head2->r->r = new node(5);
    head2->l->r->l = new node(6);
    head2->l->r->r = new node(7);

    cout << endl
         << bstcheck(head, head2);
    return 0;
}