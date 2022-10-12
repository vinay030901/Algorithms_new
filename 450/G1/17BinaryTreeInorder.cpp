#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int>ans;
void inorder(TreeNode *root)
{
    if(root==NULL) return;
    inorder(root->left);
    ans.push_back(root->val);
    inorder(root->right);
}
vector<int> inorderTraversal(TreeNode* root) {
    if(root==NULL) return ans;
    inorder(root);
    return ans;
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int>ans; 
    if(root==NULL) return ans;
    stack<TreeNode*>st;
    TreeNode *node=root;
    while(true)
    {
        if(node!=NULL) 
        {
            st.push(node);
            node=node->left;}
        else{
            if(st.empty()==true) break;
            node=st.top();
            st.pop();
            ans.push_back(node->val);
            node=node->right;
        }
    }
    return ans;
}


