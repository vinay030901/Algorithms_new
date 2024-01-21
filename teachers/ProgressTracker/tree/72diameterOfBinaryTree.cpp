#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};
class Solution
{
public:
    int mx = 0;
    int diameter(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = diameter(root->left);
        int right = diameter(root->right);
        mx = max(mx, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int x = diameter(root);
        return mx;
    }
};
int main()
{
    // Your code here
    return 0;
}