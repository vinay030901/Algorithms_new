/*Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m
substrings
 respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.



Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true


Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.


Follow up: Could you solve it using only O(s2.length) additional memory space?

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool fun(string &s1, int m, string &s2, int n, string &s3, int i, vector<vector<int>> &mp)
    {
        if (m < 0 && n < 0 && i < 0)
            return true;
        if (m < 0)
        {
            if (i != n)
                return false;
            for (int j = n; j >= 0; j--)
                if (s2[j] != s3[i--])
                    return false;
            return true;
        }
        if (n < 0)
        {
            if (i != m)
                return false;
            for (int j = m; j >= 0; j--)
                if (s1[j] != s3[i--])
                    return false;
            return true;
        }
        if (mp[m][n] != -1)
            return mp[m][n];
        if (s1[m] == s3[i] && s2[n] == s3[i])
            return mp[m][n] = fun(s1, m - 1, s2, n, s3, i - 1, mp) || (fun(s1, m, s2, n - 1, s3, i - 1, mp));
        else if (s1[m] == s3[i])
            return mp[m][n] = fun(s1, m - 1, s2, n, s3, i - 1, mp);
        else if (s2[n] == s3[i])
            return mp[m][n] = fun(s1, m, s2, n - 1, s3, i - 1, mp);
        else
            return mp[m][n] = false;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        vector<vector<int>> mp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        if (s1.size() + s2.size() != s3.size())
            return false;
        return fun(s1, s1.length() - 1, s2, s2.length() - 1, s3, s3.length() - 1, mp);
    }
};
int main()
{
    // Your code here
    return 0;
}