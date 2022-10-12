/*Given a Binary Tree (Bt), convert it to a Doubly Linked List(DLL). The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be the same as in Inorder for the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.*/

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
TreeNode *prev=NULL,*head=NULL;
void convert(TreeNode* root)
{
    if(!root) return;
    convert(root->left);
    if(prev==NULL) head=root;
    else
    {
        prev->right=root;
        root->left=prev;
    }
    prev=root;
    convert(root->right);
}
TreeNode* binaryTreeTodll(TreeNode* root)
{
    convert(root);
    return head;
}


Node *prev=NULL,*head=NULL;
void convert(Node* root)
{
    if(!root) return;
    while(root)
    {
        if(root->left==NULL)
        {
            if(prev==NULL)
            head=root;
            else
            {
                prev->right=root;
                root->left=prev;
            }
            prev=root;
            root=root->right;
        }
        else
        {
            Node* pre=root->left;
            while(pre->right && pre->right!=root)
            pre=pre->right;
            if(pre->right==NULL)
            {
                pre->right=root;
                root=root->left;
            }
            
            else
            {
                pre->right=NULL;
                if(prev==NULL)
            head=root;
            else
            {
                prev->right=root;
                root->left=prev;
            }
            prev=root;
                root=root->right;
            }
        }
    }
}
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        convert(root);
        return head;
    }