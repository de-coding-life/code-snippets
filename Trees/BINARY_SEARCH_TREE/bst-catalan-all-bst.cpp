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
int catalan(int n)
{
    if (n <= 1)
        return 1;
    ll ans = 0;
    for (int ii = 0; ii <= n - 1; ii++)
        ans += catalan(ii) * catalan(n - ii - 1);
    return ans;
}
vector<node *> allbst(int s, int e)
{
    vector<node *> trees;
    if (s > e)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = s; i <= e; i++)
    {
        vector<node *> lt = allbst(s, i - 1);
        vector<node *> rt = allbst(i + 1, e);
        for (int j = 0; j < lt.size(); j++)
        {
            for (int k = 0; k < rt.size(); k++)
            {
                node *nn = new node(i);
                nn->l = lt[j];
                nn->r = rt[k];
                trees.push_back(nn);
            }
        }
    }
    return trees;
}
int main()
{
    for (int i = 0; i < 10; i++)
        cout << catalan(i) << " ";
    cout << endl;
    vector<node *> v = allbst(1, 4);
    for (int i = 0; i < v.size(); i++)
    {
        cout << "\nTree No." << i + 1 << endl;
        preorder(v[i]);
        cout << endl;
        inorder(v[i]);
        cout << endl;
        cout << endl;
    }
    return 0;
}