#include <bits/stdc++.h>
using namespace std;
int f[10100];
int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot = tot + a[i];
    }
    for (int i = 0; i <= tot; i++)
        f[i] = -1;

    f[0] = 0;
    int h = tot / 2;
    for (int i = 0; i < n; i++)
        for (int j = h; j >= a[i]; j--)
            if (f[j - a[i]] >= 0) {
                if (f[j] == -1)
                    f[j] = f[j - a[i]] + 1;
                else
                    f[j] = min(f[j], f[j - a[i]] + 1);
            }
    for (int i = h; i >= 0; i--)
        if (f[i] != -1) {
            cout << abs(tot - 2 * i) << " " << abs(n - 2 * f[i]) << endl;
            break;
        }
    return 0;
}