#include<bits/stdc++.h>
using namespace std;
int merge(int a[],int s,int m,int e){
   int temp[e-s+1],p1=s,p2=m+1;
   int cn=0;
   for (int i=0;i<e-s+1;i++){
      if (p1>m){
         temp[i]=a[p2];
         p2++;
      }
      else if (p2>e){
         temp[i]=a[p1];
         p1++;
      }
      else if (a[p1]<=a[p2]){
         temp[i]=a[p1];
         p1++;
      }
      else{
         temp[i]=a[p2];
         cn+=m-p1+1;
         p2++;
      }
   }
   for (int i=0;i<e-s+1;i++){
      a[s+i]=temp[i];
   }
   return cn;
}
int merge_sort(int a[],int s,int e){
   if (s>=e)
   return 0;
   int m=(s+e)/2;
   return merge_sort(a,s,m)+merge_sort(a,m+1,e)+merge(a,s,m,e);
}
int main(){
   int n;
   cin>>n;
   int arr[n];
   for (int i=0;i<n;i++)
   cin>>arr[i];
   cout<<merge_sort(arr,0,n-1);
   return 0;
}