#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> ans;
void postorder(TreeNode *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return ans;
    postorder(root);
    return ans;
}
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        ans.push_back(root->val);
        if (root->left != NULL)
            st.push(root->left);
        if (root->right != NULL)
            st.push(root->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    // Your code here
    return 0;
}