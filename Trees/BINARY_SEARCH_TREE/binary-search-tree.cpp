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
class bst
{
public:
    node *root = NULL;
    node *insert(int d, node *&temp)
    {
        if (temp == NULL)
        {
            temp = new node(d);
            return temp;
        }
        else if (d < temp->data)
        {
            temp->l = insert(d, temp->l);
        }
        else if (d > temp->data)
        {
            temp->r = insert(d, temp->r);
        }
        else
        {
            cout << "\nElement Already Present\n";
        }
        return temp;
    }
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
    node *search(int d, node *temp)
    {
        if (temp == NULL)
            return NULL;
        if (d < temp->data)
            return search(d, temp->l);
        else if (d > temp->data)
            return search(d, temp->r);
        else
            return temp;
    }
    node *dell(int d, node *temp)
    {
        if (temp == NULL)
            return NULL;
        else if (temp->data > d)
        {
            temp->l = dell(d, temp->l);
            return temp;
        }
        else if (temp->data < d)
        {
            temp->r = dell(d, temp->r);
            return temp;
        }
        else
        {
            if (temp->l == NULL and temp->r == NULL)
            {
                delete temp;
                return NULL;
            }
            else if (temp->l == NULL)
            {
                node *tt = temp->r;
                delete temp;
                return tt;
            }
            else if (temp->r == NULL)
            {
                node *tt = temp->l;
                delete temp;
                return tt;
            }
            else
            {
                node *rr = temp->r;

                while (rr->l != NULL)
                    rr = rr->l;

                int td = temp->data;
                temp->data = rr->data;
                rr->data = td;
                temp->r = dell(d, temp->r);
                return temp;
            }
        }
    }
    node *buildfrompreorder(int a[], int mn, int mx, int &i, int n)
    {
        if (i > n - 1)
            return NULL;
        if (mn < a[i] && mx > a[i])
        {
            node *temp = new node(a[i]);
            i++;
            temp->l = buildfrompreorder(a, mn, temp->data, i, n);
            temp->r = buildfrompreorder(a, temp->data, mx, i, n);
            return temp;
        }
        else
            return NULL;
    }
    bool checkbst(node *temp, int mn = INT_MIN, int mx = INT_MAX)
    {
        if (temp == NULL)
            return 1;
        else if (mn < temp->data && mx > temp->data)
            return checkbst(temp->l, mn, temp->data) and checkbst(temp->r, temp->data, mx);
        else
            return 0;
    }
    node *balbstfrminorder(int arr[], int s, int e)
    {
        if (e - s < 0)
            return NULL;
        node *temp = new node(arr[(s + e) / 2]);
        temp->l = balbstfrminorder(arr, s, ((s + e) / 2) - 1);
        temp->r = balbstfrminorder(arr, ((s + e) / 2) + 1, e);
        return temp;
    }
};
int main()
{
    bst *a = new bst();
    a->insert(5, a->root);
    a->insert(1, a->root);
    a->insert(3, a->root);
    a->insert(4, a->root);
    a->insert(2, a->root);
    a->insert(7, a->root);
    cout << endl;
    a->inorder(a->root);
    node *temp = a->search(4, a->root);
    cout << endl
         << temp->data;
    a->dell(7, a->root);
    cout << endl;
    a->inorder(a->root);

    int ii = 0;
    cout << endl;
    bst *b = new bst();
    int pr[] = {7, 5, 4, 6, 8, 9};
    b->root = b->buildfrompreorder(pr, INT_MIN, INT_MAX, ii, 6);
    b->inorder(b->root);
    cout << endl;

    // b->root->l->data = 3;
    cout << b->checkbst(b->root);

    bst *c = new bst();
    int in[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    c->root = c->balbstfrminorder(in, 0, 9);
    cout << endl;
    c->preorder(c->root);

    return 0;
}