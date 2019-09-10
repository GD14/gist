#include <bits/stdc++.h>
using namespace std;
int f[200][200];
bool v[200];
int b[200];

int main(int argc, char* argv[])
{
    int n, m;
    int x;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        f[0][i] = x;
        v[i] = true;
    }

    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 1; i < m; i++)
        for (int j = 0; j < n; j++)
            f[i][j] = f[i - 1][j] - b[j];

    int tot = 0;
    for (int i = 0; i < m; i++) {
        int k = -1;
        for (int j = 0; j < n; j++)
            if (v[j]) {
                if (k == -1) {
                    k = j;
                } else if (f[i][j] > f[i][k])
                    k = j;
            }
        tot = tot + f[i][k];
        v[k] = false;
    }
    cout << tot << endl;
    return 0;
}
