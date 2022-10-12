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
vector<int> postorderTraversal(TreeNode *root)
{

    // here we will use two stacks method first
    // push the root in stack 1, then we run a while loop till stack1 is empty
    // here we will push top element of stack 1 in st2 and then push left and then right element in st1
    // in the next iteration, the top element of st1 is popped and pushed in st1 again
    // in this way, all the root elements and then the right will be pushed into the st2 and later the left.
    // so we will get our traversal that is left-right-root for us
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<TreeNode *> st1;
    stack<TreeNode *> st2;
    vector<int> v;
    st1.push(root);
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        v.push_back(root->val);
        if (root->left != NULL)
            st1.push(root->left);
        if (root->right != NULL)
            st1.push(root->right);
    }
    while (!st2.empty())
    {
        root = st2.top();
        ans.push_back(root->val);
        st2.pop();
    }
    return ans;
}

vector<int> postorderTraversal(TreeNode *root)
{

    // here we are using vector instead of second stack and we just need to reverse the vector to give us the right value
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<TreeNode *> st1;
    st1.push(root);
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        ans.push_back(root->val);
        if (root->left != NULL)
            st1.push(root->left);
        if (root->right != NULL)
            st1.push(root->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode *node = s.top();
        s.pop();
        ans.push_back(node->val);
        if (node->left != NULL)
            s.push(node->left);
        if (node->right != NULL)
            s.push(node->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}