#include <bits/stdc++.h>

using namespace std;

int main(){
    int n=8;
    vector<int> a(n,0);
    for(int i=0;i<n;i++)
     a[i]=i;
    vector<int> b;
    while(!a.empty())
    {
        vector<int> tmp;
        for(int i=0;i<a.size();i++)
          if(i%2==0)
            b.push_back(a[i]);
          else tmp.push_back(a[i]);
        a.swap(tmp);
    }
    for(auto x:b)
    cout<<x<<" "<<endl;
    return 0;
}