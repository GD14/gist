#include <bits/stdc++.h>
using namespace std;

bool f[205][205];
bool v[205];
int n;
void work(int x)
{
    for (int i = 0; i < n; i++)
        if (!v[i] && f[x][i]) {
            v[i] = true;
            work(i);
        }
}
int main(int argc, char* argv[])
{
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> x;
            f[i][j] = (x >= 3);
        }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != k && k != j && i != j) {
                    f[i][j] = f[i][j] || (f[i][k] && f[k][j]);
                }
    int ans = 0;
    for (int i = 0; i < n; i++)
        v[i] = false;

    for (int i = 0; i < n; i++)
        if (!v[i]) {
            ans++;
            v[i] = true;
            work(i);
        }
    cout << ans << endl;
    return 0;
}