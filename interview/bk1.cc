#include <bits/stdc++.h>
using namespace std;
long long absLong(long long x,long long y)
{
    if(x>y)
        return x-y;
    return y-x;
}
int main(int argc, char* argv[])
{
    int n;
    long long x;
    long long y;
    cin >> n;
    vector<long long> a;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    long long ans = absLong(a[0],a[1]);
    x = a[0];
    y = a[1];
    for (int i = 1; i <n-1; i++)
            if (absLong(a[i],a[i+1]) < ans) {
                ans = absLong(a[i],a[i+1]);
                x = a[i];
                y = a[i+1];
            }

    cout << x << " " << y;
    return 0;
}