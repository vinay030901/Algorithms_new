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
vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
       if(root==NULL)
           return ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            ans.push_back(root->val);
            if(root->right!=NULL)
            st.push(root->right);
            if(root->left!=NULL)
                st.push(root->left);
        }
        return ans;
    }
int main()
{
    
}