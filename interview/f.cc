#include <bits/stdc++.h>
using namespace std;
#define N 1000100
int segTree[4 * N];

void update(int root, int l, int r, int idx, int val)
{
    if (l == r) {
        segTree[root] = val;
        return;
    }
    int mid = l + (r - l) / 2;
    if (idx <= mid)
        update(root * 2, l, mid, idx, val);
    else
        update(root * 2 + 1, mid + 1, r, idx, val);
    segTree[root] = min(segTree[root * 2], segTree[root * 2 + 1]);
}
int query(int root, int l, int r, int left_idx, int right_idx)
{
    if (l == left_idx && right_idx == r)
        return segTree[root];
    int mid = l + (r - l) / 2;
    if (right_idx <= mid)
        return query(root * 2, l, mid, left_idx, right_idx);
    if (left_idx >= mid + 1)
        return query(root * 2 + 1, mid + 1, r, left_idx, right_idx);
    return min(query(root * 2, l, mid, left_idx, mid), query(root * 2 + 1, mid + 1, r, mid + 1, right_idx));
}
int main(int argc, char* argv[])
{
    int n,m;
    int op, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        update(1,1,n,i,x);
    }

    for (scanf("%d", &m); m--;) {
        scanf("%d%d%d", &op, &x, &y);
        if (op == 0)
            printf("%d\n", query(1, 1, n, x, y));
        if (op == 1)
            update(1, 1, n, x, y);
    }
    return 0;
}