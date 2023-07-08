#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,pos;
    cin>>n>>pos;
    if (n & 1<<pos)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}