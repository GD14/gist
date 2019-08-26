#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
int n;
int a[20005];
vector<int> pm;
int prime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}
struct node {
    set<int> s;
    int count;
    node()
        : count(0)
        , s()
    {
    }
};
set<int> work(int x)
{
    int i = 0;
    set<int> s;
    if (x == 1)
        return s;
    for (int i = 0; i < pm.size(); i++) {
        if (x == 0)
            break;
        if (x % pm[i] == 0) {
            s.insert(pm[i]);
            while (x > 0 && (x % pm[i] == 0))
                x = x / pm[i];
        }
    }
    return s;
}
int main(int argc, char* argv[])
{
    int maxVal = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxVal = max(a[i], maxVal);
    }
    for (int i = 2; i <= maxVal; i++)
        if (prime(i)) {
            pm.push_back(i);
        }

    vector<node> ans;
    for (int i = 0; i < n; i++) {
        set<int> s = work(a[i]);
        bool flag = false;
        for (auto& x : ans) {
            for (auto y : s)
                if (x.s.find(y) != x.s.end()) {
                    flag = true;
                    break;
                }
            if (flag) {
                for (auto y : s)
                    x.s.insert(y);
                x.count++;
                break;
            }
        }
        node tmp;
        tmp.count = 1;
        tmp.s = s;
        if (!flag)
            ans.push_back(tmp);
    }

    int tot = 0;
    for (auto x : ans)
        tot = max(x.count, tot);
    cout << tot << endl;
    return 0;
}