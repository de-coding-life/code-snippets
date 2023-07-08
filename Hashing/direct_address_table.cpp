#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    bool dat[1000] = {0};
    int ans;
    do
    {
        cout << "1.Search\n2.Insert\n3.Delete\n4.Any other to exit\n\n";
        cin >> ans;
        if (ans == 1)
        {
            int d;
            cout << "\nEnter key to Search\n";
            cin >> d;
            if (dat[d])
                cout << "\nYES , THE KEY " << d << " IS PRESENT\n";
            else
                cout << "\nNO , THE KEY " << d << " IS NOT PRESENT\n";
        }
        else if (ans == 2)
        {
            int d;
            cout << "\nEnter key to Insert\n";
            cin >> d;
            if (dat[d] == 1)
                cout << "\nTHE KEY " << d << " IS ALREADY PRESENT\n";
            else
            {
                dat[d] = 1;
                cout << "\nTHE KEY " << d << " IS INSERTED SUCESSFULLY\n";
            }
        }
        else if (ans == 3)
        {
            int d;
            cout << "\nEnter key to Delete\n";
            cin >> d;
            if (dat[d] == 0)
                cout << "\nTHE KEY " << d << " IS NOT PRESENT , SO IT CANNOT BE DELETED\n";
            else
            {
                dat[d] = 0;
                cout << "\nTHE KEY " << d << " IS DELETED SUCESSFULLY\n";
            }
        }
        else
            break;
    } while (ans == 1 or ans == 2 or ans == 3);
}