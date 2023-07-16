/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *ans = new ListNode();
        ans->next = head;
        ListNode *pre = ans;
        ListNode *cur, *nex;
        while (pre->next && pre->next->next)
        {
            cur = pre->next;
            nex = cur->next;
            pre->next = nex;
            cur->next = nex->next;
            nex->next = cur;
            pre = cur;
        }
        return ans->next;
    }
};