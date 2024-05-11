#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Trie
{
public:
    Trie *a[2];
    bool isp;
    Trie()
    {
        for (int i = 0; i < 2; i++)
            a[i] = NULL;
        isp = 0;
    }

    void insert(ll num)
    {
        Trie *t = this;
        int temp[60] = {0};
        for (int i = 0; i < 60; i++)
        {
            temp[i] = num % 2;
            num /= 2;
        }
        for (int i = 59; i >= 0; i--)
        {
            if (t->a[temp[i]] == NULL)
                t->a[temp[i]] = new Trie();
            t = t->a[temp[i]];
        }
        t->isp = 1;
    }

    ll minxor(ll num)
    {
        Trie *t = this;
        int temp[60] = {0};
        for (int i = 0; i < 60; i++)
        {
            temp[i] = num % 2;
            num /= 2;
        }
        ll ans = 0;
        ll curr = 1LL << 59;
        for (int i = 59; i >= 0; i--)
        {
            if (t->a[temp[i]] != NULL)
            {
                t = t->a[temp[i]];
            }
            else
            {
                ans += curr;
                t = t->a[1 - temp[i]];
            }
            curr /= 2;
        }
        return ans;
    }

    ll maxxor(ll num)
    {
        Trie *t = this;
        int temp[60] = {0};
        for (int i = 0; i < 60; i++)
        {
            temp[i] = num % 2;
            num /= 2;
        }
        ll ans = 0;
        ll curr = 1LL << 59;
        for (int i = 59; i >= 0; i--)
        {
            if (t->a[1 - temp[i]] != NULL)
            {
                ans += curr;
                t = t->a[1 - temp[i]];
            }
            else if (t->a[temp[i]] != NULL)
            {
                t = t->a[temp[i]];
            }
            curr /= 2;
        }
        return ans;
    }
};