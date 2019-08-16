#include <bits/stdc++.h>
using namespace std;
#define N 100100
struct node {
    int maxV;
} tree[4 * N];

int f[N];
int n, t, a, b;

void update(int l, int r, int root)
{
    if (r < a || l > a)
        return;
    if (r == l) {
        tree[root].maxV = b;
        return;
    }
    int mid = (l + r) / 2;
    update(l, mid, root * 2);
    update(mid + 1, r, root * 2 + 1);
    tree[root].maxV = max(tree[root * 2].maxV,
        tree[root * 2 + 1].maxV);
}
int search(int l, int r, int root)
{
    if (l > b || r < a)
        return (-1);
    if (l >= a && r <= b)
        return tree[root].maxV;
    int mid = (l + r) / 2;
    return (max(search(l, mid, root * 2),
        search(mid + 1, r, root * 2 + 1)));
}
int main()
{
    memset(tree,0,sizeof(tree));
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> b;
        f[i]=b;
        a=i;
        update(1,n,1);
    }
    for(int i=1;i<=n;i++)
    {
        a=1; b=i;
        int tmp=search(1,n,1);
        while(b<n)
        {
            a=a+1;b=b+1;
            tmp=min(tmp,search(1,n,1));
        }
        cout<<tmp<<" ";
    }
    return 0;
}