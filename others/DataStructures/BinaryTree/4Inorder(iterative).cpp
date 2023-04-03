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
vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        stack<TreeNode*>st;
        while(true){
            if(root!=NULL){
                st.push(root);
                root=root->left;
            }
            else
            {
                if(st.empty()==true) break;
                root=st.top();
                st.pop();
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
int main(){
    
}