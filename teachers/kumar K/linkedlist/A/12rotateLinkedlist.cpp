/*
Given a singly linked list of size N. The task is to left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Example 1:

Input:
N = 5
value[] = {2, 4, 7, 8, 9}
k = 3
Output: 8 9 2 4 7
Explanation:
Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
Rotate 3: 8 -> 9 -> 2 -> 4 -> 7
Example 2:

Input:
N = 8
value[] = {1, 2, 3, 4, 5, 6, 7, 8}
k = 4
Output: 5 6 7 8 1 2 3 4

Your Task:
You don't need to read input or print anything. Your task is to complete the function rotate() which takes a head reference as the first argument and k as the second argument, and returns the head of the rotated linked list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).*/
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
    ListNode *rotate(ListNode *head, int k)
    {
        // Your code here
        int len = 0;
        ListNode *temp = head;
        while (temp)
        {
            len++;
            temp = temp->next;
        }
        k = k % len;
        len = len - k;
        if (k == 0)
            return head;
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *slow = start, *fast = start;
        for (int i = 0; i < len; i++)
            fast = fast->next;
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
    ListNode *rotate(ListNode *head, int k)
    {
        // Your code here
        int len = 1;
        ListNode *temp = head;
        while (temp->next)
        {
            len++;
            temp = temp->next;
        }
        k = k % len;
        temp->next = head;
        while (k--)
            temp = temp->next;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
