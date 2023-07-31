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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int len = 0;
        ListNode *temp = head;
        while (temp)
        {
            len++;
            temp = temp->next;
        }
        int group = len / k;
        int extra = len > k ? len % k : 0;
        vector<ListNode *> ans;
        temp = head;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(temp);
            for (int j = 1; j < group; j++)
            {
                temp = temp->next;
            }
            if (extra-- > 0)
            {
                temp = temp->next;
            }
            if (temp)
            {
                ListNode *x = temp->next;
                temp->next = NULL;
                temp = x;
            }
        }
        return ans;
    }
};