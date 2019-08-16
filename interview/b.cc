#include<bits/stdc++.h>
using namespace std;

int t[10000];
int main(){
   int n,a,x,k;
   
   while(cin>>n) 
   {
       cin>>a;
       cin>>x;

       int totBug=0;
       int totMin=a*60*x+(8-x)*60;
       for(int i=0;i<n;i++){
           cin>>k;
           t[i]=k;
           totBug+=k;
       }
       if(totBug>totMin)
       {
           cout<<0<<endl;
           continue;
       }
       int ans=0;
       int i=1;
       while(i<=x&a*60<=totBug)
       {
           ans=ans+60;
           totBug-=a*60;
           i=i+1;
       }

      if(totBug==0){
          cout<<ans<<endl;
          continue;
      }

      if(i<=x){
          ans+=totBug/a;
          if((totBug%a)!=0)
          ans+=1;
      }else{
          ans+=totBug;
      }
          cout<<ans<<endl;
   }
}