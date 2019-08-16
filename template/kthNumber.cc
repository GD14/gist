#include <bits/stdc++.h>
using namespace std;
/**
 * 
 * 上一道题是要给出排序的数列，所以需要遍历每一个数字。而此次只是寻找，并不要访问每一个，
因此不能采用上一道题的暴力递归。其实这个字典数是“十叉树”，就是每个节点可以有十个孩子。
但是由于n大小的限制，构成的并不是一个满十叉树。比如示例中1只有[10,11,12,13]四个孩子。
那么这就是先序遍历十叉树的问题，难点就变成了如何计算出每个节点的子节点的个数，
我们不停的用k减去子节点的个数，当k减到0的时候，当前位置的数字即为所求。
 */
int findKthNumber(int n, int k) {
        int cur = 1;
        --k;//初始化为cur = 1，k需要自减1
        while (k > 0) {
            long long step = 0, first = cur, last = cur + 1;
            //统计这棵子树下所有节点数（step）
            while (first <= n) {
                step += min((long long)n + 1, last) - first;//不能超过n的值，并不是所有节点都有十个子节点
                first *= 10;
                last *= 10;
            }
            if (step <= k) {//不在子树中
                ++cur;
                k -= step;
            } 
            else {//在子树中，进入子树
                cur *= 10;
                --k; 
            }
        }
        return cur;
    }

int main(int argc, char* argv[])
{
    cout<<findKthNumber(100,3)<<endl;
    return 0;
}