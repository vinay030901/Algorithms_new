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
vector<int> rightSideView(TreeNode* root) {
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
int main(){
    
}