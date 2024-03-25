/*Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.



Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]


Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<string> ans;
void fun(TreeNode *root, string s)
{
    if (!root)
        return;
    if (s.empty())
    {
        s += to_string(root->val);
    }
    else
    {
        s += "->";
        s += to_string(root->val);
    }
    if (!root->left && !root->right)
    {
        ans.push_back(s);
        // s="";
    }
    fun(root->left, s);
    fun(root->right, s);
}
vector<string> binaryTreePaths(TreeNode *root)
{
    string s = "";
    fun(root, s);
    return ans;
}
int main() {
    // Your code here
    return 0;
}