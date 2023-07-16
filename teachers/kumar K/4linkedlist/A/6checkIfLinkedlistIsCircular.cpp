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
    bool isCircular(ListNode *head)
    {
        // Your code here
        if (!head)
            return true;
        ListNode *temp = head;
        while (head)
        {
            head = head->next;
            if (head == temp)
                return true;
        }
        return false;
    }
};