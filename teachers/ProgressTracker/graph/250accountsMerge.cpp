/*Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.



Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'],
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Example 2:

Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]


Constraints:

1 <= accounts.length <= 1000
2 <= accounts[i].length <= 10
1 <= accounts[i][j].length <= 30
accounts[i][0] consists of English letters.
accounts[i][j] (for j > 0) is a valid email.*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // https://leetcode.com/problems/accounts-merge/discuss/172568/Beats-99.18-solution-C%2B%2B
    int find(int a, vector<int> &par)
    {
        if (a == par[a])
            return a;
        return par[a] = find(par[a], par);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>> &arr)
    {
        int n = arr.size();
        vector<int> par(n);
        unordered_map<string, int> em2id;
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            for (int j = 1; j < arr[i].size(); j++)
            {
                if (em2id.find(arr[i][j]) != em2id.end())
                { // this email is seen once, so we will change the parent
                    par[find(em2id[arr[i][j]], par)] = find(i, par);
                }
                else
                { // this email is not seen, we set it to parent of i
                    em2id[arr[i][j]] = par[i];
                }
            }
        }
        unordered_map<int, vector<string>> newaccs;
        for (auto it : em2id)
        {
            newaccs[find(it.second, par)].emplace_back(it.first);
        }
        vector<vector<string>> ans;
        for (auto &it : newaccs)
        {
            auto &emails = it.second;
            sort(begin(emails), end(emails));
            emails.insert(begin(emails), arr[it.first][0]);
            ans.emplace_back(emails);
        }
        return ans;
    }
};
int main()
{
    // Your code here
    return 0;
}