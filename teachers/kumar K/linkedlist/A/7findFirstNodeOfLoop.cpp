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
    int findFirstNode(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        slow = head;
        while (fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->val;
    }
};