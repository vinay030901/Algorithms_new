/*Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:

Input: head = [1,1,1,2,3]
Output: [2,3]

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode *deleteDuplicates(ListNode *head)
{
    // the approach here is that we need to are just checking that if our present node is equal to next node
    // we are also having a prev pointer which is behind our head node
    // ans whenever we have a condition where head is equal to next, we are going to run a while loop
    // till that condition is not there and connect prev to next of that element so that we don't have
    // repeated element in our linkedlist
    ListNode *head1 = new ListNode(0);
    head1->next = head;
    ListNode *prev = head1;
    while (head != NULL)
    {
        if (head->next && head->val == head->next->val)
        {
            while (head->next && head->val == head->next->val)
                head = head->next;
            prev->next = head->next;
        }
        else
            prev = prev->next;
        head = head->next;
    }
    return head1->next;
}
int main()
{
    // Your code here
    return 0;
}