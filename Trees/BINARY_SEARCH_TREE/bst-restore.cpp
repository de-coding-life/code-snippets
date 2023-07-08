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
void inorder(node *temp, vector<int> &ans)
{
    if (temp == NULL)
        return;
    inorder(temp->l, ans);
    ans.push_back(temp->data);
    inorder(temp->r, ans);
}
void bstrestore(vector<int> &res)
{
    int a = -1;
    int b = -1;
    for (int i = 0; i < res.size() - 1; i++)
    {
        if (res[i] > res[i + 1])
        {
            if (a == -1)
            {
                a = i;
                b = i + 1;
            }
            else
                b = i + 1;
        }
    }
    cout << "\nElements which are swapped are " << res[a] << " & " << res[b] << endl;
}
int main()
{
    node *head = new node(10);
    head->l = new node(21);
    head->r = new node(20);
    head->l->r = new node(7);
    head->r->r = new node(5);
    head->l->r->l = new node(6);
    head->l->r->r = new node(8);

    vector<int> in;
    inorder(head, in);
    bstrestore(in);
    return 0;
}