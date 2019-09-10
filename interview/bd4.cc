#include <bits/stdc++.h>
using namespace std;

//hashmap
unordered_map<int, int> m;

int tot = 0;
int work(int n, int k)
{

    if (m.find(n) != m.end())
        return m[n];

    int t = n - k;
    if (t > 0 && t % 2 == 0) {
        int x = t / 2;
        int y = t / 2 + k;
        int t1 = work(x, k);
        int t2 = work(y, k);
        m[n]=t1+t2;
        return t1 + t2;
    }
    m[n] = 1;
    return 1;
}
int main(int argc, char* argv[])
{
    int n, k;
    cin >> n >> k;
    cout<<work(n,k)<<endl;
}