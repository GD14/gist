#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
void push(TreeNode* r, stack<TreeNode*>& st)
{
    while (r != nullptr) {
        st.push(r);
        r = r->left;
    }
}

void pop(stack<TreeNode*>& st)
{
    auto r = st.top();
    st.pop();
    push(r->right, st);
}

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> ans;
    stack<TreeNode*> st;
    push(root, st);
    while (!st.empty()) {
        ans.push_back(st.top()->val);
        pop(st);
    }
    return ans;
}
int main(int argc, char* argv[])
{
}