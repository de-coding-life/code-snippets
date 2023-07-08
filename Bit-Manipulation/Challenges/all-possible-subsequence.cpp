#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for (int i=0;i<pow(2,n);i++)
    {
        cout<<"[  ";
        for (int j=0;j<n;j++)
        {
            if ((i) & 1<<j)
            {
                cout<<arr[j]<<"  ";
            }
        }
        cout<<"]"<<endl;
    }
    return 0;
}