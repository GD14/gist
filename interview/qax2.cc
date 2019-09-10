#include<bits/stdc++.h>
using namespace std;
unordered_set<int> s;
int f[100010];
int n;
int work(int r,int x,int y)
{
    if(r>n||f[r]==-1)
        return -1;
    if(f[r]>y)
        return work(r*2,x,y);
    if(f[r]<x)
        return work(r*2+1,x,y);
    return f[r];
}
int main(int argc,char *argv[]){
    int x,y;
    cin>>x;

    n=pow(2,x)-1;
    for(int i=1;i<=n;i++) 
    {
        cin>>f[i];
        s.insert(f[i]);
    }
    cin>>x>>y;
    if(x>y)swap(x,y);
    if(s.find(x)==s.end()||s.find(y)==s.end())
        cout<<-1<<endl;
    else
        cout<<work(1,x,y)<<endl;
    return 0;
}