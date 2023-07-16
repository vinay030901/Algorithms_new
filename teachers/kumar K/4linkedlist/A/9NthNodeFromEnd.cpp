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
    int getNthFromLast(ListNode *head, int n)
    {
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < n; i++)
        {
            if (!fast)
                return -1;
            fast = fast->next;
        }

        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->val;
    }
};