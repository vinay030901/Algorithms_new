#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> ans;
void preorder(TreeNode *root)
{
    if (root == NULL)
        return;
    ans.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
}
vector<int> preorderTraversal(TreeNode *root)
{
    preorder(root);
    return ans;
}

vector<int> preorderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> ans;
    if (root == NULL)
        return ans;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        ans.push_back(root->val);
        st.pop();
        if (root->right != NULL)
            st.push(root->right);
        if (root->left != NULL)
            st.push(root->left);
    }
    return ans;
}
int main()
{
}