/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?*/

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*the first approach is using stack, stack is best if you want to reverse something
so we will create and an external linkedlist too

1.first we will calculate the length of the linkedlist, them calculate the number of reversal we need to here
2. so we run of loop till number of reversals, here we will push k elements of our given linkeslist in our stack.
3. then we put all the elements of stack in our new linkedlist, so those elements will be copied reversed now.
4.when the loop is completed, we will put the remaining elements in our new linkedlist and return.
*/
ListNode* reverseKGroup(ListNode* head, int k) {
    stack<int>s;
    ListNode *temp=head;
    ListNode *t=head;
    int length=0;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    ListNode *h=new ListNode();
    ListNode *h1=h;
    int time=length/k;
    for(int i=0;i<time;i++)
    {
        int n=k;
        while(n--)
        {
            s.push(t->val);
            t=t->next;
        }
        while(!s.empty())
        {
            h1->next=new ListNode(s.top());
            h1=h1->next;
            s.pop();
        }
    }
    while(t!=NULL)
    {
        h1->next=new ListNode(t->val);
        t=t->next;
        h1=h1->next;
    }
    return h->next;
}


int main()
{

}