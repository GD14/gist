#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back({ x, i });
    }

    sort(a.begin(), a.end());
    vector<int> w(n, 0);
    for (int i = 0; i < n; i++) {
        int x = a[i].second;
        w[x] = i;
    }

    int ans = 0;
    int maxVal = -1;
    for (int i = 0; i < a.size(); i++) {
        maxVal = max(maxVal, w[i]);
        if (maxVal == i)
            ans++;
    }
    cout << ans << endl;
    return 0;
}