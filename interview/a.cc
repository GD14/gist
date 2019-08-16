
#include <bits/stdc++.h>
using namespace std;
int f[30000];
int b[100];

int main(){
    int n,t,x,y,z;
    b[0]=1;
    for(int i=1;i<10;i++)
    b[i]=b[i-1]*2;

    while(cin>>n)
    {
       cin>>t;
       for(int i=0;i<=t;i++)
        f[i]=0;
       for(int i=0;i<n;i++)
        {
            cin>>x>>y>>z;
            int g=0;
            b[0]=1;
            int tot=1;
            while(tot<z){
                g++;
                b[g]=b[g-1]*2;
                tot+=b[g];
            }
            if(tot>z)
            {
                tot-=b[g];
                b[g]=z-tot;
            }
            //cout<<z<<"*"<<endl; 
            //for(int j=0;j<=g;j++)
            //cout<<b[j]<<"--";
            //cout<<endl;
            for(int j=0;j<=g;j++)
            if(b[j]*x<=t){
                for(int k=t;k>=b[j]*x;k--)
                f[k]=max(f[k],f[k-b[j]*x]+b[j]*y);
            }
        }   
        int ans=0;
        for(int i=0;i<=t;i++)
        ans=max(ans,f[i]);
        cout<<ans<<endl;
    }
    return 0;
}
