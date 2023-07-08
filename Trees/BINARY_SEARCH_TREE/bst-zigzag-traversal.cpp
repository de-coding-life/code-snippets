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
void zigzagtrav(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    bool ck = 0;
    vector<int> v;
    while (q.size() != 1)
    {
        if (q.front() == NULL)
        {
            ck = !ck;
            if (ck)
            {
                for (int i = 0; i < v.size(); i++)
                    cout << v[i] << " ";
            }
            else
            {
                for (int i = v.size() - 1; i >= 0; i--)
                    cout << v[i] << " ";
            }
            v.clear();
            q.pop();
            q.push(NULL);
        }
        else
        {
            if (q.front()->l != NULL)
                q.push(q.front()->l);
            if (q.front()->r != NULL)
                q.push(q.front()->r);
            v.push_back(q.front()->data);
            q.pop();
        }
    }
    ck = !ck;
    if (ck)
    {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
    }
    else
    {
        for (int i = v.size() - 1; i >= 0; i--)
            cout << v[i] << " ";
    }
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
    zigzagtrav(head);
    return 0;
}