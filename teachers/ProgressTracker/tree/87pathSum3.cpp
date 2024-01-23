/*Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

Example 1:

Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
Constraints:

The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
-1000 <= targetSum <= 1000*/
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
unordered_map<long, int> mp;
int cnt = 0;
void fun(TreeNode *root, long sum, int target)
{
    if (!root)
        return;
    sum += root->val;
    if (sum == target)
        cnt++;
    if (mp.find(sum - target) != mp.end())
        cnt += mp[sum - target];
    mp[sum]++;
    fun(root->left, sum, target);
    fun(root->right, sum, target);
    mp[sum]--;
}
int pathSum(TreeNode *root, int target)
{
    fun(root, 0, target);
    return cnt;
}
int main()
{
    // Your code here
    return 0;
}