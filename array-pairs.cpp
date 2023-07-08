#include<bits/stdc++.h>
using namespace std;
long solve(vector<long long> arr,int l,int r) {
    if (r-l<1)
    return 0;
    int temp=l;
    for (int i=l;i<=r;i++)
    {
        if (arr[temp]<=arr[i])
        temp=i;
    }
    if (arr[temp]==1)
    {
        int n=r-l+1;
        return (n*(n-1))/2;
    }
    long a=solve(arr,l,temp-1);
    long b=solve(arr,temp+1,r);
    stable_sort(arr.begin()+l,arr.begin()+temp);
    stable_sort(arr.begin()+temp+1,arr.begin()+r+1,greater<int>());
    long ans=0;
    int j=temp;
    int i=l;
    while (i<=temp and j<=r)
    {
        if (arr[i]*arr[j]>arr[temp])
                {
                    j++;
                }
        else {
            ans+=r-j+1;
            i++;
        }
    }
    return ans + a + b;
}

int main()
{
    int n;
    cin>>n;
    vector <long long> a(n);
    for (int i=0;i<n;i++)
    cin>>a[i];
    cout<<solve(a,0,n-1);
    return 0;
}