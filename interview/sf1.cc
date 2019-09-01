
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int fa[N];

int find(int x)
{
    if (fa[x] < 0)
        return x;
    fa[x] = find(fa[x]);
    return fa[x];
}
int main(int argc, char* argv[])
{
    int n, m, k;
    cin >> n >> m >> k;
    int x, y;
    int d = 0;
    for (int i = 1; i <= m; i++)
        fa[i] = -1;
    unordered_map<int, int> h;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        if (h.find(x) == h.end()) {
            h[x] = find(y);
        } else {
            int u = find(h[x]);
            int v = find(y);
            if(u!=v)
                fa[u]=v;
            h[x] = v;
        }
    }
    int ans = 0;
    unordered_set<int> s;
    for (int i = 1; i <= n; i++) {
        if (h.find(i) == h.end())
            ans += 1;
        else {
            s.insert(find(h[i]));
        }
    }
    if (s.size() > 0)
        ans += s.size() - 1;
    std::cout << ans << endl;
    return 0;
}