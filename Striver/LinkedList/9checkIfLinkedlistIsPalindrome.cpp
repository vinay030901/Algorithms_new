#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string str="";
        while(head!=NULL)
        {
            str+=head->val;
            head=head->next;
        }
        string two=str;
        reverse(str.begin(),str.end());
        return two==str;
    }
};
int main()
{

}