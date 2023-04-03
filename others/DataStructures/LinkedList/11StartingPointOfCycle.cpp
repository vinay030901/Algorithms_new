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
ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode *slow=head,*fast=head,*entry=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                while(slow!=entry){
                    slow=slow->next;
                    entry=entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }