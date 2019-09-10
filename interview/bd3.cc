#include <bits/stdc++.h>
using namespace std;


int work(vector<int>&a,vector<int>&b,int m)
{
    
}

int main(int argc, char* argv[])
{
    int n, m;
    cin >> n >> m;
    int x, y;
    int tot;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (x > m)
            tot += y;
        else {
            a.push_back(x);
            a.push_back(y);
        }
    }
    n = a.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }
    int t = work(a, b, m);
    while (t > 0) {
        tot = tot + t;
        work(a, b, m);
    }
    cout<<tot<<endl;
    return 0;
}