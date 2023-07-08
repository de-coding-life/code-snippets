// all numbers 2 times one number unique

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[9]={1,2,3,4,5,1,2,3,4};
    int ans=0;
    for (int i=0;i<9;i++)
    {
        ans=(ans ^ a[i]);
    }
    cout<<ans;
    return 0;
}