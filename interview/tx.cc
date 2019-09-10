#include <bits/stdc++.h>
using namespace std;
int f[100010][2];
int a[100010];
int b[100010];
int sum[100010];
int main(int argc, char* argv[])
{
    int n = 0, k, t;
    cin >> t >> k;

    for (int i = 0; i < t; i++) {
        cin >> a[i] >> b[i];
        n = max(a[i], n);
        n = max(b[i], n);
    }

    f[0][0] = 1;
    sum[0] = 0;
    int M = 1000000007;
    for (int i = 1; i <= n; i++) {
        f[i][0] = (f[i - 1][0] + f[i - 1][1]) % M;
        if (k != 0 && i >= k)
            f[i][1] = (f[i - k][0] + f[i - k][1]) % M;
        else
            f[i][1] = 0;
        int tmp = (f[i][0] + f[i][1]) % M;
        sum[i] = (sum[i - 1] + tmp) % M;
    }

    for (int i = 0; i < t; i++) {
        int tmp=(sum[b[i]] - sum[a[i] - 1]);
        if(tmp<0)tmp=tmp+M;
        tmp=tmp%M;
        cout << tmp << endl;
    }
}