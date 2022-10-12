/*
Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

Example 1:

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []*/

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
vector<int>ans;
vector<int> rightSideView(TreeNode* root) {
    map<int,int>mp;
    if(root==NULL) return ans;
    queue<pair<int,TreeNode*>>q;
    q.push({0,root});
    while(!q.empty())
    {
        auto p= q.front();
        q.pop();
        int row=p.first;
        TreeNode *node=p.second;
        mp[row]=node->val; // here we first went left and then right, so the last value before the row change will be in map
        if(node->left) q.push({row+1,node->left});
        if(node->right) q.push({row+1,node->right});
    }
    for(auto it: mp)
    ans.push_back(it.second);
    return ans;
}
vector<int> rightSideView(TreeNode* root) {
    //FASTER THAN 100%
    // level order solution without using map
    // we took the first value as we are traversing from the right side
    vector<int>res;
    if(root == NULL) return res;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode *curr=q.front();
            q.pop();
            if(i==0)
                res.push_back(curr->val);
            if(curr->right!=NULL)
                q.push(curr->right);
            if(curr->left!=NULL)
                q.push(curr->left);
        }
    }
    return res;
}