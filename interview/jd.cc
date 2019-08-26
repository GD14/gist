#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[600][600];
bool v[600];
int link[600];
int dfs(int x)
{
    for (int i = 1; i <= n; i++)
        if (f[x][i] == 1) {
            if (!v[i]) {
                v[i] = true;
                if (link[i] == 0 || dfs(link[i])) {
                    link[i] = x;
                    return 1;
                }
            }
        }
    return 0;
}

int main(int argc, char* argv[])
{
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        f[x][y] = 1;
        f[y][x] = 1;
        f[x][0]++;
        f[y][0]++;
    }
    n = n * 2;
    for (int i = 0; i <= n; i++) {
        v[i] = false;
        link[i] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += dfs(i);
    vector<int> p;
    for (int i = 1; i <= n; i++) {
        if (link[i] != 0) {
            int tmp = link[i];
            if (f[i][0] > f[tmp][0])
                tmp = i;
            p.push_back(tmp);
        }
    }
    cout << ans / 2 << endl;
    sort(p.begin(), p.end());
    for (int i = 0; i < p.size(); i += 2)
        cout << p[i] << " ";
    return 0;
}