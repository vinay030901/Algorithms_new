/*Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
Example 1:
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
Example 2:

Input: n = 1
Output: [[1]]


Constraints:

1 <= n <= 8
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<TreeNode *> recur(int start, int end)
{
    vector<TreeNode *> res;
    if (start > end)
    {
        res.push_back(NULL);
        return res;
    }
    for (int i = start; i <= end; i++)
    {
        vector<TreeNode *> left = recur(start, i - 1);
        vector<TreeNode *> right = recur(i + 1, end);
        for (TreeNode *l : left)
        {
            for (TreeNode *r : right)
            {
                TreeNode *root = new TreeNode(i);
                root->left = l;
                root->right = r;
                res.push_back(root);
            }
        }
    }
    return res;
}
vector<TreeNode *> generateTrees(int n)
{
    return recur(1, n);
}
int main()
{
    // Your code here
    return 0;
}