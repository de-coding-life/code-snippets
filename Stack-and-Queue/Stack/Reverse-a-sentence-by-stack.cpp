#include<bits/stdc++.h>
using namespace std;
int main()
{
   stack<string> x;
   string str;
   string temp="";
   getline(cin,str);
   for (int i=0;i<str.size();i++)
   {
      if (str[i]==' ')
      {x.push(temp);
      temp="";}
      else
      temp+=str[i];
   }
   x.push(temp);
   str="";
   while (0<x.size())
   {str+=(x.top()+" ");
   x.pop();}
   cout<<str;
   return 0;
}