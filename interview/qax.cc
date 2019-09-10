#include <bits/stdc++.h>
using namespace std;
map<unsigned int, vector<int>> tree;
set<unsigned int> s;
int work(unsigned int r)
{

    if (s.find(r) == s.end())
        return 0;
    int t = 1;
    for (int i = 0; i < tree[r].size(); i++) {
        t = t + work(tree[r][i]);
    }
    return t;
}

int main(int argc, char* argv[])
{

    string str;
    getline(cin, str);

    stringstream s1(str);
    vector<unsigned int> a;
    vector<unsigned int> b;
    unsigned int x;
    while (s1 >> x) {
        a.push_back(x);
        s.insert(x);
    }

    getline(cin, str);
    stringstream s2(str);

    while (s2 >> x) {
        b.push_back(x);
        s.insert(x);
    }
    int n = a.size();
    for (int i = 0; i < n; i++) {
        tree[b[i]].push_back(a[i]);
    }
    unsigned int t;
    cin >> t;
    cout << work(t);
    return 0;
}