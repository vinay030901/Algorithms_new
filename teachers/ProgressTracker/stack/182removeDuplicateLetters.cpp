/*Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is
the smallest in lexicographical order
 among all possible results.



Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"


Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
 */
#include <bits/stdc++.h>
using namespace std;
string removeDuplicateLetters(string s)
{
    unordered_map<char, int> mp;
    vector<int> vis(26, 0);
    for (auto it : s)
        mp[it]++;
    string res = "";
    for (auto it : s)
    {
        mp[it]--;
        if (vis[it - 'a'])
            continue;
        while (res.size() && res.back() >= it && mp[res.back()])
        {
            vis[res.back() - 'a'] = 0;
            res.pop_back();
        }
        res.push_back(it);
        vis[it - 'a'] = 1;
    }
    return res;
}
int main()
{
    // Your code here
    return 0;
}