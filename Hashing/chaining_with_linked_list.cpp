#include <bits/stdc++.h>
using namespace std;
#define ll long long
class hashtable
{
public:
    int siz = 100;
    forward_list<int> *ht;
    hashtable(int n)
    {
        siz = n;
        ht = new forward_list<int>[siz]; // ye constructor ke andar hi initialize hogi
    }
    void insert(int n)
    {
        int ind = n % siz;
        ht[ind].push_front(n);
    }
    bool search(int n)
    {
        int ind = n % siz;
        for (auto i : ht[ind])
        {
            cout << i;
            if (i == n)
                return 1;
        }
        return 0;
    }
    void del(int n)
    {
        int ind = n % siz;
        for (auto i : ht[ind])
        {
            if (i == n)
            {
                ht[ind].remove(i);
                break;
            }
        }
    }
};
int main()
{
    int ans;
    hashtable *hsh = new hashtable(10);
    do
    {
        cout << "1.Search\n2.Insert\n3.Delete\n4.Any other to exit\n\n";
        cin >> ans;
        if (ans == 1)
        {
            int d;
            cout << "\nEnter key to Search\n";
            cin >> d;
            if (hsh->search(d))
                cout << "\nYES , THE KEY " << d << " IS PRESENT\n";
            else
                cout << "\nNO , THE KEY " << d << " IS NOT PRESENT\n";
        }
        else if (ans == 2)
        {
            int d;
            cout << "\nEnter key to Insert\n";
            cin >> d;
            hsh->insert(d);
            cout << "\nTHE KEY " << d << " IS INSERTED SUCESSFULLY\n";
        }
        else if (ans == 3)
        {
            int d;
            cout << "\nEnter key to Delete\n";
            cin >> d;
            hsh->del(d);
            cout << "\nTHE KEY " << d << " IS DELETED SUCESSFULLY\n";
        }
        else
            break;
    } while (ans == 1 or ans == 2 or ans == 3);
}