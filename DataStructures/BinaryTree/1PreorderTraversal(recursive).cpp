#include <bits/stdc++.h>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
    void dfs(TreeNode *root,vector<int>&ans){
        if(root==NULL)
            return;
        ans.push_back(root->val);
        dfs(root->left,ans);
        dfs(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        dfs(root,ans);
        return ans;
    }
int main()
{
    
}