#include <bits/stdc++.h>
using namespace std;


//最近公共祖先

//如果是普通二叉树，很简单
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution1 {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return root;
    }
};

//如果是二叉搜索树 也很简单
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==nullptr) return nullptr;
       int x=min(p->val,q->val);
       int y=max(p->val,q->val);
       if(x<=root->val&&y>=root->val)
           return root;
        
       if(y<root->val)     
           return lowestCommonAncestor(root->left,p,q);
            
       return lowestCommonAncestor(root->right,p,q);
    }
};

//如果是多叉树 hihocoder

//方法3 将树转化成为数组，
//每次访问或者离开一个节点的时候，就在数组中加入节点
//那么每个节点在数组中都出现了两次，
//就两个节点的最近公共祖先就是看这两个节点在数组中最后一次出现的位置[x,y]之间哪一个节点的深度最小

int main(int argc, char* argv[])

{

    return 0;
}