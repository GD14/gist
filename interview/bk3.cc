#include <bits/stdc++.h>
using namespace std;
int n;
int main(int argc, char* argv[])
{
    cin >> n;
    vector<int> a(n);
    int x;
    for (int i = 0; i < n; i++) {
        cin>>x;
        a[i]=x;
    }
    sort(a.begin(),a.end());

    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        int l=i+1;
        int r=n;
        while(l<r)
        {
            int m=(l+r)/2;
            if(a[i]<0.9*a[m])
                r=m;
            else l=m+1;
        }
        ans+=(l-i-1);
    }
    cout<<ans;
    return 0;
}