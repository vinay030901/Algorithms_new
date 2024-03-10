/*Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.



Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]


Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode *partition(ListNode *head, int x)
{
    ListNode *left = new ListNode(0);
    ListNode *right = new ListNode(0);
    ListNode *l = left, *r = right;
    while (head)
    {
        if (head->val < x)
        {
            l->next = head;
            l = l->next;
        }
        else
        {
            r->next = head;
            r = r->next;
        }
        head = head->next;
    }
    l->next = right->next;
    r->next = NULL;
    return left->next;
}
int main()
{
    // Your code here
    return 0;
}