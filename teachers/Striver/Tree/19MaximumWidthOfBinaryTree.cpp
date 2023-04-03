/*

STRIVER L28: MAXIMUM WIDTH OF BINARY TREE

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.

Example 1:

Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: root = [1,3,null,5,3]
Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).*/

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
int widthOfBinaryTree(TreeNode *root)
{
    /* what we will do is we give index to each value of our binary tree, we start from root with value 0
    then the next two nodes will be 2*0+1 and 2*0+2, that 1 and 2, the children of 1 will be 2*1+1 and 2*1+2, that is
    3 and 4, while other childs would be 5 and 6

    in this way we will traverse each of the value of our node, width of binary tree would be max distance between those indexes
    which are in the same row, BUT
    one problem is the max number of nodes is 3000, so if we have a binary tree with only one child all over and it keep on increasing
    till the length of 3000, then we might end up with an index value of 2^32 which will give overflow easily
    it will increase a lot, so we can't exactly use 2*i+1 and 2*i+2 and we need to modify it.

    SO to do this problem, what we will do is take the minimum index in every level, for ex 1 in level 2,
    then will do i=(i-min)
    so i=(1-1)=0, and i=(2-1)=1, now children will be 1,2,3,4 then same will happen for their childs to
    min=1;
    i=1-1=0, i=2-1=1, i=3-1=2, i=4-1=2 and so on
    in this way overflow problem will be solved*/

    queue<pair<TreeNode *, unsigned long long>> q;
    q.push({root, 0});
    unsigned long long ans = 0;
    while (!q.empty())
    {
        unsigned long long size = q.size();
        unsigned long long minimum = q.front().second;
        unsigned long long first = q.front().second, last = q.back().second;
        for (int i = 0; i < size; i++)
        {
            unsigned long long cur_id = q.front().second - minimum;
            TreeNode *node = q.front().first;
            q.pop();
            if (node->left)
                q.push({node->left, cur_id * 2 + 1});
            if (node->right)
                q.push({node->right, cur_id * 2 + 2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}