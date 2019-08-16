#include<bits/stdc++.h>
using namespace std;

int a[202][202];
int f[202];
bool h[202];

int main(){
    int n,p,c;
    int x,y,t;
    while(cin>>n)
    {
        cin>>p;
        cin>>c;
        for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            a[i][j]=0x3fff;
        for(int i=0;i<p;i++)
        {
            cin>>x>>y>>t;
            a[x][y]=t;
            a[y][x]=t;
        }
        for(int i=1;i<n;i++) 
        {
            f[i]=a[0][i];
            h[i]=true;
        }
        h[0]=false;

        for(int i=1;i<n;i++)
        {
            int minV=0x3fff;
            int s=-1;
            for(int j=1;j<n;j++)
            if(h[j]&&f[j]<minV)
            {
                minV=f[j];
                s=j;
            }
           h[s]=false;
           for(int j=1;j<n;j++)
           if(h[j]&&f[s]+a[s][j]<f[j])
               f[j]=f[s]+a[s][j];
        }
        int ans=0;
        for(int i=0;i<c;i++)
         {
             cin>>y;
             ans+=f[y];
         }
         cout<<ans<<endl;
    }
}