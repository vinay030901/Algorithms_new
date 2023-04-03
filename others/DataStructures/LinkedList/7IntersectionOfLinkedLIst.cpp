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
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode *a=headA;
        ListNode *b=headB;
        while(a!=b)
        {
            a=a==NULL?headB:a->next;
            b=b==NULL?headA:b->next;
        }
        return a;
    }