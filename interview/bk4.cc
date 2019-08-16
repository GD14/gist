#include <bits/stdc++.h>
using namespace std;
int a[6000];
int n;
int ans;
int main(int argc, char* argv[])
{
    cin >> n;
    int x;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[i] = x;
    }

    x = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] <= x) {
            ans += x - a[i] + 1;
            x = x + 1;
        } else {
            x = a[i];
        }
    }
    long long tmp = 0;
    x = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] <= x) {
            tmp += x - a[i] + 1;
            x = x + 1;
        } else {
            x = a[i];
        }
    }
    if (tmp < ans)
        ans = tmp;

    for (int i = 1; i < n; i++) {
        long long tmp = 0;

        int x = a[0];
        for (int j = 1; j < i; j++) {
            if (a[j] <= x) {
                tmp += x - a[j] + 1;
                x = x+ 1;
            } else {
                x = a[j];
            }
        }
        int y = a[n - 1];
        for (int j = n -2; j >= i; j--) {
            if (a[j] <= y) {
                tmp += y - a[j] + 1;
                y = y+ 1;
            } else {
                y = a[j];
            }
        }
        if (y >= x)
            tmp += (y - x + 1);
        if (tmp < ans)
            ans = tmp;
    }

    cout << ans << endl;
    return 0;
}