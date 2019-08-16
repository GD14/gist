#include<bits/stdc++.h>
using namespace std;
int a[60000];
int f[60000];
int n;
int ans;
int main(int argc,char *argv[]){
    cin>>n;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a[i]=x;
    }

   f[1]=a[0];
   int right=1;
   for(int i=1;i<n;i++) 
   {
       int l=1;
       int r=right;
       while(l<=r)
       {
           int m=(l+r)/2;
           if(a[i]>f[m])
           {
               l=m+1;
           }else if(a[i]<f[m])
           {
                r=m-1;    
           }else break;
       }
       
       if(l>right)
       {
        f[l]=a[i];
        right=l;
       }else f[l]=min(f[l],a[i]);
   }
   cout<<right<<endl;
}