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
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val>l2->val) std::swap(l1,l2);
        ListNode *res=l1;
        while(l1!=NULL && l2!=NULL){
            ListNode *temp=NULL;
            while(l1!=NULL && l1->val<=l2->val)
            {
                temp=l1;
                l1=l1->next;
            }
            temp->next=l2;
            std::swap(l1,l2);
        }
        return res;
    }
int main(){
    
}