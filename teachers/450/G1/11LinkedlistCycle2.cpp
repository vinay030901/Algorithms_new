#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<int,int>mp;
    while(head!=NULL)
    {
        mp[head->val]++;
        if(mp[head->val]==2) return head;
        else head=head->next;
    }
    return NULL;
    }
};
int main()
{

}