/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following 
the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed).
 It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.*/

#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *detectCyle(ListNode *head){
    // we need to detect a cycle here, or the value which repeated after sometime, so we can use 
    // the tortoise hare approach here

    if(head==NULL && head->next==NULL) return NULL;

    // we are defining our variables for traversal, slow for slow pointer, fast for fast pointer and entry for the 
    // pointer when slow becomes equal to head and next process to start checking from start 
    ListNode *slow=head,*fast=head,*entry=head;

    // since fast moves, if we encounter NULL from it, we will stop
    while(fast->next!=NULL || fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) // slow equal to fast, means there is cycle in the process
        {
            while(slow!=entry)
            {
                slow=slow->next;
                entry=entry->next;
            }
            return entry;
        }
    }
    return NULL;
}
ListNode *detectCyle1(ListNode* head)
{
    map<int,int>mp;
    while(head!=NULL)
    {
        mp[head->val]++;
        if(mp[head->val]==2) return head;
    }
    return NULL;
}
int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next = new ListNode(0);
    head->next = new ListNode(-4);
    head->next = new ListNode(2);
}