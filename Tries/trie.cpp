#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Trie
{

public:
    Trie *a[26];
    int isp;
    int tot;
    Trie()
    {
        for (int i = 0; i < 26; i++)
            a[i] = NULL;
        isp = 0;
        tot = 0;
    }

    void insert(string &w)
    {
        Trie *t = this;
        for (int i = 0; i < w.size(); i++)
        {
            t->tot++;
            if (t->a[w[i] - 'a'] == NULL)
                t->a[w[i] - 'a'] = new Trie();
            t = t->a[w[i] - 'a'];
        }
        t->isp++;
        t->tot++;
    }

    int countWordsEqualTo(string &w)
    {
        Trie *t = this;
        for (int i = 0; i < w.size(); i++)
        {
            if (t->a[w[i] - 'a'] == NULL)
                return 0;
            t = t->a[w[i] - 'a'];
        }
        return t->isp;
    }

    int countWordsStartingWith(string &w)
    {
        Trie *t = this;
        for (int i = 0; i < w.size(); i++)
        {
            if (t->a[w[i] - 'a'] == NULL)
                return 0;
            t = t->a[w[i] - 'a'];
        }
        return t->tot;
    }

    void erase(string &w)
    {
        Trie *t = this;
        vector<Trie *> waste;
        for (int i = 0; i < w.size(); i++)
        {
            t->tot--;
            if (t->a[w[i] - 'a']->tot == 1)
            {
                Trie *temp = t->a[w[i] - 'a'];
                t->a[w[i] - 'a'] = NULL;
                t = temp;
                waste.push_back(t);
            }
            else
                t = t->a[w[i] - 'a'];
        }
        t->tot--;
        t->isp--;
        for (auto i : waste)
        {
            delete i;
        }
    }
};
int main()
{
    Trie t1;
    vector<char> v;
    string s1 = "tamma";
    t1.insert(s1);

    s1 = "tamma";
    cout << t1.countWordsEqualTo(s1);

    s1 = "tammarind";
    t1.insert(s1);

    s1 = "tind";
    t1.insert(s1);

    s1 = "tinder";
    t1.insert(s1);

    s1 = "tind";
    cout << t1.countWordsEqualTo(s1);

    s1 = "tinder";
    t1.erase(s1);

    s1 = "tind";
    cout << t1.countWordsEqualTo(s1);

    s1 = "tinder";
    cout << t1.countWordsEqualTo(s1);

    s1 = "tamma";
    cout << t1.countWordsStartingWith(s1);

    return 0;
}