/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.



Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false


Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.*/
#include <bits/stdc++.h>
using namespace std;
// permutation means that we need to check for each subarray of size of given string
int max = 256;
bool compare(int mps1[], int mps2[])
{
    for (int i = 0; i < 256; i++)
        if (mps1[i] != mps2[i])
            return false;
    return true;
}
bool checkInclusion(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int mps1[256] = {0}, mps2[256] = {0};
    if (m > n)
        return false;
    for (int i = 0; i < m; i++)
    {
        mps1[s1[i]]++;
        mps2[s2[i]]++;
    }
    for (int i = m; i < n; i++)
    {
        if (compare(mps1, mps2))
            return true;
        mps2[s2[i]]++;
        mps2[s2[i - m]]--;
    }
    if (compare(mps1, mps2))
        return true;
    return false;
}
int main()
{
    // Your code here
    return 0;
}