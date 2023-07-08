#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int cn=0;
    while (n!=0)
    {
        n=(n & n-1);
        cn++;
    }
    cout<<cn;
    return 0;
}