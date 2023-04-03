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
int floor(TreeNode *root,int key)
{
    int ans=-1;
    while(!root)
    {
        if(root->val==key) return key;
        else{
            if(root->val<key)
            {
                ans=root->val;
                root=root->right;
            }
            else root=root->left;
        }
    }
    return ans;
}