#include <bits/stdc++.h>
using namespace std;

struct treeNode {
    int val;
    treeNode *left, *right;
    treeNode(int v)
        : val(v)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

void insert(treeNode*& root, int val)
{
    if (root == nullptr) {
        root = new treeNode(val);
        return;
    }
    if (val > root->val)
        insert(root->right, val);
    else if (val < root->val)
        insert(root->left, val);
}
treeNode* minimum(treeNode* root)
{
    treeNode* x=root;
    while(x&&x->left){
        x=x->left;
    }
    return x;
}
treeNode* remove(treeNode* root, int val)
{
    if (root == nullptr)
        return nullptr;
    if (root->val < val) {
        root->right = remove(root->right, val);
        return root;
    } else if (root->val > val) {
        root->left == remove(root->left, val);
        return root;
    } else {
        if(root->right==nullptr)
            return root->left;
        if(root->left==nullptr)
            return root->right;
        auto next=minimum(root->right);
    }
}

void printTree(treeNode* root)
{
    if (root == nullptr)
        return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

void print(treeNode* root)
{
    printTree(root);
    cout << endl;
}
int main(int argc, char* argv[])
{
    treeNode* root = nullptr;
    vector<int> a = { 10, 11, 1, 3, 2, 5, 4, 6, 7, 8 };
    for (auto x : a)
        insert(root, x);
    print(root);
    remove(root, 10);
    print(root);
}