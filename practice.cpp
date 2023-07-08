#include <iostream>
using namespace std;

int main() {
	int t,n,m,x,y,s;
	cin>>t;
	for (int temp=0;temp<t;temp++)
	{
	    cin>>n>>m>>x>>y>>s;
	    bool mp[n][m]={{false}};
	    int inp,cntr=0;
	    for (int i=0;i<x;i++)
	    {
    	    cin>>inp;
    	    for(int j=0;j<m;j++)
    	    {
    	        mp[inp-1][j]=true;
    	    }
	    }
	    for (int i=0;i<y;i++)
	    {
    	    cin>>inp;
    	    for(int j=0;j<n;j++)
    	    {
    	        mp[j][inp-1]=true;
    	    }
	    }
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                bool tf=false;
                for (int ii=i;ii<i+s;ii++)
                {
                    for (int jj=j;jj<j+s;jj++)
                    tf=(tf or mp[ii][jj]);
                }
                if (tf==false)
                {
                    cntr++;
                    for (int ii=i;ii<i+s;ii++)
                    {
                        for (int jj=j;jj<j+s;jj++)
                        mp[ii][jj]=true;
                    }
                }
            }
        }
        cout<<cntr<<endl;
	}
	return 0;
}
