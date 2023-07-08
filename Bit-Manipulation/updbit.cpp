#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,pos,v;
    cin>>n>>pos>>v;
    cout<<((n & ~(1<<pos)) | (v<<pos));
    return 0;
}