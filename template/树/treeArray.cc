
#include <bits/stdc++.h>
using namespace std;
// c[i]=a[i-2^k+1]+a[i-2^k+2]+...a[i]
// k为从最低位到最高为连续0的长度 i=8(1000) k=3
// a[i]包含于c[x1=i+2^k1],c[x2=x1+2^k2],c[x3=x2+2^k3]
// k1=(lowbit(x1)),k2=lowbit(x2),k3=lowbit(x3)
int c[200005];
int n;
int lowbit(int x)
{
    return x& (-x);
}
void add(int x,int val)
{
    while(x<=n)
    {
        c[x]+=val;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main()
{
    cout<<lowbit(6)<<endl;
    vector<int> a={1,2,3,4,5,6};
    sort(a.begin(),a.end(),[](int x,int y){ return x<y;});
    for(auto x:a)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}