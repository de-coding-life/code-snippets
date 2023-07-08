// all numbers 2 times one number unique

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[13]={6,32434,5,1,4,6,4,1,4,5,1,5,6};
    int arr[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int ans=0;
    for (int i=0;i<13;i++)
    {
        for (int j=0;j<32;j++)
        {
            if (a[i] & 1<<j)
            {
                arr[j]++;
            }
        }
    }
    for (int j=0;j<32;j++)
    {
        arr[j]=(arr[j]%3);
    }
    for (int j=0;j<32;j++)
    {
        ans=ans+(arr[j]*pow(2,j));
    }
    cout<<endl<<ans;
    return 0;
}