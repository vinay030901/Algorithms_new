/*Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.



Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.


Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.*/
#include <bits/stdc++.h>
using namespace std;
void calculateLPS(string &pat, vector<int> &lps, int m)
{
    int i = 1, len = 0;
    lps[0] = 0;
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            lps[i++] = ++len;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[len] = 0;
                i++;
            }
        }
    }
}
int strStr(string txt, string pat)
{
    int n = txt.length(), m = pat.length();
    vector<int> lps(m);
    calculateLPS(pat, lps, m);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == m)
            return i - j;
        else if (i < n && txt[i] != pat[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
            {
                i++;
            }
        }
    }
    return -1;
}
int main()
{
    // Your code here
    return 0;
}