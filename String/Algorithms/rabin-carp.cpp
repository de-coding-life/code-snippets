#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    string p;
    cin >> s >> p;
    int m = p.size(), n = s.size();
    if (m > n)
        return 0;
    int sh = 0;
    int ph = 0;
    int d;
    cin >> d; // This could be of your choice
    int cd = 1;
    for (int i = m - 1; i >= 0; i--)
    {
        ph = ph + (p[i] * cd);
        sh = sh + (s[i] * cd);
        cd *= d;
    }
    cd /= d;
    if (ph == sh && s.substr(0, m) == p)
    {
        cout << 0 << endl;
    }
    for (int i = m; i < n; i++)
    {
        sh = (sh - s[i - m] * cd) * d + s[i];
        if (ph == sh && s.substr(i - m + 1, m) == p)
        {
            cout << i - m + 1 << endl;
        }
    }
    return 0;
}