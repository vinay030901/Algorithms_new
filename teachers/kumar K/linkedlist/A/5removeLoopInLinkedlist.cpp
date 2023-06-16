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
    void removeLoop(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return;
        bool check = true;
        ListNode *slow = head, *fast = head, *prev;
        while (fast->next && fast->next->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                check = !check;
                break;
            }
        }
        if (check)
            return;
        slow = head;
        while (fast != slow)
        {
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = NULL;
        return;
    }
};