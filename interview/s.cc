#include <bits/stdc++.h>

using namespace std;
#define N 1000100
int getInt()
{
    char ch;
    while (ch = getchar(), ch < '0' || ch > '9')
        ;
    int t = ch - '0';
    while (ch = getchar(), ch >= '0' && ch <= '9')
        t = t * 10 + ch - '0';
    return t;
}
struct node {
    int totVal;
    int lazyTag;
    node():totVal(0),lazyTag(-1){}
} segTree[4 * N];

void update(int root, int l, int r, int left_idx, int right_idx, int val)
{
    if (l == left_idx && r == right_idx) {
        segTree[root].totVal = (r - l + 1) * val;
        segTree[root].lazyTag = val;
        return;
    }
    int m = l + (r - l) / 2;
    if (segTree[root].lazyTag != -1) {
        int lazyVal=segTree[root].lazyTag;
        segTree[root].lazyTag = -1;
        segTree[root * 2].lazyTag = lazyVal;
        segTree[root * 2].totVal = lazyVal* (m - l + 1);
        segTree[root * 2 + 1].lazyTag =lazyVal;
        segTree[root * 2 + 1].totVal = lazyVal* (r - m);
    }

    if (right_idx <= m)
        update(root * 2, l, m, left_idx, right_idx, val);
    else if (left_idx >= m + 1)
        update(root * 2 + 1, m + 1, r, left_idx, right_idx, val);
    else {
        update(root * 2, l, m, left_idx, m, val);
        update(root * 2 + 1, m + 1, r, m + 1, right_idx, val);
    }
    segTree[root].totVal = segTree[root * 2].totVal + segTree[root * 2 + 1].totVal;
}
int query(int root, int l, int r, int left_idx, int right_idx)
{
    if (l == left_idx && r == right_idx) {
        return segTree[root].totVal;
    }
    int m = l + (r - l) / 2;
    if (segTree[root].lazyTag != -1) {
        int lazyVal = segTree[root].lazyTag;
        segTree[root].lazyTag = -1;
        segTree[root * 2].lazyTag = lazyVal;
        segTree[root * 2].totVal = lazyVal * (m - l + 1);
        segTree[root * 2 + 1].lazyTag = lazyVal;
        segTree[root * 2 + 1].totVal = lazyVal * (r - m);
    }
    if (right_idx <= m)
        return query(root * 2, l, m, left_idx, right_idx);
    if (left_idx >= m + 1)
        return query(root * 2 + 1, m + 1, r, left_idx, right_idx);
    return query(root * 2, l, m, left_idx, m) + query(root * 2 + 1, m + 1, r, m + 1, right_idx);
}
int main(int argc, char* argv[])
{

    int n, m;
    int op, x, y, z;
    n = getInt();
    for (int i = 1; i <= n; ++i)
        update(1, 1, n, i, i, getInt());
    m = getInt();
    for (int i = 0; i < m; ++i) {
        op = getInt();
        x = getInt();
        y = getInt();
        if (op == 1) {
            z = getInt();
            update(1, 1, n, x, y, z);
        } else
            printf("%d\n", query(1, 1, n, x, y));
    }
    return 0;
}