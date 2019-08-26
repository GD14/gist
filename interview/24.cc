#include <bits/stdc++.h>
using namespace std;
long long work(vector<int>& a, int l, int r)
{
    if (l > r)
        return 0;
    if (l == r)
        return a[l];
    int minVal = a[l];
    int k = l;
    for (int i = l + 1; i <= r; i++)
        if (a[i] < minVal) {
            minVal = a[i];
            k = i;
        }
    long long x = work(a, l, k - 1);
    long long y = work(a, k + 1, r);

    long long z = (long long)(a[k]) * (long long)(k - l + 1) * (long long)(r - k + 1);
    return x + y + z;
}
int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << work(a, 0, n - 1);
    return 0;
}