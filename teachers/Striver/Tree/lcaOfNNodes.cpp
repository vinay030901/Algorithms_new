#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};
int getKeyCount(TreeNode *root, int num, vector<int> &nodes, vector<int> &ancestor)
{
    if (root == NULL)
        return 0;
    num += (getKeyCount(root->left, num, nodes, ancestor) + getKeyCount(root->right, num, nodes, ancestor));
    if (find(nodes.begin(), nodes.end(), root->val) != nodes.end())
        num++;
    if (num == nodes.size())
        ancestor.push_back(root->val);
    return num;
}
int lcaOfNNodes(TreeNode *root, vector<int> &nodes)
{
    vector<int> ancestor;
    int num = 0;
    int ans = getKeyCount(root, num, nodes, ancestor);
    return ancestor[0];
}
int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left->left = new TreeNode(12);
    root->right->left->right = new TreeNode(13);
    root->right->right->left = new TreeNode(14);
    root->right->right->right = new TreeNode(15);

    vector<int> nodes = {8, 10, 11};
    cout << lcaOfNNodes(root, nodes);
}