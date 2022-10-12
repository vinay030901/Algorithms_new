/*Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list,
instead you will be given access to the node to be deleted directly.

It is guaranteed that the node to be deleted is not a tail node in the list.*/
#include <bits/stdc++.h>
using namespace std;
 struct ListNode {
 int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
void traverse(struct ListNode *ptr)
{
    while (ptr != NULL)
    {
        printf("%d  ", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}
void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
int main(){
    
}