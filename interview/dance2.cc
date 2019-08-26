#include <bits/stdc++.h>
using namespace std;
#define N 1500
#define M 1000000007
long f[N];
int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    f[0] = 1;
    f[2] = 1;
    for (int i = 4; i <= n; i += 2) {
        int tot = 0;
        for (int j = 2; j <= i; j += 2) {
            int x = (j - 1 - 1);
            int y = i - j;
            f[i] = (f[i] + f[x] * f[y]) % M;
        }
    }
    cout << f[n];
    return 0;
}