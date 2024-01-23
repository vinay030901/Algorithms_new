/*You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.



Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]


Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.*/
#include <bits/stdc++.h>
using namespace std;
vector<int> partitionLabels(string str)
{
    unordered_map<char, int> mp;
    int n = str.size();
    vector<int> ans;
    for (int i = 0; i < str.length(); i++)
    {
        mp[str[i]] = i;
    }
    int last = mp[str[0]];
    int p = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (mp[str[i]] > last)
            last = mp[str[i]];
        if (i == last)
        {
            ans.push_back(i + 1 - p);
            p = i + 1;
            if (i + 1 < n)
                last = mp[str[i + 1]];
        }
    }
    return ans;
}
int main()
{
    // Your code here
    return 0;
}