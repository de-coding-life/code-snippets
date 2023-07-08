// all numbers 2 times one number unique

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[12]={4,5,6,7,11,3,2,11,4,6,5,7};
    int ans=0;
    for (int i=0;i<12;i++)
    {
        ans=(ans ^ a[i]);
    }
    int temp=ans;
    int dig=-1;
    for(int i=0;i<INT_MAX;i++)
    {
        if (ans & 1<<i)
        {
            dig=i;
            break;
        }
    }
    ans=0;
    for (int i=0;i<12;i++)
    {
        if (1<<dig & a[i])
        ans=(ans ^ a[i]);
    }
    cout<<ans<<"  ";
    cout<<(ans ^ temp);
    return 0;
}