/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a
height-balanced
 binary search tree.

Example 1:

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.


Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.*/
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
class Solution
{
public:
    TreeNode *recur(vector<int> &arr, int left_, int right_)
    {
        if (left_ > right_)
            return NULL;
        int mid = (right_ + left_) / 2;
        TreeNode *node = new TreeNode(arr[mid]);
        node->left = recur(arr, left_, mid - 1);
        node->right = recur(arr, mid + 1, right_);
        return node;
    }
    TreeNode *sortedArrayToBST(vector<int> &arr)
    {
        return recur(arr, 0, arr.size() - 1);
    }
};
int main()
{
    return 0;
}