#include <bits/stdc++.h>
using namespace std;
 struct ListNode {
 int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void traverse(struct ListNode *ptr)
{
    while (ptr != NULL)
    {
        printf("%d  ", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}
bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                return true;
        }
        return false;
    }
