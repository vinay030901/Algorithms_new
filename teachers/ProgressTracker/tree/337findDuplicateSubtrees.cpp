#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    // https://leetcode.com/problems/find-duplicate-subtrees/solutions/106020/python-easy-understand-solution/?orderBy=most_votes
    unordered_map<string, pair<int, TreeNode *>> mp;
    string fun(TreeNode *root)
    {
        if (!root)
            return "X";
        string a = fun(root->left);
        string b = fun(root->right);
        string pre = to_string(root->val) + " " + a + " " + b;
        if (mp.find(pre) != mp.end())
            mp[pre].first += 1;
        else
            mp[pre] = {1, root};
        return pre;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        fun(root);
        vector<TreeNode *> ans;
        for (auto it : mp)
            if (it.second.first > 1)
                ans.push_back(it.second.second);
        return ans;
    }
};