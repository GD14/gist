#include <bits/stdc++.h>
using namespace std;
#define N 10001
int findNum(int a[], int l, int r,int t)
{
    if(l>r)
        return -1;
    int m=(l+r)/2;
    if(a[m]==t)
        return m;
    else if(a[m]>t)
        return findNum(a,l,m-1,t);
    else 
        return findNum(a,m+1,r,t);
}


int f[N];

int main(int argc, char* argv[])
{

    int n;
    int t;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>f[i];
    cin>>t;

    cout<<findNum(f,0,n-1,t);
    return 0;
}