/*
Input : a  b  c  d  e   N = 2
Output : c  d  e  a  b

Input : a  b  c  d  e  f  g  h   N = 4
Output : e  f  g  h  a  b  c  d
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

class Solution
{
public:
    ListNode *reverseListBySizeK(ListNode *head, int k)
    {
        ListNode *cur = head, *temp, *newHead;
        int count = 0;
        while (cur || count < k)
        {
            newHead = cur;
            temp = cur->prev;
            cur->prev = cur->next;
            cur->next = temp;
            cur = cur->prev;
            count++;
        }
        if (count >= k)
        {
            ListNode *rest = reverseListBySizeK(cur, k);
            head->next = rest;
            if (rest)
                rest->prev = head;
        }
        return newHead;
    }
};